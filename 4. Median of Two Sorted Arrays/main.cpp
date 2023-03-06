#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int n = nums1.size();
    //     int m = nums2.size();
    //     int totalLen = n+m;
    //     int mid = totalLen/2;
    //     int i,j,k; 
    //     vector<int> all(totalLen,0);
        
    //     // merge two sorted vector, like in mergeSort
    //     i = j = k = 0;
    //     while(i<n && j<m)
    //         all[k++] = (nums1[i]<nums2[j])? nums1[i++] : nums2[j++];
    //     while(i<n)
    //         all[k++] = nums1[i++];
    //     while(j<m)
    //         all[k++] = nums2[j++];

    //     // for(int u:all) cout<<u<<' ';
    //     // cout<<endl;

    //     if(totalLen%2) // if total length is odd
    //         return all[mid];
    //     else
    //         return (all[mid] + all[mid-1])/2.0;
    // }
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int Alen = A.size(), Blen = B.size();
        if(Alen>Blen) return findMedianSortedArrays(B, A); // require length: A < B
        
        int l = 0, r = Alen; // only need to check the
        int half = (Alen + Blen) / 2;

        while(1){
            // cout<<'?';
            int Apivot = (l + r) / 2; // take all element on left of Apivot from A
            int Bpivot =  (Alen + Blen + 1)/2 - Apivot;
            
            int Aleft  = (Apivot>0)?A[Apivot-1]:INT_MIN; // 2
            int Aright = (Apivot < Alen)?A[Apivot]:INT_MAX; // inf
            int Bleft  = (Bpivot>0)?B[Bpivot-1]:INT_MIN; // -inf
            int Bright = (Bpivot < Blen)?B[Bpivot]:INT_MAX; //

            if(Aleft <= Bright && Bleft <= Aright){ // find partition !
                // if((Alen + Blen)%2) return max(Aleft, Bleft); // total length: odd
                if((Alen + Blen)%2) return max(Aleft, Bleft); // total length: odd
                else return (min(Aright, Bright) + max(Aleft, Bleft)) / 2.0;
            }
            else if(Aleft > Bright) // adjust r, l by binary search
                r = Apivot - 1;
            else
                l = Apivot + 1;
        }
    }
};

int main(){
    Solution sol;
    // vector<int> u={1,2},v={3,4};
    vector<int> u={1,3},v={2};
    cout<<sol.findMedianSortedArrays(u,v);
    
}
