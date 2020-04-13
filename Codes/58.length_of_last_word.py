class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        res = s.split(' ')
        for i in range(len(res) - 1, -1, -1):
            if len(res[i]) > 0:
                return len(res[i])
        return 0
