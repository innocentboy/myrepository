/**
Given a binary tree, find the largest Binary Search Tree (BST), where largest means BST with largest number
of nodes in it. The largest BST may or may not
include all of its descendants.
*/


/***********
IMPORTANT:

    From now onwards, we use the term largest BST for largest BST which may or may not include all of its descendants,
    while largest BST subtree is for largest BST subtree which must include all of its descendants.

The example I showed in my last post was too trivial, so here I show a slightly more complicated example.

               ___________________15___________________
              /                                        \
  ___________10___________                             20
 /                        \
 5                   _____7____
                    /          \
                  __2__       __5
                 /     \     /
                 0      8    3

The largest BST (may or may not include all of its descendants) from the above example should be:

         ____15____
        /          \
      _10          20
     /
     5

while the largest BST subtree (must include all of its descendants) should be:

      __2_
     /    \
     0     8


***********/


/**
METHOD 1:
*/



/**
METHOD 2:
*/

// Find the largest BST in a binary tree.
// This code does not delete dynamically-allocated nodes,
// so memory will be leaked upon exit.
// The min and max values are passed top-down to check if
// including a node satisfies the current BST constraint.
// The child nodes are passed bottom-up to be assigned
// to its parent.
// Returns the total number of nodes the child holds.
int findLargestBST(BinaryTree *p, int min, int max, int &maxNodes,
                   BinaryTree *& largestBST, BinaryTree *& child) {
    if (!p) return 0;
    if (min < p->data && p->data < max) {
        int leftNodes = findLargestBST(p->left, min, p->data, maxNodes, largestBST, child);
        BinaryTree *leftChild = (leftNodes == 0) ? NULL : child;
        int rightNodes = findLargestBST(p->right, p->data, max, maxNodes, largestBST, child);
        BinaryTree *rightChild = (rightNodes == 0) ? NULL : child;
        // create a copy of the current node and
        // assign its left and right child.
        BinaryTree *parent = new BinaryTree(p->data);
        parent->left = leftChild;
        parent->right = rightChild;
        // pass the parent as the child to the above tree.
        child = parent;
        int totalNodes = leftNodes + rightNodes + 1;
        if (totalNodes > maxNodes) {
            maxNodes = totalNodes;
            largestBST = parent;
        }
        return totalNodes;
    } else {
        // include this node breaks the BST constraint,
        // so treat this node as an entirely new tree and
        // check if a larger BST exist in this tree
        findLargestBST(p, INT_MIN, INT_MAX, maxNodes, largestBST, child);
        // must return 0 to exclude this node
        return 0;
    }
}

BinaryTree* findLargestBST(BinaryTree *root) {
    BinaryTree *largestBST = NULL;
    BinaryTree *child;
    int maxNodes = INT_MIN;
    findLargestBST(root, INT_MIN, INT_MAX, maxNodes, largestBST, child);
    return largestBST;
}
