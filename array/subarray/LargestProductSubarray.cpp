class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int leftProd = 1;
        int rightProd = 1;
        for(int i=0;i<nums.size();i++)
        {
            leftProd = (leftProd == 0) ? 1 : leftProd;
            rightProd = (rightProd == 0) ? 1 : rightProd;

            // prefix product
            leftProd *= nums[i];

            // suffix prod
            rightProd *= nums[nums.size()-1-i];

            maxProd = max(maxProd, max(leftProd, rightProd)); 
        }
        return maxProd;
    }
};
