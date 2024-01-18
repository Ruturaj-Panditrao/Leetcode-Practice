//https://leetcode.com/problems/climbing-stairs/description/

// Fibonacci // Space Optimized // TC = O(N) SC = O(1)
class Solution 
{
public:
    int climbStairs(int n) 
    {
        int fib1 = 1;
        int fib2 = 2;
        int temp = 0;
        if(n<=2) return n;
        for(int i=0; i<n-2; i++)
        {
            temp = fib1+fib2;
            fib1 = fib2;
            fib2 = temp;
        }
        return temp;
    }
};

// Memoized // TC =O(N) SC = O(N)+O(N) Auxilliary Stack Space
class Solution 
{
public:
    int f(int n, vector<int>&dp)
    {
        if(n==0) return 1;
        if(n==1) return 1;

        if(dp[n]!=-1) return dp[n];
        int step1 = f(n-1,dp);
        int step2 = f(n-2,dp);

        return dp[n] = step1 + step2;  
    }
    int climbStairs(int n)
    {
          vector<int>dp(n+1,-1);
          return f(n,dp);
    }
};

// Tablulation TC = O(N) SC = O(N)

class Solution 
{
public:
    int climbStairs(int n)
    {
          vector<int>dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++)
        {
            int step1 = dp[i-1];
            int step2 = dp[i-2];

            dp[i] = step1+step2;
        }
          return dp[n];
    }
};
