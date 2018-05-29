#include "R_boostgeometry.h"
#include <Rcpp.h>
using namespace Rcpp;

/*
* CARTESIAN
*/
void unique_linestring_cartesian(Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktunique) {

  linestring_cartesian line;

  bg::read_wkt( wkt[i], line );
  bg::unique( line );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( line );
  wktunique[i] = os.str();
}

void unique_multi_linestring_cartesian(Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktunique) {

  multi_linestring_cartesian line;

  bg::read_wkt( wkt[i], line );
  bg::unique( line );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( line );
  wktunique[i] = os.str();
}

void unique_polygon_cartesian(Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktunique) {

  polygon_cartesian line;

  bg::read_wkt( wkt[i], line );
  bg::unique( line );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( line );
  wktunique[i] = os.str();
}

void unique_multi_polygon_cartesian(Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktunique) {

  multi_polygon_cartesian line;

  bg::read_wkt( wkt[i], line );
  bg::unique( line );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( line );
  wktunique[i] = os.str();
}
/*
* END CARTESIAN
*/

/*
* SPHERICAL
*/
void unique_linestring_spherical(Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktunique) {

  linestring_spherical line;

  bg::read_wkt( wkt[i], line );
  bg::unique( line );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( line );
  wktunique[i] = os.str();
}

void unique_multi_linestring_spherical(Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktunique) {

  multi_linestring_spherical line;

  bg::read_wkt( wkt[i], line );
  bg::unique( line );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( line );
  wktunique[i] = os.str();
}

void unique_polygon_spherical(Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktunique) {

  polygon_spherical line;

  bg::read_wkt( wkt[i], line );
  bg::unique( line );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( line );
  wktunique[i] = os.str();
}

void unique_multi_polygon_spherical(Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktunique) {

  multi_polygon_spherical line;

  bg::read_wkt( wkt[i], line );
  bg::unique( line );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( line );
  wktunique[i] = os.str();
}
/*
* END SPHERICAL
*/

/*
* GEOGRAPHIC
*/
void unique_linestring_geographic(Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktunique) {

  linestring_geographic line;

  bg::read_wkt( wkt[i], line );
  bg::unique( line );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( line );
  wktunique[i] = os.str();
}

void unique_multi_linestring_geographic(Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktunique) {

  multi_linestring_geographic line;

  bg::read_wkt( wkt[i], line );
  bg::unique( line );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( line );
  wktunique[i] = os.str();
}

void unique_polygon_geographic(Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktunique) {

  polygon_geographic line;

  bg::read_wkt( wkt[i], line );
  bg::unique( line );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( line );
  wktunique[i] = os.str();
}

void unique_multi_polygon_geographic(Rcpp::List& wkt, size_t i, Rcpp::StringVector& wktunique) {

  multi_polygon_geographic line;

  bg::read_wkt( wkt[i], line );
  bg::unique( line );

  std::ostringstream os;
  os << std::setprecision(12) << bg::wkt( line );
  wktunique[i] = os.str();
}
/*
* END GEOGRAPHIC
*/

// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_unique_cartesian( Rcpp::List wkt ) {
  Rcpp::StringVector wktunique( wkt.length() );

  std::string geomType;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    std::string thisWkt = wkt[i];
    geomType = geomFromWKT( thisWkt );

    if (geomType == "POINT" || geomType == "MULTIPOINT") {
      wktunique[i] = thisWkt;
    } else if (geomType == "LINESTRING") {
      unique_linestring_cartesian(wkt, i, wktunique );
    } else if (geomType == "MULTILINESTRING") {
      unique_multi_linestring_cartesian(wkt, i, wktunique );
    } else if (geomType == "POLYGON") {
      unique_polygon_cartesian(wkt, i, wktunique );
    } else if (geomType == "MULTIPOLYGON") {
      unique_multi_polygon_cartesian(wkt, i, wktunique );
    }
  }
  return wktunique;
}

// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_unique_spherical( Rcpp::List wkt ) {
  Rcpp::StringVector wktunique( wkt.length() );

  std::string geomType;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    std::string thisWkt = wkt[i];
    geomType = geomFromWKT( thisWkt );

    if (geomType == "POINT" || geomType == "MULTIPOINT") {
      wktunique[i] = thisWkt;
    } else if (geomType == "LINESTRING") {
      unique_linestring_spherical(wkt, i, wktunique);
    } else if (geomType == "MULTILINESTRING") {
      unique_multi_linestring_spherical(wkt, i, wktunique);
    } else if (geomType == "POLYGON") {
      unique_polygon_spherical(wkt, i, wktunique);
    } else if (geomType == "MULTIPOLYGON") {
      unique_multi_polygon_spherical(wkt, i, wktunique);
    }
  }
  return wktunique;
}

// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_unique_geographic( Rcpp::List wkt ) {
  Rcpp::StringVector wktunique( wkt.length() );

  std::string geomType;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    std::string thisWkt = wkt[i];
    geomType = geomFromWKT( thisWkt );

    if (geomType == "POINT" || geomType == "MULTIPOINT") {
      wktunique[i] = thisWkt;
    } else if (geomType == "LINESTRING") {
      unique_linestring_geographic(wkt, i, wktunique);
    } else if (geomType == "MULTILINESTRING") {
      unique_multi_linestring_geographic(wkt, i, wktunique);
    } else if (geomType == "POLYGON") {
      unique_polygon_geographic(wkt, i, wktunique);
    } else if (geomType == "MULTIPOLYGON") {
      unique_multi_polygon_geographic(wkt, i, wktunique);
    }
  }
  return wktunique;
}
