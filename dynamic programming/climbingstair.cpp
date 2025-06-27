class Solution {
public:
    int find(int n, vector<int> &dp)
    {
        if(n == 0)
        {
            return 1;
        }
        if(n < 0)
        {
            return 0;
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = find(n-1, dp) + find(n-2, dp);
    }
    int climbStairs(int n) {
        // vector<int> dp(n+1, -1);
        // find(n, dp);
        // return dp[n];

        if(n <= 1)
        {
            return n;
        }
        int first = 1;
        int second = 1;
        int sum = 0;
        for(int i = 2; i <= n ;i++)
        {
            sum = first + second;
            first = second;
            second = sum;
        } 
        return sum;
    }
};