#pragma once

#include <pqxx/pqxx>
#include <string>

namespace json {
template <typename... TYPES>
class JsonResponse {
 private:
  std::string result_string;

 public:
  void serialize(const char* key, const int& value);

  void serialize(const char* key, const std::string& value);

  void serialize_row(pqxx::row& row, pqxx::result& result_set){
      // WIP
  };

  void serialize_result_set(pqxx::result& result_set) {
    for (auto row : result_set.iter<TYPES...>()) {
      serialize_row(row, result_set);
    }
  };
};
}  // namespace json
