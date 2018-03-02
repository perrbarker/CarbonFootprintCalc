#ifndef INTBST_H
#define INTBST_H

#include <iostream>
#include "Person.h"
#include "wx/wfstream.h"
#include "wx/datstrm.h"
#include <fstream>

using namespace std;



class AvgBST {
private:
	
	struct TreeNode{
		TreeNode() {
			
			left = NULL;
			right = NULL;
		}
		TreeNode(Person user) {
			info = user;
			left = NULL;
			right = NULL;
		}
		Person   info;
		TreeNode *left;
		TreeNode *right;

	};

	TreeNode *root;

	void insertNode(TreeNode*, Person, double);
	bool searchNode(TreeNode*, Person);
	//void removeNode(TreeNode*&, Person);
	void displayInOrder(TreeNode*) const;
	void displayPreOrder(TreeNode*) const;
	void displayPostOrder(TreeNode*) const;
	void destroyTree(TreeNode* node);
	int countNodes(TreeNode* node);
	int count;

public:
	AvgBST();
	~AvgBST();
	void insert(Person);
	bool search(Person);
	//void remove(Person);
	void displayInOrder() const;
	void displayPreOrder() const;
	void displayPostOrder() const;
	int countNodes();
};

#endif
