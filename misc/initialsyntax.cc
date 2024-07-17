
typedef struct dlist_node dlist_node;
struct dlist_node
{
	dlist_node *prev;
	dlist_node *next;
};

typedef struct dlist_head
{
	/*
	 * head.next either points to the first element of the list; to &head if
	 * it's a circular empty list; or to NULL if empty and not circular.
	 *
	 * head.prev either points to the last element of the list; to &head if
	 * it's a circular empty list; or to NULL if empty and not circular.
	 */
	dlist_node	head;
} dlist_head;

static dlist_head BackendList = {
    {&(BackendList).head, &(BackendList).head}
};

static dlist_head BackendList2;

