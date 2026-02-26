#pragma once
#include <cmath>
#include <numbers>
struct Point {
  double x;
  double y;
};

namespace GeoMath {
inline double degreeToRadians(double degrees) {
  double radians = degrees * std::numbers::pi / 180;
  return radians;
}

inline Point geodeticToCart(double lon, double lat) {
  constexpr double EARTH_RADIUS = 6378137.0;
  double x = EARTH_RADIUS * degreeToRadians(lon);
  double y =
      EARTH_RADIUS *
      (std::log(std::tan(std::numbers::pi / 4 + degreeToRadians((lat)) / 2)));

  return {x, y};
}

}; // namespace GeoMath
