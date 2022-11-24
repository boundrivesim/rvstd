#include "../../include/rvstd/bool_and_vec/interval_set_sweep_line.hpp"
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <string>

#define ns rvstd::bool_and_vec_sweep_line

template< typename T >
void print_interval_set( ns::interval_set< T > C, std::string message )
{
   std::vector< T > C_vec = C.get_data_vector();
   bool C_init = C.get_init();
   std::cout << message << " :  init = " << C_init << " vec = {";
   for( int i = 0; i < C_vec.size(); i++ ) {
      std::cout << " " << C_vec[ i ] << " ";
   }
   std::cout << "}\n";
}

TEST_CASE( "bool_and_vec/sweep_line  different intensity 0" )
{
   ns::interval_set< int > A = { { -99, -98 }, { -97, -96 }, { -95, -94 }, { -93, -92 }, { -80, 0 }, { 2, 5 }, { 6, 17 }, { 42, 47 }, { 59, 67 }, { 85, 89 }, { 97, 100 } };
   ns::interval_set< int > B = { { -94, -80 }, { -79, -78 }, { -77, -76 }, { -75, -74 }, { -73, -72 }, { -71, -70 }, { -69, -68 }, { -67, -66 }, { -65, -64 }, { 1, 100 } };

   BENCHMARK( "Union" )
   {
      A + B;
      return 0;
   };

   BENCHMARK( "Intersect" )
   {
      A& B;
      return 0;
   };

   BENCHMARK( "Difference" )
   {
      A - B;
      return 0;
   };
   std::cout << "\n";
   print_interval_set( A + B, "A + B" );
   print_interval_set( A - B, "A - B" );
   print_interval_set( A & B, "A & B" );
}

TEST_CASE( "bool_and_vec/sweep_line  different intensity 1" )
{
   ns::interval_set< int > A = { { -905, -667 }, { -622, -614 }, { -592, -585 }, { -583, -493 }, { -476, -299 }, { -295, -281 }, { -174, -56 }, { 86, 132 }, { 191, 287 }, { 320, 366 }, { 440, 514 }, { 563, 622 }, { 650, 749 }, { 820, 924 }, { 934, 975 } };
   ns::interval_set< int > B = { { -50, -49 }, { -44, -41 }, { -37, -29 }, { -24, -18 }, { -16, -13 }, { -12, -10 }, { -8, -6 }, { -2, 9 }, { 10, 17 }, { 19, 20 }, { 21, 23 }, { 30, 40 }, { 41, 42 }, { 47, 48 }, { 49, 50 } };

   BENCHMARK( "Union" )
   {
      A + B;
      return 0;
   };

   BENCHMARK( "Intersect" )
   {
      A& B;
      return 0;
   };

   BENCHMARK( "Difference" )
   {
      A - B;
      return 0;
   };
   std::cout << "\n";
   print_interval_set( A + B, "A + B" );
   print_interval_set( A - B, "A - B" );
   print_interval_set( A & B, "A & B" );
}

TEST_CASE( "bool_and_vec/sweep_line  different intensity 2" )
{
   ns::interval_set< int > A = { { -905, -667 }, { -622, -614 }, { -592, -585 }, { -583, -493 }, { -476, -299 }, { -295, -281 }, { -174, -156 }, { -86, 132 }, { 191, 287 }, { 320, 366 }, { 440, 514 }, { 563, 622 }, { 650, 749 }, { 820, 924 }, { 934, 975 } };
   ns::interval_set< int > B = { { -50, -49 }, { -44, -41 }, { -37, -29 }, { -24, -18 }, { -16, -13 }, { -12, -10 }, { -8, -6 }, { -2, 9 }, { 10, 17 }, { 19, 20 }, { 21, 23 }, { 30, 40 }, { 41, 42 }, { 47, 48 }, { 49, 50 } };

   BENCHMARK( "Union" )
   {
      A + B;
      return 0;
   };

   BENCHMARK( "Intersect" )
   {
      A& B;
      return 0;
   };

   BENCHMARK( "Difference" )
   {
      A - B;
      return 0;
   };
   std::cout << "\n";
   print_interval_set( A + B, "A + B" );
   print_interval_set( A - B, "A - B" );
   print_interval_set( A & B, "A & B" );
}

TEST_CASE( "bool_and_vec/sweep_line  large sets" )
{
   bool A_bool = false;
   bool B_bool = false;
   ns::interval_set< int > A( A_bool );
   ns::interval_set< int > B( B_bool );

   for( int i = -1000; i < 1000; i += 7 ) {
      A_bool = ( !A_bool );
      A.append( i, A_bool );
   }

   for( int i = -1000; i < 1000; i += 11 ) {
      B_bool = ( !B_bool );
      B.append( i, B_bool );
   }
   BENCHMARK( "Union" )
   {
      A + B;
      return 0;
   };

   BENCHMARK( "Intersect" )
   {
      A& B;
      return 0;
   };

   BENCHMARK( "Difference" )
   {
      A - B;
      return 0;
   };
   std::cout << "\n";
   print_interval_set( A, "A" );
   print_interval_set( B, "B" );
   print_interval_set( A + B, "A + B" );
   print_interval_set( A - B, "A - B" );
   print_interval_set( A & B, "A & B" );
}

