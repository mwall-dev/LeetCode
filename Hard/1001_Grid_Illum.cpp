/*

    Notes: 
        - Can have a starting illuminated hashmap for rows and cols that
        we use to determine ones turned on. Then a second map for non illuminated ones
        when things change. If not in either then is off.
        - To store diagonals. Can we x+1, y+1   or x-1, y-1 until we get to an illuminated
        lamp.
        - Use a hashmap.
        
        - Note that with the queries you only turn off lamps which will then turn off lights.
        - Some lights have multiple lamps like in the example though.
    
    
    Approach:
        - Need to keep track of lamps and what cells they effect.
        - Initially we iterate through lamps.
        - For each lamp we store the row in a row hashmap and the col in a col hashmap.
          signifying these rows and cols are on.
        - For the diagonals, we store the row and col number in a diagonal_on hashmap.
        - Later to check if light shares a diagonal with this lamp it is as simple as 
        looking and the difference in each index abs(x1 - y1) == abs(x2 - y2) signifies 
        that these two points share a diagonal.
        - Also store an off hashmap for lamps that get turned off.
        
        
        Use an unordered_multiset as we could have lamps illuminating the same rows so these 
        stay lit if one of the lamps turns off. Need to use iterators to erase now though 
        as .erase(key) erases all keys of that value.
        



Need to add diagonals in both directions.
For left and down diagonals its the diff.
For right and up diagonals its the sum.


*/



class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps_vec, vector<vector<int>>& queries) {
        
        std::unordered_multiset<int> rows, cols;
        std::unordered_multiset<int> diag_diff; // For differences.
        std::unordered_multiset<int> diag_sum;
        
        std::unordered_map<int, std::unordered_set<int>> lamps; 
        // Doesn't need to be a multiset as cant have two lamps on same point.
        // Need to use string as cant use vector or pairs for keys.

        
        
        // Insert lamps into maps.
        for(const auto& lamp : lamps_vec) {
            // Avoid duplicate lamps as these screw up multisets.
            if(lamps[lamp[0]].find(lamp[1]) != lamps[lamp[0]].end()) continue;
            
            rows.insert(lamp[0]);
            cols.insert(lamp[1]);
            diag_diff.insert(lamp[0] - lamp[1]);
            diag_sum.insert(lamp[0] + lamp[1]);
            lamps[lamp[0]].insert(lamp[1]);
        }
        
        // Resultant vector
        std::vector<int> res;
        
        for(const auto& query : queries) {
            // Determine if on by looking at lamps.
            // Check rows and cols
            if(rows.find(query[0]) != rows.end() || cols.find(query[1]) != cols.end()) {
                res.push_back(1);
            }
            
            // Check diag diff
            else if(diag_diff.find(query[0] - query[1]) != diag_diff.end()) {
                res.push_back(1);
            }
            
            // Check diag sum
            else if(diag_sum.find(query[0] + query[1]) != diag_sum.end()) {
                res.push_back(1);
            }
            
            else {
                res.push_back(0);
            }


            
            // Turn off any lamp nearby. CHECK SPOT ITSELF IS A LAMP OR NOT
            int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
            int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0 ,-1};
            
            vector<std::pair<int, int>> lamps_switched;
            
            for(int i = 0; i < 9; ++i) {
                int num_erased = lamps[query[0] + dx[i]].erase(query[1] + dy[i]);
                
                if(num_erased) {
                    lamps_switched.push_back({query[0] + dx[i], query[1] + dy[i]});
                }
            }
            
            // Turn off any lights now affected by absent lamps
            for(const auto& lamp : lamps_switched) {
                // Need to use .find .erase(it) for multiset so we don't delete all identical keys.
                int lamp_x = lamp.first;
                int lamp_y = lamp.second;
                           
                // Row
                auto it_row = rows.find(lamp_x);
                if(it_row != rows.end()) rows.erase(it_row);
                
                // Col
                auto it_col = cols.find(lamp_y);
                if(it_col != cols.end()) cols.erase(it_col);
                
                // Diag diff
                auto it_diag = diag_diff.find(lamp_x - lamp_y);
                if(it_diag != diag_diff.end()) diag_diff.erase(it_diag);                                              
                // Diag sum (other direction diag)
                auto it_diag_sum = diag_sum.find(lamp_x + lamp_y);
                if(it_diag_sum != diag_sum.end()) diag_sum.erase(it_diag_sum);                                              
            }
            
        }
        
        
        
        return res;
        
    }
};
