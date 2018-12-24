#include <iostream>
#include <vector>
#include "deque.h"

using namespace std;

int main() {
    Deque<int> ints;
    Deque<string> strings;

    while (true) {
        string op;
        cin >> op;
        if (op == "exit")
            break;
        string type;
        cin >> type;
        if (op == "push_back") {
            if (type == "int") {
                int value;
                cin >> value;
                ints.push_back(value);
            }
            if (type == "string") {
                string value;
                cin >> value;
                strings.push_back(value);
            }
        }
        if (op == "push_front") {
            if (type == "int") {
                int value;
                cin >> value;
                ints.push_front(value);
            }
            if (type == "string") {
                string value;
                cin >> value;
                strings.push_front(value);
            }
        }
        if (op == "pop_back") {
            if (type == "int") {
                cout << ints.pop_back() << endl;
            }
            if (type == "string") {
                cout << strings.pop_back() << endl;
            }
        }
        if (op == "pop_front") {
            if (type == "int") {
                cout << ints.pop_front() << endl;
            }
            if (type == "string") {
                cout << strings.pop_front() << endl;
            }
        }
        if (op == "set") {
            if (type == "int") {
                int index, value;
                cin >> index >> value;
                ints.insert(value, index);
            }
            if (type == "string") {
                int index;
                string value;
                cin >> index >> value;
                strings.insert(value, index);
            }
        }
        if (op == "get") {
            int index;
            cin >> index;
            if (type == "int") {
                cout << ints.get(index) << endl;
            }
            if (type == "string") {
                cout << strings.get(index) << endl;
            }
        }
    }
}