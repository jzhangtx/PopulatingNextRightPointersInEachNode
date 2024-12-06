// PopulatingNextRightPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node* next;

    Node(int d)
        : data(d)
        , left(nullptr)
        , right(nullptr)
        , next(nullptr)
    {}
};

Node* ArrayToTree(const std::vector<int>& v)
{
    if (v.size() == 0)
        return nullptr;
    Node* root = new Node(v[0]);
    std::queue<Node*> q;
    q.push(root);
    bool l = true;
    for (size_t i = 1; i < v.size(); ++i, l = !l)
    {
        Node* pNode = q.front();
        if (!l)
            q.pop();
        if (v[i] != -1)
        {
            if (l)
            {
                pNode->left = new Node(v[i]);
                q.push(pNode->left);
            }
            else
            {
                pNode->right = new Node(v[i]);
                q.push(pNode->right);
            }
        }
    }

    return root;
}

void FreeTree(Node* pNode)
{
    if (pNode == nullptr)
        return;

    FreeTree(pNode->left);
    FreeTree(pNode->right);

    delete pNode;
}

void PrintConnected(Node* pNode)
{
    if (pNode == nullptr)
        return;

    std::cout << pNode->data;
    for (auto p = pNode->next; p != nullptr; p = p->next)
        std::cout << ", " << p->data;
    if (pNode->left != nullptr)
        std::cout << ", ";
    PrintConnected(pNode->left);
}

void Connect(std::vector<Node*>&& vec)
{
    if (vec.empty())
        return;

    std::vector<Node*> v;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (i != vec.size() - 1)
            vec[i]->next = vec[i + 1];

        if (vec[i]->left)
            v.push_back(vec[i]->left);
        if (vec[i]->right)
            v.push_back(vec[i]->right);
    }

    Connect(std::move(v));
}

void Connect(Node* root)
{
    std::vector<Node*> vec;
    vec.push_back(root);
    Connect(std::move(vec));
}

int main()
{
    while (true)
    {
        std::cout << "Number of nodes in the tree: ";
        int count = 0;
        std::cin >> count;
        if (count == 0)
            break;

        std::cout << "Values of the tree nodes: ";
        std::vector<int> v(count, 0);
        for (int i = 0; i < count; ++i)
            std::cin >> v[i];

        Node* root = ArrayToTree(v);

        Connect(root);

        PrintConnected(root);
        std::cout << std::endl << std::endl;
        FreeTree(root);
    }
}
