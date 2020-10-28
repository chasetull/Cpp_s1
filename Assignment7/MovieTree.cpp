#include <iostream>
#include <fstream>
#include <string>
#include "MovieTree.hpp"

using namespace std;

LLMovieNode* getLLMovieNode(int r, std::string t, int y, float q)
{
	LLMovieNode* lmn =new LLMovieNode();
	lmn->ranking = r;
	lmn->title=t;
	lmn->year =y;
	lmn->rating =q;
	lmn->next =NULL;
	return lmn;
}

/* HELPER FUNCTIONS */
/* ------------------------------------------------------ */
void helpShowMovieCollection(TreeNode *tn)
{
	if (tn != NULL)
	{
		helpShowMovieCollection(tn->leftChild);

		cout << "Movies starting with letter: " << tn->titleChar << endl;
		LLMovieNode *lm = tn->head;

		while (lm != NULL)
		{
			cout << " >> " << lm->title << " " << lm->rating << endl;
			lm = lm->next;
		}

		helpShowMovieCollection(tn->rightChild);
	}

}

TreeNode* helpInsertMovie(TreeNode* &tn, TreeNode* newNode)
{
	if (tn == NULL)
	{
		return newNode;
	}
	if (newNode->titleChar < tn->titleChar)
	{
		TreeNode *leftNode = helpInsertMovie(tn->leftChild, newNode);
		tn->leftChild = leftNode;
		leftNode->parent = tn;
	}
	else if (newNode->titleChar > tn->titleChar)
	{
		TreeNode *rightNode = helpInsertMovie(tn->rightChild, newNode);
		tn->rightChild = rightNode;
		rightNode->parent = tn;
	}
	else if (newNode->titleChar == tn->titleChar)
	{
		LLMovieNode *toInsertN = newNode->head;
		LLMovieNode *curr = tn->head;
		LLMovieNode *prevs = NULL;

		while (curr != NULL && curr->title.compare(toInsertN->title) < 0)
		{
			prevs = curr;
			curr = curr->next;
		}

		if (curr != NULL && curr->title.compare(toInsertN->title) == 0)
		{
			return tn;
		}
		else
		{
			if (prevs == NULL)
			{
				toInsertN->next = tn->head;
				tn->head = toInsertN;
			}
			else if (curr == NULL)
			{
				prevs->next = toInsertN;
			}
			else
			{
				prevs->next = toInsertN;
				toInsertN->next = curr;
			}
		}
	}

	return tn;
}

void destroyTree(TreeNode *t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
	
		destroyTree(t->leftChild);
		destroyTree(t->rightChild);
		LLMovieNode* head = t->head;
		LLMovieNode *temp;

		while (head != NULL)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
		delete t;
	}
}

TreeNode* helpRemoveMovieRecord(TreeNode* t, string title)
{
	if (t == NULL)
	{
		cout << "Movie not found." << endl;
		return t;
	}

	if (title.at(0) < t->titleChar)
	{
		t->leftChild = helpRemoveMovieRecord(t->leftChild, title);
	}
	else if (title.at(0) > t->titleChar)
	{
		t->rightChild = helpRemoveMovieRecord(t->rightChild, title);
	}
	else if (title.at(0) == t->titleChar)
	{
		LLMovieNode *currNode = t->head;
		LLMovieNode *prevNode = NULL;

		while (currNode != NULL && currNode->title.compare(title) != 0)
		{
			prevNode = currNode;
			currNode = currNode->next;
		}

		if (currNode == NULL)
		{
			cout << "Movie: " << title << " not found. Cannot delete." << endl;
			return t;
		}
		if (prevNode == NULL && t->head->next != NULL)
		{
			t->head = t->head->next;
			return t;
		}
		if (prevNode != NULL && currNode != NULL)
		{
			prevNode->next = currNode->next;
			return t;
		}
		if (t->leftChild == NULL && t->rightChild == NULL)
		{
			delete t;
			t = NULL;
		}
		else if (t->leftChild == NULL)
		{
			TreeNode *tempNode = t;
			t->rightChild->parent = t->parent;
			t = t->rightChild;
			delete tempNode;
		}
		else if (t->rightChild == NULL)
		{
			TreeNode *tempNode = t;
			t->leftChild->parent = t->parent;
			t = t->leftChild;
			delete tempNode;
		}
		else
		{
			TreeNode *minValNode = t->rightChild;

			while (minValNode->leftChild != NULL)
			{
				minValNode = minValNode->leftChild;
			}
			t->head = minValNode->head;
			t->titleChar = minValNode->titleChar;
			t->rightChild = helpRemoveMovieRecord(t->rightChild, minValNode->head->title);
		}	
	}

	return t;
}

