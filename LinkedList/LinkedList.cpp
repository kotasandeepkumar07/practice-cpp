//// LinkedList.cpp : Defines the entry point for the console application.
////
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
//
///*
//class LinkedList
//{
//public:
//	struct Node
//	{
//		int data;
//		Node *link;
//	}*p;
//
//	LinkedList() { p = NULL;} 
//	void AddatEnd(int num);
//	void AddatBegining(int num);
//	int count();
//
//};// end of class LinkedList
//
//
//void LinkedList::AddatEnd(int num)
//{
//	Node *q, *t;
//
//	if(p == NULL)
//	{
//		p = new Node;
//		p->data = num;
//		p->link = NULL;
//	}
//
//	else
//	{
//		q = p;
//		while(q->link != NULL)
//		{
//			q = q->link ;
//		}
//		t = new Node;
//		t->data = num;
//		t->link = NULL;
//		q->link = t;
//	}
//
//}// end of LinkedList::AddatEnd(int num)
//
//void LinkedList::AddatBegining(int num)
//{
//	Node *q;
//	q =new Node;
//	q->data = num;
//	q->link = p;
//	p = q;
//
//}// end of LinkedList::AddatBegining(int num)
//
//
//int LinkedList::count()
//{
//	Node *q;
//	int count =0;
//
//	for(q = p; q != NULL; q = q->link)
//	{
//		count++;
//	}
//	return count;
//
//}// end of LinkedList::count()
//
//void main(int argc, char* argv[])
//{
//	LinkedList obj;
//	obj.AddatEnd(11);
//	obj.AddatEnd(22);
//	obj.AddatEnd(33);
//	obj.AddatEnd(44);
//
//	int i = obj.count();
//	cout<<i<<endl;
//
//}// end of main()
//*/
//
//
//class LinkList
//{
//public:
//	struct Node
//	{
//		int data;
//		Node *link;
//	}*p;
//
//	void addatend(int num);
//	int count();
//
//};
//
//void LinkList::addatend(int num)
//{
//	Node *temp, *r;
//
//	if (p == nullptr)
//	{
//		p = new Node;
//		p->data = num;
//		p->link = nullptr;
//	}
//
//	else
//	{
//		r = p;
//		while (r->link != nullptr)
//		{
//			r = r->link;
//		}
//		temp = new Node;
//		temp->data = num;
//		temp->link = NULL;
//		r->link = temp;
//	}
//}
//
//int  LinkList::count()
//{
//	Node *temp;
//	temp = p;
//
//	int count = 0;
//	while(temp!= nullptr)
//	{
//		temp = temp->link;
//		count++;
//	}
//
//	return count;
//}
//
//void main()
//{
//	LinkList obj;
//	obj.addatend(19);
//	obj.addatend(20);
//
//	cout<<obj.count()<<endl;
//}


