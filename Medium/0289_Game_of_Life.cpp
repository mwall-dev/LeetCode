/*
 *  Notes:
 *      - Corners only have 3 neighbours
 *      - Edges only have 5 neighbours
 *      - Could use these to make some optimisation where we exit early based on the current state.
 *      - Make functions only look for a change.
 *
 *
 *
 *
 *  Approach :  Brute Force
 *      - Create another board and simply just iterate through the old cells checking each thing.
 *
 *  time:O(N^2)
 *  space:O(N^2)
 *
 *
 *  Approach: Bit shifting for space
 *      -To use less space we can use the 2nd bit to store the updated state and shift everything at end (since we only use one
 *      bit anyway)
 *      time:O(N^2)
 *      space:O(1)
 *
 */






class Solution {
private:
    // Neighbour coords.
    int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

    // Board dims
    int n;
    int m;


    int count_live_neighbours(const std::vector<std::vector<int>>& board, int x, int y) {
        int live_neighbours = 0;

        for(int i = 0; i < 8; ++i) {
            int x_new = x + dx[i];
            int y_new = y + dy[i];

            if(x_new >= 0 && x_new < n && y_new >= 0 && y_new < m) {
                live_neighbours += board[x_new][y_new] & 1; // Looking at the leftmost bit to get current state.
            }
        }

        return live_neighbours;

    }

public:
    void gameOfLife(vector<vector<int>>& board) {
        n = board.size();
        m = board[0].size();


        for(int x = 0; x < n; ++x) {
            for(int y = 0; y < m; ++y) {
                int neighbours = count_live_neighbours(board, x, y);

                if(!board[x][y]) {
                    if(neighbours == 3) {
                        board[x][y] = 2; // Binary 10
                    }
                }

                else {
                    if(neighbours == 2 || neighbours == 3) {
                        board[x][y] = 3; // Binary 11
                    }
                    //else board[x][y] = 1; // Binary 01 but we probably dont need this as is already 1.
                }

            }
        }

        for(int x = 0; x < n; ++x) {
            for(int y = 0; y < m; ++y) {
                board[x][y] >>= 1;
            }
        }
    }
};