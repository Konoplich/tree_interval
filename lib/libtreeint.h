#ifndef lib
#define lib

#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>

#define TREE treeint_t *p_tree
#define PTREE treeint_t **p_tree
#define ROOT node_t *p_root
#define SafeDelete(x)		{ if (NULL != (x)) { free_node(x);     (x) = NULL; } }

typedef struct _void_ref
{
	u_int32_t  min;
	u_int32_t max;
} void_ref_t;

typedef struct _node
{
    struct _node *p_right;
    struct _node *p_left;

    u_int32_t  max;
    void_ref_t ref;
    bool is_red;
} node_t;

typedef struct _treeint
{
    node_t *data;
} treeint_t;

bool insert(TREE, void_ref_t ref);
void delete(TREE, const u_int32_t key);
void* lookup(TREE, const u_int32_t key);

bool new(PTREE);
void destructor(PTREE);
void print(TREE);
void leaf_depth(TREE);
void traverse(TREE);
u_int32_t key_count(TREE);
void sanity_check(TREE);
#endif
