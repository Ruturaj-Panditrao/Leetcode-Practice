

class Solution 
{
public:

    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
       vector<int>curr(n+1,0);
       vector<int>next(n+1,0);
        // return f(0,-1,nums,dp);    

        for(int index=n-1; index>=0; index--)
        {
            for(int prevIndex = index-1; prevIndex>=-1; prevIndex--)
            {
                int len = 0+next[prevIndex+1];
            if(prevIndex==-1 || nums[index]>nums[prevIndex])
                {
                    len = max(len,1+next[index+1]);
                }  

                curr[prevIndex+1]=len; 
            }

           next = curr;
        }

        return curr[0];
    }

};
