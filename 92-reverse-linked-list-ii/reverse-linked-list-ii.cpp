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
        ListNode* prev = NULL;
        ListNode* next;
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head= next;
        }
        return prev;
    }
    ListNode* findRightNode(ListNode* head, int right){
        while(head){
            --right;
            cout<<right<<" "<<head->val<<endl;
            if(right == 1 ){
                return head;
            }
            head = head->next;
        }
        return head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head or left == right) {
            return head;
        }
        int k = 1;
        ListNode* dummyNode = new ListNode();
        dummyNode->next = head;
        if( left == 1 ){
            cout<<head->val<<endl;
            ListNode* r1 = findRightNode(head->next, right);
            cout<<r1->val<<endl;
            ListNode* next = r1->next;
            r1->next = NULL;
            ListNode* rev = reverse(head);
            ListNode* rev1 = rev;
            while(rev->next !=NULL){
                rev = rev->next;
            }
            rev->next = next;
            dummyNode->next = rev1;
        }else{
            while(head){
                if(left == k+1){
                    // cout<<"Head next val "<<head->next->val<<endl;
                    ListNode* r1 = findRightNode(head->next->next, right-left+1);
                    // cout<<"Rece1 : "<<r1->val<<endl;
                    ListNode* next = r1->next;
                    r1->next = NULL;
                    ListNode* rev = reverse(head->next);
                    ListNode* rev1 = rev;
                    while(rev->next !=NULL){
                        rev = rev->next;
                    }
                    rev->next = next;
                    head->next = rev1;
                    break;
                }
                k += 1;
                head=head->next;
            }
        }
        return dummyNode->next;
    }
};