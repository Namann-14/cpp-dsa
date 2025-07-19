#include<iostream>
using namespace std;

class Vehicle{
    public:
        string type;
        int fuelConsumed;
        int distanceTraveled;
        Vehicle(string t, int fuel, int dist) :
        type(t), fuelConsumed(fuel), distanceTraveled(dist) {};

        virtual int fuelEfficiency(int fuelConsumed, int distanceTraveled)= 0;
        ~Vehicle(){};
};

class Car : public Vehicle{
    public: 
        Car(string t, int f, int d) : Vehicle(t,f,d){};
        int fuelEfficiency(int f, int d) override {
            return d/f;
        }
};

class Truck : public Vehicle{
    public: 
        Truck(string t, int f, int d) : Vehicle(t,f,d){};
        int fuelEfficiency(int f, int d) override {
            return d/f;
        }
};

void display(Vehicle *veh, const string &type, int fuel, int dist){
    cout << "Fuel efficiency of: " << type << veh->fuelEfficiency(fuel, dist) << endl; 
}

int main(){
    string type;
    cin >> type;
    int fuel;
    cin >> fuel;
    int dist;
    cin >> dist;

    Vehicle *veh = nullptr;
    if (type == "Car"){
        veh = new Car(type, fuel, dist);
    }else{
        veh = new Truck(type, fuel, dist);
    }
    display(veh, type, fuel, dist);
    delete veh;
    
    return 0;
}