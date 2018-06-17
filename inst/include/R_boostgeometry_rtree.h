#ifndef R_BOOSTGEOMETRY_RTREE_H
#define R_BOOSTGEOMETRY_RTREE_H

#include "R_boostgeometry.h"
#include <boost/geometry/index/rtree.hpp>

typedef std::map<unsigned, CartesianGeometry> CartesianMap;
typedef std::map<unsigned, SphericalGeometry> SphericalMap;
typedef std::map<unsigned, GeographicGeometry> GeographicMap;

typedef std::pair<box_cartesian, CartesianMap::iterator> CartesianValue;
typedef std::pair<box_spherical, SphericalMap::iterator> SphericalValue;
typedef std::pair<box_geographic, GeographicMap::iterator> GeographicValue;

typedef std::pair<box_cartesian, unsigned> CartesianBoxUnsignedValue;
typedef std::pair<box_spherical, unsigned> SphericalBoxUnsignedValue;
typedef std::pair<box_geographic, unsigned> GeographicBoxUnsignedValue;

struct wkt_visitor : public boost::static_visitor<std::string>
{
  std::string operator()(point_cartesian const& g) const {
    std::ostringstream os;
    os << std::setprecision(12) << bg::wkt<point_cartesian>(g);
    return os.str();
  }
  std::string operator()(multi_point_cartesian const& g) const {
    std::ostringstream os;
    os << std::setprecision(12) << bg::wkt<multi_point_cartesian>(g);
    return os.str();
  }
  std::string operator()(linestring_cartesian const& g) const {
    std::ostringstream os;
    os << std::setprecision(12) << bg::wkt<linestring_cartesian>(g);
    return os.str();
  }
  std::string operator()(multi_linestring_cartesian const& g) const {
    std::ostringstream os;
    os << std::setprecision(12) << bg::wkt<multi_linestring_cartesian>(g);
    return os.str();
  }
  std::string operator()(polygon_cartesian const& g) const {
    std::ostringstream os;
    os << std::setprecision(12) << bg::wkt<polygon_cartesian>(g);
    return os.str();
  }
  std::string operator()(multi_polygon_cartesian const& g) const {
    std::ostringstream os;
    os << std::setprecision(12) << bg::wkt<multi_polygon_cartesian>(g);
    return os.str();
  }
  std::string operator()(box_cartesian const& g) const {
    std::ostringstream os;
    os << std::setprecision(12) << bg::wkt<box_cartesian>(g);
    return os.str();
  }
};


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

void fill_cartesian_rtree( Rcpp::List& wkt, bgi::rtree< CartesianBoxUnsignedValue, bgi::quadratic<16> >& rtree );

void fill_spherical_rtree( Rcpp::List& wkt, bgi::rtree< SphericalBoxUnsignedValue, bgi::quadratic<16> >& rtree );

void fill_geographic_rtree( Rcpp::List& wkt, bgi::rtree< GeographicBoxUnsignedValue, bgi::quadratic<16> >& rtree );

void cartesian_rtree( CartesianGeometry& geom,
                      Rcpp::List& wkt,
                      bgi::rtree< CartesianBoxUnsignedValue, bgi::quadratic<16> >& rtree);

void spherical_rtree( SphericalGeometry& geom,
                      Rcpp::List& wkt,
                      bgi::rtree< SphericalBoxUnsignedValue, bgi::quadratic<16> >& rtree);

void geographic_rtree( GeographicGeometry& geom,
                      Rcpp::List& wkt,
                      bgi::rtree< GeographicBoxUnsignedValue, bgi::quadratic<16> >& rtree);

void query_intersects_cartesian(std::string& thisWkt, std::vector<CartesianBoxUnsignedValue>& result_s, bgi::rtree< CartesianBoxUnsignedValue, bgi::quadratic<16> >& rtree);

void query_within_cartesian(std::string& thisWkt, std::vector<CartesianBoxUnsignedValue>& result_s, bgi::rtree< CartesianBoxUnsignedValue, bgi::quadratic<16> >& rtree);


void rcpp_bg_predicate_cartesian(
    std::string& predicate,
    Rcpp::List& wkt,
    CartesianGeometry& geom,
    bgi::rtree< CartesianBoxUnsignedValue, bgi::quadratic<16> >& rtree,
    Rcpp::List& res);

void rcpp_bg_predicate_spherical(
    std::string& predicate,
    Rcpp::List& wkt,
    SphericalGeometry& geom,
    bgi::rtree< SphericalBoxUnsignedValue, bgi::quadratic<16> >& rtree,
    Rcpp::List& res);

void rcpp_bg_predicate_geographic(
    std::string& predicate,
    Rcpp::List& wkt,
    GeographicGeometry& geom,
    bgi::rtree< GeographicBoxUnsignedValue, bgi::quadratic<16> >& rtree,
    Rcpp::List& res);



#endif
