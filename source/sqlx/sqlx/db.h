#pragma once

#include <memory>
#include <string_view>
#include "absl/status/status.h"
#include "ex.h"
#include "tx.h"

namespace sqlx {

class DB {
public:
    DB();
    ~DB() = default;

    absl::Status connect(std::string_view url);
    absl::Status disconnect();
    std::shared_ptr<Ex> newEx();
    std::shared_ptr<Tx> newTx();

private:
    std::shared_ptr<class DBimpl> impl_;
};

}  // namespace sqlx
