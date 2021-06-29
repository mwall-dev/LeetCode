/*
 *
 *  Notes:
 *      - Would you ever stop early or just keep trying to amass.
 *
 *
 *
 *
 *  Approach : Brute Force
 *      - Use a recursive function to test all directions every time.
 *      - Exit if off board or 0 gold.
 *      - Copy matrix each time and keep a gold running sum.
 *
 *      This is potentially bad but we do cut off a lot of cases by exiting early.
 *      Copying matrix is expensive so do checks first before choosing to copy.
 *      time:O((MN)^2)
 *      space:O((MN)^2)
 *
 *
 *     Optimised:
 *      You dont actually need to copy!
 *      Can use same grid for a given starting point.
 *      Just be sure to zero values and put them back after (see below).
 */


class Solution {
private:
    int max_gold = 0;
    int m;
    int n;

public:
    bool is_valid_coords(int x, int y) {
        if(x < m && x >= 0 && y < n && y >= 0) {
            return true;
        }
        return false;
    }


    void explore_paths(int x, int y, int gold_accumulated , std::vector<std::vector<int>>& grid) {
        gold_accumulated += grid[x][y];
        int temp = grid[x][y]; // Store cell before clearing.
        grid[x][y] = 0; // To prevent going back.
        max_gold = std::max(max_gold, gold_accumulated);

        // Right
        if(is_valid_coords(x + 1, y) && grid[x + 1][y]) explore_paths(x + 1, y, gold_accumulated, grid);
        // Left
        if(is_valid_coords(x - 1, y) && grid[x - 1][y]) explore_paths(x - 1, y, gold_accumulated, grid);
        // Up
        if(is_valid_coords(x, y + 1) && grid[x][y + 1]) explore_paths(x, y + 1, gold_accumulated, grid);
        // Down
        if(is_valid_coords(x, y - 1) && grid[x][y - 1]) explore_paths(x, y - 1, gold_accumulated, grid);


        // Give cell its value back.
        grid[x][y] = temp;

    }

    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Try all starting points for paths.
        for(int x = 0; x < m; ++x) {
            for(int y = 0; y < n; ++y) {
                if(grid[x][y]) explore_paths(x, y, 0, grid);
            }
        }

        return max_gold;
    }
};
