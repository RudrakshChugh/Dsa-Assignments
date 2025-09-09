#include <iostream>
#include <string>

using namespace std;

class Ticket {
private:
    string passengerName;
    int ticketNumber;
    double ticketPrice;
    bool isBooked;

public:
    Ticket() {
        passengerName = "";
        ticketNumber = 0;
        ticketPrice = 0.0;
        isBooked = false;
    }

    void bookTicket(string name, int number, double price) {
        if (isBooked) {
            cout << "Ticket already booked!\n";
            return;
        }
        passengerName = name;
        ticketNumber = number;
        ticketPrice = price;
        isBooked = true;
        cout << "Ticket booked successfully.\n";
    }

    void cancelTicket() {
        if (!isBooked) {
            cout << "No ticket booked to cancel.\n";
            return;
        }
        double refund = ticketPrice * 0.8;  // 80% refund
        cout << "Ticket canceled. Refund amount: $" << refund << endl;
        passengerName = "";
        ticketNumber = 0;
        ticketPrice = 0.0;
        isBooked = false;
    }

    void showDetails() {
        if (!isBooked) {
            cout << "No ticket booked.\n";
            return;
        }
        cout << "Passenger Name: " << passengerName << endl;
        cout << "Ticket Number: " << ticketNumber << endl;
        cout << "Ticket Price: $" << ticketPrice << endl;
    }

    bool booked() {
        return isBooked;
    }
};

int main() {
    Ticket myTicket;
    int choice;
    string name;
    int ticketNum;
    double price;

    while (true) {
        cout << "\n--- Plane Ticketing System ---\n";
        cout << "1. Book Ticket\n";
        cout << "2. Cancel Ticket\n";
        cout << "3. Show Ticket Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (myTicket.booked()) {
                    cout << "You already have a booked ticket.\n";
                    break;
                }
                cout << "Enter passenger name: ";
                cin.ignore();  // clear newline from input buffer
                getline(cin, name);
                cout << "Enter ticket number: ";
                cin >> ticketNum;
                cout << "Enter ticket price: ";
                cin >> price;
                myTicket.bookTicket(name, ticketNum, price);
                break;

            case 2:
                myTicket.cancelTicket();
                break;

            case 3:
                myTicket.showDetails();
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice, try again.\n";
        }
    }

    return 0;
}
