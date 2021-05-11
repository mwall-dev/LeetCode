/*
 *
 *  Notes:
 *      - For each shift:
 *          - Each element moves over one col.
 *          - Elements in last col can't move over one col to right so they go to first col but are also pushed down
 *          one row.
 *
 *
 *
 *
 *  Approach: Brute Force Simulation:
 *      - Do k times:
 *          - Capture last col.
 *          - Shift all cols forward starting from 2nd last.
 *          - Handle stored last col and put at front.
 *
 *
 *   Approach: Optimised using modulo
 *      - Looking at each element we see that move right and eventually down in a book read like fashion.
 *      - We should look at each number and determine what rol and col it will end up in after k shift.
 *      - The column changes exactly k times. Every step it moves forward 1 column. Use modulo number of cols.
 *      - The row changes every time we wrap around. Which is the actual division then modulo number of rows.
 *
 *
 *
 *
 */


class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        std::vector<std::vector<int>> shifted_grid;

        // Construct empty new grid for result.
        for(int i = 0; i < grid.size(); ++i) {
            shifted_grid.push_back(std::vector<int>(grid[0].size()));
        }
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                int new_col = (j + k) % m;
                int new_row = (((j + k) / m) + i ) % n;

                shifted_grid[new_row][new_col] = grid[i][j];
            }
        }

        return shifted_grid;



    }


};