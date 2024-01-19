// https://leetcode.com/problems/minimum-falling-path-sum/description/

// Recursive/ Memoized
class Solution {
public:
    long long int f(long long int row, long long int col, vector<vector<int>>& matrix, vector<vector<long long int>>& dp) {
        long long int n = matrix.size();
        if (dp[row][col] != 1e9 && dp[row][col] != LLONG_MAX) return dp[row][col];
        else if (col < 0 || col >= n || row < 0 || row >= n) return LLONG_MAX;
        else if (row == n - 1 && col >= 0 && col < n) return matrix[row][col];

        long long int c1 = (col - 1 >= 0) ? f(row + 1, col - 1, matrix, dp) : LLONG_MAX;
        long long int c2 = f(row + 1, col, matrix, dp);
        long long int c3 = (col + 1 < n) ? f(row + 1, col + 1, matrix, dp) : LLONG_MAX;

        // Ensure the indices are within bounds before accessing dp array
        if (col >= 0 && col < n) {
            dp[row][col] = matrix[row][col] + min(min(c1, c2), c3);
        }

        return dp[row][col];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        long long int curr = LLONG_MAX;
        long long int n = matrix.size();
        vector<vector<long long int>> dp(n, vector<long long int>(n, 1e9));
        for (long long int i = 0; i < n; i++) {
            curr = min(curr, f(0, i, matrix, dp));
        }

        return static_cast<int>(curr == LLONG_MAX ? 0 : curr);
    }
};

// Tabulation
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int i=0; i<n; i++)
        {
            dp[0][i] = matrix[0][i];
        }

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int left = matrix[i][j];
                if(j-1>=0) left+=dp[i-1][j-1];
                else left+=1e8;

                int right = matrix[i][j];
                if(j+1<n) right+=dp[i-1][j+1];
                else right+=1e8;

                int up = matrix[i][j];
                if(i-1>=0) up+=dp[i-1][j];
                else up+=1e8;

                dp[i][j] = min(up,min(left,right));
            }
        }

        int ans = 1e8;
        for(int i=0; i<n; i++)
        {
            ans = min(ans,dp[n-1][i]);
        }

        return ans;
    }
};