//class LinkedList
//{
//public:
//	LinkedList() { pStart = NULL; }
//	struct Node
//	{
//		int nData;
//		Node *plink;
//	}*pStart;
//
//	void AddData(int nData);
//	void InsertatNIndex(int nPosition, int nData);
//	void AddDataBeg(int nData);
//	void PrintElements();
//	int	DeleteData();
//
//};
//
//void LinkedList::PrintElements()
//{
//	while (pStart != nullptr)
//	{
//		cout << pStart->nData << endl;
//		pStart = pStart->plink;
//	}
//}
//
////Add Elements at the end 
//void LinkedList::AddData(int nData)
//{
//	Node *ptemp,  *pLastNode;
//
//	if ( pStart == nullptr )
//	{
//		pStart = new Node;
//		pStart->nData = nData;
//		pStart->plink = NULL;
//	}
//	else
//	{
//		pLastNode = pStart;
//		while (pLastNode->plink != nullptr)
//		{
//			pLastNode = pLastNode->plink;
//		}
//		ptemp = new Node;
//		ptemp->nData = nData;
//		ptemp->plink = NULL;
//		pLastNode->plink = ptemp;
//	}
//}
//
////Add Elements at index nPosition
//void LinkedList::InsertatNIndex(int nPosition, int nData)
//{
//	Node *pNewNodeCreated = new Node();
//	pNewNodeCreated->nData = nData;
//
//	Node *temp = pStart;
//	for (int i = 0; i < nPosition - 2; i++) //reach n-1 th node
//	{
//		temp = temp->plink;
//	}
//
//	pNewNodeCreated->plink = temp->plink; //assign (n-1)th link (which basically has address to nth node TO node )
//	temp->plink = pNewNodeCreated; //assign the address of newwly created node to n-1 th node
//}
//
//void LinkedList::AddDataBeg(int nData)
//{
//	Node *ptemp;
//	ptemp = new Node;
//	ptemp->nData = nData;
//	ptemp->plink = pStart; //assign the address of starting node to newly created node so that it becomes first element in the list
//	pStart = ptemp;
//}
//
//void main()
//{
//	LinkedList listObj;
//	/*listObj.AddData(2);
//	listObj.AddData(3);
//	listObj.AddData(5);
//	listObj.PrintElements();*/
//
//
//	listObj.AddData(2);
//	listObj.AddData(3);
//	listObj.AddData(5);
//	listObj.AddDataBeg(10);
//	listObj.PrintElements();
//
//	//listObj.AddDataBeg(10);
//	listObj.AddData(2);
//	listObj.AddData(3);
//	listObj.AddData(5);
//	listObj.AddData(5);
//	//lets say index 3 i.e. after 2 elements 
//	listObj.InsertatNIndex(2, 15);
//	listObj.PrintElements();
//}


//template <class T>
//class LinkedList
//{
//private:
//	T m_nData;
//	LinkedList *m_pNext;
//
//public:
//	LinkedList()
//	{
//		m_nData = 0;
//		m_pNext = NULL;
//	}
//
//	void Insert(T nData)
//	{
//		if (m_pNext == NULL )
//		{
//			m_pNext = new LinkedList;
//			m_pNext->m_nData = nData;
//		}
//		else
//		{
//			LinkedList *pTemp = new LinkedList;
//			pTemp->m_nData = nData;
//			pTemp->m_pNext = NULL;
//
//
//			while (m_pNext != NULL)
//			{
//				m_pNext = m_pNext->m_pNext;
//			}
//			m_pNext->m_pNext =  pTemp;
//		}
//	}
//};
//
//void main()
//{
//	LinkedList<int> obj;
//	obj.Insert(10);
//	obj.Insert(20);
//	obj.Insert(30);
//
//}


class LinkedList
{
public:
	int m_nCount;
	struct Node
	{
		int nData;
		Node *pNext;
	}*pStart;

	LinkedList() 
	{
		pStart = nullptr; 
		m_nCount = 0;
	}

	//Insert At the End 
	void Insert(int nData)
	{
		if (pStart == NULL)
		{
			pStart = new Node;
			pStart->nData = nData;
			pStart->pNext = nullptr;
		}
		else
		{
			Node *temp = new Node;
			temp->nData = nData;
			temp->pNext = nullptr;

			Node *pLast = pStart;
			while (pLast->pNext != nullptr)
			{
				pLast = pLast->pNext;
			}

			pLast->pNext = temp;

			int i = 10;
		}
	}

	//Insert at Beginning 
	void InsertAtBeg(int nData)
	{
		if (pStart == NULL)
		{
			pStart = new Node;
			pStart->nData = nData;
			pStart->pNext = nullptr;
		}
		else
		{
			Node *temp = new Node;
			temp->nData = nData;
			temp->pNext = pStart;
			pStart = temp;
		}
	}

	//Insert nData at nIndex Position in the List, If the list is 0, 10, 20, 40, AFter inserting an element 30 at Index 3. The list should be 
	// 0, 10, 20, 30, 40
	void InsertAtPosition(int nIndex, int nData)
	{
		Node *pTemp = new Node;
		pTemp->nData = nData;

		Node *pFirst = pStart;

		int nPos = 0;
		while (pStart != nullptr)
		{
			if (nPos == nIndex - 1)
			{
				pTemp->pNext = pFirst->pNext;
				pFirst->pNext = pTemp;
				break;
			}

			pFirst = pFirst->pNext;
			nPos++;
		}
	}

	
	//Display Elements
	void Display()
	{
		while (pStart != nullptr)
		{
			cout << pStart->nData << " " << endl ;
			pStart = pStart->pNext;
		}
	}

