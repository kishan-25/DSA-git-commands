class Solution {
  public:
    void subseq(int index, int size, int k, int &check, vector<int> temp, vector<int> arr)
    {
        if(index == size)
        {
            int sum = 0;
            for(int i = 0; i < temp.size() ; i++)
            {
                sum += temp[i];
            }
            if(sum % k == 0)
            {
                check = 1; 
            }
            return;
        }
        // nhi lenge
        subseq(index+1, size, k, check, temp, arr);
        temp.push_back(arr[index]);
        subseq(index+1, size, k, check, temp, arr);
    }
    int DivisibleByM(vector<int>& arr, int k) {
        // Code here
        vector<int> temp;
        int check = 0;
        subseq(0, arr.size(), k, check, temp, arr);
        return check;
    }
};
