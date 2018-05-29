#include "R_boostgeometry.h"
#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_correct( Rcpp::List wkt, const char* strategy ) {
  Rcpp::StringVector wktCorrect( wkt.length() );

  CSGGeometry geom;
  int tp;
  make_strategy(strategy, &tp);

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_any_wkt(wkt[i], tp);
    std::ostringstream os;
    bg::correct( geom );
    os << std::setprecision(12) << bg::wkt( geom );
    wktCorrect[i] = os.str();
  }
  return wktCorrect;
}


