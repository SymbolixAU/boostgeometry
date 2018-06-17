#include "R_boostgeometry_rtree.h"

// to store queries results
#include <vector>

// just for output
#include <iostream>
#include <boost/foreach.hpp>

namespace bg = boost::geometry;
namespace bgi = boost::geometry::index;

// queries
// https://www.boost.org/doc/libs/1_67_0/libs/geometry/doc/html/geometry/spatial_indexes/queries.html

//bgi::contains();
//bgi::covered_by();
//bgi::covers();
//bgi::disjoint();
//bgi::intersects();
//bgi::overlaps();
//bgi::within();

void fill_cartesian_rtree( Rcpp::List& wkt, bgi::rtree< CartesianBoxUnsignedValue, bgi::quadratic<16> >& rtree ) {

  for (size_t i = 0; i < wkt.size(); i++) {

    std::string thisWkt = wkt[i];
    std::string geomType = geomFromWKT( thisWkt );

    if (geomType == "POINT") {
      point_cartesian geom;
      bg::read_wkt( wkt[i], geom );
      box_cartesian b = bg::return_envelope<box_cartesian>( geom );
      rtree.insert(std::make_pair(b, i));
    } else if (geomType == "MULTIPOINT") {
      multi_point_cartesian geom;
      bg::read_wkt( wkt[i], geom );
      box_cartesian b = bg::return_envelope<box_cartesian>( geom );
      rtree.insert(std::make_pair(b, i));
    } else if (geomType == "LINESTRING") {
      linestring_cartesian geom;
      bg::read_wkt( wkt[i], geom );
      box_cartesian b = bg::return_envelope<box_cartesian>( geom );
      rtree.insert(std::make_pair(b, i));
    } else if (geomType == "MULTILINESTRING") {
      multi_linestring_cartesian geom;
      bg::read_wkt( wkt[i], geom );
      box_cartesian b = bg::return_envelope<box_cartesian>( geom );
      rtree.insert(std::make_pair(b, i));
    } else if (geomType == "POLYGON") {
      polygon_cartesian geom;
      bg::read_wkt( wkt[i], geom );
      box_cartesian b = bg::return_envelope<box_cartesian>( geom );
      rtree.insert(std::make_pair(b, i));
    } else if (geomType == "MULTIPOLYGON") {
      multi_polygon_cartesian geom;
      bg::read_wkt( wkt[i], geom );
      box_cartesian b = bg::return_envelope<box_cartesian>( geom );
      rtree.insert(std::make_pair(b, i));
    }
  }
}

void fill_spherical_rtree( Rcpp::List& wkt, bgi::rtree< SphericalBoxUnsignedValue, bgi::quadratic<16> >& rtree ) {

  for (size_t i = 0; i < wkt.size(); i++) {

    std::string thisWkt = wkt[i];
    std::string geomType = geomFromWKT( thisWkt );

    if (geomType == "POINT") {
      point_spherical geom;
      bg::read_wkt( wkt[i], geom );
      box_spherical b = bg::return_envelope<box_spherical>( geom );
      rtree.insert(std::make_pair(b, i));
    } else if (geomType == "MULTIPOINT") {
      multi_point_spherical geom;
      bg::read_wkt( wkt[i], geom );
      box_spherical b = bg::return_envelope<box_spherical>( geom );
      rtree.insert(std::make_pair(b, i));
    } else if (geomType == "LINESTRING") {
      linestring_spherical geom;
      bg::read_wkt( wkt[i], geom );
      box_spherical b = bg::return_envelope<box_spherical>( geom );
      rtree.insert(std::make_pair(b, i));
    } else if (geomType == "MULTILINESTRING") {
      multi_linestring_spherical geom;
      bg::read_wkt( wkt[i], geom );
      box_spherical b = bg::return_envelope<box_spherical>( geom );
      rtree.insert(std::make_pair(b, i));
    } else if (geomType == "POLYGON") {
      polygon_spherical geom;
      bg::read_wkt( wkt[i], geom );
      box_spherical b = bg::return_envelope<box_spherical>( geom );
      rtree.insert(std::make_pair(b, i));
    } else if (geomType == "MULTIPOLYGON") {
      multi_polygon_spherical geom;
      bg::read_wkt( wkt[i], geom );
      box_spherical b = bg::return_envelope<box_spherical>( geom );
      rtree.insert(std::make_pair(b, i));
    }
  }
}

