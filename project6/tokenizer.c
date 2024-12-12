#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_null.h>
#include "tokenizer.h"


#define NEWLINE '\n'
#define STARTCOMMENT '/'
#define ASSERT_MALLOC(ptr,msg)     if((ptr)==NULL){ \
    fprintf(stderr, msg); \
    exit(EXIT_FAILURE); \
} \

#define ASSERT_INSTRUCTION_NODE_POINTER(ptr)    if((ptr)){ \
        ptr->next=*head;\
        *head=ptr;\
} \


enum reader_int {LINE_READ,ENDOFLINE=EOF};

//reverses the linked-list
struct ins *reverse(struct ins *);

//reads each line in the source file
enum reader_int reader(struct ins **head);

enum reader_int reader(struct ins **head){
     struct ins *new=NULL;
     int c;
     int allocFactor=1;

    //ignore whitespace
     while((isspace((c=getchar()))) && c!=NEWLINE);

     while (c!=NEWLINE) {
        //ignore the characters after comment
        if(c==STARTCOMMENT){
            while(getchar()!=NEWLINE);
            ASSERT_INSTRUCTION_NODE_POINTER(new)
            return LINE_READ;
        }
        //ignore whitespace
        else if (isspace(c)) {
            c=getchar();
            continue;
        }
        else if (c==EOF) {
            ASSERT_INSTRUCTION_NODE_POINTER(new)
            return ENDOFLINE;
        }

        if(new==NULL){
            //dynamically allocate memory
            new=malloc(sizeof(struct ins) + (MIN_INS_LEN * allocFactor)+1);
            ASSERT_MALLOC(new, "failed to allocate memory\n")
            new->n=0;
        }

        //assign character to character array
        assignCharacters:
        if(new->n < (MIN_INS_LEN * allocFactor)){
            new->instruction[new->n]=c;
            ++(new->n);
            new->instruction[new->n]='\0';
            c=getchar();
            continue;
        }
        //allocate and resign memory
        int sizeofNewBlock=sizeof(struct ins) + (++allocFactor * MIN_INS_LEN) + 1;
        void *temp=realloc(new, sizeofNewBlock);
        ASSERT_MALLOC(temp, "failed to allocate memory\n")
        if(temp!=new){
            new=temp;
        }
        goto assignCharacters;
     }

     ASSERT_INSTRUCTION_NODE_POINTER(new)
     return LINE_READ;
};

struct ins *tokenizer(void){
    struct ins *head=NULL;
    int lineStatus;
    //int line=1;

    while (lineStatus!=ENDOFLINE) {
        //printf("Reading line --> %d\n",line++);
        lineStatus=reader(&head);
    }
    return head;
};
