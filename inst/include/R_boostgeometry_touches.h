#ifndef R_BOOSTGEOMETRY_TOUCHES_H
#define R_BOOSTGEOMETRY_TOUCHES_H

#include "R_boostgeometry.h"

namespace bg = boost::geometry;
namespace bgm = boost::geometry::model;

typedef boost::variant<
  point_cartesian
  , linestring_cartesian
  , multi_linestring_cartesian
  , polygon_cartesian
  , multi_polygon_cartesian
> CartesianTouches;

typedef boost::variant<
  point_spherical
  , linestring_spherical
  , multi_linestring_spherical
  , polygon_spherical
  , multi_polygon_spherical
> SphericalTouches;

typedef boost::variant<
  point_geographic
  , linestring_geographic
  , multi_linestring_geographic
  , polygon_geographic
  , multi_polygon_geographic
> GeographicTouches;

template <typename Variant = CartesianTouches>
Variant read_cartesian_touches_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = SphericalTouches>
Variant read_spherical_touches_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = GeographicTouches>
Variant read_geographic_touches_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

#endif

