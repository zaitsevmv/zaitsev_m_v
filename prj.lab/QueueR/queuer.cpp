#include "QueueR.h"

QueueR::Element::Element(const int value)
    :value(value){

}

QueueR& QueueR::push(const int value){
    Element* elem = new Element(value);
    if(0 == count){
        lastElem = elem;
        firstElem = elem;
        count = 1;
        return *this;
    }
    elem->nextElem = lastElem;
    lastElem = elem;
    for(Element* i = lastElem; i != firstElem; i = i->nextElem){
        if(i->value < i->nextElem->value){
            std::swap(i->value,i->nextElem->value);
        } else{
            break;
        }
    }
    count++;
    return *this;
}

QueueR& QueueR::pop(){
    if(count > 1){
        Element* secondElem;
        for(secondElem = lastElem; secondElem->nextElem != firstElem; secondElem = secondElem->nextElem);
        delete secondElem->nextElem;
        secondElem->nextElem = nullptr;
        firstElem = secondElem;
        count--;
    } else if(count == 1){
        firstElem = nullptr;
        lastElem = nullptr;
        count = 0;
    }
    return *this;
}

int QueueR::getMin(){
    if(count > 0){
        return firstElem->value;
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

QueueR::Element* QueueR::front(){
    if(count > 0){
        return firstElem;
    } else{
        return nullptr;
    }
}

QueueR::Element* QueueR::back(){
    if(count > 0){
        return lastElem;
    } else{
        return nullptr;
    }
}

QueueR::~QueueR(){
    this->clear();
    delete firstElem;
    delete lastElem;
}

int QueueR::size(){
    return count;
}

bool QueueR::isEmpty(){
    bool isEmpty = true ? count == 0 : false;
    return isEmpty;
}
