#include<iostream>

using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string sbl[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int val[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string ans = "";
        while(num){
            for(int i = 12; i>=0; i--){
                if(num>=val[i]){
                    ans+=sbl[i];
                    num-=val[i];
                    break;
                }
            }
        }
        return ans;
    }
};
int main(){
    
}