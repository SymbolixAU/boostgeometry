#include "R_boostgeometry.h"
#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
Rcpp::NumericVector rcpp_wkt_comparable_distance_cartesian( Rcpp::List wktFrom, Rcpp::List wktTo ) {
  Rcpp::NumericVector wktNearest(wktFrom.length());

  CartesianGeometry geomFrom;
  CartesianGeometry geomTo;

  for (size_t i = 0; i < wktFrom.length(); i++) {
    double min_d = boost::numeric::bounds<double>::highest();
    geomFrom = read_cartesian_wkt( wktFrom[i] );

    for (size_t j = 0; j < wktTo.length(); j++) {
      geomTo = read_cartesian_wkt( wktTo[j] );
      double d = bg::comparable_distance(geomFrom, geomTo);
      if (d < min_d) {
        min_d = d;
        wktNearest[i] = j;
      }
    }
  }
  return wktNearest;
}

// [[Rcpp::export]]
Rcpp::NumericVector rcpp_wkt_comparable_distance_spherical( Rcpp::List wktFrom, Rcpp::List wktTo ) {
  Rcpp::NumericVector wktNearest(wktFrom.length());

  SphericalGeometry geomFrom;
  SphericalGeometry geomTo;

  for (size_t i = 0; i < wktFrom.length(); i++) {
    double min_d = boost::numeric::bounds<double>::highest();
    geomFrom = read_spherical_wkt( wktFrom[i] );

    for (size_t j = 0; j < wktTo.length(); j++) {
      geomTo = read_spherical_wkt( wktTo[j] );
      double d = bg::comparable_distance(geomFrom, geomTo);
      if (d < min_d) {
        min_d = d;
        wktNearest[i] = j;
      }
    }
  }
  return wktNearest;
}


// [[Rcpp::export]]
Rcpp::NumericVector rcpp_wkt_comparable_distance_geographic( Rcpp::List wktFrom, Rcpp::List wktTo ) {
  Rcpp::NumericVector wktNearest(wktFrom.length());

  GeographicGeometry geomFrom;
  GeographicGeometry geomTo;

  for (size_t i = 0; i < wktFrom.length(); i++) {
    double min_d = boost::numeric::bounds<double>::highest();
    geomFrom = read_geographic_wkt( wktFrom[i] );

    for (size_t j = 0; j < wktTo.length(); j++) {
      geomTo = read_geographic_wkt( wktTo[j] );
      double d = bg::comparable_distance(geomFrom, geomTo);
      if (d < min_d) {
        min_d = d;
        wktNearest[i] = j;
      }
    }
  }
  return wktNearest;
}