	//Count Elements 
	void CountElements()
	{
		while (pStart != nullptr)
		{
			m_nCount++;
			pStart = pStart->pNext;
		}
		cout << "Count is " << m_nCount << endl;
	}

	//Sum of All Elements 
	void SumOfAllElements()
	{
		int nSum = 0;
		while (pStart != nullptr)
		{
			nSum = nSum + pStart->nData;
			pStart = pStart->pNext;
		}
		cout << "Sum of All Elements is  " << nSum << endl;
	}

	void PrintReverse()
	{
		while (pStart != nullptr)
		{
			cout << pStart->nData << " " << endl;
			pStart = pStart->pNext;
		}
	}

	//Find max Element in a linked List
	void MaxElementinList()
	{
		int nMax = INT_MIN;
		while (pStart != nullptr)
		{
			if ( pStart->nData > nMax )
				nMax = pStart->nData;

			pStart = pStart->pNext;
		}
		cout << "Maximum Element is  " << nMax << endl;
	}

	//Search for an element in LinkedList
	void SerachForAnElement(int nElementTobeFound)
	{
		int nIndex = 0;
		while (pStart != nullptr)
		{
			if (pStart->nData == nElementTobeFound)
			{
				cout << "Elemnt Found at Index " << nIndex << endl;
				break;
			}
			pStart = pStart->pNext;
			nIndex++;
		}
	}

	//Search for an element in LinkedList by moving the found element to the beginning so that it can be found in one comparision when searched next time 
	//This method is called move to head . If we are searching for 20 in 10, 20, 30, 40 then the list should become 20,30,40,10
	void SerachForAnElementImprovised(int nElementTobeFound)
	{
		Node *pPrev = NULL;
		int nIndex = 0;
		Node *ptemp = pStart;
		while (pStart != nullptr)
		{
			if (pStart->nData == nElementTobeFound)
			{
				pPrev->pNext = pStart->pNext;
				pStart->pNext = ptemp;
				cout << "Elemnt Found at Index " << nIndex << endl;
				break;
			}

			pPrev = pStart;
			pStart = pStart->pNext;
			nIndex++;
		}
	}


};


#include<string>


//struct ListNode
//{
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL)
//	{
//	}
//};
//
//
//class Solution {
//public:
//	
//	ListNode *pHead = NULL;
//
//
//	void InsertData(int nData)
//	{
//		if (pHead == NULL)
//		{
//			pHead = new ListNode(nData);
//			pHead->next = NULL;
//		}
//		else
//		{
//			ListNode *ptemp = new ListNode(nData);
//			ptemp->next = NULL;
//
//			ListNode *pNext = pHead;
//			while (pNext->next != NULL)
//			{
//				pNext = pNext->next;
//			}
//
//			pNext->next = ptemp;
//		}
//	}
//
//
//	ListNode* Add(string sRes)
//	{
//		for (int i = 0; i < sRes.length(); i++)
//		{
//			int nData = sRes[i] - 48;
//
//			if (pHead == NULL)
//			{
//				pHead = new ListNode(nData);
//				pHead->next = NULL;
//			}
//			else
//			{
//				ListNode *ptemp = new ListNode(nData);
//				ptemp->next = NULL;
//
//				ListNode *pNext = pHead;
//				while (pNext->next != NULL)
//				{
//					pNext = pNext->next;
//				}
//
//				pNext->next = ptemp;
//			}
//		}
//
//		return pHead;
//	}
//
//
//
//	ListNode* middleNode(ListNode* head) 
//	{
//		ListNode *pSlowPointer = head;
//		ListNode *pFastPointer = head;
//
//
//		while (pFastPointer != NULL && pFastPointer->next != NULL)
//		{
//			pFastPointer = pFastPointer->next->next;
//			pSlowPointer = pSlowPointer->next;
//		}
//
//		return pSlowPointer;
//	}
//
//	ListNode* reverseList(ListNode* head)
//	{
//		ListNode *pPrev = NULL;
//		ListNode *pNext = NULL;
//		ListNode *pCurrent = head;
//
//		while (pCurrent != NULL)
//		{
//			pNext = pCurrent->next;
//			pCurrent->next = pPrev;
//
//
//			pPrev = pCurrent;
//			pCurrent = pNext;
//		}
//
//		return pPrev;
//	}
//
//
//	void deleteNode(ListNode* node) 
//	{
//	
//		node->val = node->next->val;
//		node->next = node->next->next;
//	}
//
//	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
//	{
//
//		ListNode *phead = new ListNode(0);
//
//		ListNode *pTempList = phead;
//
//
//
//		while (l1 || l2 )
//		{
//
//
//
//			if (l1->val < l2->val)
//			{
//				pTempList->next = l1;
//				l1 = l1->next;
//			}
//			else
//			{
//				pTempList->next = l2;
//				l2 = l2->next;
//			}
//
//			pTempList = pTempList->next;
//			l1 = l1->next;
//			l2 = l2->next;
//		}
//
//		return phead->next;
//	}
//
//
//
//	int returnNumber(ListNode *list)
//	{
//		string s = "";
//		while (list)
//		{
//			s = s  +  to_string(list->val);
//			list = list->next;
//		}
//		std::reverse(s.begin(), s.end());
//		return  stoi(s);
//	}
//};

