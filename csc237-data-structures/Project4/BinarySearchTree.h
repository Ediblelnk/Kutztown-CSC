/**
 * @file BinarySearchTree.cpp
 * @author Peter Schaefer (pscha710@live.kutztown.edu) / Dr. Spiegel
 * @brief Class DECLARATION for a BinarySearchTree object. In this implementation of a binary tree,
 * there are values of type T, and an integer count, which keeps track of possible duplicates.
 * @version 0.1
 * @date 2023-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef TREE_H
#define TREE_H

template <typename T>
class BinaryTree;

/**
 * @brief A TreeNode contains data of type T, and its corresponding count, or number of times it is in the binary tree.
 * There are also pointers two a left child and a right child, which are initialized to NULL.
 *
 * @tparam T
 */
template <typename T>
class TreeNode
{
private:
  /**
   * @brief information / data that the node is storing.
   *
   */
  T info;

  /**
   * @brief pointers to the left and right children node of the node
   *
   */
  TreeNode<T> *left, *right;

  /**
   * @brief count of how many times this node's information is stored in the tree
   *
   */
  int count;

  /**
   * @brief Construct a new Tree Node object. Default to no children and 1 count.
   *
   * @param data data in the tree node
   * @param cnt count of data, defaults to 1
   * @param lChild left node of this node, defaults to NULL
   * @param rChild right node of this node, defaults to NULL
   */
  TreeNode(const T &data, int cnt = 1, TreeNode<T> *lChild = NULL, TreeNode *rChild = NULL)
  {
    info = data;
    count = cnt;
    left = lChild;
    right = rChild;
  }

  friend class BinaryTree<T>;
};

/**
 * @brief A BinaryTree, stores data in a tree format, where each node can have up to two children. Left children are
 * considered less than their parents, and right children are considered equal to or greater than their parents.
 *
 * @tparam T
 */
template <typename T>
class BinaryTree
{
public:
  /**
   * @brief Construct a new BinaryTree<T>::BinaryTree object
   *
   */
  BinaryTree();

  /**
   * @brief Place Element into Tree, returns 1 if new element, 0 if Data already in tree
   *
   * @param data
   * @return int
   */
  int insertToTree(const T &data);

  /**
   * @brief Search for Element in Tree, **Assumes == is defined for T.**
   * Returns pointer to count of the data, or NULL, according to success
   *
   * @param data
   * @return T*
   */
  T *treeSearch(const T &data);

  /**
   * @brief Retrieve Element from Tree (leaving Tree Intact), **Precondition: Item is in Tree**
   *
   * @param data
   * @return T&
   */
  T &retrieveFromTree(const T &data);

  /**
   * @brief Remove an Element from the tree, **Precondition: Item is in Tree**
   *
   * @param data
   */
  void deleteFromTree(const T &data);

  /**
   * @brief Decrements the count of an Element from the tree,
   * **Precondition: Item is in Tree AND count of Element is 2 or more**
   *
   * @param data
   */
  void decrementFromTree(const T &data);

  /**
   * @brief Display Tree using InOrder Traversal
   *
   */
  void inorder() const;

  /**
   * @brief Display Tree using PreOrder Traversal
   *
   */
  void preorder() const;

  /**
   * @brief Display Tree using PostOrder Traversal
   *
   */
  void postorder() const;

  /**
   * @brief Breadth first print
   *
   */
  void treePrint() const;

private:
  TreeNode<T> *root;

  /**
   * @brief Display Tree using InOrder Traversal
   *
   */
  void printInorder(TreeNode<T> *) const;

  /**
   * @brief Display Tree using PreOrder Traversal
   *
   */
  void printPreorder(TreeNode<T> *) const;

  /**
   * @brief Display Tree using PostOrder Traversal
   *
   */
  void printPostorder(TreeNode<T> *) const;

  /**
   * @brief Breadth first print
   *
   */
  void treePrintHelper(TreeNode<T> *) const;
};

#endif
