class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n<1) return 0;
        if (n==1) return nums[0];
        vector<int> opt(n);
        opt[0]= nums[0];
        opt[1] = max(nums[1], nums[0]);

        for (int i = 2;i<n;i++){
            opt[i] = max(opt[i-1], opt[i-2] + nums[i]);
        }

        return opt[n-1];
    }
};

/*
    Input: nums = [2,1] output: 2
    opt =         [0,2,1]
                i=2
    for 0≤i≤n: opt(i) = max sum up to i

    base:
    i=0,1
        opt[0] = nums[0]
        opt[1] = nums[1]
    recurse:
    i>1:
        include nums[i]:
            opt[i] = max(opt[i-1], opt[i-2] + nums[i])
        dont include nums[i]:
            opt[i] = opt[i-1]
*/
