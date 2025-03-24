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
            positions[i][j] = new Position(j, i); // Initialize each position
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
  throw runtime_error("Not yet implemented: Maze::getNeighbors");
}
