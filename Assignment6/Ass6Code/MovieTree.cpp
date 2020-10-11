#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST
MovieNode* getMovieNode(int rank, string t, int y, float r) {
    MovieNode* nn = new MovieNode;
    nn->title = t;
    nn->ranking = rank;
    nn->year = y;
    nn->rating = r;
    return nn;
}

MovieTree::MovieTree() {
  //write your code
}

MovieTree::~MovieTree() {
  //write your code
}

void MovieTree::printMovieInventory() {
   //write your code
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
  //write your code
}

void MovieTree::findMovie(string title) {
  //write your code
}

void MovieTree::queryMovies(float rating, int year) {
  //write your code
}

void MovieTree::averageRating() {
  //write your code
}

void MovieTree::printLevelNodes() {
  //write your code
}
