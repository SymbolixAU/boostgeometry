#include "R_boostgeometry.h"
#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
Rcpp::NumericMatrix rcpp_distance_test(Rcpp::List wktFrom, Rcpp::List wktTo) {
  Rcpp::NumericMatrix wktDistance(wktFrom.length(), wktTo.length());
  multi_polygon_geographic geomFrom;
  multi_polygon_geographic geomTo;

  for (size_t i = 0; i < wktFrom.length(); i++) {
    bg::read_wkt( wktFrom[i], geomFrom );

    for (size_t j = 0; j < wktTo.length(); j++) {
      bg::read_wkt( wktTo[j], geomTo );
      wktDistance(i, j) = bg::distance(geomFrom, geomTo);
    }
  }
  return wktDistance;
}


// [[Rcpp::export]]
Rcpp::NumericMatrix rcpp_wkt_distance_cartesian( Rcpp::List wktFrom, Rcpp::List wktTo ) {
  Rcpp::NumericMatrix wktDistance(wktFrom.length(), wktTo.length());

  CartesianGeometry geomFrom;
  CartesianGeometry geomTo;

  for (size_t i = 0; i < wktFrom.length(); i++) {
    geomFrom = read_cartesian_wkt( wktFrom[i] );
    for (size_t j = 0; j < wktTo.length(); j++) {
      geomTo = read_cartesian_wkt( wktTo[j] );
      wktDistance(i, j) = bg::distance(geomFrom, geomTo);
    }
  }
  return wktDistance;
}

// [[Rcpp::export]]
Rcpp::NumericMatrix rcpp_wkt_distance_spherical( Rcpp::List wktFrom, Rcpp::List wktTo ) {
  Rcpp::NumericMatrix wktDistance(wktFrom.length(), wktTo.length());

  SphericalGeometry geomFrom;
  SphericalGeometry geomTo;

  for (size_t i = 0; i < wktFrom.length(); i++) {
    geomFrom = read_spherical_wkt( wktFrom[i] );
    for (size_t j = 0; j < wktTo.length(); j++) {
      geomTo = read_spherical_wkt( wktTo[j] );
      wktDistance(i, j) = bg::distance(geomFrom, geomTo);
    }
  }
  return wktDistance;
}

// [[Rcpp::export]]
Rcpp::NumericMatrix rcpp_wkt_distance_geographic( Rcpp::List wktFrom, Rcpp::List wktTo ) {
  Rcpp::NumericMatrix wktDistance(wktFrom.length(), wktTo.length());

  GeographicGeometry geomFrom;
  GeographicGeometry geomTo;

  for (size_t i = 0; i < wktFrom.length(); i++) {
    geomFrom = read_geographic_wkt( wktFrom[i] );
    for (size_t j = 0; j < wktTo.length(); j++) {
      geomTo = read_geographic_wkt( wktTo[j] );
      wktDistance(i, j) = bg::distance(geomFrom, geomTo);
    }
  }
  return wktDistance;
}

