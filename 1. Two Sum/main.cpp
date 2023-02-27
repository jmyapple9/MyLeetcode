#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // solution 1
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        unordered_map <int,int> umap;
        for(int i = 0; i<len; i++){
            int comp = target - nums[i];
            if(umap.count(comp)){
                return {umap[comp], i};
            }
            umap[nums[i]] = i;
        }

        return {};
    }
    // solution 2
    // vector<int> twoSum(vector<int> &nums, int target) {
    //     unordered_map<int, int> visited;
    //     int len = nums.size();
    //     for (int i = 0; i < len; ++i) {
    //         int n = nums[i];
    //         int complement = target - n;
    //         if (visited.count(complement)) {
    //             return {visited[complement], i};
    //         }
    //         visited[n] = i;  // assume that each input would have exactly one solution
    //     }
    //     return {};
    // }
};
#if 1
int main(){
    Solution sol;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    for(auto u:sol.twoSum(nums, target)){
        cout<<u<<' ';
    }
    // cout<<ans[0]<<' '<<ans[1]<<endl;
}
#endif