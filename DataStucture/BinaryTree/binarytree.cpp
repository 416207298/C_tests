//C++ file
/***********************************************
#
#      Filename: realize.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-11-14 16:37:53
#**********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include "binarytree.h"

using namespace std;

/* 打印一个节点的信息 */
void printNodeInfo(binaryTreeNode *node)
{
	if (node != NULL)
		printf("node is %d\n", node->item);
	else
		printf("node is NULL\n");
}


/* 返回最大节点 */
binaryTreeNode *binaryTree::maxValueNode(binaryTreeNode *root)
{
	binaryTreeNode *cur = root;
	while (cur->r_child)
		cur = cur->r_child;
	return cur;
}

binaryTreeNode *binaryTree::minValueNode(binaryTreeNode *root)
{
	binaryTreeNode *cur = root;
	while (cur->l_child)
		cur = cur->l_child;
	return cur;
}


/* 中序遍历 */
void binaryTree::inorder(binaryTreeNode *root)
{
	if (root != NULL)
	{
		inorder(root->l_child);
		printf("%d\t", root->item);
		inorder(root->r_child);
	}
}

/* 中序遍历（非递归）*/
void binaryTree::inorder_nonRecur(binaryTreeNode *root) 
{
    stack<binaryTreeNode *> s;
    while (root != NULL || !s.empty()) {
        if (root != NULL) {
            s.push(root);
            root = root->l_child;
        }
        else {
            root = s.top();
            cout << root->item<< " ";
            s.pop();
            root = root->r_child;
        }
    }
}

/* 后序遍历 */
void binaryTree::postorder(binaryTreeNode *root)
{
	if (root != NULL)
	{
		postorder(root->l_child);
		postorder(root->r_child);
		printf("%d\t", root->item);
	}
}


/* 层序遍历 */
void binaryTree::breath_first_traversal(binaryTreeNode *root)
{
	if (root)
	{
		queue<binaryTreeNode *> in_queue;
		// 把根节点入队
		in_queue.push(root);
		
		while (!in_queue.empty())
		{
			cout << in_queue.front()->item << "\t";
			if (in_queue.front()->l_child) 	
				in_queue.push(in_queue.front()->l_child);

			if (in_queue.front()->r_child)
				in_queue.push(in_queue.front()->r_child);

			in_queue.pop();
		}
		cout << endl;
	}
}

/* 利用set的无重复元素的性质，判断一个元素是否在树中  */
bool binaryTree::ifExistsElement(int elem)
{
	for (auto pd = this->elemSet.begin(); pd != this->elemSet.end(); ++pd)
	{
		if (*pd == elem) 
			return true;
	}
	return false;
}

/* 寻找一个节点，返回该节点的指针，没找到返回NULL */
binaryTreeNode *binaryTree::searchNode(binaryTreeNode *root, int value)
{
	if (root != NULL)
	{
		if (value == root->item)
			return root;
		else if (value > root->item)
			return searchNode(root->r_child, value);
		else if (value < root->item)
			return searchNode(root->l_child, value);
	}
	else return NULL;
}


/* 插入一个节点  */
binaryTreeNode *binaryTree::insert(binaryTreeNode *root, int item)
{
	if (root == NULL)
	{
		binaryTreeNode *temp = new binaryTreeNode(item);
		this->elemSet.insert(item);  // 插入已有元素集合
		return temp;
	}
	// 检查是否元素重复
	if (ifExistsElement(item))
	{
		printf("element %d exists\n", item);
		return root;
	}

	if (item > root->item)
		root->r_child = insert(root->r_child, item);
	else
		root->l_child = insert(root->l_child, item);

	return root;
}


/* 创建一颗二叉树 */
void binaryTree::createBST(binaryTreeNode* &root, vector<int> &v)
{
	if (v.empty())
		root = NULL;
	else
	{
		for (int val : v)
			root = insert(root, val);	
	}
}


binaryTreeNode *binaryTree::leftRotation(binaryTreeNode *root, binaryTreeNode *node)
{
	return NULL;
}

binaryTreeNode *binaryTree::rightRotation(binaryTreeNode *root, binaryTreeNode *node)
{
	return NULL;
}


binaryTreeNode *binaryTree::deleteNode(binaryTreeNode *root, int value)
{
	if (root == NULL)  return NULL;

	if (value > root->item)
		root->r_child = deleteNode(root->r_child, value);
	else if (value < root->item)
		root->l_child = deleteNode(root->l_child, value);
	else
	{
		// 删除节点有一个孩子节点或无孩子节点
		if (root->l_child == NULL)
		{
			binaryTreeNode *temp = root->r_child;
			delete(root);
			return temp;
		}
		else if (root->r_child == NULL)
		{
			binaryTreeNode *temp = root->l_child;
			delete(root);
			return temp;
		}
		// 删除节点有两个孩子节点
		else
		{
			binaryTreeNode *leftChildMaxNode = maxValueNode(root->l_child);
			//cout << "leftChildMaxNode is " << leftChildMaxNode->item << endl;
			root->item = leftChildMaxNode->item;
			root->l_child = deleteNode(root->l_child, leftChildMaxNode->item);
		}
	}
	return root;
}

