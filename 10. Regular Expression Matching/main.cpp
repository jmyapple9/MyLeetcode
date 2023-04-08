#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        bool DP[21][21]; // initialize all as false
        for(int i = 0; i < 21; i++)
            for(int j = 0; j < 21; j++)
                DP[i][j] = 0;

        DP[0][0] = true;
        // all p = #*#*#*#*#*#*#* can match empty string
        for(int j = 2; j<=p.size(); j+=2){ 
            if(p[j-1]=='*' && DP[0][j-2])
                DP[0][j] = true;
        }

        for(int i = 1; i<=s.size(); i++){
            for(int j = 1; j<=p.size(); j++){
                if(s[i-1] == p[j-1] || p[j-1]=='.') // literally
                    DP[i][j] = DP[i-1][j-1];
                else if(p[j-1]=='*'){
                    if(p[j-2]!='.' && s[i-1] != p[j-2])             // ex: #####a
                        DP[i][j] = DP[i][j-2];// count b* as empty  //      ###b*
                    else                                            // ex: #####a
                        DP[i][j] = DP[i][j-2] | DP[i-1][j];         //     ###a*
                        // DP[i][j-2]: count a* as empty
                        // DP[i-1][j]: count a* as 1 or more

                }
            }    
        }
        return DP[s.size()][p.size()];
    }
};

int main(){
    Solution sol;
    string s = "aaaaaaaa", p = ".*..a*";
    cout<<sol.isMatch(s,p);
}