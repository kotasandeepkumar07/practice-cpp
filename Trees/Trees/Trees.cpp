// Trees.cpp : Defines the entry point for the console application.
//


/*
Binary Tree Data Structure :
	A tree whose elements have at most 2 children is called a binary tree
	Since each element in a binary tree can have only 2 children, we typically name them the left and right child.
	Unlike Arrays, Linked Lists, Stack and queues, which are linear data structures, trees are hierarchical data structures.

Tree Vocabulary:
	The topmost node is called root of the tree.
	The elements that are directly under an element are called its children
	The element directly above something is called its parent.

Why Trees ?
	Trees might be useful when you want to store information that naturally forms a hierarchy. For example, the file system on a computer:
	Searching an Element in Trees :  Faster than Linked List and Slower than Arrays
	Insert/Delete an Element in Trees: Faster than Array and Slower than Linked List
	Trees do not have limit on adding number of elements like Linked Lists

Applications of Trees
	1. Manipulate hierarchical data.
	2. Make information easy to search (see tree traversal).
	3. Manipulate sorted lists of data.
	4. As a workflow for compositing digital images for visual effects.
	5. Router algorithms
	6. Form of a multi-stage decision-making (see business chess).

Binary Tree Properties

	Maximum number of nodes at level ‘k’
		The maximum number of nodes at level ‘k’ of a binary tree is 2^(k-1)
		Since in Binary tree every node has at most 2 children, next level would have twice nodes, i.e. 2 * 2^(k-1)

	Maximum number of nodes in a binary tree of height ‘h’ is 2^(h) – 1
		Maximum Nodes at level 1 is 1
		Maximum Nodes at level 2 is 2
		Maximum Nodes at level 3 is 4
		The above is derived from 2^(k-1)
		so maximum nodes of tree of height k is 1 + 2 + 4 + ....+ 2^(k-1) = (2^h) - 1

	Minimum possible height or minimum number of levels where N is number of nodes
		log(N+1)

Types of Binary Trees

	Full Binary Tree
		 A Binary Tree is full if every node has 0 or 2 children

	Complete Binary Tree
		 Binary Tree is complete Binary Tree if all levels are completely filled except possibly the last level and the last level has all keys as left as possible

	Perfect Binary Tree 
		A Binary tree is Perfect Binary Tree in which all internal nodes have two children and all leaves are at the same level.

	Balanced Binary Tree
		A binary tree is balanced if the height of the tree is O(Log n) where n is the number of nodes
		AVL Trees: AVL tree maintains O(Log n) height by making sure that the difference between heights of left and right subtrees is atmost 1
		Red-Black Trees: Maintain O(Log n) height by making sure that the number of Black nodes on every root to leaf paths are same and there are no adjacent red nodes.
		Balanced Binary Search trees are performance wise good as they provide O(log n) time for search, insert and delete.


BFS vs DFS for Binary Tree
	Breadth First Traversal (Or Level Order Traversal)
	Depth First Traversals
		Inorder Traversal (Left-Root-Right)
		Preorder Traversal (Root-Left-Right)
		Postorder Traversal (Left-Right-Root)

Time Complexity?
		All four traversals require O(n) time as they visit every node exactly once.
*/

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <set>

using namespace std;


/* A binary tree node has key, pointer to left child and a pointer to right child */
struct Node
{
	int key;
	Node *left;
	Node *right;

	Node(int x)
	{
		key = x;
		left = right = NULL;
	}

	Node()
	{
		key = 0;
		left = right = NULL;
	}

} *root = nullptr;


/********************************   Insert in a BST -- Iterative ***************************************************/
void Insert(int nValue)
{
	if (root == nullptr)
	{
		root = new Node(nValue);
		root->left = root->left = nullptr;
	}
	else
	{
		Node *temp = root;
		Node *r = nullptr, *p = nullptr;

		while (temp != nullptr)
		{
			r = temp;

			if (nValue < temp->key)
			{
				temp = temp->left;
			}
			else if (nValue > temp->key)
			{
				temp = temp->right;
			}
			else 
			{
				return;
			}
		}

		p = new Node(nValue);
		p->left = p->right = nullptr;

		if ( nValue < r->key )
			r->left = p;
		else
			r->right = p;
	}
}

