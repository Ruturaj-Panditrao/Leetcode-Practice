// https://leetcode.com/problems/furthest-building-you-can-reach/description/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        priority_queue<int> maxBricks; //stores bricks used in each step in decreasing order ( max at Top )
        
        int i=0, height_diff=0;
        
        //go until all bricks and ladders are used or reach at last building
        for(i=0; i<heights.size()-1; i++)
        {
            height_diff = heights[i+1]-heights[i];
            
            
            if(height_diff<=0) 
                continue;
            
            bricks -= height_diff; 
            maxBricks.push(height_diff); 
            
            if(bricks<0) 
            {
                bricks += maxBricks.top();
                maxBricks.pop();
                ladders--; 
            }
            
            if(ladders<0) 
                break;
        }
        return i;
    }
};
