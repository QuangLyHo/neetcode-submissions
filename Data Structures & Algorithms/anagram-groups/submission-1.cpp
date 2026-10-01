class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (auto& s : strs) {
            string sSort = s;
            sort(sSort.begin(), sSort.end());
            mp[sSort].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto& [key, value] : mp) {
            ans.push_back(value);
        }

        return ans;
    }
};
