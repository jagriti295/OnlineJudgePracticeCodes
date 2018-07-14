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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int cnt=0;
        ListNode* prev=NULL,*thead=NULL,*next=NULL,*root=head;
        while(head){
            cnt++;
            if(cnt<m)  prev = head; 
            if(cnt==m){
                thead = head;
            }
            if(cnt==n){
                next=head->next;
                //cout<<head->val<<" "<<thead->val<<" "<<next->val<<" "<<prev->val<<endl;
                reverse(thead,m,n);
                if(prev){
                    prev->next = head;
                }    
                else    root = head;
                thead->next = next;
                //cout<<root->val<<" "<<thead->val<<endl;
                break;
            }  
            
            head = head->next;
            
        }
        return root;
    }
    void reverse(ListNode* node,int m,int n){
        if(m==n)    return;
        if(node->next){
            //head=head->next;
            reverse(node->next,++m,n);
            node->next->next = node;
            node->next = NULL;
        }
    }
};