#include <map>
#include <set>
#include <vector>
#include <stack>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution
{
public:


	ListNode *pHead = NULL;
	ListNode *pList2 = NULL;
	void InsertDataList1(int nData)
	{
		if (pHead == NULL)
		{
			pHead = new ListNode(nData);
			pHead->next = NULL;
		}
		else
		{
			ListNode *ptemp = new ListNode(nData);
			ptemp->next = NULL;

			ListNode *pNext = pHead;
			while (pNext->next != NULL)
			{
				pNext = pNext->next;
			}

			pNext->next = ptemp;
		}
	}

	void InsertDataList2(int nData)
	{
		if (pList2 == NULL)
		{
			pList2 = new ListNode(nData);
			pList2->next = NULL;
		}
		else
		{
			ListNode *ptemp = new ListNode(nData);
			ptemp->next = NULL;

			ListNode *pNext = pList2;
			while (pNext->next != NULL)
			{
				pNext = pNext->next;
			}

			pNext->next = ptemp;
		}
	}


	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		l1 = reverseLinkedList(l1);
		l2 = reverseLinkedList(l2);

		int nres1 = 0;
		int nres2 = 0;

		if (l1)
			nres1 = returnNumber(l1);

		if (l2)
			nres2 = returnNumber(l2);

		int nRes = nres1  + nres2;
		string sRes = to_string(nRes);
		std::reverse(sRes.begin(), sRes.end());

		ListNode* pResult = new ListNode;

		for (int i = 0; i < sRes.length(); i++)
		{
			int nData = sRes[i] - 48;
			if (pResult == NULL)
			{
				pResult->val = nData;
				pResult->next = NULL;
			}
			else
			{
				ListNode *ptemp = new ListNode(nData);
				ptemp->next = NULL;

				ListNode *pNext = pResult;

				while (pNext->next != NULL)
				{
					pNext = pNext->next;
				}

				pNext->next = ptemp;
			}
		}
		return  pResult->next;
	}

	int returnNumber(ListNode *list)
	{
		string s = "";
		while (list)
		{
			s = s + to_string(list->val);
			list = list->next;
		}

		return  stoi(s);
	}

	ListNode* reverseLinkedList(ListNode* list)
	{
		ListNode* p = list;
		ListNode* q = NULL;
		ListNode* r = NULL;

		while (p != NULL)
		{
			r = q;
			q = p;
			p = p->next;
			q->next = r;
		}

		while (q != nullptr)
		{
			cout << q->val << endl;
			q = q->next;
		}

		return q;
	}

	ListNode* Add(string sRes)
	{
		for (int i = 0; i < sRes.length(); i++)
		{
			int nData = sRes[i] - 48;

			if (pHead == NULL)
			{
				pHead = new ListNode(nData);
				pHead->next = NULL;
			}
			else
			{
				ListNode *ptemp = new ListNode(nData);
				ptemp->next = NULL;

				ListNode *pNext = pHead;
				while (pNext->next != NULL)
				{
					pNext = pNext->next;
				}

				pNext->next = ptemp;
			}
		}
		return pHead;
	}

	ListNode* deleteDuplicates(ListNode* head)
	{
		ListNode* pCurrent = head;

		while (pCurrent != NULL && pCurrent->next != NULL)
		{
			if (pCurrent->val == pCurrent->next->val)
			{
				pCurrent->next = pCurrent->next->next;
			}
			else
			{
				pCurrent = pCurrent->next;
			}	
		}

		return head;
	}

