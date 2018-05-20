#ifndef R_BOOSTGEOMETRY_CONVEX_HULL_H
#define R_BOOSTGEOMETRY_CONVEX_HULL_H

#include "R_boostgeometry.h"

namespace bg = boost::geometry;
namespace bgm = boost::geometry::model;

typedef boost::variant<
  //point_cartesian
  multi_point_cartesian
  , linestring_cartesian
  , multi_linestring_cartesian
  , polygon_cartesian
  , multi_polygon_cartesian
> CartesianConvexHull;

template <typename Variant = CartesianConvexHull>
Variant read_cartesian_convex_hull_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

/*
typedef boost::variant<
  multi_point_spherical
  , linestring_spherical
  , multi_linestring_spherical
  , polygon_spherical
  , multi_polygon_spherical
> SphericalConvexHull;

template <typename Variant = SphericalConvexHull>
Variant read_spherical_convex_hull_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}


typedef boost::variant<
  multi_point_geographic
  , linestring_geographic
  , multi_linestring_geographic
  , polygon_geographic
  , multi_polygon_geographic
> GeographicConvexHull;

template <typename Variant = GeographicConvexHull>
Variant read_geographic_convex_hull_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}
*/

#endif
