#include "MovieTree.hpp"
//#include "HelperFuncs.hpp"
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
  root = NULL;
}

MovieTree::~MovieTree() {
  //write your code
  destroyNode(root);
}

void MovieTree::printMovieInventory() {
  //write your code
  if (root == NULL)
  {
    cout << "Tree is empty. Cannot print" << endl;
  }
  else
  {
    printMovieInventoryHelper(root);
  }
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
  //write your code
  root = addMovieNodeHelper(root, ranking, title, year, rating);
}

void MovieTree::findMovie(string title) {
  //write your code
  MovieNode *f = findMovieHelper(root, title);

  if (f == NULL)
  {
    cout << "Movie not found." << endl;
  }
  else
  {
    cout << "Movie Info:" << endl;
    cout << "Rank: " << f->ranking << endl;
    cout << "Title: " << f->title << endl;
    cout << "Year: " << f->year << endl;
    cout << "Rating: " << f->rating << endl;
  }
  
}

void MovieTree::queryMovies(float rating, int year) {
  //write your code
  if (root == NULL)
  {
    cout << "Tree is empty. Cannot query movies" << endl;
  }
  else
  {
    cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
    queryMoviesHelper(root, rating, year);
  }
}

void MovieTree::averageRating() {
  //write your code
  float avg = 0;
  if (root == NULL)
  {
    cout << "Average Rating:0.0" << endl;
  }
  else
  {
    cout << "Average rating: " << averageRatingHelper(root, avg) << endl;
  }
}

void MovieTree::printLevelNodes(int k) {
  //write your code
  int d = getdepth(root);
  if (d >= k)
  {
    //print nodes
    printLevelNodesHelper(k, root);
  }
    
}




/* ===== HELPER FUNCS ===== */




void printMovieInventoryHelper(MovieNode *mn) //prints titles ALPHABETICALLY
{
  if (mn)
  {
    printMovieInventoryHelper(mn->left);
    cout << "Movie: " << mn->title << " " << mn->rating << endl;
    printMovieInventoryHelper(mn->right);
  }
  
}

MovieNode* addMovieNodeHelper(MovieNode* node, int rk, string tl, int yr, float rt)
{
  if (node == NULL)
  {
    return getMovieNode(rk, tl, yr, rt);
  }
  else if ( node->title.compare(tl) < 0 )
  {
    node->right = addMovieNodeHelper(node->right, rk, tl, yr, rt);
  }
  else if ( node->title.compare(tl) > 0 )
  {
    node->left = addMovieNodeHelper(node->left, rk, tl, yr, rt);
  }
  return node;
}

MovieNode* findMovieHelper(MovieNode *node, string titl)
{
  if (node == NULL)
  {
    return NULL;
  }

  if (node->title.compare(titl) == 0)
  {
    return node;
  }

  if(node->title.compare(titl) > 0)
  {
    return findMovieHelper(node->left, titl);
  }

  return findMovieHelper(node->right, titl);
}

float averageRatingHelper(MovieNode *node, float totAvg)
{

  if (node)
  {
    averageRatingHelper(node->left, totAvg);
    averageRatingHelper(node->right, totAvg);
    totAvg = totAvg + node->rating;
    
  }

  //cout << "Average rating: " << totAvg / totNodes << endl;
  return totAvg;
}

void queryMoviesHelper(MovieNode *node, float rating, int year)
{
  if (node)
  {
    if (node->rating >= rating && node->year > year)
    {
      cout << node->title << "(" << node->year << ") " << node->rating << endl;
      
    }
    queryMoviesHelper(node->left, rating, year);
    queryMoviesHelper(node->right, rating, year);
  }
}

int getdepth(MovieNode *node)
{
  if (node == NULL)
  {
    return 0;
  }
  else
  {
    int d1 = getdepth(node->left);
    int d2 = getdepth(node->right);

    if (d1 > d2)
    {
      return (d1+1);
    }
    else
    {
      return (d2+1);
    }
  }
}

void printLevelNodesHelper(int k, MovieNode *node)
{
  if (node == NULL)
    {
      return;
    }
  else if (k == 0)
  {
    cout << "Movie: " << node->title << " " << node->rating << endl;
    return;
  }
  else
  {
    printLevelNodesHelper(k-1, node->left);
    printLevelNodesHelper(k-1, node->right);
  }
}

void destroyNode(MovieNode *node)
{
  if(node!=NULL)
  {
    destroyNode(node->left);
    destroyNode(node->right);

    delete node;
    node = NULL;
  }
}