/**
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent"
cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false
*/
class Solution {
    vector<vector<char> >* b;
    string* s;
    vector<vector<bool> > visit;
    int southBound, eastBound;//northBound  and westBound are 0
    int maxIndex;
    bool check(int x, int y, int nn){
            //(x,y) on board, string nn index
        if (x < 0 || x > eastBound || y < 0 || y > southBound) return false;
        if (visit[y][x]) return false;
        if ((*b)[y][x] != (*s)[nn]) return false;
        //matched
        if (nn == maxIndex) return true;
        visit[y][x] = true;
        bool flag = check(x+1,y,nn+1)||check(x,y+1,nn+1)||check(x-1,y,nn+1)||check(x,y-1,nn+1);
        visit[y][x] = false;
        return flag;
    }

public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        b = &board;
        s = &word;
        if (b->empty()) return false;
        southBound = b->size()-1;
        if ((*b)[0].empty()) return false;
        eastBound = (*b)[0].size()-1;
        maxIndex = word.length() -1;
        visit.assign(b->size(), vector<bool>((*b)[0].size(), false));

        for(int ii = 0; ii <= southBound; ++ii){
            for(int jj = 0; jj <= eastBound; ++jj){
                bool flag = check(jj,ii,0);
                if (flag) return true;
            }
        }
        return false;
    }
};

