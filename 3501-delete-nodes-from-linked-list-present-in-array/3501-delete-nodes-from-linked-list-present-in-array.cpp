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
        unordered_set<int> st;
        ListNode* dummy=new ListNode(0);
        ListNode* curr = dummy;
        for(int num:nums){
            st.insert(num);
        }
        ListNode* temp = head;
        while(temp!=nullptr){
            if(!st.count(temp->val)){
                curr->next = temp;
                curr = curr->next;
            }
             temp = temp->next;
        }
        curr->next = nullptr;
        ListNode* ans = dummy->next;
        return ans;
    }
};