class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size()-1;
        int maxStr = 0;
        while(start < end)
        {
            int mini = min(height[start], height[end]);

            maxStr = max(maxStr, mini*(end - start));
            (height[start] <= height[end]) ? start++ : end--;
        }
        return maxStr;
    }
};
