/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Given a linked list and a positive integer k, rotate the list to the right by k places.
 *
 *        Version:  1.0
 *        Created:  08/06/2022 12:19:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>

class node {
  public:
    int value;
    node* next;
};

void push(node **head, int a) {
  node *new_node = new node;

  new_node->value = a;
  new_node->next = NULL;

  if (head == NULL) {
    *head = new_node;
    return;
  }

  node *t = *head;
  while (t->next != NULL) {
    t = t->next;
  }
  t->next = new_node;
}

void print(node *head) {
  while (head != NULL) {
    std::cout << head->value << ' ';
    head = head->next;
  }
  std::cout << '\n';
}

void solve(node **head, int k) {
  if (k == 0) return;

  node* current = *head;

  int cnt = 1;
  while (cnt < k && current != NULL) {
    current = current->next;
    cnt += 1;
  }

  if (current == NULL) return;

  // add the remaining elements at the start
  node *start = current;

  while (current->next != NULL) {
    current = current->next;
  }

  current->next = *head;

  *head = start->next;

  start->next = NULL;
}

int main() {
  int n, k, a;

  node *p = new node;

  std::cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    std::cin >> a;

    push(&p, a);
  }

  solve(&p, k);
  print(p);
  return 0;
}
