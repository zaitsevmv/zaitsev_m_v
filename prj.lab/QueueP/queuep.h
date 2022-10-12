#ifndef QUEUEP_H
#define QUEUEP_H

#include <iostream>
using std::unique_ptr;

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

#endif // QUEUER_H
