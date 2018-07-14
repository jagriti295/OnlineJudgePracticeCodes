/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)   return NULL;
        if(!head->next) return head;
        reverse(head,head);
        return head;
    }
    void reverse(ListNode*& head,ListNode* node){
        if(node->next){
            head = head->next;
            reverse(head,node->next);
            node->next->next = node;
            node->next = NULL;
        }
        //return node;
    }
};
