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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        auto am1 = list1;
        int acount = 1;
        while (am1->next && acount != a) {
            am1 = am1->next;
            acount++;
        }

        int bcount = acount;
        auto bp1 = am1->next;
        while (bp1 && bcount != b) {
            bp1 = bp1->next;
            bcount++;
        }
        bp1 = bp1->next;

        auto l2end = list2;
        while (l2end->next != nullptr) {
            l2end = l2end->next;
        }

        am1->next = list2;
        l2end->next = bp1;
        return list1;
    }
};
