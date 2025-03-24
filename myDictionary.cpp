//
// Created by mitch on 3/20/2025.
//

#include "myDictionary.h"
#include <unordered_map>
#include <iostream>
using namespace std;

myDictionary::myDictionary() : head(nullptr), tail(nullptr) {}

myDictionary::~myDictionary() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

string myDictionary::to_string(int x, int y) const {
    return std::to_string(x) + "," + std::to_string(y);
}

void myDictionary::add(int currentX, int currentY, int prevX, int prevY) {
    std::string key = to_string(currentX, currentY);
    dictionary[key] = make_pair(prevX, prevY);
}

pair<int, int> myDictionary::getPrevious(int currentX, int currentY) const {
    string key = to_string(currentX, currentY);
    for (const pair<string, pair<int, int>>& entry : dictionary) {
        if (entry.first == key) {
            return entry.second;
        }
    }
    throw runtime_error("Position not found in dictionary");
}

void myDictionary::tracePath(int endX, int endY) {

    int currentX = endX;
    int currentY = endY;

    while (true) {
        Node* newNode = new Node(currentX, currentY);

        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        pair<int, int> previous = getPrevious(currentX, currentY);

        if (previous.first == currentX && previous.second == currentY) {
            throw runtime_error("Path tracing incomplete");
        }
    }
}

// Print the traced path stored in the doubly linked list
void myDictionary::printPath() const {
    Node* current = head;

    std::cout << "Path: ";
    while (current) {
        cout << "(" << current->x << ", " << current->y << ")";
        if (current->next) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}