#include <iostream>
#include <stack>
#include "addTwoNumbersII.h"
using namespace std;

ListNode* makeListNode(int value)
{
	int share = 0, remainder = 0, origin = value;
	stack<int> s;
	share     = value / 10;
	remainder = value % 10;

	while (share || remainder) {
		s.push(remainder);
		value /= 10;
		share = value / 10;
		remainder = value % 10;
	}

	ListNode *cur = NULL;
	ListNode *head = NULL;
	while (!s.empty()) {
		ListNode *node = new ListNode(s.top());
		s.pop();
		if (head == NULL) {
			head = node;
			cur = head;
		} else {
			cur->next = node;
			cur = node;
		}
	}

	return head;
}

void print_list(ListNode* l)
{
	while(l != NULL) {
		cout << l->val;
		l = l->next;
		if (l) { cout << " -> "; }
	}
	cout << endl;
}

int main(void)
{
	Solution *s = new Solution();

	ListNode* l1 = makeListNode(7243);
	ListNode* l2 = makeListNode(564);
	ListNode* r1 = s->addTwoNumbers(l1, l2);
	print_list(r1);
}
