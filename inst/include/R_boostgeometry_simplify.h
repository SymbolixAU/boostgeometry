
#ifndef R_BOOSTGEOMETRY_SIMPLIFY_H
#define R_BOOSTGEOMETRY_SIMPLIFY_H

#include "R_boostgeometry.h"

namespace bg = boost::geometry;
namespace bgm = boost::geometry::model;

typedef boost::variant<
  //  linestring_cartesian
  //  , multi_linestring_cartesian
    polygon_cartesian
  //, multi_polygon_cartesian
> CartesianSimplify;

typedef boost::variant<
//  linestring_spherical
//, multi_linestring_spherical
  polygon_spherical
  //, multi_polygon_spherical
> SphericalSimplify;

typedef boost::variant<
//  linestring_geographic
//, multi_linestring_geographic
  polygon_geographic
  //, multi_polygon_geographic
> GeographicSimplify;

template <typename Variant = CartesianSimplify>
Variant read_cartesian_simplify_wkt(std::string const& wkt) {
return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = SphericalSimplify>
Variant read_spherical_simplify_wkt(std::string const& wkt) {
return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = GeographicSimplify>
Variant read_geographic_simplify_wkt(std::string const& wkt) {
return detail::read_any_helper<Variant>::call(wkt);
}

#endif

