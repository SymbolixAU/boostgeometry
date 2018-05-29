#include "R_boostgeometry_union.h"
#include <Rcpp.h>
using namespace Rcpp;

/*
// TODO:
// - accept one 'list' of geometries, or two?
// - if one, all geometries will get 'unioned'


Rcpp::StringVector rcpp_wkt_union( Rcpp::List wkt ) {
  Rcpp::StringVector wktUnion;

  CartesianUnion geom;
  multi_polygon_cartesian mp;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_cartesian_union_wkt( wkt[i] );
    bg::union_(geom, mp, mp);
  }
  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( mp );
  wktUnion = os.str();
  return wktUnion;
}
*/
