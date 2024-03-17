#include <iostream>
#include <vector>

struct Node
{
    Node* left = NULL;
    Node* right = NULL;
    char data = '.';
};

void InOrder(Node* node)
{
    if (node->data != '.') {
        std::cout << node->data;
        if (node->left != NULL) InOrder(node->left);
        if (node->right != NULL) InOrder(node->right);
    }
    return;
}

void PreOrder(Node* node)
{
    if (node->data != '.') {
        if (node->left != NULL) PreOrder(node->left);
        std::cout << node->data;
        if (node->right != NULL) PreOrder(node->right);
    }
    return;
}

void PostOrder(Node* node)
{
    if (node->data != '.') {
        if (node->left != NULL) PostOrder(node->left);
        if (node->right != NULL) PostOrder(node->right);
        std::cout << node->data;
    }
    return;
}

int main(void)
{
    int n;
    std::vector <Node> tree(28);
    char data, left, right;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> data >> left >> right;
        tree[data-'A'].data = data;
        if(left != '.') tree[data-'A'].left = &tree[left-'A'];
        if(right != '.') tree[data-'A'].right = &tree[right-'A'];
    }

    InOrder(&tree[0]);
    std::cout << '\n';
    PreOrder(&tree[0]);
    std::cout << '\n';
    PostOrder(&tree[0]);
    return 0;
}