#ifndef QUEUER_H
#define QUEUER_H

class QueueR
{
public:
    struct Element{
        Element(const int value);
        ~Element() = default;

        int value;

        Element* nextElem;
    };

    QueueR() {}
    ~QueueR();

    QueueR(const QueueR& copy);
    QueueR& operator=(const QueueR& copy);

    QueueR& push(const int value);
    QueueR& pop();

    int getMin();

    QueueR& clear();

    Element* front();
    Element* back();

    bool isEmpty();

    int size();

private:
    int count = 0;
    Element* firstElem;
    Element* lastElem;
};

#endif // QUEUER_H
