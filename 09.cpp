#include <iostream>
#include <algorithm>
using namespace std;
typedef struct hnode
{
    int weight;
    int lchild, rchild;
    int parent;
} huffNode, * huffmanTree;
void Select(huffmanTree& HT, int k, int& s1, int& s2);
//从HT数组的0到k-1中找出parent为-1的且权重最小的结点赋给s1,s2。
void CreateHuffTree(huffmanTree& HT, int W[], int N);
//创建哈夫曼树，W为权重数组，N为叶子结点个数
int main()
{
    huffNode* ht;
    int i, N, * W;
    cin >> N; //输入节点个数
    W = new int[N];   //申请动态数组，存储N个节点的权值
    ht = new huffNode[2 * N - 1];   //申请动态数组，存储2*N-1个节点
    for (i = 0; i < N; i++)
        cin >> W[i];  //读入N个节点的权值
    CreateHuffTree(ht, W, N);
    for (i = 0; i < 2 * N - 1; i++)
    {
        cout << i << "   " << ht[i].weight << "   " << ht[i].parent << "   " << ht[i].lchild << "   " << ht[i].rchild << "\n";
    }
    delete W;
    delete ht;
    return 0;
}
void CreateHuffTree(huffmanTree& HT, int W[], int N)
{
    int i, i1, i2, k;
    for (i = 0; i < N; i++)     //叶子结点初始化
    {
        HT[i].parent = -1;
        HT[i].lchild = -1;
        HT[i].rchild = -1;
        HT[i].weight = W[i];
    }
    for (k = N; k < 2 * N - 1; k++)
    {
        Select(HT, k, i1, i2);
        HT[k].weight = HT[i1].weight + HT[i2].weight;
        HT[k].lchild = i1;
        HT[k].rchild = i2;
        HT[k].parent = -1;
        HT[i1].parent = k;
        HT[i2].parent = k;
    }
}
void Select(huffmanTree& HT, int k, int& s1, int& s2)
{
    int min1, min2;
    int i = 0;
    while (HT[i].parent != -1 && i < k)
    {
        ++i;
    }
    min1 = HT[i].weight;
    s1 = i++;
    while (HT[i].parent != -1 && i < k)
    {
        ++i;
    }
    if (HT[i].weight < min1) 
    {
        min2 = min1;
        s2 = s1;
        min1 = HT[i].weight;
        s1 = i;
    }
    else 
    {
        min2 = HT[i].weight;
        s2 = i;
    }
    for (int j = i + 1; j < k; j++)
    {
        if (HT[j].parent != -1) 
        {
            continue;
        }
        if (HT[j].weight < min1) 
        {
            min2 = min1;
            min1 = HT[j].weight;
            s2 = s1;
            s1 = j;
        }
        else if (HT[j].weight >= min1 && HT[j].weight < min2) 
        {
            min2 = HT[j].weight;
            s2 = j;
        }
    }
}
