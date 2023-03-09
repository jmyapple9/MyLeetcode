#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x==0 || x==-2147483648) return 0;
        
        int sign = 1;
        int arr[10] = {0};
        int len = 0;
        if(x<0) sign = -1, x*=-1;
        for(int i = 0; i<9; i++){
            arr[i] = x%10;
            x/=10;
            if(x==0){
                len = i;
                break;
            }
        }
        if(x>0) 
            arr[9] = x, len = 9;

        int n = 0;
        for(int d = 1, i = len; i>0; i--, d*=10) n += arr[i]*d;
        if(((n>147483647 && arr[0]==2) || arr[0]>2) && len==9) return 0;
        if(arr[0]!=0) n+=arr[0]*(int)pow(10,len);
        return n*sign;
    }
};

int main(){
    // int x = 1000000009; // reverse would overflow, should return 0
    // int x = -1000000009; // reverse would overflow, should return 0
    // int x = -2147483647; 
    // int x = 2147483647; // 2^31-1
    int x = -2147483648; //-2^31
    // int x = -2147483641;
    // int x = 2147483641;
    // int x = 1000000003;
    // int x = 120;
    // int x = -123;
    Solution sol;
    cout<<sol.reverse(x);
}