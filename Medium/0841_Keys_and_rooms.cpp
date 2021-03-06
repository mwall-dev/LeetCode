/* Approach: 
    Get number of rooms from the rooms.size().
    
    Note: cant just brute force iterate through each room and check if all numbers are there
    as there might be locked off cycles between rooms that we cant enter to get the keys.
    
    Store a hashset of visited rooms. When size of this = rooms.size() then return true.
    
    Start at room 0.
    
    Add keys to the keys stack if they are for rooms not in hashset and then add to hashset.
    
    pop stack and visit room to add more keys.
    
    Just a DFS.

*/



class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        std::stack<int> keys;
        
        std::unordered_set<int> visited;
        visited.insert(0);
        keys.push(0);
                
        while(!keys.empty()){
            
            // Visit next room.
            int room = keys.top();
            keys.pop();
            
            const std::vector<int>& room_keys = rooms[room];
            // Add keys found in that room if you don't already have.
            
            for(const int& found_key : room_keys) {
                if(visited.find(found_key) == visited.end()) {
                    visited.insert(found_key);
                    keys.push(found_key);
                }
            }
            
            if(visited.size() == rooms.size()) return true;
        }
        
        return false;
    }
};