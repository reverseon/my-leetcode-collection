#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* it1 = l1;
        ListNode* it2 = l2;
        ListNode* ret = new ListNode(-1);
        ListNode* head = ret;
        while (it1 != nullptr || it2 != nullptr) {
            int sum = carry;
            if (it1 != nullptr) {
                sum += it1->val;
                it1 = it1->next;
            }
            if (it2 != nullptr) {
                sum += it2->val;
                it2 = it2->next;
            }
            carry = sum / 10;
            sum = sum % 10;
            if (ret->val == -1) {
                ret->val = sum;
            } else {
                ret->next = new ListNode(sum);
                ret = ret->next;
            }
        }
        if (carry > 0) {
            ret->next = new ListNode(carry);
        }
        return head;
    }
};