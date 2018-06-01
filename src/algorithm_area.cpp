#include "R_boostgeometry.h"
#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
Rcpp::NumericVector rcpp_wkt_area( Rcpp::List wkt, const char* strategy ) {
  Rcpp::NumericVector wktArea( wkt.length() );

  // AREA: cartesian / spherical / geographic
  CSGGeometry geom;
  int tp;
  make_strategy(strategy, &tp);

  for (size_t i = 0; i < wkt.length(); i++ ) {
    geom = read_any_wkt(wkt[i], tp);
    std::ostringstream os;
    wktArea[i] = bg::area(geom);
  }
  return wktArea;
}

/*

void area_test() {
  double area_poly;
  double area_multi;

  std::string wkt_multi = "MULTIPOLYGON (((-78.65572 33.94867, -78.63472 33.97798, -78.63027 34.0102, -78.58778 34.03061, -78.56343 34.05894, -78.54428 34.13416, -78.52724 34.15486, -78.49274 34.1585, -78.42543 34.13807, -78.36112 34.18672, -78.37357 34.20235, -78.26106 34.21526, -78.15479 34.36224, -78.13024 34.36412, -78.02592 34.32877, -78.01131 34.31261, -78.00702 34.28482, -77.99539 34.2828, -78.00022 34.26788, -77.98315 34.26168, -77.97528 34.24336, -77.96587 34.24229, -77.96073 34.18924, -77.95853 33.99258, -78.03481 33.91429, -78.57972 33.88199, -78.65572 33.94867)))";
  std::string wkt_poly = "POLYGON ((-78.65572 33.94867, -78.63472 33.97798, -78.63027 34.0102, -78.58778 34.03061, -78.56343 34.05894, -78.54428 34.13416, -78.52724 34.15486, -78.49274 34.1585, -78.42543 34.13807, -78.36112 34.18672, -78.37357 34.20235, -78.26106 34.21526, -78.15479 34.36224, -78.13024 34.36412, -78.02592 34.32877, -78.01131 34.31261, -78.00702 34.28482, -77.99539 34.2828, -78.00022 34.26788, -77.98315 34.26168, -77.97528 34.24336, -77.96587 34.24229, -77.96073 34.18924, -77.95853 33.99258, -78.03481 33.91429, -78.57972 33.88199, -78.65572 33.94867))";

  typedef bgm::polygon<point_geographic> polygon_geographic;
  typedef bgm::multi_polygon<bgm::polygon<point_geographic> > multi_polygon_geographic;

  boost::geometry::model::polygon< boost::geometry::model::point<double, 2, bg::cs::geographic<bg::degree> > > poly;
  boost::geometry::model::multi_polygon< boost::geometry::model::polygon< boost::geometry::model::point<double, 2, bg::cs::geographic<bg::degree> > > > multi;

  boost::geometry::read_wkt(wkt_poly, poly);
  boost::geometry::read_wkt(wkt_multi, multi);

  area_poly = boost::geometry::area(poly);
  area_multi = boost::geometry::area(multi);

  std::cout << "polygon area: " << area_poly << std::endl;
  std::cout << "multipolygon area: " << area_multi << std::endl;

}
*/
