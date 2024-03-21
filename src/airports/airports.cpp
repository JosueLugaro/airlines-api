#include <httpserver.hpp>
#include <pqxx/pqxx>
#include <iostream>
#include <string.h>

#include "airports/airports.hpp"
#include "json_response/json_response.hpp"

using String = std::string;
using namespace httpserver;
using namespace pqxx;

namespace airports
{
  std::shared_ptr<http_response> Airports::render_GET(const http_request &req)
  {
    try
    {
      char *connection_string = getenv("AIRLINES_CONNECTION");
      connection c(connection_string);

      std::string limit(req.get_arg("limit"));
      std::string offset(req.get_arg("offset"));

      if (limit.empty())
      {
        limit = "10";
      }

      if (offset.empty())
      {
        offset = "0";
      }

      std::string query_string = std::format(
          "SELECT * FROM airports_data LIMIT {} OFFSET {};", limit, offset);

      work w(c);
      result res = w.exec(query_string);
      w.commit();

      json::JsonResponse<String, const char*, String, String, String> json_response(res);

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
  };
} // namespace airports
