#pragma once

#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
		stack<int> s1, s2, result;
		ListNode *ln1 = l1, *ln2 = l2;
		while(ln1 != NULL) { s1.push(ln1->val); ln1 = ln1->next; }
		while(ln2 != NULL) { s2.push(ln2->val); ln2 = ln2->next; }

		int carry = 0;
		while(!s1.empty() || !s2.empty() || carry) {
			int sum = 0;
			int share = 0, remainder = 0;

			if (s1.empty() && s2.empty() && carry) {
				result.push(carry);
				break;
			}

			if (!s1.empty()) { sum += s1.top(); s1.pop(); }
			if (!s2.empty()) { sum += s2.top(); s2.pop(); }
			if (carry) { sum++; }

			share = sum / 10;
			remainder = sum % 10;
			result.push(remainder);
			carry = share ? 1 : 0;
		}

		ListNode *cur = NULL, *head = NULL;
		while(!result.empty()) {
			ListNode *node = new ListNode(result.top());
			result.pop();
			if (cur == NULL) {
				cur = node;
				head = cur;
			} else {
				cur->next = node;
				cur = node;
			}
		}
		return head;
	}
};
