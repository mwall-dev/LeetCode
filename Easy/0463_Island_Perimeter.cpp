/*
    Approach:
        - Count number of ones. add 4 for each land and remove 2 for each internal edge.
        - Basically do a simple two cell island.
        - This would be 8 - 2 = 6. The minus 2 is to symbolise the 2 connecting edges (
        even though it looks like one).
*/


int perimeter;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count=0, repeat=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0; j<grid[i].size();j++)
                {
                    if(grid[i][j]==1)
                    {
                        count ++;
                        if(i!=0 && grid[i-1][j] == 1) repeat++;
                        if(j!=0 && grid[i][j-1] == 1) repeat++;
                    }
                }
        }
        return 4*count-repeat*2;
    }
    
};
