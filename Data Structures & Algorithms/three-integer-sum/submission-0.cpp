class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < n; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                int need = -(nums[i] + nums[j]);

                bool found = bS(nums,j+1, n-1, need);
                if (found) {
                    ans.push_back({nums[i], nums[j], need});
                }
            }
        }

        return ans;
    }

    bool bS(vector<int>& nums,int start, int end, int need) {

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == need) return true;
            else if (nums[mid] > need) end = mid-1;
            else start = mid + 1;
        }
        return false;
    } 
};
/*
    Output: [[-1,-1,2],[-1,0,1]]
    Input: nums =   [-1,0,1,2,-1,-4]
                    s=0,e=5,m=
                    [-4 -1 -1 0 1 2]
    target = 0
    need = -(nums[i] + nums[j])
    [-4 -1 -1 0 1 2]
      i
                j


*/