/* 判断一棵树是否为二叉搜索树（BST）*/
bool ifIsA_BST(binaryTreeNode *root)
{
	binaryTree *tree = new binaryTree();
	if (root == NULL)
		return true;
	if (root->l_child != NULL && tree->maxValueNode(root->l_child)->item > root->item)
		return false;
	if (root->r_child != NULL && tree->minValueNode(root->r_child)->item < root->item)
		return false;
	if (!ifIsA_BST(root->l_child) || !ifIsA_BST(root->r_child))
		return false;
	return true;
}


/* 判断一颗二叉树是否为二叉树的高效方法 
 * 去判断每个节点是否在一个range中*/
bool ifIsA_BST_util(binaryTreeNode *root, int max_value, int min_value)
{
	if (root == NULL) return true;

	if (root->item < max_value && root->item > min_value
			&& ifIsA_BST_util(root->l_child, root->item, min_value)
			&& ifIsA_BST_util(root->r_child, max_value, root->item))
		return true;
	else
		return false;
}
bool ifIsA_BST_efficient(binaryTreeNode *root)
{
	return ifIsA_BST_util(root, MAX_VAL, MIN_VAL);
}



bool doesTree1HasTree2(binaryTreeNode *root1, binaryTreeNode *root2)
{
	if (root2 == NULL)
		return true;
	if (root1 == NULL)
		return false;
	if (root1->item != root2->item)
		return false;

	return doesTree1HasTree2(root1->l_child, root2->l_child) &&
		doesTree1HasTree2(root1->r_child, root2->r_child);
}
bool hasSubTree(binaryTreeNode *root1, binaryTreeNode *root2)
{
	bool result = false;

	if (root1 != NULL && root2 != NULL)
	{
		if (root1->item == root2->item)
			result = doesTree1HasTree2(root1, root2);
		if (!result)
			result = hasSubTree(root1->l_child, root2);
		if (!result)
			result = hasSubTree(root1->r_child, root2);
	}
	return result;
}

void treeMirrorRecusively(binaryTreeNode *root)
{
	if (root == NULL || (root->l_child == NULL && root->r_child == NULL))
		return;

	binaryTreeNode *temp = root->l_child;
	root->l_child = root->r_child;
	root->r_child = temp;

	if (root->l_child)
		treeMirrorRecusively(root->l_child);
	if (root->r_child)
		treeMirrorRecusively(root->r_child);

}

/*
 * 一条`路径`为从根节点到叶子节点的一条道，要判断路径所有值之和是否为一个value，首先要前序遍历该二叉树，
 * 遍历到一个节点，如果是叶节点且路径之和为value，就打印，否则退回父节点，并把该叶节点从路径中pop掉，
 * 路径之和的值中也减去该节点的值。
 */
void findPathMatchValue(binaryTreeNode *root, int expectedSum)
{
	if (root == NULL)
		return;

	int currentSum = 0;
	vector<int> path;  // 这里用vector而非stack的原因是，打印路径值需要访问所有元素值，但stack只能访问栈顶的。
	bool isFound = false;  // 找到路径的标记

	findPathMatchValue(root, expectedSum, path, currentSum, isFound);

	if (!isFound)
		cout << endl << "Not found a path that match the expectedSum." << endl;
}


void findPathMatchValue(binaryTreeNode *root, int expectedSum, vector<int> &path, int &currentSum, bool &isFound) 
{
	// 把当前节点加进路径，并计算sum值
	path.push_back(root->item);	
	currentSum += root->item;

	// 若当前节点为叶节点，且path的sum值为expectedSum，打印路径
	bool isLeaf = root->l_child == NULL && root->r_child == NULL;
	if (currentSum == expectedSum && isLeaf)
	{
		cout << endl << "Found path: ";
		isFound = true;
		for (auto iter = path.begin(); iter != path.end(); ++iter)
			cout << *iter << " ";
		cout << endl;
	}

	// 如果不是叶节点，继续递归判断
	if (root->l_child != NULL)
		findPathMatchValue(root->l_child, expectedSum, path, currentSum, isFound);
	if (root->r_child != NULL)
		findPathMatchValue(root->r_child, expectedSum, path, currentSum, isFound);

	// 在返回父节点之前，要把当前节点在路径中弹出，并从sum值中减去当前节点值
	path.pop_back();
	currentSum -= root->item;
}

/* 合并两个二叉树（leetcode-617）
 * 合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。
 */
binaryTreeNode *mergeTrees(binaryTreeNode *t1, binaryTreeNode *t2) {

	if (t1 == NULL) { return t2; }	
	if (t2 == NULL) { return t1; }	

	t1->item += t2->item;
	t1->l_child = mergeTrees(t1->l_child, t2->l_child);
	t1->r_child = mergeTrees(t1->r_child, t2->r_child);

	return t1;
} 

/* 层序遍历方法创建一个二叉树（非二叉搜索树）*/
void createBinarytree(binaryTreeNode * &root, vector<const char *> &v) 
{
	if (v.empty()) { root = NULL; return; }

	// 把vector中的元素顺序放入二叉树节点中中
	for (const char *val : v) {
		if (!strcmp(val, "")) { qq.push(NULL); }
		else { qq.push(val); }
	}
		
}

