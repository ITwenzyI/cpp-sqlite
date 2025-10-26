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

void Database::createTable() {
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            age INTEGER
        );
    )";

    sqlite3_stmt* stmt = nullptr;

    // 1. prepare
    // Bereitet SQL-Statement vor | Parst die SQL-Zeichenkette,
    // Prüft Syntax und erzeugt ein internes Query-Objekt (vom Typ sqlite3_stmt*), das später ausgeführt werden kann.
    if (sqlite3_prepare_v2(db_, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Prepare-Fehler: " << sqlite3_errmsg(db_) << "\n";
        return;
    }

    // 2. step (ausführen)
    // Führt das vorbereitete Statement einmal aus.
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Step-Fehler: " << sqlite3_errmsg(db_) << "\n";
    } else {
        std::cout << "Tabelle erfolgreich (oder bereits) erstellt.\n";
    }

    // 3. finalize
    sqlite3_finalize(stmt);
}

void Database::insertUser(const std::string& name, int age) {
    const char* sql = "INSERT INTO users (name, age) VALUES (?, ?);";
    sqlite3_stmt* stmt = nullptr;

    // 1. Prepare
    // Bereitet SQL-Statement vor | Parst die SQL-Zeichenkette,
    // Prüft Syntax und erzeugt ein internes Query-Objekt (vom Typ sqlite3_stmt*), das später ausgeführt werden kann.
    if (sqlite3_prepare_v2(db_, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Prepare-Fehler (INSERT): " << sqlite3_errmsg(db_) << "\n";
        return;
    }

    // 2. Parameter binden
    // sqlite3_bind_* ersetzt die ?-Platzhalter im SQL-Statement durch echte Werte.
    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);  // 1. Platzhalter
    sqlite3_bind_int(stmt, 2, age);                                // 2. Platzhalter

    // 3. Ausführen
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Step-Fehler (INSERT): " << sqlite3_errmsg(db_) << "\n";
    } else {
        std::cout << "User eingefügt: " << name << ", Alter " << age << "\n";
    }

    // 4. Aufräumen
    sqlite3_finalize(stmt);
}


void Database::printAllUsers() {
    const char* sql = "SELECT id, name, age FROM users;";
    sqlite3_stmt* stmt = nullptr;

    // 1. Statement vorbereiten
    // Bereitet SQL-Statement vor | Parst die SQL-Zeichenkette,
    // Prüft Syntax und erzeugt ein internes Query-Objekt (vom Typ sqlite3_stmt*), das später ausgeführt werden kann.
    if (sqlite3_prepare_v2(db_, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Prepare-Fehler (SELECT): " << sqlite3_errmsg(db_) << "\n";
        return;
    }

    std::cout << "Alle Benutzer:\n";

    // 2. Ergebnisse Zeile für Zeile durchgehen
    // Führt das vorbereitete Statement mehrmals aus.
    // wiederholter Aufruf von sqlite3_step(stmt) gibt Zeile für Zeile → SQLITE_ROW
    // → danach SQLITE_DONE, wenn keine Zeilen mehr
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id         = sqlite3_column_int(stmt, 0);
        const unsigned char* name = sqlite3_column_text(stmt, 1);
        int age         = sqlite3_column_int(stmt, 2);

        std::cout << "ID: " << id
                    // Cast nötig: SQLite gibt unsigned char*, cout braucht char*. static_cast geht nicht.
                  << " | Name: " << (name ? reinterpret_cast<const char*>(name) : "NULL")
                  << " | Alter: " << age << "\n";
    }

    // 3. Statement freigeben
    sqlite3_finalize(stmt);
}


void Database::updateUser(int id, const std::string& newName, int newAge) {
    const char* sql = "UPDATE users SET name = ?, age = ? WHERE id = ?;";
    sqlite3_stmt* stmt = nullptr;

    // 1. Prepare
    // Bereitet SQL-Statement vor | Parst die SQL-Zeichenkette,
    // Prüft Syntax und erzeugt ein internes Query-Objekt (vom Typ sqlite3_stmt*), das später ausgeführt werden kann.
    if (sqlite3_prepare_v2(db_, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Prepare-Fehler (UPDATE): " << sqlite3_errmsg(db_) << "\n";
        return;
    }

    // 2. Bind Parameter
    // sqlite3_bind_* ersetzt die ?-Platzhalter im SQL-Statement durch echte Werte.
    sqlite3_bind_text(stmt, 1, newName.c_str(), -1, SQLITE_STATIC); // name
    sqlite3_bind_int(stmt, 2, newAge);                               // age
    sqlite3_bind_int(stmt, 3, id);                                   // id (WHERE)

    // 3. Ausführen
    // Führt das vorbereitete Statement einmal aus.
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Step-Fehler (UPDATE): " << sqlite3_errmsg(db_) << "\n";
    } else {
        std::cout << "User mit ID " << id << " aktualisiert.\n";
    }

    // 4. Freigeben
    sqlite3_finalize(stmt);
}


