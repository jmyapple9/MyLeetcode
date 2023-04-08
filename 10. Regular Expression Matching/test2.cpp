#include<iostream>
#include<string>
#include<stack>
#include<iomanip>
using namespace std;

class Solution {
public:
    // bool isMatch(string s, string p) {
    //     stack<char> p_char;
    //     // ab*ccd*eeeefg
    //     for(int i = p.size()-1; i>=0;i--){
    //         if(p[i]!='*') {
    //             p_char.emplace(p[i]);
    //         }
    //         else{
    //             p_char.emplace(Upper(p[--i]));
    //         }
    //     }
    //     pourStack(p_char);
    //     return true;
    // }
    // void pourStack(stack<char> stk){
    //     while(!stk.empty()){
    //         cout<<stk.top()<<' ';
    //         stk.pop();
    //     }
    //     cout<<endl;
    // }
    // char Upper(char c){
    //     return c-32;
    // }
    bool isMatch(string s, string p) {
        int range[20][2];
        for(int i = 0 ; i < 20; i++){
            range[i][0]=1;
            range[i][1]=1;
        }
        char p_bucket[20];
        int idx = 0;
        p_bucket[0] = p[0];
        // p:      ab*ccdd*dddee
        // p_bucket: ab
        for(int i = 1; i < p.size(); i++){
            if(p[i]!='*'){
                if(p[i]==p_bucket[idx]){
                    range[idx][1]++;
                    range[idx][0]++;
                }
                else{
                    p_bucket[++idx] = p[i];
                }
            }else{
                range[idx][1] = 20;
                range[idx][0]--;
            }
        }
        int s_cnt[20];
        for(int i = 0; i<20; i++) s_cnt[i] = 1;
        char s_bucket[20];
        s_bucket[0] = s[0];
        int k = 0;
        for(int i = 1; i < s.size(); i++){
            if(s_bucket[k]==s[i]){
                s_cnt[k]++;
            }else{
                s_bucket[++k] = s[i];
            }
        }

        // compare s and p
        /* 
        aa.*aabb*
        aaaaaaaaaaaaabbb
         */
        // int j = 0;
        // for(int i = 0; i <= k ; i++){
        //     if(s_bucket[i] == p_bucket[j]){ // if char match
        //         if(s_cnt[i]<range[j][0] || s_cnt[i]>range[j][1]) // check ranges
        //             return false;
        //         j++;
        //     }else if(p_bucket[j]=='.'){
        //         if(s_cnt[i]<range[j][0] || s_cnt[i]>range[j][1]){
                    
        //         }
        //     }else{
        //         return false;
        //     }
        // }
        // return true;

        // check range, p_bucket

        cout<<"P_str:  ";
        for(int i = 0; i<p.size(); i++){
            cout<<p[i];
        }cout<<endl;
        cout<<"regexB: ";
        for(int i = 0; i<=idx; i++){
            cout<< setw(2) << p_bucket[i]<<' ';
        }cout<<endl;
        cout<<"Urange: ";
        for(int i = 0; i<=idx; i++){
            cout<< setw(2) << range[i][1]<<' ';
        }cout<<endl;
        cout<<"Lrange: ";
        for(int i = 0; i<=idx; i++){
            cout<< setw(2) << range[i][0]<<' ';
        }cout<<endl;
        cout<<"-----------\n";
        // check s_bucket, s_cnt
        cout<<"S_str:  ";
        for(int i = 0; i<s.size(); i++){
            cout<< s[i];
        }cout<<endl;
        cout<<"S_bkt: ";
        for(int i = 0; i<=k; i++){
            cout<< setw(2) << s_bucket[i]<<' ';
        }cout<<endl;
        cout<<"sCount:";
        for(int i = 0; i<=k; i++){
            cout<< setw(2) << s_cnt[i]<<' ';
        }cout<<endl;
    }
};


int main(){
    Solution sol;
    string s = "aaabfffaaabbbcb";
    // string p = "a*";
    string p = "aa.*aabb*";
    
    cout<<sol.isMatch(s,p);
    // cout<<Upper('c');
    
}