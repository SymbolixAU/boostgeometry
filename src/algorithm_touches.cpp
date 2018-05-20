#include "R_boostgeometry.h"
#include <Rcpp.h>
using namespace Rcpp;

/*
Rcpp::LogicalMatrix rcpp_wkt_touches( Rcpp::List wktFrom, Rcpp::List wktTo ) {
  Rcpp::LogicalMatrix wktTouches(wktFrom.length(), wktTo.length());

  CartesianGeometry geomFrom;
  CartesianGeometry geomTo;

  for (size_t i = 0; i < wktFrom.length(); i++) {
    geomFrom = read_cartesian_wkt( wktFrom[i] );
    for (size_t j = 0; j < wktTo.length(); j++) {
      geomTo = read_cartesian_wkt( wktTo[j] );
      wktTouches(i, j) = bg::touches(geomFrom, geomTo);
    }
  }
  return wktTouches;
}
*/
