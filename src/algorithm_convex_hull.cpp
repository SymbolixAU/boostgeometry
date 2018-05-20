#include "R_boostgeometry_convex_hull.h"
#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_convex_hull_cartesian( Rcpp::List wkt ) {
  Rcpp::StringVector wktHull( wkt.length() );

  polygon_cartesian hull;
  CartesianConvexHull geom;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_cartesian_convex_hull_wkt( wkt[i] );
    bg::convex_hull(geom, hull);
    std::ostringstream os;
    os << bg::wkt( hull );
    wktHull[i] = os.str();
  }
  return wktHull;
}

/*
Rcpp::StringVector rcpp_wkt_convex_hull_spherical( Rcpp::List wkt ) {
  Rcpp::StringVector wktHull( wkt.length() );

  polygon_spherical hull;
  SphericalConvexHull geom;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_spherical_convex_hull_wkt( wkt[i] );
    bg::convex_hull(geom, hull);
    std::ostringstream os;
    os << bg::wkt( hull );
    wktHull[i] = os.str();
  }
  return wktHull;
}


Rcpp::StringVector rcpp_wkt_convex_hull_geographic( Rcpp::List wkt ) {
  Rcpp::StringVector wktHull( wkt.length() );

  polygon_geographic hull;
  GeographicConvexHull geom;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_geographic_convex_hull_wkt( wkt[i] );
    bg::convex_hull(geom, hull);
    std::ostringstream os;
    os << bg::wkt( hull );
    wktHull[i] = os.str();
  }
  return wktHull;
}
*/
