#include "R_boostgeometry.h"

#include <Rcpp.h>
using namespace Rcpp;

//TODO(length calculation strategies)

// [[Rcpp::export]]
Rcpp::NumericVector rcpp_wkt_length_cartesian( Rcpp::List wkt ) {
  Rcpp::NumericVector wktLength( wkt.length() );

  // length:
  CartesianGeometry geom;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_cartesian_wkt(wkt[i]);
    wktLength[i] = bg::length( geom );   // using default strategy
    //wktLength[i] = bg::length(geom,bg::strategy::distance::haversine<float>(boostgeometry::EARTH_RADIUS));  // providing a strategy
  }
  return wktLength;
}

// [[Rcpp::export]]
Rcpp::NumericVector rcpp_wkt_length_spherical( Rcpp::List wkt ) {
  Rcpp::NumericVector wktLength( wkt.length() );

  // length:
  SphericalGeometry geom;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_spherical_wkt(wkt[i]);
    wktLength[i] = bg::length( geom );   // using default strategy
    //wktLength[i] = bg::length(geom,bg::strategy::distance::haversine<float>(boostgeometry::EARTH_RADIUS));  // providing a strategy
  }
  return wktLength;
}

// [[Rcpp::export]]
Rcpp::NumericVector rcpp_wkt_length_geographic( Rcpp::List wkt ) {
  Rcpp::NumericVector wktLength( wkt.length() );

  // length:
  GeographicGeometry geom;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_geographic_wkt(wkt[i]);
    wktLength[i] = bg::length( geom );   // using default strategy
    //wktLength[i] = bg::length(geom,bg::strategy::distance::haversine<float>(boostgeometry::EARTH_RADIUS));  // providing a strategy
  }
  return wktLength;
}














