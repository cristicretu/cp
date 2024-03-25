class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        mapping = {}

        for num in nums:
          if num in mapping:
            return True
          mapping[num] = True

        return False


