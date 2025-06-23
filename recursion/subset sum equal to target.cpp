// subset sum equal to target

class Solution {
  public:
    void subseq(int index, int size, int target, vector<int> temp, int &count, vector<int> arr)
    {
        if(index == size)
        {
            int sum = 0;
            for(int i = 0 ; i < temp.size() ; i++)
            {
                sum += temp[i];
            }
            if(sum == target)
            {
                count++;
            }
            return;
        }
        // nhi lena
        subseq(index+1, size, target, temp, count, arr);
        // lena h
        temp.push_back(arr[index]);
        subseq(index+1, size, target, temp, count, arr);
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        vector<int> temp;
        int count = 0;
        subseq(0, arr.size(), target, temp, count, arr);
        return count;
    }
};
