/**
 * CSL 102 Lab 7
 * Submission deadline Thursday July 1 @ 6am
 * 
 * Compilation error = ZERO
 * Submission filename not having your roll no = ZERO
 * Pleading for marks despite compilation error = NEGATIVE FOUR
 * Pleading for marks without running evalution tool = NEGATIVE FOUR
 * Copying code from each other = NEGATIVE FOUR
 * Keeping main function in the submission code = NEGATIVE FOUR
 * Keep the file extension in lower case c
 * 
 * * 
 * Suggestion:
 * * Implement the main function in a separate c file and not in the submission c file
 * */

#define EMPTYNODE 0

struct node
{
    short data[4]; // pay attention
    struct node *next;
    struct node *prev;
} * head, *last;

typedef struct node nodeQ_t;

typedef enum
{
    LIST_FALSE = 0,
    LIST_TRUE = 1,
} status_t;

/**
 * Example doubly linked list
 * 	   HEAD						   			    TAIL
 * 		|										 |
 * [2,5,1,6] <=> [4,7,8,9] <=> [0,3,6,3] <=> [43,7,32,7] <=> EMPTYNODE
 * */

/**
 * Method to create a node by passing an array. 
 * Create a node on the heap memory and return the address
 **/
nodeQ_t *createNode(short values[4])
{
    int i, data;
    struct node *newNode;

    if (values >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));

        if (head != EMPTYNODE)
        {
            printf("Enter data of one node: ");
            scanf("%d", &data);

            *head->data = data;
            head->prev = EMPTYNODE;
            head->next = EMPTYNODE;

            last = head;

            /*
             * Create rest of the n-1 nodes
             */
            for (i = 2; i <= values; i++)
            {
                newNode = (struct node *)malloc(sizeof(struct node));

                if (newNode != EMPTYNODE)
                {
                    printf("Enter data of %d node: ", i);
                    scanf("%d", &data);

                    *newNode->data = data;
                    newNode->prev = last;
                    newNode->next = EMPTYNODE;

                    last->next = newNode;
                    last = newNode;
                }
                else
                {
                    printf("Unable to allocate the memory.");
                    break;
                }
            }

            printf("\ndoubly linked list is created\n");
        }
        else
        {
            printf("Unable to allocate memory");
        }
    }
};

/**
 * Method to append a node after the tail
 * Pointers to head node and new node will be provided as input
 * If the operation is successful return LIST_TRUE, else LIST_FALSE 
 * For invalid address as input, return LIST_FALSE
 **/
status_t appendNode(nodeQ_t *tail, nodeQ_t *newNode)
{
    struct node *newNode;

    if (last == EMPTYNODE)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        *newNode->data = tail;
        newNode->next = EMPTYNODE;
        newNode->prev = last;

        last->next = newNode;
        last = newNode;

        printf("node is appended after the tail succesfully\n");
    }
};

/**
 * Method to prepend a node before the head
 * Pointers to head node and new node will be provided as input
 * If the operation is successful return LIST_TRUE, else LIST_FALSE 
 * For invalid address as input, return LIST_FALSE
 **/
status_t prependNode(nodeQ_t *head, nodeQ_t *newNode)
{
    struct node *toDelete;

    if (head == EMPTYNODE)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = head;

        head = head->next;

        if (head != EMPTYNODE)
            head->prev = EMPTYNODE;

        free(toDelete);
        printf("node is prepended before the head succesfully\n");
    }
};

/**
 * Method to delete a node
 * Instead of the array, only a single value is provided as input.
 * Delete all nodes where data[4] consists of value
 * If the head changes, update the new head using the out_newHead variable
 * If the operation is successful return LIST_TRUE, else LIST_FALSE 
 * For invalid address as input, return LIST_FALSE
 **/
status_t deleteNode(nodeQ_t *head, nodeQ_t **out_newHead, short value)
{
    struct node *current;
    int i;

    current = head;
    for (i = 1; i < value && current != EMPTYNODE; i++)
    {
        current = current->next;
    }

    if (value == 1)
    {
        deleteFromBeginning();
    }
    else if (current == last)
    {
        deleteFromEnd();
    }
    else if (current != EMPTYNODE)
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;

        free(current);

        printf("node is deleted succesfully from %d value\n", value);
    }
    else
    {
        printf("Invalid position!\n");
    }
};