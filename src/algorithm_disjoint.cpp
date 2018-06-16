#include "R_boostgeometry_disjoint.h"
#include <Rcpp.h>
using namespace Rcpp;



// [[Rcpp::export]]
void compare_point_cartesian(Rcpp::List& wkt, size_t i) {
  point_cartesian point;
  bg::read_wkt(wkt[i], point);

  // given the algorithm, test if this type of geometry is comparable
  // IF NOT, return
  std::vector<std::string> disjoint_cartesian_geometries{"point", "multipoint"};

  std::find(disjoint_cartesian_geometries.begin(), disjoint_cartesian_geometries.end(), "point");


}


// [[Rcpp::export]]
Rcpp::LogicalMatrix rcpp_wkt_disjoint_cartesian( Rcpp::List wktOne, Rcpp::List wktTwo ) {
  Rcpp::LogicalMatrix wktDisjoint( wktOne.length(), wktTwo.length() );

  CartesianDisjoint geomOne;
  CartesianDisjoint geomTwo;

  std::string geomType;

  for (size_t i = 0; i < wktOne.length(); i++ ) {

    std::string thisWkt = wktOne[i];
    geomType = geomFromWKT( thisWkt );

    geomOne = read_cartesian_disjoint_wkt( wktOne[i] );

    for (size_t j = 0; j < wktTwo.length(); j++ ){
      geomTwo = read_cartesian_disjoint_wkt( wktTwo[j] );
      wktDisjoint(i, j) = bg::disjoint(geomOne, geomTwo);
    }
  }
  return wktDisjoint;
}

// [[Rcpp::export]]
Rcpp::LogicalMatrix rcpp_wkt_disjoint_spherical( Rcpp::List wktOne, Rcpp::List wktTwo ) {
  Rcpp::LogicalMatrix wktDisjoint( wktOne.length(), wktTwo.length() );

  SphericalDisjoint geomOne;
  SphericalDisjoint geomTwo;

  for (size_t i = 0; i < wktOne.length(); i++ ) {
    geomOne = read_spherical_disjoint_wkt( wktOne[i] );

    for (size_t j = 0; j < wktTwo.length(); j++ ){
      geomTwo = read_spherical_disjoint_wkt( wktTwo[j] );
      wktDisjoint(i, j) = bg::disjoint(geomOne, geomTwo);
    }
  }
  return wktDisjoint;
}

// [[Rcpp::export]]
Rcpp::LogicalMatrix rcpp_wkt_disjoint_geographic( Rcpp::List wktOne, Rcpp::List wktTwo ) {
  Rcpp::LogicalMatrix wktDisjoint( wktOne.length(), wktTwo.length() );

  GeographicDisjoint geomOne;
  GeographicDisjoint geomTwo;

  for (size_t i = 0; i < wktOne.length(); i++ ) {
    geomOne = read_geographic_disjoint_wkt( wktOne[i] );

    for (size_t j = 0; j < wktTwo.length(); j++ ){
      geomTwo = read_geographic_disjoint_wkt( wktTwo[j] );
      wktDisjoint(i, j) = bg::disjoint(geomOne, geomTwo);
    }
  }
  return wktDisjoint;
}
