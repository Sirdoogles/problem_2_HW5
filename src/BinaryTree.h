#pragma once

#include "Tree.h"
#include "TreeNode.h"
#include <vector>
#include <cstdio>
#include "LinkedStack.h"
#include <iostream>
#include <fstream>

template<class T>
class BinaryTree :  public Tree<T> {
private:
    TreeNode<T>* root;

    int height(TreeNode<T>* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(height(root->left), height(root->right));
    }

    void _destroyTree(TreeNode<T>* node)
    {
        if(node) { // Assurance if node actually exists.
            if (node->getLeft() != nullptr) { // Since traversal is pre-order, check left branch first, then repeat.
                _destroyTree(node->getLeft());
            }
            if (node->getRight() != nullptr) { // right after!
                _destroyTree(node->getRight());
            }

            delete node; // Finally got to "root" delete that.
        }
    }

    void _traversePostOrder(TreeNode<T>* node) // Not used.
    {
        // Base Case
        if(node == nullptr)
        {
            return;
        }
        // Left side first
        _traversePostOrder(node->getLeft());
        // Right side afterwards.
        _traversePostOrder(node->getRight());

        std::cout << node->val << " ";
    }

    bool _lca(TreeNode<T>* root, TreeNode<T>* &lca, T node1, T node2)
    {
        // Base Case: root is null.
        if(root == nullptr)
        {
            return false;
        }
        // Base Case,
        if(root->val == node1 || root->val == node2)
        {
            lca = root;
            return true;
        }
        // Recursively call _lca to check if there node1 or node2 is present in left or right subtrees.
        bool leftCheck = _lca(root->getLeft(), lca, node1, node2);
        bool rightCheck = _lca(root->getRight(), lca, node1, node2);

        // Both var. are true, which means node1 and node2 are found, update lca variable.
        if(leftCheck && rightCheck)
        {
            lca = root;
        }

        return (leftCheck || rightCheck); // Return boolean if node1 or node2 is found within current subtree.
    }

public:
    BinaryTree() : root(nullptr) {};

    BinaryTree(std::vector<T> &array) {
        // not implemented yet
    }

    BinaryTree(TreeNode<T>* root) : root(root) {
    }

    bool contains(T val) override {
        // not implemented yet
        return false;
    }

    void traverseInOrder(std::vector<T> & result) override {
        // homework, to be done iteratively

        LinkedStack<TreeNode<T>*> s;
        TreeNode<T>* current = root;

        while(current != nullptr || s.isEmpty() == false) // Run loop while current is not null or stack is not empty.
        {
            // Start traversing left of the tree.
            while(current != nullptr)
            {
                s.push(current); // Push the nodes in the stack
                current = current->getLeft(); // traverse!
            }

            current = s.peek(); // Reassign current from the stack.
            s.pop();

            std::cout << current->val << " "; // Print data.
            result.push_back(current->val); // Push into vector
            current = current->getRight(); // Focus on right
        }

        std::cout << std::endl;
    }

    void traversePreOrder() override {
        // don't bother
    }
    void traversePostOrder(std::vector<T> & result) override {
        // homework, to be done iteratively

        if(root == nullptr) // Root is null, do nothing.
        {
            return;
        }

        LinkedStack<TreeNode<T>*> s1; // Use a double stack system.
        LinkedStack<TreeNode<T>*> s2;

        s1.push(root); // Push root into stack 1.

        TreeNode<T>* node;

        while(!s1.isEmpty())
        {
            node = s1.peek();
            s1.pop();
            s2.push(node); // Push stack 2 the top of stack 1.

            if(node->getLeft()) // Left side first
            {
                s1.push(node->getLeft()); // push stack 1 the left node from root.
            }
            if(node->getRight()) // Then right.
            {
                s1.push(node->getRight());
            }
        }

        while(!s2.isEmpty())
        {
            node = s2.peek(); // Peek and pop.
            s2.pop();
            std::cout << node->val << " "; // Print out values.
            result.push_back(node->val); // Append values into vector.
        }
        std::cout << std::endl;
    }

    virtual ~BinaryTree() {
        // homework
        _destroyTree(root);
    }

    T LCA(T node1, T node2) {
        // homework

        TreeNode<T>* lca = nullptr;

        if(root->getLeft() != nullptr && root->getRight() != nullptr) // If subtrees exists, begin search.
        {
            _lca(root, lca, node1, node2);
        }

        if(lca != nullptr)
        {
            return lca->val;
        }

        else // If nothing is found, default to -1.
        {
            return -1;
        }
    }

    bool add(const T &) override {
        // not implemented yet
    }

    bool remove(const T &) override {
        // not implemented yet
    }

    int height() override {
        return height(root);
    }

};
