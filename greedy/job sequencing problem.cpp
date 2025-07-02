int find(int num, vector<int>& parent)
    {
            if(num == parent[num])
                return num;
            
            return parent[num] = find(parent[num], parent);
    }

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // int n = deadline.size();
        // int maxDead = 0;
        // for (int i = 0; i < n; i++) {
        //     maxDead = max(maxDead, deadline[i]);
        // }

        // vector<int> mark(maxDead + 1, -1);  // time slots
        // vector<pair<int, int>> p;

        // for (int i = 0; i < n; i++) {
        //     p.push_back({profit[i], deadline[i]});
        // }

        // sort(p.begin(), p.end(), greater<>());  // sort by profit descending

        // int count = 0;
        // int maxProfit = 0;

        // for (int i = 0; i < n; i++) {
        //     int d = p[i].second;
        //     while (d > 0 && mark[d] != -1) {
        //         d--;
        //     }
        //     if (d == 0) continue;

        //     count++;
        //     maxProfit += p[i].first;
        //     mark[d] = p[i].first;
        // }

        // return {count, maxProfit};
        
        
        
        int n = deadline.size();
        vector<pair<int, int>> p;

        for (int i = 0; i < n; i++) {
            p.push_back({profit[i], deadline[i]});
        }

        sort(p.begin(), p.end(), greater<>());  // sort by profit descending
        
        int maxDead = 0;
        for (int i = 0; i < n; i++) {
            maxDead = max(maxDead, deadline[i]);
        }

        vector<int> parent(maxDead+1);
        
        for(int i = 0;i <= maxDead; i++)
        {
            parent[i] = i;
        }
        
        vector<int> ans(2, 0);
        
        //pick each task one by one
      
        for(int i = 0;i<n;i++)
        {
            int slot = find(p[i].second, parent);
            if(slot > 0)
            {
                ans[0]++;
                ans[1] += p[i].first;
                parent[slot] = slot-1;
            }
        }
        return ans;
    }
};
