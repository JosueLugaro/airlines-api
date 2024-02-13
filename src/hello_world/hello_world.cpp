#include "hello_world.hpp"

using namespace std;
using namespace httpserver;

shared_ptr<http_response> HelloWorldResource::render(const http_request&) {
  return shared_ptr<http_response>(new string_response("Hello World!"));
}
