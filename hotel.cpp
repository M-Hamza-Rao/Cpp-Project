#include "hotel.h"

using namespace std;


Hotel::Hotel() {
    conn = mysql_init(NULL);
}


Hotel::~Hotel() {
    if (conn != NULL) {
        mysql_close(conn);
    }
}

bool Hotel::connectDB() {
    if (!mysql_real_connect(conn, "localhost", "root", "1234", "mydb", 3306, NULL, 0)) {
        cout << "Error: " << mysql_error(conn) << endl;
        return false;
    }
    cout << "Logged in to Database" << endl;
    return true;
}


void Hotel::closeDB() {
    mysql_close(conn);
    cout << "Connection closed" << endl;
}


void Hotel::setupTables() {
    const char* create_rooms_table = 
        "CREATE TABLE IF NOT EXISTS rooms ("
        "id INT PRIMARY KEY, "
        "type ENUM('P', 'S', 'D'), "
        "available_from DATETIME, "
        "reserved_by INT, "
        "price_per_night FLOAT);";

    if (mysql_query(conn, create_rooms_table)) {
        cout << "Error creating rooms table: " << mysql_error(conn) << endl;
    } else {
        cout << "Rooms table created!" << endl;
    }

    const char* create_customers_table =
        "CREATE TABLE IF NOT EXISTS customers ("
        "id INT PRIMARY KEY AUTO_INCREMENT, "
        "name VARCHAR(50), "
        "phone VARCHAR(15), "
        "payment_status ENUM('paid', 'unpaid'), "
        "room_type ENUM('P', 'S', 'D'), "
        "room_id INT, "
        "check_in DATETIME, "
        "check_out DATETIME);";

    if (mysql_query(conn, create_customers_table)) {
        cout << "Error creating customers table: " << mysql_error(conn) << endl;
    } else {
        cout << "Customers table created!" << endl;
    }
}

void Hotel::populateRooms() {
    string query;
    
    for (int i = 1; i <= 10; i++) {
        query = "INSERT INTO rooms (id, type, available_from, reserved_by, price_per_night) VALUES ("
                + to_string(i) + ", 'P', NOW(), NULL, 50)";
        mysql_query(conn, query.c_str());
    }

    for (int i = 1; i <= 15; i++) {
        query = "INSERT INTO rooms (id, type, available_from, reserved_by, price_per_night) VALUES ("
                + to_string(i) + ", 'S', NOW(), NULL, 35)";
        mysql_query(conn, query.c_str());
    }

    // Insert 25 Deluxe rooms
    for (int i = 1; i <= 25; i++) {
        query = "INSERT INTO rooms (id, type, available_from, reserved_by, price_per_night) VALUES ("
                + to_string(i) + ", 'D', NOW(), NULL, 25)";
        mysql_query(conn, query.c_str());
    }

    cout << "Rooms populated!" << endl;
}

void Hotel::checkAvailableRooms() {
    const char* query = "SELECT id, type, price_per_night FROM rooms WHERE reserved_by IS NULL";
    if (mysql_query(conn, query)) {
        cout << "Error checking available rooms: " << mysql_error(conn) << endl;
        return;
    }

    MYSQL_RES* res = mysql_store_result(conn);
    if (!res) {
        cout << "Error fetching result: " << mysql_error(conn) << endl;
        return;
    }

    MYSQL_ROW row;
    cout << "Available Rooms: " << endl;
    while ((row = mysql_fetch_row(res))) {
        cout << "Room ID: " << row[0] << ", Type: " << row[1] << ", Price: " << row[2] << " Euro/night" << endl;
    }

    mysql_free_result(res);
}
