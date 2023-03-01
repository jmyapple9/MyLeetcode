#include<iostream>
#include<set>
#include<string>
#include<unordered_map>
#include<unordered_set>
// #include<multiset>
// #define max(a,b) ((a>b)?(a):(b))
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0, n = s.length();
        multiset<char> bucket;
        for(int start=0;start<n-maxlen;start++){
            for(int end=start;end<n;end++){
                char c = s[end];
                
                if(bucket.find(c)==bucket.end()){ 
                    bucket.insert(c);
                    maxlen = max(maxlen, end-start+1); 
                }
                else{
                    bucket.insert(c);
                    bucket.clear();
                    start = s.substr(start,end-start+1).find(c)+start;
                    break;
                }
            }
        }
        return maxlen;
    }
};

/* class Solution{
public:
    int lengthOfLongestSubstring(string s){
        int n = s.length();
        int i = 0, j = 0, max_len = 0;
        unordered_set<char> seen;

        while (i < n && j < n) {
            if (seen.find(s[j]) == seen.end()) {
                seen.insert(s[j]);
                j++;
                max_len = max(max_len, j - i);
            } else {
                seen.erase(s[i]);
                i++;
            }
        }

        return max_len;
    }
}; */
int main(){
    Solution sol;
    cout<<sol.lengthOfLongestSubstring("1 344 .qm0   ");
}

/* 

dp[i][j] = 
 */