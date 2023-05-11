#include<iostream>
#include<string>
#include<set>
using namespace std;
class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        set<int> Dv;
        set<int> Rv;

        for(int i = 0; i<n; i++){
            if(senate[i] == 'R') Rv.insert(i);
            else Dv.insert(i);
        }
        while(!Dv.empty() && !Rv.empty()){
            for(int i = 0; i<n && !Dv.empty() && !Rv.empty(); i++){
                if(Dv.end()==Dv.find(i) && Rv.end()==Rv.find(i)) 
                    continue;
                
                if(senate[i] == 'R'){
                    // Dv.insert(i);
                    cout<<"R: "<<i<<endl;
                    set<int>::iterator it = Dv.lower_bound(i);
                    // it++;
                    if(it == Dv.end())
                        it = Dv.begin();
                    
                    if(*it != i)
                        Dv.erase(it);
                    else
                        return "Radiant";
                    // Dv.erase(i);
                }
                else{
                    // Rv.insert(i);
                    cout<<"D: "<<i<<endl;

                    set<int>::iterator it = Rv.lower_bound(i);
                    // it++;
                    if(it == Rv.end())
                        it = Rv.begin();
                    
                    if(*it != i)
                        Rv.erase(it);
                    else
                        return "Dire";
                    // Rv.erase(i);
                }
            }
        }
        if(!Dv.empty()) return "Dire";
        else return "Radiant";
    }
};
int main(){
    Solution sol;
    // string s = "RRDDD";
    string s = "DRRDRDRDRDDRDRDR";
    // string s = "DRRDRDRDRDDRDRDR";
    cout<<sol.predictPartyVictory(s);
    
}