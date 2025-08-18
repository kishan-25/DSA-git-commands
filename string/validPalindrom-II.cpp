class Solution {
public:
    bool isPalindrome(int start, int end, string s)
    {
        while(start < end)
        {
            if(s[start] != s[end])
                return false;
            start++; 
            end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        if(isPalindrome(0, s.size()-1, s) == true)
            return true;
        // check for deletion
        int start = 0, end = s.size()-1;
        while(start < end)
        {
            if(s[start] != s[end])
            {
                return isPalindrome(start+1, end, s) || isPalindrome(start, end-1, s);
              
            }
            start++;
            end--;
        }
        return true;
    }
};