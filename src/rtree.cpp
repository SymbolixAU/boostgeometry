//#include <boost/geometry.hpp>
//#include <boost/geometry/geometries/point.hpp>
//#include <boost/geometry/geometries/box.hpp>

#include "R_boostgeometry.h"

#include <boost/geometry/index/rtree.hpp>

// to store queries results
#include <vector>

// just for output
#include <iostream>
#include <boost/foreach.hpp>

namespace bg = boost::geometry;
namespace bgi = boost::geometry::index;

// [[Rcpp::export]]
void rtreetest( Rcpp::List wkt ) {

  CartesianGeometry geometry;
  CartesianMap geometries;

  bgi::rtree< CartesianValue, bgi::quadratic<16> > rtree;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geometry = read_cartesian_wkt( wkt[i] );
    geometries.insert(std::make_pair(i, geometry));
  }

  // fill the spatial index
  for ( CartesianMap::iterator it = geometries.begin() ; it != geometries.end() ; ++it )
  {
    // calculate polygon bounding box
    box_cartesian b = boost::apply_visitor(envelope_visitor_cartesian(), it->second);
    // insert new value
    rtree.insert(std::make_pair(b, it));
  }


  // find values intersecting some area defined by a box
  box_cartesian query_box(point_cartesian(2, 2), point_cartesian(5, 5));
  std::vector<CartesianValue> result_s;
  rtree.query(bgi::intersects(query_box), std::back_inserter(result_s));

  // display results
  std::cout << "spatial query box:" << std::endl;
  std::cout << bg::wkt<box_cartesian>(query_box) << std::endl;
  std::cout << "spatial query result:" << std::endl;
  BOOST_FOREACH(CartesianValue const& v, result_s)
    boost::apply_visitor(print_visitor(), v.second->second);

  /*
  //typedef boost::variant<polygon_cartesian, linestring_cartesian> geometry;
  //typedef std::map<unsigned, geometry> map;
  //typedef std::pair<box_cartesian, map::iterator> value;

  // create the rtree using default constructor
  bgi::rtree< value, bgi::quadratic<16> > rtree;

  // create some values
  for ( unsigned i = 0 ; i < 10 ; ++i )
  {
    // create a box
    box_cartesian b(point_cartesian(i + 0.0f, i + 0.0f), point_cartesian(i + 0.5f, i + 0.5f));
    //linestring_cartesian l(point(i + 0.0f, i + 0.0f), point(i + 0.5f, i + 0.5f));
    // insert new value
    rtree.insert(std::make_pair(b, i));
  }

  // find values intersecting some area defined by a box
  box_cartesian query_box(point_cartesian(0, 0), point_cartesian(5, 5));
  std::vector<value> result_s;
  rtree.query(bgi::intersects(query_box), std::back_inserter(result_s));


  // find 5 nearest values to a point
  std::vector<value> result_n;
  rtree.query(bgi::nearest(point_cartesian(0, 0), 5), std::back_inserter(result_n));

  // display results
  std::cout << "spatial query box:" << std::endl;
  std::cout << bg::wkt<box_cartesian>(query_box) << std::endl;
  std::cout << "spatial query result:" << std::endl;
  BOOST_FOREACH(value const& v, result_s)
    std::cout << bg::wkt<box_cartesian>(v.first) << " - " << v.second << std::endl;

  std::cout << "knn query point:" << std::endl;
  std::cout << bg::wkt<point_cartesian>(point_cartesian(0, 0)) << std::endl;
  std::cout << "knn query result:" << std::endl;
  BOOST_FOREACH(value const& v, result_n)
    std::cout << bg::wkt<box_cartesian>(v.first) << " - " << v.second << std::endl;
  */
}
