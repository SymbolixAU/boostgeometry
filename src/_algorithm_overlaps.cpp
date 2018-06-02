#include "R_boostgeometry_overlaps.h"
#include <Rcpp.h>
using namespace Rcpp;


bool isOverlapValidComparison(std::string& thisWktOne, std::string& thisWktTwo) {

  if (thisWktOne == thisWktTwo) {
    return true;
  }
  if ( (thisWktOne == "POINT" && thisWktTwo == "MULTIPOINT" ) ||
       (thisWktOne == "MULTIPOINT" && thisWktTwo == "POINT")) {
    return true;
  }
  if ( (thisWktOne == "LINESTRING" && thisWktTwo == "MULTILINESTRING" ) ||
       (thisWktOne == "MULTILINESTRING" && thisWktTwo == "LINESTRING")) {
    return true;
  }
  if ( (thisWktOne == "POLYGON" && thisWktTwo == "MULTIPOLYGON" ) ||
       (thisWktOne == "MULTIPOLYGON" && thisWktTwo == "POLYGON")) {
    return true;
  }
  return false;
}


/*
 * CARTESIAN
 */
void overlap_point_cartesian(
  std::string& geomTypeOne, std::string& wktOne, Rcpp::List& wktTwo, size_t i, Rcpp::LogicalMatrix& wktOverlaps) {

  CartesianPointOverlaps point = read_cartesian_overlaps_point_wkt( wktOne );
  std::string geomTypeTwo;

  for (size_t j = 0; j < wktTwo.length(); j++) {
    std::string thisWktTwo = wktTwo[j];
    geomTypeTwo = geomFromWKT( thisWktTwo );

    if ( isOverlapValidComparison(geomTypeOne, geomTypeTwo) ) {
      CartesianPointOverlaps overlapPoint = read_cartesian_overlaps_point_wkt( wktTwo[j] );
      //wktOverlaps(i, j) = bg::overlaps( point, overlapPoint );
    }
  }

}


/*
void overlap_linestring_cartesian(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktDensify, double& distance) {

  linestring_cartesian line;
  linestring_cartesian denseLine;

  bg::read_wkt( wkt[i], line );
  bg::densify( line, denseLine, distance );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( denseLine );
  wktDensify[i] = os.str();
}

void overlap_polygon_cartesian(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktDensify, double& distance) {

  polygon_cartesian line;
  polygon_cartesian denseLine;

  bg::read_wkt( wkt[i], line );
  bg::densify( line, denseLine, distance );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( denseLine );
  wktDensify[i] = os.str();
}
*/

/*
 * END CARTESIAN
 */


// [[Rcpp::export]]
Rcpp::LogicalMatrix rcpp_wkt_overlaps_cartesian( Rcpp::List wktOne, Rcpp::List wktTwo ) {
  Rcpp::LogicalMatrix wktOverlaps( wktOne.length(), wktTwo.length() );

  std::string geomTypeOne;
  std::string geomTypeTwo;

  for (size_t i = 0; i < wktOne.length(); i++ ) {
    std::string thisWktOne = wktOne[i];
    geomTypeOne = geomFromWKT( thisWktOne );

    if (geomTypeOne == "POINT" || geomTypeOne == "MULTIPOINT") {
      overlap_point_cartesian(geomTypeOne, thisWktOne, wktTwo, i, wktOverlaps);
    }


    /*
    for (size_t j = 0; j < wktTwo.length(); j++) {
      std::string thisWktTwo = wktTwo[j];
      geomTypeTwo = geomFromWKT( thisWktTwo );

      if ( isOverlapValidComparison(geomTypeOne, geomTypeTwo) ) {

        if ( geomTypeOne == "POINT" || geomTypeTwo == "MULTIPOINT" ) {
          overlap_point_cartesian( thisWktOne, thisWktTwo, i, j, wktOverlaps );
        } else if (geomTypeOne == "LINESTRING" || geomTypeOne == "MULTILINESTRING") {
          //overlap_lines_cartesian( thisWktOne, thisWktTwo, i, j, wktOverlaps );
        } else if (geomTypeOne == "POLYGON" || geomTypeOne == "MULTIPOLYGON") {
          //overlap_polygon_cartesian( thisWktOne, thisWktTwo, i, j, wktOverlaps );
        }
      } else {
        wktOverlaps(i, j) = false;
      }
    }
    */
  }
  return wktOverlaps;
}

/*
Rcpp::LogicalMatrix rcpp_wkt_touches_spherical( Rcpp::List wktOne, Rcpp::List wktTwo ) {
  Rcpp::LogicalMatrix wktTwouches( wktOne.length(), wktTwo.length() );

  SphericalTouches geomFrom;
  SphericalTouches geomTo;

  for (size_t i = 0; i < wktOne.length(); i++) {
    geomFrom = read_spherical_touches_wkt( wktOne[i] );

    for (size_t j = 0; j < wktTwo.length(); j++) {
      geomTo = read_spherical_touches_wkt( wktTwo[j] );

      wktTwouches(i, j) = bg::touches(geomFrom, geomTo);
    }
  }
  return wktTwouches;
}

Rcpp::LogicalMatrix rcpp_wkt_touches_geographic( Rcpp::List wktOne, Rcpp::List wktTwo ) {
  Rcpp::LogicalMatrix wktTwouches( wktOne.length(), wktTwo.length() );

  GeographicTouches geomFrom;
  GeographicTouches geomTo;

  for (size_t i = 0; i < wktOne.length(); i++) {
    geomFrom = read_geographic_touches_wkt( wktOne[i] );

    for (size_t j = 0; j < wktTwo.length(); j++) {
      geomTo = read_geographic_touches_wkt( wktTwo[j] );

      wktTwouches(i, j) = bg::touches(geomFrom, geomTo);
    }
  }
  return wktTwouches;
}
*/
