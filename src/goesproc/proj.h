#pragma once

#if PROJ_VERSION_MAJOR < 4
#error "proj version >= 4 required"
#else
// Assume proj continues to ship with a backwards compatibility layer.
// See for a migration guide https://proj.org/development/migration.html.
#define ACCEPT_USE_OF_DEPRECATED_PROJ_API_H 1
#endif

#include <map>
#include <string>
#include <tuple>
#include <vector>

#include <proj_api.h>

class Proj {
public:
  explicit Proj(const std::vector<std::string>& args);

  explicit Proj(const std::map<std::string, std::string>& args);

  ~Proj();

  std::tuple<double, double> fwd(double lon, double lat);

  std::tuple<double, double> inv(double x, double y);

protected:
  projPJ proj_;
};
