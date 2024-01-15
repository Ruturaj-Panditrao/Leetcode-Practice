// https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& mat) {
        map<int,int> mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                mp[mat[i][j]]+=j;
            }
        }
        vector<vector<int>> ans(2);
        for(auto i:mp){
            if(i.second==0)ans[0].push_back(i.first);
            else if(i.second==1)ans[1].push_back(i.first);
        }
        return ans;
    }
};
