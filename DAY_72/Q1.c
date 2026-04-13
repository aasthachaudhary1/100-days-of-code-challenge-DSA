#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        int VISITED_ALL = (1 << n);
        
        // dp[mask][i] = min cost to reach city i with visited mask
        vector<vector<int>> dp(VISITED_ALL, vector<int>(n, INT_MAX));
        
        // Starting from city 0
        dp[1][0] = 0;
        
        for (int mask = 1; mask < VISITED_ALL; mask++) {
            for (int u = 0; u < n; u++) {
                if ((mask & (1 << u)) == 0) continue;
                
                for (int v = 0; v < n; v++) {
                    if (mask & (1 << v)) continue;
                    
                    int newMask = mask | (1 << v);
                    dp[newMask][v] = min(dp[newMask][v],
                                         dp[mask][u] + cost[u][v]);
                }
            }
        }
        
        // Return to starting city (0)
        int ans = INT_MAX;
        for (int i = 1; i < n; i++) {
            if (dp[VISITED_ALL - 1][i] != INT_MAX) {
                ans = min(ans, dp[VISITED_ALL - 1][i] + cost[i][0]);
            }
        }
        
        return ans;
    }
};
