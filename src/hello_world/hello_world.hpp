#pragma once

#include <httpserver.hpp>

class HelloWorldResource : public httpserver::http_resource {
 public:
  std::shared_ptr<httpserver::http_response> render(
      const httpserver::http_request&);
};
