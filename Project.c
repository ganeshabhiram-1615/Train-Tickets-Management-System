#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRAINS 10
#define MAX_BOOKINGS 50

// Structure for train details
struct Train {
    int train_no;
    char train_name[50];
    char source[50];
    char destination[50];
    int total_seats;
    int available_seats;
};

// Structure for passenger booking
struct Booking {
    int pnr;
    char passenger_name[50];
    int age;
    int train_no;
    int seats_booked;
};

// Global arrays
struct Train trains[MAX_TRAINS];
struct Booking bookings[MAX_BOOKINGS];
int train_count = 0, booking_count = 0;
int pnr_counter = 1001;

// Function declarations
void addTrain();
void viewTrains();
void bookTicket();
void viewBookings();
void searchBooking();
void cancelBooking();

int main() {
    int choice;

    printf("\n==== TRAIN TICKET BOOKING MANAGEMENT SYSTEM ====\n");

    while (1) {
        printf("\n----------- MENU -----------\n");
        printf("1. Add Train\n");
        printf("2. View All Trains\n");
        printf("3. Book Ticket\n");
        printf("4. View All Bookings\n");
        printf("5. Search Booking by PNR\n");
        printf("6. Cancel Booking\n");
        printf("7. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline

        switch (choice) {
            case 1: addTrain(); break;
            case 2: viewTrains(); break;
            case 3: bookTicket(); break;
            case 4: viewBookings(); break;
            case 5: searchBooking(); break;
            case 6: cancelBooking(); break;
            case 7:
                printf("Thank you for using the system!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to add train details
void addTrain() {
    if (train_count >= MAX_TRAINS) {
        printf("Cannot add more trains!\n");
        return;
    }

    struct Train t;
    printf("\nEnter Train Number: ");
    scanf("%d", &t.train_no);
    getchar();

    printf("Enter Train Name: ");
    fgets(t.train_name, sizeof(t.train_name), stdin);
    t.train_name[strcspn(t.train_name, "\n")] = '\0';

    printf("Enter Source Station: ");
    fgets(t.source, sizeof(t.source), stdin);
    t.source[strcspn(t.source, "\n")] = '\0';

    printf("Enter Destination Station: ");
    fgets(t.destination, sizeof(t.destination), stdin);
    t.destination[strcspn(t.destination, "\n")] = '\0';

    printf("Enter Total Seats: ");
    scanf("%d", &t.total_seats);
    t.available_seats = t.total_seats;

    trains[train_count++] = t;

    printf("Train added successfully!\n");
}

// Function to view all train details
void viewTrains() {
    if (train_count == 0) {
        printf("No trains available!\n");
        return;
    }

    printf("\n%-10s %-20s %-15s %-15s %-10s %-10s\n", 
           "Train No", "Train Name", "Source", "Destination", "Total", "Available");

    for (int i = 0; i < train_count; i++) {
        printf("%-10d %-20s %-15s %-15s %-10d %-10d\n",
               trains[i].train_no,
               trains[i].train_name,
               trains[i].source,
               trains[i].destination,
               trains[i].total_seats,
               trains[i].available_seats);
    }
}

// Function to book ticket
void bookTicket() {
    if (train_count == 0) {
        printf("No trains available for booking!\n");
        return;
    }

    int train_no, seats;
    char name[50];
    int age;

    printf("\nEnter Train Number to Book: ");
    scanf("%d", &train_no);

    // Find train
    int found = -1;
    for (int i = 0; i < train_count; i++) {
        if (trains[i].train_no == train_no) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Train not found!\n");
        return;
    }

    printf("Enter Passenger Name: ");
    getchar();
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter Passenger Age: ");
    scanf("%d", &age);

    printf("Enter number of seats to book: ");
    scanf("%d", &seats);

    if (trains[found].available_seats < seats) {
        printf("Not enough seats available!\n");
        return;
    }

    struct Booking b;
    b.pnr = pnr_counter++;
    strcpy(b.passenger_name, name);
    b.age = age;
    b.train_no = train_no;
    b.seats_booked = seats;

    bookings[booking_count++] = b;
    trains[found].available_seats -= seats;

    printf("Booking Successful! Your PNR is %d\n", b.pnr);
}

// Function to view all bookings
void viewBookings() {
    if (booking_count == 0) {
        printf("No bookings found!\n");
        return;
    }

    printf("\n%-10s %-20s %-10s %-10s %-10s\n",
           "PNR", "Passenger", "Age", "Train No", "Seats");

    for (int i = 0; i < booking_count; i++) {
        printf("%-10d %-20s %-10d %-10d %-10d\n",
               bookings[i].pnr,
               bookings[i].passenger_name,
               bookings[i].age,
               bookings[i].train_no,
               bookings[i].seats_booked);
    }
}

// Function to search booking by PNR
void searchBooking() {
    if (booking_count == 0) {
        printf("No bookings available!\n");
        return;
    }

    int pnr;
    printf("Enter PNR to search: ");
    scanf("%d", &pnr);

    for (int i = 0; i < booking_count; i++) {
        if (bookings[i].pnr == pnr) {
            printf("\nBooking Found!\n");
            printf("Passenger Name: %s\n", bookings[i].passenger_name);
            printf("Age: %d\n", bookings[i].age);
            printf("Train No: %d\n", bookings[i].train_no);
            printf("Seats Booked: %d\n", bookings[i].seats_booked);
            return;
        }
    }

    printf("Booking not found for PNR %d\n", pnr);
}

// Function to cancel booking
void cancelBooking() {
    if (booking_count == 0) {
        printf("No bookings available!\n");
        return;
    }

    int pnr;
    printf("Enter PNR to cancel: ");
    scanf("%d", &pnr);

    for (int i = 0; i < booking_count; i++) {
        if (bookings[i].pnr == pnr) {
            // Refund seats
            for (int j = 0; j < train_count; j++) {
                if (trains[j].train_no == bookings[i].train_no) {
                    trains[j].available_seats += bookings[i].seats_booked;
                    break;
                }
            }

            // Remove booking
            for (int k = i; k < booking_count - 1; k++) {
                bookings[k] = bookings[k + 1];
            }
            booking_count--;

            printf("Booking with PNR %d cancelled successfully!\n", pnr);
            return;
        }
    }

    printf("PNR not found!\n");
}
