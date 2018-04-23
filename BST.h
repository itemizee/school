//****************************************************************************************************
//
//		File:					BST.h
//		
//		Student:				Josh Gerber
//
//		Assignment:	 			Program  # 11
//
//		Course Name:			Data Structures   II 
//
//		Course Number:			COSC 3100 - 01
//
//		Due:					April 5, 2016
//
//
//		Defines binary search tree class
//		 
//		
//****************************************************************************************************

#ifndef BST_H
#define BST_H

//****************************************************************************************************

#include <cmath>
#include "node.h"

//****************************************************************************************************

template <typename TYPE>
class BST
{
	private:
		Node<TYPE> * root;
		void _destruct(Node<TYPE> * pRoot);
		Node<TYPE> * _search(Node<TYPE> * pRoot, const TYPE & dataOut) const;
		Node<TYPE> * _insert(Node<TYPE> * pRoot, const TYPE & dataIn);					
		Node<TYPE> * _remove(Node<TYPE> * pRoot, const TYPE & dataOut);
		void _inorderTraverse(void (* process) (TYPE d), Node<TYPE> * pRoot);
		int _getCount(Node<TYPE> * pRoot) const;
		int _getHt(Node<TYPE> * pRoot) const;
		bool _isComplete(Node<TYPE> * pRoot);
		bool _isBalanced(Node<TYPE> * pRoot);
	public:
		BST();
		~BST();
		bool search(TYPE & dataOut) const;
		bool insert(const TYPE & dataIn);					
		bool remove(TYPE & dataOut);
		bool update(const TYPE & dataIn);
		void inorderTraverse(void (* process) (TYPE d));
		int getCount() const;
		int getHt() const;
		bool isEmpty() const;
		bool isFull() const;
		bool isComplete();
		bool isBalanced();

};

//****************************************************************************************************
//PRIVATE BELOW

template <typename TYPE>
void BST<TYPE>::_destruct(Node<TYPE> * pRoot)
{
	if(pRoot)
	{
		_destruct(pRoot -> left);
		_destruct(pRoot -> right);
		delete pRoot;
	}
}

//****************************************************************************************************

template <typename TYPE>
Node<TYPE> * BST<TYPE>::_search(Node<TYPE> * pRoot, const TYPE & dataOut) const
{
	if(pRoot)
	{
		if(dataOut < pRoot -> data)
			pRoot = _search(pRoot -> left, dataOut);
		else if(dataOut > pRoot -> data)
			pRoot = _search(pRoot -> right, dataOut);
	}

	return pRoot;
}

//****************************************************************************************************

template <typename TYPE>
Node<TYPE> * BST<TYPE>::_insert(Node<TYPE> * pRoot, const TYPE & dataIn)
{
	if(pRoot)
	{
		if(dataIn < pRoot -> data)
			pRoot -> left = _insert(pRoot -> left, dataIn);
		else
			pRoot -> right = _insert(pRoot -> right, dataIn);
	}
	else
	{
		pRoot = new Node<TYPE>(dataIn);
	}

	return pRoot;
}

//****************************************************************************************************

