
/*
#ifndef R_BOOSTGEOMETRY_COVERED_BY_H
#define R_BOOSTGEOMETRY_COVERED_BY_H

#include "R_boostgeometry.h"

namespace bg = boost::geometry;
namespace bgm = boost::geometry::model;

typedef boost::variant<
  point_cartesian
  , multi_point_cartesian
  , linestring_cartesian
  , multi_linestring_cartesian
  , polygon_cartesian
  , multi_polygon_cartesian
> CartesianCoveredBy;

typedef boost::variant<
  point_spherical
  , multi_point_spherical
  , linestring_spherical
  , multi_linestring_spherical
  , polygon_spherical
  , multi_polygon_spherical
> SphericalCoveredBy;

typedef boost::variant<
  point_geographic
  //, multi_point_geographic
  , linestring_geographic
  , multi_linestring_geographic
  , polygon_geographic
  , multi_polygon_geographic
> GeographicCoveredBy;

template <typename Variant = CartesianCoveredBy>
Variant read_cartesian_covere_by_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = SphericalCoveredBy>
Variant read_spherical_covered_by_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = GeographicCoveredBy>
Variant read_geographic_covered_by_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}
*/

#endif
