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
private:
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int tbl[20002] = {0};
        int offset = 10000;
        int max = -10000;
        int min = 10000;
        for(ListNode* head: lists){
            ListNode* node = head;
            while(node){
                int v = node->val+offset;
                tbl[v]++;
                if(max < v) max = v;
                if(min > v) min = v;
                node = node->next;
            }
        }
        ListNode* BeforeHead = new ListNode(0);
        ListNode* cur = BeforeHead;

        for(int i = min; i<=max; i++){
            int n = tbl[i];
            while(n--)
                cur = cur->next = new ListNode(i-offset);
        }
        return BeforeHead->next;

    }
};

int main(){
    
}