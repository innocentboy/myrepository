/**
Given two sorted arrays A, B of size m and n respectively. Find the k-th smallest element in the union of A and B.
You can assume that there are no  duplicate elements.

*/

/**
The best solution, but non-trivial, O(lg m + lg n):
Although the above solution is an improvement both in run time and space complexity, it only works well for small values of
k, and thus is still in linear run time. Could we improve the run time further?

The above logarithmic complexity gives us one important hint. Binary search is a great example of achieving logarithmic
complexity by halving its search space in each iteration. Therefore, to achieve the complexity of O(lg m  + lg n), we must
halved the search space of A and B in each iteration.

We try to approach this tricky problem by comparing middle elements of A and B, which we identify as Ai and Bj. If Ai is
between Bj and Bj-1, we have just found the i + j< + 1 smallest element. Why? Therefore, if we choose i and j such that
i + j = k - 1, we are able to find the k-th smallest element. This is an important invariant that we must maintain for the
correctness of this algorithm.

Summarizing the above,
Maintaining the invariant
    i + j = k - 1,

    If Bj-1 < Ai < Bj, then Ai must be the k-th smallest,
or else if Ai-1 < Bj < Ai, then Bj must be the k-th smallest.

If one of the above conditions are satisfied, we are done. If not, we will use i and j as the pivot index to subdivide
the arrays. But how? Which portion should we discard? How about Ai and Bj itself?

We make an observation that when Ai < Bj, then it must be true that Ai < Bj-1. On the other hand, if Bj < Ai, then Bj < Ai-1
. Why?

Using the above relationship, it becomes clear that when Ai < Bj, Ai and its lower portion could never be the k-th smallest
element. So do Bj and its upper portion. Therefore, we could conveniently discard Ai with its lower portion and Bj with its
upper portion.

If you are still not convince why the above argument is true, try drawing blocks representing elements in A and B.
Try visualize inserting blocks of A up to Ai in front of Bj-1. You could easily see that no elements in the inserted blocks
would ever be the k-th smallest. For the latter, you might want to keep the invariant i + j = k - 1 in mind to reason why
Bj and its upper portion could never be the k-th smallest.

On the other hand, the case for Ai > Bj is just the other way around. Easy.

Below is the code and I have inserted lots of assertion (highly recommended programming style by the way) to help you
understand the code. Note that the below code is an example of tail recursion, so you could technically convert it to an
iterative method in a straightforward manner. However, I would leave it as it is, since this is how I derive the solution
and it seemed more natural to be expressed in a recursive manner.

Another side note is regarding the choices of i and j. The below code would subdivide both arrays using its array sizes as
weights. The reason is it might be able to guess the k-th element quicker (as long as the A and B is not differed in an
extreme way; ie, all elements in A are smaller than B). If you are wondering, yes, you could choose i to be A's middle.
In theory, you could choose any values for i and j as long as the invariant i+j = k-1
is satisfied.
*/


int findKthSmallest(int A[], int m, int B[], int n, int k) {
    assert(m >= 0); assert(n >= 0); assert(k > 0); assert(k <= m+n);

    int i = (int)((double)m / (m+n) * (k-1));
    int j = (k-1) - i;

    assert(i >= 0); assert(j >= 0); assert(i <= m); assert(j <= n);
    // invariant: i + j = k-1
    // Note: A[-1] = -INF and A[m] = +INF to maintain invariant
    int Ai_1 = ((i == 0) ? INT_MIN : A[i-1]);
    int Bj_1 = ((j == 0) ? INT_MIN : B[j-1]);
    int Ai   = ((i == m) ? INT_MAX : A[i]);
    int Bj   = ((j == n) ? INT_MAX : B[j]);

    if (Bj_1 < Ai && Ai < Bj)
        return Ai;
    else if (Ai_1 < Bj && Bj < Ai)
        return Bj;

    assert((Ai > Bj && Ai_1 > Bj) ||
           (Ai < Bj && Ai < Bj_1));

    // if none of the cases above, then it is either:
    if (Ai < Bj)
        // exclude Ai and below portion
        // exclude Bj and above portion
        return findKthSmallest(A+i+1, m-i-1, B, j, k-i-1);
    else /* Bj < Ai */
        // exclude Ai and above portion
        // exclude Bj and below portion
        return findKthSmallest(A, i, B+j+1, n-j-1, k-j-1);
}
