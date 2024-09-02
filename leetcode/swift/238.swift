class Solution {
    func productExceptSelf(_ nums: [Int]) -> [Int] {
        var result: [Int] = []
        var product = 1
        var zeroCount = 0

        for num in nums {
            if num == 0 {
                zeroCount += 1
            } else {
                product *= num
            }
        }

        for num in nums {
            if zeroCount > 1 {
                result.append(0)
            } else if zeroCount == 1 {
                if num == 0 {
                    result.append(product)
                } else {
                    result.append(0)
                }
            } else {
                result.append(product / num)
            }
        }

        return result
    }
}

let sol = Solution()

let input1 = [1,2,3,4]
let output1 = sol.productExceptSelf(input1)
assert(output1 == [24, 12,8 ,6], "t1 failed")

let input2 = [-1,1,0,-3,3]
let output2 = sol.productExceptSelf(input2)
assert(output2 == [0,0,9,0,0], "t2 failed")
