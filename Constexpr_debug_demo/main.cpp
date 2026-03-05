#include <iostream>


/**
 * Determines if a given integer is a prime number.
 *
 * A prime number is a natural number greater than 1 that has no positive divisors
 * other than 1 and itself. This function checks divisibility starting from 2 up
 * to the square root of the given integer (inclusive). For efficiency, it skips
 * even numbers greater than 2.
 *
 * @param i The integer to be checked for primality.
 * @return True if the integer is a prime number, otherwise false.
 */
constexpr bool is_prime(const int i) {
    if (i < 2) return false;
    if (i == 2) return true;
    if (i % 2 == 0) return false;
    for (int d = 3; d * d <= i; d += 2) {
        if (i % d == 0) return false;
    }
    return true;
}


/**
 * Computes the count of prime numbers less than the given number.
 *
 * This function iterates through all integers from 0 to the specified number
 * (exclusive) and checks each integer for primality. If the number is determined
 * to be a prime, it is added to the count, which is ultimately returned.
 *
 * @param given_number The upper limit (exclusive) up to which prime numbers
 *                     are counted.
 * @return The number of prime numbers less than the specified upper limit.
 */
constexpr int sum_of_prime_numbers(int given_number) {
    int result = 0;
    for (int i = 0; i < given_number; ++i) {
        if (is_prime(i))
            result++;
    }
    return result;
}

int main() {
    std::string hello_world = "Hello, World!";
    constexpr int sum = sum_of_prime_numbers(100);

    std::cout << hello_world << std::endl;
    return 0;
}