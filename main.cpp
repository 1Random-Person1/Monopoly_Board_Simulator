#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <bits/locale_facets_nonio.h>

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
        } else
        {
            return false;
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

        if (nodeCount == MAX_SPACES)
        {
            cout << endl << "ERROR: too many spaces" << endl; //mainly for testing
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

    // -------------------------------
    // Core B: Add Multiple Spaces at Once
    // -------------------------------

    int addMany(vector<T> values) {

        int counter = 0;

        for (int i = 0; i < values.size(); i++)
        {
            if (!addSpace(values[i]))
            {
                break;
            }

            counter++;
        }
        return counter;
    }

    // -------------------------------
    // Core C: Traversal-Based Player Movement
    // -------------------------------

    void movePlayer(int steps) {

        if (playerNode == nullptr)
        {
            return;
        }

        for (int i = 0; i < steps; i++)
        {
            if (playerNode == tailNode)
            {
                playerNode = playerNode->nextNode;
                passGoCount++;
            } else
            {
                playerNode = playerNode->nextNode;
            }

        }
    }
    int getPassGoCount() {
        return passGoCount;
    }

    // -------------------------------
    // Core D: Controlled Board Display
    // -------------------------------

    void printFromPlayer(int count) {
        // TODO:
        // - Print exactly 'count' nodes starting from playerNode
        // - Must not infinite loop
        // - Must handle empty list
        // - Output must be deterministic and readable

        for (int i = 0; i < count; i++)
        {
            cout << playerNode << endl;
        }

        cout << "printFromPlayer unwritten" << endl;
    }
    // Optional helper: print full board once (one full cycle)
    void printBoardOnce() {
        // TODO:
        // - Traverse exactly one full cycle and print each node
        cout << "printBoardOnce unwritten" << endl;
    }

};

// -------------------------------
// Main: playable loop demo
// -------------------------------
int rollDice2to12() {
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}

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
    vector<MonopolySpace> spaces;
    spaces.push_back(MonopolySpace("GO","None",0,0));
    spaces.push_back(MonopolySpace("Space2","None",0,0));
    spaces.push_back(MonopolySpace("Space3","None",0,0));
    spaces.push_back(MonopolySpace("Space4","None",0,0));
    spaces.push_back(MonopolySpace("Space5","None",0,0));
    spaces.push_back(MonopolySpace("Space6","None",0,0));
    spaces.push_back(MonopolySpace("Space7","None",0,0));
    spaces.push_back(MonopolySpace("Space8","None",0,0));
    spaces.push_back(MonopolySpace("Space9","None",0,0));
    spaces.push_back(MonopolySpace("Space10","None",0,0));

    board.addMany(spaces);
    //
    // NOTE: This starter calls addSpace once to show the intended API,
    // but your final submission should build a meaningful board.
    //board.addSpace(MonopolySpace("GO", "None", 0, 0));


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