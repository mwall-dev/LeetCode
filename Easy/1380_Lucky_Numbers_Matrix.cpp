/*
 * Notes:
 *  Lucky is defined as min in its row and max in its column.
 *  Can't sort due to positioning. Can sort the rows and move them around.
 *
 *
 * Approach: Brute Force
 *  Iterate through rows.
 *  For each row, get min.
 *  Check if it is the max in its column.
 *
 *  Actually not as bad as I thought as there will only be one min in each row
 *  and we can ignore duplicate columns by storing them if we've already find a lucky number in it.
 *  std::unordered_map<int, int> column_max   where key,val = column_index, max_val.
 *
 *
 *  Approach: Optmised code but not complexity.
 *  Slightly more optimsed memory wise and code wise
 *
 *  Use std::unordered_set and just store all column_maxes and row_mins in it.
 *  If there are two elements that are same then add to result vector.
 *  We are relying on the uniqueness of each element as specified by the question.
 *
 *
 *  Disgusting python
 *  We can create a set of the minimum row values using set comprehension.
To create a set of the maximum column values we can use the unpacking operator (*) on the matrix and use zip to iterate over the unpacked rows in parallel.
We can then get a set of our lucky numbers by intersecting those two sets using the intersection operator (&). Then all that is left to do is to convert the set back into a list.

Time complexity: O(m * n)
Space complexity: O(m + n)

class Solution:
    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        return list({min(row) for row in matrix} & {max(col) for col in zip(*matrix)})
 */

class Solution {

public:
    vector<int> luckyNumbers(vector <vector<int>> &matrix) {
        std::unordered_set<int> s;
        std::vector<int> res;
        for(int row = 0; row < matrix.size(); ++row) {
            int min_element = *std::min_element(matrix[row].begin(), matrix[row].end());
            s.insert(min_element);

        }

        for(int col = 0; col < matrix[0].size(); ++col) {
            // Have to do manually as can't look down columns with iterators.
            int max_element = INT_MIN;
            for(int row = 0; row < matrix.size(); ++row) {
                max_element = std::max(max_element, matrix[row][col]);
            }

            if(s.find(max_element) != s.end()) res.push_back(max_element);

        }

        return res;


    }

};







/*
class Solution {

public:

    std::pair<int, int> get_min_element_index_in_row(const vector<vector<int>>& matrix, int row) {
        int min_element = INT_MAX;
        int min_index;

        for(int col = 0; col < matrix[row].size(); ++col) {
            if(matrix[row][col] < min_element) {
                min_index = col;
                min_element = matrix[row][col];
            }
        }
        std::cout << min_element << " " << min_index << std::endl;
        return std::make_pair(min_element, min_index);
    }

    int get_max_element_in_col(const vector<vector<int>>& matrix, int col) {
        int max_element = INT_MIN;

        for(int row = 0; row < matrix.size(); ++row) {
            if (matrix[row][col] > max_element) {
                max_element = matrix[row][col];
            }
        }

        return max_element;
    }

    vector<int> luckyNumbers (vector<vector<int>>& matrix) {

        std::vector<std::pair<int, int> > row_mins; // pair = row_min, column_number
        std::unordered_map<int, int> column_maxes; // key,val = column_number, max_val;

        for(int row = 0; row < matrix.size(); ++row) {
            row_mins.push_back(get_min_element_index_in_row(matrix, row));
        }

        for(int col = 0; col < matrix[0].size(); ++col) {
            int col_res = get_max_element_in_col(matrix, col);
            column_maxes[col] = col_res;

        }

        std::vector<int> result;

        for(int i = 0; i < row_mins.size(); ++i) {
            const auto& row_min_pair = row_mins[i];
            if(column_maxes[row_min_pair.second] == row_min_pair.first) {
                result.push_back(row_min_pair.first);
            }
        }

        return result;


    }
};

 */