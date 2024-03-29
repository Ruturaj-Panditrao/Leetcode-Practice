// https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> retInter;
        int i=0;
        while(i<intervals.size() && intervals[i][1]<newInterval[0])
            retInter.push_back(intervals[i++]);
        while(i<intervals.size() && intervals[i][0]<=newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i++][1]);
        }
        retInter.push_back(newInterval);
        for(; i<intervals.size(); i++)
                retInter.push_back(intervals[i]);
        return retInter;
    }
};