void fill_geographic_rtree( Rcpp::List& wkt, bgi::rtree< GeographicBoxUnsignedValue, bgi::quadratic<16> >& rtree ) {

  for (size_t i = 0; i < wkt.size(); i++) {

    std::string thisWkt = wkt[i];
    std::string geomType = geomFromWKT( thisWkt );

    if (geomType == "POINT") {
      point_geographic geom;
      bg::read_wkt( wkt[i], geom );
      box_geographic b = bg::return_envelope<box_geographic>( geom );
      rtree.insert(std::make_pair(b, i));
    } else if (geomType == "MULTIPOINT") {
      multi_point_geographic geom;
      bg::read_wkt( wkt[i], geom );
      box_geographic b = bg::return_envelope<box_geographic>( geom );
      rtree.insert(std::make_pair(b, i));
    } else if (geomType == "LINESTRING") {
      linestring_geographic geom;
      bg::read_wkt( wkt[i], geom );
      box_geographic b = bg::return_envelope<box_geographic>( geom );
      rtree.insert(std::make_pair(b, i));
    } else if (geomType == "MULTILINESTRING") {
      multi_linestring_geographic geom;
      bg::read_wkt( wkt[i], geom );
      box_geographic b = bg::return_envelope<box_geographic>( geom );
      rtree.insert(std::make_pair(b, i));
    } else if (geomType == "POLYGON") {
      polygon_geographic geom;
      bg::read_wkt( wkt[i], geom );
      box_geographic b = bg::return_envelope<box_geographic>( geom );
      rtree.insert(std::make_pair(b, i));
    } else if (geomType == "MULTIPOLYGON") {
      multi_polygon_geographic geom;
      bg::read_wkt( wkt[i], geom );
      box_geographic b = bg::return_envelope<box_geographic>( geom );
      rtree.insert(std::make_pair(b, i));
    }
  }
}

void query_intersects_cartesian(std::string& thisWkt, std::vector<CartesianBoxUnsignedValue>& result_s, bgi::rtree< CartesianBoxUnsignedValue, bgi::quadratic<16> >& rtree) {

  std::string geomType = geomFromWKT( thisWkt );

  if (geomType == "BOX") {
    box_cartesian box;
    bg::read_wkt( thisWkt, box );
    bgi::query( rtree, bgi::intersects( box ), std::back_inserter( result_s ));
  } else if (geomType == "POINT") {
    point_cartesian point;
    bg::read_wkt( thisWkt, point);
    rtree.query( bgi::intersects( point ), std::back_inserter( result_s ));
  } else if (geomType == "MULTIPOINT") {
    multi_point_cartesian multi_point;
    bg::read_wkt( thisWkt, multi_point );
    rtree.query( bgi::intersects( multi_point ), std::back_inserter( result_s ));
  } else if (geomType == "LINESTRING") {
    linestring_cartesian line;
    bg::read_wkt( thisWkt, line );
    rtree.query( bgi::intersects( line ), std::back_inserter( result_s ));
  } else if (geomType == "MULTILINESTRING") {
    multi_linestring_cartesian multi_line;
    bg::read_wkt( thisWkt, multi_line );
    rtree.query( bgi::intersects( multi_line ), std::back_inserter( result_s ));
  } else if (geomType == "POLYGON") {
    box_cartesian poly;
    bg::read_wkt( thisWkt, poly );
    rtree.query( bgi::intersects( poly ), std::back_inserter( result_s ));
  } else if (geomType == "MULTIPOLYGON") {
    multi_polygon_cartesian multi_poly;
    bg::read_wkt( thisWkt, multi_poly );
    rtree.query( bgi::intersects( multi_poly ), std::back_inserter( result_s ));
  }
}
void query_within_cartesian(std::string& thisWkt, std::vector<CartesianBoxUnsignedValue>& result_s, bgi::rtree< CartesianBoxUnsignedValue, bgi::quadratic<16> >& rtree) {

  std::string geomType = geomFromWKT( thisWkt );

  if (geomType == "BOX") {
    box_cartesian box;
    bg::read_wkt( thisWkt, box );
    bgi::query( rtree, bgi::within( box ), std::back_inserter( result_s ));
  }
}


