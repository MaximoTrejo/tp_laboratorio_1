/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif


//Publicas
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
//------------------------------------------------------------------------------
//crea la lista en memoria
LinkedList* ll_newLinkedList(void);
//saca el largo de la lista
int ll_len(LinkedList* this);
//agrega
int ll_add(LinkedList* this, void* pElement);
//trae un pasajero , retorna un pasajero
void* ll_get(LinkedList* this, int index);
//modifica
int ll_set(LinkedList* this, int index,void* pElement);
//borra un elemento
int ll_remove(LinkedList* this,int index);
//limpio la lista
int ll_clear(LinkedList* this);
//borra de memoria la lista
int ll_deleteLinkedList(LinkedList* this);
//devueve el indice especifico , en que posicion esta
int ll_indexOf(LinkedList* this, void* pElement);
//me dice si la lista esta vacia
int ll_isEmpty(LinkedList* this);
//abre lugar , mete en el medio dependiendo del indice
int ll_push(LinkedList* this, int index, void* pElement);
//parecido al remove, devuelve el elemento , lo saca de la lista pero lo devuelve
void* ll_pop(LinkedList* this,int index);
//si un elemento especifico esta contenido en la lista
int ll_contains(LinkedList* this, void* pElement);
//puedo mover un elemento especifico en otra lista
int ll_containsAll(LinkedList* this,LinkedList* this2);
//devuelve de la lista un pedacito
LinkedList* ll_subList(LinkedList* this,int from,int to);
//copia de una lista
LinkedList* ll_clone(LinkedList* this);
//ordena la lista
//el primer parametro es el puntero linkedlist
//el segundo es un puntero a funcion
//y el ultimo es el orden 0 (z a) 1(a z)
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order); //orden 0 (z a) 1(a z)
