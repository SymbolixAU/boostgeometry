#ifndef R_BOOSTGEOMETRY_WITHIN_H
#define R_BOOSTGEOMETRY_WITHIN_H

#include "R_boostgeometry.h"

namespace bg = boost::geometry;
namespace bgm = boost::geometry::model;

// https://www.boost.org/doc/libs/1_67_0/libs/geometry/doc/html/geometry/reference/algorithms/within/within_2.html

typedef boost::variant<
  point_cartesian
  , linestring_cartesian
> CartesianWithinOne;

typedef boost::variant<
  linestring_cartesian
  , multi_linestring_cartesian
  , polygon_cartesian
  , multi_polygon_cartesian
> CartesianWithinTwo;

typedef boost::variant<
  point_spherical
  , linestring_spherical
> SphericalWithinOne;

typedef boost::variant<
  multi_linestring_spherical
  , polygon_spherical
  , multi_polygon_spherical
> SphericalWithinTwo;

typedef boost::variant<
  point_geographic
  , linestring_geographic
> GeographicWithinOne;

typedef boost::variant<
  multi_linestring_geographic
  , polygon_geographic
  , multi_polygon_geographic
> GeographicWithinTwo;

template <typename Variant = CartesianWithinOne>
Variant read_cartesian_within_one_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = CartesianWithinTwo>
Variant read_cartesian_within_two_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = SphericalWithinOne>
Variant read_spherical_within_one_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = SphericalWithinTwo>
Variant read_spherical_within_two_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = GeographicWithinOne>
Variant read_geographic_within_one_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = GeographicWithinTwo>
Variant read_geographic_within_two_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

#endif
