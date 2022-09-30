#ifndef QUEUER_H
#define QUEUER_H

class QueueR
{
public:
    struct Node{
        Node(const int value);
        ~Node() = default;

        int value;

        Node* nextNode;
    };

    QueueR() {}
    ~QueueR();

    QueueR(const QueueR& copy);
    QueueR& operator=(const QueueR& copy);

    QueueR& push(const int value);
    QueueR& pop();

    const int top();

    QueueR& clear();

    Node* front();

    Node* back();

    bool isEmpty() const;

private:
    int count = 0;
    Node* lastNode;
};

#endif // QUEUER_H
