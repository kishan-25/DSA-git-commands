approach going from 0 to n

class Solution {
public:
    int find(int index, vector<int>& coins, int size, int amount, vector<vector<int>> &dp)
    {
        if(amount == 0)
            return 1;
        if(amount < 0)
            return 0; 
        if(index >= size)
            return 0;
        if(dp[index][amount] != -1)
            return dp[index][amount];
        return dp[index][amount] = find(index, coins, size, amount - coins[index], dp) + find(index+1, coins, size, amount, dp);        
    }
    int change(int amount, vector<int>& coins) {
        int size = coins.size();
        vector<vector<int>> dp(size+1, vector <int>(amount+1, -1));
        return find(0, coins, size, amount, dp);
    }
};
