#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

template<class T>
void clear(T&);

bool checkStack(stack<int>& s, int value);
bool checkQueue(queue<int>& q, int value);
bool checkPriorityQueue(priority_queue<int>& p_q, int value);


main()
{
    int cmdNum;
    int request, value;
    priority_queue<int>p_q;
    stack<int>s;
    queue<int>q;


    while(scanf("%d", &cmdNum) == 1) {
        bool isStack = true, isQueue = true, isPriorityQueue = true;
        clear(p_q);
        clear(s);
        clear(q);

        while(cmdNum--) {
            scanf("%d%d", &request, &value);
            if (request == 1) {
                if (isPriorityQueue)
                    p_q.push(value);

                if (isStack)
                    s.push(value);

                if (isQueue)
                    q.push(value);
            } else if (request == 2) {
                if (isStack)
                    isStack = checkStack(s, value);

                if (isQueue)
                    isQueue = checkQueue(q, value);

                if (isPriorityQueue)
                    isPriorityQueue = checkPriorityQueue(p_q, value);
            }
        }

        if (isStack && !isQueue && !isPriorityQueue)
            printf("stack\n");
        else if (!isStack && isQueue && !isPriorityQueue)
            printf("queue\n");
        else if (!isStack && !isQueue && isPriorityQueue)
            printf("priority queue\n");
        else if (!isStack && !isQueue && !isPriorityQueue)
            printf("impossible\n");
        else
            printf("not sure\n");
    }
}


template<class T>
void clear(T& container) {
    while (!container.empty())
        container.pop();
}

bool checkStack(stack<int>& s, int value) {
    if (s.empty())
        return false;
    int top = s.top();
    s.pop();
    return top == value;
}

bool checkQueue(queue<int>& q, int value) {
    if (q.empty())
        return false;
    int front = q.front();
    q.pop();
    return front == value;
}

bool checkPriorityQueue(priority_queue<int>& p_q, int value) {
    if (p_q.empty())
        return false;
    int top = p_q.top();
    p_q.pop();
    return top == value;
}
