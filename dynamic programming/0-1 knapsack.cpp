class Solution {
  public:
    int find(int index, int w, vector<int> &val, vector<int> &wt)
    {
        if(w == 0)
            return 0;
        if(index == 0)
            return 0;
        if(wt[index] > w)
            return find(index+1, w, val, wt);
            
        return max(val[index]+find(index-1, w-wt[index], val, wt), find(index-1, w, val, wt));
    }
    int knapsack(int w, vector<int> &val, vector<int> &wt) {
        // code here
        return find(val.size()-1,w, val, wt);
    }
};
