#ifndef R_BOOSTGEOMETRY_EQUALS_H
#define R_BOOSTGEOMETRY_EQUALS_H

#include "R_boostgeometry.h"

namespace bg = boost::geometry;
namespace bgm = boost::geometry::model;

// https://www.boost.org/doc/libs/1_67_0/libs/geometry/doc/html/geometry/reference/algorithms/equals/equals_2.html

/*
typedef boost::variant<
  point_cartesian
  //, multi_point_cartesian
  , linestring_cartesian
  //, multi_linestring_cartesian
  //, polygon_cartesian
  //, multi_polygon_cartesian
> CartesianEquals;

template <typename Variant = CartesianEquals>
Variant read_cartesian_equals_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}
*/

#endif
