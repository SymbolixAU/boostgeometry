#ifndef R_BOOSTGEOMETRY_CROSSES_H
#define R_BOOSTGEOMETRY_CROSSES_H

#include "R_boostgeometry.h"

namespace bg = boost::geometry;
namespace bgm = boost::geometry::model;

typedef boost::variant<
   linestring_cartesian
  , multi_linestring_cartesian
//  , polygon_cartesian
//  , multi_polygon_cartesian
> CartesianCrossesOne;

typedef boost::variant<
  linestring_cartesian
  , multi_linestring_cartesian
//  , polygon_cartesian
//  , multi_polygon_cartesian
> CartesianCrossesTwo;

typedef boost::variant<
  linestring_spherical
  , multi_linestring_spherical
//  , polygon_spherical
//  , multi_polygon_spherical
> SphericalCrossesOne;

typedef boost::variant<
  linestring_spherical
  , multi_linestring_spherical
//  , polygon_spherical
//  , multi_polygon_spherical
> SphericalCrossesTwo;

typedef boost::variant<
  linestring_geographic
  , multi_linestring_geographic
//  , polygon_geographic
//  , multi_polygon_geographic
> GeographicCrossesOne;

typedef boost::variant<
  linestring_geographic
  , multi_linestring_geographic
//  , polygon_geographic
//  , multi_polygon_geographic
> GeographicCrossesTwo;

template <typename Variant = CartesianCrossesOne>
Variant read_cartesian_crosses_one_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = CartesianCrossesTwo>
Variant read_cartesian_crosses_two_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}
template <typename Variant = SphericalCrossesOne>
Variant read_spherical_crosses_one_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = SphericalCrossesTwo>
Variant read_spherical_crosses_two_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = GeographicCrossesOne>
Variant read_geographic_crosses_one_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = GeographicCrossesTwo>
Variant read_geographic_crosses_two_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

#endif
