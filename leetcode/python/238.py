nums = [1, 2, 3, 4]

def productExceptSelf(nums):
    ans = [1] * len(nums)

    prod = 1
    for i in range(1, len(nums) - 1):
        ans[i] *= nums[i - 1] * ans[i - 1]

    for i in range(len(nums) - 2, -1, -1):
        prod *= nums[i + 1]
        ans[i] *= prod

    return ans

print(productExceptSelf(nums))
