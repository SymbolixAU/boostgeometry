#include "R_boostgeometry.h"

#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::NumericVector rcpp_wkt_num_geometries( Rcpp::List wkt ) {

  // TODO:
  // - account for open & closed polygons & winding?
  Rcpp::NumericVector wktNumGeometries( wkt.length() );

  // num_geometries - cartesian / spherical / geographics
  CartesianGeometry geom;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_cartesian_wkt( wkt[i] );
    wktNumGeometries[i] = bg::num_geometries(geom);
  }
  return wktNumGeometries;
}


// [[Rcpp::export]]
Rcpp::NumericVector rcpp_wkt_num_interior_rings( Rcpp::List wkt ) {
  Rcpp::NumericVector wktNumG( wkt.length() );

  // num_geometries - cartesian / spherical / geographics
  CartesianGeometry geom;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_cartesian_wkt( wkt[i] );
    wktNumG[i] = bg::num_interior_rings(geom);
  }
  return wktNumG;
}

// [[Rcpp::export]]
Rcpp::NumericVector rcpp_wkt_num_points( Rcpp::List wkt ) {
  Rcpp::NumericVector wktNumG( wkt.length() );

  // num_ponts - cartesian / spherical / geographics
  CartesianGeometry geom;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_cartesian_wkt( wkt[i] );
    wktNumG[i] = bg::num_points(geom);
  }
  return wktNumG;
}


// [[Rcpp::export]]
Rcpp::NumericVector rcpp_wkt_num_segments( Rcpp::List wkt ) {

  // TODO:
  // - account for open & closed polygons & winding?
  Rcpp::NumericVector wktNumG( wkt.length() );

  // num_segments - cartesian / spherical / geographics
  CartesianGeometry geom;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_cartesian_wkt( wkt[i] );
    wktNumG[i] = bg::num_segments(geom);
  }
  return wktNumG;
}

