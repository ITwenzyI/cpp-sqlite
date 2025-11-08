#ifndef DB_HPP
#define DB_HPP

#include <string>
#include <sqlite3.h>
#include "types.hpp"
#include <vector>
#include <optional>


class Database {
public:
    // Konstruktor öffnet die DB
    explicit Database(const std::string& db_path);

    // Destruktor schließt die DB
    ~Database();

    // Test Creation
    void createTable();

    UserResult insertUser(const std::string& name, int age);

    void printAllUsers();

    UserResult updateUser(int id, const std::string& newName, int newAge);

    DBResult deleteUserById(int id);

    UserResult findUserByName(const std::string& name);

    UserResult findUserById(int id);



    std::vector<User> getAllUsers();


private:
    sqlite3* db_; // roher C-Pointer auf die SQLite DB
};

#endif // DB_HPP
