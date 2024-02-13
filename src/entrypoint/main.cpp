#include <httpserver.hpp>
#include "hello_world/hello_world.hpp"


using namespace httpserver;

int main() {
  webserver ws = create_webserver(8000);

  hello_world_resource hwr;

  ws.register_resource("/hello", &hwr);
  ws.start(true);
  return 0;
}
