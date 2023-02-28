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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* Node = new ListNode();
        ListNode* firstNode = Node;
        
        int sum, d, c = 0;
        while(l1 || l2 || c){
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + c;
            c = sum / 10;
            d = sum % 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            ListNode* nextNode = (l1 || l2 || c) ? new ListNode() : nullptr;
            Node->val = d;
            Node->next = nextNode;
            Node = Node->next;
        }
        return firstNode;
    }
};

#if 1
void traverse(ListNode* list){
    while(list){
        cout<<list->val<<' ';
        list = list->next;
    }
}
ListNode* buildList(vector<int> arr){
    int n = arr.size();
    ListNode* node = new ListNode();
    ListNode* firstNode = node;
    for(int i=0;i<n;i++){
        ListNode* nextNode = (i+1!=n)? new ListNode() : nullptr;
        node->val = arr[i];
        node->next = nextNode;
        node = node->next;
    }
    return firstNode;

}
int main(void){
    
    vector<int> a = {9,9,9,9,9,9,9};
    vector<int> b = {9,9,9,9};
    ListNode* alist = buildList(a);
    ListNode* blist = buildList(b);
    // traverse(buildList(a));
    
    Solution sol;
    traverse(sol.addTwoNumbers(alist,blist));
}
#endif