class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> opt(n+1);

        for (int i = 2; i <= n; i++) {
            opt[i] = min(cost[i-1] + opt[i-1], cost[i-2] + opt[i-2]);
        } 

        return opt[n];
    }
};
/*
    cost =  [1,2,3]
    opt=    [0,0,1,2]
    for 0≤i≤n:
    opt[i] = min cost from 0-i

    base:
        opt[0] = 0
        opt[1] = 0
    recursive:
        i≥2: opt[i] = min(cost[i-1] + opt[i-1], cost[i-2] + opt[i-2])
*/