#ifndef R_BOOSTGEOMETRY_DISJOINT_H
#define R_BOOSTGEOMETRY_DISJOINT_H

#include "R_boostgeometry.h"

namespace bg = boost::geometry;
namespace bgm = boost::geometry::model;

namespace bg_disjoint {
  // sorted lists for using binary_search
  static const std::set<std::string> disjoint_cg{"MULTIPOINT", "POINT"};
}


typedef boost::variant<
  point_cartesian
  , multi_point_cartesian
  , linestring_cartesian
  , multi_linestring_cartesian
  , polygon_cartesian
  , multi_polygon_cartesian
> CartesianDisjoint;

typedef boost::variant<
  point_spherical
  , multi_point_spherical
  , linestring_spherical
  , multi_linestring_spherical
  , polygon_spherical
  , multi_polygon_spherical
> SphericalDisjoint;

typedef boost::variant<
  point_geographic
  //, multi_point_geographic
  , linestring_geographic
  , multi_linestring_geographic
  , polygon_geographic
  , multi_polygon_geographic
> GeographicDisjoint;

template <typename Variant = CartesianDisjoint>
Variant read_cartesian_disjoint_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = SphericalDisjoint>
Variant read_spherical_disjoint_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = GeographicDisjoint>
Variant read_geographic_disjoint_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

#endif
