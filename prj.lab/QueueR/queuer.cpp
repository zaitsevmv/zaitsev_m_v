#include <iostream>
#include "queuer.h"

QueueR::Node::Node(const int value)
    :value(value){

}

QueueR& QueueR::push(const int value){
    Node* elem = new Node(value);
    if(0 == count){
        elem->nextNode = nullptr;
        lastNode = elem;
        count = 1;
        return *this;
    }
    elem->nextNode = lastNode;
    lastNode = elem;
    count++;
    for(Node* i = lastNode; i->nextNode != nullptr; i = i->nextNode){
        if(i->value < i->nextNode->value){
            std::swap(i->value,i->nextNode->value);
        } else{
            break;
        }
    }
    return *this;
}

QueueR& QueueR::pop(){
    if(count > 1){
        Node* secondNode;
        for(secondNode = lastNode; secondNode->nextNode->nextNode != nullptr; secondNode = secondNode->nextNode);
        delete secondNode->nextNode;
        secondNode->nextNode = nullptr;
        count--;
    } else if(count == 1){
        lastNode = nullptr;
        count = 0;
    }
    return *this;
}

const int QueueR::top(){
    if(count > 0){
        return this->front()->value;
    } else{
        return -1;
    }
}

QueueR& QueueR::clear(){
    for(int i = 0; i < count; i++){
        this->pop();
    }
    return *this;
}

QueueR::Node* QueueR::front(){
    if(count > 0){
        Node* firstNode;
        for(firstNode = lastNode; firstNode->nextNode != nullptr; firstNode = firstNode->nextNode);
        return firstNode;
        delete firstNode;
        firstNode = nullptr;
    } else{
        return nullptr;
    }
}

QueueR::Node* QueueR::back(){
    if(count > 0){
        return lastNode;
    } else{
        return nullptr;
    }
}

QueueR::~QueueR(){
    this->clear();
    delete lastNode;
}

bool QueueR::isEmpty() const{
    bool isEmpty = true ? count == 0 : false;
    return isEmpty;
}
