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

// -------------------------------
// Template Node class (NOT a struct)
// -------------------------------
template <typename T>
class Node {
public:
    T data;
    Node<T>* nextNode;
    Node(T value) {
        data = value;
        nextNode = nullptr;
    }
};

// -------------------------------
// Template Circular Linked List class
// Spring 2026 version: traversable board
// -------------------------------

template <typename T>
class CircularLinkedList
{
private:
    Node<T>* headNode;
    Node<T>* tailNode;
    // player cursor for traversal-based gameplay
    Node<T>* playerNode;
    int nodeCount;
    int passGoCount;

public:
    CircularLinkedList() {
        headNode = nullptr;
        tailNode = nullptr;
        playerNode = nullptr;
        nodeCount = 0;
        passGoCount = 0;
    }

    // -------------------------------
    // Board Construction Policy (Reminder)
    // -------------------------------
    // Spaces are added during board construction BEFORE gameplay.
    // You choose how to construct the board:
    // - hardcode spaces, read from file, or generate programmatically
    // The only non-negotiable requirement:
    // - enforce MAX_SPACES
    // - maintain circular integrity
    // -------------------------------
    // -------------------------------
    // Core A: Add a Space with Capacity Enforcement
    // -------------------------------

    bool addSpace(T value) {
        // TODO:
        // - If nodeCount == MAX_SPACES return false (do not corrupt list)
        // - Create new node
        // - If empty list: head=tail=player=new, new->next=head
        // - Else: tail->next=new, tail=new, tail->next=head
        // - nodeCount++

        if (nodeCount == MAX_SPACES)
        {
            return false;
        }

        Node<T>* newNode = new Node<T>(value);

        if (headNode == nullptr)
        {
            headNode = newNode;
            tailNode = newNode;
            playerNode = newNode;
            newNode->nextNode = headNode;
        } else {
            tailNode->nextNode = newNode;
            tailNode = newNode;
            tailNode->nextNode = headNode;
        }
        nodeCount++;
        return true;
    }
};

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    CircularLinkedList<MonopolySpace> board;
    // -------------------------------
    // Board Construction Phase
    // -------------------------------
    // You decide how to build the board:
    // - hardcode spaces, load from file, or generate spaces programmatically
    // The only requirement: never exceed MAX_SPACES and keep the list circular.
    //
    // Example (hardcoded) usage:
    // vector<MonopolySpace> spaces;
    // spaces.push_back(MonopolySpace("GO","None",0,0));
    // ...
    // board.addMany(spaces);
    //
    // NOTE: This starter calls addSpace once to show the intended API,
    // but your final submission should build a meaningful board.
    board.addSpace(MonopolySpace("GO", "None", 0, 0));

    /*
    // -------------------------------
    // Playable Traversal Loop
    // -------------------------------
    for (int turn = 1; turn <= 10; turn++) {
        int roll = rollDice2to12();
        cout << "\nTurn " << turn << " | Rolled: " << roll << endl;
        board.movePlayer(roll);
        cout << "Board view from player (next 5 spaces):" << endl;
        board.printFromPlayer(5);
        cout << "Times passed GO so far: " << board.getPassGoCount() << endl;
    }
    */

    // -------------------------------
    // Advanced Feature Demos (students choose path)
    // -------------------------------
    // Option A examples:
    // board.removeByName("Baltic Avenue");
    // vector<string> brownProps = board.findByColor("Brown");
    //
    // Option B example:
    // board.mirrorBoard();
    return 0;
}