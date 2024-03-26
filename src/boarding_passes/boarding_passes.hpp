#pragma once

#include <httpserver.hpp>

namespace boarding_passes
{
  class BoardingPasses : public httpserver::http_resource
  {
  public:
    std::shared_ptr<httpserver::http_response> render_GET(
        const httpserver::http_request &req);
  };
} // namespace boarding_passes
