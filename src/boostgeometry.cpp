#include "R_boostgeometry.h"
#include <Rcpp.h>
using namespace Rcpp;


std::string geomFromWKT(std::string& pl) {
  size_t s = pl.find_first_of("(");
  std::string geom = pl.substr(0, s);
  boost::trim(geom);
  return geom;
}
