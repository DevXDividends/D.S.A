// TC:𝑂(𝑚×𝑛×3^𝐿) SC:O(L)
class Solution {
public:
    bool f(int row, int col, vector<vector<char>>& board, int index,
           string& word) {
        if(index == word.size())
        return true;
        if (row < 0 || col < 0 || row >= board.size() ||
            col >= board[0].size() || board[row][col] == '*' || board[row][col]!=word[index])
            return false;
        if(index == word.size()-1)
        return true;
        char temp = board[row][col];
        board[row][col] = '*';
        bool found = f(row + 1, col, board, index+1, word) ||
                     f(row - 1, col, board, index+1, word) ||
                     f(row, col + 1, board, index+1, word) ||
                     f(row, col - 1, board, index+1, word);
        board[row][col] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (f(row,col, board, 0, word))

                    return true;
            }
        }
        return false;
    }
};