template <typename TYPE>
Node<TYPE> * BST<TYPE>::_remove(Node<TYPE> * pRoot, const TYPE & dataOut)
{
	Node<TYPE> * pDel;
	Node<TYPE> * pMax;

	if(pRoot)
	{
		if(dataOut < pRoot -> data)
		{
			pRoot -> left = _remove(pRoot -> left, dataOut);
		}
		else if(dataOut > pRoot -> data)
		{
			pRoot -> right = _remove(pRoot -> right, dataOut);
		}
		else
		{
			if((pRoot -> right) && (pRoot -> left))
			{
				pMax = pRoot -> left;
				
				while((pMax) && (pMax -> right))
					pMax = pMax -> right;

				pRoot -> data = pMax -> data;
				pRoot -> left = _remove(pRoot -> left, pMax -> data);
			}
			else
			{
				pDel = pRoot;
				pRoot = (pRoot -> left) ? (pRoot -> left) : (pRoot -> right);
				delete pDel;
			}
		}
	}

	return pRoot;
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE>::update(const TYPE & dataIn)
{
	bool success = false;
	Node<TYPE> * pFound = nullptr;

	pFound = _search(root, dataIn);

	if(pFound)
	{
		pFound -> data = dataIn;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
void BST<TYPE>::_inorderTraverse(void (* process) (TYPE d), Node<TYPE> * pRoot)
{
	if(pRoot)
	{
		_inorderTraverse(process, pRoot -> left);
		process(pRoot -> data);
		_inorderTraverse(process, pRoot -> right);
	}
}

//****************************************************************************************************

template <typename TYPE>
int BST<TYPE>::_getCount(Node<TYPE> * pRoot) const
{
	int count = 0;

	if(pRoot)
		count = _getCount(pRoot -> left) + _getCount(pRoot -> right) + 1;

	return count;
}

//****************************************************************************************************

template <typename TYPE>
int BST<TYPE>::_getHt(Node<TYPE> * pRoot) const
{
	int height = 0;

	if(pRoot)
		height = max(_getHt(pRoot -> left), _getHt(pRoot -> right)) + 1;

	return height;
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE>::_isComplete(Node<TYPE> * pRoot)
{
	bool complete = true;

	if(pRoot)
	{
		if(_getHt(pRoot -> left) == _getHt(pRoot -> right))
			complete = (_isComplete(pRoot -> left)) && (_isComplete(pRoot -> right));
		else
			complete = false;
	}

	return complete;
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE>::_isBalanced(Node<TYPE> * pRoot)
{
	bool balanced = true;
	int balanceFactor;

	if(pRoot)
	{
		balanceFactor = _getHt(pRoot -> left) - _getHt(pRoot -> right);

		if((balanceFactor >= -1) && (balanceFactor <= 1))
			balanced = (_isBalanced(pRoot -> left)) && (_isBalanced(pRoot -> right));
		else 
			balanced = false;
	}

	return balanced;
}

//****************************************************************************************************
//PUBLIC BELOW

template <typename TYPE>
BST<TYPE>::BST()
{
	root = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
BST<TYPE>::~BST()
{
	_destruct(root);
	root = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE>::search(TYPE & dataOut) const
{
	bool isFound = false;
	Node<TYPE> * pFound = nullptr;

	pFound = _search(root, dataOut);

	if(pFound)
	{
		dataOut = pFound -> data;
		isFound = true;
	}

	return isFound;
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE>::insert(const TYPE & dataIn)
{
	bool success = false;
	Node<TYPE> * pFound = nullptr;
	
	pFound = _search(root, dataIn);

	if(!pFound)
	{
		root = _insert(root, dataIn);
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE>::remove(TYPE & dataOut)
{
	bool success = false;
	Node<TYPE> * pFound;

	pFound = _search(root, dataOut);

	if(pFound)
	{
		success = true;
		dataOut = pFound -> data;
		root = _remove(root, dataOut);
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
void BST<TYPE>::inorderTraverse(void (* process) (TYPE d))
{
	_inorderTraverse(process, root);
}

//****************************************************************************************************

template <typename TYPE>
int BST<TYPE>::getCount() const
{
	return(_getCount(root));
}

//****************************************************************************************************

template <typename TYPE>
int BST<TYPE>::getHt() const
{
	return(_getHt(root) - 1);
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE>::isEmpty() const
{
	return (!root);
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE>::isFull() const
{
	bool full = true;

	Node<TYPE> * notFull = new (nothrow) Node<TYPE>();

	if(notFull)
	{
		full = false;
		delete notFull;
	}

	return full;
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE>::isComplete()
{
	return (_isComplete(root));
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE>::isBalanced()
{
	return (_isBalanced(root));
}

//****************************************************************************************************

#endif