

/*
 *  Approach 1:
 *  Create a new vector to hold result.
 *  Iterate through vector in 2's.
 *  Take freq and val and use a while loop to push onto result vector.
 *
 *
 *
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
    std::vector<int> decompressRLElist(std::vector<int>& nums) {
        std::vector<int> res;
        for(int i = 0; i < nums.size(); i+=2) {
            int freq = res[i];
            int val = res[i + 1];

            while(freq) {
                res.push_back(val);
                --freq;
            }

        }

        return res;
    }
};


// python one liner
//class Solution:
//    def decompressRLElist(self, A) -> List[int]:
//        return [x for a, b in zip(A[::2], A[1::2]) for x in [b] * a]
//
