#include <boost/test/unit_test.hpp>
#define BOOST_TEST_DYN_LINK

BOOST_AUTO_TEST_SUITE( TestSuite )

BOOST_AUTO_TEST_CASE( Test1 )
{
    BOOST_CHECK( 1 == 1 );
}

BOOST_AUTO_TEST_CASE( Test2 )
{
    BOOST_CHECK( 1 == 3 );
}

BOOST_AUTO_TEST_SUITE_END()