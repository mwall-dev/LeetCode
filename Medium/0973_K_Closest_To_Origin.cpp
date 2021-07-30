/*
    Notes:
        - Naive answer is sort and lambda.

        - Thinking a sort will take too long here.
        - Maybe we dont need to sort the whole array
        - We are wasting sorting whole array, only need to sort first k elements.
        - Use std::partial_sort





    Approach 1 : Sort
        - Sort points by their Eucildean distance from the origin.
        - Return first K points

    time: O(NlogN)
    space: O(1)


    Approach 2 : std::partial_sort and std::nth_element use an algo called quickselect.


    Approach 3 : heap and take first k elements
        - This is interesting.
        - The cost of building a heap is O(N), you would think that it would be O(NlogN) but it isnt. https://stackoverflow.com/questions/9755721/how-can-building-a-heap-be-on-time-complexity
        - The cost of taking the top is O(logN) as it does have to rebalance.

        so
        time:O(KlogN)
        space:O(N)




*/

class Solution {

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        auto comp = [](const std::vector<int>& p1, const std::vector<int>& p2) {
            double euc_dis1 = std::hypot(p1[0], p1[1]);
            double euc_dis2 = std::hypot(p2[0], p2[1]);

            if(std::fabs(euc_dis1 - euc_dis2) < 0.000001) {
                return false;
            }

            return euc_dis1 > euc_dis2;
        };



        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(comp)> heap(comp);

        for(auto&& point : points) {
            heap.push(point);
        }

        std::vector<std::vector<int>> result;

        while(result.size() < k) {
            result.push_back(heap.top());
            heap.pop();
        }

        return result;
    }

};


/*
// Approach 2 : std::partial_sort (requires C++20)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::partial_sort(points.begin(), points.begin() + k, [](const auto& p1, const auto& p2) {
          double euc_dis1 = std::hypot(p1[0], p1[1]);
          double euc_dis2 = std::hypot(p2[0], p2[1]);

          if(std::fabs(euc_dis1 - euc_dis2) < 0.000001) {
              return true;
          }

          return euc_dis1 < euc_dis2;
       });

        return std::vector<std::vector<int>>(points.begin(), points.begin() + k);

    }


};

*/

/*
// Approach 1 : Sort
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       std::sort(points.begin(), points.end(), [](const auto& p1, const auto& p2) {
          double euc_dis1 = std::hypot(p1[0], p1[1]);
          double euc_dis2 = std::hypot(p2[0], p2[1]);

          if(std::fabs(euc_dis1 - euc_dis2) < 0.000001) {
              return true;
          }

          return euc_dis1 < euc_dis2;
       });



        return std::vector<std::vector<int>>(points.begin(), points.begin() + k);

    }
};

*/