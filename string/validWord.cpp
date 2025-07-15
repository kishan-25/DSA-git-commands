class Solution {
public:
    bool isValid(string s) {
        if(s.size() < 3)
            return false;
        
        bool hasVowel = false;
        bool hasConsonant = false;
        for(auto ch : s)
        {
            char c = tolower(ch);
            if(isalpha(c))
            {
                if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                {
                    hasVowel = true;
                }else{
                    hasConsonant = true;
                }
            }
            else if(!isdigit(c))
            {
                return false;
            }
        }
        return hasVowel && hasConsonant;
    }
};