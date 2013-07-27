/**

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*/
/**
METHOD 1
*/

class Solution {
    bool validate(vector<char> &num){
        vector<bool> v(10,false);
        for(int ii = 0; ii < num.size(); ++ii){
            if (num[ii] == '.') continue;
            int index = num[ii] - '0';
            if (v[index]) return false;
            else (v[index] = true);
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for(int ii = 0; ii < board.size(); ++ii){
            if (!validate(board[ii])) return false;
        }

        for(int col = 0; col < board.size(); ++col){
            vector<char> v;
            for(int row = 0; row < board.size(); ++row){
                v.push_back(board[row][col]);
            }
            if (!validate(v)) return false;
        }

        for(int start = 0; start < 3; ++start){
            for(int first = 0; first < 3; ++first){
                vector<char> block;
                for(int line = 0; line < 3; ++line){
                    for(int cell = 0; cell < 3; ++cell){
                        int row = start * 3 + line;
                        int col = first * 3 + cell;
                        block.push_back(board[row][col]);
                    }
                }
                if (!validate(block)) return false;
            }
        }
        return true;
    }
};



/**
METHOD 2:

*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<bool> > rows(9, vector<bool>(9, false));
        vector<vector<bool> > cols(9, vector<bool>(9, false));
        vector<vector<bool> > blocks(9, vector<bool>(9, false));

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int c = board[i][j] - '1';
                if (rows[i][c] || cols[j][c] || blocks[i - i % 3 + j / 3][c])
                    return false;
                rows[i][c] = cols[j][c] = blocks[i - i % 3 + j / 3][c] = true;
            }
        }
        return true;
    }
};


