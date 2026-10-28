class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0, right = n-1;
        int maxWater = 0;
        int height;
        int length;

        while (left < right) {
            height = min(heights[left], heights[right]);
            length = right - left;

            maxWater = max(maxWater, (height * length));

            if (heights[left] > heights[right]) right--;
            else left++;
        }

        return maxWater;
    }
};
/*
     0 1 2 3 4 5 6 7
    [1,7,2,5,4,7,3,6]
     l 
                   r
    height = 1, length = 7 area = 7, 


    Input: height = [1,7,2,5,4,7,3,6] output: 36
    return maximum amount of water a container can store

    area = length x height
    height: will be the minimum(height[left], height[right])
    length: abs(right - left)

    maxWater = 0
    iterate over height:
        calculate curWater
        maxWater = max(maxWater, curWater)
*/