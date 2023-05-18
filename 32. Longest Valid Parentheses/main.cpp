#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
class Solution { // O(n), other's solution
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int maxlen = 0;

        for(int i = 0 ;i<s.size();i++){
            if(s[i] == '(') st.push(i);
            else{
                st.pop();
                if(st.empty()) st.push(i);
                else {
                    int len = i - st.top();
                    maxlen = max(len, maxlen);
                }
            }
        }
        return maxlen;
    }
};

class Solution2 { // O(n^2), my solution
public:
    int n;
    int longestValidParentheses(string s) {
        n = s.size();
        int ans = 0;
        for(int l = 0; l<n-1 ; l++){
            if(s[l]!='(') continue;
            if(ans>=n-l) break;
            int tmp = valid(s, l);
            ans = max(tmp, ans);
            l+=tmp;
        }
        return ans;
    }
    int valid(string &s, int l){
        int left=0, right=0;
        int last_valid = l-1;
        int cnti_cnt = 0;
        int ans = 0;
        for(int i = l; i<n && right<=left; i++){
            (s[i]=='(') ? left++ : right++; 

            if(left==right){
                cnti_cnt += left;
                ans = max(ans, cnti_cnt);
                if(last_valid != i-left-right){
                    cnti_cnt = 1;
                }
                
                left = right = 0;
                last_valid = i;
            }
        }
        return ans>0 ? ans<<1 : 0;
    }
};

int main(){
    Solution sol;
    vector<string> v = {
        "(()", // 2
        ")()())", // 4
        "", // 0
        "()(()", // 2
        "((())))()())))(((()()(())))((()(())", // 12
        "((()))())", // 8
        ")(())(()()))(" // 10
    };
    for(auto s:v){
        cout<<sol.longestValidParentheses(s)<<endl;
    }
}