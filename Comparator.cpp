#include<bits/stdc++.h>
using namespace std;

bool myComparator(int a, int b)
{
    // Descending order
    if(a > b) 
        return true;
    return false;
}

int main() {
    
    vector<int> vec = {1, 5, 2, 3};
    sort(vec.begin(), vec.end(), myComparator);
    for(auto ele : vec)
        cout<<ele << "   ";
    return 0;
} 


// for ascending order

#include<bits/stdc++.h>
using namespace std;

bool myComparator(int a, int b)
{
    // Descending order
    if(a < b) 
        return true;
    return false;
}

int main() {
    
    vector<int> vec = {1, 5, 2, 3};
    sort(vec.begin(), vec.end(), myComparator);
    for(auto ele : vec)
        cout<<ele << "   ";
    return 0;
} 

#include<bits/stdc++.h>
using namespace std;

// sort on the basis of the first element
bool mycomparator(pair<int, int> a, pair<int, int> b)
{
    if(a.first < b.first)
        return true;
    return false;
}

int main()
{
    vector<pair<int, int>> vec = {{1, 2}, {4, 5}, {0, 3}, {1, 1}};
    sort(vec.begin(), vec.end(), mycomparator);
    for(auto ele : vec)
        cout<<ele.first << "  "<<ele.second<<"  "<<endl;
    return 0;
}
// Output
0  3  
1  2  
1  1  
4  5  

#include<bits/stdc++.h>
using namespace std;

// sort on the basis of the first element if smae then on the basis of the second element
bool mycomparator(pair<int, int> a, pair<int, int> b)
{
    if(a.first == b.first)
         if(a.second < b.second)
            return true;
    if(a.first < b.first)
        return true;
    return false;
}

int main()
{
    vector<pair<int, int>> vec = {{1, 2}, {4, 5}, {0, 3}, {1, 1}};
    sort(vec.begin(), vec.end(), mycomparator);
    for(auto ele : vec)
        cout<<ele.first << "  "<<ele.second<<"  "<<endl;
    return 0;
}
