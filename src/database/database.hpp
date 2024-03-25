#include <pqxx/pqxx>

namespace database
{
  pqxx::result query_all(std::string table, std::string limit, std::string offset);
}
