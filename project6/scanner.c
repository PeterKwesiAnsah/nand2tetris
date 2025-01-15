//resolves variables and goto declarations.
#include "scanner.h"
#include "symbolTable.h"
#include "parser.h"
#include <sys/_types/_null.h>
#define VARIABLE_ADDRESS 16


unsigned address=VARIABLE_ADDRESS;
void labelScan(struct Tokens *ins){
    int i;
    for(i=0;i<ins->count;i++){
        if(ins->darray[i]->tokenKind==LABEL){
            //set goto address to sym table
            //each instruction has line i+1
            //so the next instruction has line i+2
            setSymValue(ins->darray[i]->tokenType.address, i+2);
        }
    }
}

void variableScan(struct Tokens *ins){
    int i;
    for(i=0;i<ins->count;i++){
        char *variable=ins->darray[i]->tokenType.address;
        if(ins->darray[i]->tokenKind==A && getSymValue(variable)==NULL){
            setSymValue(variable, address++);
        }
    }
}
