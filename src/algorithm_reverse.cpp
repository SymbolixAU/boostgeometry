#include "R_boostgeometry.h"
#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_reverse( Rcpp::List wkt, const char* strategy ) {
  Rcpp::StringVector wktReverse( wkt.length() );

  CSGGeometry geom;
  int tp;
  make_strategy(strategy, &tp);

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_any_wkt(wkt[i], tp);
    std::ostringstream os;
    bg::reverse( geom );
    os << bg::wkt( geom );
    wktReverse[i] = os.str();
  }
  return wktReverse;
}
