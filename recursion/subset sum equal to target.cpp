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

T.C : O(n*2^n)

// updated version
T.C : O(2^n)
class Solution {
  public:
    void subseq(int index, int size, int target, int sum, int &count, vector<int> arr)
    {
        if(index == size)
        {
            if(sum == target)
            {
                count++;
            }
            return;
        }
        // nhi lena
        subseq(index+1, size, target, sum, count, arr);
        // lena h
        subseq(index+1, size, target, sum + arr[index], count, arr);
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        vector<int> temp;
        int sum = 0;
        int count = 0;
        subseq(0, arr.size(), target, sum, count, arr);
        return count;
    }
};
