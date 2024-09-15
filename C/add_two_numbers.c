#include <stdio.h>
#include <stdlib.h>
/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/
//structure 
struct ListNode {
    int val;
    struct ListNode *next;
};

//function declaration
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
struct ListNode* createNode(int value);
void printList(struct ListNode* head);

int main() {
    struct ListNode* l1;
    struct ListNode* l2;

    l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);

    l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    struct ListNode* result = addTwoNumbers(l1, l2);
    printf("Result: ");
    printList(result);

    return 0;
}

//function definition
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = head;
    int carry = 0; //initial carry = 0

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum/10;
        current->val = sum%10;
        if (l1 != NULL || l2 != NULL || carry) {
            current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            current = current->next;
        } else {
            current->next = NULL;
        }
    }
    return head;
}

struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while(current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}