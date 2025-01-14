//resolves variables and goto declarations.
#include "scanner.h"
#include "symbolTable.h"
#include "parser.h"


void labelScan(struct Tokens *ins){
    int i;
    for(i=0;i<ins->count;i++){
        if(ins->darray[i]->tokenKind==LABEL){
            //set
        }
    }
}
