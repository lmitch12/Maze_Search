//
// Created by mitch on 3/20/2025.
//

#ifndef MAZE_3_MYDICTIONARY_H
#define MAZE_3_MYDICTIONARY_H
#include <unordered_map> // For the dictionary
#include <string>        // For using keys as strings
using namespace std;
// Node for the doubly linked list
struct Node {
    int x;
    int y;
    Node* prev;
    Node* next;

    Node(int xCoord, int yCoord) : x(xCoord), y(yCoord), prev(nullptr), next(nullptr) {}
};

class myDictionary {
private:
    //looked online to determine best way to store coord pain
    std::unordered_map<std::string, std::pair<int, int>> dictionary;

    Node* head;
    Node* tail;

    std::string to_string(int x, int y) const;

public:

    myDictionary();

    ~myDictionary();

    void add(int currentX, int currentY, int prevX, int prevY);

    std::pair<int, int> getPrevious(int currentX, int currentY) const;

    void tracePath(int endX, int endY);

    void printPath() const;
};
#endif //MAZE_3_MYDICTIONARY_H

