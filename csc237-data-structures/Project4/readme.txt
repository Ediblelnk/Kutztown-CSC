LINK TO DOXYGEN DOCUMENTATION: https://acad.kutztown.edu/~pscha710/csc237/Project4/html/

I encountered very little friction in completing this assignment.

I chose to modify the TreeNode class, and added a "count" integer variable to store the number of times a value was "in" the binary tree.

I modified the "insertToTree" method, specifically when it finds a value that is already in the tree. Before the function simply returns a value of 0, it increments the count of the node which value matched what was supposed to be inserted into the binary tree. This keeps track of adding multiples of values in a very efficient manner.

I modified the "treeSearch" method, and made it return the count of the value that it finds in the tree, or zero if the value is not in the tree. This way allowed me to correctly structure my Treetest.cpp driver program while still keeping my BinarySearchTree unspecialized for this program.

I added a new method, called "decrementFromTree". The function finds the node holding a value in the binary tree and decrements the count of that value by 1. The preconditions for this function is that the value is definitely in the tree, and the count of the value is at least 2.

Finally for the BinarySearchTree, I modified the print functions so that when a node prints, if it has a count of greater than one, it also prints in parenthesis how many counts of that value are being stored in the list.

I made a only a couple modifications to Treetest.cpp. First, I expanded the case structure of the "removeFromTree" function, to include cases where count of the value being removed was greater than 1. In such a case, the function jumps into a helper function, which will prompt the user whether he or she wants to remove just one count of the value from the binary tree, or if they want to remove all counts of the value from the binary tree.

-----------------------------------------------------------------------------------------------------------------------------

Bug report:
  only one bug that needed to be fixed. I need to modify a special case of the deleteFromTree method of the BinarySearchTree. When the value is copied over when there are two subtrees of a node that needs to be deleted, I also needed to copy of the count of the node being copied over.