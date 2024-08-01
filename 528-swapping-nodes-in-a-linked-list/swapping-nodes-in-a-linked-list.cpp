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
    ListNode* reverse(ListNode* head){
        if(!head)   return head;
        ListNode* prev = NULL;
        ListNode* next;
        while(head){
            next = head->next;
            head->next = prev;
            prev= head;
            head = next;
        }
        return prev;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        // if(  k == 1) return reverse(head);
        int n = 0 ,n1 = 1,start = k;
        ListNode* sta;
        ListNode* end1;
        ListNode* h1 = head;
        ListNode* next = head;
        ListNode* prev = NULL;
        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;
        dummy->next= head;
        while(h1){
            h1 = h1->next;
            ++n;
        }
        int end = n-k+1;
        h1 =head;
        while(h1 ){
            if(n1 == start ){
                sta =h1;
            }
            if(n1 == end){
                end1 = h1;
            }
            ++n1;
            h1 =h1->next;
        }
        int temp =sta->val;
        sta->val = end1->val;
        end1->val = temp;
        return ans->next;

    }
};