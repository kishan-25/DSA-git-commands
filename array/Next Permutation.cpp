class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        // 1. Find the pivot (first decreasing element from the right)
        for (int i = n - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                pivot = i - 1;
                break;
            }
        }

        if (pivot != -1) {
            // 2. Find the smallest element greater than pivot from the right
            for (int i = n - 1; i > pivot; i--) {
                if (nums[i] > nums[pivot]) {
                    swap(nums[i], nums[pivot]);
                    break;
                }
            }
            // 3. Reverse the suffix
            reverse(nums.begin() + pivot + 1, nums.end());
        } 
        else {
            // Last permutation → reverse to get first
            reverse(nums.begin(), nums.end());
        }
    }
};
