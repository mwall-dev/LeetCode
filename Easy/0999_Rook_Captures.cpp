class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rook_x;
        int rook_y;
        
        // Find rook position
        for(int i = 0; i < 8; ++i) {
            for(int j = 0; j < 8; ++j) {
                if(board[i][j] == 'R') {
                    rook_x = i;
                    rook_y = j;
                    break;
                }
            }
        }
        
        
        
        int pawns_cap = 0;
        
        // Up
        for(int i = rook_x; i >= 0; --i) {
            if(board[i][rook_y] == 'p')  {
                ++pawns_cap;
                break;
            }
            if(board[i][rook_y] == 'B') break;
        }
            
            
        // Down
        for(int i = rook_x; i < 8; ++i) {
            if(board[i][rook_y] == 'p')  {
                ++pawns_cap;
                break;
            }
            if(board[i][rook_y] == 'B') break;
        }
            
            
        // Left 
        for(int j = rook_y; j >= 0; --j) {
            if(board[rook_x][j] == 'p')  {
                ++pawns_cap;
                break;
            }
            if(board[rook_x][j] == 'B') break;
        }
            
            
        //Right 
        for(int j = rook_y; j < 8; ++j) {
            if(board[rook_x][j] == 'p')  {
                ++pawns_cap;
                break;
            }
            if(board[rook_x][j] == 'B') break;
        }
        
        return pawns_cap;
        
    }
};



// More consise

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x0 = 0, y0 = 0, res = 0;
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                if (board[i][j] == 'R') {
                    x0 = i;
                    y0 = j;
                    break;
                }
        vector<vector<int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (const auto& d : direction) {
            for (int x = x0 + d[0], y = y0 + d[1]; 0 <= x && x < 8 && 0 <= y && y < 8; x += d[0], y += d[1]) {
                if (board[x][y] == 'p') res++;
                if (board[x][y] != '.') break;
            }
        }
        return res;
    }
};