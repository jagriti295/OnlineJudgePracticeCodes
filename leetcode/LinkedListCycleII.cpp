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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow,*fast;
        if(!head)   return NULL;
        if(!head->next) return NULL;
        slow = head->next;
        fast = head->next->next;
        while(fast && fast->next && slow!=fast){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(slow && slow==fast){
            cout<<"Cycle exists!"<<endl;
            slow = head;
            while(fast && slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            if(slow && slow==fast){
                cout<<slow->val<<endl;
                return slow;
            }   
        }
        return NULL;
    }
};
