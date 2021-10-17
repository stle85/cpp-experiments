#include "db.h"
#include "db_impl.h"

namespace sqlx {

DB::DB()
    : impl_(std::make_shared<DBimpl>()) {}

absl::Status DB::connect(std::string_view url) { return impl_->connect(url); }

absl::Status DB::disconnect() { return impl_->disconnect(); }

std::shared_ptr<Ex> DB::newEx() { return std::make_shared<Ex>(); }

std::shared_ptr<Tx> DB::newTx() { return std::make_shared<Tx>(); }

}  // namespace sqlx
