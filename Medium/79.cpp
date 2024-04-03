// https://leetcode.com/problems/word-search/

class Solution {
public:
    bool solve(int i, int j, vector<vector<char>>&board, 
    vector<vector<int>>&visited,int ptr, string &word)
    {
        
        if(i>=board.size() || j>=board[i].size() || i<0 || j<0 || 
        visited[i][j]==1 || board[i][j]!=word[ptr])
        {
            return false;
        }

        if(ptr==word.length()-1)
        {
            return true;
        }
        visited[i][j]=1;
           bool found = 
            solve(i+1,j,board,visited,ptr+1,word) ||
            solve(i-1,j,board,visited,ptr+1,word) ||
            solve(i,j+1,board,visited,ptr+1,word) ||
            solve(i,j-1,board,visited,ptr+1,word);
        visited[i][j] = 0;

        return found;
        }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));

        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[i].size(); j++)
            {
                if(board[i][j]==word[0])
                {
                     if (solve(i,j,board,visited,0,word)) return true;
                }
            }
        }
        return false;
    }
};
