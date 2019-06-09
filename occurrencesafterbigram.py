class Solution(object):
    def findOcurrences(self, text, first, second):
        """
        :type text: str
        :type first: str
        :type second: str
        :rtype: List[str]
        """
        words = text.split()
        ans = []
        n = len(words)
        for i in range(n) :
            if (i+2 < n and words[i] == first and words[i+1] == second) :
                ans.append(words[i+2])
                i += 1
        return ans
