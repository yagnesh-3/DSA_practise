class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // Use a set for fast lookup
        unordered_set<int> numSet(nums.begin(), nums.end());
        int ans = 0;

        // Iterate over each number in nums
        for (int num : nums) {
            int count = 0;
            long long current = num; // Use long long to prevent overflow

            // Form the square streak
            while (numSet.count(current)) {
                count++;
                current *= current; // Square the current number
                
                // Break if current exceeds the int range
                if (current > INT_MAX) break;
            }
            ans = max(ans, count); // Update ans with the max streak length
        }

        return ans > 1 ? ans : -1; // Return -1 if no valid streak is found
    }
};
