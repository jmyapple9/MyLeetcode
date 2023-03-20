#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int DP[text1.size()+1][text2.size()+1];

        DP[0][0] = 0; // remember to initialize !!!
        for(int i=1; i<=text1.size(); i++){
            DP[i][0] = 0; // initialize faster
            for(int j  = 1 ; j<=text2.size(); j++){
                DP[0][j] = 0; // initialize faster
                if(text1[i-1] == text2[j-1])
                    DP[i][j] = DP[i-1][j-1] + 1;
                else
                    DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }
        return DP[text1.size()][text2.size()];
    }
};

int main(){
    Solution sol;
    string text1 = "abcde", text2 = "ace";
    // string text1 = "abc", text2 = "abc";
    // string text1 = "abc", text2 = "def";
    // string text1 = "", text2 = "";
    cout<<sol.longestCommonSubsequence(text1,text2);
}