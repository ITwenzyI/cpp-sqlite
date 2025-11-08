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
    db.createTable();

    //db.insertUser("Kilian", 24);
    //db.insertUser("GitHub", 30);
    //db.updateUser(1, "Kilian L.", 25);
    //db.deleteUserByID(2);

    db.findUserByName("Kilian L.");
    db.findUserByName("Unbekannt");

    auto users = db.getAllUsers();
    for (const auto& user : users) {
        std::cout << "ID: " << user.id
                  << " | Name: " << user.name
                  << " | Alter: " << user.age << '\n';
    }


    db.printAllUsers();

    return 0;
}
