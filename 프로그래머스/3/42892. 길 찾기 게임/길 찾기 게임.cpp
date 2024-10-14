#include <string>
#include <vector>
#include <algorithm>

#define vi vector<int>
#define vvi vector<vector<int>>

struct Tree{
    Tree *left;
    Tree *right;
    int index;
};

using namespace std;

Tree *makeTree(vvi &nodeinfo, int start, int end)
{
    if (start > end)
        return NULL;
    //find root node
    int cur = start;
    int yMax = nodeinfo[start][1];
    for (int i = start+1; i <= end; i++)
    {
        if (nodeinfo[i][1] > yMax)
        {
            cur = i;
            yMax = nodeinfo[i][1];
        }
    }
    Tree *result = new Tree();
    result->index = nodeinfo[cur][2];
    result->left = makeTree(nodeinfo, start, cur-1);
    result->right = makeTree(nodeinfo, cur+1, end);
    return result;
}

void preorder(Tree *tree, vi &answer)
{
    if (tree == NULL)
        return;
    answer.push_back(tree->index);
    preorder(tree->left, answer);
    preorder(tree->right, answer);
}

void postorder(Tree *tree, vi &answer)
{
    if (tree == NULL)
        return;
    postorder(tree->left, answer);
    postorder(tree->right, answer);
    answer.push_back(tree->index);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    int size = nodeinfo.size();
    for (int i=0; i<size; i++) //remember the index number
        nodeinfo[i].push_back(i+1);
    sort(nodeinfo.begin(), nodeinfo.end()); //sort by x
    Tree *tree = makeTree(nodeinfo, 0, size-1);
    
    vi pre, post;
    preorder(tree, pre);
    postorder(tree, post);
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}