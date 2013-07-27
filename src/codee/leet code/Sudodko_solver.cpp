/**
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

*/

/**
METHOD 1:
*/
vector<bool> GetValidSubSudoku(vector<vector<char> > &board, int x, int y) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<bool> sub(9, true);
    for(int i=0; i<9; ++i){
        if(board[x][i] != '.')
            sub[board[x][i]-'1'] = false;
        if(board[i][y] != '.')
            sub[board[i][y]-'1'] = false;
    }
    int rx = (x/3)*3, ry = (y/3)*3;
    for(int i=rx; i<rx+3; ++i)
        for(int j=ry; j<ry+3; ++j)
            if(board[i][j] != '.')
                sub[board[i][j]-'1'] = false;
    return sub;
}

bool solvehelper(vector<vector<char> > &board, int start){
    for(; start<81; ++start){
        int x = start/9, y = start%9;
        if(board[x][y] == '.'){
            vector<bool> sub = GetValidSubSudoku(board, x, y);
            for(int i=0; i<9; ++i){
                if(sub[i]){
                    board[x][y] = i+'1';
                    if(solvehelper(board, start+1))
                        return true;
                }
            }
            if(board[x][y] == '.')
                return false;
            else
                board[x][y] = '.';
            break;
        }
    }
    if(start >= 80){
        if(isValidSudoku(board))
            return true;
    }
    return false;
}

void solveSudoku(vector<vector<char> > &board) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    solvehelper(board, 0);
}

/**
METHOD 2:
*/
class Solution {
public:
    vector<vector<bool> > rows;
    vector<vector<bool> > cols;
    vector<vector<bool> > blocks;

    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        rows.clear();
        cols.clear();
        blocks.clear();
        rows.resize(9, vector<bool>(9, false));
        cols.resize(9, vector<bool>(9, false));
        blocks.resize(9, vector<bool>(9, false));

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c != '.') {
                    rows[i][c - '1'] = cols[j][c - '1'] = blocks[(i / 3) * 3 + j / 3][c - '1'] = true;
                }
            }
        }

        sub(board, 0);
    }

    bool sub(vector<vector<char> > &board, int index) {

        while (index < 81 && board[index / 9][index % 9] != '.')
            index++;

        if (index == 81) return true;

        int row = index / 9, col = index % 9;
        for (int i = 0; i < 9; ++i) {
            if (rows[row][i] || cols[col][i] || blocks[(row / 3) * 3 + col / 3][i]) continue;
            rows[row][i] = cols[col][i] = blocks[(row / 3) * 3 + col / 3][i] = true;
            board[row][col] = '1' + i;
            if (sub(board, index + 1))
                return true;
            board[row][col] = '.';
            rows[row][i] = cols[col][i] = blocks[(row / 3) * 3 + col / 3][i] = false;
        }

        return false;
    }
};

/**
METHOD 3:
*/

class Solution {
public:

    pair<int, int> findFirstEmpty(const vector< vector<char> >& board) {
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] == '.') return make_pair(i, j);
        return make_pair(-1, -1);
    }


    bool isValid(const vector<char>& vec) {
        vector<bool> occur(9, false);
        for (int i = 0; i < 9; ++i) {
            if (isdigit(vec[i])) {
                if (occur[vec[i]-'1']) return false;
                else occur[vec[i]-'1'] = true;
            }
        }
        return true;
    }

    bool isValidBoard(const vector< vector<char> >& board, pair<int, int> pos) {

        if (!isValid(board[pos.first])) return false;

        vector<char> column(9);
        for (int i = 0; i < 9; ++i)
            column[i] = board[i][pos.second];
        if (!isValid(column)) return false;


        int block_row = pos.first / 3;
        int block_col = pos.second / 3;
        vector<char> block;
        for (int i = block_row * 3; i < block_row * 3 + 3; ++i)
            for (int j = block_col * 3; j < block_col * 3 + 3; ++j)
                block.push_back(board[i][j]);
        if (!isValid(block)) return false;


        return true;
    }


    bool solveSudoku(vector<vector<char> >& board) {

        pair<int, int> pos = findFirstEmpty(board);
        if (pos.first == -1 && pos.second == -1)
            return true;

        for (int i = 1; i <= 9; ++i) {
            board[pos.first][pos.second] = i + '0';
            if (isValidBoard(board, pos) && solveSudoku(board))
                return true;

            board[pos.first][pos.second] = '.';
        }
        return false;
    }
};



