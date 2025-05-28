#include <iostream>
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
    double add(double a, double b) {
        return a + b;
    }
};



//take decision during compile time based on the type of arguments passed
// This is an example of static polymorphism using function overloading
int main() {
    Calculator calc;
    cout << "Add ints: " << calc.add(3, 4) << endl;       
    cout << "Add doubles: " << calc.add(3.5, 4.5) << endl; 
    return 0;
}
