class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n);
        vector<int> m(n);
        m[0] = prices[0];
/*
           [10,1,5,6,7,1]
        dp [0 0 4 5 6 6]
        m [10 1 1 1 1 1] i=5
*/
        for (int i = 1; i < n; i++) {
            m[i] = min(prices[i], m[i-1]);
            dp[i] = max(dp[i-1], prices[i] - m[i-1]);
        }

        return dp[n-1];
    }
};
/*
*************************************************
************** DYNAMIC PROGRAMMING **************
    PRICES = [10,1,5,6,7,1], MIN = [10]
    0≤i≤n+1: dp[i] = max profit possible ( prices[i] - min[i] ) up to i

    base:
        min[0] = prices[1]
        dp[0] = 0
    recursive case: i > 1
        dp[i] = max(dp[i-1], prices[i] - min[i-1])


Input: prices = [10,1,5,6,7,1] output: 6 (max(prices[j]-prices[i]=6))
                        i
                              j
        maxProfit = 5
*****************************************
************** BRUTE FORCE **************

        for 0≤i≤j≤n: max(prices[j]-prices[i])
        // int n = prices.size();
        // if (n == 1) return 0;

        // int maxProfit = 0;
        // for (int i = 0; i < n; i++) {
        //     for (int j = i+1; j < n; j++) {
        //         maxProfit = max(maxProfit, prices[j] - prices[i]);
        //     }
        // }

        // return (maxProfit > 0) ? maxProfit : 0;

**********************************************
**************DIVIDE AND CONQUER**************
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return dC(prices, 0, n);
    }

    int dC(vector<int>&p, int start, int end) {
        if (start > end) return 0;
        int mid = start + (end - start) / 2;

        int left = dC(p, start, mid);
        int right = dC(p, mid + 1, end);

        int minL = INT_MAX, i = mid;
        while (i >= start) {
            minL = min(minL, p[i]);
            i--;
        }

        int maxR = INT_MIN, j = mid+1;
        while (j <= end) {
            maxR = max(maxR, p[j]);
            j++;
        }
        
        return max({left, right, maxR - minL});
    }
*/