class Solution {
    func threeSum(_ nums: [Int]) -> [[Int]] {
        let sortedNums = nums.sorted()
        var result: [[Int]] = []
        
        for i in 0..<sortedNums.count - 2 {
            if i > 0 && sortedNums[i] == sortedNums[i - 1] { continue }
            
            var left = i + 1
            var right = sortedNums.count - 1
            
            while left < right {
                let sum = sortedNums[i] + sortedNums[left] + sortedNums[right]
                
                if sum == 0 {
                    result.append([sortedNums[i], sortedNums[left], sortedNums[right]])
                    
                    while left < right && sortedNums[left] == sortedNums[left + 1] { left += 1 }
                    while left < right && sortedNums[right] == sortedNums[right - 1] { right -= 1 }
                    
                    left += 1
                    right -= 1
                } else if sum < 0 {
                    left += 1
                } else {
                    right -= 1
                }
            }
        }
        
        return result
    }
}
