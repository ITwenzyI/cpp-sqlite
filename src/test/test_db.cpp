/*
 * File: test_db
 * Author: Kilian | ItwenzyI
 * Created: 08.11.2025
 * Description: 
 */
//

#include "test_db.hpp"
#include <iostream>

void runDatabaseTests(Database& db) {
    std::cout << "=== Mini-Tests starten ===\n";

    UserResult res = db.insertUser("Tester", 20);
    if (res.status != DBResult::OK) {
        std::cerr << "Insert fehlgeschlagen\n";
        return;
    }
    int id = res.user->id;

    if (db.findUserById(id).status != DBResult::OK)
        std::cerr << "Find fehlgeschlagen\n";

    if (db.updateUser(id, "TesterX", 21).status != DBResult::OK)
        std::cerr << "Update fehlgeschlagen\n";

    if (db.deleteUserById(id) != DBResult::OK)
        std::cerr << "Delete fehlgeschlagen\n";
}
