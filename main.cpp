// test file for LinkedQueue class
#include "LinkedQueue.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;


int main() {
    LinkedQueue<int> q;

    // Test enqueue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front: " << q.front() << endl; // Expected: 10
    cout << "Back: " << q.back() << endl;   // Expected: 30
    cout << "Length: " << q.getLength() << endl; // Expected: 3

    // Test dequeue
    q.dequeue();
    cout << "Front after dequeue: " << q.front() << endl; // Expected: 20
    cout << "Length after dequeue: " << q.getLength() << endl; // Expected: 2

    // Test clear
    q.clear();
    cout << "Length after clear: " << q.getLength() << endl; // Expected: 0
    cout << "Is empty after clear: " << (q.isEmpty() ? "Yes" : "No") << endl; // Expected: Yes

    // Test underflow error on front
    try {
        q.front();
    } catch (const std::underflow_error& e) {
        cout << "Caught exception on front from empty queue: " << e.what() << endl;
    }

    // Test underflow error on back
    try {
        q.back();
    } catch (const std::underflow_error& e) {
        cout << "Caught exception on back from empty queue: " << e.what() << endl;
    }

    // Test underflow error on dequeue
    try {
        q.dequeue();
    } catch (const std::underflow_error& e) {
        cout << "Caught exception on dequeue from empty queue: " << e.what() << endl;
    }

    return 0;
}