#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    	this=(LinkedList*)malloc(sizeof(LinkedList));//creo espacio en memoria

    	if(this!=NULL){//valido que no este vacio

    		this->size=0;//inicializo la lista en 0
    		this->pFirstNode=NULL;//inicializo en vacio el puntero al proximo nodo (quiere decir que no hay mas nodos)
    	}

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){//veo que la lista no esta vacia
    	returnAux=this->size;//cargo en la variable de retorno el tamanio de la lista
    }
    return returnAux;//retorno el tamanio de la lista
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node*AuxNode=NULL; //creo un puntero a node y lo igualo a null porque en caso de error devuelve null
	int largo;//creo el largo para sacar el largo de la lista

	largo=ll_len(this);//saco el largo

	//valido que este todo bien
	//nodeIndex porque es el indice al nodo y verifico que no sea mas chico que el largo de la lista
	if(this!=NULL && nodeIndex >=0 && largo>nodeIndex){


		AuxNode=this->pFirstNode;//pongo en el nodo aux el gancho al nodo

		//busco el nodo que vino por parametro
		for(int i=0;i<nodeIndex;i++){

			//guerdo el nodo en el aux
			AuxNode=AuxNode->pNextNode;
		}


	}
    return AuxNode;//si sale todo bien devuelve el nodo , sino devuelve null
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node*auxNodo;
    Node*nodoAnterior;

    //el nodo que quiero agregar tiene que ser mayor a 0 y menor al size , que es el total de los nodos
    if(this!=NULL && nodeIndex >=0 && nodeIndex <= this->size){
    	//creo un espacio en memoria del nodo
    	auxNodo=(Node*)malloc(sizeof(Node));
    	//valido
    	if(auxNodo!=NULL){
    		auxNodo->pElement=pElement;//me guardo el nuevo elemento en el nodo

    		if(nodeIndex==0){//esto quiere decir que va al primer nodo , si no es en el primer lugar va a ir entre medio

    			auxNodo->pNextNode=this->pFirstNode; //lo que hice es si tengo un nuevo nodo es transformar a la cabeza en el nuevo nodo
    			this->pFirstNode=auxNodo;//y en este es unir la cabeza al nuevo nodo
    			this->size++;
    			returnAux = 0;
    		}else{
    			nodoAnterior=getNode(this, nodeIndex-1);//con esto obtengo el nodo anterior , le paso la lista y la ubicacion del nodo y le resto 1 para que sea el anterior
    			auxNodo->pNextNode=nodoAnterior->pNextNode;
    			/*
    			 *	lo que hice  fue agarra el puntero del nuevo nodo de memoria y transformarlo en el puntero del anteror nodo
    			 *	(el puntero del anterior nodo tiene guardado la direccion del siguiente)
    			 * (porque el nuevo antes no existia)
    			 */
    			nodoAnterior->pNextNode=auxNodo;//y aca es unir al nodo anterior al nuevo nodo (al nodo que se creo en memoria // queria como entre medio de los 2 nodos (el anterior y el siguiente))
    			this->size++;
    			returnAux = 0;
    		}

    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    //verifico
    if(this!=NULL){//no valido el pElement porque puede que no tenga nada , un tren pruede venir con vagones vacios

    	//la funcion addNode carga un nuevo nodo a la lista
    	//le paso la lista , posicion seria al final , y el elemento(serian los datos)
    	//serie el size porque este es la cantidad de nodos que hay y le paso la ultima posicion
    	if(addNode(this,this->size,pElement)==0){

    		returnAux=0;//retorno 0 porque lo pide la funcion
    	}

    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)//retorna el elemento
{
    void* returnAux = NULL;

    //valido
    if(this!=NULL && index <= this->size){
    	//creo un nodo aux donde guardo el nodo que quiero obtener
    	Node* aux= getNode(this, index);
    	//valido que ese nodo tenga algo
    	if(aux!=NULL){

    		//retorno los elementos de ese nodo
    		returnAux = aux->pElement;
    	}

    }


    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node *aux;

    if(this!=NULL && index<this->size){
    	//traigo el nodo que quiero modificar
    	aux=getNode(this, index);
    	//veo si ese nodo tiene algo
    	if(aux!=NULL){
    		//llamo al los elementos del puntero que antes busque y los cmabio por los nuevos elementos que hay en parametros
    		aux->pElement=pElement;
    		//retorno 0 si esta bien
    		returnAux=0;
    	}
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node *aux;
    Node*nodoAnterior;
    if(this!=NULL && index < this->size && index >=0){

    	aux=getNode(this, index);
    	if(index==0){

    		aux=this->pFirstNode;//trasformo al nodo que quiero borrar en el gancho al otro nodo(como la cabeza)
    		this->pFirstNode=aux->pNextNode;//agarro el gancho y lo igualo al puntero del nodo que quiero borrar (porque en ese nodo esta la direccion de el proximo nodo y si lo igualo es como si uniera la cabeza con el nodo)
    		free(aux);//borro el nodo que no quiero
    		this->size--;
    		returnAux = 0;
    	}else{

    		nodoAnterior=getNode(this, index-1);//saco el nodo anterior
    		nodoAnterior->pNextNode = aux->pNextNode;//agarro el nodo que quiero borrar y lo igualo al puntero del anterior (que guarda la direccion del siguiente )(con esto uno el anterior con el siguiente y me olvido del nodo que quiero borrar)
    		free(aux);//borro el nodo a borrar
    		this->size--;
    		returnAux = 0;
    	}

    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL){


    	for(int i=0;i<this->size;i++){

    		 ll_remove(this,i);

    	}
    	returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL){

    	free(this);//le hago free a todo y chau todo
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL){//valido
    	//recorro toda la lista
    	for(int i=0;i<this->size;i++){
    		//busco con la funcion llget (justo me devuelve el elemento) y lo igualo al elemento que ve vino por parametro
    		if(ll_get(this, i)==pElement){
    			//retorno el indice
    			returnAux = i;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int largo;
    if(this!=NULL){

    	largo=ll_len(this);

    	if(largo == 0){
    		returnAux = 1;
    	}else{
    		returnAux = 0;
    	}

    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
	 int returnAux = -1;
	    //verifico
	    if(this!=NULL && index >= 0 && index <= this->size){//no valido el pElement porque puede que no tenga nada , un tren pruede venir con vagones vacios

	    	//la funcion addNode carga un nuevo nodo a la lista
	    	//le paso la lista , posicion seria index esto se lo pregunto al usuario , y el elemento(serian los datos)
	    	if(addNode(this, index, pElement)==0){

	    		returnAux=0;//retorno 0 porque lo pide la funcion
	    	}

	    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this!=NULL && index >=0 && index<this->size){

    	returnAux=ll_get(this, index);

    	if(returnAux != NULL){

    		ll_remove(this, index);
    	}
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL){

    	if(ll_indexOf(this, pElement) != -1){
    		returnAux = 1;

    	}else{
    		returnAux = 0;

    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* pElement;

    if(this!=NULL && this2 !=NULL){

    	if(ll_len(this2)==0){

    		returnAux = 0;
    	}

    	for(int i=0; i<this2->size ; i++){

    		pElement=ll_get(this2, i);

    		if(ll_contains(this, pElement)==1){

    			returnAux = 1;
    		}else{
    		    returnAux = 0;
    		    break;
    		}

    	}

    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void*pElemento;

    if(this!=NULL && from >= 0 && to >= from && to <= this->size){
    	//creo una nueva lista
    	cloneArray=ll_newLinkedList();
    	//recorro la indice de la lista hasta el final de la misma indicada en los parametros (te mandan el inicio y el final de la lista por parametro)
    	for(int i=from;i<to;i++){

    		//guardo el elemento de la lista que vino por parametro
    		pElemento=ll_get(this, i);
    		//lo guerdo en la nueva lista
    		ll_add(cloneArray, pElemento);


    	}

    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    void*pElemento;

    if(this!=NULL && this->size > 0 ){

    	cloneArray=ll_newLinkedList();//creo una nueva lista

    	//recorro la lista principal (la que viene por parametro)
    	for(int i=0;i<this->size;i++){
    		//cargo el elemento	de la lista anterior
    		pElemento=ll_get(this, i);
    		//uno el elemento a la lista nueva
    		ll_add(cloneArray, pElemento);

    	}
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void*pElemento1;//elementos que  estan guardados en la funcion
    void*pElemento2;//elementos que  estan guardados en la funcion

    if(this != NULL && pFunc != NULL && (order ==1 || order == 0)){

    	//recorro cada lugar de la lista
    	for(int i=0 ;i<this->size -1 ;i++){

    		for(int j = i+1 ;j<this->size;j++){

    			//guardo en los pElementos los elementos de la lista
    			pElemento1=ll_get(this, i);
    			pElemento2=ll_get(this, j);

    			//si el orden es == 1 (ascendente)
    			if(order==1){
    				//dependiendo de que devuelva la funcion (0 iguales)(1 cuando p1 es mayor a p2)(-1 cuando p1 es menor a p2)
    				if((*pFunc)(pElemento1 ,pElemento2) > 0){

    					//modifica la lista(se pisan los elementos dependiendo cual es mayor o menor)
    					ll_set(this, j, pElemento1);
    					ll_set(this, i, pElemento2);
    				}

    			}else{

    				//dependiendo de que devuelva la funcion (0 iguales)(1 cuando p1 es mayor a p2)(-1 cuando p1 es menor a p2)
    				if((*pFunc)(pElemento1 ,pElemento2) < 0){

    					//modifica la lista(se pisan los elementos dependiendo cual es mayor o menor)
    					ll_set(this, j, pElemento1);
    					ll_set(this, i, pElemento2);
    				}
    			}
    		}
    	}

    	returnAux = 0;
    }

    return returnAux;

}

