#ifndef DB_HPP
#define DB_HPP

#include <string>
#include <sqlite3.h>


class Database {
public:
    // Konstruktor öffnet die DB
    explicit Database(const std::string& db_path);

    // Destruktor schließt die DB
    ~Database();

    // Testfunktion für erste Query
    static void testConnection();

    // Test Creation
    void createTable();

    void insertUser(const std::string& name, int age);

    void printAllUsers();

    void updateUser(int id, const std::string& newName, int newAge);





private:
    sqlite3* db_; // roher C-Pointer auf die SQLite DB
};

#endif // DB_HPP
