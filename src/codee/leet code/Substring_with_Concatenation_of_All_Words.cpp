/**
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of
substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/



/**
METHOD 1: BRUTE FORCE.
*/
public ArrayList<integer> findSubstring(String S, String[] L) {
int len =  L[0].length();

    int count = L.length;

    HashMap<String, Integer> words = new HashMap<String, Integer> ();

    for ( String s:L ) {
        if ( words.containsKey( s ) ){
            words.put( s, 1+words.get(s) );
        } else {
            words.put( s, 1 );
        }
    }
    ArrayList<Integer> rv = new ArrayList<Integer>();

    int slen = S.length();

    for ( int i=0; i<=slen-count*len;  ) {

        HashMap<String, Integer> targets = new HashMap<String, Integer>  (words);
        int forward = i;
        while ( true ) {
            String sub = S.substring( forward, forward+len);
            if ( targets.containsKey ( sub ) ) {
                if (targets.get(sub) == 1 ) {
                    targets.remove ( sub ) ;
                } else {
                    targets.put ( sub, targets.get (sub)-1 ) ;
                }
                if ( targets.isEmpty() ) {
                    rv.add ( i );
                    break;
                }
                forward += len;
            } else {
                break;
            }
        }
        i++;
    }
    return rv;
}




/**
METHOD 2: OPTIMITIZED.

A brutal force solution is to check all substrings and the time complexity is O((M - N) * N), letting M be length of
S and N be length of L. There is also another solution of O(M), based on the approach described in
http://discuss.leetcode.com/questions/97/minimum-window-substring.

*/
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = S.size(), n = L.size(), len = L[0].size();
        map<string, int> ids;

        vector<int> need(n, 0);
        for (int i = 0; i < n; ++i) {
            if (!ids.count(L[i])) ids[L[i]] = i;
            need[ids[L[i]]]++;
        }

        vector<int> s(m, -1);
        for (int i = 0; i < m - len + 1; ++i) {
            string key = S.substr(i, len);
            s[i] = ids.count(key) ? ids[key] : -1;
        }

        vector<int> ret;
        for (int offset = 0; offset < len; ++offset) {
            vector<int> found(n, 0);
            int count = 0, begin = offset;
            for (int i = offset; i < m - len + 1; i += len) {
                if (s[i] < 0) {
                    // recount
                    begin = i + len;
                    count = 0;
                    found.clear();
                    found.resize(n, 0);
                } else {
                    int id = s[i];
                    found[id]++;
                    if (need[id] && found[id] <= need[id])
                        count++;

                    if (count == n)
                        ret.push_back(begin);

                    // move current window
                    if ((i - begin) / len + 1 == n) {
                        id = s[begin];
                        if (need[id] && found[id] == need[id])
                            count--;
                        found[id]--;
                        begin += len;
                    }
                }
            }
        }
        return ret;
    }
};


