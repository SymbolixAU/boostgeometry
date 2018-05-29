#include "R_boostgeometry_simplify.h"
#include <Rcpp.h>
using namespace Rcpp;

// TODO(other geometries)

// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_simplify_cartesian( Rcpp::List wkt, double distance) {
  Rcpp::StringVector wktSimplify( wkt.length() );

  CartesianSimplify geom;
  CartesianSimplify geomSimplified;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_cartesian_simplify_wkt( wkt[i] );
    std::ostringstream os;
    bg::simplify(geom, geomSimplified, distance);
    os << std::setprecision(12) << bg::wkt( geomSimplified );
    wktSimplify[i] = os.str();
  }
  return wktSimplify;
}


// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_simplify_spherical( Rcpp::List wkt, double distance) {
  Rcpp::StringVector wktSimplify( wkt.length() );

  SphericalSimplify geom;
  SphericalSimplify geomSimplified;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_spherical_simplify_wkt( wkt[i] );
    std::ostringstream os;
    bg::simplify(geom, geomSimplified, distance);
    os << std::setprecision(12) << bg::wkt( geomSimplified );
    wktSimplify[i] = os.str();
  }
  return wktSimplify;
}

/*
Rcpp::StringVector rcpp_wkt_simplify_geographic( Rcpp::List wkt, double distance) {
  Rcpp::StringVector wktSimplify( wkt.length() );

  GeographicSimplify geom;
  GeographicSimplify geomSimplified;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_geographic_simplify_wkt( wkt[i] );
    std::ostringstream os;
    bg::simplify(geom, geomSimplified, distance);
    os << std::setprecision(12) << bg::wkt( geomSimplified );
    wktSimplify[i] = os.str();
  }
  return wktSimplify;
}
*/
