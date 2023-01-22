#include <iostream>
#include <queue>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int value;
    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
    Node* root;

    Node* find(Node* curNode, int value) {
        if (curNode == NULL)
            return NULL;
        if (curNode->value == value)
            return curNode;
        if (curNode->value < value)
            return find(curNode->right, value);
        return find(curNode->left, value);
    }

    Node* insert(Node* curNode, int value) {
        if (curNode == NULL) {
            return new Node(value);
        }
        if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        }
        else {
            curNode->left = insert(curNode->left, value);
        }
        return curNode;
    }

    Node* remove(Node* curNode, int value) {
        if (curNode == NULL) {
            return NULL;
        }
        if (curNode->value < value) {
            curNode->right = remove(curNode->right, value);
        }
        else if (curNode->value > value) {
            curNode->left = remove(curNode->left, value);
        }
        else {
            if (curNode->left == NULL) {
                Node* tmp = curNode->right;
                delete curNode;
                return tmp;
            }
            Node* minInLeftSubTree = findMin(curNode->right);
            curNode->value = minInLeftSubTree->value;
            curNode->right = remove(curNode->right, curNode->value);
        }
        return curNode;
    }

    void printSorted(Node* root) {
        if (root == NULL) {
            return;
        }
        printSorted(root->left);
        cout << root->value << " ";
        printSorted(root->right);
    }

    Node* findMax(Node* root) {
        if (root->right != NULL) {
            return findMax(root->right);
        }
        return root;
    }

    Node* findMin(Node* root) {
        if (root->left != NULL) {
            return findMin(root->left);
        }
        return root;
    }

    Node* lowerBound(Node* root, int value) {
        if (root == NULL) {
            return NULL;
        }
        else if (root->value == value) {
            return root;
        }
        else if (root->value < value) {
            return lowerBound(root->right, value);
        }
        else {
            Node* tmp = lowerBound(root->left, value);
            if (tmp != NULL)
                return tmp;
            else
                return root;
        }
    }

public:
    BST() {
        root = NULL;
    }
    Node* getRoot() {
        return root;
    }
    void insert(int value) {
        if (root == NULL) {
            root = new Node(value);
        }
        else {
            insert(root, value);
        }
    }
    void remove(int value) {
        root = remove(root, value);
    }
    bool exists(int value) {
        return find(root, value) != NULL;
    }
    int findMin() {
        if (root == NULL)
            return -1;
        return findMin(root)->value;
    }
    int findMax() {
        if (root == NULL)
            return -1;
        return findMax(root)->value;
    }
    int lowerBound(int value) {
        Node* lb = lowerBound(root, value);
        if (lb == NULL)
            return -1;
        else return lb->value;
    }
    void printSorted() {
        printSorted(root);
    }
    Node* returnKthLargest(Node* root, int k)
    {
        Node* curr = root;
        Node* Klargest = NULL;
        int count = 0;

        while (curr != NULL) {
            if (curr->right == NULL) {
                if (++count == k)
                    Klargest = curr;
                curr = curr->left;
            }
            else {
                Node* succ = curr->right;
                while (succ->left != NULL && succ->left != curr)
                    succ = succ->left;
                if (succ->left == NULL) {
                    succ->left = curr;
                    curr = curr->right;
                }
                else {

                    succ->left = NULL;

                    if (++count == k)
                        Klargest = curr;
                    curr = curr->left;
                }
            }
        }

        return Klargest;
    }
    void printLevelOrder(Node* root)
    {
        if (root == NULL) return;

        queue<Node*> que;

        que.push(root);

        while (que.empty() == false)
        {
            int nodeCount = que.size();
            while (nodeCount > 0)
            {
                Node* node = que.front();
                cout << node->value << " ";
                que.pop();
                if (node->left != NULL)
                    que.push(node->left);
                if (node->right != NULL)
                    que.push(node->right);
                nodeCount--;
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N;
    cin >> K;
    BST tree;
    int number_to_add;
    Node* root;
    for (size_t i = 0; i < N; i++) {
        cin >> number_to_add;
        tree.insert(number_to_add);
    }
    //tree.printLevelOrder(tree.getRoot());
   // cout << endl;
    Node* helper;
    helper = tree.returnKthLargest(tree.getRoot(), K);
    //cout << helper->value<< endl;
    tree.remove(helper->value);
    tree.printLevelOrder(tree.getRoot());

    return 0;
}