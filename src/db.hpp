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
    void testConnection();


private:
    sqlite3* db_; // roher C-Pointer auf die SQLite DB
};

#endif // DB_HPP
