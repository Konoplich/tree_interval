#ifndef interface_c
#define interface_c
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>

#define TREE treeint_t *p_tree
#define PTREE treeint_t **p_tree
#define ROOT node_t *p_root
#define SafeDelete(x)		{ if (NULL != (x)) { free(x);     (x) = NULL; } }

#define DEBUG

#ifdef DEBUG
    #define p(...) printf("line %d ", __LINE__); printf(__VA_ARGS__);
#else
    #define p(...) /*__LINE__ __VA_ARGS__*/
#endif

#define ArraySize(x) (sizeof(x) / (sizeof((x)[0])))
#define Max(x, y) ((x)>(y)) ? (x) : (y)
#define Min(x, y) ((x)>(y)) ? (y) : (x)

typedef struct _void_ref
{
	u_int32_t  min;
	u_int32_t  max;
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

#endif
