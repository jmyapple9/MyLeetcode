#include<iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        char prev= 'a';
        int ans = 0;
        for(int i = 0; i<s.size(); i++){
            switch(s[i]){
                case 'I':
                    ans+=1;
                    break;
                case 'V':
                    if(prev=='I') ans+=3;
                    else ans+=5;
                    break;
                case 'X':
                    if(prev=='I') ans+=8;
                    else ans+=10;
                    break;
                case 'L':
                    if(prev=='X') ans+=30;
                    else ans+=50;
                    break;
                case 'C':
                    if(prev=='X') ans+=80;
                    else ans+=100;
                    break;
                case 'D':
                    if(prev=='C') ans+=300;
                    else ans+=500;
                    break;
                case 'M':
                    if(prev=='C') ans+=800;
                    else ans+=1000;
                    break;
                default:
                    break;
            }
            prev = s[i];
        }
        return ans;
    }
};

int main(){
    
}