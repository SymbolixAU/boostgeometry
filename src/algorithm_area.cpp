#include "R_boostgeometry.h"
#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
Rcpp::NumericVector rcpp_wkt_area( Rcpp::List wkt, const char* strategy ) {
  Rcpp::NumericVector wktArea( wkt.length() );

  // AREA: cartesian / spherical / geographic
  CSGGeometry geom;
  int tp;
  make_strategy(strategy, &tp);

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_any_wkt(wkt[i], tp);
    std::ostringstream os;
    wktArea[i] = bg::area(geom);
  }
  return wktArea;
}

