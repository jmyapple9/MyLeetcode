#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Solution {
private:
    vector<vector<string>> tbl = {
        {"a", "b", "c"},
        {"d", "e", "f"},
        {"g", "h", "i"},
        {"j", "k", "l"},
        {"m", "n", "o"},
        {"p", "q", "r", "s"},
        {"t", "u", "v"},
        {"w", "x", "y", "z"},
    };
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n==0)
            return vector<string> {};
        if(n==1)
            return tbl[digits[0] - '2'];
        
        vector<string> ans;
        char c = digits[0];
        vector<string> v = letterCombinations(digits.substr(1,n-1));
        for(auto a:tbl[c - '2'])
            for(auto b:v)
                ans.emplace_back(a+b);

        return ans;
    }
};

class Solution2 {
private:
    vector<vector<string>> tbl = {
        {"a", "b", "c"},
        {"d", "e", "f"},
        {"g", "h", "i"},
        {"j", "k", "l"},
        {"m", "n", "o"},
        {"p", "q", "r", "s"},
        {"t", "u", "v"},
        {"w", "x", "y", "z"},
    };
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> v = {};
        switch(n){
            case 0:
                break;
            case 1:
                return tbl[digits[0] - '2'];
                break;
            case 2:
                for(auto a:tbl[digits[0] - '2'])
                    for(auto b:tbl[digits[1] - '2'])
                        v.emplace_back(a+b);
                break;

            case 3:
                for(auto a:tbl[digits[0] - '2'])
                    for(auto b:tbl[digits[1] - '2'])
                        for(auto c:tbl[digits[2] - '2'])
                            v.emplace_back(a+b+c);
                break;
            case 4:
                for(auto a:tbl[digits[0] - '2'])
                    for(auto b:tbl[digits[1] - '2'])
                        for(auto c:tbl[digits[2] - '2'])
                            for(auto d:tbl[digits[3] - '2'])
                                v.emplace_back(a+b+c+d);
                break;
            default:
                break;
        }
        return v;

    }
};

int main(){
    
}
