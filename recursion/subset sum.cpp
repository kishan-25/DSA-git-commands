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
T.C : O(n * 2^n)

// modified approach
T.C : O(2^n)

class Solution {
  public:
    void subseq(int index, int size, vector<int> arr, vector<int>&ans, int sum)
    {
        if(index == size)
        {
            ans.push_back(sum);
            return;
        }
        // nhi lena
        subseq(index+1, size, arr, ans, sum);
        // lena h
        subseq(index+1, size, arr, ans, sum + arr[index]);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> ans;
        int sum = 0;
        subseq(0, arr.size(), arr, ans, sum);
        return ans;
    }
};

