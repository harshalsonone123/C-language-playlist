/**
 * Take home assignment 2
 * CSL 102 2021
 * Compilation error = 0
 * Late submission = 0
 * Presence of uncommented main function in the submission file = 0
 * Cheating/plagiarism = 0
 * */

#define EMPTYNODE 0

typedef enum
{
    LIST_FALSE = 0,
    LIST_TRUE = 1,
} status_t;

struct nodeQ
{
    int data;
    struct nodeQ *next;
};

struct nodeQ *head = EMPTYNODE;
struct nodeQ *curr = EMPTYNODE;

typedef struct nodeQ nodeQ_t;

/**
 * Create a linked list from the values in the array
 * The size of the array could be anywhere from 1 to 1000
 * The data in the list must be in the same order as the input array
 * Return the head node
 * values is the input array
 * sz is the size of the array
 * */
nodeQ_t *createList(short values[], short sz)
{
    printf(" creating list with headnode as %d\n", values);
    struct nodeQ *ptr = (struct nodeQ *)malloc(sizeof(struct nodeQ));
    if (EMPTYNODE == ptr)
    {
        printf("\n Node creation failed \n");
        return EMPTYNODE;
    }
    ptr->data = values;
    ptr->next = EMPTYNODE;

    head = curr = ptr;
    return ptr;
};

/**
 * Delete all nodes whose data value matches the input data value
 * For example, for input data value 7 and input list 5->6->7->7->9->19->2->3->7->11->EMPTYNODE
 * the new list will be 5->6->9->19->2->3->11->EMPTYNODE
 * If the head changes, update the new head using the out_newHead variable
 * If the operation is successful return LIST_TRUE, else LIST_FALSE 
 * */
status_t deleteNodes(nodeQ_t *head, nodeQ_t **out_newHead, short in_data, nodeQ_t *prev)
{
    while (head != EMPTYNODE && head->data == in_data)
    {
        *out_newHead = head->next;
        free(head);
        head = *out_newHead;
    }
    while (head != EMPTYNODE)

    {

        while (head != EMPTYNODE && head->data != in_data)
        {
            prev = head;
            head = head->next;
        }

        if (head == EMPTYNODE)
            return;

        prev->next = head->next;

        free(head);

        head = prev->next;
    }
};
/**
 * For a given input list that starts with head, split it into two lists
 * 1) List of all even indices made available using out_evenList
 * 2) List of all odd indices made available using out_oddList
 * For example list 4->6->7->19->5->24->45->1->1->8->EMPTYNODE will be split into
 * out_evenList = 4->7->5->45->1->EMPTYNODE
 * out_oddList = 6->19->24->1->8->EMPTYNODE
 * If the operation is successful return LIST_TRUE, else LIST_FALSE 
 * */
status_t splitLists(nodeQ_t *head, nodeQ_t **out_evenList, nodeQ_t **out_oddList)
{
    struct Node *a = EMPTYNODE;
    struct Node *b = EMPTYNODE;

    struct Node *curr = head;
    while (curr != EMPTYNODE)
    {
        MoveNode(&a);
        if (curr != EMPTYNODE)
        {
            MoveNode(&b);
        }
    }
    *out_evenList = a;
    *out_oddList = b;
};

/**
 * In this example below the next for nodes 24 and 44 both point to 45
 * head1 = 4->6->7->19->5->24-> \
 *                                ->45->1->1->8->EMPTYNODE
 * head2 =         81->15->44-> /
 * This the common sublist for both the lists is 45->1->1->8->EMPTYNODE
 * 
 * It is possible that the input lists head1 and head2 do not have a sub list in common
 * 
 * If the operation is successful return LIST_TRUE, else LIST_FALSE 
 * If there does not exist a common sublist return LIST_FALSE
 * */
status_t getCommonSubList(nodeQ_t *head1, nodeQ_t *head2, nodeQ_t **out_commonSubList)
{
    int x1 = getCount(head1);
    int x2 = getCount(head2);
    int d;

    if (x1 > x2)
    {
        d = x1 - x2;
        return getCommonSubList(d, head1, head2);
    }
    else
    {
        d = x2 - x1;
        return getCommonSubList(d, head2, head1);
    }
};