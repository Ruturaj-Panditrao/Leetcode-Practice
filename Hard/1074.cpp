// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        // brute-force would be to check for all the submatrices if sum equals target then increment result
        // below is the optimized approach using prefix sums
        int n=matrix.size(), m=matrix[0].size();
        if(n<1) return 0;
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                matrix[i][j]=matrix[i][j]+matrix[i][j-1];
            }
        }
        int res=0, sum;
        unordered_map<int, int> mp;
        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                mp.clear();
                mp[0]=1;
                sum=0;
                for(int k=0;k<n;k++){
                    sum+=matrix[k][j]-(i>0 ? matrix[k][i-1] : 0);
                    res+=(mp.find(sum-target)!=mp.end() ? mp[sum-target] :0);
                    mp[sum]++;
                }
            }
        }
        return res;
    }
};
