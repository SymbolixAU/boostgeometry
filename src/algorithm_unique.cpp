
#include "R_boostgeometry_unique.h"
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_unique_cartesian( Rcpp::List wkt ) {
  Rcpp::StringVector wktUnique( wkt.length() );

  CartesianUnique geom;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_cartesian_unique_wkt( wkt[i] );
    bg::unique( geom );
    std::ostringstream os;
    os << bg::wkt( geom );
    wktUnique[i] = os.str();
  }
  return wktUnique;
}

// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_unique_spherical( Rcpp::List wkt ) {
  Rcpp::StringVector wktUnique( wkt.length() );

  SphericalUnique geom;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_spherical_unique_wkt( wkt[i] );
    bg::unique( geom );
    std::ostringstream os;
    os << bg::wkt( geom );
    wktUnique[i] = os.str();
  }
  return wktUnique;
}

// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_unique_geographic( Rcpp::List wkt ) {
  Rcpp::StringVector wktUnique( wkt.length() );

  GeographicUnique geom;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_geographic_unique_wkt( wkt[i] );
    bg::unique( geom );
    std::ostringstream os;
    os << bg::wkt( geom );
    wktUnique[i] = os.str();
  }
  return wktUnique;
}


