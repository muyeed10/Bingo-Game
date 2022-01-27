#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "list.h"

//this function adds value to the CALLLIST and increases the length by 1
void ADD (int value, ADT *p) {
         
        p->numarr[p->length]=value;
        p->length++;
}

//this function initializes the ADT. Allocates memory accoding to specific size(for us 75*4)
void INITIALIZE(int maxsize, ADT *p) {
        p->length=0;
	p->numarr=(int*)malloc(maxsize * sizeof(4));
}

//this function checks if an item is present in the CallList
int CHECK(int item, ADT *p) {
    
    for(int i=0; i < p->length; i ++) {
        
        if(item == p->numarr[i]) {
            return 0; //reutrns 0 if item is found (false)
        }
    }
    return 1; //returns 1 if item is not found (true)
}

//this function prints the CallList according to range
void PRINT(ADT *p) {
    
    for(int i=0; i < p->length; i ++) {
        
        switch (p->numarr[i]) {
            case 1 ... 15:
                printf("L%02d ", p->numarr[i]);
            break ;

            case 16 ... 30:
                printf("I%d ", p->numarr[i]);
            break;
            
            case 31 ... 45:
                printf("N%d ", p->numarr[i]);
            break;
            
            case 46 ... 60:
                printf("U%d ", p->numarr[i]);
            break;
            
            case 61 ... 75:
                printf("X%d ", p->numarr[i]);
            break;
        }
    }
}
