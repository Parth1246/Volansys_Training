struct node *create(int item);
struct node *insertion(struct node *root, int item);
int height(struct node *node);
void CurrentLevel(struct node *root, int level);
void LevelOrder(struct node *root);
void inorderTraversal(struct node *root);
void preorderTraversal(struct node *root);
void postorderTraversal(struct node *root);
void Display_BST_tree_level_order_traversal_format(struct node *root);
void Display_BST_tree_in_order_traversal_format(struct node *root);
void Display_BST_tree_pre_order_traversal_format(struct node *root);
void Display_BST_tree_post_order_traversal_format(struct node *root);
void search(struct node *root, int item);


struct node
{
    
    int data;
    struct node *Left;
    struct node *Right;
};