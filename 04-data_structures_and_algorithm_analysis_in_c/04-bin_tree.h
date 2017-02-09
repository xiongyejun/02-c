#ifndef _04_bin_tree_h
#define ElementType int

struct TreeNode;
typedef struct TreeNode *PtrToNode;
typedef PtrToNode Tree;
typedef struct TreeNode *SearchTree;
typedef struct TreeNode *Position;

SearchTree InitTree();
void PrintTree(SearchTree T);
SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T, SearchTree T_parent, int left_right);
SearchTree Delete(ElementType X, SearchTree T);

#endif
