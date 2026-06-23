#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Device {
protected:
    int id;
    string name;
    bool status;

public:
    Device(int i, string n) {
        id = i;
        name = n;
        status = false;
    }

    virtual void display() = 0;

    void turnOn() {
        status = true;
    }

    void turnOff() {
        status = false;
    }

    virtual ~Device() {
        cout << "\nDestructor Called";
    }
};

class Light : public Device {
public:
    Light(int i, string n) : Device(i, n) {}

    void display() {
        cout << "\nLight ID: " << id;
        cout << "\nName: " << name;
        cout << "\nStatus: " << (status ? "ON" : "OFF") << endl;
    }
};

class Fan : public Device {
public:
    Fan(int i, string n) : Device(i, n) {}

    void display() {
        cout << "\nFan ID: " << id;
        cout << "\nName: " << name;
        cout << "\nStatus: " << (status ? "ON" : "OFF") << endl;
    }
};

class AC : public Device {
public:
    AC(int i, string n) : Device(i, n) {}

    void display() {
        cout << "\nAC ID: " << id;
        cout << "\nName: " << name;
        cout << "\nStatus: " << (status ? "ON" : "OFF") << endl;
    }
};

int main() {
    vector<Device*> devices;

    devices.push_back(new Light(1,"Living Room Light"));
    devices.push_back(new Fan(2,"Bedroom Fan"));
    devices.push_back(new AC(3,"Hall AC"));

    devices[0]->turnOn();
    devices[2]->turnOn();

    cout << "\nSMART HOME AUTOMATION DEVICE HUB";
    cout << "\n--------------------------------";

    for(int i=0;i<devices.size();i++)
        devices[i]->display();

    ofstream file("devices.txt");

    if(file) {
        file<<"Smart Home Device Data Saved";
        file.close();
    }

    for(int i=0;i<devices.size();i++)
        delete devices[i];

    return 0;
}
