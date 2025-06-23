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
    int getLengthOfLinkedList(ListNode *head){
        int cnt = 0;
        while(head){
            ++cnt;
            head= head->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)   return head;
        // if(head->next == NULL and n == 1)   return NULL;
        int len = getLengthOfLinkedList(head);
        int k = len - n;
        if(k == 0 ){
            return head->next;
        }
        ListNode* ans = head;
        while(k!=1){
            // cout<<head->val<<" ";
            --k;
            head=head->next;
        }
        // cout<<endl;
        head->next = head->next->next;
        return ans;
    }
};