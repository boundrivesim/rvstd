#include <iostream>
#include <boost/icl/interval.hpp>
#include <boost/icl/interval_set.hpp>

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>


static boost::icl::interval<double>::type interval1(0.0, 100.0);
static boost::icl::interval<double>::type interval2(10.0, 90.0);

boost::icl::interval_set<double> intersection_set;
boost::icl::interval_set<double> union_set;
boost::icl::interval_set<double> difference_set;


TEST_CASE("main") {

    BENCHMARK("Interval") {
        boost::icl::interval<double>::type interval1(34.5, 78.9);
        return 0;
    };

    BENCHMARK("Intersection") {
        intersection_set = static_cast< boost::icl::interval_set<double> >(interval1) & static_cast< boost::icl::interval_set<double> >(interval2);
        return 0;
    };

    BENCHMARK("Union") {
        union_set = static_cast< boost::icl::interval_set<double> >(interval1) + static_cast< boost::icl::interval_set<double> >(interval2);
        return 0;
    };

    BENCHMARK("Difference") {
        difference_set = static_cast< boost::icl::interval_set<double> >(interval1) - static_cast< boost::icl::interval_set<double> >(interval2);
        return 0;
    };
    
}











