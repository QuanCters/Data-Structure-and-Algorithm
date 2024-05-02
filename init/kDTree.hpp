#include "main.hpp"
#include "Dataset.hpp"
/* TODO: Please design your data structure carefully so that you can work with the given dataset
 *       in this assignment. The below structures are just some suggestions.
 */
struct kDTreeNode
{
    vector<int> data;
    int label;
    kDTreeNode *left;
    kDTreeNode *right;
    kDTreeNode(vector<int> data, int label = 0, kDTreeNode *left = nullptr, kDTreeNode *right = nullptr)
    {
        this->data = data;
        this->label = label;
        this->left = left;
        this->right = right;
    }
};

class kDTree
{
private:
    int k;
    kDTreeNode *root;

public:
    kDTree(int k = 2);
    ~kDTree();

    const kDTree &operator=(const kDTree &other);
    kDTree(const kDTree &other);

    void inorderTraversal() const;
    void preorderTraversal() const;
    void postorderTraversal() const;
    int height() const;
    int nodeCount() const;
    int leafCount() const;

    void insert(const vector<int> &point);
    void remove(const vector<int> &point);
    bool search(const vector<int> &point);
    void buildTree(const vector<vector<int>> &pointList, const vector<int> &label);
    void nearestNeighbour(const vector<int> &target, kDTreeNode *best);
    void kNearestNeighbour(const vector<int> &target, int k, vector<kDTreeNode *> &bestList);

    void deleteTree(kDTreeNode *node);
    kDTreeNode *deepCopyTree(kDTreeNode *node);
    void printNode(kDTreeNode *node) const;
    void printInorder(kDTreeNode *node) const;
    void printPreorder(kDTreeNode *node) const;
    void printPostorder(kDTreeNode *node) const;
    int getHeight(kDTreeNode *node) const;
    int numNode(kDTreeNode *node) const;
    void numLeaf(kDTreeNode *node, int &sum) const;
    kDTreeNode *insertNode(kDTreeNode *node, kDTreeNode *newNode, int dimension);
    kDTreeNode *removeNode(kDTreeNode *node, kDTreeNode *parentNode, int dimension);
    bool searchNode(kDTreeNode *node, const vector<int> &point, int dimension);
    kDTreeNode *getMinNodeByDimension(kDTreeNode *node, int dimension);
    kDTreeNode *makeTree(vector<vector<int>> &pointList, vector<int> &label, int start, int end, int dimension);
    void mergeSort(vector<vector<int>> &pointList, vector<int> &label, int start, int end, int dimension);
    void merge(vector<vector<int>> &pointList, vector<int> &label, int start, int middle, int end, int dimension);
    void findNearestNeighbour(const vector<int> &target, kDTreeNode *&best, kDTreeNode *node, int dimension, double &R);
    void findKNearestNeighbour(const vector<int> &target, kDTreeNode *&best, kDTreeNode *node, int dimension, double &R, double TOL);
    double euclidDistance(vector<int> &A, const vector<int> &B);
    int distanceByDimension(vector<int> &A, const vector<int> &B, int dimension);
};

class kNN
{
private:
    int k;
    kDTree *tree;
    Dataset *X_train;
    Dataset *y_train;
    int numClasses;

public:
    kNN(int k = 5);
    void fit(Dataset &X_train, Dataset &y_train);
    Dataset predict(Dataset &X_test);
    double score(const Dataset &y_test, const Dataset &y_pred);
};

// Please add more or modify as needed
int MaxLabelCount(vector<kDTreeNode *> result);
bool equalNode(kDTreeNode *node, const vector<int> &point);
