#include <httpserver.hpp>

#include "aircrafts/aircrafts.hpp"
#include "airports/airports.hpp"
#include "boarding_passes/boarding_passes.hpp"
#include "bookings/bookings.hpp"
#include "hello_world/hello_world.hpp"

int main()
{
  httpserver::webserver ws = httpserver::create_webserver(8000);

  HelloWorldResource hwr;
  aircrafts::Aircrafts ac;
  airports::Airports ap;
  boarding_passes::BoardingPasses bp;
  bookings::Bookings b;

  ws.register_resource("/hello", &hwr);
  ws.register_resource("/aircrafts", &ac);
  ws.register_resource("/airports", &ap);
  ws.register_resource("/boarding-passes", &bp);
  ws.register_resource("/bookings", &b);
  ws.start(true);
  return 0;
}
