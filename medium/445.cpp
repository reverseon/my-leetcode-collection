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
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* it = head;
        int carry = 0;
        ListNode* l1r = reverseLL(l1);
        ListNode* l2r = reverseLL(l2);
        while (l1r != nullptr || l2r != nullptr) {
            int sum = carry;
            if (l1r != nullptr) {
                sum += l1r->val;
                l1r = l1r->next;
            }
            if (l2r != nullptr) {
                sum += l2r->val;
                l2r = l2r->next;
            }
            carry = sum / 10;
            sum = sum % 10;
            if (it->val == -1) {
                it->val = sum;
            } else {
                it->next = new ListNode(sum);
                it = it->next;
            }
        }
        if (carry > 0) {
            it->next = new ListNode(carry);
        }
        return reverseLL(head);
    }
};