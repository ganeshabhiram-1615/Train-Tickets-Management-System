# Train-Tickets-Management-System
A simple C program that allows users to book, view, and cancel train tickets. It uses menus, structures, and file handling to manage passenger and train details, making it useful for learning basic C programming concepts.
Project Title:

Train Ticket Management System in C

#Functional Requirements:

1.User Registration & Login

Users can register with basic information.

Login validation before accessing the system.

2.Train Information Management

View list of available trains.

Each train has: Train No., Name, Source, Destination, Arrival Time, Departure Time, Total Seats, Fare.

3.Ticket Reservation

Select a train from the available list.

Enter passenger details.

Allocate seat(s) based on availability.

Generate a ticket ID.

4.Ticket Cancellation

Enter ticket number to cancel.

Update seat count in the train record.

5.View Booking Records

Display all booked tickets with passenger details.

6.Search Train

Search by train number or route.

7.Exit System

Close the program safely and save records (if using file handling).

#Features

~Menu-driven console interface for easy navigation.

~File handling support (optional) to store:

-Train details

-Booking history

-User database

~Error handling for invalid inputs, incorrect logins, and unavailable seats.

~Simple, modular code structure using functions like:

-addTrain(), viewTrains(), bookTicket(), cancelTicket(), searchTrain()

~Portable and lightweight—works on any system with a C compiler.

How to Run the Project
1. Requirements

C Compiler (GCC, MinGW, Turbo C, or CodeBlocks)

A terminal/IDE such as:

CodeBlocks

Visual Studio Code with C extension

Dev C++

Linux Terminal / Windows Command Prompt

2. Steps to Compile

(Using GCC as an example)

gcc train_ticket.c -o train

3. Run the Program
./train

4. If Using an IDE

Open the .c file in your IDE.

Press Build → Run.

Explanation: How This Project Works (Conceptually)

The Train Ticket Management System works as a menu-driven program in the C language. Here is how the main components function:

1. Data Structures

Most implementations use:

Structures (struct) to store train and passenger details.

Arrays or linked lists to store multiple records.

Files (.txt or .dat) to store data permanently.

Example:

struct Train {
    int train_no;
    char name[50];
    char source[50];
    char destination[50];
    int seats;
    float fare;
};

2. Menu-driven Logic

The main function usually displays a menu:

1. View Trains
2. Book Ticket
3. Cancel Ticket
4. Search Train
5. View Bookings
6. Exit


The user chooses an option → Corresponding function executes.

3. Train Display & Selection

The system first loads a list of trains (hardcoded or from a file).
Users view available trains and choose one by train number.

4. Ticket Booking Process

When the user books a ticket:

Select a train.

Enter passenger name, age, gender.

System checks if seats are available.

If yes:

Seat is allocated.

Train’s available seats decrease by 1.

A ticket ID is generated.

Ticket details are saved in a file (optional).

5. Ticket Cancellation

User enters ticket number → system:

Searches for the ticket.

Deletes the record.

Increases the train's seat count.

6. File Handling (Optional but Recommended)

To make data persistent, many projects use files such as:

trains.dat → stores train info

tickets.dat → stores bookings

This allows data to remain even after closing the program.

7. Error Handling

The system handles:

Invalid inputs

Train not found

No available seats

Wrong ticket ID during cancellation
