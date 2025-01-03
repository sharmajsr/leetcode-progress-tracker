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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(!head)   return head;
        ListNode* dummyNode = new ListNode();
        dummyNode->next = head;
        unordered_map<int,int>um;
        for(auto i : nums)
            ++um[i];
            
        while(head and head->next){
            if(um.find(head->next->val)!=um.end()){
                // cout<<"Found : "<<head->val<<endl;
                ListNode* tempHead = head;
                while(tempHead->next and um.find(tempHead->next->val) != um.end()){
                    tempHead= tempHead->next;
                }
                head->next = tempHead->next;
                head = head->next;
            }else{
                head=head->next;
            }
        }
        if(um.find(dummyNode->next->val) != um.end()){
            return dummyNode->next->next;
        }
        return dummyNode->next;
    }
};