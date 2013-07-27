/**
Insert into a Cyclic Sorted List

PROBLEM:
    Given a node from a cyclic linked list which has been sorted, write a function to insert a value into
    the list such that it remains a cyclic sorted list.
    The given node can be any single node in the list.

*/

/**
SOLUTION:
    Solution:
Basically, you would have a loop that traverse the cyclic sorted list and find the point where you insert the
value (Let’s assume the value being inserted called x). You would only need to consider the following three cases:

    prev→val ≤ x ≤ current→val:

        Insert between prev and current.

    x is the maximum or minimum value in the list:

        Insert before the head. (ie, the head has the smallest value and its prev→val > head→val.

    Traverses back to the starting point:

        Insert before the starting point.
*/

void insert(Node *& aNode, int x) {
  if (!aNode) {
    aNode = new Node(x);
    aNode->next = aNode;
    return;
  }

  Node *p = aNode;
  Node *prev = NULL;
  do {
    prev = p;
    p = p->next;
    if (x <= p->data && x >= prev->data) break;   // For case 1)
    if ((prev->data > p->data) && (x < p->data || x > prev->data)) break; // For case 2)
  } while (p != aNode);   // when back to starting point, then stop. For case 3)

  Node *newNode = new Node(x);
  newNode->next = p;
  prev->next = newNode;
}
