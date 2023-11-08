#include "dynamic-stack.h"
#include <iostream>

using namespace std;

const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack() {
    init_capacity_= 16;
    items_ = new StackItem[init_capacity_];
    size_ = 0;
    capacity_ = 16;
}

DynamicStack::DynamicStack(unsigned int capacity){
    init_capacity_ = capacity;
    items_ = new StackItem[capacity];
    size_ = 0;
    capacity_ = capacity;
}

DynamicStack::~DynamicStack() {
    delete [] items_;
    items_ = nullptr;
}

unsigned int DynamicStack::size() const {
    return size_;

}

bool DynamicStack::empty() const {
    return (size_ == 0) ? true: false;

}

DynamicStack::StackItem DynamicStack::peek() const
{
    return (empty()) ? (DynamicStack::EMPTY_STACK) : (items_[size_-1]);

}

void DynamicStack::push(StackItem value) {
    if (size_ == capacity_)
    {
        capacity_ = capacity_*2;
        //double capacity if size has reached capacity

        StackItem *items_2 = new StackItem[capacity_];
        for (int i = 0; i < size_; i++)
        {
            items_2[i] = items_[i];
        }

        delete [] items_;
        items_ = items_2;
        items_2 = nullptr;

        items_[size_] = value;
        size_++;
        return;

    }
    else
    {
        items_[size_]= value;
        size_++;
        return;
    }


}

DynamicStack::StackItem DynamicStack::pop() {
    if (empty())
        return DynamicStack::EMPTY_STACK;

    StackItem tempVal = items_[size_-1];
    size_--;

    if (size_ <= (0.25*capacity_) &&  //once size is less than a quarter of capacity, reduce capacity
    ((0.5 * capacity_) >= init_capacity_)) //cannot make capacity less than initial capacity
    {
        capacity_ = capacity_*0.5;

        StackItem *items_2 = new StackItem [capacity_];
        for (int i = 0; i < size_; i++)
        {
            items_2[i] = items_[i];
        }
        delete items_;
        items_ = items_2;

    }
    return tempVal;


}

void DynamicStack::print() const {
    cout << "-----printing stack----" << endl;
    for (int i = size_-1; i >= 0; i--)
    {
        cout << "element number " << size_-i << ": " << items_[i] << endl;
    }

    return;
}
