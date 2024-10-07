class Solution {
    func topKFrequent(_ nums: [Int], _ k: Int) -> [Int] {
    // have a key value hashmap, where key is the number, value is the number of appearances, we then sort by the value  
      var frequency : [Int: Int] = [:]

      for num in nums {
          frequency[num, default: 0] += 1
      }

      let sortedNums = frequency.keys.sorted { frequency[$0]! > frequency[$1]! }
      return Array(sortedNums.prefix(k))
    }
}
