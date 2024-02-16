#include "aircrafts.hpp"

#include <iostream>
#include <pqxx/pqxx>

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

    // TODO: Add conversion from result set to JSON

    return std::shared_ptr<http_response>(
        new string_response("Aircrafts endpoint"));
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
    return std::shared_ptr<http_response>(new string_response(e.what()));
  };
}
}  // namespace aircrafts
