#pragma once

#include <pqxx/pqxx>
#include <string>

namespace json
{
  template <typename... TYPES>
  class JsonResponse
  {
  private:
    std::string result_string;

  public:
    JsonResponse(pqxx::result &result_set)
    {
      result_string.append("{");
      open_data_block();
      serialize_result_set(result_set);
      close_data_block();
      result_string.append("}");
    };

    std::string get_result_string() { return result_string; }

    void open_data_block() { result_string.append("\"data\": ["); };

    void close_data_block() { result_string.append("]"); }

    void serialize(const char *key, const int &value)
    {
      result_string = result_string + "\"" + key + "\"" + ":" + std::to_string(value);
    };

    void serialize(const char *key, const std::string &value)
    {
      // Some values in the database are stored as objects so I added
      // this conditional to handle those specific cases
      if (value[0] == '{')
      {
        result_string = result_string + "\"" + key + "\"" + ":" + value;
        return;
      };
      result_string = result_string + "\"" + key + "\"" + ":" + "\"" + value + "\"";
    };

    template <std::size_t I = 0>
    void serialize_row(std::tuple<TYPES...> &row, pqxx::result &result_set)
    {
      if constexpr (I < sizeof...(TYPES))
      {
        serialize(result_set.column_name(I), std::get<I>(row));
        if (I != sizeof...(TYPES) - 1)
        {
          result_string.append(",");
        }
        serialize_row<I + 1>(row, result_set);
      }
    };

    void serialize_result_set(pqxx::result &result_set)
    {
      for (auto row : result_set.iter<TYPES...>())
      {
        result_string.append("{");
        serialize_row(row, result_set);
        result_string.append("},");
      }
      result_string.pop_back();
    };
  };
} // namespace json