/********************************   Insert in a BST -- Recursive ***************************************************/
Node* Insert(Node *head, int nValue)
{
	if (head == nullptr)
	{
		head = new Node(nValue);
		head->left = head->left = nullptr;
		return head;
	}
	if (head->key > nValue)
		head->left = Insert(head->left, nValue);

	else if (head->key < nValue)
			head->right = Insert(head->right, nValue);

	return head;
}


/********************************   Search in a BST -- Iterative *******************************/

Node *Search(int value)
{
	if (!root) return nullptr;

	while (root != nullptr)
	{
		if (root->key == value)
			return root;
		if (root->key < value)
			root = root->right;
		else
			root = root->left;
	}

	return root;
}


/********************************   Search in a BST -- Recursive *******************************/

Node* Search(Node *root, int value)
{
	if (!root) return nullptr;

	if (root->key == value)
		return root;

	if (root->key < value)
		Search(root->left, value);
	else
		Search(root->right, value);

	return NULL;
}


/********************************   Delete in a BST -- Recursive *******************************/


int Height(Node *root)
{
	if (!root) return 0;
	int x = Height(root->left);
	int y  = Height(root->right);
	return x > y ? x + 1 : y + 1;
}

Node* InPre(Node* root)
{
	if (!root) return nullptr;
	if (root->right != nullptr)
	{
		root = root->right;
	}

	return root;
}


Node* InSucce(Node* root)
{
	if (!root) return nullptr;
	if (root->left != nullptr)
	{
		root = root->left;
	}

	return root;
}

Node* Delete(Node *p, int key) 
{
	Node* q;

	if (p == nullptr) 
	{
		return nullptr;
	}
	if (p->left == nullptr && p->right == nullptr)
	{
		if (p == root) 
		{
			root = nullptr;
		}

		delete p;
		return nullptr;
	}

	if (key < p->key) {
		p->left = Delete(p->left, key);
	}
	else if (key > p->key) {
		p->left = Delete(p->left, key);
	}
	else 
	{
		if (Height(p->left) > Height(p->right)) 
		{
			q = InPre(p->left);
			p->key = q->key;
			p->left = Delete(p->left, q->key);
		}
		else 
		{
			q = InSucce(p->right);
			p->key = q->key;
			p->right = Delete(p->right, q->key);
		}
	}
	return p;
}


/* Inorder traversal of a binary tree*/
void InOrderTraversal(Node *root)
{
	if (root == nullptr)
		return;

	/* first recur on left child */
	InOrderTraversal(root->left);

	/* then print the data of node */
	cout << root->key << " ";

	/* now recur on right child */
	InOrderTraversal(root->right);
}



/* PreOrder traversal of a binary tree*/
void PreOrderTraversal(Node *root)
{
	if (root == nullptr)
		return;

	/* first print data of node */
	cout << root->key << " ";

	/* then recur on left sutree */
	PreOrderTraversal(root->left);

	/* now recur on right subtree */
	PreOrderTraversal(root->right);
}

/* PostOrder traversal of a binary tree*/
void PostOrderTraversal(Node *root)
{
	if (root == nullptr)
		return;

	/* then recur on left sutree */
	PostOrderTraversal(root->left);

	/* now recur on right subtree */
	PostOrderTraversal(root->right);

	/* first print data of node */
	cout << root->key << " ";
}


/* Compute the "height" of a tree -- the number of
nodes along the longest path from the root node
down to the farthest leaf node.*/
int height(Node* node)
{
	if (node == NULL)
		return 0;
	else
	{
		/* compute the height of each subtree */
		int lheight = height(node->left);
		int rheight = height(node->right);

		/* use the larger one */
		if (lheight > rheight)
			return(lheight + 1);
		else return(rheight + 1);
	}
}


void PrintGivenlevel(Node* root, int level)
{
	if (root == NULL)
		return;

	if (level == 1)
		cout << root->key << " ";

	if (level > 1)
	{
		PrintGivenlevel(root->left, level - 1);
		PrintGivenlevel(root->right, level - 1);
	}
}



void printLevelOrder(Node* root)
{
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
		PrintGivenlevel(root, i);
}



/************************************** Insert element in binary tree **************************************/

