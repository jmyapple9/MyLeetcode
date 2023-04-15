#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4) return vector<vector<int>> {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int prev = INT_MAX;
        for(int h = 0; h<nums.size()-3; h++){
            if(nums[h]==prev)  // Only check unique first numbers
                continue;
            prev = nums[h];
            threeSum(nums,ans,target - nums[h],h);
        }
        return ans;

    }
    void threeSum(vector<int>& nums, vector<vector<int>>& ans, long goal, int h) {

        int prev = -1000000009;
        for (int i = h+1; i < nums.size(); ++i) {
            if (nums[i] == prev) // Only check unique first numbers
                continue; 
            prev = nums[i];

            long target = goal - nums[i];

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int s = nums[j] + nums[k];
                if (s == target) {
                    ans.push_back({nums[h],nums[i],nums[j++],nums[k--]});
                    while (j < k && nums[k] == nums[k+1])
                        k--;
                }
                else if (s < target)
                    ++j;
                else
                    --k;
            }
        }
    }
};

    
int main(){
    
}