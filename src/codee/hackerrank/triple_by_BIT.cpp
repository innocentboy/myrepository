There is an integer array d which does not contain more than two elements of the same value. How many distinct ascending triples (d[i] < d[j] < d[k], i < j < k) are present?

Input format
The first line contains an integer N denoting the number of elements in the array. This is followed by a single line containing N integers separated by a single space with no leading/trailing spaces

Output format:
A single integer that denotes the number of distinct ascending triples present in the array

Constraints:
N <= 10^5
Every element of the array is present at most twice
Every element of the array is a 32-bit positive integer

Sample input:
6
1 1 2 2 3 4

Sample output:
4

Explanation:
The distinct triplets are
(1,2,3)
(1,2,4)
(1,3,4)
(2,3,4)
-------------------
Use Binary Indexed Array and Compress the data as the first step.
Detailed Solution as below
-------------------
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Arrays;


public class Solution {
int[] leftSmaller, rightLarger, treeArray, dscArray, leftFlags, rightFlags;

int arraySize, CNTKEYS = 0;

Solution(int aSize, int[] inputArray) {
arraySize = aSize;
leftSmaller = new int[arraySize];
rightLarger = new int[arraySize];
dscArray = new int[arraySize];
int[] tmpArray = Arrays.copyOf(inputArray, inputArray.length);
Arrays.sort(tmpArray);
HashMap<Integer, Integer> tmpMap = new HashMap<Integer, Integer>(
arraySize);
for (int i = 0; i < arraySize; i++) {
if (!tmpMap.containsKey(tmpArray[i])) {
CNTKEYS++;
tmpMap.put(tmpArray[i], CNTKEYS);
}
}
CNTKEYS++;
treeArray = new int[CNTKEYS];
leftFlags = new int[CNTKEYS];
rightFlags = new int[CNTKEYS];
for (int i = 0; i < arraySize; i++) {
dscArray[i] = tmpMap.get(inputArray[i]);
}

}

void update(int idx) {
while (idx < CNTKEYS) {
treeArray[idx]++;

idx += (idx & -idx);
}
}

int read(int index) {
int sum = 0;
while (index > 0) {
sum += treeArray[index];
index -= (index & -index);
}
return sum;
}
void countLeftSmaller() {
Arrays.fill(treeArray, 0);
Arrays.fill(leftSmaller, 0);
Arrays.fill(leftFlags, 0);
for (int i = 0; i < arraySize; i++) {
int val = dscArray[i];
leftSmaller[i] = read(val - 1);
if (leftFlags[val] == 0) {
update(val);
leftFlags[val] = i + 1;
} else {
leftSmaller[i] -= leftSmaller[leftFlags[val] - 1];
}
}
}

void countRightLarger() {

Arrays.fill(treeArray, 0);
Arrays.fill(rightLarger, 0);
Arrays.fill(rightFlags, 0);
for (int i = arraySize - 1; i >= 0; i--) {
int val = dscArray[i];
rightLarger[i] = read(CNTKEYS - 1)-read(val);
if (rightFlags[val] == 0) {
update(val);
rightFlags[val] = i + 1;
}
}
}

long countTripleLets() {
long sum = 0;
for (int i = 0; i < arraySize; i++) {
sum += leftSmaller[i] * rightLarger[i];
}
return sum;
}

public static void main(String[] args) throws Exception {
BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

int N = Integer.parseInt(br.readLine());
int[] a = new int[N];
String[] strs = br.readLine().split(" ");
for (int i = 0; i < N; i++)
a[i] = Integer.parseInt(strs[i]);
Solution sol = new Solution(N, a);
sol.countLeftSmaller();
sol.countRightLarger();
System.out.println(sol.countTripleLets());
}

}
