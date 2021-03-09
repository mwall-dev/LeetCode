
/*
    Approach:
    
    Notes:
    Drawn to binary search as we have sorted rows.
    Maybe look at first or last column to see which row you may be in?
    Then binary search the row.
    
    time:O(2logn) which is O(logn). Number of dimensions scales that complexity.
    space: O(1)
    
    
    Though note below we have done a linear sweep first and then binary search.
    
    
*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
        int row = 0;
        
        while( row < matrix.size() && target >= matrix[row][0]) {
            ++row;
        }
        
        if(row) --row;
        
        std::vector<int>& mat = matrix[row];

        int low = 0;
        int high = mat.size() - 1;
            
        // Binary search row.
        while(low <= high) {    
            int mid = (low + high) / 2;
            
            if(target > mat[mid]) {
                low = mid + 1;
            }

            else if (target < mat[mid]) {
                high = mid - 1;
            }

            else {
                return true;
            }
            
        }
        
        return false;  
            
    }
};