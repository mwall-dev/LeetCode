/*
 *
 *
 *  Notes:
 *      - k only has 5 digits max as k <= 10000
 *      - the array can have 10000 digits itself.
 *      - In most cases the array will be longer than the length of k but there will
 *      be times when k is longer.
 *
 *
 *
 *
 *  Approach 1 : Add each array element and each modulo k to a new array and keep track of carries.
 *      - Iterate through array in reverse and the integer in reverse using modulo.
 *      - Store a sum variable and have a carry too.
 *
 *     time:O(N)
 *     space: O(N) for solution
 *
 *
 *  Approach 2 : Inplace in the array
 *      -
 *
 */
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int index = num.size() - 1;
        int carry = 0;

        // Add until array runs out.
        while ((k || carry) && index >= 0) {
            int sum = num[index];

            if (k) {
                sum += (k % 10);
                k /= 10;
            }

            sum += carry;
            carry = sum / 10;
            sum = sum % 10;

            num[index--] = sum;

        }


        // Since k is <=5 digits, rare chance this inefficient part will run.
        while (k > 0) {
            int sum = carry;
            sum += k % 10;
            carry = sum / 10;
            sum = sum % 10;
            num.insert(num.begin(), sum);
            k /= 10;
        }


        // Add final carry.
        if(carry) {
            num.insert(num.begin(), carry);
        }

        return num;
    }





/*
// Approach 1
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int index = num.size() - 1;
        int carry = 0;
        std::vector<int> result;

        while(k || index >= 0 || carry) {
            int sum = 0;
            if(index >= 0) sum += num[index--];
            if(k) {
                sum += (k % 10);
                k /= 10;
            }
            sum += carry;
            carry = sum / 10;

            sum = sum % 10;

            result.push_back(sum);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
*/