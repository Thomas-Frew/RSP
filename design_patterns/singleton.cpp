#include <iostream>
using namespace std;

class Singleton {
    private:
        static Singleton* instance;     // We store a single, static instance of our singleton
        Singleton() {};                    // Constructor is private to prevent instancing

    public:
        /* Static access method. */
        static Singleton* getInstance() {
            if (instance == 0)
            {
                instance = new Singleton();
            }

            return instance;
        }
};

Singleton* Singleton::instance = 0;

int main() {
    Singleton* sing1 = Singleton::getInstance(); // Original singleton is created
    Singleton* sing2 = Singleton::getInstance(); // New singleton is made

    // The addresses of our singletons will be the same
    cout << sing1 << endl;
    cout << sing2 << endl;
}