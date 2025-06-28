class Solution {
  public:
    int find(int index, int w, vector<int> &val, vector<int> &wt)
    {
        if(w == 0)
            return 0;
        if(index == 0)
            return 0;
        if(wt[index] > w)
            return find(index+1, w, val, wt);
            
        return max(val[index]+find(index-1, w-wt[index], val, wt), find(index-1, w, val, wt));
    }
    int knapsack(int w, vector<int> &val, vector<int> &wt) {
        // code here
        return find(val.size()-1,w, val, wt);
    }
};


//  memoization

class Solution {
  public:
    int find(int index, int w, vector<int> &val, vector<int> &wt,  vector<vector<int>> &dp)
    {
        if(w == 0)
            return 0;
        if(index < 0)
            return 0;
        if(wt[index] > w)
            return find(index-1, w, val, wt, dp);
        if(dp[index][w] != -1)
            return dp[index][w];
            
        return dp[index][w] = max(val[index]+find(index-1, w-wt[index], val, wt, dp), find(index-1, w, val, wt, dp));
    }
    int knapsack(int w, vector<int> &val, vector<int> &wt) {
        // code here
        vector<vector<int>> dp(wt.size()+1, vector<int> (w+1, -1));
        return find(val.size()-1,w, val, wt, dp);
    }
};

// tabular

 int knapsack(int w, vector<int> &val, vector<int> &wt) {
        // code here
        vector<vector<int>> dp(wt.size()+1, vector<int> (w+1, 0));
        // return find(val.size()-1,w, val, wt, dp);
        for(int i = 1; i <= wt.size(); i++) {
        for(int j = 1; j <= w; j++) {
            // Check if current item's weight exceeds capacity
            if(wt[i-1] > j) {
                // Can't include current item, take previous best
                dp[i][j] = dp[i-1][j];
            }
            else {
                // Choose maximum of: include current item vs exclude current item
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
        }
    }
        return dp[wt.size()][w];
    }
