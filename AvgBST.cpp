//FINAL POLISHED

#include <iostream>
#include "AvgBST.h"
#include "Person.h"
#include <fstream>


ofstream STATS;

AvgBST::AvgBST() {
	Person Average("Average");
	Average.setCarbonFootprint(19702);

	root = new TreeNode(Average);
	

}

void AvgBST::insert(Person user) {

	insertNode(root, user, user.getCarbonFootprint());
}

void AvgBST::insertNode(TreeNode* node, Person user, double data) {
	if (node == NULL){
		root = new TreeNode(user);
	
	}
	else if (node != NULL) {
		TreeNode* currentNode = root;
		while (currentNode != NULL){
			if (user.getCarbonFootprint() < currentNode->info.getCarbonFootprint()){
				if (currentNode->left == NULL){
					currentNode->left = new TreeNode(user);
					currentNode = NULL;
				}
				else{
					currentNode = currentNode->left;
				}
			}
			else{
				if (currentNode->right == NULL){
					currentNode->right = new TreeNode(user);
					currentNode = NULL;
				}
				else{
					currentNode = currentNode->right;
				}
			}
			}
		}
	}
			
	

void AvgBST::displayInOrder() const {

	STATS.open("InProject.txt");

	displayInOrder(root);

	STATS.close();
	
}

void AvgBST::displayInOrder(TreeNode* node) const {

	

	if (node != NULL) {
		//cout << "testing...\n";
		displayInOrder(node->left);

		STATS << node->info.getCarbonFootprint() << " : "
			<< node->info.getUserName() << "; "; //writes to text file
		
		displayInOrder(node->right);

	}



}

void AvgBST::displayPreOrder() const {

	displayPreOrder(root);

}

void AvgBST::displayPreOrder(TreeNode* node) const {

	if (node) {

		cout << node->info.getCarbonFootprint() << " " 
			<< node->info.getUserName() << " " << endl;

		displayPreOrder(node->left);

		displayPreOrder(node->right);

	}

}

void AvgBST::displayPostOrder() const {

	displayPostOrder(root);

}

void AvgBST::displayPostOrder(TreeNode*  node) const {

	if (node) {

		displayPostOrder(node->left);	

		displayPostOrder(node->right);

		cout << node->info.getCarbonFootprint() << " " 
			 << node->info.getUserName() << " " << endl;

	}

}

bool AvgBST::search(Person user) {

	return searchNode(root, user);

}

bool AvgBST::searchNode(TreeNode* node, Person user) {

	if (node == NULL)

		return NULL;

	else if (user.getCarbonFootprint() == node->info.getCarbonFootprint())

		return true;

	else if (user.getCarbonFootprint() < node->info.getCarbonFootprint())

		return searchNode(node->left, user);

	else

		return searchNode(node->right, user);

}
/*
void AvgBST::remove(Person user) {

	removeNode(root, user);

}

void AvgBST::removeNode(TreeNode*& node, Person user) {

	if (node == NULL)

		cout << "cannot remove data " << user.getUserName() << endl;

	else if (user.getCarbonFootprint() < node->data->getCarbonFootprint())

		removeNode(node->left, user);

	else if (user.getCarbonFootprint() > node->data->getCarbonFootprint())

		removeNode(node->right, user);

	else { // found node containing data

		TreeNode* toDelete = node;

		if (node->left == NULL) { // at most one child only (no left child)

			node = node->right;

			delete toDelete;

		}

		else if (node->right == NULL) { // at most one child only (no right child)

			node = node->left;

			delete toDelete;

		}

		else { // two children

			// get data from the rightmost node in the left subtree

			TreeNode* temp = node->left;


			while (temp->right != NULL)

				temp = temp->right;

			// swap data and delete the rightmost node in the left subtree

			node->data = temp->data;
		
			removeNode(node->left, temp.data);

		}

	}

}
*/
AvgBST::~AvgBST() {

	destroyTree(root);

}

void AvgBST::destroyTree(TreeNode* node) {

	if (node) {

		if (node->left)

			destroyTree(node->left);

		else if (node->right)

			destroyTree(node->right);

		delete node;

	}

}

int AvgBST::countNodes(){

	countNodes(root);

	return count;

}

int AvgBST::countNodes(TreeNode* node){

	if (node == NULL){

		return count;

	}

	else{

		countNodes(node->left);

		++count;

		countNodes(node->right);

	}

}
/*
			FOLLOWING CODE WAS USED FOR DEBUGGING

int main(){
	
	AvgBST FtEmitAvg;

	Person User;
	User.setUserName("Perry");
	//TEST TRANSPORTATION FUNCTIONS
	cout << "USER NAME " << User.getUserName() << endl;
	User.setCarPoolSize(1);
	User.setDailyMiles(20);
	User.setCarMPG(35, User.getCarPoolSize());
	cout << "USER MPG " << User.getCarMPG() << endl;
	cout << "TOTAL TRANSPORTATION EMMISSIONS " << User.calcTransportation() << endl;
	//TEST HOUSE ENERGY FUNCTIONS
	User.setHouseholdSize(3);
	User.setElectricUsage(50.59);
	User.setGasUsage(22.57);
	cout << "ELECTRIC BILL " << User.getElectricUsage() << endl;
	cout << "GAS BILL " << User.getGasUsage() << endl;
	cout << "HOUSE ENERGY EMISSIONS " << User.calcHouseEnergy() << endl;
	//TEST WASTE FUNCTIONS
	cout << "RECYCLE METAL " << User.recyMetal(0) << endl;
	cout << "RECYCLE NEWSPAPER " << User.recyNewspaper(0) << endl;
	cout << "RECYCLE GLASS " << User.recyGlass(0) << endl;
	cout << "RECYCLE PLASTIC " << User.recyPlastic(0) << endl;
	cout << "RECYCLE MAGAZINES " << User.recyMagazines(0) << endl;
	cout << "TOTAL WASTE EMISSIONS " << User.calcWaste() << endl;
	//TEST FOOTPRINT
	cout << "CARBON FOOTPRINT " << User.calcCarbonFootprint() << endl;
	cout << User.getCarbonFootprint() << endl;

	//TESTING BST
	Person Average;
	Average.setUserName("AVERAGE");
	Average.setCarbonFootprint(19702);
	FtEmitAvg.insert(Average);
	FtEmitAvg.insert(User);

	

	cout << "IN ORDER FROM LEAST TO GREATEST ";

	FtEmitAvg.displayPreOrder() ;

	cout << FtEmitAvg.search(User);

	


	system("PAUSE");
	return 0;
	
}
*/