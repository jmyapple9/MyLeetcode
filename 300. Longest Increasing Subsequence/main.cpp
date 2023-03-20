#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // int lengthOfLIS(vector<int>& v) { // n^2 solution
    //     int ans = 0;
    //     vector<int> DP(v.size());
    //     for(int i = 0; i<v.size();i++){
    //         DP[i] = 0;
    //         for(int j =0; j<i; j++){
    //             if(v[i]>v[j])
    //                 DP[i] = max(DP[i],DP[j]);
    //         }
    //         DP[i]++;
    //         ans = max(ans,DP[i]);
    //     }
    //     return ans;
    // }

    int lengthOfLIS(vector<int>& s) { // nlogn solution
        if(s.size()==0) return 0;
        vector<int> v;
        v.emplace_back(s[0]);
        for(int i = 1; i<s.size(); i++){
            if(s[i]>v.back()) v.emplace_back(s[i]);
            else *lower_bound(v.begin(),v.end(),s[i]) = s[i];
        }
        return v.size();
    }
};

int main(){
    Solution sol;
    // vector<int> v = {10,9,2,5,3,7,101,18};
    // vector<int> v = {0,1,0,3,2,3};
    // vector<int> v = {7,7,7,7,7,7};
    vector<int> v = {-7, 10, 9, 2, 3, 8, 8, 1};
    cout<<sol.lengthOfLIS(v)<<endl;
}