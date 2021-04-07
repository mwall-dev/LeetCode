/* 

    Approach : Brute Force
        - Iterate through array for first best then second best... storing indicies as you go.
        - Then just build string vector.
    
    time:O(N^2)
    space:O(N)
    
    Note: can't sort vector as need indicies 
    Approach : Optimised
        - Iterate through and build a std::map with scores as keys and index as val (as scores are unique and will make godo keys + std::map sorts).
        - Iterate through map and build vector
        
    time: O(NlogN)
    space: O(N)
    
    
    
    
    
*/


class Solution {
public:
    
    std::string build_rank(int rank) {
        switch(rank) {
            case 1:
                return "Gold Medal";
            case 2:
                return "Silver Medal";
            case 3:
                return "Bronze Medal";

            default: 
                return std::to_string(rank);            
    }
    }
        
        
        
    vector<string> findRelativeRanks(vector<int>& score) {
        std::map<int, int> score_index_map;
        
        for(int i = 0; i < score.size(); ++i) {
            score_index_map[score[i]] = i;
        }
        
        std::vector<std::string> result(score.size());
        
        int rank = 1;
        for(auto it = score_index_map.rbegin(); it != score_index_map.rend(); ++it) {
            int index = it->second;
            result[index] = build_rank(rank++);
        }
        
        return result;
    }
    
};