/*
Rcpp::StringMatrix rtreetest( Rcpp::List wkt ) {

  CartesianGeometry geometry;
  CartesianMap geometries;

  bgi::rtree< CartesianValue, bgi::quadratic<16> > rtree;

  for (unsigned i = 0; i < wkt.length(); i++ ) {
    geometry = read_cartesian_wkt( wkt[i] );
    geometries.insert(std::make_pair(i, geometry));
  }

  // fill the spatial index
  for ( CartesianMap::iterator it = geometries.begin(); it != geometries.end(); ++it )
  {
    // calculate polygon bounding box
    box_cartesian b = boost::apply_visitor(envelope_visitor_cartesian(), it->second);
    // insert new value
    rtree.insert(std::make_pair(b, it));
  }

  // find values intersecting some area defined by a box
  box_cartesian query_box( point_cartesian( 2, 2 ), point_cartesian( 5, 5 ) );
  std::vector<CartesianValue> result_s;
  rtree.query( bgi::intersects( query_box ), std::back_inserter( result_s ) );

  // display results
  std::cout << "spatial query box:" << std::endl;
  std::cout << bg::wkt<box_cartesian>( query_box ) << std::endl;
  std::cout << "spatial query result:" << std::endl;

  BOOST_FOREACH(CartesianValue const& v, result_s){
    boost::apply_visitor(print_visitor(), v.second->second);

  }

  // getting index of iterator:
  // it - vec.begin()

  Rcpp::StringMatrix res( result_s.size(), 2 );

  int i = 0;
  for ( auto r : result_s ) {
    std::string s = boost::apply_visitor(wkt_visitor(), r.second->second);
    //std::string t = boost::apply_visitor(wkt_visitor(), query_box);
    res(i, 0) = s;
    //res(i, 1) = t;
    i++;
  }

  return res;
}


void rtreetest2() {

  typedef bg::model::point<float, 2, bg::cs::cartesian> point;
  typedef bg::model::box<point> box;
  typedef std::pair<box, unsigned> value;

  // create the rtree using default constructor
  bgi::rtree< value, bgi::quadratic<16> > rtree;

  // create some values
  for ( unsigned i = 0 ; i < 10 ; ++i )
  {
    // create a box
    box b(point(i + 0.0f, i + 0.0f), point(i + 0.5f, i + 0.5f));
    // insert new value
    rtree.insert(std::make_pair(b, i));
  }

  // find values intersecting some area defined by a box
  box query_box(point(0, 0), point(2, 2));
  std::vector<value> result_s;
  rtree.query(bgi::intersects(query_box), std::back_inserter(result_s));

  // find 5 nearest values to a point
  //std::vector<value> result_n;
  //rtree.query(bgi::nearest(point(0, 0), 5), std::back_inserter(result_n));

  // display results
  std::cout << "spatial query box:" << std::endl;
  std::cout << bg::wkt<box>(query_box) << std::endl;
  std::cout << "spatial query result:" << std::endl;
  BOOST_FOREACH(value const& v, result_s)
    std::cout << bg::wkt<box>(v.first) << " - " << v.second << std::endl;

  //std::cout << "knn query point:" << std::endl;
  //std::cout << bg::wkt<point>(point(0, 0)) << std::endl;
  //std::cout << "knn query result:" << std::endl;
  //BOOST_FOREACH(value const& v, result_n)
  //  std::cout << bg::wkt<box>(v.first) << " - " << v.second << std::endl;
}
*/

void cartesian_rtree( CartesianGeometry& geom,
                      Rcpp::List& wkt,
                      bgi::rtree< CartesianBoxUnsignedValue, bgi::quadratic<16> >& rtree) {

  for (size_t i = 0; i < wkt.size(); i++) {
    geom = read_cartesian_wkt( wkt[i] );
    box_cartesian b = boost::apply_visitor(envelope_visitor_cartesian(), geom);
    rtree.insert(std::make_pair(b, i));
  }
}

void spherical_rtree( SphericalGeometry& geom,
                      Rcpp::List& wkt,
                      bgi::rtree< SphericalBoxUnsignedValue, bgi::quadratic<16> >& rtree) {

  for (size_t i = 0; i < wkt.size(); i++) {
    geom = read_spherical_wkt( wkt[i] );
    box_spherical b = boost::apply_visitor(envelope_visitor_spherical(), geom);
    rtree.insert(std::make_pair(b, i));
  }
}

void geographic_rtree( GeographicGeometry& geom,
                      Rcpp::List& wkt,
                      bgi::rtree< GeographicBoxUnsignedValue, bgi::quadratic<16> >& rtree) {

  for (size_t i = 0; i < wkt.size(); i++) {
    geom = read_geographic_wkt( wkt[i] );
    box_geographic b = boost::apply_visitor(envelope_visitor_geographic(), geom);
    rtree.insert(std::make_pair(b, i));
  }
}

void rcpp_bg_predicate_operation_cartesian(
    std::string& predicate,
    bgi::rtree< CartesianBoxUnsignedValue, bgi::quadratic<16> >& rtree,
    std::vector<CartesianBoxUnsignedValue>& result_s,
    CartesianGeometry& geom) {

  //TODO(the rtree query is slow)
  if (predicate == "intersects") {
    rtree.query(bgi::intersects(geom), std::back_inserter(result_s));
  }
  // TODO(other rtree queries)
  // - requires other operations to accept CartesianGeometry!!
}

void rcpp_bg_predicate_cartesian(
  std::string& predicate,
  Rcpp::List& wkt,
  CartesianGeometry& geom,
  bgi::rtree< CartesianBoxUnsignedValue, bgi::quadratic<16> >& rtree,
  Rcpp::List& res) {

  for (size_t i = 0; i < wkt.size(); i++) {

    geom = read_cartesian_wkt( wkt[i] );
    std::vector<CartesianBoxUnsignedValue> result_s;

    rcpp_bg_predicate_operation_cartesian(predicate, rtree, result_s, geom);

    Rcpp::IntegerVector iv(result_s.size());
    int counter = 0;
    for (auto r : result_s) {
      iv[counter] = r.second + 1;  // 1-index
      counter++;
    }
    res[i] = iv;
  }
}

// [[Rcpp::export]]
Rcpp::List rcpp_bg_join_predicate_cartesian( Rcpp::List wktOne, Rcpp::List wktTwo, std::string predicate ) {

  Rcpp::List res( wktTwo.size() );
  CartesianGeometry geomOne;
  CartesianGeometry geomTwo;

  bgi::rtree< CartesianBoxUnsignedValue, bgi::quadratic<16> > rtree;

  cartesian_rtree(geomOne, wktOne, rtree);

  rcpp_bg_predicate_cartesian(predicate, wktTwo, geomTwo, rtree, res);
  return res;
}




