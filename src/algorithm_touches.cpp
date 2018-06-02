#include "R_boostgeometry_touches.h"
#include <Rcpp.h>
using namespace Rcpp;

// point >> point
// point !! multipoint
// point >> line
// point >> multiline
// point >> polygon
// point >> multi_polygon

// line >> polygon

// multipoint !! point
// multipoint !! multipoint
// multipoint >> linestring
// multipoint >> multilinestring
// multipoint >> polygon
// multipoint >> multipolygon

// [[Rcpp::export]]
Rcpp::LogicalMatrix rcpp_wkt_touches_cartesian( Rcpp::List wktFrom, Rcpp::List wktTo ) {
  Rcpp::LogicalMatrix wktTouches( wktFrom.length(), wktTo.length() );

  CartesianTouches geomFrom;
  CartesianTouches geomTo;

  for (size_t i = 0; i < wktFrom.length(); i++) {
    geomFrom = read_cartesian_touches_wkt( wktFrom[i] );

    for (size_t j = 0; j < wktTo.length(); j++) {
      geomTo = read_cartesian_touches_wkt( wktTo[j] );

      wktTouches(i, j) = bg::touches(geomFrom, geomTo);
    }
  }
  return wktTouches;
}

// [[Rcpp::export]]
Rcpp::LogicalMatrix rcpp_wkt_touches_spherical( Rcpp::List wktFrom, Rcpp::List wktTo ) {
  Rcpp::LogicalMatrix wktTouches( wktFrom.length(), wktTo.length() );

  SphericalTouches geomFrom;
  SphericalTouches geomTo;

  for (size_t i = 0; i < wktFrom.length(); i++) {
    geomFrom = read_spherical_touches_wkt( wktFrom[i] );

    for (size_t j = 0; j < wktTo.length(); j++) {
      geomTo = read_spherical_touches_wkt( wktTo[j] );

      wktTouches(i, j) = bg::touches(geomFrom, geomTo);
    }
  }
  return wktTouches;
}

// [[Rcpp::export]]
Rcpp::LogicalMatrix rcpp_wkt_touches_geographic( Rcpp::List wktFrom, Rcpp::List wktTo ) {
  Rcpp::LogicalMatrix wktTouches( wktFrom.length(), wktTo.length() );

  GeographicTouches geomFrom;
  GeographicTouches geomTo;

  for (size_t i = 0; i < wktFrom.length(); i++) {
    geomFrom = read_geographic_touches_wkt( wktFrom[i] );

    for (size_t j = 0; j < wktTo.length(); j++) {
      geomTo = read_geographic_touches_wkt( wktTo[j] );

      wktTouches(i, j) = bg::touches(geomFrom, geomTo);
    }
  }
  return wktTouches;
}

