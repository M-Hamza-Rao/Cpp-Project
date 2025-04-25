#ifndef HOTEL_H
#define HOTEL_H

#include <mysql.h>
#include <string>
#include <iostream>

class Hotel {
private:
    MYSQL* conn;  

public:
    
    Hotel();
    ~Hotel();

    bool connectDB();
    void closeDB();

    void setupTables();
    void populateRooms();

    void addReservation();
    void checkAvailableRooms();
    void clearUnpaidReservations();
    void viewReservations();
};

#endif
