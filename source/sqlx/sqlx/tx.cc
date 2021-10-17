#include "tx.h"

namespace sqlx {

absl::Status Tx::commit() { return absl::OkStatus(); }

absl::Status Tx::rollback() { return absl::OkStatus(); }

}  // namespace sqlx
