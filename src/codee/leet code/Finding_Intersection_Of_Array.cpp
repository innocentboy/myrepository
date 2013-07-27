/**

Find the intersection of two sorted arrays
*/


/**
IDEA:

    Let's called array1 as A and array2 as B, each with size m and n.

The obvious brute-force solution is to scan through each element in A, and for each element in A,
scan if that element exist in B. The running time complexity is O(m*n). Not good! Can we do better? Absolutely!

First, we know that both arrays are sorted. Can we somehow use this information to our advantage?

We can apply binary search to search if an element of A exist in B. So, the only modification from the brute-force
approach is modifying linear search to binary search. This seems like a good improvement, we manage to reduce the
complexity to O(m*lg(n)).

Of course, you know you can trade space for running time by using a hash table. Is it really useful? We can definitely
hash each element in B to an array index (takes O(n) time). Therefore, to find if an element of A exist in B, it would
require just O(1) time. The complexity improves to O(m+n).

But there is a problem, what if n is very big? (ie, n is one billion!). We have a problem here. The hash table will
either requires a large amount of memory space, or there will be lots of collision in the table, which makes access time
no longer O(1) time. Therefore, using a hash table is not a good
general solution to this problem. Besides, using hash table DO NOT require that the array being sorted in the first place.

Here is the most important observation in order to solve this problem. Both arrays ARE sorted. This provides a very
important clue. We must make full use of this information that they ARE in fact sorted.

We can have two index, which both starts at zero. Compare the two first elements of A and B. If A[0] is greater than B[0],
we increase index of B by one. If B[0] is greater than A[0], we increase index of A by one. If they are equal, we know an
intersection has occurred, so add it to the list and increment index of A and B by one. Once either index reaches the end
of A or B, we have found all the intersections of A and B.

The complexity of this approach is still O(m+n), but it does not requires any extra space that a hash table requires. The
complexity is O(m+n) because in the worse case, there would be no intersection between the two arrays, and we need to
increment first index a total of m times and increment second index a total of n times, which is a total of m+n times.
*/


vector<int> findIntersection(vector<int> A, vector<int> B) {
    vector<int> intersection;
    int n1 = A.size();
    int n2 = B.size();
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (A[i] > B[j]) {
            j++;
        } else if (B[j] > A[i]) {
            i++;
        } else {
            intersection.push_back(A[i]);
            i++;
            j++;
        }
    }
    return intersection;
}


