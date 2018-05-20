#include "R_boostgeometry_buffer.h"

#include <boost/geometry.hpp>

#include <Rcpp.h>
using namespace Rcpp;

// TODO(variants not supported)
/*
Rcpp::StringVector rcpp_wkt_buffer_cartesian( Rcpp::List wkt, double distance) {
  Rcpp::StringVector wktBuffer( wkt.length() );

  //point_cartesian geom;
  //polygon_cartesian buff;

  typedef double coordinate_type;
  //typedef boost::geometry::model::d2::point_xy<coordinate_type> point;
  //typedef boost::geometry::model::polygon<point> polygon;


  double buffer_distance = 1.0;
  int points_per_circle = 36;
  boost::geometry::strategy::buffer::distance_symmetric<coordinate_type> distance_strategy(buffer_distance);
  boost::geometry::strategy::buffer::join_round join_strategy(points_per_circle);
  boost::geometry::strategy::buffer::end_round end_strategy(points_per_circle);
  boost::geometry::strategy::buffer::point_circle circle_strategy(points_per_circle);
  boost::geometry::strategy::buffer::side_straight side_strategy;

  //boost::geometry::model::multi_point<point_cartesian> mp;
  //multi_point_cartesian mp;
  CartesianBuffer mp;

  // Declare output
  //boost::geometry::model::multi_polygon<polygon_cartesian> result;
  multi_polygon_cartesian result;
  //CartesianBuffer result;       // TODO: variant result not supported

  for (size_t i = 0; i < wkt.length(); i++ ) {
    mp = read_cartesian_buffer_wkt( wkt[i] );
    //bg::read_wkt( wkt[i], mp );
    bg::buffer( mp, result, distance_strategy, side_strategy, join_strategy, end_strategy, circle_strategy );
    std::ostringstream os;
    os << bg::wkt( result );
    wktBuffer[i] = os.str();
  }
  return wktBuffer;
}
*/
