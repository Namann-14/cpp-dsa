#include <iostream>
#include <string>
using namespace std;
// Base class Transportation
class Transportation {
protected:
    int passengers;
    double distance;
    double baseFarePerPassenger;
public:
    Transportation(int p = 0, double d = 0.0) : passengers(p), distance(d), baseFarePerPassenger(10.0) {}
    // Function to calculate base fare (Overloaded function)
    double calculateCost() {
        return passengers * baseFarePerPassenger;
    }
    // Overloaded function for calculating total fare based on distance
    virtual double calculateCost(double distance) {
        return passengers * baseFarePerPassenger + distance * 20; // Default vehicle cost per km
    }
    // Virtual function for overriding in derived classes
    virtual double calculateTotalCost() {
        return calculateCost(distance);
    }
    virtual ~Transportation() {}
};
// Derived class Bus
class Bus : public Transportation {
public:
    Bus(int p, double d) : Transportation(p, d) {}
    // Override the cost calculation for Bus
    double calculateTotalCost() override {
        double costPerKm = 50; // Bus-specific cost
        return passengers * baseFarePerPassenger + distance * costPerKm;
    }
};
// Derived class Van
class Van : public Transportation {
public:
    Van(int p, double d) : Transportation(p, d) {}
    // Override the cost calculation for Van
    double calculateTotalCost() override {
        double costPerKm = 30; // Van-specific cost
        return passengers * baseFarePerPassenger + distance * costPerKm;
    }
};
// Derived class Car
class Car : public Transportation {
public:
    Car(int p, double d) : Transportation(p, d) {}
    // Override the cost calculation for Car
    double calculateTotalCost() override {
        double costPerKm = 20; // Car-specific cost
        return passengers * baseFarePerPassenger + distance * costPerKm;
    }
};
int main() {
    string vehicleType;
    int passengers;
    double distance;
    cout << "Enter the vehicle type (Bus/Van/Car): ";
    cin >> vehicleType;
    cout << "Enter the number of passengers: ";
    cin >> passengers;
    cout << "Enter the distance in kilometers: ";
    cin >> distance;
    Transportation *transport;
    // Create appropriate object based on vehicle type
    if (vehicleType == "Bus") {
        transport = new Bus(passengers, distance);
    } else if (vehicleType == "Van") {
        transport = new Van(passengers, distance);
    } else if (vehicleType == "Car") {
        transport = new Car(passengers, distance);
    } else {
        cout << "Invalid vehicle type!" << endl;
        return 1;
    }
    // Output the total cost
    cout << "Total cost for " << vehicleType << " transportation: " << transport->calculateTotalCost() << " INR" << endl;
    // Cleanup
    delete transport;
        return 0;
}
