// AVL tree implementation in C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Create Node
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Calculate height
int height(struct Node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// Create a node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)
        malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

// Right rotate
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = MAX(height(y->left), height(y->right)) + 1;
    x->height = MAX(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotate
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = MAX(height(x->left), height(x->right)) + 1;
    y->height = MAX(height(y->left), height(y->right)) + 1;

    return y;
}

// Get the balance factor
int getBalance(struct Node* N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Insert node
struct Node* insertNode(struct Node* node, int key) {
    // Find the correct position to insertNode the node and insertNode it
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else
        return node;

    // Update the balance factor of each node and
    // Balance the tree
    node->height = 1 + MAX(height(node->left),
        height(node->right));

    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

// Delete a nodes
struct Node* deleteNode(struct Node* root, int key) {
    // Find the node and delete it
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else {
            struct Node* temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    // Update the balance factor of each node and
    // balance the tree
    root->height = 1 + MAX(height(root->left),
        height(root->right));

    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Print the tree
#define MAX_QUEUE 0x400
void printTree(struct Node* bt)
{
    struct Node* queue[MAX_QUEUE];
    int i, ii, queue_start, queue_end, space;
    int count;
    for (i = 0; i < 80; i++)
    {
        printf("-");
    }
    printf("\n");
    count = 0;
    for (i = 0; i < MAX_QUEUE; i++)
    {
        queue[i] = NULL;
    }
    queue_start = 0;
    queue_end = 0;
    queue[queue_start % MAX_QUEUE] = bt;
    queue_end = (queue_end + 1) % MAX_QUEUE;
    while (queue_start != queue_end && queue[queue_start])
    {
        space = 0;
        count++;
        space += printf("%2d: %3d  ", count, queue[queue_start]->key);
        if (queue[queue_start]->left || queue[queue_start]->right)
        {
            printf("  -> ");

            if (queue[queue_start]->left)
            {
                printf("%3d   ", queue[queue_start]->left->key);
                queue[queue_end] = (struct Node*)queue[queue_start]->left;
                queue_end = (queue_end + 1) % MAX_QUEUE;
            }
            if (queue[queue_start]->right)
            {
                printf("%3d   ", queue[queue_start]->right->key);
                queue[queue_end] = (struct Node*)queue[queue_start]->right;
                queue_end = (queue_end + 1) % MAX_QUEUE;
            }
        }
        printf("\n");
        queue[queue_start] = NULL;
        queue_start = (queue_start + 1) % MAX_QUEUE;
    }
    printf("\n");
}

void test()
{
#define NUM 8
    struct Node* root = NULL;
    int num[NUM], i, ii, temp;
    srand(time(NULL));
    for (i = 0; i < NUM; i++)
    {
        do
        {
            temp = rand() % 100;
            for (ii = 0; ii < i; ii++)
            {
                if (num[ii] == temp)
                {
                    break;
                }
            }
            num[i] = temp;
        } while (i != ii);
    }
    printf("number: ");
    for (i = 0; i < NUM; i++)
    {
        printf("%2d  ", num[i]);
    }
    printf("\n");
    printf("Please build: ");
    getchar(); // pause()
    for (i = 0; i < NUM; i++)
    {
        root = insertNode(root, num[i]);
        printTree(root);
    }
    temp = rand() % NUM;
    printf("Please delete: %d ", num[temp]);
    getchar();
    root = deleteNode(root, num[temp]);
    printTree(root);
}


int main() {
    struct Node* root = NULL;

    // test();

#define IN(v) {root = insertNode(root, v);}
#define DEL(v) {root = deleteNode(root, v);}
    IN(1);
    IN(2);
    IN(3);
    printTree(root);

    return 0;
}