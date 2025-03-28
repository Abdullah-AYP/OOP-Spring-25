#include <iostream>
using namespace std;

class Ticket {
protected:
    int ticketID;
    string passengerName;
    float price;
    string date;
    string destination;
public:
    Ticket(int id, string n, float p, string d, string de)
        : ticketID(id), passengerName(n), price(p), date(d), destination(de) {}
    virtual void reserve() {
        cout << "Ticket reserved for " << passengerName << " on " << date << " to " << destination << "\n";
    }
    virtual void cancel() {
        cout << "Ticket " << ticketID << " canceled.\n";
    }
    virtual void displayTicketInfo() {
        cout << "Ticket ID: " << ticketID << "\nPassenger Name: " << passengerName
             << "\nPrice: " << price << "\nDate: " << date << "\nDestination: " << destination << endl;
    }
};
class FlightTicket : public Ticket {
    string airlineName;
    int flightNumber;
    string seatCategory;
public:
    FlightTicket(string a, int nu, string c, int id, string n, float p, string d, string de)
        : airlineName(a), flightNumber(nu), seatCategory(c), Ticket(id, n, p, d, de) {}
    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Airline Name: " << airlineName << "\nFlight Number: " << flightNumber << "\nSeat Class: " << seatCategory << endl;
    }
};
class TrainTicket : public Ticket {
    int trainNumber;
    string coachCategory;
    string departureTime;
public:
    TrainTicket(int t, string co, string dep, int id, string n, float p, string d, string de)
        : trainNumber(t), coachCategory(co), departureTime(dep), Ticket(id, n, p, d, de) {}
    void reserve() override {
        cout << "Train Ticket Reserved: Auto-assigning seat for " << passengerName << "\n";
    }
};
class BusTicket : public Ticket {
    string busCompany;
    int seatNumber;
public:
    BusTicket(string b, int s, int id, string n, float p, string d, string de)
        : busCompany(b), seatNumber(s), Ticket(id, n, p, d, de) {}
    void cancel() override {
        cout << "Bus Ticket " << ticketID << " canceled. Eligible for last-minute refund.\n";
    }
};
class ConcertTicket : public Ticket {
    string artistName;
    string venue;
    string seatType;
public:
    ConcertTicket(string ar, string v, string st, int id, string n, float p, string d, string de)
        : artistName(ar), venue(v), seatType(st), Ticket(id, n, p, d, de) {}
    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Artist Name: " << artistName << "\nVenue: " << venue << "\nSeat Type: " << seatType << endl;
    }
};
int main() {
    FlightTicket flight("Emirates", 69696, "Business Class", 12345, "Abdullah", 230000.0, "29-03-25", "Tokyo");
    TrainTicket train(1234, "Sleeper", "11:59 AM", 22222, "Talha", 7000.0, "29-03-25", "Karachi");
    BusTicket bus("Red Bus", 1, 33333, "Raghib", 100.0, "29-03-25", "Malir");
    ConcertTicket concert("One Direction", "Fast University", "Student", 44444, "Rafay", 6969.0, "29-03-25", "Karachi");

    flight.displayTicketInfo();
    cout << "\n";
    train.displayTicketInfo();
    cout << "\n";
    bus.displayTicketInfo();
    cout << "\n";
    concert.displayTicketInfo();
    return 0;
}
