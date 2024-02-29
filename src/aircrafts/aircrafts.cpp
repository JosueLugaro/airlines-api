#include "aircrafts/aircrafts.hpp"
#include "json_response/json_response.hpp"

#include <iostream>
#include <pqxx/pqxx>

using String = std::string;
using namespace httpserver;
using namespace pqxx;

namespace aircrafts {
std::shared_ptr<http_response> Aircrafts::render_GET(const http_request &) {
  try {
    char *connection_string = getenv("AIRLINES_CONNECTION");
    connection c(connection_string);

    work w(c);
    result res = w.exec("SELECT * FROM aircrafts_data");
    w.commit();

    json::JsonResponse<String, String, int> json_response(res);

    std::cout << json_response.get_result_string() << std::endl;

    return std::shared_ptr<http_response>(
        new string_response(json_response.get_result_string()));
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
    return std::shared_ptr<http_response>(new string_response(e.what()));
  };
}
}  // namespace aircrafts
