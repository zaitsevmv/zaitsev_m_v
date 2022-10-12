#include <iostream>
#include "queuep.h"

QueueP::Node::Node(const int value)
    :value(value){

}

QueueP& QueueP::push(const int value){
    std::unique_ptr<Node> elem(new Node(value));
    if(0 == count){
        elem->nextNode = nullptr;
        lastNode = std::move(elem);
        count = 1;
        return *this;
    }
    elem->nextNode = std::move(lastNode);
    lastNode = std::move(elem);
    count++;
    Node* i(nullptr);
    for(i = lastNode.get(); i->nextNode.get() != nullptr; i = i->nextNode.get()){
        if(i->value < i->nextNode->value){
            std::swap(i->value,i->nextNode->value);
        } else{
            break;
        }
    }
    i = nullptr;
    return *this;
}

QueueP& QueueP::pop(){
    if(count > 1){
        Node* secondNode;
        for(secondNode = lastNode.get(); secondNode->nextNode->nextNode.get() != nullptr; secondNode = secondNode->nextNode.get());
        secondNode->nextNode = nullptr;
        count--;
        secondNode = nullptr;
    } else if(count == 1){
        lastNode = nullptr;
        count = 0;
    }
    return *this;
}

const int QueueP::top(){
    if(count > 0){
        return this->front()->value;
    } else{
        return -1;
    }
}

QueueP& QueueP::clear(){
    for(int i = 0; i < count; i++){
        this->pop();
    }
    return *this;
}

QueueP::Node* QueueP::front(){
    if(count > 0){
        Node* firstNode = lastNode.get();
        while(firstNode->nextNode.get() != nullptr){
            firstNode = firstNode->nextNode.get();
        }
        return firstNode;
        firstNode = nullptr;
    } else{
        return nullptr;
    }
}

QueueP::Node* QueueP::back(){
    if(count > 0){
        return lastNode.get();
    } else{
        return nullptr;
    }
}

QueueP::~QueueP(){
    this->clear();
}

bool QueueP::isEmpty() const{
    bool isEmpty = true ? count == 0 : false;
    return isEmpty;
}
