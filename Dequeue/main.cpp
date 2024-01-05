#include <stdio.h>
#include <iostream>
#include <string>
#include "Dequeue.h"
// STL is not allowed.

using namespace std;

int main(){
    Dequeue<int> deque(10, 5);
    deque.display();
    deque.push_back(10);
    deque.push_back(15);
    deque.push_back(16);
    deque.display();
    deque.resize(20, 0);
    deque.display();
    deque.resize(13, 0);
    deque.display();
    deque.resize(20, 0);
    deque.display();
    deque.resize(13, 0);
    deque.display();
    deque.pop_back();
    deque.pop_back();
    deque.pop_back();
    deque.display();
    deque.push_front(10);
    deque.push_front(15);
    deque.push_front(16);
    deque.display();
    deque.pop_front();
    deque.pop_front();
    deque.pop_front();
    deque.display();
    cout << deque.front() << endl;
    cout << deque.back() << endl;
    cout << deque.size() << endl;
    return 0;
}
