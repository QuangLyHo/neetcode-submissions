class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> seen;
        
        int maxCount = 0;

        for (auto& n:nums) {
            seen.insert(n);
        }

        for (int i = 0; i < n; i++) {
            if (!seen.contains(nums[i]-1)) {
                int count = 1, j = 1;

                while (seen.contains(nums[i] + j)) {
                    count++;
                    j++;
                }
                maxCount = max(maxCount, count);
            }
        }

        return maxCount;
    }
};


/*
Brute Force:
{
        int n = nums.size();

        int maxConsecutive = 0;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int count = 1;
            int j = 0;

            for (; j < n; j++) {
                if (nums[j] == num+1) {
                    count++;
                    num = num+1;
                    j = 0;
                }
            }

            maxConsecutive = max(maxConsecutive, count);
            count = 0;
        }

        return maxConsecutive;
    }
*/