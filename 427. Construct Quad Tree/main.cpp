#include<iostream>
#include<vector>
#include<queue>
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
        val = false;
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
    int X, Y, n;
public:
    Node* construct(vector<vector<int>>& grid) {
        n = grid.size();
        return BuildTree(grid, n, 0, 0);
    }
    Node* BuildTree(vector<vector<int>>& grid, int size, int x, int y){
        bool tl, tr, bl, br;
        bool leaf_tl, leaf_tr, leaf_bl, leaf_br;
        Node *topLeft, *topRight, *bottomLeft, *bottomRight;
        Node *node = new Node(1,0);
        
        if (size==1) return new Node(grid[y][x],1);
        int halfsize = size/2;
        node->topLeft  = BuildTree(grid, halfsize, x, y);
        node->topRight = BuildTree(grid, halfsize, x + halfsize, y);
        node->bottomLeft  = BuildTree(grid, halfsize, x, y + halfsize);
        node->bottomRight = BuildTree(grid, halfsize, x + halfsize, y + halfsize);
         
        tl = node->topLeft->val;
        tr = node->topRight->val;
        bl = node->bottomLeft->val;
        br = node->bottomRight->val;

        leaf_tl = node->topLeft->isLeaf;
        leaf_tr = node->topRight->isLeaf;
        leaf_bl = node->bottomLeft->isLeaf;
        leaf_br = node->bottomRight->isLeaf;

        if(leaf_tl & leaf_tr & leaf_bl & leaf_br){
            if((tl & tr & bl & br)){
                node->val = 1;
                node->isLeaf = 1;
                node->topLeft = NULL;
                node->topRight = NULL;
                node->bottomLeft = NULL;
                node->bottomRight = NULL;
            }
            if(!(tl | tr | bl | br)){
                node->val = 0;
                node->isLeaf = 1;
                node->topLeft = NULL;
                node->topRight = NULL;
                node->bottomLeft = NULL;
                node->bottomRight = NULL;
            }

        }
      
        return node;
    }
};



#if 1
queue<Node *> Q;
void traverseTree(Node* node){
    Q.push(node);
    int cnt=0;
    while(!Q.empty()){
        Node *t = Q.front();
        Q.pop();
        if(t && !t->isLeaf){
            if(t->topLeft) Q.push(t->topLeft);
            if(t->topRight) Q.push(t->topRight);
            if(t->bottomLeft) Q.push(t->bottomLeft);
            if(t->bottomRight) Q.push(t->bottomRight);
        }
        cout<<'['<<t->isLeaf<<','<<t->val<<']'<<", \n";
        cnt++;
    }
    cout<<cnt<<" nodes in total.\n";
}
int main(){
    vector<vector<int>> vect
    {
        // {0,1},
        // {1,0}
        
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0}

        // {1,1,1,1,1,1,1,1},
        // {1,1,1,1,1,1,1,1},
        // {1,1,1,1,1,1,1,1},
        // {1,1,1,1,1,1,1,1},
        // {1,1,1,1,1,1,1,1},
        // {1,1,1,1,1,1,1,1},
        // {1,1,1,1,1,1,1,1},
        // {1,1,1,1,1,1,1,1}
    };
    Solution sol;
    Node* node = sol.construct(vect);
    traverseTree(node);
}
#endif