//print middle eleent of a given Linked List
	ListNode* PrintMiddleElement(ListNode* head)
	{
		ListNode* pPrev = head;
		ListNode* pSlowPointer = head;
		ListNode* pFastPointer = head;

		while (pFastPointer &&  pFastPointer->next)
		{
			pPrev = pSlowPointer;

			pSlowPointer = pSlowPointer->next;
			pFastPointer = pFastPointer->next->next;
		}
		pPrev->next = pSlowPointer->next;

		return head;
	}

	//1,2,2,1,1

	bool isPalindrome(ListNode* head)
	{
		if (!head) return true;

		ListNode*reverseList = reverseLinkedList(head);
		while (reverseList != nullptr && head != nullptr)
		{
			if (reverseList->val != head->val)
				return false;
			reverseList = reverseList->next;
			head = head->next;
		}

		return true;
	}

	ListNode* oddEvenList(ListNode* &head)
	{
		if (!head)
			return head;

		ListNode* odd = head;
		ListNode* even = head->next;
		ListNode* temp = even;

		while (temp && temp->next)
		{
			odd->next = odd->next->next;
			temp->next = temp->next->next;

			odd = odd->next;
			temp = temp->next;
		}

		odd->next = even;
		return head;
	}


	std::vector<ListNode*> splitListToParts(ListNode* root, int k) 
	{
		ListNode *pTemp = root;
		std::vector<ListNode*> arrListNodes;
		int nCount = 0; 

		while (pTemp)
		{
			nCount++;
			pTemp = pTemp->next;
		}

		while (nCount < k && nCount >= -1)
		{
			ListNode *pTemp1 = root;
			while (pTemp1)
			{
				ListNode *pTemp = new ListNode;
				pTemp->val= pTemp1->val;

				arrListNodes.push_back(pTemp);
				pTemp1 = pTemp1->next;

				nCount--;
			}

			ListNode *pTemp = nullptr;
			arrListNodes.push_back(pTemp);
			nCount--;

			return arrListNodes;
		}

		int nParts = nCount / k;
		int nReminder = nCount % k;
		
		if (nReminder > 0) 
		{
			nParts++;
			nReminder--;
		}

		return arrListNodes;
	}


	//remove nth node from end of linked list
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode* pTemp = head;
		ListNode *pNewList = head;
		int nCount = 0;
		while (pTemp)
		{
			nCount++;
			pTemp = pTemp->next;
		}

		int c2 = 0;
		if (n >= nCount)
		{
			head = head->next;
		}
		else 
		{
			for (c2 = 1; c2 < nCount - n; c2++) 
			{
				pNewList = pNewList->next;
			}
			pNewList->next = pNewList->next->next;
		}
		return head;
	}

	//Insert node at position 
	ListNode* InsertatPosition(ListNode *head, int nData, int nPos)
	{

		if (head == nullptr)
		{
			ListNode* head = new ListNode(nData);
			head->next = nullptr;
		}


		ListNode* temp = head;
		for (int i = 0; i < nPos -1; i++)
		{
			temp = temp->next;
		}
		ListNode* newnode = new ListNode(nData);
		newnode->next = temp->next;
		temp->next = newnode;

		return head;
	}

	//delete given node
	void deleteNode(ListNode* node) 
	{
		node->val = node->next->val;
		node->next = node->next->next;
	}


	//sort linked list
	ListNode* sortList(ListNode* head) 
	{
		ListNode *resultNode= nullptr;
		std::vector<int> myArray;

		while (head)
		{
			myArray.push_back(head->val);
			head = head->next;
		}
		std::sort(myArray.begin(), myArray.end());

		for (auto it = myArray.begin(); it != myArray.end(); it++)
		{
			if (resultNode == nullptr)
			{
				resultNode = new ListNode;
				resultNode->val = *it;
				resultNode->next = NULL;
			}
			else
			{
				ListNode *pTemp = new ListNode;
				pTemp->val = *it;
				pTemp->next = NULL;

				ListNode *pFinal = resultNode;
				while (pFinal->next != nullptr)
				{
					pFinal = pFinal->next;
				}

				pFinal->next = pTemp;
			}
			
		}
		return resultNode;
	}


	ListNode* RotateList(ListNode* head, int k)
	{
		int nCount = 1;
		ListNode* pTemp = head;
		ListNode* newHead = head;

		while (pTemp->next)
		{
			pTemp = pTemp->next;
			nCount++;
		}

		pTemp->next = head;

		int val = k % nCount; //even if k > n By doing k % ncount it becomes less than n and hence we can rotate

		if (k %= nCount)
		{
			for (auto i = 0; i < nCount - k; i++)
				pTemp = pTemp->next;
		}

		newHead = pTemp->next;
		pTemp->next = NULL;

		return newHead;
	}



	ListNode* removeElements(ListNode* head, int val)
	{
		if (head == nullptr) return NULL;

		ListNode* pTemp = new ListNode(0);

		while (head != nullptr)
		{
			if (head->val != val)
			{
				ListNode *pNew = new  ListNode(head->val);
				pNew->next = nullptr;

				ListNode *p = pTemp;
				while (p->next != nullptr)
				{
					p = p->next;
				}
				p->next = pNew;
			}

			head = head->next;
		}

		return pTemp->next;
	}



	//has cycle
	bool hasCycle(ListNode *head)
	{
		std::vector<ListNode *> arr;
		if (head == nullptr) return false;
		if (head->next == nullptr) return false;

		while (head != nullptr)
		{
			arr.push_back(head);
			if (std::find(arr.begin(), arr.end(), head->next) != arr.end())
				return true;

			head = head->next;
		}

		return false;
	}

	//hascycle Two Pointer
	bool hasCycleTwoPointer(ListNode* head)
	{
		if (!head) return false;
		if (head == head->next) return true;

		ListNode* fastpointer = head;
		ListNode* slowpointer = head;

		while (fastpointer && fastpointer->next)
		{
			slowpointer = slowpointer->next;
			fastpointer = fastpointer->next->next;
			if (slowpointer == fastpointer)
				return true;
		}

		return false;
	}


	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{

		ListNode *tempA = headA;
		ListNode *tempB = headB;

		int lengthA = 0;
		while (tempA != nullptr)
		{
			lengthA++;
			tempA = tempA->next;
		}

		int lengthB = 0;
		while (tempB != nullptr)
		{
			lengthB++;
			tempB = tempB->next;
		}

		if (lengthA > lengthB)
		{
			while (lengthA - lengthB != 0)
				headA = headA->next;
		}

		if (lengthA < lengthB)
		{
			while (lengthB - lengthA != 0)
			{
				headB = headB->next;
				lengthB--;
			}		
		}

		while (headA && headB)
		{
			if (headA = headB)
				return headA;

			headA = headA->next;
			headB = headB->next;
		}

		return nullptr;
	}


	ListNode* addTwoNumbersEx(ListNode* l1, ListNode* l2)
	{
		pHead = nullptr;
		ListNode *preturn = addValues(l1, l2, 0);;
		return addValues(l1, l2, 0);
	}


	ListNode* addValues(ListNode* l1, ListNode* l2, int carry)
	{
		int value = 0;
		int reminder = 0;
		if (l1 == nullptr && l2 == nullptr && carry == 0) return nullptr;

		value = value + carry;

		if (l1)
		{
			value = value + l1->val;
		}

		if (l2)
		{
			value = value + l2->val;
		}

		if (value >= 10)
		{
			reminder = value % 10;
			value = value / 10;
		}		
		else
		{
			reminder = value;
			value = 0;
		}
			
		if (!pHead)
		{
			pHead = new ListNode(reminder);
			pHead->next = nullptr;
		}
		else
		{
			ListNode *pTemp = new ListNode(reminder);
			pTemp->next = nullptr;

			ListNode *pNext = pHead;
			while (pNext->next != nullptr)
			{
				pNext = pNext->next;
			}

			pNext->next = pTemp;
		}

		if (l1 == nullptr && l2 == nullptr)
			return pHead;

		if (l1 == nullptr)
		{
			addValues(nullptr, l2->next, value);
		}
		else if (l2 == nullptr)
		{
			addValues(l1->next, nullptr, value);
		}
		else
			addValues(l1->next, l2->next, value);

		return pHead;
	}


	void reorderList(ListNode* head)
	{
		if (!head) return;
		ListNode *temp = head;

		vector<int> res;
		while (temp != nullptr)
		{
			res.push_back(temp->val);
			temp = temp->next;
		}

		int i = 0;
		int k = 0;

		ListNode *p = head;
		ListNode *pNew = nullptr;

		int length = res.size();
		while (length > -1)
		{
			if (i % 2 == 0)
			{
				int value = res[res.size() - 1 - k];
				ListNode *pNew = new ListNode(value);
				pNew->next = nullptr;

				ListNode *pStore = p->next;
				pNew->next = pStore;
				p->next = pNew;

				k = k + 1;
			}

			p = p->next;
			i++;
			length = length - 1;
		}

		ListNode*q = head;
		for (int i = 0; i < res.size() -1; i++)
		{
			q = q->next;

		}
		q->next = nullptr;

	}
};

