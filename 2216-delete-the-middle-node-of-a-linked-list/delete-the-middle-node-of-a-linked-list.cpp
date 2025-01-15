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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL)       return head; 
        if(head->next == NULL) return {}; 
        ListNode* dummyNode = new ListNode();
        dummyNode =head;
        ListNode* ans = dummyNode;
        ListNode* prev = head;
        ListNode* temp =head;
        while(temp and temp->next){
            prev= head;
            head=head->next;
            temp=temp->next->next;
        }
        prev->next = head->next;
        return ans;
    }
};