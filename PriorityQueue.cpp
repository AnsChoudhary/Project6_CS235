
#include "iostream"
using namespace std;
#include "PriorityQueue.hpp"
// sahil computer has gins
template<typename ItemType>
PriorityQueue<ItemType>::PriorityQueue()
{
    item_count=0;
    front_= nullptr;
    back_ = nullptr;
}

template<typename ItemType>
 PriorityQueue<ItemType>::PriorityQueue(const PriorityQueue<ItemType>& a_priority_queue)
{
    /*item_count = 0;
    front_= nullptr;
    back_ = nullptr;

    PriorityNode<ItemType>* current = nullptr;

    for (current = a_priority_queue.front_; current != nullptr; current = current->getNext()) {
        this->enqueue(current->getItem(), current->getPriority());
    }*/

}

template<typename ItemType>
 PriorityQueue<ItemType>::~PriorityQueue()
{
   dequeue();
}

template<typename ItemType>
 void PriorityQueue<ItemType>::enqueue(const ItemType & new_entry, int priority) {
    PriorityNode<ItemType> *newNode = new PriorityNode<ItemType>(new_entry, priority);
    PriorityNode<ItemType> *curr = front_;
    PriorityNode<ItemType> *pre = nullptr;
    bool added = false;

    // assign newNode to the back pointer
    if (front_== nullptr) {
        front_ = back_ = newNode;
        item_count++;
    }
    while (curr != nullptr) {
        if (priority < curr->getPriority()) {
            if (pre != nullptr)
            {
                pre->setNext(newNode);
                newNode->setNext(curr);
            }
            else
       {
                front_ = newNode;
                newNode->setNext(curr);
       }
            added = true;
            break;
        }
        pre = curr;
        curr = curr->getNext();
    }
    if (!added)
    {
        back_->setNext(newNode);
        back_=newNode;
    }
    ++item_count;
}
template<typename ItemType>
 void PriorityQueue<ItemType>::dequeue()
{

}

template<typename ItemType>
 ItemType PriorityQueue<ItemType>::front() const
{

    return front_->getItem();
}

template<typename ItemType>
 PriorityNode<ItemType>* PriorityQueue<ItemType>::getFrontPtr() const
{

    return front_;
}

template<typename ItemType>
 int PriorityQueue<ItemType>::size() const
{
    return item_count;
}

template<typename ItemType>
 bool PriorityQueue<ItemType>::isEmpty() const
{
     if (nullptr==front_&&nullptr == back_&&0 == item_count){
         return true;
     }

}

template<typename ItemType>
void PriorityQueue<ItemType>::print() const {

    PriorityNode<ItemType>* node= front_;
    while(node!= nullptr){
        cout<<"("<<node->getItem()<<","<<node->getPriority()<<")"<<" ";
        node=node->getNext();
    }
    cout<<endl;

}


