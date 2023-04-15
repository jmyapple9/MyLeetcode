#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* nodes[30];
        ListNode* cur = head;
        int len = 0;
        while(cur){
            nodes[len++] = cur;
            cur = cur->next;
        }
        if(n==len) return head->next;
        for(int i = 1; i<len; i++){
            if(i==len-n){
                ListNode* tmp = nodes[i];
                nodes[i-1]->next = tmp->next;
                delete tmp;
            }
        }
        return head;
        
    }
};

class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        int len = 0;
        while(cur)
            cur = cur->next, len++;
        
        cur = head;
        for(int i = 0; i<len-n-1; i++){
            cur = cur->next;
        }
        if(len==n){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        return head;

    }
};
int main(){
    
}