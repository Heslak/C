typedef struct {
    int max;
    int top;
    char *p;
} PILA;

PILA *nuevaPila(int n);
int pilaVacia(PILA *pila);
void dump(PILA *pila);
void push(PILA *pila, char c);
char pop(PILA *pila);
char tope(PILA *pila);
