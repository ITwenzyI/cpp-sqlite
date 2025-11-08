/*
 * File: main
 * Author: Kilian | ItwenzyI
 * Created: 26.10.2025
 * Description: 
 */
//

#include <iostream>
#include "db.hpp"

int main() {
    Database db("../data/test.db");
    //db.createTable();

    //db.insertUser("Kilian", 24);
    //db.insertUser("GitHub", 30);
    //db.updateUser(1, "Kilian L.", 25);
    //db.deleteUserByID(2);

    // if (auto user = db.findUserByName("Kilian L.")) {
    //     std::cout << "Gefunden: ID=" << user->id << ", Name=" << user->name << ", Alter=" << user->age << "\n";
    // } else {
    //     std::cout << "Kein Benutzer gefunden.\n";
    // }

    if (auto user = db.updateUser(1, "Kilian Update", 25)) {
        std::cout << "ID=" << user->id << ", Name=" << user->name << ", Age=" << user->age << "\n";
    }
    else {
        std::cout << "Kein Benutzer gefunden.\n";
    }

    auto result = db.deleteUserById(5);

    switch (result) {
        case DBResult::OK:
            std::cout << "User gelöscht.\n";
            break;
        case DBResult::NotFound:
            std::cout << "Keine passende ID gefunden.\n";
            break;
        case DBResult::Error:
            std::cout << "Fehler bei der Datenbankoperation.\n";
            break;
    }




    auto users = db.getAllUsers();
    for (const auto& user : users) {
        std::cout << "ID: " << user.id
                  << " | Name: " << user.name
                  << " | Alter: " << user.age << '\n';
    }


    //db.printAllUsers();

    return 0;
}