TreeNode* checktitle(TreeNode *&root, string title)
{
   if (root == NULL)
   {
       return NULL;
   }

   if (root->titleChar == title[0])
   {
       return root;
   }
   else if (root->titleChar > title[0])
   {
       return checktitle(root->leftChild, title);
   }
   else
   {
       return checktitle(root->rightChild, title);
   }
}

void deleteTree(TreeNode*& t, char titleChar)
{
   if (t == NULL)
   {
       return;
   }
   else
   {
       if (titleChar < t->titleChar)
       {
           deleteTree(t->leftChild, titleChar);
       }
       else if (titleChar > t->titleChar)
       {
           deleteTree(t->rightChild, titleChar);
       }
       else
       {
           TreeNode* X = t;

           if (t->leftChild == NULL)
           {
               if (t->rightChild != NULL)
                   t->rightChild->parent = t->parent;
               t = t->rightChild;

           }
           else if (t->rightChild == NULL)
           {
               if (t->leftChild != NULL)
                   t->leftChild->parent = t->parent;
               t = t->leftChild;
           }
           else
           {

               findNodeTemp(X, t->rightChild);

           }
           delete X;
       }
   }
}



/* ------------------------------------------------------ */

MovieTree::MovieTree()
{
	root = NULL;
}

MovieTree::~MovieTree()
{
	//destr
	destroyTree(root);

}

void MovieTree::showMovieCollection()
{
	helpShowMovieCollection(root);
}

void MovieTree::insertMovie(int ranking, string title, int year, float rating)
{
	LLMovieNode *m = getLLMovieNode(ranking, title, year, rating);

	TreeNode *newNode = new TreeNode;
	newNode->titleChar = title.at(0);
	newNode->head = m;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	newNode->parent = NULL;

	root = helpInsertMovie(root, newNode);
}

void MovieTree::removeMovieRecord(string title)
{
	//root = helpRemoveMovieRecord(root, title);
	TreeNode* k = checktitle(root, title);
	if (k != NULL && k->head != NULL)
	{
		if (k->head->title == title)
		{
			LLMovieNode* temp = k->head;
			k->head = k->head->next;
			delete temp;
		}
		else
		{
			LLMovieNode* prev = k->head;
			for (LLMovieNode* h = k->head->next; h != NULL; h = h->next)
			{
				if (h->title == title)
				{
					LLMovieNode* temp = h;
					prev->next = h->next;
					delete temp;
					break;
				}
				prev = h;
			}
		}

		if (k->head == NULL)
		{
			deleteTree(root, k->titleChar);
		}
		return;
	}
	cout << "Movie not found." << endl;
	
}

void MovieTree::leftRotation(TreeNode *curr)
{
	TreeNode* right = curr->rightChild;

	if (curr->titleChar == root->titleChar)
	{
		curr->rightChild = right->leftChild;
		right->leftChild = curr;
		right->parent = NULL;
		curr->parent = right;

		if (curr->rightChild != NULL)
		{
			curr->rightChild->parent = curr;
		}

		root = right;
		return;
	}
	if (curr->parent->rightChild->titleChar == curr->titleChar)
	{
		curr->parent->rightChild = right;
	}
	else
	{
		curr->parent->leftChild = right;
	}
	right->parent = curr->parent;
	curr->parent = right;

	curr->rightChild = right->leftChild;

	if (right->leftChild != NULL)
	{
		right->leftChild->parent = curr;
	}
	right->leftChild = curr;
	
}







/* ------------------------------------------------------ */

void _grader_inorderTraversal(TreeNode * root) {
		if (root == NULL) {
			return;
		}

		_grader_inorderTraversal(root->leftChild);
		cout << root->titleChar << " ";
		_grader_inorderTraversal(root->rightChild);
}


void MovieTree::inorderTraversal() {
	_grader_inorderTraversal(root);
	cout << endl;
}



TreeNode* searchCharHelper(TreeNode* curr, char key)
{
    if (curr == NULL)
        return curr;
    else if(curr->titleChar == key)
        return curr;
    else if (curr->titleChar > key)
        return searchCharHelper(curr->leftChild, key);
    else
        return searchCharHelper(curr->rightChild, key);
}

TreeNode* MovieTree::searchCharNode(char key)
{
    return searchCharHelper(root, key);
}
