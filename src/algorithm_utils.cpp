#include "R_boostgeometry.h"
#include <Rcpp.h>
using namespace Rcpp;

void make_strategy(const char* strategy, int *tp) {
  int type = 0;
  if (strcmp(strategy, "cartesian") == 0) {
    type = BG_Cartesian;
  } else if (strcmp(strategy, "spherical") == 0) {
    type = BG_Spherical;
  } else if (strcmp(strategy, "geographic") == 0) {
    type = BG_Geographic;
  } else {
    type = BG_Unknown;
  }
  if (tp != NULL) {
    *tp = type;
  }
}
