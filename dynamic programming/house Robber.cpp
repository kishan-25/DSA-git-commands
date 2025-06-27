class Solution {
public:
    void find(int index, int &maxi, vector<int>& nums, int size, int sum)
    {
        if(index >= size)
        {
            maxi = max(maxi, sum);
            return;
        }
        if(dp[index] != -1)
        {
            return dp[index];
        }
        // nhi churaye
        find(index+1, maxi, nums, size, sum);
        // churaye
        sum += nums[index];
        find(index+2, maxi, nums, size, sum);
    }
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size+1, -1);
        int maxi = INT_MIN;
        int sum = 0;
        find(0, maxi, nums, size, sum);
        return maxi;
    }
};
