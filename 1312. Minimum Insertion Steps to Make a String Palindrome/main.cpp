#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int minInsertions(string s) {
        int l = 0, r = s.size()-1;
        int ans = 0;
        while(l<r){
            if(s[l]!=s[r]) s.insert(r+1, 1, s[l++]), ans++;
            else r--, l++;
            // cout<<s<<endl;
        }
        return ans;
    }
};
int main(){
    Solution sol;
    string s = "zjveiiwvc"; // ans=5
    cout<<sol.minInsertions(s)<<endl;
}

// zjcvweiiewvcjz
// zjveiiwvcjz