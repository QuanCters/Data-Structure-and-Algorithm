#include "kDTree.hpp"

// void tc1()
// {
//     Dataset dataset;
//     dataset.loadFromCSV("mnist.csv");
//     dataset.printHead(10, 10);
//     std::cout << endl;
//     dataset.printTail(10, 10);
//     std::cout << endl;
//     int nRows, nCols;
//     dataset.getShape(nRows, nCols);
//     std::cout << "Shape: " << nRows << "x" << nCols << endl;
// }

// void tc2()
// {
//     Dataset dataset;
//     dataset.loadFromCSV("mnist.csv");
//     int nRows, nCols;

//     Dataset feature = dataset.extract(0, -1, 1, -1);
//     Dataset label = dataset.extract(0, -1, 0, 0);
//     feature.getShape(nRows, nCols);
//     std::cout << "Feature shape: " << nRows << "x" << nCols << endl;
//     label.getShape(nRows, nCols);
//     std::cout << "Label shape: " << nRows << "x" << nCols << endl;
// }

// void tc3()
// {
//     Dataset dataset;
//     dataset.loadFromCSV("mnist.csv");
//     int nRows, nCols;

//     Dataset X_train, X_test, y_train, y_test;
//     Dataset feature = dataset.extract(0, -1, 1, -1);
//     Dataset label = dataset.extract(0, -1, 0, 0);

//     train_test_split(feature, label, 0.2, X_train, X_test, y_train, y_test);
//     X_train.getShape(nRows, nCols);
//     std::cout << "X_train shape: " << nRows << "x" << nCols << endl;
//     X_test.getShape(nRows, nCols);
//     std::cout << "X_test shape: " << nRows << "x" << nCols << endl;
//     y_train.getShape(nRows, nCols);
//     std::cout << "y_train shape: " << nRows << "x" << nCols << endl;
//     y_test.getShape(nRows, nCols);
//     std::cout << "y_test shape: " << nRows << "x" << nCols << endl;
// }

void tc4()
{
    Dataset dataset;
    dataset.loadFromCSV("mnist.csv");
    int nRows, nCols;

    kNN knn;
    Dataset X_train, X_test, y_train, y_test;
    Dataset feature = dataset.extract(0, -1, 1, -1);
    Dataset label = dataset.extract(0, -1, 0, 0);

    train_test_split(feature, label, 0.2, X_train, X_test, y_train, y_test);
    knn.fit(X_train, y_train);
    Dataset y_pred = knn.predict(X_test);

    std::cout << "y_pred" << endl;
    y_pred.printHead(10, 0);
    std::cout << endl;
    std::cout << "y_test" << endl;
    y_test.printHead(10, 10);
    std::cout << endl;
}

void tc5()
{
    Dataset dataset;
    dataset.loadFromCSV("mnist.csv");
    int nRows, nCols;
    kNN knn;
    Dataset X_train, X_test, y_train, y_test;
    Dataset feature = dataset.extract(0, -1, 1, -1);
    Dataset label = dataset.extract(0, -1, 0, 0);
    train_test_split(feature, label, 0.2, X_train, X_test, y_train, y_test);
    knn.fit(X_train, y_train);
    Dataset y_pred = knn.predict(X_test);
    double accuracy = knn.score(y_test, y_pred);
    std::cout << "Accuracy: " << accuracy << endl;
}

// void tcBuildTree()
// {
//     vector<vector<int>>
//         pointList = {{0, 0, 0, 0, 1}, {0, 0, 0, 0, 2}, {0, 0, 0, 0, 3}, {0, 0, 0, 0, 4}, {0, 0, 0, 0, 5}, {0, 0, 0, 0, 6}, {0, 0, 0, 0, 7}, {0, 0, 0, 0, 8}, {0, 0, 0, 0, 9}};
//     vector<int> label = {1, 2, 3, 4, 5, 6, 7, 8, 9};

//     kDTree tree(5);

//     tree.buildTree(pointList, label);

//     cout << "Preorder Traversal of the KD Tree: \n";
//     tree.preorderTraversal();
//     cout << endl;
//     cout << tree.search({0, 0, 0, 0, 1});
// }

int main(int argc, const char *argv[])
{
    // tc1();
    // tc2();
    // tc3();
    // tc4();
    tc5();
    // tcBuildTree();

    return 0;
}