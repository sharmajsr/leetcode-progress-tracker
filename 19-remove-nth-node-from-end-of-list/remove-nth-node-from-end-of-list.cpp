/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getLengthOfLL(ListNode* head){
        int ans = 0 ;
        while(head){
            head=head->next;
            ++ans;
        }
        return ans;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n2) {
        int n = getLengthOfLL(head);
        // if(!head->next and n2 == 1)  return NULL;
        ListNode* dummyNode = new ListNode();
        dummyNode->next = head;
        ListNode* prev = head;
        n2 = n -n2;
        if(n2 == 0 )    return head->next;
        while(head and n2 != 0 ){
            prev = head;
            head = head->next;
            --n2;
        }
        // cout<<"prev val : "<<prev->val<<endl;
        if(!prev->next){
            prev->next = NULL;
        }else{
            
            prev->next = prev->next->next;
        }
        
        return dummyNode->next;

    }
};