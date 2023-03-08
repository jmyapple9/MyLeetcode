#include<iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n =s.size(), k = 0, idx = 0;;
        if(n==1 || numRows==1 || n<=numRows) return s;

        string ans (n, '?');
        int w = 2*(numRows-1);

        for(int i = 0;i<numRows;i++){
            int off = 2*(numRows-1-i);
            idx = i;
            while(idx<n){
                ans[k++] = s[idx];
                if(off==0) off = w;
                if(idx+off<n){
                    idx+=off;
                }else break;
                off = (w - off)>0?(w-off): w;
            }
        }
        return ans;
    }
};



int main(){
    //          01234567890123
    string s = "A";
    //          PINALSIGYAHRPI
    //    ans = PINALSIGYAHRPI
    int numRow = 1;
    Solution sol;
    // cout<<s<<endl;
    cout<<sol.convert(s, numRow);
}