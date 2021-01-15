import math


class Solution:
    def countPrimes(self, n: int) -> int:
        if(n == 0 or n == 1 or n == 2): return 0
        prime_flags = [True for index in range(0,n)]
        prime_flags[0] = False
        prime_flags[1] = False

        for divisor in range(2, int(math.sqrt(n)) + 1):
            if prime_flags[divisor] == True:
                for index in range(divisor * divisor, n, divisor):
                    prime_flags[index] = False

        return prime_flags.count(True)
        
                
            
# See  https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
            








if __name__ == "__main__":
    s = Solution()
    print(s.countPrimes(10))