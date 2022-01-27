//decalring list ADT using arrays and length variable
typedef struct list {
    int *numarr;
    int length;
} ADT;

//funciton prototypes
void ADD (int value, ADT *P);
void INITIALIZE(int maxsize, ADT *p);
void PRINT(ADT *p);
int CHECK(int item, ADT *p);
