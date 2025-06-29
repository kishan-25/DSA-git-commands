class Solution {
  public:
    void find(int i, string s1, int j, string s2, int &maxi, int count)
    {
        if(i <= 0 || j <= 0)
        {
            return;
        }
        if(s1[i-1] == s2[j-1])
        {
            count++;
            maxi = max(maxi, count);
            find(i-1, s1, j-1, s2, maxi, count);
        }
        else
        {
            count = 0;
            find(i-1, s1, j, s2, maxi, count);
            find(i, s1, j-1, s2, maxi, count);
        }
    }
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int maxi = 0;
        int count = 0;
        find(s1.size(), s1, s2.size(), s2, maxi, count);
        return maxi;
    }
};
