class Solution {
public:
    int climbStairs(int n) {
        vector<int> opt(n+1);
        if (n == 0 || n == 1) return 1;

        opt[0] = 1;
        opt[1] = 1;

        for (int i = 2; i <= n; i++) {
            opt[i] = opt[i-1] + opt[i-2];
        }

        return opt[n];
    }
};
/*
    you can climb either 1 step or 2 steps at a time
    for 0<=i<=n: opt[n] = distinct ways to climb stairs

    base:
        opt[0] = 1, 1 unique way to climb 0 stairs
        opt[1] = 1, 1 unique way to climb 1 stair  
    resursive:
        i ≥ 2
        opt[i] = opt[i-1] + max[i-2]
*/