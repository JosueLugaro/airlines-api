#include <pqxx/pqxx>

namespace database
{
  pqxx::result query_all(std::string table, std::string limit, std::string offset)
  {
    char *connection_string = getenv("AIRLINES_CONNECTION");
    pqxx::connection c(connection_string);

    if (limit.empty())
    {
      limit = "10";
    }

    if (offset.empty())
    {
      offset = "0";
    }

    std::string query_string = std::format(
        "SELECT * FROM {} LIMIT {} OFFSET {};", table, limit, offset);

    pqxx::work w(c);
    pqxx::result res = w.exec(query_string);
    w.commit();

    return res;
  }
} // namespace database
