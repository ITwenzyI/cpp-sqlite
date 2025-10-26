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
    db.testConnection();
    return 0;
}
