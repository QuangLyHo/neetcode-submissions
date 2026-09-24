class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        //[2,3,4,3,4] val = 1 k=3
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++; 
            }
        }
        return k;
    }
};