// problem link
// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/

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
    int gcd(int a, int b){
        int temp;

        if(b > a){
            temp = a;
            a = b;
            b = temp;
        }

        while(b != 0){
            temp = b;
            b = a%b;
            a = temp;
        }

        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* temp1 = head;
        ListNode* temp2 = head->next;

        while(temp1 != nullptr && temp2 != nullptr){
            int val = gcd(temp1->val, temp2->val);

            ListNode* nn = new ListNode(val);

            nn->next = temp1->next;
            temp1->next = nn;



            temp1 = temp2;
            temp2 = temp2->next;
        }

        return head;
    }
};
