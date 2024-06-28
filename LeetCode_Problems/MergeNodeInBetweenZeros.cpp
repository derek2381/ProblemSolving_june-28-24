// problem link
// https://leetcode.com/problems/merge-nodes-in-between-zeros/description/


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
    ListNode* mergeNodes(ListNode* head) {
        long long int sum = 0;

        ListNode* dm = new ListNode(-99);
        ListNode* last = dm;
        ListNode* temp = head->next;

        while(temp != nullptr){
            if(temp->val == 0){
                ListNode* nn = new ListNode(sum);
                cout << sum << endl;
                last->next = nn;
                last = last->next;

                sum = 0;
            }else{
                sum += temp->val;
            }

            temp = temp->next;
        }


        return dm->next;
    }
};
