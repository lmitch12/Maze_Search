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
  throw runtime_error("Not yet implemented: Maze::solveBreadthFirst");
}

vector<Position*> Maze::solveDepthFirst() {
  /* you will need an unordered_map to store the previous of each position */
  /* the keys for this map are the to_string of a position object
   * the associated value should be a pointer to the Position from which
   * you saw the key
   */
  throw runtime_error("Not yet implemented: Maze::solveDepthFirst");
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
