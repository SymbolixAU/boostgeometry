#include "R_boostgeometry_equals.h"
#include <Rcpp.h>
using namespace Rcpp;

// TODO(not fully supported)

bool isEqualsValidComparison (std::string& thisWktOne, std::string& thisWktTwo ) {

  if (thisWktOne == thisWktTwo) {
    return true;
  }
  // other possible comparisons
  if (thisWktOne == "LINESTRING" && thisWktTwo == "MULTILINESTRING") {
    return true;
  }
  if (thisWktOne == "MULTILINESTRING" && thisWktTwo == "LINESTRING") {
    return true;
  }
  if (thisWktOne == "POLYGON" && thisWktTwo == "MULTIPOLYGON") {
    return true;
  }
  if (thisWktOne == "MULTIPOLYGON" && thisWktTwo == "POLYGON") {
    return true;
  }
  return false;
}

/*
 * CARTESIAN
 */
void equals_point_cartesian(
    std::string& geomTypeOne, std::string& thisWktOne, Rcpp::List& wktTwo, size_t i,  Rcpp::LogicalMatrix& wktEquals) {

  point_cartesian point;
  bg::read_wkt(thisWktOne, point);

  std::string geomTypeTwo;

  for (size_t j = 0; j < wktTwo.length(); j++) {
    std::string thisWktTwo = wktTwo[j];
    geomTypeTwo = geomFromWKT( thisWktTwo );

    if ( isEqualsValidComparison(geomTypeOne, geomTypeTwo) ) {
      point_cartesian equalsPoint;
      bg::read_wkt( thisWktTwo, equalsPoint );
      wktEquals(i, j) = bg::equals( point, equalsPoint );
    }
  }
}

void equals_linestring_cartesian(
    std::string& geomTypeOne, std::string& thisWktOne, Rcpp::List& wktTwo, size_t i, Rcpp::LogicalMatrix& wktEquals) {

  CartesianLineEquals line;
  line = read_cartesian_equals_line_wkt( thisWktOne );
  std::string geomTypeTwo;

  for (size_t j = 0; j < wktTwo.length(); j++) {
    std::string thisWktTwo = wktTwo[j];
    geomTypeTwo = geomFromWKT( thisWktTwo );

    if ( isEqualsValidComparison(geomTypeOne, geomTypeTwo) ) {
      CartesianLineEquals equalsLine;
      equalsLine = read_cartesian_equals_line_wkt( thisWktTwo );
      wktEquals(i, j) = bg::equals( line, equalsLine );
    }
  }
}

void equals_polygon_cartesian(
    std::string& geomTypeOne, std::string& thisWktOne, Rcpp::List& wktTwo, size_t i, Rcpp::LogicalMatrix& wktEquals) {

  CartesianPolygonEquals polygon;
  polygon = read_cartesian_equals_polygon_wkt( thisWktOne );
  std::string geomTypeTwo;

  for (size_t j = 0; j < wktTwo.length(); j++) {
    std::string thisWktTwo = wktTwo[j];
    geomTypeTwo = geomFromWKT( thisWktTwo );

    if ( isEqualsValidComparison(geomTypeOne, geomTypeTwo) ) {
      CartesianPolygonEquals equalsPolygon;
      equalsPolygon = read_cartesian_equals_polygon_wkt( thisWktTwo );
      wktEquals(i, j) = bg::equals( polygon, equalsPolygon );
    }
  }
}

/*
 * END CARTESIAN
 */

// [[Rcpp::export]]
Rcpp::LogicalMatrix rcpp_wkt_equals_cartesian( Rcpp::List wktOne, Rcpp::List wktTwo ) {
  Rcpp::LogicalMatrix wktEquals( wktOne.length(), wktTwo.length() );

  std::string geomTypeOne;
  std::string geomTypeTwo;

  for (size_t i = 0; i < wktOne.length(); i++ ) {
    std::string thisWktOne = wktOne[i];
    geomTypeOne = geomFromWKT( thisWktOne );

    if ( geomTypeOne == "POINT" ) {
      equals_point_cartesian( geomTypeOne, thisWktOne, wktTwo, i, wktEquals );
    } else if ( geomTypeOne == "LINESTRING" || geomTypeOne == "MULTILINESTRING" ) {
      equals_linestring_cartesian( geomTypeOne, thisWktOne, wktTwo, i, wktEquals );
    } else if ( geomTypeOne == "POLYGON" || geomTypeOne == "MULTIPOLYGON" ) {
      equals_polygon_cartesian( geomTypeOne, thisWktOne, wktTwo, i, wktEquals );
    }
  }
  return wktEquals;
}
