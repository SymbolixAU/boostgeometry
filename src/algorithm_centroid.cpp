#include "R_boostgeometry.h"

#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_centroid( Rcpp::List wkt ) {
  Rcpp::StringVector wktCentroid( wkt.length() );

  // Centroid - cartesian only
  point_cartesian pt;
  CartesianGeometry geom;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_cartesian_wkt( wkt[i] );
    bg::centroid( geom, pt );
    std::ostringstream os;
    os << std::setprecision(12) << bg::wkt( pt );
    wktCentroid[i] = os.str();
  }
  return wktCentroid;
}


