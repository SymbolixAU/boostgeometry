/*
#ifndef R_BOOSTGEOMETRY_UNIQUE_H
#define R_BOOSTGEOMETRY_UNIQUE_H

#include "R_boostgeometry.h"

namespace bg = boost::geometry;
namespace bgm = boost::geometry::model;

typedef boost::variant<
//  linestring_cartesian
//  , multi_linestring_cartesian
   polygon_cartesian
//  , multi_polygon_cartesian
> CartesianUnique;

typedef boost::variant<
  linestring_spherical
  , multi_linestring_spherical
  , polygon_spherical
  , multi_polygon_spherical
> SphericalUnique;

typedef boost::variant<
  linestring_geographic
  , multi_linestring_geographic
  , polygon_geographic
  , multi_polygon_geographic
> GeographicUnique;

template <typename Variant = CartesianUnique>
Variant read_cartesian_unique_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = SphericalUnique>
Variant read_spherical_unique_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = GeographicUnique>
Variant read_geographic_unique_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

#endif
*/
