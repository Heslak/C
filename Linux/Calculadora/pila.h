typedef union {
    char c;
    int  k;
    float f;
    double y;
} INFO;

typedef struct {
    int max;
    int top;
    INFO *p;
} PILA;

PILA *nuevaPila(int n);
int pilaVacia(PILA *pila);
void dump(PILA *pila);
void push(PILA *pila, INFO c);
INFO pop(PILA *pila);
INFO tope(PILA *pila);
