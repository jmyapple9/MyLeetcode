#include<iostream>
#include<vector>
using namespace std;


// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = true;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
private:
    int x, y, n;
public:
    Node* construct(vector<vector<int>>& grid) {
        n = grid.size();
        
        // int half = n/2;
        // int tl, tr, bl, br;
        // // cout<<n<<endl;
        // for(int i=0; i<half; i++){
        //     for(int j=0; j<half; j++){
        //         tl = grid[i*2][j*2];
        //         tr = grid[i*2][j*2+1];
        //         bl = grid[i*2+1][j*2];
        //         br = grid[i*2+1][j*2+1];

        //     }
        // }
        
    }
    Node* BuildTree(vector<vector<int>>& grid){
        bool tl, tr, bl, br;
        Node *topLeft, topRight, bottomLeft, bottomRight;
        Node *node = new Node();
        
        if (n==1) return new Node(grid[x][y],1);
        
        tl = (new Node(grid[n/2][n/2],0))->val;
        
        if((tl & tr & bl & br) || !(tl | tr | bl | br)){
            node->isLeaf = 1;
            if(!(tl | tr | bl | br))
                node->val = 0;
        }
        return NULL;
    }
};



#if 1
int main(){
    vector<vector<int>> vect
    {
        {0,1},
        {1,0}
    };
    Solution sol;
    Node* node = sol.construct(vect);
    
}
#endif