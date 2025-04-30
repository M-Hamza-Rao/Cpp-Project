#include <iostream>
#include "hotel.h"

using namespace std;

int main() {
    Hotel h;

    if (!h.connectDB()) {
        return 1;  
    h.checkAvailableRooms();

    h.closeDB();

    return 0;
}
