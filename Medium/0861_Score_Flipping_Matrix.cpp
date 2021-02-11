

/*
    Apporach 1: Greedy
        - Make use of fact that MSB's are all we can about. Want to maximise left hand side.
        This is just due to nature of numbers where 111 < 1000.
        - First, iterate through all rows and invert row if there are any leading zeroes.
        - Second go through each column and if there are more 0's than 1's than invert col.
        - Third, convert to binary and sum




*/



#include <vector>
#include <cmath>
class Solution {
public:
    int matrixScore(std::vector<std::vector<int> >& A) {
        // Check rows
        for(auto row = 0; row < A.size(); ++row) {
            if(A[row][0] == 1) {
                for(int j = 0; j < A[row].size(); ++j) {
                    A[row][j] = (A[row][j] == 1) ? 0 : 1; 
                }
            }
        }

        // Check cols
        for(auto col = 0; col < A[0].size(); ++col) {
            int num_zeroes = 0;
            int num_ones = 0;
            for(auto row = 0; row < A.size(); ++row) {
                if(A[row][col] == 1) ++num_ones;
                else ++num_zeroes;
            }
            // If more zeroes than ones.
            if(num_zeroes > num_ones) {
                // Invert column
                for(auto row = 0; row < A.size(); ++row) {
                    A[row][col] = (A[row][col] == 1) ? 0 : 1;
                }
            }

        }
        
        int res = 0;
        for(auto row = 0; row < A.size(); ++row) {
            res += binary_to_num(A[row]);
        }
        return res;
        
    }


    int binary_to_num(std::vector<int> binary) {
        int power = binary.size() - 1;
        int num = 0;

        for(auto binary_digit : binary) {
            if(binary_digit == 1) num += (int)std::pow(2, power);

            --power;
        }

        return num;
    }
    
};
