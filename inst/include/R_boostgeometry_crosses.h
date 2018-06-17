#ifndef R_BOOSTGEOMETRY_CROSSES_H
#define R_BOOSTGEOMETRY_CROSSES_H

#include "R_boostgeometry.h"

namespace bg = boost::geometry;
namespace bgm = boost::geometry::model;

//namespace bg_crosses {
  // reference matrix
  // https://www.boost.org/doc/libs/1_67_0/libs/geometry/doc/html/geometry/reference/algorithms/crosses/crosses_3_with_strategy.html
  // - columns are first parameter, rows are second parameter

  // sorted lists for using binary_search
  //static const std::set<std::string> crosses_cg{"LINESTRING", "MULTILINESTRING"};
  //static const std::set<std::string> crosses_sg{"LINESTRING", "MULTILINESTRING"};
  //static const std::set<std::string> crosses_gg{"LINESTRING", "MULTILINESTRING"};

  //static const std::set<std::string> linestring_crosses{"LINESTRING","MULTILINESTRING","MULTIPOLYGON","POINT","POLYGON"};
  //static const std::set<std::string> polygon_crosses{"POINT"};
  //static const std::set<std::string> multi_linestring_crosses{"LINESTRING","MULTILINESTRING","MULTIPOLYGON","POLYGON","POINT"};
  //static const std::set<std::string> multi_polygon_crosses{"POINT"};
//}

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
