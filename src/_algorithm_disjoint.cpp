#include "R_boostgeometry_disjoint.h"
#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
Rcpp::LogicalMatrix rcpp_wkt_disjoint( Rcpp::List wktOne, Rcpp::List wktTwo ) {
  Rcpp::LogicalMatrix wktDisjoint( wktOne.length(), wktTwo.length() );

  CSGDisjointGeometry geomOne;
  CSGDisjointGeometry geomTwo;

  for (size_t i = 0; i < wktOne.length(); i++ ) {
    geomOne = read_cartesian_disjoint_wkt( wktOne[i] );

    for (size_t j = 0; j < wktTwo.length(); j++ ){
      geomTwo = read_cartesian_disjoint_wkt( wktTwo[j] );
      wktDisjoint(i, j) = bg::disjoint(geomOne, geomTwo);
    }
  }
  return wktDisjoint;
}
