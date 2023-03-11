#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long y = 0;
        int n = x;
        while(n){
            y = y*10 + n%10;
            n/=10;
        }
        return x==y;
    }
};
int main(){
    Solution sol;
    int n = 121;
    cout<<sol.isPalindrome(n);
}