#pragma once

#include <httpserver.hpp>

class hello_world_resource : public httpserver::http_resource {
public:
  std::shared_ptr<httpserver::http_response> render(const httpserver::http_request&);
  virtual ~hello_world_resource() = default;
};
