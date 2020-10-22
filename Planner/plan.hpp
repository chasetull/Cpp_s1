#include <string>
#include <iostream>

using namespace std;

struct ClassNode
{
    string name;
    string assignments[5];
    ClassNode *next;
    int numFull;
};

class Planner{
    private:
        ClassNode *root;
        bool isSaved;

    public:
        Planner(); //constr
        ~Planner(); //destr
        void addAss(string, string);
        void deleteAss(string, string);
        void deleteClass(string);
        void saveall(string);
        void addClass(string);
        void printall();
        ClassNode* searchClass(string);
        bool isSave();
        void readData(string);
};

void printAss(ClassNode*);