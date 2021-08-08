class Solution {
private: 
    vector<int> original;
    
    int getRand(int l, int r) {
        random_device rd; 
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(l, r);
        return distrib(gen);
    }
public:
    Solution(vector<int>& nums) {
        original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffeled = original;
        // get number from current index to array size
        for (int i = original.size() - 1; i >= 0; --i)
        {
            int newIndex = getRand(0, i);
            swap(shuffeled[i], shuffeled[newIndex]);
        }
        
        return shuffeled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
