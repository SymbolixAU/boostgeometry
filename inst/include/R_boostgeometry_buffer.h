/*
#ifndef R_BOOSTGEOMETRY_BUFFER_H
#define R_BOOSTGEOMETRY_BUFFER_H

#include "R_boostgeometry.h"

typedef boost::variant<
  //point_cartesian
   multi_point_cartesian
  //, linestring_cartesian
  //, multi_linestring_cartesian
  //, polygon_cartesian
  // multi_polygon_cartesian
> CartesianBuffer;

typedef boost::variant<
  point_spherical
  , multi_point_spherical
  , linestring_spherical
  , multi_linestring_spherical
  , polygon_spherical
  , multi_polygon_spherical
> SphericalBuffer;

typedef boost::variant<
  point_geographic
  , multi_point_geographic
  , linestring_geographic
  , multi_linestring_geographic
  , polygon_geographic
  , multi_polygon_geographic
> GeographicBuffer;

template <typename Variant = CartesianBuffer>
Variant read_cartesian_buffer_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = SphericalBuffer>
Variant read_spherical_buffer_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = GeographicBuffer>
Variant read_geographic_buffer_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

#endif
*/
