/**
 * @file BinarySearchTree.cpp
 * @author Peter Schaefer (pscha710@live.kutztown.edu) / Dr. Spiegel
 * @brief Class DEFINITION for a BinarySearchTree object. In this implementation of a binary tree,
 * there are values of type T, and an integer count, which keeps track of possible duplicates.
 * @version 0.1
 * @date 2023-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <string>
#include <queue>
#include "BinarySearchTree.h"

using namespace std;

// Constructor
template <typename T>
BinaryTree<T>::BinaryTree()
{
  root = NULL;
}

// Place Element into Tree
// Returns 1 if inserted, 0 if data already in tree
template <typename T>
int BinaryTree<T>::insertToTree(const T &data)
{
  if (root == NULL)
  { // Empty Tree
    root = new TreeNode<T>(data);
    return (1);
  }
  // Search for spot to put data; We only stop when we get to the bottom (NULL)
  TreeNode<T> *t = root, *parent;
  while (t != NULL)
  {
    if (t->info == data) // data already in Tree, increment
    {
      t->count++;
      return (0);
    }
    parent = t; // Set the trail pointer to the ancestor of where we're going
    if (data < t->info)
      t = t->left;
    else
      t = t->right;
  }
  // Found the spot; insert node.
  if (data < parent->info)
    parent->left = new TreeNode<T>(data);
  else
    parent->right = new TreeNode<T>(data);
  return (1);
}

// Search for Element in Tree
// Assumes == is defined for T
// Returns pointer to count of T if Found, NULL otherwise
template <typename T>
T *BinaryTree<T>::treeSearch(const T &key)
{
  TreeNode<T> *t = root;
  while (t && t->info != key)
    if (key < t->info)
      t = t->left;
    else
      t = t->right;
  if (t)
    return (&t->count);
  return (NULL);
}

// Retrieve Element from Tree (leaving Tree Intact)
// Precondition: Item is in Tree
template <typename T>
T &BinaryTree<T>::retrieveFromTree(const T &key)
{
  TreeNode<T> *t;
  for (t = root; t->info != key;)
    if (key < t->info)
      t = t->left;
    else
      t = t->right;
  return (t->info);
}

// Remove an Element from the tree
// Precondition: Element is in the Tree;
template <typename T>
void BinaryTree<T>::deleteFromTree(const T &data)
{
  TreeNode<T> *nodeWithData, *nodeToDelete, *t = root, *trailT = NULL;
  // Find spot
  while (t->info != data)
  { // safe because of precondition
    trailT = t;
    if (data < t->info)
      t = t->left;
    else
      t = t->right;
  }
  nodeWithData = t; // Hold onto the data Node for later deletion
  // Case 1: Leaf?
  if (!(nodeWithData->left) && !(nodeWithData->right))
  {
    // No Subtrees, node is leaf...Wipe it
    // Is it the root?
    if (nodeWithData == root)
      root = NULL;
    else if (trailT->right == nodeWithData) // Parent's right child
      trailT->right = NULL;
    else
      trailT->left = NULL;
    nodeToDelete = nodeWithData; // free this at the end
  }
  else if (!(nodeWithData->left))
  {
    // If 1st condition false and this one's true, there's a right subtree
    if (!trailT)
    { // Node to delete is root and there is no left subtree
      nodeToDelete = root;
      root = root->right;
    }
    else
    { // Point parent's pointer to this node to this node's right child
      if (trailT->right == nodeWithData)
        trailT->right = nodeWithData->right;
      else
        trailT->left = nodeWithData->right;
      nodeToDelete = nodeWithData;
    }
  }
  else if (!(nodeWithData->right))
  {
    // If 1st 2 conditions false and this one's true, there's a left subtree
    if (!trailT)
    { // Node to delete is root and there is no left subtree
      nodeToDelete = root;
      root = root->left;
    }
    else
    { // Otherwise, move up the right subtree
      if (trailT->right == nodeWithData)
        trailT->right = nodeWithData->left;
      else
        trailT->left = nodeWithData->left;
      nodeToDelete = nodeWithData;
    }
  }
  else
  { // If you make it here, node has two children
    // Go to rightmost node in left subtree; we know there's a right child...
    for (trailT = nodeWithData, t = nodeWithData->left; t->right != NULL; trailT = t, t = t->right)
      ;
    // Want to copy data from node with 0 or 1 child to node with data to delete
    // Place node data in NodeWithData
    nodeWithData->info = t->info;
    nodeWithData->count = t->count;
    // Set the parent of source node to point at source node's left child
    //   (We know it hasn't a right child. Also ok if no left child.)
    if (trailT == nodeWithData)
      // Need to point parent correctly.
      //   See if after the we went left there was no right child
      //   If there was no right child, this is rightmost node in left subtree
      trailT->left = t->left;
    else // we did go right; after going left, there was a right child
      // rightmost node has no r. child, so point its parent at its l. child
      trailT->right = t->left;
    nodeToDelete = t;
  }
  delete nodeToDelete;
}

// Remove an Element from the tree
// Precondition: Element is in the Tree; AND there are 2 or more counts of the element
template <typename T>
void BinaryTree<T>::decrementFromTree(const T &data)
{
  TreeNode<T> *t = root;
  // Find spot
  while (t->info != data)
  { // safe because of precondition
    if (data < t->info)
      t = t->left;
    else
      t = t->right;
  }

  // decrement count of node
  t->count--;
}

// Need Helper to Recursively Print the Tree
template <typename T>
void BinaryTree<T>::printInorder(TreeNode<T> *t) const
// void printTheTree(TreeNode *T)
{
  if (t)
  {
    printInorder(t->left);
    cout << t->info;
    if (t->count > 1)
      cout << " (" << t->count << ")";
    cout << endl;
    printInorder(t->right);
  }
}

// Display Tree using InOrder Traversal
template <typename T>
void BinaryTree<T>::inorder() const
{
  printInorder(root);
}

// Need Helper to Recursively Print the Tree
template <typename T>
void BinaryTree<T>::printPreorder(TreeNode<T> *t) const
// void printTheTree(TreeNode *t)
{
  if (t)
  {
    cout << t->info;
    if (t->count > 1)
      cout << " (" << t->count << ")";
    cout << endl;
    printPreorder(t->left);
    printPreorder(t->right);
  }
}

// Display Tree using InOrder Traversal
template <typename T>
void BinaryTree<T>::preorder() const
{
  printInorder(root);
}

// Need Helper to Recursively Print the Tree
template <typename T>
void BinaryTree<T>::printPostorder(TreeNode<T> *t) const
// void printTheTree(TreeNode *t)
{
  if (t)
  {
    printPostorder(t->left);
    printPostorder(t->right);
    cout << t->info;
    if (t->count > 1)
      cout << " (" << t->count << ")";
    cout << endl;
  }
}

// Display Tree using InOrder Traversal
template <typename T>
void BinaryTree<T>::postorder() const
{
  printInorder(root);
}

template <typename T>
void BinaryTree<T>::treePrint() const
{
  treePrintHelper(root);
}

template <typename T>
void BinaryTree<T>::
    treePrintHelper(TreeNode<T> *root) const
{
  queue<TreeNode<T> *> Q;
  // A dummy node to mark end of level
  TreeNode<T> *dummy = new TreeNode<T>(-1);
  if (root)
  {
    cout << root->info;
    if (root->count > 1)
      cout << " (" << root->count << ")";
    cout << endl;
    Q.push(root->left);
    Q.push(root->right);
    Q.push(dummy);
  }
  TreeNode<T> *t = root;
  while (!Q.empty())
  {
    t = Q.front();
    Q.pop();
    if (t == dummy)
    {
      if (!Q.empty())
        Q.push(dummy);
      cout << endl;
    }
    else if (t)
    {
      cout << t->info;
      if (t->count > 1)
        cout << " (" << t->count << ")";
      cout << " ";
      Q.push(t->left);
      Q.push(t->right);
    }
  }
}

template class BinaryTree<int>;
