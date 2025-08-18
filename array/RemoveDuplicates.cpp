class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // map<int, int> mp;
        // for(int i=0;i<nums.size();i++)
        // {
        //     mp[nums[i]]++;
        // }
        // int i=0;
        // for(auto ele : mp)
        // {
        //     nums[i] = ele.first;
        //     i++;
        // }
        // return mp.size();


        if (nums.empty()) return 0;
        
        int j = 0; // slow pointer
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[j]) {
                j++; 
                nums[j] = nums[i]; 
            }
        }
        return j + 1; // number of unique elements

    }
};