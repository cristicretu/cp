class Solution {
    func twoSum(_ numbers: [Int], _ target: Int) -> [Int] {
      var leftIndex = 0, rightIndex = numbers.count - 1

      while leftIndex < rightIndex {
        var sum = numbers[leftIndex] + numbers[rightIndex]

        if sum == target {
          return [leftIndex + 1, rightIndex + 1]
        } else if sum < target {
          leftIndex += 1
        } else {
          rightIndex -= 1
        }
      }

      return [0, 0]
    }
}
