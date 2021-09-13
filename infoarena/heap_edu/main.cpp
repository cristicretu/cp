#include <iostream>
//#include <algorithm>

int heap[100] = {4, 7, 5, 9, 10, 8, 9, 15, 20, 13, 18, 14};
int n = 12;

inline void mySwap(int x, int y)
{
    std::swap(heap[x], heap[y]);
}

void upHeap(int node)
{
//    int parent = node / 2;
//    while (parent > 0)
//    {
//        if (heap[parent] > heap[node])
//        {
//            mySwap(parent, node);
//        }
//
//        node = parent;
//        parent = node / 2;
//    }

    int parent = node / 2;

    if (parent && heap[parent] > heap[node])
    {
        mySwap(node, parent);
        upHeap(parent);
    }
}

void downHeap(int node) {
    int child = node * 2;

    if (child + 1 <= n && heap[child + 1] < heap[child])
    {
        child += 1;
    }

    if (child <= n && heap[child] < heap[node])
    {
        mySwap(child, node);
        downHeap(child);
    }

}

void pop()
{
    mySwap(0, n);
    n -= 1;
    downHeap(0);
}

int peak()
{
    return heap[0];
}

void insert(int node)
{
    n += 1;
    heap[n] = node;
    upHeap(n);
}



int main()
{
//    std::cout << peak() << '\n';
    insert(1);

//    std::cout << peak() << '\n';
//    for (int i = 0; i < n; ++i, std::cout << '\n')
//    {
//        std::cout << heap[i] << ' ';
//    }
    return 0;
}
