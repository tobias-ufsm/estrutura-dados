struct lista
{
    float info;
    struct lista *prox;
};
typedef struct lista Lista;
/* estrutura da fila */
struct fila
{
    Lista *ini;
    Lista *fim;
};
typedef struct fila Fila;
Fila *fila_cria(void);
void fila_insere(Fila *f, float v);
float fila_retira(Fila *f);