// https://leetcode.com/problems/determine-if-string-halves-are-alike/

class Solution {
public:
bool halvesAreAlike(string s) {
string str="aeiouAEIOU";
int c=0,i=0,n=s.size(),mid=n/2;
while(i<mid){
c+=count(str.begin(), str.end(),s[i]);
i++;
}
while(i<n){
c-=count(str.begin(), str.end(),s[i]);
i++;
}
if(c==0)
return 1;
return 0;
}
};

