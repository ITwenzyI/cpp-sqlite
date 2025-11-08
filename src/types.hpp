/*
 * File: types
 * Author: Kilian | ItwenzyI
 * Created: 08.11.2025
 * Description: 
 */
//

#include <optional>
#include <string>

#ifndef CPP_SQLITE_TYPES_HPP
#define CPP_SQLITE_TYPES_HPP

// User-Datensatz
struct User {
    int id;
    std::string name;
    int age;
};

// Rückgabestatus
enum class DBResult {
    OK,
    NotFound,
    Error
};

// Kombinierter Rückgabetyp für Funktionen mit User-Ergebnis
struct UserResult {
    DBResult status;
    std::optional<User> user;
};

#endif //CPP_SQLITE_TYPES_HPP