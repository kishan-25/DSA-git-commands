class Solution {
  public:
  int find(int index1, string s1, int index2, string s2)
    {
        if(index1 <= 0 || index2 <= 0)
        {
            return 0;
        }
        if(s1[index1-1] == s2[index2-1] && index1 != index2)
        {
            return 1 + find(index1-1, s1, index2-1, s2);
        }
        else
        {
            return max(find(index1-1, s1, index2, s2), find(index1, s1, index2-1, s2));
        }
    }
    int LongestRepeatingSubsequence(string &s1) {
        // Code here
        string s2 = s1;
        // reverse(s2.begin(), s2.end());
        int lcs = find(s1.size(), s1, s2.size(), s2);
        return lcs;
    }
};
