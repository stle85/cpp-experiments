#pragma once

#include "absl/status/status.h"
#include "ex.h"

namespace sqlx {

class Tx : public Ex {
public:
    absl::Status commit();
    absl::Status rollback();
};

}  // namespace sqlx
