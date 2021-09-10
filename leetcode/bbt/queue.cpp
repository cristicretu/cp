#include <iostream>

using namespace std;

typedef struct node
{
    int value;
    struct node *next;
} node;

void insertFront(node &current, int newData)
{
    node newNode;
    newNode->value = newData;
    newNode->next = current;
    current = newNode;
}

int main()
{
    int n;
    cin >> n;
}