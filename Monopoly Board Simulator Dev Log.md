**\#\#\# Entry 1**  
**Date**: 2026-27-02  
**Entry Type**: Bug Fix  
**Task worked on**: Core A: Add a Space with Capacity Enforcement  
**Issue or decision**: The program provided an error message when I tried to run it using what I have created so far when using the int main provided.  
**Error message / symptom (if applicable)**: Process finished with exit code \-1073741819 (0xC0000005)  
**What I tried**: I went with the literal route and did what the TO DO said exactly for “If empty list”. Instead of setting all of the different nodes to the new node, I had them point to each other in a circular loop.  
**Fix / resolution (or final decision)**: What I did to fix this was go back to the LLTemplate that we covered a week ago, since I remembered that there was a section covering how to add to a list. The specific example I looked at was the “Insert at beginning” and saw that you would have to set the nodes as the newNode. I also moved both the nodeCount++ and return true outside of the if statement.  
**Commit(s)**: A method based on lecture notes, in which a new space is added at the end, and the tailNode pointer is repositioned to keep circularity 

**\#\#\# Entry 2**  
**Date**: 2026-28-02  
**Entry Type**: Bug Fix  
**Task worked on**: Core B: Add Multiple Spaces at Once  
**Issue or decision**: Design flaw  
**Error message / symptom (if applicable)**: N/A  
**What I tried**: Initially, when attempting this core, I tried to implement a similar system to that in Core A, but after receiving an error message and having a friend look at it, I pivoted to using a loop instead. I then tried to create a loop that iterates through the inputs and breaks when nodeCount equals the MAX\_SPACES, otherwise, it would add a new space.  
**Fix / resolution (or final decision)**: I redesigned it so now there is a counter to count how many successful spaces have been added, and the loop now relies on the addSpace method to check if the nodeCount has reached the MAX\_SPACES.  
**Commit(s)**: Had the addMany method check if it was still possible to add more spaces by using the addSpace, since it already had an if statement that compared the nodeCount to the MAX\_SPACES

**\#\#\# Entry 3**  
**Date**: 2026-03-01  
**Entry Type**: Bug Fix  
**Task worked on**: Core D and optional helper  
**Issue or decision**: Infinite loop   
**Error message / symptom (if applicable)**: The loop would run infinitely and didn’t print the data of the node  
**What I tried**: I initially followed the CS-210 reader and used the printList as an example for both Core D and printBoardOnce, which resulted in the loop running infinitely.  
**Fix / resolution (or final decision)**: I switched out the while loop for a for loop instead and switched to use a temp pointer for the headNode. I also made it so the temp would be equal to the next node, so it would no longer print the same node.   
**Commit(s)**: Shifted the type of loop that was being used and how temp was being used in the method to set the data of the node it was on

**\#\#\# Entry 4**  
**Date**: 2026-03-02  
**Entry Type**: Bug Fix and Edge Case  
**Task worked on**: Clean up  
**Issue or decision**: Non-zero exit code  
**Error message / symptom (if applicable)**: Running the program would provide a non-zero exit code  
**What I tried**: Seeing that the point of Cleanup was to delete the nodes in the linked list and that we weren’t really supposed to use the tail pointer, I went back into my lecture notes on linked list (delete from head) and the CS-210 reader (pg 50). This ended with me creating a temp pointer at the headNode and a while loop that runs until the temp pointer reaches nullptr, then moves the headNode to the nextNode while deleting the temp. This worked, but I kept getting a non-zero exit code when running the clear method and printing the board to see if it worked.   
**Fix / resolution (or final decision)**: The problem was that I didn’t include a check in the printBoardOnce method, and the reason is that the headNode was set to a nullptr, which the printBoardOnce method wasn’t set to check. I discovered this after removing board.printBoardOnce(); and just ran board.clear();, which returned a 0 for the exit code.  
**Commit(s)**: Included an if statement to check if the list is empty 

**\#\#\# Entry 5**  
**Date**: 2026-03-06  
**Entry Type**: Testing Entry  
**Task worked on**: Board Construction Phase  
**Issue or decision**: Core D: Controlled Board Display no longer works  
**Error message / symptom (if applicable)**: When running the program, instead of printing the next five spaces in front of the player’s position, it instead only printed from the start of the board.  
**What I tried**: I noticed that this problem occurred after implementing the 40 hard-coded spaces, so I first tried deleting those new spaces and reverting back to the 10 spaces I had previously. I then went on GitHub to look at my previous commits to compare it with the current version to see if there were any changes aside from the new spaces.   
**Fix / resolution (or final decision)**: In Core D, I was using a temp pointer in order for the method to work without changing the actual position of the pointer node that temp was equal to. The issue was that while using lecture notes for the Core D method, I set the temp to be the headNode instead of the playerNode, and never noticed the issue occurring until now.   
**Commit(s)**: Committed a change to what the temp pointer was equal to

**\#\#\# Entry 6**  
**Date**: 2026-03-08  
**Entry Type**: Testing  
**Task worked on**: Advanced Option B  
**Issue or decision**: I genuinely do not know what happened. While working on the Advanced Option B, I did a trial run to see what the program would do, expecting either an exit code of zero or non-zero like before, but for some reason, none of the spaces are being used for the list  
**Error message / symptom (if applicable)**: No spaces are being added to the linked list  
**What I tried**: I tried reverting back to the previous commit I made when things were working, but now, that running the program with that version of the commit no longer works. I copy and pasted the code into an online C++ compiler to run a test, and that compiler ran the program just fine.  
**Fix / resolution (or final decision)**: I copied the code into ChatGPT and it claimed that “\#include \<bits/locale\_facets\_nonio.h\> ” is what caused the issue. I proceeded to delete the line and the program ran just fine. I also added it back for testing and the program runs fine as well. Supposedly, it was a corrupted build cache issue.   
**Commit(s)**: Committed a finished Advanced Option B and kept the \#include as well