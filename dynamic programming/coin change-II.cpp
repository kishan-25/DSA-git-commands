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

// tabular

class Solution {
public:
    int find(int index, int amount, vector<int>& coins, vector<vector<int>> &dp)
    {
        if(amount == 0)
            return 1;
        if(amount < 0 || index < 0)
            return 0;
        if(dp[index][amount] != -1)
            return dp[index][amount]; 
        return  dp[index][amount] = find(index, amount - coins[index], coins, dp) + find(index-1, amount, coins, dp);
    }
    int change(int amount, vector<int>& coins) {
        int size = coins.size();
        // vector<vector<int>> dp(size+1, vector<int>(amount+1, -1));
        // return find(size-1, amount, coins, dp);

    //     vector<vector<unsigned long long>> dp(size+1, vector<int>(amount+1, 0));

    //     for(int i = 0;i < size+1 ;i++)   
    //         dp[i][0] = 1;    
        
    //     for(int i = 1; i <= size ; i++)
    //     {
    //         for(int j = 1; j <= amount ; j++)
    //         {
    //             if(coins[i-1] > j)
    //                 dp[i][j] = dp[i-1][j];
    //             else
    //                 dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
    //         }
    //     }
    //     return dp[size][amount];
         vector<unsigned long long> dp(amount+1, 0);
         dp[0] = 1;
         for(int i = 1; i < size+1; i++)
         {
            for(int j = 1 ; j < amount + 1 ; j++)
            {
                if(coins[i-1] <= j)
                {
                    dp[j] = dp[j] +  dp[j-coins[i-1]];
                }
            }
         }
         return dp[amount];
    }

};
