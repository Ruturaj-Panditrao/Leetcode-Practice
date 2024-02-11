// https://leetcode.com/problems/cherry-pickup-ii/

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> A(cols, vector<int>(cols));
        for(int i=0; i<cols; i++) for(int j=i; j<cols; j++)
            A[i][j] = grid[rows-1][i] + (i==j ? 0 : grid[rows-1][j]);
        for(int row=rows-2; row>=0; row--)
        {
            vector<vector<int>> temp(cols, vector<int>(cols));
            for(int i=0; i<cols; i++) for(int j=i; j<cols; j++)
            {
                int a = grid[row][i], b = grid[row][j];
                int cur = a + (i==j ? 0 : b);
                int nextRow = INT_MIN;
                for(int ii=max(i-1,0); ii<=min(i+1,cols-1); ii++)
                for(int jj=max(j-1,0); jj<=min(j+1,cols-1); jj++)
                    nextRow = max(nextRow, A[ii][jj]);
                temp[i][j] = nextRow + cur;
            }
            A = temp;
        }
        return A[0][cols-1];
    }
};
