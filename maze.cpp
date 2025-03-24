#include <stdexcept>

/* STL libraries needed */
#include <stack>
#include <queue>
#include <vector>

/* library for reverse function */
#include <algorithm>
/* there is a function called "reverse" in this library that can reverse the elements of a vector
 * call it as follows:
 * reverse(v.begin(), v.end()); // this reverses the order of the elements in vector v
 */

#include "maze.h"
#include "myDictionary.h"
using namespace std;

Maze::Maze(int width, int height) {
    positions = new Position **[height];
    for (int i = 0; i < height; ++i) {
        positions[i] = new Position *[width];
        for (int j = 0; j < width; ++j) {
            positions[i][j] = new Position(j, i);
        }
    }
}

Maze::~Maze() {
    int mazeHeight = positions[0][0]->getX();

    for (int i = 0; i < mazeHeight; ++i) {
        int mazeWidth = positions[0][0]->getY();

        for (int j = 0; j < mazeWidth; ++j) {
            delete positions[i][j];
        }
        delete[] positions[i];
    }
    delete[] positions;
}

int Maze::getWidth() {
    int mazeWidth = positions[0][0]->getY();
    return mazeWidth;
}

int Maze::getHeight() {
    int mazeHeight = positions[0][0]->getX();
    return mazeHeight;
}

bool Maze::isWall(int x, int y) {
  return positions[y][x]->isWall();
}

void Maze::setWall(int x, int y) {
    positions[y][x]->setWall();
}

vector<Position*> Maze::solveBreadthFirst() {
  /* you will need an unordered_map to store the previous of each position */
  /* the keys for this map are the to_string of a position object
   * the associated value should be a pointer to the Position from which
   * you saw the key
   */
    std::queue<Position*> queue;
    std::unordered_map<string, Position*> previous; // key (current (x,y), previous
    std::vector<Position*> path;

    int height = getHeight();
    int width = getWidth();

    // Start at (0,0)
    Position* start = positions[0][0];
    queue.push(start);
    previous[start->to_string()] = nullptr; // No previous position for the start

    while (!queue.empty()) {
        Position* current = queue.front();
        queue.pop();

        // Check if we've reached the bottom-right corner
        if (current == positions[height - 1][width - 1]) {
            // Reconstruct the path
            Position* step = current;
            while (step != nullptr) {
                path.insert(path.begin(), step); // Add steps to the start of the path
                step = previous[step->to_string()]; // Follow breadcrumbs
            }
            return path;
        }

        // Explore neighbors
        for (Position* neighbor : getNeighbors(current)) {
            if (previous.find(neighbor->to_string()) == previous.end()) { // Not visited
                queue.push(neighbor);
                previous[neighbor->to_string()] = current; // Track previous position
            }
        }
    }

    return {};
}

vector<Position*> Maze::solveDepthFirst() {
  /* you will need an unordered_map to store the previous of each position */
  /* the keys for this map are the to_string of a position object
   * the associated value should be a pointer to the Position from which
   * you saw the key
   */
    std::stack<Position*> stack;                              // Stack to manage DFS exploration
    std::unordered_map<std::string, Position*> previous;      // Tracks breadcrumbs (visited positions)
    std::vector<Position*> path;                              // Final path to be returned

    // Starting position (top-left corner)
    Position* start = positions[0][0];
    stack.push(start);
    previous[start->to_string()] = nullptr;

    while (!stack.empty()) {
        Position* current = stack.top();
        stack.pop();

        // check if reached goal
        if (current == positions[getHeight() - 1][getWidth() - 1]) {
            Position* step = current;
            while (step != nullptr) {
                path.insert(path.begin(), step); // add to start of path
                step = previous[step->to_string()];
            }
            return path; // Return the full path from start to goal
        }
        for (Position* neighbor : getNeighbors(current)) {
            if (previous.find(neighbor->to_string()) == previous.end()) { // if  neighbor not  visited
                stack.push(neighbor); // add neighbor to stack
                previous[neighbor->to_string()] = current;
            }
        }
    }
    // else, return an empty vector
    return {};
}

vector<Position*> Maze::getNeighbors(Position* position) {
    std::vector<Position*> neighbors;
    int x = position->getX();
    int y = position->getY();

    int width = positions[0][0]->getY();
    int height = positions[0][0]->getX();

    // up
    if (y > 0 && !positions[y - 1][x]->isWall()) {
        neighbors.push_back(positions[y - 1][x]);
    }
    // left
    if (x > 0 && !positions[y][x - 1]->isWall()) {
        neighbors.push_back(positions[y][x - 1]);
    }
    // right
    if (x < width - 1 && !positions[y][x + 1]->isWall()) {
        neighbors.push_back(positions[y][x + 1]);
    }
    // down
    if (y < height - 1 && !positions[y + 1][x]->isWall()) {
        neighbors.push_back(positions[y + 1][x]);
    }

    return neighbors;
}
