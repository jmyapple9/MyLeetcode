#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
private:
    vector<vector<string>> tbl {{},{},{},{},{},{},{},{}};
public:
    vector<string> generateParenthesis(int n) {
        // return {};
        tbl[0] = {"()"};
        if(n==1) return tbl[0];
        for(int i = 1; i<n ; i++){
            for(auto str:tbl[i-1]){
                tbl[i].push_back("(" + str + ")");
            }
            for(auto str:tbl[i]){
                tbl[i].push_back("()" + str);
            }
            for(auto str:tbl[i]){
                tbl[i].push_back(str + "()");
            }
            string dpc = repeatString("()",i);
            // cout<<"repeat () "<<i<<" times: "<<dpc<<endl;
            
            remove(tbl[i].begin(), tbl[i].end(), dpc);
        }
        return tbl[n-1];
        
    }
    string repeatString(string rpt, int n){
        string ans = "";
        while(n--){
            ans+=rpt;
        }
        return ans;
    }
};
int main(){
    vector<vector<string>> tbl = {{"1","1","1","222"},{"2","2","2"}};
    tbl.erase(remove(tbl.begin(), tbl.end(), "222"), tbl.end());;
    for(auto item:tbl[0])
        cout<<item<<" ";
}
