/*
 * File: main
 * Author: Kilian | ItwenzyI
 * Created: 26.10.2025
 * Description: 
 */
//

#include <iostream>
#include "db.hpp"
#include "test/test_db.hpp"


int main() {
    Database db("../data/test.db");
    //db.createTable();

    //db.insertUser("Kilian", 24);
    //db.insertUser("GitHub", 30);
    //db.updateUser(1, "Kilian L.", 25);
    //db.deleteUserByID(2);

    // if (auto user = db.updateUser(1, "Kilian Update", 25)) {
    //     std::cout << "ID=" << user->id << ", Name=" << user->name << ", Age=" << user->age << "\n";
    // }
    // else {
    //     std::cout << "Kein Benutzer gefunden.\n";
    // }

    // UserResult res = db.findUserByName("Kilian Update");
    //
    // switch (res.status) {
    //     case DBResult::OK:
    //         std::cout << "Gefunden: " << res.user->name << ", " << res.user->age << "\n";
    //         break;
    //     case DBResult::NotFound:
    //         std::cout << "Kein User mit diesem Namen gefunden.\n";
    //         break;
    //     case DBResult::Error:
    //         std::cout << "Fehler beim DB-Zugriff.\n";
    //         break;
    // }

    // UserResult res = db.insertUser("Neuer Kilian", 22);
    //
    // switch (res.status) {
    //     case DBResult::OK:
    //         std::cout << "Erstellt: " << res.user->name << ", " << res.user->age << ", " << res.user->id <<"\n";
    //         break;
    //     case DBResult::NotFound:
    //         std::cout << "Kein User mit diesem Namen gefunden.\n";
    //         break;
    //     case DBResult::Error:
    //         std::cout << "Fehler beim DB-Zugriff.\n";
    //         break;
    // }





    auto users = db.getAllUsers();
    for (const auto& user : users) {
        std::cout << "ID: " << user.id
                  << " | Name: " << user.name
                  << " | Alter: " << user.age << '\n';
    }


    runDatabaseTests(db);


    return 0;
}
