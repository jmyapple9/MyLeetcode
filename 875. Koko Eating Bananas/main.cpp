#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int kl = 1, kr = *max_element(piles.begin(), piles.end());
        while(kl < kr){
            int k = (kl+kr)/2;
            int pilesWhenK = 0;
            for(int i = 0; i<piles.size(); i++)
                pilesWhenK += (piles[i]+k-1)/k;
            if(pilesWhenK < h) kr = k;
            else if(pilesWhenK > h) kl = k + 1;
            else kr = (kl+kr)/2;
        }
        return kl;
    }
};


int main(){
    // vector<int> piles = {30,11,23,4,20};
    // int h = 6;
    vector<int> piles = {3,6,7,11};
    int h = 8;
    // vector<int> piles = {1000000000};
    // int h = 2;
    Solution sol;
    cout<<sol.minEatingSpeed(piles, h);
}