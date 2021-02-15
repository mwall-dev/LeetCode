
/*
    Approach 1: Sort 
        - Sort, now min is on left and max is on right.
        - Start at left end, look at max value and min + K
        - Only need to work with these two values as everything in between can be 
        brought up or down as needed.
        - if min + K < max
            return (max- K) - (min + K)

            else 
            return 0

        time: O(nlogn)
        space:O(1)


    Apporach 2: Scan array for max and min on a linear sweep and just do the 
    same as above.






*/




// Approach 1 
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        std::sort(A.begin(), A.end())
        if(A[0] + K < A[A.size()-1]) return (A[A.size() - 1] - K) - (A[0] + K); 

        return 0;
    }
};


// Approach 2
class Solution {
    public:
    int smallestRangeI(vector<int>& A, int K) {
        int min = *std::min_element(std::begin(A), std::end(A)); 
        int max = *std::max_element(std::begin(A), std::end(A)); 
        cout << min << endl;
        cout << max << endl;
        if(min + K < max - K) return (max - K) - (min + K);

        return 0;
   }
};