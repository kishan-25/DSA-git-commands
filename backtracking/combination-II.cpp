class Solution {
public:
    void ways(vector<vector<int>> &ans, int index, int size, vector<int> &temp, vector<int>& candidates, int sum, set<vector<int>> &s)
    {
        if(sum < 0)
        {
            return;
        }
        if(sum == 0)
        {
            if(s.find(temp) == s.end())
            {
                s.insert(temp);
                ans.push_back(temp);
                return;
            }
        }
        
        for(int i = index; i < size ; i++)
        {
                if(i > index && candidates[i] == candidates[i - 1]) continue;  // skip duplicates

                temp.push_back(candidates[i]);
                ways(ans, i + 1, size, temp, candidates, sum - candidates[i], s);
                temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         vector<vector<int>> ans;
         int size = candidates.size();
         sort(candidates.begin(), candidates.end());
         vector<int> temp;
         set<vector<int>> s;
         ways(ans, 0, size, temp, candidates, target, s);
         return ans;
    }
};