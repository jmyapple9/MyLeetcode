#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestPalindromeSubseq(string s){
        // vector<vector<int>> DP(s.size(), vector<int>(s.size()));
        int DP[s.size()][s.size()];
        for (int r = 0; r < s.size(); r++){   
            for (int l = r; l>=0; l--){
                if (r - l == 0)
                    DP[l][r] = 1;
                else if (s[l] == s[r])
                    DP[l][r] = DP[l + 1][r - 1] + 2;
                else
                    DP[l][r] = max(DP[l + 1][r], DP[l][r - 1]);
            }
        }
        return DP[0][s.size()-1];
    }

    // the following code can't be run on local (2d array too large)
    // but it can be run on leetcode (AC code)

    /* int memo[1000][1000];
    int longestPalindromeSubseq(string s){
        return solve(s,0,s.size()-1);
    }
    int solve(string& s, int l, int r){
        if(l > r) return 0;
        if(l==r) return 1;
        if(memo[l][r]!=0) return memo[l][r];
        if(s[l]==s[r])
            return memo[l][r]= solve(s, l+1, r-1) + 2;
        return memo[l][r] = max(solve(s, l, r-1), solve(s,l+1,r));
    } */
};

int main()
{
    Solution sol;
    // string s = "bbbab";
    // string s = "cbbd";
    // string s = "aabbbabba";
    // string s = "euazbipzncptldueeuechubrcourfpftcebikrxhybkymimgvldiwqvkszfycvqyvtiwfckexmowcxztkfyzqovbtmzpxojfofbvwnncajvrvdbvjhcrameamcfmcoxryjukhpljwszknhiypvyskmsujkuggpztltpgoczafmfelahqwjbhxtjmebnymdyxoeodqmvkxittxjnlltmoobsgzdfhismogqfpfhvqnxeuosjqqalvwhsidgiavcatjjgeztrjuoixxxoznklcxolgpuktirmduxdywwlbikaqkqajzbsjvdgjcnbtfksqhquiwnwflkldgdrqrnwmshdpykicozfowmumzeuznolmgjlltypyufpzjpuvucmesnnrwppheizkapovoloneaxpfinaontwtdqsdvzmqlgkdxlbeguackbdkftzbnynmcejtwudocemcfnuzbttcoew";
    cout << sol.longestPalindromeSubseq(s);
}