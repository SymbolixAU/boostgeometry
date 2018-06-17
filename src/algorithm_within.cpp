#include "R_boostgeometry_within.h"

#include <Rcpp.h>
using namespace Rcpp;

/*
void point_within_poly() {
  std::string pt = "POINT(0 0)";
  std::string pl = "POLYGON((-1 -1,1 -1,1 1,-1 1,-1 -1))";
  point_cartesian point;
  polygon_cartesian poly;

  bg::read_wkt( pt, point );
  bg::read_wkt( pl, poly );

  bgi::rtree< CartesianBoxUnsignedValue, bgi::quadratic<16> > rtree;
  std::vector<CartesianBoxUnsignedValue> result_s;

  // put point into an rtree
  box_cartesian b = bg::return_envelope<box_cartesian>( poly );
  rtree.insert(std::make_pair(b, 0));

  // query rtree
  bgi::query( rtree, bgi::within( point ), std::back_inserter( result_s ));
}
*/

// [[Rcpp::export]]
Rcpp::LogicalMatrix rcpp_wkt_within_cartesian( Rcpp::List x, Rcpp::List y ) {
  Rcpp::LogicalMatrix wktWithin( x.length(), y.length() );

  CartesianWithinOne geom1;
  CartesianWithinTwo geom2;
  // TODO(try-catch unsupported types)

  for (size_t i = 0; i < x.length(); i++) {
    geom1 = read_cartesian_within_one_wkt( x[i] );
    for (size_t j = 0; j < y.length(); j++) {
      geom2 = read_cartesian_within_two_wkt( y[j] );
      wktWithin(i, j) = bg::within(geom1, geom2);
    }
  }
  return wktWithin;
}

// [[Rcpp::export]]
Rcpp::LogicalMatrix rcpp_wkt_within_spherical( Rcpp::List x, Rcpp::List y ) {
  Rcpp::LogicalMatrix wktWithin( x.length(), y.length() );

  SphericalWithinOne geom1;
  SphericalWithinTwo geom2;

  for (size_t i = 0; i < x.length(); i++) {
    geom1 = read_spherical_within_one_wkt( x[i] );
    for (size_t j = 0; j < y.length(); j++) {
      geom2 = read_spherical_within_two_wkt( y[j] );
      wktWithin(i, j) = bg::within(geom1, geom2);
    }
  }
  return wktWithin;
}

// [[Rcpp::export]]
Rcpp::LogicalMatrix rcpp_wkt_within_geographic( Rcpp::List x, Rcpp::List y ) {
  Rcpp::LogicalMatrix wktWithin( x.length(), y.length() );

  GeographicWithinOne geom1;
  GeographicWithinTwo geom2;

  for (size_t i = 0; i < x.length(); i++) {
    geom1 = read_geographic_within_one_wkt( x[i] );
    for (size_t j = 0; j < y.length(); j++) {
      geom2 = read_geographic_within_two_wkt( y[j] );
      wktWithin(i, j) = bg::within(geom1, geom2);
    }
  }
  return wktWithin;
}


