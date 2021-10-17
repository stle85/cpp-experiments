#include "query.h"
#include <string_view>

namespace sqlx {

Query::Query(std::string_view query)
    : query(query) {}

}  // namespace sqlx

bool operator==(const sqlx::Query &q, std::string_view query) { return q.query == query; }
