subset sum : sum of every subset

class Solution {
  public:
    void subseq(int index, int size, vector<int> arr, vector<int> temp, vector<int>&ans)
    {
        if(index == size)
        {
            int sum  = 0;
            for(int i = 0 ;i < temp.size(); i++)
            {
                sum += temp[i];
            }
            ans.push_back(sum);
            return;
        }
        // nhi lena
        subseq(index+1, size, arr, temp, ans);
        // lena h
        temp.push_back(arr[index]);
        subseq(index+1, size, arr, temp, ans);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> temp;
        vector<int> ans;
        subseq(0, arr.size(), arr, temp, ans);
        return ans;
    }
};
