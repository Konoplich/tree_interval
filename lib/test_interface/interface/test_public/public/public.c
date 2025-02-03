#ifndef public_c
#define public_c
#include <interface.c>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool new(PTREE)
{
    *p_tree = malloc(sizeof(treeint_t));
    if(NULL !=*p_tree)
    {
        memset(*p_tree, 0, sizeof(treeint_t));
        return true;
    }
    return false;
}

void free_node(ROOT)
{
    p("free node %p\n", p_root);
	if (NULL != p_root) {
		if (NULL != p_root->p_left) {
			free_node(p_root->p_left);
		}
		if (NULL != p_root->p_right) {
			free_node(p_root->p_right);
		}
		SafeDelete(p_root);
	}
}

node_t* new_node(void)
{
	node_t *pNew = malloc(sizeof(node_t));

	pNew->ref.min      = 0;
	pNew->ref.max        = 0;
	pNew->is_red        = true;
	pNew->p_left        = NULL;
	pNew->p_right       = NULL;

	return pNew;
}

void destructor(PTREE)
{
    p("destructor enter\n");
    p("destructor: %p\n", (*p_tree));
    free_node((*p_tree)->data);
    free(*p_tree);
    p_tree = NULL;
}

void print_rec(ROOT, u_int32_t tab, char *prefix)
{
    for(u_int32_t i=0;i<tab;i++)
        printf("-");
    printf(" ");
    printf("%s %p color: %5s, [%d-%d] max:%d\n",prefix, p_root, (p_root->is_red)?"red":"black", p_root->ref.min, p_root->ref.max, p_root->max);
    if(NULL != p_root->p_left)
        print_rec(p_root->p_left, tab+5, "L");
    if(NULL != p_root->p_right)
        print_rec(p_root->p_right, tab+5, "R");
}

void print(TREE)
{
    if(NULL != p_tree && NULL !=p_tree->data)
	    print_rec(p_tree->data, 1, "ROOT");
}

#endif
