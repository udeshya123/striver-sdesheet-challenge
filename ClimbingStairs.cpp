
Complexity Analysis:
- The time complexity of the fmemo function is O(n) because we are calculating and storing the number of ways to climb n steps.
- The space complexity is also O(n) to store the dp array.
*/


// Memoization
int fmemo(int n, vector<int>& dp) {
    if (n == 1 || n == 2)
        return dp[n] = n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fmemo(n - 1, dp) + fmemo(n - 2, dp);
}

// Tabulation
int ftab(int n){
    vector<int> dp(n+1);
    dp[1] = 1, dp[2] = 2;
    for(int i=3; i<=n; i++)
        dp[i] = dp[i-1]+dp[i-2];
    return dp[n];
}

// Space Optimization
int fopt(int n){
    int p1 = 1, p2 = 2, ans = 0;
    for(int i=3; i<=n; i++){
        ans = p1+p2;
        p1 = p2, p2 = ans;
    }
    return ans;
}

int climbStairs(int n) {
    if (n == 1 || n == 2)
        return n;
    return fopt(n);
}
