#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int val) : val(val), next(nullptr) {}
    Node() : val(0), next(nullptr) {}
};

/* PROBLEM 1 - Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/
// avoids converting the whole list into an int (and thus avoids overflow) by doing digit‐by‐digit addition with carry
Node *addTwoNumbers(Node *l1, Node *l2)
{
    // Create a dummy head to simplify list construction (avoids special handling for the first node)
    Node *dummyHead = new Node();
    Node *current = dummyHead; // Pointer to build the result list
    int sum = 0;               // Holds the running sum + carry

    // Continue until both lists are exhausted and there's no carry left
    while (l1 != nullptr || l2 != nullptr || sum != 0)
    {
        // Add digit from l1 if available
        if (l1 != nullptr)
        {
            sum += l1->val; // include l1's digit in the sum
            l1 = l1->next;  // advance in l1
        }
        // Add digit from l2 if available
        if (l2 != nullptr)
        {
            sum += l2->val; // include l2's digit in the sum
            l2 = l2->next;  // advance in l2
        }

        // Create a new node for the current digit (sum % 10)
        current->next = new Node(sum % 10);
        // Update carry for next iteration (sum /= 10)
        sum /= 10;
        // Move current pointer forward
        current = current->next;
    }

    // The real head is next to dummy
    return dummyHead->next;
}
// Problem Approach Summary:
// We traverse both input lists simultaneously, adding corresponding digits and carrying over any overflow.
// A dummy head node streamlines list construction, and we loop until both lists are done and carry is zero.
//
// Time Complexity: O(max(n, m)) where n and m are the lengths of the two lists.
// Space Complexity: O(max(n, m)) for the newly created result nodes.

/*
PROBLEM 2 - Merge Two Sorted Lists
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list.
The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
*/
Node *mergeTwoLists(Node *l1, Node *l2)
{
    Node *ans = new Node();
    Node *curr = ans;
    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            curr->next = l1;
            l1 = l1->next;
        }
        else
        {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }
    curr->next = l1 ? l1 : l2;
    return ans->next;
}

/*
PROBLEM 3 - REVERSE A LINKED LIST 2
Reverse a linked list from position m to n. Do it in one-pass.
You may assume that m <= n.
Input: head = [1,2,3,4,5], m = 2, n = 4
Output: [1,4,3,2,5]
*/

Node *reverseBetween(Node *head, int m, int n)
{
    if (!head || m == n)
        return head;

    Node dummy(0);
    dummy.next = head;
    Node *prev = &dummy;

    // Move prev to the node before the m-th node
    for (int i = 1; i < m; ++i)
        prev = prev->next;

    Node *start = prev->next; // m-th node
    Node *then = start->next; // (m+1)-th node

    // Reverse the sublist from m to n
    for (int i = 0; i < n - m; ++i)
    {
        start->next = then->next;
        then->next = prev->next;
        prev->next = then;
        then = start->next;
    }

    return dummy.next;
}

int main()
{
    Node *l1 = new Node(2);
    l1->next = new Node(4);
    l1->next->next = new Node(3);
    Node *l2 = new Node(5);
    l2->next = new Node(6);
    l2->next->next = new Node(4);
    Node *result = addTwoNumbers(l1, l2);
    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    // Clean up memory
    while (l1)
    {
        Node *temp = l1;
        l1 = l1->next;
        delete temp;
    }
    while (l2)
    {
        Node *temp = l2;
        l2 = l2->next;
        delete temp;
    }
    while (result)
    {
        Node *temp = result;
        result = result->next;
        delete temp;
    }
    return 0;
}