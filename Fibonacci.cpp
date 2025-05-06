Fibbonaci DP solution.


// Memoization
int fibo(int n, vector<int>& dp) {
    if (n == 0 || n == 1)
        return dp[n] = n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
}

// Tabulation
int fiboTab(int n){
    vector<int> dp(n+1);
    dp[0] = 0, dp[1] = 1;
    for(int i=2; i<=n; i++){
            dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    fibo(n, dp);
    cout << dp[n];
    return 0;
}


==
constant space 
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int prev2 = 0;  // F(0)
    int prev1 = 1;  // F(1)
    int curr = 0;

    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}
