
/*
    Bottom face: Always n*n
    Top face: Always n*n
             
    Better approach:
    Ignoring how parts cut each other out, each tower has surface area (4 * v) + 2
    However 2 adjacent towers will hide the area of the connected part.
    The hidden part is min(v1,v2) and we jsut need to minus this area * 2


    Shown below if grid[i][j] = 0 then is tower of 0 and will do nothing
    if(i) and if(j) are smart as they skip over when indicies are 0 and we are looking left and up
    each time but heading down and right so we never double up or miss.


*/



#include <vector>

using namespace std;


class Solution {
public:
       int surfaceArea(vector<vector<int>> grid) {
        int res = 0, n = grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) res += grid[i][j] * 4 + 2;
                if (i) res -= min(grid[i][j], grid[i - 1][j]) * 2;
                if (j) res -= min(grid[i][j], grid[i][j - 1]) * 2;
            }
        }
        return res;
    }
};