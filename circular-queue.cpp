#include "circular-queue.h"
#include <iostream>

using namespace std;

const CircularQueue::QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue() {
    capacity_ = 16;
    items_ = new QueueItem [capacity_];
    size_ = 0;
    head_ = 0;
    tail_ = 0;


}

CircularQueue::CircularQueue(unsigned int capacity) {
    capacity_ = capacity;

    items_ = new QueueItem [capacity];
    size_ = 0;
    head_ = 0;
    tail_ = 0;


}

CircularQueue::~CircularQueue() {
    delete [] items_;
    items_ = nullptr;

}

unsigned int CircularQueue::size() const {
    return size_;
}

bool CircularQueue::empty() const {
    return (size_ == 0)? true : false;
}

bool CircularQueue::full() const {
    return (size_== capacity_)? true: false;
}

CircularQueue::QueueItem CircularQueue::peek() const {
    if (empty())
        return CircularQueue::EMPTY_QUEUE;
    else
        return items_[head_];
}

bool CircularQueue::enqueue(QueueItem value) {
    if (full())
        return false;
    else
    {
        items_[tail_] = value;
        size_++;
        if (full())
            tail_ = head_;
        else
            tail_ = (tail_+1) % capacity_;
        return true;
    }

}

CircularQueue::QueueItem CircularQueue::dequeue() {
    if (empty())
        return CircularQueue::EMPTY_QUEUE;
    else
    {
        QueueItem temp = items_[head_];
        head_ = (head_+1) % capacity_;
        size_--;
        return temp;
    }

}

void CircularQueue::print() const {

    cout << "printing queue" << endl;
    if (empty())
    {
        cout << "the queue is empty" << endl;
        return;
    }
    else
    {
        int i = 0;
        int temp = head_;
        while (i < size_) {
            cout << items_[temp] << "-> ";
            temp = (temp + 1) % capacity_;
            i++;
    }
        cout << endl;
        return;
    }
}