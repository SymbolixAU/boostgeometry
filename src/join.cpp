
#include "R_boostgeometry_rtree.h"

#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::List rcpp_spatial_predicate_cartesian( Rcpp::List wktOne, Rcpp::List wktTwo, std::string predicate ) {

  Rcpp::Rcout << "inside rcpp" << std::endl;

  Rcpp::List res( wktTwo.size() );
  bgi::rtree< CartesianBoxUnsignedValue, bgi::quadratic<16> > rtree;

  fill_cartesian_rtree( wktOne, rtree );

  for (size_t i = 0; i < wktTwo.size(); i++) {

    std::vector<CartesianBoxUnsignedValue> result_s;
    std::string thisWkt = wktTwo[i];

    if ( predicate == "intersects") {
      query_intersects_cartesian( thisWkt, result_s, rtree );
    } else if ( predicate == "within") {
      query_within_cartesian( thisWkt, result_s, rtree );
    }

    Rcpp::IntegerVector iv( result_s.size() );
    int counter = 0;
    for (auto r : result_s) {
      iv[counter] = r.second + 1;  // 1-index
      counter++;
    }
    res[i] = iv;
  }
  return res;
}
