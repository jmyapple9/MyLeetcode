#include<iostream>
#include<string>
using namespace std;
bool DP[21][21];
class Solution {
public:
    bool isMatch(string s, string p) {
        char prev_p = '\0';
        bool star = false;
        DP[1][1] = true;
        if(s[0] != p[0] && p[0] != '.') return false;

        for(int j = 1; j<=p.size(); j++){
            for(int i = 1; i<=s.size(); i++){
                // if(s[i]==p[j] || p[j]=='.') DP[i][j] = DP[i-1][j-1];
                // else DP[i][j] = DP[i][j-1] || DP[i-1][j];
                if (p[j]=='*'){
                    star = true;
                } // s=aa, p=a*
                if(s[i-1]==p[j-1]){
                    DP[i+1][j] = DP[i][j];
                    prev_p = s[i];
                    star = false;
                }
                else if (star && prev_p==s[i]){
                    DP[i][j+1] = DP[i][j];
                }
                else{
                    DP[i][j] = false;
                }
                if(i==s.size()) prev_p = p[j-1];
                cout<<"i="<<i<<", j="<<j<<", star="<<star<<", DP[i][j]="<<DP[i][j]<<endl;
            }    
        }
        return DP[s.size()][p.size()];
        
    }
};

int main(){
    Solution sol;
    string s = "aaa", p = "a*";
    cout<<sol.isMatch(s,p);
}

/*

    0 1 2 3
      b a a
0   0 0 0 0
1 b 0 1 0 0
2 a 0 0 1 0
3 * 0 1 1 1

    0 1 2 3
      b a a
0   0 0 0 0
1 b 0 b 0 0
2 a 0 0 a 0
3 * 0 b 1 1


*/