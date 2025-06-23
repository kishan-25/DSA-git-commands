// generate all the possible substes of a string

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void subseq(int index, int size, string input, string temp, vector<string> &ans)
{
    if(index == size)
    {
        ans.push_back(temp);
        return;
    }
    // not included
    subseq(index+1, size, input, temp, ans);
    // included
    temp += input[index];
    subseq(index+1, size, input, temp, ans);
}
int main() {
    string input = "abc";
    string temp;
    vector<string>ans;
    subseq(0, input.size(), input, temp, ans);
    for(int i = 0; i <ans.size() ; i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}