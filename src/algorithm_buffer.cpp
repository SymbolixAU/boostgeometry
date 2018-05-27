#include "R_boostgeometry_buffer.h"

#include <boost/geometry.hpp>

#include <Rcpp.h>
using namespace Rcpp;


/*
 * CARTESIAN
 */
void buffer_point_cartesian(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktBuffer, double& buffer_distance ) {

  point_cartesian point;
  multi_polygon_cartesian buffer_mp;

  typedef double coordinate_type;
  int points_per_circle = 36;
  bgsb::distance_symmetric<coordinate_type> distance_strategy(buffer_distance);
  bgsb::join_round join_strategy(points_per_circle);
  bgsb::end_round end_strategy(points_per_circle);
  bgsb::point_circle circle_strategy(points_per_circle);
  bgsb::side_straight side_strategy;

  bg::read_wkt( wkt[i], point );
  bg::buffer( point, buffer_mp, distance_strategy, side_strategy, join_strategy, end_strategy, circle_strategy );

  std::ostringstream os;
  os << bg::wkt( buffer_mp );
  wktBuffer[i] = os.str();
}


void buffer_multi_point_cartesian(
  Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktBuffer, double& buffer_distance) {

  multi_point_cartesian point;
  multi_polygon_cartesian buffer_mp;

  typedef double coordinate_type;
  int points_per_circle = 36;
  bgsb::distance_symmetric<coordinate_type> distance_strategy(buffer_distance);
  bgsb::join_round join_strategy(points_per_circle);
  bgsb::end_round end_strategy(points_per_circle);
  bgsb::point_circle circle_strategy(points_per_circle);
  bgsb::side_straight side_strategy;

  bg::read_wkt( wkt[i], point );
  bg::buffer( point, buffer_mp, distance_strategy, side_strategy, join_strategy, end_strategy, circle_strategy );

  std::ostringstream os;
  os << bg::wkt( buffer_mp );
  wktBuffer[i] = os.str();
}

void buffer_linestring_cartesian(
  Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktBuffer, double& buffer_distance ) {

  linestring_cartesian line;
  multi_polygon_cartesian buffer_mp;

  typedef double coordinate_type;
  int points_per_circle = 36;
  bgsb::distance_symmetric<coordinate_type> distance_strategy(buffer_distance);
  bgsb::join_round join_strategy(points_per_circle);
  bgsb::end_round end_strategy(points_per_circle);
  bgsb::point_circle circle_strategy(points_per_circle);
  bgsb::side_straight side_strategy;

  bg::read_wkt( wkt[i], line );
  bg::buffer( line, buffer_mp, distance_strategy, side_strategy, join_strategy, end_strategy, circle_strategy );

  std::ostringstream os;
  os << bg::wkt( buffer_mp );
  wktBuffer[i] = os.str();
}

void buffer_multi_linestring_cartesian(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktBuffer, double& buffer_distance ) {

  multi_linestring_cartesian line;
  multi_polygon_cartesian buffer_mp;

  typedef double coordinate_type;
  int points_per_circle = 36;
  bgsb::distance_symmetric<coordinate_type> distance_strategy(buffer_distance);
  bgsb::join_round join_strategy(points_per_circle);
  bgsb::end_round end_strategy(points_per_circle);
  bgsb::point_circle circle_strategy(points_per_circle);
  bgsb::side_straight side_strategy;

  bg::read_wkt( wkt[i], line );
  bg::buffer( line, buffer_mp, distance_strategy, side_strategy, join_strategy, end_strategy, circle_strategy );

  std::ostringstream os;
  os << bg::wkt( buffer_mp );
  wktBuffer[i] = os.str();
}

void buffer_polygon_cartesian(
  Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktBuffer, double& buffer_distance ) {

  polygon_cartesian line;
  multi_polygon_cartesian buffer_mp;

  typedef double coordinate_type;
  int points_per_circle = 36;
  bgsb::distance_symmetric<coordinate_type> distance_strategy(buffer_distance);
  bgsb::join_round join_strategy(points_per_circle);
  bgsb::end_round end_strategy(points_per_circle);
  bgsb::point_circle circle_strategy(points_per_circle);
  bgsb::side_straight side_strategy;

  bg::read_wkt( wkt[i], line );
  bg::buffer( line, buffer_mp, distance_strategy, side_strategy, join_strategy, end_strategy, circle_strategy );

  std::ostringstream os;
  os << bg::wkt( buffer_mp );
  wktBuffer[i] = os.str();
}

