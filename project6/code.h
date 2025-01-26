//code table
//code lookup to asci
#ifndef CODE_H
#include "symbolTable.h"
#include "parser.h"
#define CODE_H
void translateA(struct Tokens *,struct symTable *);
void translateC(struct Tokens *,struct symTable *);
#endif
