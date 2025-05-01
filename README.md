HOTEL ACCOMMODATION SYSTEM (C++ + MySQL)
=======================================

A simple hotel management system built using C++ and MySQL Connector C for database operations.


REQUIREMENTS
------------

- Windows OS
- Dev-C++ IDE
- MySQL Server installed and running locally
- MySQL Connector/C 6.1 installed at:
  C:\Program Files (x86)\MySQL\MySQL Connector C 6.1\


SETUP INSTRUCTIONS
------------------

1. Install MySQL Connector/C
   - Download from: https://dev.mysql.com/downloads/connector/c/
   - Install using default settings.

2. Configure Dev-C++

   a) Add Include Directory:
      - Go to Tools → Compiler Options
      - Select the Directories tab
      - Choose C++ Includes
      - Click Add
      - Enter:
        C:\Program Files (x86)\MySQL\MySQL Connector C 6.1\include

   b) Add Library Directory:
      - Stay in the Directories tab
      - Choose Libraries
      - Click Add
      - Enter:
        C:\Program Files (x86)\MySQL\MySQL Connector C 6.1\lib

   c) Add Linker Option:
      - Go to the Linker (or Parameters) tab
      - In the Linker Options box, add:
        -lmysql

3. Copy DLL to Project Folder
   - After compiling the project, copy:
     C:\Program Files (x86)\MySQL\MySQL Connector C 6.1\lib\libmysql.dll
   - Into your project folder (the folder containing your .exe file).


BUILD INSTRUCTIONS
------------------

- Open "Hotel Accomodation system.dev" project file in Dev-C++
- Click Execute → Compile & Run


BUG FIX NOTICE
--------------

In main.cpp, correct this issue before running:
Replace:
    if (!h.connectDB()) {
        return 1;  
    h.checkAvailableRooms();

With:
    if (!h.connectDB()) {
        return 1;
    }
    h.checkAvailableRooms();


FEATURES
--------

- Create and setup hotel room and customer tables
- Populate room data
- View available rooms
- (Future) Add reservations
- (Future) View and clear unpaid reservations


DATABASE DETAILS
----------------

Database: mydb
User: root
Password: 1234
Port: 3306

* Adjust these in Hotel::connectDB() if your database setup differs.


FILES INCLUDED
--------------

- main.cpp              - Program entry point
- hotel.cpp             - Hotel management implementation
- hotel.h               - Class definitions
- Hotel Accomodation system.dev - Dev-C++ project file
- libmysql.dll          - MySQL runtime library (copy after compiling)
- Makefile.win          - Build instructions for Dev-C++
- README.txt            - This readme file


NOTES
-----

- Ensure MySQL Server is running before executing the program.
- Use default installation paths for this setup guide to work directly.

----------------------------
End of README
----------------------------
