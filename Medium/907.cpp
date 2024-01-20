// https://leetcode.com/problems/sum-of-subarray-minimums/
class Solution 
{
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n = arr.size();
        stack<int>s1,s2;
        vector<int>next_smaller(n);
        vector<int>prev_smaller(n);

        for(int i=0; i<n; i++)
        {
            next_smaller[i]=n-i;
            prev_smaller[i]=i+1;
        }    

        for(int i=0; i<n; i++)
        {
            while(!s1.empty() && arr[i]<arr[s1.top()])
            {
                next_smaller[s1.top()] = i-s1.top();
                s1.pop();
            }
            s1.push(i);
        }    

        // Prev Smaller Element
         for(int i=n-1; i>=0; i--)
        {
            while(!s2.empty() && arr[i]<=arr[s2.top()])
            {
                prev_smaller[s2.top()] = s2.top()-i;
                s2.pop();
            }
            s2.push(i);
        }    

        long long ans = 0;
        int MOD = 1e9+7;
        for(int i=0; i<n; i++)
        {
          long int temp = arr[i] % MOD;
    temp = (temp * next_smaller[i]) % MOD;
    temp%=MOD;
    temp = (temp * prev_smaller[i]) % MOD;
    ans += temp;
    ans %= MOD;
        }
        return ans;

    }
};