void main()
{
	//Solution st;
	//for (int i = 1; i < 3; i++)
	//{
	//	st.InsertDataList1(i);
	//}
	////st.splitListToParts(st.pHead, 5);
	//st.removeNthFromEnd(st.pHead, 2);



	//for (int i = 1; i < 5; i++)
	//{
		//s.InsertDataList1(9);
		
	//}
	
	//s.middleNode(s.pHead);
	//s.reverseList(s.pHead);
	//s.pTemp = s.pHead->next->next;
	//s.deleteNode(s.pTemp);
	//ListNode *l1 = new ListNode(1);

	//int nval = s.returnNumber(s.pHead);


	/*s.pList2 = NULL;
	s.InsertDataList2(1);
	s.InsertDataList2(9);
	s.InsertDataList2(9);
	s.InsertDataList2(9);
	s.InsertDataList2(9);
	s.InsertDataList2(9);
	s.InsertDataList2(9);
	s.InsertDataList2(9);
	s.InsertDataList2(9);
	s.InsertDataList2(9);

	s.addTwoNumbers(s.pHead, s.pList2);


	int nval1 = s.returnNumber(s.pHead);*/

	

	//int nRes = nval + nval1;
	//string sRes = to_string(nRes);
	//std::reverse(sRes.begin(), sRes.end());

	//int n = sRes.at(0);


/*
	s.pHead = NULL;
	s.InsertData(sRes[0]- 48);
	s.InsertData(sRes[1] - 48);
	s.InsertData(sRes[2] - 48);
	s.InsertData(sRes[3] - 48);
*/





	//s.pHead = NULL;
	//ListNode* temp =s.Add(sRes);
	//int j = 10;

	//LinkedList L1;
	/*L1.Insert(10);
	L1.Insert(20);
	L1.Insert(30);
	L1.Insert(40);*/

	//Test InsertAtPosition
	/*L1.Insert(0);
	L1.Insert(10);
	L1.Insert(20);
	L1.Insert(40);
	L1.InsertAtPosition(3, 30);
	L1.Display();*/

	/*L1.InsertAtBeg(100);
	L1.InsertAtBeg(200);
	L1.InsertAtBeg(300);
	L1.InsertAtBeg(400);*/

	/*L1.Display();
	L1.CountElements();
	L1.SumOfAllElements();
	L1.MaxElementinList();*/
	//L1.SerachForAnElement(20);

	//L1.SerachForAnElementImprovised(30);
	//L1.Display();

	/*Solution s;
	s.InsertDataList1(1);
	s.InsertDataList1(2);
	s.InsertDataList1(3);
	s.InsertDataList1(4);
	s.InsertDataList1(5);
	s.InsertDataList1(6);
	s.InsertDataList1(7);
	s.InsertDataList1(8);
	s.InsertDataList1(9);
	s.PrintMiddleElement(s.pHead);

	s.InsertDataList1(1);
	s.InsertDataList1(2);
	s.InsertDataList1(2);
	s.InsertDataList1(1);
	s.isPalindrome(s.pHead);*/



	/*Solution s;
	for (int i = 1; i < 5; i++)
	{

		s.InsertDataList1(1);
		s.InsertDataList1(22);
		s.InsertDataList1(45);
		s.InsertDataList1(18);
	}

	s.deleteNode(s.pHead->next);*/


	/*Solution s;
	s.InsertDataList1(4);
	s.InsertDataList1(2);
	s.InsertDataList1(1);
	s.InsertDataList1(3);
	s.sortList(s.pHead);*/

	Solution s;
	s.InsertDataList1(1);
	s.InsertDataList1(2);
	s.InsertDataList1(3);
	s.InsertDataList1(4);
	s.InsertDataList1(5);
	s.RotateList(s.pHead, 2);



	/*Solution s;
	s.InsertDataList1(1);
	s.InsertDataList1(2);
	s.InsertDataList1(6);
	s.InsertDataList1(3);
	s.InsertDataList1(4);
	s.InsertDataList1(5);
	s.InsertDataList1(6);
	s.removeElements(s.pHead, 6); */


	//Solution s;
	//s.InsertDataList1(3);
	//s.InsertDataList1(2);
	//s.InsertDataList1(0);
	//s.InsertDataList1(-4);
	//s.hasCycle(s.pHead);


	/*Solution s;
	s.InsertDataList1(1);
	s.InsertDataList1(2);
	s.InsertDataList1(2);
	s.InsertDataList1(1);
	s.InsertDataList1(1);
	s.isPalindrome(s.pHead);*/

	/*Solution s;
	s.InsertDataList1(4);
	s.InsertDataList1(1);
	s.InsertDataList1(8);
	s.InsertDataList1(4);
	s.InsertDataList1(5);

	s.InsertDataList2(5);
	s.InsertDataList2(6);
	s.InsertDataList2(1);
	s.InsertDataList2(8);
	s.InsertDataList2(4);
	s.InsertDataList2(5);
	s.getIntersectionNode(s.pHead, s.pList2);*/


	//Solution s;
	//s.InsertDataList1(5);
	///*s.InsertDataList1(4);
	//s.InsertDataList1(3);*/
	//
	//
	//s.InsertDataList2(5);
	///*s.InsertDataList2(6);
	//s.InsertDataList2(4);*/
	//s.addTwoNumbersEx(s.pHead, s.pList2);
	


	/*Solution s;
	s.InsertDataList1(1);
	s.InsertDataList1(2);
	s.InsertDataList1(3);
	s.InsertDataList1(13);
	s.InsertDataList1(12);
	s.InsertDataList1(11);
	s.reorderList(s.pHead);
*/


	/*Solution s;
	s.InsertDataList1(16);
	s.InsertDataList1(12);
	s.InsertDataList1(4);
	s.InsertDataList1(2);
	s.InsertDataList1(5);
	s.reverseLinkedList(s.pHead);*/


	//Solution s;
	//s.InsertDataList1(16);
	//s.InsertDataList1(13);
	//s.InsertDataList1(7);
	//s.InsertatPosition(s.pHead, 1, 2);
	
}