void InsertNewNode(Node* temp, int key)
{
	queue<Node*> q;
	q.push(temp);

	while (!q.empty())
	{
		Node *temp = q.front(); //Maintain a queue for each element in the tree form top and check if it has left and right children,
		q.pop();						// If it has then push that also to queue else insert there 
		
		if (temp == NULL)
			return;

		if (temp->left == NULL)
		{
			temp->left= new Node(key);
			break;
		}
		else
		{
			q.push(temp->left);
		}

		if(temp->right == NULL)
		{
			temp->right = new Node(key);
			break;
		}
		else
		{
			q.push(temp->right);
		}	
	}
}


/************************************** Delete deepest/last in binary tree **************************************/

void DeleteDeepestNode(Node* root, Node* deepestNode)
{
	queue<Node *> q;
	q.push(root);

	while (!q.empty())
	{
		Node *temp = q.front();
		q.pop();

		if (temp == NULL)
			return;

		if (temp == deepestNode)
		{
			temp = NULL;
			delete temp;
		}

		if (temp->left != NULL)
		{
			if (temp->left != deepestNode)
				q.push(temp->left);
			else
			{
				temp->left = NULL;
				delete deepestNode;
				break;
			}		
		}

		if (temp->right != NULL)
		{
			if (temp->right != deepestNode)
				q.push(temp->right);
			else
			{
				temp->right = NULL;
				delete deepestNode;
				break;
			}
			
		}
	}
}


void NthInorder(struct Node* node, int n)
{
	static int count = 0;
	int nValue = LONG_MIN;

	if (node == NULL)
		return;

	if (count <= n) {

		/* first recur on left child */
		NthInorder(node->left, n);
		count++;

		// when count = n then print element 
		if (count == n)
			nValue = n;

		/* now recur on right child */
		NthInorder(node->right, n);
	}
}



/********************************* Invert a Binary Node *****************************/
//class Solution
//{
//public:
//	Node* invertTree(Node* root)
//	{
//		if (root == NULL)
//			return root;
//
//		std::queue<Node*> q;
//		q.push(root);
//
//		while (!q.empty())
//		{
//			Node *temp = q.front();
//			q.pop();
//
//			std::swap(temp->left, temp->right);
//
//			if (temp->left)
//				q.push(temp->left);
//
//			if (temp->right)
//				q.push(temp->right);
//
//		}
//
//		return root;
//
//	/*	if (root == NULL)
//			return root;
//		invertTree(root->left);
//		invertTree(root->right);
//		std::swap(root->left, root->right);
//
//		return root;*/
//	}
//};



/********************************** Range Sum of BST ***********************************/
//class Solution
//{
//public:
//	int rangeSumBST(Node* root, int L, int R)
//	{
//		static int nSum = 0;
//
//		if (root == nullptr)
//		{
//			nSum += 0;
//			return 0;
//		}
//			
//		if (root->key >= L && root->key <= R)
//			nSum = nSum + root->key;
//
//		rangeSumBST(root->left, L, R);
//
//		rangeSumBST(root->right, L, R);
//
//		return nSum;
//	}
//};


/*************** Search in a Binary Search Tree ******************************/
//class Solution {
//public:
//	bool bFound = false;
//	Node* searchBST(Node* root, int val)
//	{
//		if (!root) return NULL;
//
//		if (root->key == val)
//		{
//			bFound = true;
//			return root;
//		}
//			
//		if (!bFound)
//			return searchBST(root->left, val);
//
//		if (!bFound)
//			return searchBST(root->right, val);
//
//		return nullptr;
//	}
//};

/******************* Maximum Depth of Binary Tree ******************************/
//class Solution 
//{
//public:
//	int maxDepth(Node* root)
//	{
//		int count = 1;
//		if (!root) return 0;
//		int nleftDepth = maxDepth(root->left);
//		int nrightDepth = maxDepth(root->right);
//		
//		return (std::max(nleftDepth, nrightDepth) + 1);
//	}
//};


/******************* Validate Binary Search Tree ******************************/ 
//class Solution 
//{
//public:
//	bool isValidBST(Node* root, Node* min = NULL, Node* max = NULL) 
//	{
//		if (!root) return true;
//
//		if (min != NULL && root->key <= min->key) 
//			return false;
//
//		if (max != NULL && root->key >= max->key) 
//			return false;
//
//		return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
//	}
//};