TEST_CASE( "bool_and_vec/sweep_line  rare cases" )
{
   ns::interval_set< int > A = { { -99, -95 }, { -93, -89 }, { -82, -80 }, { -66, -58 }, { -55, -52 }, { -42, -34 }, { -33, -15 }, { -13, -11 }, { -5, -1 }, { 2, 5 }, { 6, 17 }, { 42, 47 }, { 59, 67 }, { 85, 89 }, { 97, 100 } };

   ns::interval_set< int > not_A = not( A );

   ns::interval_set< int > NULL_( false );

   BENCHMARK( "Union with itself" )
   {
      A + A;
      return 0;
   };

   BENCHMARK( "Union with NULL" )
   {
      A + NULL_;
      return 0;
   };

   BENCHMARK( "Union with complementary" )
   {
      A + not_A;
      return 0;
   };

   BENCHMARK( "Difference by itself" )
   {
      A - A;
      return 0;
   };

   BENCHMARK( "Intersection by itself" )
   {
      A& A;
      return 0;
   };
   std::cout << "\n";
   print_interval_set( A, "A" );
   print_interval_set( not_A, "not_A" );
   print_interval_set( A + A, "A + A" );
   print_interval_set( A + NULL_, "A + NULL_" );
   print_interval_set( A + not_A, "A + not_A" );
   print_interval_set( A - A, "A - A" );
   print_interval_set( A & A, "A& A" );
}

TEST_CASE( "bool_and_vec/sweep_line  basic double" )
{
   ns::interval_set< double > A = { { -9.99898498, -9.554985 }, { -9.36546, -8.987 }, { -8.2, -8.05688 }, { -6.66868, -5.84 }, { -5.5999999, -5.2546 }, { -4.22232, -3.4111111 }, { -3.33, -1.52 }, { -1.364895, -1.1389595 }, { -0.525959, -0.16 }, { 0.2999999, 0.500000 }, { 0.6322312, 1.711235 }, { 4.22359, 4.79595 }, { 5.999999, 6.79999 }, { 8.59999, 8.999595 }, { 9.723135, 10.046646122 } };
   ns::interval_set< double > B = { { -9.40404040, -8.012151 }, { -5.9526252, -4.86544848 }, { -4.065888, -3.835595952 }, { -2.3122, -0.9956 }, { 0.6926, 1.2965 }, { 2.3658489, 3.889529 }, { 4.6456289, 5.98959595 }, { 6.3123595, 6.987654 }, { 7.2232826, 8.93595 }, { 9.166666, 9.2126888 } };

   BENCHMARK( "Union" )
   {
      A + B;
      return 0;
   };

   BENCHMARK( "Intersect" )
   {
      A& B;
      return 0;
   };

   BENCHMARK( "Difference" )
   {
      A - B;
      return 0;
   };

   BENCHMARK( "Not" )
   {
      not( A );
      return 0;
   };

   BENCHMARK( "at" )
   {
      A.at( -8.262626 );
   };

   std::cout << "\n";
   print_interval_set( A + B, "A + B" );
   print_interval_set( A - B, "A - B" );
   print_interval_set( A & B, "A & B" );
   print_interval_set( not( A ), "not(A)" );
}

TEST_CASE( "bool_and_vec/sweep_line  basic" )
{
   ns::interval_set< int > A = { { -99, -95 }, { -93, -89 }, { -82, -80 }, { -66, -58 }, { -55, -52 }, { -42, -34 }, { -33, -15 }, { -13, -11 }, { -5, -1 }, { 2, 5 }, { 6, 17 }, { 42, 47 }, { 59, 67 }, { 85, 89 }, { 97, 100 } };
   ns::interval_set< int > B = { { -94, -80 }, { -59, -48 }, { -40, -38 }, { -23, -9 }, { 6, 12 }, { 23, 38 }, { 46, 59 }, { 63, 69 }, { 72, 89 }, { 91, 92 } };

   BENCHMARK( "Union" )
   {
      A + B;
      return 0;
   };

   BENCHMARK( "Intersect" )
   {
      A& B;
      return 0;
   };

   BENCHMARK( "Difference" )
   {
      A - B;
      return 0;
   };

   BENCHMARK( "Not" )
   {
      not( A );
      return 0;
   };

   BENCHMARK( "at" )
   {
      A.at( 44 );
   };

   std::cout << "\n";
   print_interval_set( A + B, "A + B" );
   print_interval_set( A - B, "A - B" );
   print_interval_set( A & B, "A & B" );
   print_interval_set( not( A ), "not(A)" );
}
