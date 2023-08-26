// 참고 : https://velog.io/@kon6443/Data-Structure-%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-C-%ED%8A%B8%EB%A6%AC
// 풀이 방법 - 이진 트리 구현
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    char data;
    Node *left;
    Node *right;
};

// 노드 생성
Node *createNode(char data)
{
    Node *node = new Node();
    if (!node)
    {
        cout << "Memory error" << endl;
        return NULL;
    }
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// 트리에 내가 만든 노드 추가
Node *insertNode(Node *root, char parent, char data)
{
    // root가 존재하지 않는다면 새로 트리 생성
    if (root == NULL)
    {
        root = createNode(data);
        return root;
    }

    //bfs탐색하며 이진트리 채우기
    queue <Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *tmp = q.front();
        q.pop();
        if (tmp->left != NULL)
            q.push(tmp->left);
        else
        {
            if (tmp->data == parent)
            {
                tmp->left = createNode(data);
                return root;
            }
        }
        if (tmp->right != NULL)
            q.push(tmp->right);
        else
        {
            if (tmp->data == parent)
            {
                tmp->right = createNode(data);
                return root;
            }
        }
    }
    return root;
}

void preorder(struct Node *node)
{
    if (node == NULL) return;
    if (node->data != '.') cout << node->data;
    preorder(node->left);
    preorder(node->right);
}

void inorder(struct Node *node)
{
    if (node == NULL) return;
    inorder(node->left);
    if (node->data != '.') cout << node->data;
    inorder(node->right);
}

void postorder(struct Node *node)
{
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    if (node->data != '.') cout << node->data;
}

int main()
{
    int N;
    cin >> N;
    Node *root = createNode('A');
    for (int i = 0; i < N; i++)
    {
        char parent, left, right;
        cin >> parent >> left >> right;
        root = insertNode(root, parent, left);
        root = insertNode(root, parent, right);
    }
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
}