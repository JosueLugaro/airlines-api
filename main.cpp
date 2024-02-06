#include <httpserver.hpp>
#include <pqxx/pqxx>

using namespace httpserver;
using namespace std;

class hello_world_resource : public http_resource {
  public:
    shared_ptr<http_response> render(const http_request&) {
      return shared_ptr<http_response>(new string_response("Hello World!"));
    }
};

int main() {
  pqxx::connection c;
  webserver ws = create_webserver(8000);

  hello_world_resource hwr;

  ws.register_resource("/hello", &hwr);
  ws.start(true);
  return 0;
}
