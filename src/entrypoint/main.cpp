#include <httpserver.hpp>

#include "aircrafts/aircrafts.hpp"
#include "airports/airports.hpp"
#include "hello_world/hello_world.hpp"

int main()
{
  httpserver::webserver ws = httpserver::create_webserver(8000);

  HelloWorldResource hwr;
  aircrafts::Aircrafts ac;
  airports::Airports ap;

  ws.register_resource("/hello", &hwr);
  ws.register_resource("/aircrafts", &ac);
  ws.register_resource("/airports", &ap);
  ws.start(true);
  return 0;
}
