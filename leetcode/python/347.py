class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """

        mapping = {}

        for num in nums:
            if num in mapping:
                mapping[num] += 1
            else:
                mapping[num] = 1

        sorted_items = sorted(mapping.items(), key=lambda x: x[1], reverse=True)

        ans = []

        for num, _ in sorted_items[:k]:
            ans.append(num)

        return ans

