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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>index;
        ListNode* temp = head;
        int prev = 0;
        int count = 1;
        while(temp != NULL){
            if(prev != NULL && temp->next){
                if(temp->val > prev && temp->val > temp->next->val)index.push_back(count);
                if(temp->val < prev && temp->val < temp->next->val)index.push_back(count);
            }
            prev = temp->val;
            temp = temp->next;
            count++;
        }

        if(index.size()<2)return {-1,-1};
        int n = index.size();
        vector<int>ans(2,INT_MAX-1);
        for(int i = 0;i<n-1;i++){
            ans[0] = min(ans[0] , index[i+1] - index[i]);
        }
        ans[1] = index[n-1] - index[0];

        return ans;
    }
};