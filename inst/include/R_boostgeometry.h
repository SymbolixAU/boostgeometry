
#ifndef R_BOOSTGEOMETRY_H
#define R_BOOSTGEOMETRY_H

#include <boost/geometry.hpp>
#include <boost/geometry/index/rtree.hpp>

#include <iostream>

#include <boost/fusion/include/for_each.hpp>
#include <boost/fusion/include/vector.hpp>
#include <boost/bind.hpp>
#include <boost/variant.hpp>
#include <boost/spirit/home/x3.hpp>

#include <Rcpp.h>
using namespace Rcpp;

namespace bg = boost::geometry;
namespace bgm = boost::geometry::model;
namespace bgi = boost::geometry::index;

namespace boostgeometry {
  const float EARTH_RADIUS = 6371009.0;    // metres
  // 6378137.0 ?
}

//https://stackoverflow.com/questions/48040584/how-to-create-a-geometry-using-a-variant

namespace detail {
template <typename Variant> struct read_any_helper {

  static Variant call(std::string const& wkt) {
    Variant output;
    call_impl(wkt, output);
    return output;
  }

  using result_type = void;
  template <typename Geo> result_type operator()(std::string const& wkt, Geo& output) const {
    bg::read_wkt(wkt, output);
  }

private:
  template <typename... T>
  static void call_impl(std::string const& wkt, boost::variant<T...>& output) {
    static auto const switch_ = gen_switch(output);
    if (parse(wkt.begin(), wkt.end(), switch_, output)) {
      boost::apply_visitor(boost::bind(read_any_helper{}, boost::ref(wkt), _1), output);
    } else {
      throw bg::read_wkt_exception("Unregistered type", wkt);
    }
  }

  template <typename... T>
  static auto gen_switch(boost::variant<T...> const&) {
    namespace x3 = boost::spirit::x3;
    x3::symbols<Variant> result;

    boost::fusion::for_each(boost::fusion::vector<T...>{}, [&result](auto&& seed) {
      auto const serialized = boost::lexical_cast<std::string>(bg::wkt(seed));

      std::string keyword;
      if (x3::parse(serialized.begin(), serialized.end(), +x3::alpha, keyword)) {
        result.add(keyword, std::forward<decltype(seed)>(seed));
      } else {
        throw std::logic_error(std::string("registering WKT for ") + typeid(seed).name());
      }
    });
    return result;
  }
};
}

//typedef boost::tuple<double, double> generic_point;
typedef bgm::point< double, 2, bg::cs::cartesian > point_cartesian;
typedef bgm::multi_point<point_cartesian> multi_point_cartesian;
typedef bgm::linestring<point_cartesian> linestring_cartesian;
typedef bgm::multi_linestring<bgm::linestring<point_cartesian> > multi_linestring_cartesian;
typedef bgm::polygon<point_cartesian> polygon_cartesian;
typedef bgm::multi_polygon<bgm::polygon<point_cartesian> > multi_polygon_cartesian;
typedef bgm::segment<point_cartesian> segment_cartesian;
typedef bgm::box<point_cartesian> box_cartesian;

typedef bgm::point< double, 2, bg::cs::spherical_equatorial< bg::degree > > point_spherical;
typedef bgm::multi_point<point_spherical> multi_point_spherical;
typedef bgm::linestring<point_spherical> linestring_spherical;
typedef bgm::multi_linestring<bgm::linestring<point_spherical> > multi_linestring_spherical;
typedef bgm::polygon<point_spherical> polygon_spherical;
typedef bgm::multi_polygon<bgm::polygon<point_spherical> > multi_polygon_spherical;
typedef bgm::segment<point_spherical> segment_spherical;
typedef bgm::box<point_spherical> box_spherical;

typedef bgm::point< double, 2, bg::cs::geographic< bg::degree > > point_geographic;
typedef bgm::multi_point<point_geographic> multi_point_geographic;
typedef bgm::linestring<point_geographic> linestring_geographic;
typedef bgm::multi_linestring<bgm::linestring<point_geographic> > multi_linestring_geographic;
typedef bgm::polygon<point_geographic> polygon_geographic;
typedef bgm::multi_polygon<bgm::polygon<point_geographic> > multi_polygon_geographic;
typedef bgm::segment<point_geographic> segment_geographic;
typedef bgm::box<point_geographic> box_geographic;

typedef boost::variant<
  point_cartesian,
  multi_point_cartesian,
  linestring_cartesian,
  multi_linestring_cartesian,
  polygon_cartesian,
  multi_polygon_cartesian
> CartesianGeometry;

typedef boost::variant<
  point_spherical,
  multi_point_spherical,
  linestring_spherical,
  multi_linestring_spherical,
  polygon_spherical,
  multi_polygon_spherical
> SphericalGeometry;

typedef boost::variant<
  point_geographic,
  multi_point_geographic,
  linestring_geographic,
  multi_linestring_geographic,
  polygon_geographic,
  multi_polygon_geographic
> GeographicGeometry;

typedef std::map<unsigned, CartesianGeometry> CartesianMap;
typedef std::map<unsigned, SphericalGeometry> SphericalMap;
typedef std::map<unsigned, GeographicGeometry> GeographicMap;

typedef std::pair<box_cartesian, CartesianMap::iterator> CartesianValue;
typedef std::pair<box_spherical, SphericalMap::iterator> SphericalValue;
typedef std::pair<box_geographic, GeographicMap::iterator> GeographicValue;

