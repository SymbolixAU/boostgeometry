#include "R_boostgeometry.h"
#include <Rcpp.h>
using namespace Rcpp;

/*
 * CARTESIAN
 */
void densify_linestring_cartesian(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktDensify, double& distance) {

  linestring_cartesian line;
  linestring_cartesian denseLine;

  bg::read_wkt( wkt[i], line );
  bg::densify( line, denseLine, distance );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( denseLine );
  wktDensify[i] = os.str();
}

void densify_multi_linestring_cartesian(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktDensify, double& distance) {

  multi_linestring_cartesian line;
  multi_linestring_cartesian denseLine;

  bg::read_wkt( wkt[i], line );
  bg::densify( line, denseLine, distance );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( denseLine );
  wktDensify[i] = os.str();
}

void densify_polygon_cartesian(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktDensify, double& distance) {

  polygon_cartesian line;
  polygon_cartesian denseLine;

  bg::read_wkt( wkt[i], line );
  bg::densify( line, denseLine, distance );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( denseLine );
  wktDensify[i] = os.str();
}

void densify_multi_polygon_cartesian(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktDensify, double& distance) {

  multi_polygon_cartesian line;
  multi_polygon_cartesian denseLine;

  bg::read_wkt( wkt[i], line );
  bg::densify( line, denseLine, distance );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( denseLine );
  wktDensify[i] = os.str();
}
/*
* END CARTESIAN
*/

/*
 * SPHERICAL
 */
void densify_linestring_spherical(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktDensify, double& distance) {

  linestring_spherical line;
  linestring_spherical denseLine;

  bg::read_wkt( wkt[i], line );
  bg::densify( line, denseLine, distance );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( denseLine );
  wktDensify[i] = os.str();
}

void densify_multi_linestring_spherical(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktDensify, double& distance) {

  multi_linestring_spherical line;
  multi_linestring_spherical denseLine;

  bg::read_wkt( wkt[i], line );
  bg::densify( line, denseLine, distance );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( denseLine );
  wktDensify[i] = os.str();
}

void densify_polygon_spherical(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktDensify, double& distance) {

  polygon_spherical line;
  polygon_spherical denseLine;

  bg::read_wkt( wkt[i], line );
  bg::densify( line, denseLine, distance );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( denseLine );
  wktDensify[i] = os.str();
}

void densify_multi_polygon_spherical(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktDensify, double& distance) {

  multi_polygon_spherical line;
  multi_polygon_spherical denseLine;

  bg::read_wkt( wkt[i], line );
  bg::densify( line, denseLine, distance );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( denseLine );
  wktDensify[i] = os.str();
}
/*
 * END SPHERICAL
 */

/*
 * GEOGRAPHIC
 */
void densify_linestring_geographic(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktDensify, double& distance) {

  linestring_geographic line;
  linestring_geographic denseLine;

  bg::srs::spheroid<double> spheroid(6378137.0, 6356752.3142451793);
  bg::strategy::densify::geographic<> strategy(spheroid);

  bg::read_wkt( wkt[i], line );
  bg::densify( line, denseLine, distance, strategy );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( denseLine );
  wktDensify[i] = os.str();
}

void densify_multi_linestring_geographic(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktDensify, double& distance) {

  multi_linestring_geographic line;
  multi_linestring_geographic denseLine;

  bg::read_wkt( wkt[i], line );
  bg::densify( line, denseLine, distance );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( denseLine );
  wktDensify[i] = os.str();
}

void densify_polygon_geographic(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktDensify, double& distance) {

  polygon_geographic line;
  polygon_geographic denseLine;

  bg::read_wkt( wkt[i], line );
  bg::densify( line, denseLine, distance );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( denseLine );
  wktDensify[i] = os.str();
}

void densify_multi_polygon_geographic(
    Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktDensify, double& distance) {

  multi_polygon_geographic line;
  multi_polygon_geographic denseLine;

  bg::read_wkt( wkt[i], line );
  bg::densify( line, denseLine, distance );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( denseLine );
  wktDensify[i] = os.str();
}
/*
 * END GEOGRAPHIC
 */

// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_densify_cartesian( Rcpp::List wkt, double distance) {
  Rcpp::StringVector wktDensify( wkt.length() );

  std::string geomType;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    std::string thisWkt = wkt[i];
    geomType = geomFromWKT( thisWkt );

    if (geomType == "POINT" || geomType == "MULTIPOINT") {
      wktDensify[i] = thisWkt;
    } else if (geomType == "LINESTRING") {
      densify_linestring_cartesian(wkt, i, wktDensify, distance);
    } else if (geomType == "MULTILINESTRING") {
      densify_multi_linestring_cartesian(wkt, i, wktDensify, distance);
    } else if (geomType == "POLYGON") {
      densify_polygon_cartesian(wkt, i, wktDensify, distance);
    } else if (geomType == "MULTIPOLYGON") {
      densify_multi_polygon_cartesian(wkt, i, wktDensify, distance);
    }
  }
  return wktDensify;
}

// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_densify_spherical( Rcpp::List wkt, double distance) {
  Rcpp::StringVector wktDensify( wkt.length() );

  std::string geomType;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    std::string thisWkt = wkt[i];
    geomType = geomFromWKT( thisWkt );

    if (geomType == "POINT" || geomType == "MULTIPOINT") {
      wktDensify[i] = thisWkt;
    } else if (geomType == "LINESTRING") {
      densify_linestring_spherical(wkt, i, wktDensify, distance);
    } else if (geomType == "MULTILINESTRING") {
      densify_multi_linestring_spherical(wkt, i, wktDensify, distance);
    } else if (geomType == "POLYGON") {
      densify_polygon_spherical(wkt, i, wktDensify, distance);
    } else if (geomType == "MULTIPOLYGON") {
      densify_multi_polygon_spherical(wkt, i, wktDensify, distance);
    }
  }
  return wktDensify;
}

// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_densify_geographic( Rcpp::List wkt, double distance) {
  Rcpp::StringVector wktDensify( wkt.length() );

  std::string geomType;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    std::string thisWkt = wkt[i];
    geomType = geomFromWKT( thisWkt );

    if (geomType == "POINT" || geomType == "MULTIPOINT") {
      wktDensify[i] = thisWkt;
    } else if (geomType == "LINESTRING") {
      densify_linestring_geographic(wkt, i, wktDensify, distance);
    } else if (geomType == "MULTILINESTRING") {
      densify_multi_linestring_geographic(wkt, i, wktDensify, distance);
    } else if (geomType == "POLYGON") {
      densify_polygon_geographic(wkt, i, wktDensify, distance);
    } else if (geomType == "MULTIPOLYGON") {
      densify_multi_polygon_geographic(wkt, i, wktDensify, distance);
    }
  }
  return wktDensify;
}
