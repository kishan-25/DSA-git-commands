class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        // string word = "a";
        // for(int i=0;i<operations.size();i++)
        // {
        //     if(operations[i] == 0)
        //     {
        //         string str = word;
        //         word += str;
        //     }
        //     else if(operations[i] == 1)
        //     {
        //         string str = "";
        //         for(int i=0;i<word.size();i++)
        //         {
        //             if(word[i] == 'z')
        //                 str += word[i] - 25;
        //             else
        //                 str += word[i]+1;
        //         }
        //         word += str;
        //     }
        // }
        // return word[k-1];

        int shift = 0;
        vector<long long> lengths;
        long long len = 1;

        for (int op : operations) {
            len *= 2;
            lengths.push_back(len);
            if (len >= k) break;
        }

        for (int i = lengths.size() - 1; i >= 0; --i) {
            long long half = lengths[i] / 2;
            int op = operations[i];
            if (k > half) {
                k -= half;
                if (op == 1) shift++;
            }
        }

        return (char)((('a' - 'a' + shift) % 26) + 'a');
    }
};
