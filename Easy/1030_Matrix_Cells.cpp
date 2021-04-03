/*
    Approach:
        Closest cells are the ones touch it and distances grow as you move out.
        Its essentailly a BFS.
        
        Can start from cell and work outwards.
        
        Note that cell distance, is actaully just steps away from the starting spot (not including diagonal steps, so diagonal 
        is 2 steps).
        So we can just work our way outwards and count how far out we have gone.
        
        BFS and hashmap to store visited.
        For each node look left, right, up, down and enquue it.
        
        Still O(N^2) but is now less time really due to no need for sort.
        

    Approach Brute Force:
        Iterate through all cells and compute distance and put in map with key, val = distance, point.
        Then iterate through map and put cells in vector.
        Return vector.
        
    time: O(N2LOGN) 
    but some bad memory requirements and all round bad.
    
    

*/

class Solution {
    public:
        vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
            
            std::vector<std::vector<bool>> visited(R, std::vector<bool>(C));
            
            std::queue<std::pair<int, int>> coord_queue;
            coord_queue.push({r0, c0});

            std::vector<std::vector<int>> result;
            
            while(!coord_queue.empty()) {
                
                auto [x, y] = coord_queue.front();
                coord_queue.pop();
                if(x >= R || x < 0 || y < 0 || y >= C) continue;
                if(visited[x][y]) continue;
                
                
                result.push_back({x,y});
                visited[x][y] = true;
                    
                coord_queue.push({x + 1, y});
                coord_queue.push({x, y + 1});
                coord_queue.push({x - 1, y});
                coord_queue.push({x, y - 1});

            }
            
            return result;                 
    }
};


// APPROACH 1: Brute Force.
/*
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        std::multimap<int, std::vector<int>> points_sorted_by_distance;
        
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                points_sorted_by_distance.insert({std::abs(i - r0) + std::abs(j - c0), {i,j}});
                std::cout << i << " " << j << std::endl;
            }
        }
        
        std::vector<vector<int>> cells_sorted_by_distance;
        for(auto it = points_sorted_by_distance.begin(); it != points_sorted_by_distance.end(); ++it) {
            cells_sorted_by_distance.push_back(it->second);
            std::cout << it->first << " ";
        }
        
        return cells_sorted_by_distance;
    }
};

*/
