#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <fstream>
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
            cout << endl << "ERROR: too many spaces" << endl; //testing
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

        if (playerNode == nullptr)
        {
            return;
        }

        Node<T>* temp = playerNode;

        for (int i = 0; i < count; i++)
        {

            temp->data.print();
            temp = temp->nextNode;

        }
    }

    // Optional helper: print full board once (one full cycle)
    void printBoardOnce() {

        if (headNode == nullptr)
        {
            cout << endl;
            cout << "nothing" << endl; //testing
            return;
        }

        Node<T>* temp = headNode;

        cout << endl;

        for (int i = 0; i < nodeCount; i++)
        {
            temp->data.print();
            temp = temp->nextNode;
        }

    }

    // -------------------------------
    // Edge-case helper: countSpaces O(n)
    // -------------------------------

    int countSpaces() {
        // TODO:
        // - Must be O(n), traverse exactly once with correct stop condition
        // - Do NOT rely on nodeCount for this method

        int counter = 0;

        if (headNode == nullptr)
        {
            return 0;
        }

        tailNode->nextNode = nullptr;
        Node<T>* temp = headNode;

        while (temp != nullptr)
        {
            temp = temp->nextNode;
            counter++;
        }

        cout << endl;
        cout << "Number of spaces = " << counter << endl; //testing
        return counter;

    }

    // -------------------------------
    // Cleanup
    // -------------------------------

    void clear() {
        // TODO:
        // - Safely delete all nodes
        // - Tip: if tailNode exists, break the cycle first: tailNode->nextNode = nullptr
        // - Then delete like a normal singly linked list

        if (headNode == nullptr)
        {
            return;
        }

        if (tailNode != nullptr)
        {
            tailNode->nextNode = nullptr;
        }

        Node<T>* temp = headNode;

        while (temp != nullptr)
        {
            headNode = headNode->nextNode;
            delete temp;
            temp = headNode;
        }

        headNode = nullptr;
        tailNode = nullptr;
        playerNode = nullptr;

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
    spaces.push_back(MonopolySpace("Mediterranean Avenue","Brown",60,0));
    spaces.push_back(MonopolySpace("Community Chest","None",0,0));
    spaces.push_back(MonopolySpace("Baltic Avenue","Brown",60,0));
    spaces.push_back(MonopolySpace("Income Tax","None",0,200));
    spaces.push_back(MonopolySpace("Reading Railroad","None",200,0));
    spaces.push_back(MonopolySpace("Oriental Avenue","Light Blue",100,0));
    spaces.push_back(MonopolySpace("Chance","None",0,0));
    spaces.push_back(MonopolySpace("Vermont Avenue","Light Blue",100,0));
    spaces.push_back(MonopolySpace("Connecticut Avenue","Light Blue",120,0));
    spaces.push_back(MonopolySpace("Jail","None",0,0));
    spaces.push_back(MonopolySpace("St. Charles Place","Pink",0,0));
    spaces.push_back(MonopolySpace("Electric Company","None",150,0));
    spaces.push_back(MonopolySpace("States Avenue","Pink",140,0));
    spaces.push_back(MonopolySpace("Virginia Avenue","Pink",160,0));
    spaces.push_back(MonopolySpace("Pennsylvania Railroad","None",200,0));
    spaces.push_back(MonopolySpace("St. James Place","Orange",180,0));
    spaces.push_back(MonopolySpace("Community Chest","",0,0));
    spaces.push_back(MonopolySpace("Tennessee Avenue","Orange",180,0));
    spaces.push_back(MonopolySpace("New York Avenue","Orange",200,0));
    spaces.push_back(MonopolySpace("Free Parking","None",0,0));
    spaces.push_back(MonopolySpace("Kentucky Avenue","Red",220,0));
    spaces.push_back(MonopolySpace("Chance","None",0,0));
    spaces.push_back(MonopolySpace("Indiana Avenue","Red",220,0));
    spaces.push_back(MonopolySpace("Illinois Avenue","Red",240,0));
    spaces.push_back(MonopolySpace("B. & O. Railroad","",200,0));
    spaces.push_back(MonopolySpace("Atlantic Avenue","Yellow",260,0));
    spaces.push_back(MonopolySpace("Ventnor Avenue","Yellow",260,0));
    spaces.push_back(MonopolySpace("Water Works","None",150,0));
    spaces.push_back(MonopolySpace("Marvin Gardens","Yellow",280,0));
    spaces.push_back(MonopolySpace("Go to Jail","None",0,0));
    spaces.push_back(MonopolySpace("Pacific Avenue","Green",300,0));
    spaces.push_back(MonopolySpace("North Carolina Avenue","Green",300,0));
    spaces.push_back(MonopolySpace("Community Chest","None",0,0));
    spaces.push_back(MonopolySpace("Pennsylvania Avenue","Green",320,0));
    spaces.push_back(MonopolySpace("Short Line","None",200,0));
    spaces.push_back(MonopolySpace("Chance","None",0,0));
    spaces.push_back(MonopolySpace("Park Place","Dark Blue",0,0));
    spaces.push_back(MonopolySpace("Luxury Tax","None",0,350));
    spaces.push_back(MonopolySpace("Boardwalk","None",400,0));


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

    board.printBoardOnce();

    board.countSpaces();

    board.clear();

    board.printBoardOnce();

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