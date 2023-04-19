#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int n1 = word1.size();
        int n2 = word2.size();
        int l1 = 0, l2 = 0;
        while(l1<n1 && l2<n2){
            ans.push_back(word1[l1++]);
            ans.push_back(word2[l2++]);
        }
        while(l1<n1) 
                ans.push_back(word1[l1++]);
        while(l2<n2) 
                ans.push_back(word2[l2++]);
        return ans;
    }
};
int main(){
    
}