/*
    Notes:
        - Useful info is the row index (used as a secondary option for comparison if two rows have an equal number of soldiers)
          and the number of soldiers in that row.
        - Could use std::count_if but better to do a for loop and exit early.
        - ONLY NEED k weakest rows. Still need to search all rows though.
        - Faster to stop early when counting ones as we know all 1's are on left.

    // CANT DO THIS AS WE CANT USE VALUES IN THE COMPARATOR FUNCTION
    https://stackoverflow.com/questions/52074218/custom-compare-function-for-stdmultimap-when-keys-are-equal
    Approach : std::multi_map (tree map)
        - Iterate through matrix and fill a std::multi_map with key, val = number_of_ones_in_row, row_index.
        - Problem if two rows have same number of ones. Use a std::multi_map.
        - Need to use a custom comparator or can just use tuple as it compares lexiograhpically (first then second if equal, then third if equal...._
        - Iterate through std::multi_map and print keys in sorted order.

    time: O(NlogN)
    space:O(N)


    Approach : above but manually with a vector of pairs and sort.
     - Iterate through matrix and fill a std::vector with std::pair<int,int> = number_of_ones_in_row, row_index.

     - Sort. (Pair uses lexiographic comparison by default).
     - Take first k elements.

    time: O(nm)
    space: O(n)


    Approach: Maybe faster using a heap.
     - Iterate through matrix and fill a std::priority_queue with std::pair<int,int> = number_of_ones_in_row, row_index.
     - Pair uses lexiographic comparison by default
     - Take the top k times to get solution.



    Approach: Set (not as good as ours)!!!
        - We used a multimap because we would get duplicate keys (rows with equal number of ones).
        - SHould instead use a set of pairs. Will never get duplicate as the row number is now part of key.
*/
/*
class Solution {
    public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    set<pair<int, int>> m;
    for (auto i = 0; i < mat.size(); ++i) {
        auto p = accumulate(begin(mat[i]), end(mat[i]), 0);
        m.insert({p, i});
    }
    vector<int> res;
    for (auto it = begin(m); k > 0; ++it, --k)
        res.push_back(it->second);
    return res;
}
};
*/


class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> row_soldier_count;

        for(int row = 0; row < mat.size(); ++row) {
            int number_of_ones = 0;
            for(const auto& ele : mat[row]) {
                if(!ele) break;
                ++number_of_ones;
            }
            row_soldier_count.emplace(number_of_ones, row);
        }

        std::vector<int> result;

        // Take top of heap k times.
        for(int count = 0; count < k; ++count){
            result.push_back(row_soldier_count.top().second);
            row_soldier_count.pop();
        }

        return result;
    }
};

/*

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        std::vector<std::pair<int, int>> row_soldier_count;

        for(int row = 0; row < mat.size(); ++row) {
            int number_of_ones = 0;
            for(const auto& ele : mat[row]) {
                if(!ele) break;
                ++number_of_ones;
            }
            row_soldier_count.emplace_back(number_of_ones, row);
        }

        std::sort(row_soldier_count.begin(), row_soldier_count.end());


        for (auto& ele: row_soldier_count ) {
            std::cout << "Ones: "  << ele.first << " | Row: " << ele.second <<'\n';

        }
        std::vector<int> result;

        // Take first element.
        std::transform(begin(row_soldier_count), begin(row_soldier_count) + k,
               std::back_inserter(result),
               [](const auto& pair){ return pair.second; });

        return result;
    }
}; */