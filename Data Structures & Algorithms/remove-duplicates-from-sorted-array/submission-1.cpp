class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;// 
        //nums=[1,1,2,3,4]
        //nums=[1,1,2,3,4]
        for (int i = 0/*4*/; i < nums.size(); i++) {
            if (nums[i] != nums[k]) {
                k++;
                nums[k] = nums[i];
            }
        }
        cout << k+1 ;
        return k+1;
    }
};