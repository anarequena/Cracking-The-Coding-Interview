/* Write code to remove duplicates from an unsorted linked list
    Input = linked list with duplicates
    Output = linked list without duplicates
    Questions?
    - the nodes are integers?
    - is it a singly or doubly linked list?
    - is it possible to have triplicates?

    What to do?
    1) Brute Force:
        take first node and compare to all the others,
        if theres duplicate, remove it.
        take second node and compare to all the others and so on...
        takes O(n²) time

    2)  sort the linked list
        compare one node with the next neighbour
        if equal, delete the neighbour and compare again (in case of triplicates)
        move on to the next node until the last one
        to sort takes O(nlogn) time
        to compare takes O(n) time, so in total we have O(nlogn)

    3)  hash table;
        put the first node on a hash and go to the next one
        checks the hash table if it already has the same value
        if not put the node one the hash table
        takes only one look on the linked list O(n)
*/

#include <stdio.h>
#include <stdlib.h>

/* struct of a node and the list */
typedef struct node{
    int key;
    struct node *next;
} node, *list;

/* remove the next node of p from the list */
void removeNode(node *p){
    node *q
    q = p->next;
    p->next = q->next;
    free(q);
}

/* look through the list and creates a hash */
void checkDup(node *head, int sizeList){
    node *p, *q;
    int *hash, hcode, n, i;

    // creates a hash list with the size of the list
    hash = malloc(sizeList * sizeof(int));

    // initializes the hash table with a invalid key value of the linked list
    for(i = 0; i < sizeList; i++){
        hash[i] = -1;
    }

    p = head;
    n = head->key;

    // i would have to think if this formula is unique for everyone, problably not
    hcode = n%sizeList
    hash[hcode] = n;

    while(p->next){
        q = p->next;
        n = q->key;
        hcode = n%sizeList;

        if(q->key == hash[hcode])
            removeNode(p);
        else
            hash[hcode] = q->key;

        p = q;
    }

}
