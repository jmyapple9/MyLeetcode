#include<iostream>
#include<vector>
using namespace std;
typedef long long ll; // reference others code
class Solution {
public:
    int n;
    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        ll DP[n+1];
        DP[n] = 0;
        for(int i = n-1; i>=0; i--){
            int points = questions[i][0];
            int power = questions[i][1];
            int jump = min(n, power+i+1);
            DP[i] = max(DP[i+1], points + DP[jump]); 
            //    = max(not take, take)
        }
        return DP[0];
    }
    
};
int main(){
    Solution sol;
    vector<vector<int>> arr{
        // {3,2},{4,3},{4,4},{2,5}
        {1,1},{2,2},{3,3},{4,4},{5,5}
    };
    cout<<sol.mostPoints(arr);
}