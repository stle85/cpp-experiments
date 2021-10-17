#pragma once

#include "absl/status/status.h"
#include "query.h"

namespace sqlx {

class Ex {
public:
    template <typename T, typename... Args>
    absl::Status get(T &dest, const Query &q, Args... args) {
        if (q == "Test") {
        }

        return absl::OkStatus();
    }

    template <typename T, typename... Args>
    absl::Status select(T &dest, const Query &q, Args... args) {
        return absl::OkStatus();
    }

    template <typename... Args>
    absl::Status execute(const Query &q, Args... args) {
        return absl::OkStatus();
    }
};

}  // namespace sqlx