void buffer_multi_polygon_cartesian(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktBuffer, double& buffer_distance ) {

  multi_polygon_cartesian line;
  multi_polygon_cartesian buffer_mp;

  typedef double coordinate_type;
  int points_per_circle = 36;
  bgsb::distance_symmetric<coordinate_type> distance_strategy(buffer_distance);
  bgsb::join_round join_strategy(points_per_circle);
  bgsb::end_round end_strategy(points_per_circle);
  bgsb::point_circle circle_strategy(points_per_circle);
  bgsb::side_straight side_strategy;

  bg::read_wkt( wkt[i], line );
  bg::buffer( line, buffer_mp, distance_strategy, side_strategy, join_strategy, end_strategy, circle_strategy );

  std::ostringstream os;
  os << bg::wkt( buffer_mp );
  wktBuffer[i] = os.str();
}

/*
* END CARTESIAN
*/

/*
* SPHERICAL
*/
/*
void buffer_linestring_spherical(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktBuffer ) {

  linestring_spherical line;
  multi_polygon_spherical buffer_mp;

  bg::read_wkt( wkt[i], line );
  bg::buffer( line, buffer_mp, distance_strategy, side_strategy, join_strategy, end_strategy, circle_strategy );

  std::ostringstream os;
  os << bg::wkt( buffer_mp );
  wktBuffer[i] = os.str();
}

void buffer_multi_linestring_spherical(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktBuffer ) {

  multi_linestring_spherical line;
  multi_polygon_spherical buffer_mp;

  bg::read_wkt( wkt[i], line );
  bg::buffer( line, buffer_mp, distance_strategy, side_strategy, join_strategy, end_strategy, circle_strategy );

  std::ostringstream os;
  os << bg::wkt( buffer_mp );
  wktBuffer[i] = os.str();
}

void buffer_polygon_spherical(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktBuffer ) {

  polygon_spherical line;
  multi_polygon_spherical buffer_mp;

  bg::read_wkt( wkt[i], line );
  bg::buffer( line, buffer_mp, distance_strategy, side_strategy, join_strategy, end_strategy, circle_strategy );

  std::ostringstream os;
  os << bg::wkt( buffer_mp );
  wktBuffer[i] = os.str();
}

void buffer_multi_polygon_spherical(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktBuffer ) {

  multi_polygon_spherical line;
  multi_polygon_spherical buffer_mp;

  bg::read_wkt( wkt[i], line );
  bg::buffer( line, buffer_mp, distance_strategy, side_strategy, join_strategy, end_strategy, circle_strategy );

  std::ostringstream os;
  os << bg::wkt( buffer_mp );
  wktBuffer[i] = os.str();
}
 */
/*
* END SPHERICAL
*/

/*
* GEOGRAPHIC
*/
/*
void buffer_linestring_geographic(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktBuffer ) {

  typedef double coordinate_type;
  double buffer_distance = 1.0;
  int points_per_circle = 36;
  bgsb::distance_symmetric<coordinate_type> distance_strategy(buffer_distance);
  bgsb::join_round join_strategy(points_per_circle);
  bgsb::end_round end_strategy(points_per_circle);
  bgsb::point_circle circle_strategy(points_per_circle);
  bgsb::side_straight side_strategy;

  linestring_geographic line;
  multi_polygon_geographic buffer_mp;

  bg::read_wkt( wkt[i], line );
  bg::buffer( line, buffer_mp, distance_strategy, side_strategy, join_strategy, end_strategy, circle_strategy );

  std::ostringstream os;
  os << bg::wkt( buffer_mp );
  wktBuffer[i] = os.str();
}

void buffer_multi_linestring_geographic(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktBuffer ) {

  multi_linestring_geographic line;
  multi_polygon_geographic buffer_mp;

  bg::read_wkt( wkt[i], line );
  bg::buffer( line, buffer_mp, distance_strategy, side_strategy, join_strategy, end_strategy, circle_strategy );

  std::ostringstream os;
  os << bg::wkt( buffer_mp );
  wktBuffer[i] = os.str();
}

void buffer_polygon_geographic(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktBuffer ) {

  polygon_geographic line;
  multi_polygon_geographic buffer_mp;

  bg::read_wkt( wkt[i], line );
  bg::buffer( line, buffer_mp, distance_strategy, side_strategy, join_strategy, end_strategy, circle_strategy );

  std::ostringstream os;
  os << bg::wkt( buffer_mp );
  wktBuffer[i] = os.str();
}

void buffer_multi_polygon_geographic(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktBuffer ) {

  multi_polygon_geographic line;
  multi_polygon_geographic buffer_mp;

  bg::read_wkt( wkt[i], line );
  bg::buffer( line, buffer_mp, distance_strategy, side_strategy, join_strategy, end_strategy, circle_strategy );

  std::ostringstream os;
  os << bg::wkt( buffer_mp );
  wktBuffer[i] = os.str();
}
 */
