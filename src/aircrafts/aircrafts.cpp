#include "aircrafts/aircrafts.hpp"

#include <iostream>
#include <pqxx/pqxx>

#include "database/database.hpp"
#include "json_response/json_response.hpp"

using String = std::string;
using namespace httpserver;

namespace aircrafts
{
  std::shared_ptr<http_response> Aircrafts::render_GET(const http_request &req)
  {
    try
    {
      pqxx::result res = database::query_all("aircrafts_data", req.get_arg("limit"), req.get_arg("offset"));

      json::JsonResponse<String, String, int> json_response(res);

      std::shared_ptr<http_response> response = std::shared_ptr<http_response>(
          new string_response(json_response.get_result_string()));

      response->with_header("Content-Type", "application/json");

      return response;
    }
    catch (const std::exception &e)
    {
      std::cout << e.what() << std::endl;
      return std::shared_ptr<http_response>(new string_response(e.what()));
    };
  }
} // namespace aircrafts
