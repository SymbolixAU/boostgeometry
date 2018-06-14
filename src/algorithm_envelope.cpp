#include "R_boostgeometry.h"
#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_envelope_cartesian( Rcpp::List wkt ) {
  Rcpp::StringVector wktEnvelope( wkt.length() );

  CartesianGeometry geom;
  box_cartesian box;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_cartesian_wkt( wkt[i] );
    bg::envelope( geom, box );
    std::ostringstream os;
    os << std::setprecision(12) << bg::wkt( box );
    wktEnvelope[i] = os.str();
  }
  return wktEnvelope;
}

// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_envelope_spherical( Rcpp::List wkt ) {
  Rcpp::StringVector wktEnvelope( wkt.length() );

  SphericalGeometry geom;
  box_spherical box;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_spherical_wkt( wkt[i] );
    bg::envelope( geom, box );
    std::ostringstream os;
    os << std::setprecision(12) << bg::wkt( box );
    wktEnvelope[i] = os.str();
  }
  return wktEnvelope;
}

// [[Rcpp::export]]
Rcpp::StringVector rcpp_wkt_envelope_geographic( Rcpp::List wkt ) {
  Rcpp::StringVector wktEnvelope( wkt.length() );

  GeographicGeometry geom;
  box_geographic box;

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_geographic_wkt( wkt[i] );
    bg::envelope( geom, box );
    std::ostringstream os;
    os << std::setprecision(12) << bg::wkt( box );
    wktEnvelope[i] = os.str();
  }
  return wktEnvelope;
}

