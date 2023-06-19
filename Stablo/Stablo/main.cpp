#include "BSTree.h"
#include "MinHeap.h"

int main() {
	BSTree bst;
	//int a[] = { 56, 26, 28, 200, 190, 213, 27 };
	int a[] = { 56, 26, 28, 200, 18, 24, 190, 213, 27, 12};
	MinHeap mh(10);
	for (int i = 0; i < 10; i++)
		mh.insert(a[i]);
	mh.printHeap();
	cout << endl;
	mh.updateEl(26, -18);
	mh.printHeap();
	//MinHeap::HeapSort(a, 10);
	//for (int i = 0; i < 10; i++)
	//	cout << a[i] << " ";
	//for (int i : a) {
	//	bst.insert(i);
	//}
	//bst.insert(29);
	//bst.insert(30);
	//bst.insert(23);
	//cout << bst.isPerfect();
	//cout << bst.countNodesInRange(28, 50);
	//cout << bst.countCloseSiblings();
	//BSTNode* node = bst.findSibling(bst.find(56));
	//if (node == 0)
	//	cout << "0";
	//else
	//	node->visit();
	//cout << bst.deleteAllLeftLeafs() << endl;
	//bst.breadthFirst();
	//cout << bst.countSL();
	//cout << bst.countSingleLeavesNodes();
	//bst.findNodeWithLargestRightSubtree()->visit();
	//cout << bst.countSpecificNodes();
	//bst.getNNode()->visit();
	//int maxDifference;
	//bst.biggestDifference(&maxDifference)->visit();
	//cout << endl << maxDifference;
	//cout << bst.countWeight();
	//cout << bst.findLevelWidth(2);
	//cout << bst.countGreater(18);
	//cout << bst.deleteRightLeaves() << endl;
	//bst.breadthFirst();
	//BSTNode* node;
	//cout << bst.getDeepest(&node) << endl;
	//node->visit();


	//for (int i : a) {
	//	bst.insert(i);
	//}

	//bst.recursiveInorder();
	//bst.iterativeInorder();
	//bst.recursivePreorder();
	//bst.iterativePreorder();
	//bst.recursivePostorder();
	//bst.iterativePostorder();
	//bst.breadthFirst();
	//bst.deleteByCopying(26);
	//bst.breadthFirst();

}