#include "hello_world.hpp"

using namespace std;
using namespace httpserver;

shared_ptr<http_response> hello_world_resource::render(const http_request&) {
  return shared_ptr<http_response>(new string_response("Hello World!"));
}
