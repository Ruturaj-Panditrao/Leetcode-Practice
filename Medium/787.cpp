// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

class Solution {
public:
long long helper(vector<vector<pair<int,int>>> &v,int src,int dst,int k,vector<vector<int>> &dp){
    if(src==dst){
        return 0;
    }
    if(k<0){
        return INT_MAX;
    }
    if(dp[src][k]!=-1){
        return dp[src][k];
    }
    long long ans=INT_MAX;
    for(int i=0;i<v[src].size();++i){
            ans=min(ans,v[src][i].second+helper(v,v[src][i].first,dst,k-1,dp));
    }
    return dp[src][k]=ans;
}
    int findCheapestPrice(int n, vector<vector<int>>& flight, int src, int dst, int k) {
        vector<vector<pair<int,int>>> v(n,vector<pair<int,int>>());
        vector<bool> visited(n,false);
        for(int i=0;i<flight.size();++i){
            v[flight[i][0]].push_back({flight[i][1],flight[i][2]});
        }
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        long long ans=helper(v,src,dst,k,dp);
        if(ans>=INT_MAX){
            return -1;
        }
        return ans;
    }
};
