// https://leetcode.com/problems/maximum-profit-in-job-scheduling/

// class Solution 
// {
// public:

//     int f(int index, int currEnd, vector<int>&startTime, vector<int>&endTime, vector<int>&profit)
//     {
//         if(index>=profit.size()) return 0;

//         if(startTime[index]>=currEnd)
//         {
//             return max(profit[index]+f(index+1,endTime[index],startTime,endTime,profit),f(index+1,currEnd,startTime,endTime,profit));
//         }

//         else return f(index+1,currEnd,startTime,endTime,profit);
//     }

//     int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
//     {
        
//         return f(0,-1,startTime,endTime,profit);
//     }
// };

// This solution does not handle the necessary case such that the previous job selections are non-overlapping, we need to consider previous schedule as well.

class Solution 
{
public:

    int f(int index, vector<vector<int>>&jobs, vector<int>&startTime, vector<int>&dp)
    {
        if(index>=jobs.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int i = lower_bound(startTime.begin(),startTime.end(),jobs[index][1])-startTime.begin();
        // Find the next possible just equal or greater value of endtime than current start time

        // If you decide to pick this job, move to the next possible job that can picked after this
        // Also, since startTime has been sorted, it ensures that the previous selections do not overlap at any point of time.
        int pick = jobs[index][2]+f(i,jobs,startTime,dp);

        // Don't pick this job, then simply move 1 step ahead
        int npick = f(index+1,jobs,startTime,dp);

        return dp[index] = max(pick,npick);

    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        vector<vector<int>>jobs;
        for(int i=0; i<profit.size(); i++)
        {
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        sort(startTime.begin(),startTime.end());

        vector<int>dp(profit.size(),-1);
        // Only 1 changing variable is present
        return f(0,jobs,startTime,dp);
    }
};
