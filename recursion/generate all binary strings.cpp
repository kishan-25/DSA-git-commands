// Geenrate all binary strings
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void find(int n, int n0s, int n1s, vector<vector<int>> &store, vector<int> &temp)
{
    if(temp.size() == n)
    {
        store.push_back(temp);
        return;
    }
    temp.push_back(0);
    find(n, n0s-1, n1s, store, temp);
    temp.pop_back();
    temp.push_back(1);
    find(n, n0s, n1s-1, store, temp);
    temp.pop_back();
}

int main() {
    
    int n = 10;
    int n0s = n;
    int n1s = 1;
    vector<vector<int>> store;
    vector<int> temp;
    find(n, n0s, n1s, store, temp);
    for(int i=0;i<store.size();i++)
    {
        for(int j=0;j<store[i].size();j++)
        {
            cout<<store[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
