#ifndef QUEUE_P_HPP
#define QUEUE_P_HPP

#include <iostream>
#include <memory>

class QueueP
{
private:
    struct Node{
        Node(const int value);
        ~Node() = default;
        int value;

        std::unique_ptr<Node> nextNode;
    };

    int count = 0;
    std::unique_ptr<Node> lastNode;

public:
    QueueP() {}
    ~QueueP();

    QueueP(const QueueP& copy);
    QueueP& operator=(const QueueP& copy);

    QueueP& push(const int value);
    QueueP& pop();

    const int top();

    QueueP& clear();

    Node* front();

    Node* back();

    bool isEmpty() const;
};

#endif