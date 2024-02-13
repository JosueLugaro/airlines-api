#include "aircrafts.hpp"

#include <iostream>
#include <pqxx/pqxx>

using namespace httpserver;
using namespace pqxx;

std::shared_ptr<http_response>
aircrafts::Aircrafts::render_GET(const http_request &) {
  try {
    char *connection_string = getenv("AIRLINES_CONNECTION");
    connection *c = new connection(connection_string);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return std::shared_ptr<http_response>(
      new string_response("Testing aircrafts endpoint"));
}
