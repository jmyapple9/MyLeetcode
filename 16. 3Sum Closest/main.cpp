#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = atMostThreeSameItem(nums);
        int prev = -1;
        int dist = INT_MAX;
        int ans = INT_MAX;

        for(int l = 0; l<n; l++){
            while(prev == l) l++;
            prev = l;
            int r = n-1;

            for(int m = l+1; m<r; ){
                int sum = nums[l] + nums[m] + nums[r];
                int D = sum - target;
                if(abs(D) < dist){
                    dist = abs(D);
                    ans = sum;
                }
                if(D<0)
                    m++;
                else if(D>0)
                    r--;
                else 
                    return ans;

            }
        }
        return ans;
    }
    int atMostThreeSameItem(vector<int>& nums){
        int same = 1;
        int idx = 1;
        int n = nums.size();
        for(int i = 1; i<n; i++){
            if(nums[i]==nums[i-1]){
                if(++same==3){
                    while(i<n && nums[i]==nums[i-1]){
                        i++;
                    }
                    i--;
                }
            } 
            else same = 1;
            nums[idx++] = nums[i];
        }
        return idx;
    }
};

int main(){
    
}