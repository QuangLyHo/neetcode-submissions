// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    void insert(vector<Pair>& pairs, int i) {
        Pair temp = pairs[i];
        int j;

        for (j = i - 1; j >= 0; j--) {
            if (pairs[j].key > temp.key) {
                pairs[j + 1] = pairs[j];
            }
            else break;
        }
        pairs[j + 1] = temp;
    }

    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> result;
        int n = pairs.size();

        if (n == 0) return result;
        if (n == 1) {
            result.push_back(pairs);
        }
        if (n > 1) {
            result.push_back(pairs);
        }

        for (int i = 1; i < n; i++) {
            insert(pairs, i);
            result.push_back(pairs);
        }

        return result;
    }
};
