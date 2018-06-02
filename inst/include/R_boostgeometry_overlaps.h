#ifndef R_BOOSTGEOMETRY_OVERLAPS_H
#define R_BOOSTGEOMETRY_OVERLAPS_H

#include "R_boostgeometry.h"

namespace bg = boost::geometry;
namespace bgm = boost::geometry::model;

typedef boost::variant<
  point_cartesian
  , multi_point_cartesian
> CartesianPointOverlaps;

typedef boost::variant<
  linestring_cartesian
  , multi_linestring_cartesian
> CartesianLineOverlaps;

typedef boost::variant<
  polygon_cartesian
  , multi_polygon_cartesian
> CartesianPolygonOverlaps;

template <typename Variant = CartesianPointOverlaps>
Variant read_cartesian_overlaps_point_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = CartesianLineOverlaps>
Variant read_cartesian_overlaps_line_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = CartesianPolygonOverlaps>
Variant read_cartesian_overlaps_polygon_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}



#endif
