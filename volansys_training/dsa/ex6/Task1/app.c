
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"


int main()
{
    struct node *root = NULL;
    clock_t t;
    root = insertion(root, 45);
    root = insertion(root, 15);
    root = insertion(root, 79);
    root = insertion(root, 90);
    root = insertion(root, 10);
    root = insertion(root, 55);
    root = insertion(root, 12);
    root = insertion(root, 20);
    root = insertion(root, 50);

    Display_BST_tree_level_order_traversal_format(root);
    Display_BST_tree_in_order_traversal_format(root);
    Display_BST_tree_pre_order_traversal_format(root);
    Display_BST_tree_post_order_traversal_format(root);
   

    t = clock();
     search(root, 20);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
    printf("\nserarch data function took %f seconds to execute \n", time_taken);
    return 0;
}