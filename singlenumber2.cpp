class Solution(object):
    def singleNumber(self,nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        unique = set(nums)
        return (3*sum(unique) - sum(nums))/2
