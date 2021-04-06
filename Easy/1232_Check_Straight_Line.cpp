/*
    Notes: 
        For a straight line we need a constant gradient.
        Could say we look at x and y differences between points but it might be a further up point,
        so we need to look at gradient.
        
    Approach 1: Sort and gradient.
        For each pair of points check that gradient is constant.
        Need to sort first
        
    time: O(NLOGN)
    space: O(1)
    
   
    Problems:
        Points dont come ordered in some cases.  (0,0) (0,1) (0,-1)
        so we need to sort somehow.
        Sort with a lambda that sorts by x but is x's are equal then sort by y.
        
        
        
    Approach 2: Math approach. Using Hint 3.
        - Need to check for colinearity (points are all on same line).
        - Can do this by forming a matrix of all the coords x1 x2 x3
                                                            y1 y2 y3
          and so on and then computing the rank (reducing to row-echlon and counting non-zero rows).
          This would be a bit cooked to implement Gaussian Elimination in a LeetCode program.
        
        - Use Theroem: Two vectors (coords/points) are colinear (on same line) if their cross product is equal to the zero vector.
        
*/
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coords) {
        
        if(coords.size() == 2) return true;
        
        auto gradient = [](std::vector<int> p1, std::vector<int> p2) {
            return static_cast<double>((p2[1] - p1[1])) / (p2[0] - p1[0]);
        };

        std::sort(coords.begin(), coords.end(), [](std::vector<int> p1, std::vector<int> p2) {
            if(p1[0] > p2[0]) return true;
            else if(p1[0] == p2[0]) return p1[1] > p2[1];
            else return false;
        });
           
        const double grad = gradient(coords[0], coords[1]);
        
        for(int i = 2; i < coords.size(); ++i) {
            if(abs(gradient(coords[i - 1], coords[i]) - grad) > 0.0001) return false;
        }
        
        return true;
    }
    

};
