class Solution {
    func trap(_ height: [Int]) -> Int {
        var ans = 0
        var left = 0
        var right = height.count - 1        
        var lMax = 0
        var rMax = 0

        while left < right {
            if height[left] < height[right] {
                if height[left] >= lMax {
                        lMax = height[left]
                    } else {
                            ans += lMax - height[left]
                        }
                    left += 1
                } else {
                        if height[right] >= rMax {
                           rMax = height[right] 
                        } else {
                                ans += rMax - height[right]
                            }

                        right -= 1
                    }
                
        }

        return ans
    }
}

let sol = Solution()
