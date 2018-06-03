#ifndef R_BOOSTGEOMETRY_OVERLAPS_H
#define R_BOOSTGEOMETRY_OVERLAPS_H

#include "R_boostgeometry.h"

namespace bg = boost::geometry;
namespace bgm = boost::geometry::model;

typedef boost::variant<
  point_cartesian
  , linestring_cartesian
  , multi_linestring_cartesian
  , polygon_cartesian
> CSGDisjointGeometry;

template <typename Variant = CSGDisjointGeometry>
Variant read_cartesian_disjoint_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

#endif
