#include "R_boostgeometry_equals.h"
#include <Rcpp.h>
using namespace Rcpp;

// TODO(not fully supported)

/*
Rcpp::LogicalMatrix rcpp_wkt_equals( Rcpp::List x, Rcpp::List y) {
  Rcpp::LogicalMatrix wktEquals( x.length(), y.length() );

  CartesianEquals geom1;
  CartesianEquals geom2;

  for (size_t i = 0; i < x.length(); i++) {
    geom1 = read_cartesian_equals_wkt( x[i] );
    for (size_t j = 0; j < y.length(); j++) {
      geom2 = read_cartesian_equals_wkt( y[j] );
      wktEquals(i, j) = bg::equals(geom1, geom2);
    }
  }

  return wktEquals;
}
*/
