#include "R_boostgeometry_equals.h"
#include <Rcpp.h>
using namespace Rcpp;

// TODO(not fully supported)

/*
 * CARTESIAN
 */
void equals_point_cartesian(
    std::string& thisWktOne, std::string& thisWktTwo, size_t i, size_t j, Rcpp::LogicalMatrix& wktEquals) {

  point_cartesian point;
  point_cartesian equalsPoint;

  bg::read_wkt( thisWktOne, point );
  bg::read_wkt( thisWktTwo, equalsPoint );
  wktEquals(i, j) = bg::equals( point, equalsPoint );
}

void equals_linestring_cartesian(
    std::string& thisWktOne, std::string& thisWktTwo, size_t i, size_t j, Rcpp::LogicalMatrix& wktEquals) {

  CartesianLineEquals line;
  CartesianLineEquals equalsLine;

  line = read_cartesian_equals_line_wkt( thisWktOne );
  equalsLine = read_cartesian_equals_line_wkt( thisWktTwo );
  wktEquals(i, j) = bg::equals( line, equalsLine );
}


void equals_polygon_cartesian(
    std::string& thisWktOne, std::string& thisWktTwo, size_t i, size_t j, Rcpp::LogicalMatrix& wktEquals) {

  CartesianPolygonEquals polygon;
  CartesianPolygonEquals equalsPolygon;

  polygon = read_cartesian_equals_polygon_wkt( thisWktOne );
  equalsPolygon = read_cartesian_equals_polygon_wkt( thisWktTwo );
  wktEquals(i, j) = bg::equals( polygon, equalsPolygon );
}

/*
 * END CARTESIAN
 */

bool isValidComparison (std::string& thisWktOne, std::string& thisWktTwo ) {

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

// [[Rcpp::export]]
Rcpp::LogicalMatrix rcpp_wkt_equals_cartesian( Rcpp::List wktOne, Rcpp::List wktTwo ) {
  Rcpp::LogicalMatrix wktEquals( wktOne.length(), wktTwo.length() );

  std::string geomTypeOne;
  std::string geomTypeTwo;

  for (size_t i = 0; i < wktOne.length(); i++ ) {
    std::string thisWktOne = wktOne[i];
    geomTypeOne = geomFromWKT( thisWktOne );

    // TODO(split i & j loop)
    // so that i is only read once.

    for (size_t j = 0; j < wktTwo.length(); j++) {
      std::string thisWktTwo = wktTwo[j];
      geomTypeTwo = geomFromWKT( thisWktTwo );

      if ( isValidComparison(geomTypeOne, geomTypeTwo) ) {

        if ( geomTypeOne == "POINT" ) {
          equals_point_cartesian( thisWktOne, thisWktTwo, i, j, wktEquals );
        } else if (geomTypeOne == "LINESTRING" || geomTypeOne == "MULTILINESTRING") {
          equals_linestring_cartesian( thisWktOne, thisWktTwo, i, j, wktEquals );
        } else if (geomTypeOne == "POLYGON" || geomTypeOne == "MULTIPOLYGON") {
          equals_polygon_cartesian( thisWktOne, thisWktTwo, i, j, wktEquals );
        }
      } else {
        wktEquals(i, j) = false;
      }
    }
  }
  return wktEquals;
}
