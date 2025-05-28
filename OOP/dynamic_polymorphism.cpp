#include <iostream>
using namespace std;

class Post {
public:
    virtual void display() {  
        cout << "Displaying a generic post" << endl;
    }
    virtual ~Post() {}
};

class TextPost : public Post {
public:
    void display() override {
        cout << "Displaying a text post" << endl;
    }
};

class ImagePost : public Post {
public:
    void display() override {
        cout << "Displaying an image post" << endl;
    }
};


//take decision during runtime based on the type of object
// This is an example of dynamic polymorphism using virtual functions

int main() {
    Post* post1 = new TextPost();
    Post* post2 = new ImagePost();

    post1->display();  
    post2->display();  

    delete post1;
    delete post2;
    return 0;
}
