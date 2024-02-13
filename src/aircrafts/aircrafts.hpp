#pragma once

#include <httpserver.hpp>

namespace aircrafts {
class Aircrafts : public httpserver::http_resource {
 public:
  std::shared_ptr<httpserver::http_response> render_GET(
      const httpserver::http_request&);
};
}  // namespace aircrafts
