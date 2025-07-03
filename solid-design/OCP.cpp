/* 
--------------OCP------------------
Don't touch old code,add new code
Old tested code remain untouched
great for growing system



*/
//  --------------------------------------------------
// Step 1: Code that VIOLATES the OCP
// --------------------------------------------------


#include<iostream>
#include<string>
using namespace std;

class Disount_calculator_OCP_violation{
    public:
        double getDiscount(string userType){
            if(userType == "Student") return 0.20;
         
            else if (userType == "Teacher") return 0.10;
        
            else if (userType == "Staff") return 0.15;
        
            else if (userType == "Guest") return 0.05;
        
            else return 0.0;
        }
        // How its violates OCP
        // If we want to add a new user type like "PremiumMember",
        // we have to OPEN this class and MODIFY the if-else logic


};

// test the violation code

void testViolation(){
    cout << "🚫 OCP Violation Output:\n";

    Disount_calculator_OCP_violation calc;
    cout << "Student Discount: " << calc.getDiscount("Student") << endl;
    cout << "Teacher Discount: " << calc.getDiscount("Teacher") << endl;
    cout << "Guest Discount: " << calc.getDiscount("Guest") << endl;
    cout << "PremiumMember Discount: " << calc.getDiscount("PremiumMember") << " (Not handled)\n\n";
}


/* --------------- Now fix the issues ,we will FOLLOW OCP------------

    Instead of using "if-else" logic, we use polymorphism.
    We create an abstract base class (IUser) with a method getDiscount().
    Then for each new user type, we create a new class that EXTENDS this behavior.

    Now we don't touch old code anymore — we just ADD new classes.
 */

// Let's create the base class


    class IUser{
        public:
        virtual string getType ()=0;
        virtual double getDiscount()=0;
        virtual ~IUser() {} ;
    };

    //  Now we extend behavior without touching old classes

    class Student : public IUser{
    public:
        string getType() override { return "Student"; }
        double getDiscount() override { return 0.20; }
        
    };
    class Teacher : public IUser {
    public:
    string getType() override { return "Teacher"; }
    double getDiscount() override { return 0.10; }
    };

    class Staff : public IUser {
    public:
    string getType() override { return "Staff"; }
    double getDiscount() override { return 0.15; }
    };

    class Guest : public IUser {
    public:
    string getType() override { return "Guest"; }
    double getDiscount() override { return 0.05; }
    };

    class PremiumMember : public IUser {
    public:
    string getType() override { return "PremiumMember"; }
    double getDiscount() override { return 0.30; }
    };

    // Now we can add new user types without changing old code


    void printDiscount(IUser* user){
        cout << "Discount for " << user->getType() << " is " << user->getDiscount() << endl;
    }

    void testOCP(){
        cout << " OCP  Output:\n";

    Student s;
    Teacher t;
    Staff st;
    Guest g;
    PremiumMember pm;

    printDiscount(&s);
    printDiscount(&t);
    printDiscount(&st);
    printDiscount(&g);
    printDiscount(&pm);

    cout << "\nWe did NOT change the printDiscount() function at all!\n";
    cout << "We just extended behavior using new classes.\n";


    }


int main()



{
    testViolation();
    testOCP();
}