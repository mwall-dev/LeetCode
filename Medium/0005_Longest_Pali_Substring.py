
""" 
    Approach 1: Brute Force
        Start at each letter do nested loop to check all start and end points. 
        Each iteration, build string and check if is a palindrome. If so, record the string.
        
    time: O(n^3) as n choose 2 substrings = n(n-1)/2 
    space: O(N)

    Approach 2: DP
        Need to reuse a previosuly computed palindrome to compute a larger palindrome.
        public class Solution {
            
private int lo, maxLen;

public String longestPalindrome(String s) {
	int len = s.length();
	if (len < 2)
		return s;
	
    for (int i = 0; i < len-1; i++) {
     	extendPalindrome(s, i, i);  //assume odd length, try to extend Palindrome as possible
     	extendPalindrome(s, i, i+1); //assume even length.
    }
    return s.substring(lo, lo + maxLen);
}

private void extendPalindrome(String s, int j, int k) {
	while (j >= 0 && k < s.length() && s.charAt(j) == s.charAt(k)) {
		j--;
		k++;
	}
	if (maxLen < k - j - 1) {
		lo = j + 1;
		maxLen = k - j - 1;
	}
}}


"""

def is_pali(s: str) -> bool: 
    
    ptr_start = 0
    ptr_end = len(s) - 1

    while ptr_start < ptr_end:
        if s[ptr_start] != s[ptr_end]:
            return False
        ptr_start += 1
        ptr_end -= 1

    return True


class Solution:
    def longestPalindrome(self, s: str) -> str:

        if len(s) == 2:
            if s[0] == s[1]:
                return s
            else:
                return s[0]
        

        test_string = ""
        longest_pali = s[0]
        
        for i in range(0, len(s)):
            test_string += s[i]
            for j in range(i + 1, len(s)):
                test_string += s[j]
                if is_pali(test_string) and len(test_string) > len(longest_pali):
                    longest_pali = test_string
                
            
            test_string = ""

        return longest_pali







if __name__ == "__main__":
    s = Solution()
    print(s.longestPalindrome("a"))