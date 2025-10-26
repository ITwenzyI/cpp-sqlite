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

    db.printAllUsers();


    db.testConnection();
    return 0;
}
