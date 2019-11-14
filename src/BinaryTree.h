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
        if(node) {
            if (node->getLeft() != nullptr) {
                _destroyTree(node->getLeft());
            }
            if (node->getRight() != nullptr) {
                _destroyTree(node->getRight());
            }

            printf("Node Destroyed! Value: ");
            std::cout << node->val << std::endl;
            delete node;
        }
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

    void traverseInOrder() override {
        // homework, to be done iteratively
    }

    void traversePreOrder() override {
        // don't bother
    }
    void traversePostOrder() override {
        // homework, to be done iteratively
    }

    virtual ~BinaryTree() {
        // homework
        _destroyTree(root);
        printf("Tree Blown Up!\n");
    }

    T LCA(T node1, T node2) {
        // homework
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
