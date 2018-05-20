#include "R_boostgeometry.h"
#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
Rcpp::NumericVector rcpp_wkt_perimeter_cartesian( Rcpp::List wkt  ) {
  Rcpp::NumericVector wktPerimeter( wkt.length() );

  // PERIMETER: cartesian / spherical / geographic
  CartesianGeometry geom;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_cartesian_wkt( wkt[i] );
    wktPerimeter[i] = bg::perimeter( geom );
  }
  return wktPerimeter;
}


// [[Rcpp::export]]
Rcpp::NumericVector rcpp_wkt_perimeter_spherical( Rcpp::List wkt  ) {
  Rcpp::NumericVector wktPerimeter( wkt.length() );

  // PERIMETER: cartesian / spherical / geographic
  SphericalGeometry geom;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_spherical_wkt( wkt[i] );
    wktPerimeter[i] = bg::perimeter( geom );
  }
  return wktPerimeter;
}

// [[Rcpp::export]]
Rcpp::NumericVector rcpp_wkt_perimeter_geographic( Rcpp::List wkt  ) {
  Rcpp::NumericVector wktPerimeter( wkt.length() );

  // PERIMETER: cartesian / spherical / geographic
  GeographicGeometry geom;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_geographic_wkt( wkt[i] );
    wktPerimeter[i] = bg::perimeter( geom );
  }
  return wktPerimeter;
}
