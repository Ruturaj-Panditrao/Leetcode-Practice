// https://leetcode.com/problems/perfect-squares/description/

class Solution {
public:
    int numSquares(int n) {
        int arr[n + 1];
        arr[0] = 0;
        arr[1] = 1;

        for(int i = 2; i <= n; i++){
            int minV = INT_MAX;
            for(int j = 1; j * j <= i; j++){
                int rem = i - j * j;
                if(arr[rem] < minV){
                    minV = arr[rem];
                }
            }
            arr[i] = minV + 1;
        }
        return arr[n];
    }
};