class Solution
{
public:
	int count = 0;
	vector<int> res;

	int pathSum(Node* root, int sum)
	{
		if (!root) return 0;
		Getsum(root, sum);
		return count;
	}


	void Getsum(Node* root, int sum)
	{
		if (!root) return ;
		res.push_back(root->key);
		Getsum(root->left, sum);
		Getsum(root->right, sum);

		int temp = 0;
		for (int i = res.size() - 1; i > -1; i--)
		{
			temp = temp + res[i];
			if (temp == sum)
				count++;
		}
		res.pop_back();
	}


	int rob(Node* root)
	{
		if (!root) return 0;
		int sum = 0;
		std::queue<Node*> myq;
		myq.push(root);

		std::vector<int> nums;
		while (!myq.empty())
		{
			int nsize = myq.size();
			for (int i = 0; i < nsize; i++)
			{
				
				Node *p = myq.front();
				myq.pop();

				sum = sum + p->key;

				if (p->left)
					myq.push(p->left);

				if (p->right)
					myq.push(p->right);

			}

			nums.push_back(sum);
			sum = 0;
		}

		int even_sum = 0;
		int odd_sum = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (i % 2 == 0)
				even_sum = max(even_sum + nums[i], odd_sum);
			else
				odd_sum = max(odd_sum + nums[i], even_sum);
		}
		return max(even_sum, odd_sum);
	}

	std::set<int> myset;
	int kthSmallest(Node* root, int k)
	{
		getsmallvalue(root, k);

		if (k <= myset.size())
		{
			auto it = myset.begin();
			std::advance(it, k -1);
			return *it;
		}

		return -1;
	}

	void getsmallvalue(Node* root, int k)
	{
		if (!root) return;

		myset.insert(root->key);

		if (root->left)
			getsmallvalue(root->left, k);

		if (root->right)
			getsmallvalue(root->right, k);
	}
};


/******************************************* Symmetric Tree ***********************************************/
//class Solution
//{
//public:
//	bool isSymmetric(Node* root)
//	{
//		return (isMirror(root, root));
//	}
//
//	bool isMirror(Node* rootL, Node* rootR)
//	{
//		if (!rootL && !rootR) return true;
//
//		if ( rootL && rootR && rootL->key == rootR->key)
//		{
//			return 
//				(
//					isMirror(rootL->left, rootR->right) && 
//					isMirror(rootL->right, rootR->left)
//				);
//		}
//
//
//		return false;
//	}
//};



/**************** Convert Sorted Array to Binary Search Tree *************************/
//class Solution 
//{
//public:
//	Node* sortedArrayToBST(vector<int>& nums, int nStart, int nEnd) 
//	{
//
//		if (nStart > nEnd)
//			return NULL;
//
//		int nMid = nStart + nEnd / 2;
//
//		int MidVal;
//		if (nMid < nums.size())
//			MidVal = nums[nMid];
//		
//		Node *p = new Node(MidVal);
//
//		p->left = sortedArrayToBST(nums, nStart, nMid-1);
//		p->right = sortedArrayToBST(nums, nMid + 1, nEnd);
//
//
//		return p;	
//	}
//};



/****************************** Leaf-Similar Trees ***************************/
//class Solution 
//{
//public:
//	std::vector<int> res;
//
//	bool leafSimilar(Node* root1, Node* root2)
//	{
//
//		if (!root1 && !root2) return true;
//		if (!root1 || !root2) return false;
//
//		std::vector<int> resroot1 = ReturnLeafNodes(root1);
//		res.clear();
//		std::vector<int> resroot2 = ReturnLeafNodes(root2);
//
//		bool bReturn;
//		resroot1 == resroot2 ? bReturn=  true : bReturn = false;
//		return bReturn;
//		
//	}
//
//
//	vector<int> ReturnLeafNodes(Node* root1)
//	{
//		if (root1)
//		{
//			if ( root1->left == NULL && root1->right == NULL)
//				res.push_back(root1->key);
//			ReturnLeafNodes(root1->left);
//			ReturnLeafNodes(root1->right);
//		}
//
//		return res;
//	}
//
//	vector<int> preorderTraversalIterative(Node* root)
//	{
//		if (!root) return res;
//		std::queue<Node*> myqueue;
//		myqueue.push(root);
//
//		while (!myqueue.empty())
//		{
//			Node *pTempNode = myqueue.front();
//
//
//			res.push_back(pTempNode->key);
//			myqueue.pop();
//
//			if (pTempNode->left)
//				myqueue.push(pTempNode->left);
//
//			if (pTempNode->right)
//				myqueue.push(pTempNode->right);
//
//		}
//
//		return res;
//	}
//};


