#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
private:
    int boss[100001];
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int pairs = connections.size();
        if(pairs<n-1) return -1;
        // check how many sets are there, (the # of set - 1) will be the ans
        for(int i = 0; i<n; i++)
            boss[i] = i;
        for(auto connect:connections)
            Union(connect[0],connect[1]);
        
        set<int> S;
        
        for(int i = 0; i<n; i++)
            boss[i] = find_root(boss[i]); // root可能出現:0 0 0 0 0 3 0 3 8 9 10 11的情況，其中看似有6個集合，實際上只有五個，因此要再壓縮一次
        for(int i = 0; i<n; i++)
            S.insert(boss[i]);

        return S.size()-1;
    }
    int find_root(int x){
        return (x==boss[x])? x : boss[x] = find_root(boss[x]);
    }
    void Union(int x, int y){
        int x_root = find_root(x);
        int y_root = find_root(y);
        boss[y_root] = x_root;
        // if(x_root != y_root) boss[y_root] = x_root;
    }
};
/* 
// Code from leetcode (shortest running time)
int p[100000], cnt;
int find(int i) {
    if (p[i] != i) p[i] = find(p[i]); 
    //p[i]==i means the set has only one element
    // else it has other parent, find the parent
    return p[i];
}
void join(int a, int b) {
    int findA = find(a), findB = find(b);
    if (findA == findB) return; // if findA == findB, 
    p[findA] = findB;
    cnt--;
}
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        cnt = n;
        for (int i = 0; i < n; i++) p[i] = i;
        for (vector<int>& c : connections) join(c[0], c[1]);
        return cnt - 1;
    }
};
 */
int main(){
    Solution sol;
    int n = 6;
    // vector<vector<int>> v = {{0,1},{0,2},{1,2}};
    vector<vector<int>> v = {{0,1},{0,2},{0,3},{1,2},{1,3}};
    // vector<vector<int>> v = {{0,1},{0,2},{0,3},{1,2}};
    // vector<vector<int>> v = {{1,5},{1,7},{1,2},{1,4},{3,7},{4,7},{3,5},{0,6},{0,1},{0,4},{2,6},{0,3},{0,2}}; //4
    cout<<sol.makeConnected(n,v);
}