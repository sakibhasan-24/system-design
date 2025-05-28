#include <iostream>
#include <string>
using namespace std;

class SportsCar {
private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
    string tyreCompany;

public:
    SportsCar(string b, string m) {
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
        tyreCompany = "MRF";
    }

    //  Getters: Safe read access
    int getSpeed() const {
        return currentSpeed;
    }

    string getTyreCompany() const {
        return tyreCompany;
    }

    //  Setter with validation (encapsulation)
    void setTyreCompany(string company) {
        if (company != "") {
            tyreCompany = company;
        }
    }

    //  No setter for speed to protect control
    //  Controlled change through methods only
    void accelerate() {
        if (!isEngineOn) {
            cout << "Engine is off! Cannot accelerate." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << ": Accelerated to " << currentSpeed << " km/h" << endl;
    }

    void brake() {
        currentSpeed -= 20;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << ": Braking to " << currentSpeed << " km/h" << endl;
    }

    void startEngine() {
        isEngineOn = true;
        cout << brand << " " << model << ": Engine started!" << endl;
    }

    void stopEngine() {
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
        cout << brand << " " << model << ": Engine stopped." << endl;
    }

    void shiftGear(int gear) {
        if (!isEngineOn) {
            cout << "Engine is off! Cannot shift gear." << endl;
            return;
        }
        currentGear = gear;
        cout << brand << " " << model << ": Shifted to gear " << gear << endl;
    }
};


int main() {
    SportsCar myCar("Ford", "Mustang");

    myCar.startEngine();
    myCar.shiftGear(1);
    myCar.accelerate();
    myCar.shiftGear(2);
    myCar.accelerate();
    myCar.brake();
    myCar.stopEngine();

    //  This would break encapsulation (uncommenting this line will result in error)
    // myCar.currentSpeed = 999;

    // ✅ Use getter to read the speed
    cout << "Current Speed: " << myCar.getSpeed() << " km/h" << endl;

    // ✅ Changing tyre brand through setter
    myCar.setTyreCompany("Michelin");
    cout << "Tyre Brand: " << myCar.getTyreCompany() << endl;

    return 0;
}
