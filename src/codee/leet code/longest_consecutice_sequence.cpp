/**
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity
*/


int longestConsecutiveSeq(vector<int> A) {
    if(A.empty()) return 0;
    unordered_map<int, int> map;

    vector<int>::iterator it = A.begin();
    for(; it != A.end(); ++it) map[*it] = 0;

    int max = 0;
    for(it = A.begin(); it != A.end(); ++it) {
        if(map[*it] == 0) {
            int c = 0, num = *it + 1;
            while(map.find(num) != map.end() && map[num] == 0) {
                ++c;
                map[num++] = -1;
            }
            map[*it] = map.find(num) == map.end() ? c : c+map[num]+1;
            if(map[*it] > max) max = map[*it];
        }
    }

    return max+1;
}
