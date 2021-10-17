#pragma once

#include <string>
#include <string_view>

namespace sqlx {

class Query {
public:
    explicit Query(std::string_view query);
    Query(const Query &q) = default;
    Query(Query &&q) noexcept = default;
    ~Query() = default;

    std::string query;
};

}  // namespace sqlx

bool operator==(const sqlx::Query &q, std::string_view query);
