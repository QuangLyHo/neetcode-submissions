class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int need = target - nums[i];
            int search = bS(nums, i+1, n-1, need);
            if (search>0) return {i+1, search+1};
        }

        return {};
    }

    int bS(vector<int>& nums, int s, int e, int need) {
        while (s<=e) {
            int mid = s+(e-s)/2;
            if (nums[mid] == need) return mid;
            else if (nums[mid] > need) e = mid-1;
            else s = mid+1;
        }
        return -1;
    }
};
/*
    numbers=[2,3,4] target=6
             i
     need = 4

*/