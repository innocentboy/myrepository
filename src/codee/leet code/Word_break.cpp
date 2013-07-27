/**

Given an input string and a dictionary, determine if the string can be segmented into
 a space-separated sequence of dictionary words.

For example,

Given a standard English dictionary and the input string "codereaddiscuss",

return true because the string can be segmented into "code read discuss
*/

/**
EXPALNATION:
    One of DP solutions. Given a string s with length n. We use seg(i, j) to indicate whether
    sub-string t (starting at s[i] and length is j) can be segmented into dictionary words.

Therefore seg(i, j) = true if

1): sub-string t is a word in the dictionary;

or

2): there is a length k (1 <= k < j) such that both seg(i,k) and seg(i+k, j-k) are true.

The entire string can be segmented if seg(0, n) is true

*/

bool isSegmented(string s, unordered_set<string> &dict) {
    int len = s.length();
    if(len < 1) return false;

    bool **seg = new bool*[len];
    for(int i = 0; i < len; ++i) seg[i] = new bool[len-i];

    for(int seg_len = 1; seg_len <= len; ++seg_len) {
        for(int i = 0; i <= len-seg_len; ++i) {
            seg[i][seg_len-1] = false;
            if(dict.find(s.substr(i, seg_len)) != dict.end()) {
                seg[i][seg_len-1] = true;
                continue;
            }
            for(int j = 1; j < seg_len; ++j) {
                if(seg[i][j-1] && seg[i+j][seg_len-j-1]) {
                    seg[i][seg_len-1] = true;
                    break;
                }
            }
        }
    }

    return seg[0][len-1];
}
