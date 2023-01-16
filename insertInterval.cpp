class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> vec;
        if(n==0)
        {
            vec.push_back(newInterval);
            return vec;
        }
        int i =0;
        int x = newInterval[0];
        int y = newInterval[1];
        while(i< n && intervals[i][1] < x)
            {
                vec.push_back(intervals[i]);
                i++;
            }
        if(i == n)
        {
            vec.push_back(newInterval);
            return vec;
        }
        int a = min(intervals[i][0],newInterval[0]);
        while(i<n && intervals[i][1] < y)
            {
                i++;
            }
        if(i<n && intervals[i][0] <= y)
            {
                vec.push_back({a,intervals[i][1]});
                i++;
            }
        else{
                vec.push_back({a,y});
            }
        while(i<n)
            {
                vec.push_back(intervals[i]);
                i++;
            }

        return vec;

    }
};