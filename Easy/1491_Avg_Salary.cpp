/*
    Approach:
        - Iterate through and sum all, while also recording max and min.
        - Subtract max and min from sum then divide by salary.size() - 2 to get the average.
        
        time: O(N)
        space:O(1)
        
        
    Alt approach:
        - Sort
        
        time:O(NlogN)
        space:O(1)



*/

/*
class Solution {
public:
    double average(vector<int>& salary) {
        
       double sum = std::accumulate(salary.begin(), salary.end(), 0.0);
        
        sum -= *std::max_element(salary.begin(), salary.end());
        sum -= *std::min_element(salary.begin(), salary.end());

                
        return sum / (salary.size() - 2);
    }
};*/

// Dirty one-liner using standard library.
class Solution {
    public:
        double average(std::vector<int>& salary) {
            return (std::accumulate(salary.begin(), salary.end(), 0.0) 
                - (*std::max_element(salary.begin(), salary.end()) + *std::min_element(salary.begin(), salary.end()) ))
                / (salary.size() - 2);
        }
};

