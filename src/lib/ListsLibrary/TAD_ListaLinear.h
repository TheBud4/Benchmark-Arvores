#ifndef LISTA_TAD_H
#define LISTA_TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
typedef struct noh  Noh;
typedef Noh*        pNoh;

/* descritor da lista */
typedef struct dLista  DLista;
typedef DLista*        pDLista;

/* 3 tipos que representam ponteiros para funcao */
typedef int   (*FuncaoComparacao)(void *, void *);
typedef void  (*FuncaoImpressao) (void *);
typedef void* (*FuncaoAlocacao)  (void *);
typedef void  (*FuncaoLiberacao)  (void *);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDLista  CreateList       ();

void     IncludeInfo      (pDLista, void *);
void     IncludeInfoFirst(pDLista, void *);
void     IncludeInfoMiddle(pDLista, void *, int);

int      ExcludeInfo      (pDLista, void *, FuncaoComparacao);
//int      excluirInfoEx3   (pDLista, void *, FuncaoComparacao, FuncaoLiberacao);

int      ContainInfo       (pDLista, void *, FuncaoComparacao);
void     PrintList    (pDLista, FuncaoImpressao);

void     DestructList        (pDLista);
void     DestructNormalList  (pDLista);
void     DestructListInfo    (pDLista, FuncaoLiberacao);

void    ReverseList (pDLista);

pDLista  DuplicateList    (pDLista, FuncaoAlocacao);

/* o parametro int estabelece a posicao da lista onde a divisao deve acontecer */
pDLista  DivideList     (pDLista, int);

pDLista  JoinLists     (pDLista, pDLista, FuncaoComparacao);

void*    SearchNohInfo    (pDLista, void*, FuncaoComparacao);
void*    SearchInfoPos    (pDLista, int);

#endif

