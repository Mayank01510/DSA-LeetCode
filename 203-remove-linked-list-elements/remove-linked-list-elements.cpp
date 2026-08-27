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
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL && head->val == val){
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        if(head == nullptr)return NULL;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            if( temp->val == val){
                ListNode* p = temp;
                temp = temp->next;
                prev->next = temp;
                delete p;
                continue;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};