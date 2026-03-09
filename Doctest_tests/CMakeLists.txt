include(FetchContent)
FetchContent_Declare(
        Doctest
        GIT_REPOSITORY https://github.com/onqtam/doctest.git
        GIT_TAG        master
)

FetchContent_MakeAvailable(Doctest)

add_executable(doctest_runner TestMain.cpp TestBase.cpp)
target_link_libraries(doctest_runner PRIVATE doctest::doctest)

enable_testing()

add_test(NAME DoctestRunner COMMAND doctest_runner)
