#include <stdio.h>
#include <stdlib.h>

typedef struct NODE 
{
        int value;
        struct NODE* next;

} aNode;


void addToLinkedList(aNode** list, int value) {

    aNode* newNode = (aNode *)malloc(sizeof(aNode));
    newNode->value = value;
    newNode->next  = NULL;

    aNode* freeSpot = *list;
    
    if( freeSpot == NULL ) *list = newNode;
    else {
        while(freeSpot->next != NULL) {
            freeSpot = freeSpot->next;
        }
        freeSpot->next = newNode;
    }
}

/*
aNode* addToLinkedList(aNode* list, int value) {

        aNode* freeSpot;
        aNode* newNode;

        // Find a free spot at the end to add the value
        freeSpot = list;
        while(freeSpot->next != NULL) {
                freeSpot = freeSpot->next;
        }

        newNode = (aNode *)malloc(sizeof(aNode));
        newNode->value = value;
        newNode->next  = NULL;
        freeSpot->next = newNode;

        return list;
}
*/

void printNodes(aNode* my_node) {

        printf(" %i ", my_node->value);
        if (my_node->next != NULL) {
                printNodes(my_node->next);
        }
}

void printLinkedList(aNode* list) {

        if (list != NULL) {
                printf("Content of list is :");
                printNodes(list);
        } else {
                printf("List is empty.");
        }

        printf("\n");

}

aNode *head=NULL;

int main(void) {

	addToLinkedList(&head, 5);
	addToLinkedList(&head, 10);
	printLinkedList(head);
}


