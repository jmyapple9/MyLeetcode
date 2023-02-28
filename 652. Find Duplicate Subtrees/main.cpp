#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

// * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        SerialSubTree(root);
        return ans;
    }
private:
    unordered_map<string, int> umap;
    vector<TreeNode*> ans;
    
    string SerialSubTree(TreeNode* root){
        if(!root) return "#";
        const string encode = to_string(root->val) + "#" \
                            + SerialSubTree(root->left)  + "#" \
                            + SerialSubTree(root->right) + "#";
        if(++ umap[encode] == 2)
            ans.push_back(root);
        return encode;
    }
};


#if 1
int main(void){
    TreeNode* G = new TreeNode(4);
    TreeNode* D = new TreeNode(4);
    TreeNode* F = new TreeNode(4);
    TreeNode* E = new TreeNode(2,G,nullptr);
    TreeNode* B = new TreeNode(2,D,nullptr);
    TreeNode* C = new TreeNode(3,E,F);
    TreeNode* A = new TreeNode(1,B,C);
    cout<<"G: "<<G<<endl;
    cout<<"D: "<<D<<endl;
    cout<<"F: "<<F<<endl;
    cout<<"E: "<<E<<endl;
    cout<<"B: "<<B<<endl;
    cout<<"C: "<<C<<endl;
    cout<<"A: "<<A<<endl;
    Solution sol;
    for(auto u:sol.findDuplicateSubtrees(A)){
        cout<<u<<", ";
    }
}
#endif