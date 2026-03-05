#include <array>
#include <cstddef>
#include <iomanip>
#include <iostream>

constexpr bool isPowerOfTwo(std::size_t value) {
    return value != 0 && (value & (value - 1)) == 0;
}

constexpr std::uint64_t rotateLeft64(std::uint64_t value, unsigned shift) {
    shift &= 63U;
    return shift == 0 ? value : static_cast<std::uint64_t>((value << shift) | (value >> (64 - shift)));
}

constexpr std::uint64_t mix(std::uint64_t value, std::size_t rounds) {
    for (std::size_t r = 0; r < rounds; ++r) {
        value ^= 0x9E3779B97F4A7C15ULL + r;
        value = rotateLeft64(value, static_cast<unsigned>((r + 1) * 7));
        value += value >> 3;
    }
    return value;
}

template <std::size_t N>
constexpr std::array<std::uint8_t, N> toBytes(std::uint64_t value) {
    static_assert(N <= sizeof(std::uint64_t), "Cannot decompose value into more than 8 bytes.");
    std::array<std::uint8_t, N> bytes{};
    for (std::size_t i = 0; i < N; ++i) {
        bytes[i] = static_cast<std::uint8_t>((value >> (8 * i)) & 0xFFU);
    }
    return bytes;
}

template <std::size_t N>
constexpr std::uint64_t checksum(const std::array<std::uint8_t, N>& bytes) {
    std::uint64_t state = 0;
    for (std::size_t i = 0; i < N; ++i) {
        state = rotateLeft64(state ^ bytes[i], 5);
        state += (state >> 4) | bytes[i];
    }
    return state;
}

constexpr std::uint64_t kSampleValue = 0x11223344ULL;
constexpr std::size_t kValueBytes = sizeof(kSampleValue);
constexpr auto kSampleBytes = toBytes<kValueBytes>(kSampleValue);
constexpr auto kSampleChecksum = checksum(kSampleBytes);

// Multi-step constexpr computation
constexpr std::size_t kMixRounds = 5;
constexpr auto kMixedValue = mix(kSampleValue, kMixRounds);
constexpr auto kMixedBytes = toBytes<kValueBytes>(kMixedValue);
constexpr auto kMixedChecksum = checksum(kMixedBytes);

// Additional constexpr computations to debug
constexpr auto kDoubleMixed = mix(kMixedValue, 3);
constexpr auto kCombinedChecksum = checksum(kSampleBytes) ^ checksum(kMixedBytes);

static_assert(kSampleBytes[0] == 0x44, "Least significant byte should come first.");
static_assert(kSampleBytes[3] == 0x11, "Most significant byte should remain in the last extracted position.");
static_assert(mix(kSampleValue, 0) == kSampleValue, "Zero rounds of mixing must be an identity.");

void printBytes(const std::array<std::uint8_t, kValueBytes>& bytes, const char* label) {
    std::cout << label << ": ";
    for (std::size_t i = 0; i < bytes.size(); ++i) {
        std::cout << "0x" << std::hex << std::setw(2) << std::setfill('0')
                  << static_cast<int>(bytes[i]) << (i + 1 == bytes.size() ? "" : " ");
    }
    std::cout << std::dec << "\n";
}

void testEndianConversion() {
    std::uint64_t value = kSampleValue;
    auto* bytes = reinterpret_cast<std::uint8_t*>(&value);

    printBytes(kSampleBytes, "Compile-time bytes");

    std::cout << "Runtime view: ";
    for (std::size_t i = 0; i < kValueBytes; ++i) {
        std::cout << "0x" << std::hex << std::setw(2) << std::setfill('0')
                  << static_cast<int>(bytes[i]) << (i + 1 == kValueBytes ? "" : " ");
    }
    std::cout << std::dec << "\n";
}

void testMixingLogic() {
    printBytes(kMixedBytes, "Mixed bytes");

    std::uint64_t rolling = 0;
    for (std::size_t i = 0; i < kMixedBytes.size(); ++i) {
        rolling = rotateLeft64(rolling + kMixedBytes[i] + (i * 3), static_cast<unsigned>((i + 1) * 2));
    }

    std::cout << "Mixed value: 0x" << std::hex << kMixedValue << std::dec << "\n";
    std::cout << "Sample checksum: 0x" << std::hex << kSampleChecksum << std::dec << "\n";
    std::cout << "Mixed checksum: 0x" << std::hex << kMixedChecksum << std::dec << "\n";
    std::cout << "Double mixed: 0x" << std::hex << kDoubleMixed << std::dec << "\n";
    std::cout << "Combined checksum: 0x" << std::hex << kCombinedChecksum << std::dec << "\n";
    std::cout << "Rolling accumulator: " << rolling << "\n";
}

int main() {
    std::cout << "=== Constexpr Debugger Demo ===\n\n";

    testEndianConversion();
    testMixingLogic();

    return 0;
}
