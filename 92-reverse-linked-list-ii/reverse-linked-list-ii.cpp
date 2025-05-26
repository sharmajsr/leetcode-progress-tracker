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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* next;
        while(head!=NULL){
            next = head->next;
            head->next= prev;
            prev = head;
            head=next;
        }
        return prev;
    }
    void printList(ListNode* head){
        while(head){
            cout<<head->val<<" ";
            head= head->next;
        }cout<<endl;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)   return head;
        
        ListNode* dummyNode = new ListNode();
        dummyNode->next = head;
        ListNode* lprev;
        ListNode* rprev;
        bool lfind = false, rfind = false;
        if(left == 1){
            lfind= true;
            lprev = head;
        }
        int cnt = 0; 
        while(head!=NULL){
            ++cnt;

            if(cnt == left)   lfind = true;
            if(cnt == right)  rfind = true;

            if(!lfind)  lprev = head;
            if(!rfind)  rprev = head;

            head=head->next;
        }
        ListNode* robj = rprev->next->next;
        rprev->next->next = NULL;
        cout<<"lprev next "<<lprev->next->val<<endl;
        ListNode* rev ;
        if(left != 1){
            rev  = reverseList(lprev->next);
            lprev->next = rev;
        } 
        else{
            rev  = reverseList(lprev);
            lprev = rev;
            dummyNode->next = lprev;
        }    
        printList(robj);
        
        while(lprev->next !=NULL){
            lprev = lprev->next;
        }
        lprev->next = robj;
        return dummyNode->next;
    }
};