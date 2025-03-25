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
    ListNode* rever(ListNode* head){
        ListNode* prev = NULL;
        ListNode* next;
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    void prin(ListNode* head){
        while(head){
            cout<<head->val<<" ";
            head = head->next;
        }

    }
    void reorderList(ListNode* head) {
        ListNode* slow , *fast , *next ,  *prev;
        slow = head;
        fast = head ;
        while(slow and fast and fast->next){
            prev =slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast!=NULL){
            prev = slow;
            slow = slow->next;
        }

        cout<<"prev val : " <<prev->val<<endl;
        prev->next = NULL;
        ListNode* midPoint= rever(slow);
        // prin(midPoint);

        ListNode* dummyNode = new ListNode(0);
        dummyNode->next =head;
       while(head && midPoint){
            ListNode* midPointNext = midPoint->next;
            midPoint->next = head->next;
            head->next = midPoint;
            head=head->next->next;
            midPoint = midPointNext;
        }
        return ;
    }
};