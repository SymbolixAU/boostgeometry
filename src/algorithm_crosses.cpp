#include "R_boostgeometry_crosses.h"
#include "R_boostgeometry_rtree.h"

#include <Rcpp.h>
using namespace Rcpp;

//TODO(variants not supported)

// [[Rcpp::export]]
Rcpp::LogicalMatrix rcpp_wkt_crosses_cartesian( Rcpp::List x, Rcpp::List y ) {
  Rcpp::LogicalMatrix wktCrosses( x.length(), y.length() );

  CartesianCrossesOne geom1;
  CartesianCrossesTwo geom2;

  for (size_t i = 0; i < x.length(); i++) {
    geom1 = read_cartesian_crosses_one_wkt( x[i] );
    for (size_t j = 0; j < y.length(); j++) {
      geom2 = read_cartesian_crosses_two_wkt( y[j] );
      wktCrosses(i, j) = bg::crosses(geom1, geom2);
    }
  }
  return wktCrosses;
}

// [[Rcpp::export]]
Rcpp::LogicalMatrix rcpp_wkt_crosses_spherical( Rcpp::List x, Rcpp::List y ) {
  Rcpp::LogicalMatrix wktCrosses( x.length(), y.length() );

  SphericalCrossesOne geom1;
  SphericalCrossesTwo geom2;

  for (size_t i = 0; i < x.length(); i++) {
    geom1 = read_spherical_crosses_one_wkt( x[i] );
    for (size_t j = 0; j < y.length(); j++) {
      geom2 = read_spherical_crosses_two_wkt( y[j] );
      wktCrosses(i, j) = bg::crosses(geom1, geom2);
    }
  }
  return wktCrosses;
}

// [[Rcpp::export]]
Rcpp::LogicalMatrix rcpp_wkt_crosses_geographic( Rcpp::List x, Rcpp::List y ) {
  Rcpp::LogicalMatrix wktCrosses( x.length(), y.length() );

  GeographicCrossesOne geom1;
  GeographicCrossesTwo geom2;

  for (size_t i = 0; i < x.length(); i++) {
    geom1 = read_geographic_crosses_one_wkt( x[i] );
    for (size_t j = 0; j < y.length(); j++) {
      geom2 = read_geographic_crosses_two_wkt( y[j] );
      wktCrosses(i, j) = bg::crosses(geom1, geom2);
    }
  }
  return wktCrosses;
}

