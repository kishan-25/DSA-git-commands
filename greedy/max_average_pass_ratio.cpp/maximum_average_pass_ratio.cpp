class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> maxh;
        // current pass ratio
        for(int i=0;i<classes.size();i++)
        {
            double curr_pass = (double)classes[i][0]/classes[i][1];
            double new_pass = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double diff = new_pass - curr_pass;
            maxh.push({diff, i});
        }
        while(extraStudents--)
        {
            auto curr = maxh.top();
            maxh.pop();

            double diff = curr.first;
            int idx = curr.second;

            classes[idx][0]++;
            classes[idx][1]++;

            double curr_pass = (double)classes[idx][0]/classes[idx][1];
            double new_pass = (double)(classes[idx][0]+1)/(classes[idx][1]+1);
            diff = new_pass - curr_pass;

            maxh.push({diff, idx});
        }
        double res = 0.0;
        for(int i=0;i<classes.size();i++)
        {
            res += (double)classes[i][0]/classes[i][1];
        }
        return res/classes.size();
    }
};