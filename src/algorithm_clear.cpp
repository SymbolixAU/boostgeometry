#include "R_boostgeometry.h"
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_clear( Rcpp::List wkt ) {
  Rcpp::StringVector wktClear( wkt.length() );

  CSGGeometry geom;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_cartesian_wkt( wkt[i] );
    bg::clear( geom );
    std::ostringstream os;
    os << bg::wkt( geom );
    wktClear[i] = os.str();
  }
  return wktClear;
}


