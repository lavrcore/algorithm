//Linked list
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class LinkedList
{
    struct Node
    {
        T val;
        shared_ptr <Node> next;
        Node(T val) : val(val), next(nullptr) {}
    };
    shared_ptr <Node> head;

public:
    LinkedList() : head(nullptr) {}
    void add(T val)
    {
        shared_ptr <Node> newNode = make_shared <Node>(val);
        if (this->head == nullptr)
        {
            this->head = newNode;
        }
        else 
        {
            shared_ptr <Node> cur = this->head;
            while (cur->next != nullptr)
            {
                cur = cur->next;

            }
            cur->next = newNode;
        }
    }
    void remove(T val)
    {
        shared_ptr <Node> cur = this->head;
        shared_ptr <Node> prev = nullptr;
        while (cur != nullptr && cur->val != val)
        {
            prev = cur;
            cur = cur->next;
        }
        if (cur == nullptr)
        {
            return;
        }
        else if (prev == nullptr)
        {
            this->head = this->head->next;
        }
        prev->next = cur->next;
        
    }
    void reverse()
    {
        shared_ptr <Node> prev = nullptr;
        shared_ptr <Node> cur = this->head;
        shared_ptr <Node> next;
        while (cur != nullptr)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        this->head = prev;
    }
    void show()
    {
        shared_ptr <Node> current = this->head;
        while(current != nullptr)
        {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;

    }

};
template <typename T>
int solve(shared_ptr <typename LinkedList<T>::Node> head)
{
    shared_ptr <vector <T>> nums = make_shared<vector <T>>();
    while (head != nullptr)
    {
        nums->push_back(head->val);
        head = head->next;

    }
    int res = 0;
    for (int i = 0; i < nums->size(); i++)
    {
        res += nums->operator[](i)* pow(2,num->size-1-i);
    }
    
}
int main()
{
    LinkedList <int> ll;
    ll.add(111);
    ll.add(20);
    ll.add(1);
    ll.add(0);
    ll.show();
    //ll.remove(1);
    ll.show();
    ll.reverse();
    ll.show();
    cout << solve<int>(ll.head);

}
