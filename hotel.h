#ifndef HOTEL_H
#define HOTEL_H

#include <mysql.h>
#include <string>
#include <iostream>

class Hotel {
private:
    MYSQL* conn;  // MySQL connection pointer

public:
    // Constructor and Destructor
    Hotel();
    ~Hotel();

    // DB connection and closure
    bool connectDB();
    void closeDB();

    // Table management
    void setupTables();
    void populateRooms();

    // Reservation handling
    void addReservation();
    void checkAvailableRooms();
    void clearUnpaidReservations();
    void viewReservations();
};

#endif
