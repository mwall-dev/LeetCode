/*

    Approach 1: Sort, sweep and choose to add or subtract based on earlier adjacent index.
        - Sort 
        - Start at left and add K
        - Now at A[1] look at A[0] and if is less than add K. If not then subtract K
        - Repeat for next and so on recording min and max elements after the operation 
        as you go 

    time:O(nlogn)
    space:O(1)


    Apporach 2: 
        Find max and min
        If max - min <= K then return K

        else:
        - Problem is the middle values.


        

*/






class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int min = *std::min_element(std::begin(A), std::end(A)); 
        int max = *std::max_element(std::begin(A), std::end(A)); 

        if(max - min <= K) return max - min;



        int N = A.size();
        std::sort(A.begin(), A.end());
        int ans = A[N-1] - A[0];

        for (int i = 0; i < N - 1; ++i) {
            int a = A[i], b = A[i+1];
            int high = std::max(A[N-1] - K, a + K);
            int low = std::min(A[0] + K, b - K);
            ans = std::min(ans, high - low);
        }
        return ans;
    }
};