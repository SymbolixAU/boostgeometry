#include "R_boostgeometry.h"
#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
Rcpp::LogicalMatrix rcpp_wkt_intersects_cartesian( Rcpp::List wktOne, Rcpp::List wktTwo ) {
  Rcpp::LogicalMatrix wktIntersects( wktOne.length(), wktTwo.length() );

  CartesianGeometry geomOne;
  CartesianGeometry geomTwo;

  for (size_t i = 0; i < wktOne.length(); i++ ) {
    geomOne = read_cartesian_wkt( wktOne[i] );

    for (size_t j = 0; j < wktTwo.length(); j++ ){
      geomTwo = read_cartesian_wkt( wktTwo[j] );
      wktIntersects(i, j) = bg::intersects(geomOne, geomTwo);
    }
  }
  return wktIntersects;
}

// [[Rcpp::export]]
Rcpp::LogicalMatrix rcpp_wkt_intersects_spherical( Rcpp::List wktOne, Rcpp::List wktTwo ) {
  Rcpp::LogicalMatrix wktIntersects( wktOne.length(), wktTwo.length() );

  SphericalGeometry geomOne;
  SphericalGeometry geomTwo;

  for (size_t i = 0; i < wktOne.length(); i++ ) {
    geomOne = read_spherical_wkt( wktOne[i] );

    for (size_t j = 0; j < wktTwo.length(); j++ ){
      geomTwo = read_spherical_wkt( wktTwo[j] );
      wktIntersects(i, j) = bg::intersects(geomOne, geomTwo);
    }
  }
  return wktIntersects;
}

/*
// [[Rcpp::export]]
Rcpp::LogicalMatrix rcpp_wkt_intersects_geographic( Rcpp::List wktOne, Rcpp::List wktTwo ) {
  Rcpp::LogicalMatrix wktIntersects( wktOne.length(), wktTwo.length() );

  GeographicGeometry geomOne;
  GeographicGeometry geomTwo;

  for (size_t i = 0; i < wktOne.length(); i++ ) {
    geomOne = read_geographic_wkt( wktOne[i] );

    for (size_t j = 0; j < wktTwo.length(); j++ ){
      geomTwo = read_geographic_wkt( wktTwo[j] );
      wktIntersects(i, j) = bg::intersects(geomOne, geomTwo);
    }
  }
  return wktIntersects;
}
*/
