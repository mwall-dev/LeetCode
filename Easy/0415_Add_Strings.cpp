/*
 *  Notes:
 *      - Can't use longs or std::stoi.
 *      - Numbers will defs overflow.
 *      - Strings might not be equal length so work on smaller one and then break out.
 *
 *
 *
 *  Approach:
 *      - Iterate through strings in parallel starting at end.
 *      - Convert each char to an int and add together.
 *      - Append new result to a new string.
 *      - If sum > 10 then take % 10 of the number and carry the one.
 *      - Need to reverse string at end.
 *
 *      time: O(N)
 *      space:O(N) but can be O(1) if we do it in place in one of the inputs.
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
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string res = "";
        while(i>=0 || j>=0 || carry){
            long sum = 0;
            if(i >= 0){sum += (num1[i] - '0');i--;}
            if(j >= 0){sum += (num2[j] - '0');j--;}
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            res =  res + to_string(sum);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};