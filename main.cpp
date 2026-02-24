#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
static const int MAX_SPACES = 40;

class MonopolySpace {
public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;

    MonopolySpace() {
        propertyName = "";
        propertyColor = "";
        value = 0;
        rent = 0;
    }

    MonopolySpace(string propertyName, string propertyColor, int value, int rent) {
        this->propertyName = propertyName;
        this->propertyColor = propertyColor;
        this->value = value;
        this->rent = rent;
    }

    bool isEqual(MonopolySpace other) {
        if (propertyName == other.propertyName)
        {
            return true;
        }
    }

    void print() {
        cout << propertyName << " | " << propertyColor << " | $" << value <<
            " | $" << rent << endl;
        }
};

int main()
{
    MonopolySpace Go("Go", "Yellow", 0, 0);
    Go.print();
    MonopolySpace Space2("Mediterranean Ave", "Brown", 60, 0);
    Space2.print();
}