void main()
{

	/************ Initialize Tree ******************/

	Node *root = new Node(5);

	root->left = new Node(3);
	root->left->left = new Node(2);
	root->left->right = new Node(4);
	root->left->left->left = new Node(1);
	//root->left->left->right = new Node(-2);
	//root->left->right->right = new Node(1);
	////root->left->right = new Node(4);
	////root->left->right->left = new Node(6);

	root->right = new Node(6);
	////root->right->left = new Node(6);
	//root->right->right = new Node(1);
	////root->right->right->right = new Node(25);


	//Node *root1 = new Node(3);
	//root1->left = new Node(9);
	////root->left->left = new Node(3);
	////root->left->left->left = new Node(1);

	////root->left->right = new Node(4);
	////root->left->right->left = new Node(6);

	//root1->right = new Node(20);
	//root1->right->left = new Node(15);
	////root1->right->right = new Node(7);
	////root->right->right->right = new Node(25);

/*************   Recursive insert elements into BST  **************/
	/*Node * root = nullptr;
	root = Insert(root, 10);
	Insert(root, 45);
	Insert(root, 2);
	Insert(root, 67);*/


	/*************   Iterative insert elements into BST **************/
	/*Insert(3);
	Insert(4);
	Insert(5);
	Insert(1);
	Insert(3);
	Insert(1);*/

	//Node *temp = Search(45);

	int k = 10;

	cout << "Inorder traversal" << endl;
	InOrderTraversal(root);
	cout << endl;

	//Delete(root, 45);

	//cout << "Initial tree" << endl;
	//InOrderTraversal(root);
	//InsertNewNode(root, 12);
	//cout << "Tree after Insertion" << endl;

	//InOrderTraversal(root);
	//cout << "Tree after Deletion" << endl;
	//DeleteDeepestNode(root, root->left->right);
	//InOrderTraversal(root);
	//height(root);
	//NthInorder(root, 2);





///***** DFS Depth First Traversal Start  *******/

	/*cout << "Inorder traversal after"<<endl;
	InOrderTraversal(root);
	cout << endl;*/

	//cout << "Pre order traversal"<<endl;
	//PreOrderTraversal(root);
	//cout << endl;

	//cout << "Post order traversal"<<  endl;
	//PostOrderTraversal(root);
	//cout << endl;




/********** DFS Depth First Traversal End  *************/
	//PrintGivenlevel(root, 4);


/***************** Invert a Binary Node  ***************/
	//Solution s;
	//s.invertTree(root);


/**************  Range Sum of BST *****************/
	/*Solution s;
	s.rangeSumBST(root, 6, 10);*/


/***********  Search in a Binary Search Tree *******/
	/*Solution s;
	s.searchBST(root, 2);*/


/********** Maximum Depth of Binary Treee *********/
	/*Solution s;
	int n  = s.maxDepth(root);*/


/******** Validate Binary Search Tree *************/
	//Solution s;
	//bool b = s.isValidBST(root);


/******** Symmetric Tree *************/
	/*Solution s;
	bool b = s.isSymmetric(root);*/

/****** Convert Sorted Array to Binary Search Tree ************/
	/*std::vector<int>arr {-10, -3, 0, 5, 9};
	int n = sizeof(arr) / sizeof(arr[0]);

	Solution s;
	Node *p = s.sortedArrayToBST(arr, 0, n - 1);*/


	/****** Leaf-Similar Trees ************/
	/*Solution s;
	s.leafSimilar(root, root1);*/


	/*Solution s1;
	s1.preorderTraversalIterative(root);*/



	/***********  Path Sum III **********/
	/*Solution s1;
	s1.pathSum(root, 8);*/


	/*Solution s;
	s.rob(root);*/

	Solution s;
	s.kthSmallest(root, 3);

	int i = 10;
}






