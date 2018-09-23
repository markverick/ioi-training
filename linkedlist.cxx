#include<bits/stdc++.h>
using namespace std;
template<typename T>
struct ListNode
{
    T val;
    ListNode* next;

    ListNode(T v,ListNode* n=0)
    {
        val=v;
        next=n;
    }
    ListNode(ListNode* n=0) : next(n){}
//struct ListNode
//{
//    T val;
//    ListNode* next;
//
//    ListNode(T v,ListNode*n=0)
//        : val(v),next(n)
//    {
//    }
//};
ListNode *header, *tail;
public:
    LinkedList()
    {
        header = new h=ListNode<T>();
        tail=header;
    }
    void.push_back(T x);
};
template<typename T>
void LinkedList::push_back(T x)
{
    ListNode<T>*n = new ListNode<T>(x);
    tail->next = n;
    tail = n;
}
main()
{
    ListNode<int>* n = new ListNode<int> x;
}
