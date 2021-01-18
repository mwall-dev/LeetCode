class Solution:
    def isPalindrome(self, x: int) -> bool:
        word = str(x)
        return word == word[::-1]



if __name__ == "__main__":
    s = Solution()
    print(s.isPalindrome(123421))