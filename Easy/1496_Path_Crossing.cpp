/*
 *  Notes:
 *      Ways to cross:
 *          N -> S
 *          S -> N
 *          E -> W
 *          W -> E
 *
 *          ...'
 *          ...
 *
 *          Too many ways to cross.
 *          Need to store coords.
 *
 *          Use a hashtable
 *          N = +1y
 *          S = -1y
 *          E = +1x
 *          W = -1x
 *
 *
 *  Need to use strings to store in hash data structures as pair does have a hash function.
 *
 *  Approach:
 *     - For each move:
 *          Calculate location and check if visited in hashmap.
 *          If visited than early return.
 *          Else store coord in hashset
 *
 *
 *
 */

class Solution {
public:
    bool isPathCrossing(string path) {
        std::unordered_set<std::string> coords_visited;
        int x = 0, y = 0;
        coords_visited.insert(std::to_string(x) + std::to_string(y));

        for(const auto& move : path) {
            switch(move) {
                case 'N':
                    ++y;
                    break;
                case 'S':
                    --y;
                    break;
                case 'E':
                    ++x;
                    break;
                case 'W':
                    --x;
                    break;
            }
            std::cout << x << " " << y << std::endl;
            std::string current_coord = std::to_string(x) + std::to_string(y);

            if(coords_visited.find(current_coord) != coords_visited.end()) {
                return true;
            }

            coords_visited.insert(current_coord);
        }

        return false;
    }
};