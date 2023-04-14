#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

// class Solution2 {
// private:
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> v;
//         set<vector<int>> s;
//         sort(nums.begin(), nums.end()); // sort O(nlgn)

//         int same = 1;
//         int idx = 1;
//         // nums.emplace_back(old[0]);
//         for(int i = 1; i<n; i++){ // if a same number exist more than 3 times, remove it. O(n)
//             if(nums[i]==nums[i-1]){
//                 if(++same==3){
//                     while(i<n && nums[i]==nums[i-1]){
//                         i++;
//                     }
//                     i--;
//                 }
//             } 
//             else same = 1;
//             nums[idx++] = nums[i];
//         }
//         n = idx;
//         int table[n][n];

//         for(int i = 0 ; i<n ; i++) // store two sums O(n^2)
//             for(int j = 0 ; j<n ; j++)
//                 table[i][j] = nums[i] + nums[j];
        
//         for(int i = 0 ; i<n ; i++){ // push triples into set O(n^2lgn)
//             for(int j = 0 ; j<n ; j++){
//                 int k = bs(nums,-table[i][j], 0, n-1);
//                 if(k!=-1 && i!=j && j!=k && i!=k){
//                     vector<int> u = {nums[i], nums[j], nums[k]};
//                     sort(u.begin(), u.end());
//                     s.emplace(u);
//                 }
//             }
//         }
//         for(auto u: s)  // puts items into vector O(nlgn)
//             v.emplace_back(u);

//         return v;
//     }
//     int bs(vector<int>& nums, int tar, int l, int r){
//         if(l>r) return -1;
//         int mid = (l + r)/2;
//         if(tar==nums[mid]) return mid;
//         else if(tar>nums[mid]) 
//             return bs(nums, tar, mid+1, r);
//         else
//             return bs(nums, tar, l, mid-1);
//     }
// };

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::sort(nums.begin(), nums.end());

        int prev = -1 * INT_MAX;
        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i) {
            // Only check unique first numbers
            if (nums[i] == prev) continue;
            prev = nums[i];

            int target = 0 - nums[i];

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int s = nums[j] + nums[k];
                if (s == target) {
                    ans.push_back({nums[i],nums[j++],nums[k--]});
                    while (j < k && nums[j] == nums[j - 1])
                        ++j;
                }
                else if (s < target)
                    ++j;
                else
                    --k;
            }
        }
        
        return ans;
    }
};

int main(){
    Solution sol;
    // vector<int> v = {0,0,0};
    // vector<int> v = {0,1,1};
    vector<int> v = {3,0,-2,-1,1,2};
    // vector<int> v = {-1,0,1,2,-1,-4};
    // vector<int> v = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    // cout<<v.size()<<endl;
    vector<vector<int>>ans=sol.threeSum(v);
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
}