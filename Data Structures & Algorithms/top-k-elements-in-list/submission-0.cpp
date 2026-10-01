class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        for (auto& [key, values]:mp) {
            cout << key << ": " << values << " ";
        }
        vector<int> res;
        while (k > 0) {
            auto maxIt = mp.begin();
            for (auto it = mp.begin(); it != mp.end(); it++) {
                if (it->second > maxIt->second) maxIt = it;
            }
            res.push_back(maxIt->first);
            mp.erase(maxIt->first);
            k--;
        }

        return res;
    }
};
