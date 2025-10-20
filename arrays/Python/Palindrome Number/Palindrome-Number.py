class Solution:
    def isPalindrome(self, x: int) -> bool:
        num = x
        if x < 0:
            return False

        reverseNum = 0
        while x > 0:
            remainder = x % 10
            reverseNum = reverseNum * 10 + remainder
            x //= 10

        return num == reverseNum
