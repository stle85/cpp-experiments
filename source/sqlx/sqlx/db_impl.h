#pragma once

/**
 * @file db_private.inc
 * @author Stanislav Lebedev (stanislav.lebedev@netcracker.com)
 * @brief Private implementation of DB.
 *
 * @version 0.1
 * @date 2021-10-16
 *
 * @copyright Copyright (c) 2021
 */

#include <string_view>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include "absl/status/status.h"

namespace sqlx {

class DBimpl {
    friend class DB;

public:
    DBimpl() = default;
    ~DBimpl() = default;

private:
    absl::Status connect(std::string_view url);
    absl::Status disconnect();

private:
    SQLHENV env_;
    SQLHDBC conn_;
};

absl::Status DBimpl::connect(std::string_view url) {
    SQLRETURN ret;
    ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env_);
    if ((SQL_SUCCESS != ret) && (SQL_SUCCESS_WITH_INFO != ret)) {
        return absl::InternalError("cannot allocate environment handle");
    }

    ret = SQLSetEnvAttr(env_, SQL_ATTR_ODBC_VERSION, (void *)SQL_ODBC_VER, 0);
    if ((SQL_SUCCESS != ret) && (SQL_SUCCESS_WITH_INFO != ret)) {
        return absl::InternalError("cannot set odbc version attribute");
    }

    ret = SQLAllocHandle(SQL_HANDLE_DBC, env_, &conn_);
    if ((SQL_SUCCESS != ret) && (SQL_SUCCESS_WITH_INFO != ret)) {
        return absl::InternalError("cannot allocate connection");
    }

    /* Set timeout */
    SQLSetConnectAttr(conn_, SQL_LOGIN_TIMEOUT, (SQLPOINTER *)5, 0);

    return absl::OkStatus();
}

absl::Status DBimpl::disconnect() {
    SQLFreeHandle(SQL_HANDLE_DBC, conn_);
    SQLFreeHandle(SQL_HANDLE_ENV, env_);
    return absl::OkStatus();
}

}  // namespace sqlx