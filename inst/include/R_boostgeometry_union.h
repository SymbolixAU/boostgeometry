#ifndef R_BOOSTGEOMETRY_UNION_H
#define R_BOOSTGEOMETRY_UNION_H

#include "R_boostgeometry.h"
#include <Rcpp.h>
using namespace Rcpp;

typedef boost::variant<
//  point_cartesian
//  , multi_point_cartesian
//  , linestring_cartesian
//  multi_linestring_cartesian
   polygon_cartesian
  , multi_polygon_cartesian
> CartesianUnion;

template <typename Variant = CartesianUnion>
Variant read_cartesian_union_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

#endif

