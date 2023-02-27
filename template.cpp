#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
    	if(height.size() <= 1) {
    		return 0;
    	}
    	int left = 0;
    	int right = height.size()-1;
    	int water = 0 ;
    	int h = 0;
    	while(left < right) {
    		h = min(height.at(left),height.at(right));
    		water = max(water, (right-left)*h);
    		while(height.at(left)<=h && left<right) {
    			left++;
    		}
    		while(height.at(right)<=h && left<right) {
    			right--;
    		}

    	}
    	return water;
    }
};

#if 1
int main() {

	Solution sol;
	int arr[] = {1,8,6,2,5,4,8,3,7};
	std::vector<int> v(arr,arr+sizeof(arr)/sizeof(int));
	int ret = sol.maxArea(v);
	cout<<ret<<endl;
	return 0;
}
#endif