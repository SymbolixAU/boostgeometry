#include "R_boostgeometry.h"

#include <boost/geometry.hpp>

#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_difference( Rcpp::List wktOne, Rcpp::List wktTwo, const char* strategy ) {
  Rcpp::StringVector wktDifference( wktOne.length() );

  int tp;
  make_strategy(strategy, &tp);

  linestring_geographic geom1;
  linestring_geographic geom2;
  multi_linestring_geographic output;

  bg::read_wkt( wktTwo[0], geom2 );

  for (size_t i = 0; i < wktOne.length(); i++ ) {
    bg::read_wkt( wktOne[i], geom1 );

    bg::difference( geom1, geom2, output );
    std::ostringstream os;
    os << bg::wkt( output );
    wktDifference[i] = os.str();
  }

  return wktDifference;
}
