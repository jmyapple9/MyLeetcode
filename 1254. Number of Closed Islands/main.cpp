#include<iostream>
#include<vector>
#include<queue>
// #define pair<int,int> Pair
using namespace std;
class Solution {
private:
    class Pair{
        public:
            int i, j;
            Pair(int a, int b){i=a,j=b;};
        friend Pair operator+(const Pair a, const Pair b) {
            return Pair(a.i+b.i, a.j+b.j);
        }
        friend auto operator<<(std::ostream &os, const Pair &P) -> std::ostream& { 
            return os << "("<<P.i<<", "<<P.j<<")";
        }
    };
    int length, width; // length = grid.size(), width = grid[0].size();
    Pair directions[4] = {Pair(0,1),Pair(0,-1),Pair(1,0),Pair(-1,0)};
    // bool touchEdge = false;
public:
    int closedIsland(vector<vector<int>>& grid) {
        length = grid.size(), width = grid[0].size();
        
        int arr[] = {0, length-1};
        int brr[] = {0, width-1};
        for(int i:arr)
            for(int j = 0; j<width; j++)
                dfs(i,j, grid);
        for(int j:brr)
            for(int i = 1; i<length-1; i++)
                dfs(i,j, grid);
        // cout<<"test"<<endl;
        int cnt = 0;
        for(int i = 0; i<length; i++){
            for(int j =0; j<width; j++){
                if(grid[i][j]==0){
                    dfs(i,j,grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }
    void bfs(int i,int j, vector<vector<int>>& grid){
        queue<Pair> Q;
        Q.emplace(Pair(i,j));
        while(!Q.empty()){
            Pair p = Q.front();
            Q.pop();
            grid[p.i][p.j] = 1;
            for(Pair q:directions){
                Pair t = p+q;
                if(valid(t.i,t.j) && grid[t.i][t.j]==0)
                    Q.push(t);
            }
        }
    }
    void dfs(int i,int j, vector<vector<int>>& grid){
        if(!valid(i,j) || grid[i][j]==1) return;
        // cout<<"?";
        grid[i][j]=1;
        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
    }
    bool valid(int i, int j){
        return i<length && i>=0 && j<width && j>=0;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = 
    {
        {1,1,1,1,1,1,1,0},
        {1,0,0,0,0,1,1,0},
        {1,0,1,0,1,1,1,0},
        {1,0,0,0,0,1,0,1},
        {1,1,1,1,1,1,1,0}
        
        // {0,0,1,0,0},{0,1,0,1,0},{0,1,1,1,0}
    
        // {1,1,1,1,1,1,1},
        // {1,0,0,0,0,0,1},
        // {1,0,1,1,1,0,1},
        // {1,0,1,0,1,0,1},
        // {1,0,1,1,1,0,1},
        // {1,0,0,0,0,0,1},
        // {1,1,1,1,1,1,1}
    };
    
    cout<<sol.closedIsland(grid);

}