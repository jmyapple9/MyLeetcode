#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};



class Solution {
public:
    Node* visited[101];
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        memset(visited, 101, sizeof(Node*));
        Node* root = new Node(node->val);
        dfs(node,root);
        return root;
    }
    void dfs(Node* node, Node* copy){
        visited[node->val] = copy;
        for(Node* nbr: node->neighbors){
            if(visited[nbr->val]==NULL)
                dfs(nbr, new Node(nbr->val));
            copy->neighbors.push_back(visited[nbr->val]);
        }
    }
};
int main(){
    
}