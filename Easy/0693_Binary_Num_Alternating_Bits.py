class Solution:
    def hasAlternatingBits(self, n: int) -> bool:

        if n == 0:
            return True

        next_valid_bit = not(n & 1)
        n = n >> 1

        while (n > 0):

            next_bit = n & 1
            if next_bit != next_valid_bit:
                return False

            n = n >> 1
            next_valid_bit = not next_valid_bit 

        return True 
        








if __name__ == "__main__":
    s = Solution()
    while(True):
        try:
            number_to_check = int(input("Enter a number: "))
        except ValueError:
            print("Not a valid int.")
            continue

        print(s.hasAlternatingBits(int(number_to_check)))