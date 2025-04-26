#include <iostream>
#include "hotel.h"

using namespace std;

int main() {
    Hotel h;

    // Connect to DB
    if (!h.connectDB()) {
        return 1;  // Exit if DB connection fails
    }

    // Create tables and populate rooms
    //h.setupTables();
    //h.populateRooms();

    // Now you can start implementing your hotel management logic
    // Example: checking available rooms
    h.checkAvailableRooms();

    // Exit
    h.closeDB();

    return 0;
}
