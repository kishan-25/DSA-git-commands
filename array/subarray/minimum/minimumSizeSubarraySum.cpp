class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // int minilen = INT_MAX;
        // for(int i=0;i<nums.size();i++)
        // {
        //     int sum = 0;
        //     for(int j=i;j<nums.size();j++)
        //     {
        //         sum += nums[j];
        //         if(sum >= target)
        //         {
        //             int len = j - i + 1;
        //             minilen = min(minilen, len);
        //         }
        //     }
        // }
        // return (minilen == INT_MAX) ? 0 : minilen;
        int minilen = INT_MAX;
        int sum = 0;
        int start = 0, end = 0;
        while(end < nums.size())
        {
            sum += nums[end];
            while(sum >= target)
            {
                minilen = min(minilen, end-start+1);
                sum = sum - nums[start];
                start++;
            }
            end++;
        }
        return (minilen == INT_MAX) ? 0 : minilen;
    }
};