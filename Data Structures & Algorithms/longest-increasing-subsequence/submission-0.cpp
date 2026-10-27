class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1);

        for (int i = n-1; i>=0; i--) {
            for (int j = i+1; j < n; j++) {
                if (nums[i] < nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
/*
    input: nums = [9,1,4,2,3,3,7] 
    output: integer representing max # of increasing subsequence

    dp[1:n] = [1 1 1 1 1 1 1]
    i = 0 to n: dp[i] = max count of subsequence in increasing order up to i

    base:
        dp[n-1] = 1
    recurse:
        for j = i, j>n, j++
        j NOT in solution:
            dp[i] = dp[i]
        j IN solution:
            dp[i] = max(dp[i], dp[j]+1)
*/  