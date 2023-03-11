#include<iostream>
#include<vector>
using namespace std;
// Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    vector<int> v;
    int len;
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* now = head;
        len = 0;
        while(now){
            len++;
            v.push_back(now->val);
            now = now->next;
        }
        // for debug
        // cout<<"vector: ";
        // for(int u:v) cout<<u<<" ";
        // cout<<endl;
        // for debug
        return VectorToBST(0, (len-1)/2, len);
    }
    TreeNode* VectorToBST(int l, int mid, int r){
        if(l == r) return nullptr;
        TreeNode* node = new TreeNode(\
                                    v[mid], \
                                    VectorToBST(l, (l + mid)/2, mid), \
                                    VectorToBST(mid+1, (mid+1+r)/2, r) \
                                );
        // cout<<"Node: "<<v[mid]<<", ("+to_string(l)+to_string(mid)+to_string(r)+")\n";
        return node;
    }
    ListNode* makeList(vector<int>& v){
        ListNode* head = nullptr;

        for(int i = v.size()-1; i >=0 ; i--) {
            ListNode* node = new ListNode();
            node->val = v[i];
            node->next = head;
            head = node;
        }

        // for debug
        // ListNode* now = head;
        // cout<<"single linked list: ";
        // while(now) cout<<now->val<<' ', now = now->next;
        // cout<<endl;
        // for debug
        return head;
    }
    void InorderTraverse(TreeNode* root){
        if(!root) return;
        InorderTraverse(root->left);
        cout<<root->val<<' ';
        InorderTraverse(root->right);
    }
};
int main(){
    Solution sol;
    // vector<int> v = {-10,-3,0,5,9};
    vector<int> v = {};
    ListNode *listHead = sol.makeList(v);
    TreeNode* root = sol.sortedListToBST(listHead);
    sol.InorderTraverse(root);

}