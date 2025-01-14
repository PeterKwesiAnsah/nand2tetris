//first pass label declarations...takes a pointer to a symTable
//second pass address variables...takes a pointer to a symTable
#ifndef SCANNER_H
#define SCANNER_H
#include "parser.h"
void labelScan(struct Tokens *);
void gotoScan(struct Tokens *);
#endif
