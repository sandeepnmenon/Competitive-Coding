from curses.ascii import isalnum


class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = "".join([x.lower() for x in s if isalnum(x)])
        return s == s[::-1]


string = "A man, a plan, a canal: Panama"
s = Solution()
print(s.isPalindrome(string))
