nums[2,3,2]

phele 2,3 ka nikal lo and then 3, 2 ka nikal lo or jo maximum h use return kr do kyoki circular h array 

or optimize krne ke time dono ki alg alg dp banalena

class Solution {
public:
    int find(int index, int size, vector<int>& nums)
    {
        if(index >= size)
            return 0;
        
        return max(nums[index] + find(index+2, size, nums), find(index+1, size, nums));
    }
    int rob(vector<int>& nums) 
    {
        int size = nums.size();
        return max(find(0, size - 1, nums), find(1, size, nums));
    }
};
