#include <iostream>

struct Node {
  int data;
  Node* next;
};

class LinkedList {
  private: 
    Node* head;
  public:
    LinkedList() {
      head = NULL;
    }

    void push_back(int element) {
      Node* newNode = new Node();

      newNode->data = element;
      newNode->next = NULL;

      if (head == NULL) {
        head = newNode;
      } else {
        Node* temp = head;

        while (temp->next != NULL) {
          temp = temp->next;
        }
        temp->next = newNode;
      }
    }

    void push_front(int element) {
      Node* newNode = new Node();

      newNode->data = element;
      newNode->next = head;

      head = newNode;
    }

    void print_list() {
      Node* temp = head;

      if (temp != NULL) {
        while (temp != NULL) {
          std::cout << temp->data << ' ';
          temp = temp->next;
        }
        std::cout << '\n';
      } else {
        std::cout << "The list is empty.\n";
      }
    }

    void rotate_list(int k) {
      if (k == 0) return; 

      Node* current = head;

      int count = 1;
      while (count < k && current != NULL) {
        count++;
        current = current->next;
      }

      if (current == NULL) return;

      Node* toRotate = current;

      while (current->next != NULL) {
        current = current->next;
      }

      current->next = head;

      head = toRotate->next;

      toRotate->next = NULL;
    }
};

int main() {
  LinkedList list;

  int n, k, a;
  std::cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    std::cin >> a;

    list.push_back(a);
  }

  list.print_list();

  list.rotate_list(k);

  list.print_list();
}
