#include <atomic>
#include <iostream>

using namespace std;

template<typename T>
struct Node
{
    T data;
    Node *next;
    Node(const T &val):data(val),next(nullptr){}
};

template<typename T>
class Stack
{
private:
    std::atomic<Node<T>*> head ;
public:
    void push(const T &data)
    {
        Node<T> *new_node = new Node<T>(data);
        new_node->next = head.load(std::memory_order_relaxed);
        while(!head.compare_exchange_weak(new_node->next, new_node,
                                        std::memory_order_release,
                                        std::memory_order_relaxed));
    }

    void show()
    {
        Node<T> *pt = head.load();
        while (nullptr != pt) {
                cout << "val:" << pt->data << endl;
                pt = pt->next;
        }
    }
};

int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    s.show();
    return 0;
}
