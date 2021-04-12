/*
 *  Notes:
 *      - Every element needs to be checked.
 *      - Only need to check down and left diagonals.
 *      - For down and left diagonals, the indices have the following relation:
 *      Two 2d indices (r1, c1), (r2, c2) are on the same left and down diagonal if
 *      r1-c1 == r2-c2
 *
 *  Approach:
 *      Iterate through elements of first row and then first column and for each one you look at the elements on its
 *      diagonal using the above relationship.
 *
 *      time:O(N^2)
 *      space:O(1)
 *
 *      Optimise with a lambda.
 *
 *  Alt approach:
 *      Just iterate through matrix and for each ele check its adjacent diagonals for equality (check for out of range
 *      too).
 *
 *      time:O(N^2) but longer than the above approach as you will visit elements more than once.
 *      space:O(1)
 *
 *  Alt 2 approach:
 *      As above but just check top left neighbour for equality (and also bounds checking).
 *
 *      time:O(N^2)
 *      space:O(1)
 *
 *      Same as first approach but this is less code
 *
 *
 *
 *
 *
 *
 *
 *
 */

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int row = 0; row < matrix.size(); ++row) {
            for(int col = 0; col < matrix[0].size(); ++col) {
                if(row - 1 >= 0 && col - 1 >= 0) {
                    if(matrix[row][col] != matrix[row - 1][col - 1]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};


/*
 *
 // Approach 1:
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        // Look at first row.
        for(int col = 0; col < matrix[0].size(); ++col) {
            int element = matrix[0][col];
            int row_traverse = 1;
            int col_traverse = col + 1;

            while(row_traverse < matrix.size() && col_traverse < matrix[0].size()) {
                if (matrix[row_traverse++][col_traverse++] != element) {
                    return false;
                }
            }
        }

        // Look at first col
        for(int row = 0; row < matrix.size(); ++row) {
            int element = matrix[row][0];
            int col_traverse = 1;
            int row_traverse = row + 1;

            while(row_traverse < matrix.size() && col_traverse < matrix[0].size()) {
                if (matrix[row_traverse++][col_traverse++] != element) {
                    return false;
                }
            }
        }

        return true;

    }
};

 */