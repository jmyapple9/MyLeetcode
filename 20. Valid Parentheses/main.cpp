#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char c: s){
            switch(c){
                case '(':
                    stk.emplace(c);
                    break;
                case ')':
                    if(stk.empty() || stk.top()!='(') return false;
                    stk.pop();
                    break;
                case '[':
                    stk.emplace(c);
                    break;
                case ']':
                    if(stk.empty() || stk.top()!='[') return false;
                    stk.pop();
                    break;
                case '{':
                    stk.emplace(c);
                    break;
                case '}':
                    if(stk.empty() || stk.top()!='{') return false;
                    stk.pop();
                    break;
                default:
                    break;
            }
        }
        return stk.empty();
    }
};
int main(){
    
}