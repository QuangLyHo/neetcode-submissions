class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;
        if (n == 1) return 1;

        int left = 0, res = 0, count = 0;
        unordered_map<char, int> mp;

        for (int right = 0; right < n; right++) {
            mp[s[right]]++;
            
            if (mp[s[right]] > 1) {
                while (mp[s[right]] > 1) {
                    mp[s[left]]--;
                    left++;
                }
            } 
            count = right - left + 1;
            res = max(res, count);
        }

        return res;
    }
};
/*
    longest substring without repeating characters
    input: string   output: int (count of longest substring)

    need hashmap<char, int> mp

    brute force:
        0≤i≤j≤n: 
            count = 0
            if () 
                count = max(count, maxCount), 
                count = 0
            else count++

    sliding window + hashmap
*/