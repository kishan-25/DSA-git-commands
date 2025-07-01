

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool comp(pair<int, int> a, pair<int,int> b)
    {
        return a.second < b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int, int>> p;
        int n  = start.size();
        for(int i=0;i<n;i++)
        {
            p.push_back({start[i], end[i]});
        }
        sort(p.begin(), p.end(), comp);
        int total = 0;
        int ending = -1;
        for(int i=0;i<n;i++)
        {
            if(p[i].first > ending)
            {
                total++;
                ending = p[i].second;
            }
        }
        return total;
    }
};
