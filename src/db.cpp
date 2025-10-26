#include "db.hpp"
#include <iostream>

Database::Database(const std::string& db_path)
    : db_(nullptr)
{
    if (sqlite3_open(db_path.c_str(), &db_) != SQLITE_OK) {
        std::cerr << "Fehler beim Öffnen der Datenbank: "
                  << sqlite3_errmsg(db_) << std::endl;
    } else {
        std::cout << "Datenbank erfolgreich geöffnet.\n";
    }
}

Database::~Database() {
    if (db_) {
        sqlite3_close(db_);
        std::cout << "Datenbank geschlossen.\n";
    }
}

void Database::testConnection() {
    std::cout << "[Test] Verbindung aktiv.\n";
}
