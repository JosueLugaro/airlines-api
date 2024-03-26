#include <iostream>

#include "flights/flights.hpp"
#include "database/database.hpp"
#include "json_response/json_response.hpp"

using String = std::string;
using namespace httpserver;

namespace flights
{
  std::shared_ptr<http_response> Flights::render_GET(const http_request &req)
  {
    try
    {
      pqxx::result res = database::query_all("flights", req.get_arg("limit"), req.get_arg("offset"));

      json::JsonResponse<
          int, String, String, String, String, String, String, String, String, String>
          json_response(res);

      std::shared_ptr<http_response> response = std::shared_ptr<http_response>(
          new string_response(json_response.get_result_string()));

      response->with_header("Content-Type", "application/json");

      return response;
    }
    catch (const std::exception &e)
    {
      std::cout << e.what() << std::endl;
      return std::shared_ptr<http_response>(new string_response(e.what()));
    }
  }
}
