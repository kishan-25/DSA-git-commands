class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int , int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int count = 0;
        int maxCount = 0;
        int prev = INT_MIN;
        for(auto ele : mp)
        {
            if(prev == INT_MIN)
            {
                prev = ele.first;
                count++;
                maxCount = max(maxCount, count);
            }
            else
            {
                if(ele.first - prev == 1)
                {
                    count++;
                    maxCount = max(maxCount, count);
                    prev = ele.first;
                }
                else
                {
                    count = 1;
                    prev = ele.first;
                }
            }
        }
        return maxCount;
    }
};
