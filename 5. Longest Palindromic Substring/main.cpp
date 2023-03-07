#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s){
        int n = s.size();
        if(n==1) return s;
        int maxLen = 1, limit;
        int base = 0;
        // check odd length
        for(int mid = 1; mid < n - 1; mid++){
            int curLen = 1;
            limit = min(mid, n-1-mid);
            for(int halfL = 1; halfL<=limit; halfL++){
                if(s[mid-halfL] == s[mid+halfL]){
                    curLen+=2;
                    if(curLen>maxLen){
                        maxLen = curLen;
                        base = mid - halfL;
                    }
                }
                else
                    break;
            }
        }
        // check even length
        for(int mid = 0; mid < n-1; mid++){
            int curLen = 0;
            limit = min(mid, n-1-mid);
            for(int halfL = 0; halfL<=limit; halfL++){
                if(s[mid-halfL] == s[mid+halfL+1]){
                    curLen+=2;
                    if(curLen>maxLen){
                        maxLen = curLen;
                        base = mid - halfL;
                    }
                }
                else
                    break;
            }
        }
        return s.substr(base, maxLen);
    }
};

int main(){
    string s = "babad";
    // string s = "aacabdkacaa";
    // string s = "abcdbbfcba";
    // string s = "aa";
    // string s = "cbbd";
    // string s = "c";
    Solution sol;
    cout<<sol.longestPalindrome(s);
}