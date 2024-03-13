// https://leetcode.com/problems/find-the-pivot-integer/
class Solution {
public:
    int pivotInteger(int n) 
    {
        int answer = -1;
        int required = ((n)*(n+1))/2;
        
        for(int i=0; i<=n; i++)
        {
            if(pow(i,2) == required)
            {
                answer = i;
                break;
            }
        }
        return answer;
    }
};