/*
* END GEOGRAPHIC
*/

// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_buffer_cartesian( Rcpp::List wkt, double distance) {
  Rcpp::StringVector wktBuffer( wkt.length() );

  std::string geomType;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    std::string thisWkt = wkt[i];
    geomType = geomFromWKT( thisWkt );

    if (geomType == "POINT" ) {
      buffer_point_cartesian(wkt, i, wktBuffer, distance );
    } else if ( geomType == "MULTIPOINT" ) {
      buffer_multi_point_cartesian(wkt, i, wktBuffer, distance );
    } else if ( geomType == "LINESTRING" ) {
      buffer_linestring_cartesian(wkt, i, wktBuffer, distance );
    } else if ( geomType == "MULTILINESTRING" ) {
      buffer_multi_linestring_cartesian(wkt, i, wktBuffer, distance );
    } else if ( geomType == "POLYGON" ) {
      buffer_polygon_cartesian(wkt, i, wktBuffer, distance );
    } else if ( geomType == "MULTIPOLYGON" ) {
      buffer_multi_polygon_cartesian(wkt, i, wktBuffer, distance );
    }
  }
  return wktBuffer;
}
/*

// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_buffer_spherical( Rcpp::List wkt, double distance) {
  Rcpp::StringVector wktBuffer( wkt.length() );

  typedef double coordinate_type;
  double buffer_distance = 1.0;
  int points_per_circle = 36;
  bgsb::distance_symmetric<coordinate_type> distance_strategy(buffer_distance);
  bgsb::join_round join_strategy(points_per_circle);
  bgsb::end_round end_strategy(points_per_circle);
  bgsb::point_circle circle_strategy(points_per_circle);
  bgsb::side_straight side_strategy;

  std::string geomType;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    std::string thisWkt = wkt[i];
    geomType = geomFromWKT( thisWkt );

    if (geomType == "POINT" || geomType == "MULTIPOINT") {
      wktBuffer[i] = thisWkt;
    } else if (geomType == "LINESTRING") {
      buffer_linestring_spherical(wkt, i, wktBuffer, distance);
    } else if (geomType == "MULTILINESTRING") {
      buffer_multi_linestring_spherical(wkt, i, wktBuffer, distance);
    } else if (geomType == "POLYGON") {
      buffer_polygon_spherical(wkt, i, wktBuffer, distance);
    } else if (geomType == "MULTIPOLYGON") {
      buffer_multi_polygon_spherical(wkt, i, wktBuffer, distance);
    }
  }
  return wktBuffer;
}

// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_buffer_geographic( Rcpp::List wkt) {
  Rcpp::StringVector wktBuffer( wkt.length() );

  std::string geomType;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    std::string thisWkt = wkt[i];
    geomType = geomFromWKT( thisWkt );

    if (geomType == "POINT" || geomType == "MULTIPOINT") {
      //wktBuffer[i] = thisWkt;
    } else if (geomType == "LINESTRING") {
      buffer_linestring_geographic(wkt, i, wktBuffer);
    } else if (geomType == "MULTILINESTRING") {
      //buffer_multi_linestring_geographic(wkt, i, wktBuffer, distance);
    } else if (geomType == "POLYGON") {
      //buffer_polygon_geographic(wkt, i, wktBuffer, distance);
    } else if (geomType == "MULTIPOLYGON") {
      //buffer_multi_polygon_geographic(wkt, i, wktBuffer, distance);
    }
  }
  return wktBuffer;
}
*/


/*
// TODO(variants not supported)
Rcpp::StringVector rcpp_wkt_buffer_cartesian( Rcpp::List wkt, double distance) {
  Rcpp::StringVector wktBuffer( wkt.length() );

  typedef double coordinate_type;
  double buffer_distance = 1.0;
  int points_per_circle = 36;
  bgsb::distance_symmetric<coordinate_type> distance_strategy(buffer_distance);
  bgsb::join_round join_strategy(points_per_circle);
  bgsb::end_round end_strategy(points_per_circle);
  bgsb::point_circle circle_strategy(points_per_circle);
  bgsb::side_straight side_strategy;

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
