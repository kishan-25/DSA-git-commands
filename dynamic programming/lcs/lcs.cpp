// recursion

class Solution {
public:
    int find(int index1, string text1, int index2, string text2)
    {
        if(index1 <= 0 || index2 <= 0)
        {
            return 0;
        }
        if(text1[index1-1] == text2[index2-1])
        {
            return 1 + find(index1-1, text1, index2-1, text2);
        }
        else
        {
            return max( find(index1-1, text1, index2, text2), find(index1, text1, index2-1, text2));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        return find(text1.size(), text1, text2.size(), text2);
    }
};
