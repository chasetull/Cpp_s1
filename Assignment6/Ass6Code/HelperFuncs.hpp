#include <string>
//#include "MovieTree.hpp"

using namespace std;

void printMovieInventoryHelper(MovieNode*);
MovieNode* addMovieNodeHelper(MovieNode*, int, string, int, float);
MovieNode* findMovieHelper(MovieNode*, string);
float averageRatingHelper(MovieNode*, float);
void queryMoviesHelper(MovieNode *node, float rating, int year);
int getdepth(MovieNode*);
void printLevelNodesHelper(int, MovieNode*);
void destroyNode(MovieNode*);