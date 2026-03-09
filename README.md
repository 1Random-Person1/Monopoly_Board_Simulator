# CS210 Programming Assignment
## Monopoly Board Simulator (Spring 2026)

---

## How to Build and Run
# Build
- `g++ -std=c++17 main.cpp -o monopoly_board`
# Run
- `./monopoly_board`
  
---

## Data Structures Used

# MonopolySpace
A class that stoes the values of the spaces

# Template Node
Allows for the creation of a template with the type T and nodes that stores data and a pointer

# Circular Linked Lists
A linked list in which the tailNode points back towards the headNode, allowing for a circular loop to be formed

---

Note = The max capacity for this is MAX_SPACES = 40, meaning that both addSpace and addMany won't increase the 
number of spaces if this has been reached, even if the user inputs more than 40 spaces.

## Functions

**Function:** `addSpace(...)`
**Description:** Adds a new node to the tail, maintains circular structure,
enforces max size 40, returns success/failure beyond capacity.

**Function:** `addMany(...)`
**Description:** Adds spaces sequentially, stops exactly at capacity, returns how
many were added, and does not corrupt pointers. 

**Function:** `movePlayer(int n)`
**Description:** Moves a player cursor forward by `n` steps node-by-node, wraps
around, and tracks how many times the player passes GO.

**Function:** `printFromPlayer(int count)`
**Description:** Prints a fixed number of spaces starting from the player (or a
starting point if you design it that way) with a safe stop condition (no infinite
loops).

**Function:** `printBoardOnce()`
**Description:** Prints the entire board once starting at the headNode, relies on a 
loop using the nodeCount to print the exact number of nodes in the list.

**Function:** `mirrorBoard()`
**Description:** Prints a mirror/reversal of the entire board, loops until the nodeCount
has been reached, reverses the next links of all the nodes, makes the headNode and the 
tailNode switch values, and maintains circularity.

**Function:** `countSpaces()`
**Description:** Breaks the circular linked list, loops until the temp pointer reaches the 
end of the linked list by checking if it's a nullptr, and adds the number of spaces the temp passed.

**Function:** `clear()`
**Description:** Breaks the circular linked list, starting at the headNode it interates up and deletes
the node.

---

## Traversal and Movement logic

In this, the movement of the playerNode is determined by a dice roll, ranigng from 2-12. The movement is solely relying 
on pointers to move from one node/space to the next. Using the given number rolled/steps from the dice, the playerNode
could move to the next node until the loop has reached the number of steps. If the playerNode equals to the tailNode at
any point, this is seen as the player moving passed GO, as such, a counter is increased to track how many times this has occured. 
