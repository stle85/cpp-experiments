/**
 * @brief
 *   SQLX library. Provides easy API for working with database.
 */

#include <iostream>
#include <memory>
#include <vector>
#include "sqlx/db.h"

int main(const int, const char *[]) {
    auto db = std::make_unique<sqlx::DB>();
    auto ok = db->connect("posrgres://user:pass@localhost:5432/db");
    if (ok.ok()) {
        auto tx = db->newTx();

        ok = tx->execute(sqlx::Query("SELECT 1"));
        std::cout << ok.message() << std::endl;

        std::vector<int> ids;
        ok = tx->select(ids, sqlx::Query("SELECT ID FROM USERS WHERE NAME={{ 1 }}"), "Mark");
        std::cout << ok.message() << std::endl;
    }
    return 0;
}