struct print_visitor : public boost::static_visitor<>
{
  void operator()(point_cartesian const& g) const { std::cout << bg::wkt<point_cartesian>(g) << std::endl; }
  void operator()(multi_point_cartesian const& g) const { std::cout << bg::wkt<multi_point_cartesian>(g) << std::endl; }
  void operator()(linestring_cartesian const& g) const { std::cout << bg::wkt<linestring_cartesian>(g) << std::endl; }
  void operator()(multi_linestring_cartesian const& g) const { std::cout << bg::wkt<multi_linestring_cartesian>(g) << std::endl; }
  void operator()(polygon_cartesian const& g) const { std::cout << bg::wkt<polygon_cartesian>(g) << std::endl; }
  void operator()(multi_polygon_cartesian const& g) const { std::cout << bg::wkt<multi_polygon_cartesian>(g) << std::endl; }
};

struct envelope_visitor_cartesian : public boost::static_visitor<box_cartesian>
{
  box_cartesian operator()(point_cartesian const& g) const { return bg::return_envelope<box_cartesian>(g); }
  box_cartesian operator()(multi_point_cartesian const& g) const { return bg::return_envelope<box_cartesian>(g); }
  box_cartesian operator()(linestring_cartesian const& g) const { return bg::return_envelope<box_cartesian>(g); }
  box_cartesian operator()(multi_linestring_cartesian const& g) const { return bg::return_envelope<box_cartesian>(g); }
  box_cartesian operator()(polygon_cartesian const& g) const { return bg::return_envelope<box_cartesian>(g); }
  box_cartesian operator()(multi_polygon_cartesian const& g) const { return bg::return_envelope<box_cartesian>(g); }
};

struct envelope_visitor_spherical : public boost::static_visitor<box_spherical>
{
  box_spherical operator()(point_spherical const& g) const { return bg::return_envelope<box_spherical>(g); }
  box_spherical operator()(multi_point_spherical const& g) const { return bg::return_envelope<box_spherical>(g); }
  box_spherical operator()(linestring_spherical const& g) const { return bg::return_envelope<box_spherical>(g); }
  box_spherical operator()(multi_linestring_spherical const& g) const { return bg::return_envelope<box_spherical>(g); }
  box_spherical operator()(polygon_spherical const& g) const { return bg::return_envelope<box_spherical>(g); }
  box_spherical operator()(multi_polygon_spherical const& g) const { return bg::return_envelope<box_spherical>(g); }
};

struct envelope_visitor_geographic : public boost::static_visitor<box_geographic>
{
  box_geographic operator()(point_geographic const& g) const { return bg::return_envelope<box_geographic>(g); }
  box_geographic operator()(multi_point_geographic const& g) const { return bg::return_envelope<box_geographic>(g); }
  box_geographic operator()(linestring_geographic const& g) const { return bg::return_envelope<box_geographic>(g); }
  box_geographic operator()(multi_linestring_geographic const& g) const { return bg::return_envelope<box_geographic>(g); }
  box_geographic operator()(polygon_geographic const& g) const { return bg::return_envelope<box_geographic>(g); }
  box_geographic operator()(multi_polygon_geographic const& g) const { return bg::return_envelope<box_geographic>(g); }
};


/*
typedef boost::variant<
  bgm::box<point_cartesian>,
  bgm::box<point_spherical>,
  bgm::box<point_geographic>
> CSGBox;
*/

typedef boost::variant<
  CartesianGeometry,
  SphericalGeometry
> CSGeometry;

typedef boost::variant<
  SphericalGeometry,
  GeographicGeometry
> SGGeometry;

typedef boost::variant<
  CartesianGeometry,
  SphericalGeometry,
  GeographicGeometry
> CSGGeometry;


template <typename Variant = CartesianGeometry>
Variant read_cartesian_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = SphericalGeometry>
Variant read_spherical_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = GeographicGeometry>
Variant read_geographic_wkt(std::string const& wkt) {
  return detail::read_any_helper<Variant>::call(wkt);
}

template <typename Variant = CSGeometry>
Variant read_cs_wkt(std::string const& wkt, int geom_type) {
  switch( geom_type ) {
  case 1:
    return read_cartesian_wkt(wkt);
  case 2:
    return read_spherical_wkt(wkt);
  }
  return read_cartesian_wkt(wkt);
}

template <typename Variant = SGGeometry>
Variant read_sg_wkt(std::string const& wkt, int geom_type) {
  switch( geom_type ) {
  case 2:
    return read_spherical_wkt(wkt);
  case 3:
    return read_geographic_wkt(wkt);
  }
  return read_spherical_wkt(wkt);
}


template <typename Variant = CSGGeometry>
Variant read_any_wkt(std::string const& wkt, int geom_type) {
  switch( geom_type ) {
  case 1:
    return read_cartesian_wkt(wkt);
  case 2:
    return read_spherical_wkt(wkt);
  case 3:
    return read_geographic_wkt(wkt);
  }
  return read_cartesian_wkt(wkt);
}

std::string geomFromWKT(std::string& pl);


void make_strategy(const char* strategy, int *tp = NULL);

#define BG_Unknown      0
#define BG_Cartesian    1
#define BG_Spherical    2
#define BG_Geographic   3

#define POINT           0
#define MULTIPOINT      1
#define LINESTRING      2
#define MULTILINESTRING 3
#define POLYGON         4
#define MULTIPOLYGON    5
#define BOX             6
#define SEGMENT         7

#endif
