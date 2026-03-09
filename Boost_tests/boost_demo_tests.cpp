#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE module1

#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>

#define MY_ONE 1


BOOST_AUTO_TEST_SUITE(demo_suite)

    BOOST_AUTO_TEST_CASE(test_equal_1) {
        BOOST_CHECK_EQUAL(MY_ONE, 1);
    }

    // Fixture example
    struct SimpleFixture {
        SimpleFixture() : value(42) {
            BOOST_TEST_MESSAGE("Setting up fixture");
        }

        ~SimpleFixture() {
            BOOST_TEST_MESSAGE("Tearing down fixture");
        }

        int value;
    };

    BOOST_FIXTURE_TEST_CASE(test_with_fixture, SimpleFixture) {
        BOOST_CHECK_EQUAL(value, 42);
        value = 100;
        BOOST_CHECK_EQUAL(value, 100);
    }

    // Data-driven test example
    namespace bdata = boost::unit_test::data;

    BOOST_DATA_TEST_CASE(test_data_driven,
                         bdata::make({1, 2, 3, 4, 5}) ^ bdata::make({2, 4, 6, 8, 10}),
                         input, expected) {
        BOOST_CHECK_EQUAL(input * 2, expected);
    }

    //Debug test with Valgrind Memcheck
    BOOST_AUTO_TEST_CASE(test_equal_word) {
        char *name = new char[4];
        name[1] = 't';
        name[2] = 'e';
        name[3] = 's';
        name[4] = 't';

        BOOST_CHECK_EQUAL(name, "test");
    }

BOOST_AUTO_TEST_SUITE_END()

// Quick doc macro replacement - practical sample
// https://www.boost.org/doc/libs/1_41_0/libs/preprocessor/doc/ref/repeat.html
#define DECL(z, n, text) text ## n = n;
BOOST_PP_REPEAT(5, DECL, int x)
