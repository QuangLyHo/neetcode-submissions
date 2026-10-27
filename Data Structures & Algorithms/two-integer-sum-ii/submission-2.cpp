class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;

        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                return {left+1, right+1};
            }
            if (numbers[left] + numbers[right] > target) {
                right--;
            }
            else {
                left++;
            }
        }

        return {0,0};
    }
};

/*
    Input: numbers = [-5,-3,0,2,4,6,8], target = 5
    Output: vector 
    -3 + 8 = 5
    [-5,-3,0,2,4,6,8] target = 5 
         l
                   r
    l=1, r=6
    while l < r:
        if l+r > target:
            r--
        else if l+r < target:
            l++
        else l+r == target:
            return {l,r}
*/
