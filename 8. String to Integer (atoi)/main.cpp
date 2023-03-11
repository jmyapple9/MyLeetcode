#include<iostream>
#include<climits>
using namespace std;
/* 
// My code: failed !
class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int seenNum = 0;
        long long ans=0;
        // for(char ch:s){
        for(int i = 0; i < s.size();i++){
            char ch = s[i];
            if(ch == ' ') continue;
            if('0'<=ch && ch <='9'){
                seenNum = 1;
                ans = ans*10 + (ch-'0');
            }
            else if(ch == '-' && '0'<=s[i+1] && s[i+1] <='9' && seenNum==0) sign = -1;
            else if(ch == '+' && '0'<=s[i+1] && s[i+1] <='9' && seenNum==0) sign = 1;
            else break;
        }
        // cout<<((sign==1)?'':'-');
        // if(sign==-1) cout<<'-';
        // cout<<endl;
        ans*=sign;
        if(ans>INT_MAX) return INT_MAX;
        else if(ans<INT_MIN) return INT_MIN;
        else return ans;
        // return ();
    }
}; */

// Other's code
class Solution {
public:
    int myAtoi(string s) {
        int len = s.size();
        double num = 0;
        int i=0;
        while(s[i] == ' '){
            i++;
        }
        bool positive = s[i] == '+';
        bool negative = s[i] == '-';
        positive == true ? i++ : i;
        negative == true ? i++ : i;
        while(i < len && s[i] >= '0' && s[i] <= '9'){
            num = num*10 + (s[i]-'0');
            i++;
        }
        num = negative ? -num : num;
        cout<<num<<endl;
        num = (num > INT_MAX) ? INT_MAX : num;
        num = (num < INT_MIN) ? INT_MIN : num;
        cout<<num<<endl;
        return int(num);
    }
};
int main(){
    Solution sol;
    // string s = "-1123u3761867";
    // string s = "   -42";
    // string s = "4193 with words";
    // string s = "words and 987";
    // string s = "2147483648";
    string s = "+-12";
    // cout<<endl;
    cout<<sol.myAtoi(s);
}