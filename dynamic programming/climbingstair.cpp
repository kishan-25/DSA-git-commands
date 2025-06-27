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



//  memoization

class Solution {
public:
    int find (int index, vector<int>& nums, int size, vector<int> &dp)
    {
        if(index >= size)
        {
            return 0;
        }
        if(dp[index] != -1)
        {
            return dp[index];
        }
        return dp[index] = max(nums[index] + find(index+2, nums, size, dp), find(index+1, nums, size, dp));
    }
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size+1, -1);
        find(0, nums, size, dp);
        return dp[0];
    }
};

// tabulation

int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size+2, -1);
        // find(0, nums, size, dp);
        dp[size] = 0;
        dp[size+1] = 0;
        for(int i = size-1; i >= 0; i--)
        {
            dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
        }
        return dp[0];
    }

// space optimization

 int rob(vector<int>& nums) {
        int size = nums.size();
        // vector<int> dp(size+2, -1);
        // find(0, nums, size, dp);
        // dp[size] = 0;
        // dp[size+1] = 0;
        int last = 0, secondLast = 0;
        int sum = 0;
        for(int i = size-1; i >= 0; i--)
        {
            sum = max(nums[i] + last, secondLast);
            last = secondLast;
            secondLast = sum;
        }
        return sum;
