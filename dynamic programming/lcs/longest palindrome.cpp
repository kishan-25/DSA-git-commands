class Solution {
public:
    int find(int index1, string s1, int index2, string s2)
    {
        if(index1 <= 0 || index2 <= 0)
        {
            return 0;
        }
        if(s1[index1-1] == s2[index2-1])
        {
            return 1 + find(index1-1, s1, index2-1, s2);
        }
        else
        {
            return max(find(index1-1, s1, index2, s2), find(index1, s1, index2-1, s2));
        }
    }
    int longestPalindromeSubseq(string s1) {
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        return find(s1.size(), s1, s2.size(), s2);
    }
};
