/**
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

*/

/**
Solution:
Here is the much better solution. Instead of examining all nodes of both subtrees in each pass,
we only need to examine two nodes in each pass.

Refer back to the binary tree (1) above. As we traverse down the tree from node (10) to right node (15),
we know for sure that the right node's value fall between 10 and +INFINITY. Then, as we traverse further down from
node (15) to left node (6), we know for sure that the left node's value fall between 10 and 15. And since (6) does not
satisfy the above requirement, we can quickly determine it is not a valid BST. All we need
 to do is to pass down the low and high limits from node to node! Once we figure out this algorithm, it is easy to code.
*/

/**
METHOD 1:
*/

bool isBSTHelper(BinaryTree *p, int low, int high) {
    if (!p) return true;
    if (low < p->data && p->data < high)
        return isBSTHelper(p->left, low, p->data) &&
    isBSTHelper(p->right, p->data, high);
    else
        return false;
}

bool isBST(BinaryTree *root) {
    // INT_MIN and INT_MAX are defined in C++'s <climits> library
    return isBSTHelper(root, INT_MIN, INT_MAX);
}




/**
METHOD 2:

Alternative Solution:
Another solution is to do an in-order traversal of the binary tree, and verify that the previous value
(can be passed into the recursive function as reference) is less than the current value. This works because
when you do an in-order
traversal on a BST, the elements must be strictly in increasing order. This method also runs in O(N) time and O(1) space
*/
bool isBSTInOrderHelper(BinaryTree *p, int& prev) {
    if (!p) return true;
    return (isBSTInOrderHelper(p->left, prev) &&
            (p->data > prev) && (prev = p->data) &&
            isBSTInOrderHelper(p->right, prev));
}

bool isBSTInOrder(BinaryTree *root) {
    int prev = INT_MIN;
    return isBSTInOrderHelper(root, prev);
}

/**
EDIT: (Bug fix)
An id han6 pointed that the above code has a bug. When one of the node's value is 0, the function would return false
straight away, even though it is a valid BST. Why?

Below is the corrected code:

*/
bool isBSTInOrderHelper(BinaryTree *p, int& prev) {
    if (!p) return true;
    if (isBSTInOrderHelper(p->left, prev)) {
        if (p->data > prev) {
            prev = p->data;
            return isBSTInOrderHelper(p->right, prev);
        } else {
            return false;
        }
    }
    else {
        return false;
    }
}
bool isBSTInOrder(BinaryTree *root) {
    int prev = INT_MIN;
    return isBSTInOrderHelper(root, prev);
}

