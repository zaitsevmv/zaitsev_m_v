#include "c_queue_p.h"
#include "queue_p.hpp"

#include <map>

class QueueManager {
public:
    QueueManager(QueueManager&& a) = delete;
    QueueManager& operator=(QueueManager&& a) = delete;

    static QueueManager& Instance()
    {
        static QueueManager theSingleInstance;
        return theSingleInstance;
    }

    ErrorCode CreateQueue(QueueHandler* queue){
        QueueHandler newQueueHandler = lastQueueHandler+1;
        lastQueueHandler++;
        try{
            qMap.emplace(std::make_pair(newQueueHandler, QueueP()));
        } catch(...){
            return ErrorCode::kHandlerError;
        }
        *queue = newQueueHandler;
        return ErrorCode::kGood;
    }

    ErrorCode CloneQueue(QueueHandler source, QueueHandler* queue){
        auto thisQueuePair = qMap.find(source);
        if(thisQueuePair == qMap.end()){
            return ErrorCode::kHandlerError;
        }
        QueueP thisQueue = thisQueuePair->second;
        QueueHandler newQueueHandler = lastQueueHandler+1;
        lastQueueHandler++;
        try{
            qMap.emplace(std::make_pair(newQueueHandler, QueueP(thisQueue)));
        } catch(...){
            return ErrorCode::kHandlerError;
        }
        *queue = newQueueHandler;
        return ErrorCode::kGood;
    }

    ErrorCode DestroyQueue(QueueHandler queue){
        auto thisQueuePair = qMap.find(queue);
        if(thisQueuePair == qMap.end()){
            return ErrorCode::kHandlerError;
        }
        qMap.erase(thisQueuePair);
        return ErrorCode::kGood;
    }

    ErrorCode Pop(QueueHandler queue){
        auto thisQueuePair = qMap.find(queue);
        if(thisQueuePair == qMap.end()){
            return ErrorCode::kHandlerError;
        }
        QueueP thisQueue = thisQueuePair->second;
        if(thisQueue.isEmpty()){
            return ErrorCode::kOutOfRange;
        }
        thisQueue.pop();
        return ErrorCode::kGood;
    }

    ErrorCode Push(QueueHandler queue, int32_t value){
        auto thisQueuePair = qMap.find(queue);
        if(thisQueuePair == qMap.end()){
            return ErrorCode::kHandlerError;
        }
        QueueP thisQueue = thisQueuePair->second;
        thisQueue.push(value);
        return ErrorCode::kGood;
    }

    ErrorCode IsEmpty(QueueHandler queue, int32_t* result){
        auto thisQueuePair = qMap.find(queue);
        if(thisQueuePair == qMap.end()){
            return ErrorCode::kHandlerError;
        }
        QueueP thisQueue = thisQueuePair->second;
        thisQueue.isEmpty();
        return ErrorCode::kGood;
    }

    ErrorCode Top(QueueHandler queue, int32_t* result){
        auto thisQueuePair = qMap.find(queue);
        if(thisQueuePair == qMap.end()){
            return ErrorCode::kHandlerError;
        }
        QueueP thisQueue = thisQueuePair->second;
        if(thisQueue.isEmpty()){
            return ErrorCode::kOutOfRange;
        }
        thisQueue.top();
        return ErrorCode::kGood;
    }

    const char* WhatIs(ErrorCode err){
        switch (err) {
            case kGood:
                return "kGood";
            case kHandlerError:
                return "kHandlerError";
            case kOutOfRange:
                return "kOutOfRange";
            default:
                return "Error";
        }
    }

private:
    QueueManager() = default;
    ~QueueManager() = default;

    QueueHandler lastQueueHandler = 0;
    std::map<QueueHandler, QueueP> qMap;
};

extern "C" {
    ErrorCode CreateQueue(QueueHandler* queue) {
        return QueueManager::Instance().CreateQueue(queue);
    };

    ErrorCode CloneQueue(QueueHandler source, QueueHandler* queue) {
        return QueueManager::Instance().CloneQueue(source, queue);
    };

    ErrorCode DestroyQueue(QueueHandler queue) {
        return QueueManager::Instance().DestroyQueue(queue);
    };

    ErrorCode Pop(QueueHandler queue) {
        return QueueManager::Instance().Pop(queue);
    };

    ErrorCode Push(QueueHandler queue, int32_t value) {
        return QueueManager::Instance().Push(queue, value);
    };

    ErrorCode IsEmpty(QueueHandler queue, int32_t* result) {
        return QueueManager::Instance().IsEmpty(queue, result);
    };

    ErrorCode Top(QueueHandler queue, int32_t* result) {
        return QueueManager::Instance().Top(queue, result);
    };

    const char* WhatIs(ErrorCode err) {
        return QueueManager::Instance().WhatIs(err);
    };
}