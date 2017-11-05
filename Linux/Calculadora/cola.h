typedef struct estructuraNodo NODO;

struct estructuraNodo {
    char info;
    NODO *sig;
};

typedef struct {
    NODO *h;
    NODO *t;
} COLA;


typedef  void (*ITERADOR_COLA)(NODO *nodo);

COLA *nuevaCola();
NODO *nuevoNodo();
int colaEstaVacia(COLA *cola);
void colaAgregar(COLA *cola,NODO *nodo);
NODO *colaRetirar(COLA *cola);
void colaIterar(COLA *cola, ITERADOR_COLA miFuncion);
void presentaInfoNODO(NODO *n);

