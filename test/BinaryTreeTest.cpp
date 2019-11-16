#include "BinaryTree.h"
#include "gtest/gtest.h"

TEST(tree_height, demo) {
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(5));

    BinaryTree<int> tree(root);

    ASSERT_EQ(tree.height(),3);
}

TEST(tree_inOrder_It, demo2)
{
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(5));

    BinaryTree<int> tree2(root);

    std::vector<int> answer{2, 1, 7 ,3 ,5, 5};
    std::vector<int> inOrder;
    tree2.traverseInOrder(inOrder);

    ASSERT_EQ(inOrder, answer);
}

TEST(tree_postOrder_It, demo3)
{
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(5));

    BinaryTree<int> tree3(root);

    std::vector<int> answer{2, 7, 1, 5, 5, 3};
    std::vector<int> postOrder;
    tree3.traversePostOrder(postOrder);

    ASSERT_EQ(answer,postOrder);
}

TEST(tree_LCA, demo4)
{
    TreeNode<int>* root = new TreeNode<int>(4);
    root->setLeft(new TreeNode<int>(8));
    root->setRight(new TreeNode<int>(6));

    root->getLeft()->setLeft(new TreeNode<int>(7));
    root->getLeft()->setRight(new TreeNode<int>(3));

    root->getRight()->setLeft(new TreeNode<int>(2));
    root->getRight()->setRight(new TreeNode<int>(9));
    
    BinaryTree<int> tree4(root);

    int output;

    output = tree4.LCA(6,3);
    std::cout << output << std::endl;


}
