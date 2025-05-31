
#include<iostream>
#include<string>

using namespace std;



class User{
private:
    string name;
    string email;
    string password;
public:
    User(string name, string email, string password) 
        : name(name), email(email), password(password) {}
    

        
};