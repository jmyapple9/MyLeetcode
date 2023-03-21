#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        // vector<vector<int>> DP(s.size(), vector<int>(s.size(), 0));
        vector<vector<int>> DP(s.size(), vector<int>(s.size()));
        // int DP[s.size()][s.size()];
        // for(int i = 0; i < s.size(); i++) for(int j = 0; j < s.size(); j++)
        //     DP[i][j] = 0;
        int ans = 0;
        for (int r = 0; r < s.size(); r++)
        {   
            for (int l = r; l>=0; l--)
            {
                if (r - l == 0)
                    DP[l][r] = 1;
                else if (s[l] == s[r])
                    DP[l][r] = DP[l + 1][r - 1] + 2;
                else
                    DP[l][r] = max(DP[l + 1][r], DP[l][r - 1]);
                ans = max(ans, DP[l][r]);
            }
        }
        return DP[0][s.size()-1];
        // cout<<DP[0][s.size()-1]<<endl;
        // return ans;
    }
};

int main()
{
    Solution sol;
    // string s = "bbbab";
    // string s = "cbbd";
    // string s = "aabbbabba";
    string s = "euazbipzncptldueeuechubrcourfpftcebikrxhybkymimgvldiwqvkszfycvqyvtiwfckexmowcxztkfyzqovbtmzpxojfofbvwnncajvrvdbvjhcrameamcfmcoxryjukhpljwszknhiypvyskmsujkuggpztltpgoczafmfelahqwjbhxtjmebnymdyxoeodqmvkxittxjnlltmoobsgzdfhismogqfpfhvqnxeuosjqqalvwhsidgiavcatjjgeztrjuoixxxoznklcxolgpuktirmduxdywwlbikaqkqajzbsjvdgjcnbtfksqhquiwnwflkldgdrqrnwmshdpykicozfowmumzeuznolmgjlltypyufpzjpuvucmesnnrwppheizkapovoloneaxpfinaontwtdqsdvzmqlgkdxlbeguackbdkftzbnynmcejtwudocemcfnuzbttcoew";
    cout << sol.longestPalindromeSubseq(s);
}