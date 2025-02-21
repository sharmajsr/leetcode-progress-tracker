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
        ListNode* next = head;
        while(head!=NULL){
            next = head->next;
            head->next= prev;
            prev= head;
            head = next;
        }
        return prev;
    }
    void printList(ListNode* head){
        cout<<"Inside printList function\n";
        while(head){
            cout<<head->val<<" ";
            head =head->next;
        }
    }
    void reorderList(ListNode* head) {
        
        ListNode* dummyNode = new ListNode();
        dummyNode->next= head;
        ListNode* prevSlow ;
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow and fast and fast->next){
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast!=NULL){
            prevSlow = slow;
            slow = slow->next;
        }
        prevSlow->next = NULL;
        ListNode* midPoint = rever(slow);
        // printList(midPoint);
        while(head && midPoint){
            ListNode* midPointNext = midPoint->next;
            midPoint->next = head->next;
            head->next = midPoint;
            head=head->next->next;
            midPoint = midPointNext;
        }
        // while

        // return dummyNode->next;
    }
};