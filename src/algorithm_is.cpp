#include "R_boostgeometry.h"
#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
Rcpp::NumericVector rcpp_wkt_is_empty( Rcpp::List wkt, const char* strategy ) {
  Rcpp::NumericVector wktEmpty( wkt.length() );

  // IS_EMPTY: cartesian / spherical / geographic
  CSGGeometry geom;
  int tp;
  make_strategy(strategy, &tp);

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_any_wkt( wkt[i], tp );
    wktEmpty[i] = bg::is_empty(geom);
  }
  return wktEmpty;
}

// [[Rcpp::export]]
Rcpp::NumericVector rcpp_wkt_is_simple( Rcpp::List wkt, const char* strategy ) {
  Rcpp::NumericVector wktSimple( wkt.length() );

  // IS_SIMPLE: cartesian / spherical / geographic
  CSGGeometry geom;
  int tp;
  make_strategy(strategy, &tp);

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_any_wkt( wkt[i], tp );
    wktSimple[i] = bg::is_simple(geom);
  }
  return wktSimple;
}

// [[Rcpp::export]]
Rcpp::NumericVector rcpp_wkt_is_valid( Rcpp::List wkt, const char* strategy ) {
  Rcpp::NumericVector wktValid( wkt.length() );
  // TODO(other is_valid implementations)
  // IS_EMPTY: cartesian / spherical / geographic
  CSGGeometry geom;
  int tp;
  make_strategy(strategy, &tp);

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_any_wkt( wkt[i], tp );
    wktValid[i] = bg::is_valid(geom);
  }
  return wktValid;
}


