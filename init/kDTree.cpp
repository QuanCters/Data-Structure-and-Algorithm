#include "kDTree.hpp"

/* TODO: You can implement methods, functions that support your data structures
 * here.
 * */
kDTree::kDTree(int k)
{
    this->k = k;
    root = nullptr;
}

kDTree::~kDTree() { deleteTree(root); }

void kDTree::deleteTree(kDTreeNode *node)
{
    if (node)
    {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

const kDTree &kDTree::operator=(const kDTree &other)
{
    if (this == &other)
    {
        return *this;
    }

    deleteTree(this->root);

    k = other.k;
    root = deepCopyTree(other.root);

    return *this;
}

kDTreeNode *kDTree::deepCopyTree(kDTreeNode *node)
{
    if (!node)
    {
        return NULL;
    }

    kDTreeNode *newNode = new kDTreeNode(node->data, 0, deepCopyTree(node->left),
                                         deepCopyTree(node->right));
    return newNode;
}

kDTree::kDTree(const kDTree &other)
{
    k = other.k;
    root = deepCopyTree(other.root);
}

void kDTree::inorderTraversal() const { printInorder(this->root); }

void kDTree::printInorder(kDTreeNode *node) const
{
    if (!node)
        return;

    printInorder(node->left);
    printNode(node);
    cout << " ";
    printInorder(node->right);
}

void kDTree::preorderTraversal() const { printPreorder(this->root); }

void kDTree::printPreorder(kDTreeNode *node) const
{
    if (!node)
        return;

    printNode(node);
    cout << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void kDTree::postorderTraversal() const { printPostorder(this->root); }

void kDTree::printPostorder(kDTreeNode *node) const
{
    if (!node)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    printNode(node);
    cout << " ";
}

void kDTree::printNode(kDTreeNode *node) const
{
    cout << "(" << node->data[0];
    int n = node->data.size();
    for (int i = 1; i < n; i++)
    {
        cout << " " << node->data[i];
    }
    cout << ")";
}

int kDTree::height() const { return getHeight(this->root); }

int kDTree::getHeight(kDTreeNode *node) const
{
    if (!node)
        return 0;
    return 1 + max(getHeight(node->left), getHeight(node->right));
}

int kDTree::nodeCount() const { return numNode(this->root); }

int kDTree::numNode(kDTreeNode *node) const
{
    if (!node)
        return 0;
    return 1 + numNode(node->left) + numNode(node->right);
}

int kDTree::leafCount() const
{
    int sum = 0;
    numLeaf(this->root, sum);
    return sum;
}

void kDTree::numLeaf(kDTreeNode *node, int &sum) const
{
    if (!node)
        return;
    if (!node->left && !node->right)
        sum += 1;
    if (node->left)
        numLeaf(node->left, sum);
    if (node->right)
        numLeaf(node->right, sum);
}

void kDTree::insert(const vector<int> &point)
{
    if (point.size() != this->k)
        return;
    int dimension = 0;
    kDTreeNode *newNode = new kDTreeNode(point, 0, nullptr, nullptr);
    this->root = insertNode(this->root, newNode, dimension);
}

kDTreeNode *kDTree::insertNode(kDTreeNode *node, kDTreeNode *newNode, int dimension)
{
    if (!node)
    {
        return newNode;
    }
    else if (newNode->data[dimension] >= node->data[dimension])
    {
        node->right =
            insertNode(node->right, newNode, (dimension + 1) % this->k);
    }
    else
    {
        node->left =
            insertNode(node->left, newNode, (dimension + 1) % this->k);
    }
    return node;
}

void kDTree::remove(const vector<int> &point)
{
    if (!search(point))
        return;
    kDTreeNode *parentNode = NULL;
    kDTreeNode *trackNode = this->root;
    int dimension = 0;
    while (true)
    {
        if (trackNode->data[dimension] > point[dimension])
        {
            parentNode = trackNode;
            trackNode = trackNode->left;
        }
        else if (trackNode->data[dimension] < point[dimension])
        {
            parentNode = trackNode;
            trackNode = trackNode->right;
        }
        else
        {
            if (!equalNode(trackNode, point))
            {
                parentNode = trackNode;
                trackNode = trackNode->right;
            }
            else
            {
                break;
            }
        }
        dimension += 1;
        dimension %= this->k;
    }
    trackNode = removeNode(trackNode, parentNode, dimension);
}

kDTreeNode *kDTree::removeNode(kDTreeNode *node, kDTreeNode *parentNode, int dimension)
{
    if (!node)
        return NULL;

    if (!node->left && !node->right)
    {
        node->data.clear();
        delete node;
        if (parentNode)
        {
            if (parentNode->left == node)
            {
                parentNode->left = NULL;
            }
            else
            {
                parentNode->right = NULL;
            }
        }
        return NULL;
    }
    else if (node->right)
    {
        parentNode = node;
        kDTreeNode *minNode = getMinNodeByDimension(node->right, dimension);
        node->data = minNode->data;
        node->label = minNode->label;
        minNode = removeNode(minNode, parentNode, dimension);
    }
    else if (node->left)
    {
        parentNode = node;
        kDTreeNode *minNode = getMinNodeByDimension(node->left, dimension);
        node->data = minNode->data;
        node->label = minNode->label;
        node->right = node->left;
        node->left = NULL;
        minNode = removeNode(minNode, parentNode, dimension);
    }
    return node;
}

kDTreeNode *kDTree::getMinNodeByDimension(kDTreeNode *node, int dimension)
{
    if (!node)
        return NULL;
    kDTreeNode *leftMin = getMinNodeByDimension(node->left, dimension);
    kDTreeNode *rightMin = getMinNodeByDimension(node->right, dimension);

    kDTreeNode *minNode = node;
    if (leftMin && leftMin->data[dimension] < minNode->data[dimension])
    {
        minNode = leftMin;
    }
    if (rightMin && rightMin->data[dimension] < minNode->data[dimension])
    {
        minNode = rightMin;
    }
    return minNode;
}

bool kDTree::search(const vector<int> &point)
{
    if (point.size() != k)
        return 0;
    int dimension = 0;
    return searchNode(this->root, point, dimension);
}

bool kDTree::searchNode(kDTreeNode *node, const vector<int> &point, int dimension)
{
    if (!node)
        return 0;
    if (equalNode(node, point))
    {
        return true;
    }
    if (point[dimension] >= node->data[dimension])
    {
        return searchNode(node->right, point, (dimension + 1) % (this->k));
    }
    else
    {
        return searchNode(node->left, point, (dimension + 1) % (this->k));
    }
    return false;
}

bool equalNode(kDTreeNode *node, const vector<int> &point)
{
    int size = point.size();
    for (int i = 0; i < size; i++)
    {
        if (node->data[i] != point[i])
        {
            return false;
        }
    }
    return true;
}

void kDTree::buildTree(const vector<vector<int>> &pointList, const vector<int> &label)
{
    if (pointList.size() == 0)
        return;
    vector<vector<int>> pointCopyList = pointList;
    vector<int> labelCopyList = label;
    int dimension = 0;
    this->root = makeTree(pointCopyList, labelCopyList, 0, pointCopyList.size() - 1, dimension);
}

kDTreeNode *kDTree::makeTree(vector<vector<int>> &pointList, vector<int> &label, int start, int end, int dimension)
{
    if (end < start)
        return NULL;
    if (end == start)
        return new kDTreeNode(pointList[start], label[start], NULL, NULL);
    mergeSort(pointList, label, start, end, dimension);
    int mid = (start + end) / 2;
    kDTreeNode *newNode = new kDTreeNode(pointList[mid], label[mid], NULL, NULL);
    newNode->left = makeTree(pointList, label, start, mid - 1, (dimension + 1) % this->k);
    newNode->right = makeTree(pointList, label, mid + 1, end, (dimension + 1) % this->k);
    return newNode;
}

void kDTree::mergeSort(vector<vector<int>> &pointList, vector<int> &label, int start, int end, int dimension)
{
    if (start < end)
    {
        int middle = (start + end) / 2;
        mergeSort(pointList, label, start, middle, dimension);
        mergeSort(pointList, label, middle + 1, end, dimension);

        merge(pointList, label, start, middle, end, dimension);
    }
}

void kDTree::merge(vector<vector<int>> &pointList, vector<int> &label, int start, int middle, int end, int dimension)
{
    vector<vector<int>> leftPoint(middle - start + 1);
    vector<vector<int>> rightPoint(end - middle);
    vector<int> leftLabel(middle - start + 1);
    vector<int> rightLabel(end - middle);
    int leftSize = leftPoint.size();
    for (int i = 0; i < leftSize; i++)
    {
        leftPoint[i] = pointList[start + i];
        leftLabel[i] = label[start + i];
    }

    int rightSize = rightPoint.size();
    for (int i = 0; i < rightSize; i++)
    {
        rightPoint[i] = pointList[middle + 1 + i];
        rightLabel[i] = label[middle + 1 + i];
    }

    int leftIndex = 0, rightIndex = 0;

    int currentIndex = start;

    while (leftIndex < leftSize && rightIndex < rightSize)
    {
        if (leftPoint[leftIndex][dimension] <= rightPoint[rightIndex][dimension])
        {
            pointList[currentIndex] = leftPoint[leftIndex];
            label[currentIndex] = leftLabel[leftIndex];
            leftIndex++;
        }
        else
        {
            pointList[currentIndex] = rightPoint[rightIndex];
            label[currentIndex] = rightLabel[rightIndex];
            rightIndex++;
        }
        currentIndex++;
    }

    while (leftIndex < leftSize)
    {
        pointList[currentIndex] = leftPoint[leftIndex];
        label[currentIndex] = leftLabel[leftIndex];
        currentIndex++;
        leftIndex++;
    }

    while (rightIndex < rightSize)
    {
        pointList[currentIndex] = rightPoint[rightIndex];
        label[currentIndex] = rightLabel[rightIndex];
        currentIndex++;
        rightIndex++;
    }
}

void kDTree::nearestNeighbour(const vector<int> &target, kDTreeNode *best)
{
    int dimension = 0;
    double R = 0;
    findNearestNeighbour(target, best, this->root, dimension, R);
}

void kDTree::findNearestNeighbour(const vector<int> &target, kDTreeNode *&best, kDTreeNode *node, int dimension, double &R)
{
    if (!node->left && !node->right)
    {
        if (best->data.size() == 0)
        {
            best = node;
            best->data = node->data;
            R = euclidDistance(best->data, target);
        }
        else
        {
            double tempR = euclidDistance(node->data, target);
            if (tempR < R)
            {
                best = node;
                best->data = node->data;
                R = tempR;
            }
        }
    }
    else if (target[dimension] >= node->data[dimension])
    {
        findNearestNeighbour(target, best, node->right, (dimension + 1) % this->k, R);
        double tempR = euclidDistance(node->data, target);
        if (tempR < R)
        {
            best = node;
            best->data = node->data;
            R = tempR;
        }
        int r = distanceByDimension(node->data, target, dimension);
        if (r > R)
        {
            return;
        }
        else
        {
            if (node->left)
            {
                findNearestNeighbour(target, best, node->left, (dimension + 1) % this->k, R);
            }
            return;
        }
    }
    else
    {
        findNearestNeighbour(target, best, node->left, (dimension + 1) % this->k, R);
        double tempR = euclidDistance(node->data, target);
        if (tempR < R)
        {
            best = node;
            best->data = node->data;
            R = tempR;
        }
        int r = distanceByDimension(node->data, target, dimension);
        if (r > R)
        {
            return;
        }
        else
        {
            if (node->right)
            {
                findNearestNeighbour(target, best, node->right, (dimension + 1) % this->k, R);
            }
            return;
        }
    }
}

double kDTree::euclidDistance(vector<int> &A, const vector<int> &B)
{
    int total = 0;
    int size = A.size();
    for (int i = 0; i < size; i++)
    {
        int sqrtDis = A[i] - B[i];
        total += sqrtDis * sqrtDis;
    }
    double distance = sqrt(total);
    return distance;
}

int kDTree::distanceByDimension(vector<int> &A, const vector<int> &B, int dimension)
{
    return abs(A[dimension] - B[dimension]);
}

void kDTree::kNearestNeighbour(const vector<int> &target, int k, vector<kDTreeNode *> &bestList)
{
    double TOL = 0;
    for (int i = 0; i < k; i++)
    {
        int dimension = 0;
        double R = 0;
        kDTreeNode *best = new kDTreeNode({}, 0, nullptr, nullptr);
        findKNearestNeighbour(target, best, this->root, dimension, R, TOL);
        kDTreeNode *result = new kDTreeNode(best->data, best->label, nullptr, nullptr);
        TOL = euclidDistance(best->data, target);
        bestList.push_back(result);
    }
}

void kDTree::findKNearestNeighbour(const vector<int> &target, kDTreeNode *&best, kDTreeNode *node, int dimension, double &R, double TOL)
{
    if (!node->left && !node->right)
    {
        if (best->data.size() == 0)
        {
            best = node;
            best->data = node->data;
            R = euclidDistance(best->data, target);
        }
        else
        {
            double tempR = euclidDistance(node->data, target);
            if (tempR < R && tempR > TOL)
            {
                best = node;
                best->data = node->data;
                R = tempR;
            }
        }
    }
    else if (target[dimension] >= node->data[dimension])
    {
        findKNearestNeighbour(target, best, node->right, (dimension + 1) % this->k, R, TOL);
        double tempR = euclidDistance(node->data, target);
        if (tempR < R && tempR > TOL)
        {
            best = node;
            best->data = node->data;
            R = tempR;
        }
        int r = distanceByDimension(node->data, target, dimension);
        if (r > R)
        {
            return;
        }
        else
        {
            if (node->left)
            {
                findKNearestNeighbour(target, best, node->left, (dimension + 1) % this->k, R, TOL);
            }
            return;
        }
    }
    else
    {
        findKNearestNeighbour(target, best, node->left, (dimension + 1) % this->k, R, TOL);
        double tempR = euclidDistance(node->data, target);
        if (tempR < R && tempR > TOL)
        {
            best = node;
            best->data = node->data;
            R = tempR;
        }
        int r = distanceByDimension(node->data, target, dimension);
        if (r > R)
        {
            return;
        }
        else
        {
            if (node->right)
            {
                findKNearestNeighbour(target, best, node->right, (dimension + 1) % this->k, R, TOL);
            }
            return;
        }
    }
}

kNN::kNN(int k)
{
    this->k = k;
    this->tree = nullptr;
    this->X_train = nullptr;
    this->y_train = nullptr;
    this->numClasses = 0;
}

void kNN::fit(Dataset &X_train, Dataset &y_train)
{
    this->X_train = &X_train;
    this->y_train = &y_train;
    int nRows, nCols;
    this->X_train->getShape(nRows, nCols);
    vector<vector<int>> listPoint;
    vector<int> label;
    for (auto &row : this->X_train->data)
    {
        vector<int> point(row.begin(), row.end());
        listPoint.push_back(point);
    }
    for (auto &row : this->y_train->data)
    {
        vector<int> l(row.begin(), row.end());
        label.push_back(l.front());
    }
    tree = new kDTree(nCols);
    tree->buildTree(listPoint, label);
}

Dataset kNN::predict(Dataset &X_test)
{
    Dataset y_pred;
    list<list<int>> *dataPtr = &(y_pred.data);
    int nRows, nCols;
    X_test.getShape(nRows, nCols);
    for (auto &row : X_test.data)
    {
        vector<int> target(row.begin(), row.end());
        vector<kDTreeNode *> result;
        kDTree *tempTree = this->tree;
        tempTree->kNearestNeighbour(target, this->k, result);
        int maxLabelCount = MaxLabelCount(result);
        list<int> res;
        res.push_back(maxLabelCount);
        dataPtr->push_back(res);
    }
    return y_pred;
}

int MaxLabelCount(vector<kDTreeNode *> result)
{
    {
        int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int n = result.size();
        for (int i = 0; i < n; i++)
        {
            int temp = result[i]->label;
            arr[temp]++;
        }
        int max = arr[0];
        int maxIdx = 0;
        for (int i = 1; i <= 9; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
                maxIdx = i;
            }
        }
        return maxIdx;
    }
}

double kNN::score(const Dataset &y_test, const Dataset &y_pred)
{
    int nRows, nCols;
    const list<list<int>> *y_test_Ptr = &(y_test.data);
    const list<list<int>> *y_pred_Ptr = &(y_pred.data);
    y_test.getShape(nRows, nCols);
    auto test_it = (*y_test_Ptr).begin();
    auto pred_it = (*y_pred_Ptr).begin();
    int pred = 0;
    for (int i = 0; i < nRows; i++)
    {
        if ((*test_it).front() == (*pred_it).front())
        {
            pred++;
        }
        test_it++;
        pred_it++;
    }
    double accuracy = pred * 1.0 / nRows;
    return accuracy;
}
