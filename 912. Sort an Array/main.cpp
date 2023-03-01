#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
public:
    vector<int> nums;
    vector<int> sortArray(vector<int>& V) {
        nums = V;
        Mergesort(0, nums.size()-1);
        return nums;
    }
    void Mergesort(int L, int R){
        if(L>=R) return;
        int mid = (R + L)/2;
        Mergesort(L, mid);
        Mergesort(mid+1, R);
        
        int size= R-L+1;
        vector<int> tmp(size, 0);
        int i=L, j=mid+1, k=0;
        
        while((i<=mid) && (j<=R)){
            if(nums[i]<nums[j])
                tmp[k++] = nums[i++];
            else
                tmp[k++] = nums[j++];
        }
        while(i<=mid)
            tmp[k++]=nums[i++];
        while(j<=R)
            tmp[k++]=nums[j++];
        for(i=0;i<size;i++)
            nums[i+L] = tmp[i];
        
    }
    
};

int main(void){
    vector<int> v = {-1,0,-43,5,-1,5,100,54};
    // vector<int> v = {7,2,4,7};
    Solution sol;
    for(int u:sol.sortArray(v)){
        cout<<u<<' ';
    }
}