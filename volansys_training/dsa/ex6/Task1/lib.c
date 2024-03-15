#include<stdio.h>
#include<stdlib.h>
#include"lib.h"
#include <time.h>


struct node *create(int item)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = item;
    new_node->Left = new_node->Right = NULL;
    return new_node;
}

struct node *insertion(struct node *root, int item)
{
    if (root == NULL)
        return create(item);
    if (item < root->data)
        root->Left = insertion(root->Left, item);
    else
        root->Right = insertion(root->Right, item);
    return root;
}


int height(struct node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->Left);
        int rheight = height(node->Right);
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}


void CurrentLevel(struct node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == 1)
    {
        printf("%d ", root->data);
    }
    else if (level > 1)
    {
        CurrentLevel(root->Left, level - 1);
        CurrentLevel(root->Right, level - 1);
    }
}

void LevelOrder(struct node *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
    {
        CurrentLevel(root, i);
    }
}


void inorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->Left);
    printf("%d ", root->data);
    inorderTraversal(root->Right);
}


void preorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorderTraversal(root->Left);
    preorderTraversal(root->Right);
}


void postorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->Left);
    postorderTraversal(root->Right);
    printf("%d ", root->data);
}


void Display_BST_tree_level_order_traversal_format(struct node *root)
{
    clock_t t0;
    t0 = clock();
    LevelOrder(root);
    t0 = clock() - t0;
    double time_taken = ((double)t0) / CLOCKS_PER_SEC; // in seconds
    printf("\nLevel Order Traversal took %f seconds to execute \n", time_taken);
}


void Display_BST_tree_in_order_traversal_format(struct node *root)
{
    clock_t t1;
    t1 = clock();
    inorderTraversal(root);
    t1 = clock() - t1;
    double time_taken = ((double)t1) / CLOCKS_PER_SEC; // in seconds
    printf("\ninorder Traversal took %f seconds to execute \n", time_taken);
}


void Display_BST_tree_pre_order_traversal_format(struct node *root)
{
    clock_t t2;
    t2 = clock();
    preorderTraversal(root);
    t2 = clock() - t2;
    double time_taken = ((double)t2) / CLOCKS_PER_SEC; // in seconds
    printf("\npreorder Traversaltook %f seconds to execute \n", time_taken);
}


void Display_BST_tree_post_order_traversal_format(struct node *root)
{
    clock_t t3;
    t3 = clock();
    postorderTraversal(root);
    t3 = clock() - t3;
    double time_taken = ((double)t3) / CLOCKS_PER_SEC; // in seconds
    printf("\npostorder Traversal took %f seconds to execute \n", time_taken);
}


void search(struct node *root, int item)
{
    if (root == NULL)
    {
        return;
    }
    if (item > root->data)
    {
        search(root->Right, item);
    }
    else if (item < root->data)
    {
        search(root->Left, item);
    }
    else if (item == root->data)
    {
        printf("%d is found\n", item);
    }
}