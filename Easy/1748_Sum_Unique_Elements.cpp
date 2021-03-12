/*
    Approach:
        Iterate through and count freq of nums using map.
        Iterate through map and add all with freq=1.
        
        time:O(N)
        space:O(N)


    Approach 2:
        Numbers are limited to 1 to 100 so just use static array for faster indexing.


*/



class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int freq_count[101] = {0 };
        
        for(const int& num : nums) {
            ++freq_count[num];
        }
        
        int sum = 0;
        for(int i = 0; i <= 100; ++i) {
            if(freq_count[i] == 1) sum += i;
        }
        
        return sum;
    }
};
