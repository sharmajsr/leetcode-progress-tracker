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
        if(head->next == NULL and n2 ==1 )  return {};
        ListNode* dummyNode = new ListNode();
        dummyNode =head;
        ListNode* ans = dummyNode;
        
        int n1 = getLengthOfLL(head);
        int n = n1-n2-1 ;
        if(n1 == n2)    return head->next;
        while(head and n>0){
            head=head->next;
            n--;
        }
        if(head and head->next){
            head->next = head->next->next;
        }
        return ans;
    }
};