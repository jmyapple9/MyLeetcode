#include<iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    int len;
    int arr[10001];
public:
    Solution(ListNode* head) {
        ListNode* cur = head;
        srand(time(nullptr));

        len = 0;
        while(cur){
            arr[len++] = cur->val;
            cur = cur->next;
        }
    }
    
    int getRandom() {
        return arr[rand()%len];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
int main(){
    ListNode* node3= new ListNode(7);
    ListNode* node2= new ListNode(6, node3);
    ListNode* node1= new ListNode(5, node2);
    Solution* obj = new Solution(node1);
    
    for(int i = 0;i<3;i++) cout<<obj->getRandom()<<endl;
    // int param_1 = obj->getRandom();
}