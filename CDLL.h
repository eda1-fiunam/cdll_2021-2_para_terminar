
#ifndef  CDLL_INC
#define  CDLL_INC

#include <stdlib.h>
// para malloc and friends y size_t

#include <stdbool.h>
// para bool and friends

#include <assert.h>
// para las aserciones: assert()

#include <stdio.h>
// para fprintf()


typedef struct Node
{
	int datos;

	struct Node* next;
	struct Node* prev;
} Node;

typedef struct
{
	Node* first;
	Node* last;
	Node* cursor;
	size_t len;
} CDLL;


/**
 * @brief Crea una lista doblemente enlazada
 *
 * @return Una referencia a la nueva lista
 * @post Una lista existente en el heap
 */
CDLL* CDLL_New();

/**
 * @brief Destruye una lista.
 *
 * @param this Una lista.
 */
void CDLL_Delete( CDLL** this );

/**
 * @brief Inserta un elemento en el frente de la lista.
 *
 * @param this Una lista.
 * @param item El elemento a insertar
 */
void CDLL_Push_front( CDLL* this, int item );

/**
 * @brief Inserta un elemento en el fondo de la lista.
 *
 * @param this Una lista.
 * @param item El elemento a insertar
 */
void CDLL_Push_back( CDLL* this, int item );

/**
 * @brief Inserta un elemento a la derecha del cursor.
 *
 * @param lista Una referencia a la lista de trabajo
 * @param item El elemento a insertar
 *
 * @return true si el valor se insertó en la lista; false en caso
 * contrario. Esto podría suceder si la memoria se agotó.
 */
void CDLL_Insert( CDLL* this, int item );

/**
 * @brief Elimina el elemento al frente de la lista.
 *
 * @param this Referencia a una lista.
 *
 * @post El cursor se mantiene en la posición en la que estaba cuando entró la
 * función.
 */
void CDLL_Pop_front( CDLL* this );

/**
 * @brief Elimina el elemento al fondo de la lista.
 *
 * @param this Referencia a una lista.
 *
 * @post El cursor se mantiene en la posición en la que estaba cuando entró la
 * función.
 */
void CDLL_Pop_back( CDLL* this );

/**
 * @brief Elimina el primer nodo que coincida con la llave.
 *
 * @param this Referencia a una lista.
 * @param key  Valor buscado
 *
 */
void CDLL_Remove( CDLL* this, int key );

/**
 * @brief Elimina un elemento.
 *
 * @param this Una lista.
 * @param pos Una posición válida. Éste se puede obtener de las diferentes funciones de movimiento del cursor y de las funciones de búsqueda.
 *
 * @return Una referencia al elemento a la derecha del elemento que se acaba de borrar.
 */
Node* CDLL_Erase( CDLL* this, Node* pos );

/**
 * @brief Elimina todos los elementos que den positivo a la función predicado.
 *
 * @param this Una lista.
 * @param cmp Función predicado. El elemento |y| es proporcionado por el argumento |key|, mientras que el valor |x| se obtiene de la lista. Por ejemplo, si la función quiere saber si el valor de la lista es menor que el valor del usuario (list_val < user_val), entonces la función podría ser: less_than( list_val, user_val), la cual se lee en conjunto: "Si el valor de la lista |list_val| es menor que el valor del usuario |user_val|, devuelve verdadero".
 * @param key El valor contra el que se está comparando.
 */
void CDLL_Remove_if( CDLL* this, bool (*cmp)( int x, int y ), int key );

/**
 * @brief Devuelve una copia del valor apuntado por el cursor.
 *
 * @param this Una lista.
 * @param pos Una posición válida. Éste se puede obtener de las diferentes funciones de movimiento del cursor y de las funciones de búsqueda.
 *
 * @return El valor apuntado por pos
 *
 * @post No altera al cursor.
 */
int CDLL_Get( CDLL* this, Node* pos );


/**
 * @brief Manda al cursor al inicio de la lista
 *
 * @param lista Una referencia a la lista de trabajo
 */
void CDLL_Cursor_front( CDLL* this );

void CDLL_Cursor_back( CDLL* this );

void CDLL_Cursor_next( CDLL* this );

void CDLL_Cursor_prev( CDLL* this );


bool CDLL_IsEmpty( CDLL* this );

size_t CDLL_Len( CDLL* this );

/**
 * @brief Elimina todos los elementos de la lista sin eliminar la lista.
 *
 * @param this Referencia a una lista.
 */
void CDLL_MakeEmpty( CDLL* this );

/**
 * @brief Recorre la lista y hace algo en cada uno de sus elementos
 *
 * @param lista Una referencia a la lista de trabajo
 * @param fn Esta función hace algo con el campo de datos 
 */
void CDLL_Traverse( CDLL* this, void (*fn)( int item ) );

/**
 * @brief Devuelve una copia del elemento en el frente de la lista.
 *
 * @param this Una lista.
 *
 * @return La copia del elemento en el frente de la lista.
 *
 * @post Si la lista está vacía se dispara una aserción.
 */
int CDLL_Front( CDLL* this );

/**
 * @brief Devuelve una copia del elemento en la parte trasera de la lista.
 *
 * @param this Una lista.
 *
 * @return La copia del elemento en la parte trasera de la lista.
 *
 * @post Si la lista está vacía se dispara una aserción.
 */
int CDLL_Back( CDLL* this );

/**
 * @brief Busca un valor en la lista.
 *
 * @param this Una lista.
 * @param key El valor que se está buscando.
 *
 * @return Un apuntador al nodo donde se haya encontrado la primer coincidencia. Devuelve NULL en caso de no haber encontrado ninguna.
 */
Node* CDLL_Find( CDLL* this, int key );

/**
 * @brief Busca si algún valor en la lista cumple con la función predicado.
 *
 * @param this Una lista.
 * @param p_fn Función predicado. El elemento |y| es proporcionado por el argumento |key|, mientras que el valor |x| se obtiene de la lista. Por ejemplo, si la función quiere saber si el valor de la lista es menor que el valor del usuario (list_val < user_val), entonces la función podría ser: less_than( list_val, user_val), la cual se lee en conjunto: "Si el valor de la lista |list_val| es menor que el valor del usuario |user_val|, devuelve verdadero".
 * @param key El valor contra el que se está realizando la comparación.
 *
 * @return Un apuntador al nodo donde se haya encontrado la primer coincidencia. Devuelve NULL en caso de no haber encontrado ninguna.
 */
Node* CDLL_Find_if( CDLL* this, bool (*p_fn)( int, int ), int key );


/**
 * @brief Imprime la estructura de la lista. Es para uso de depuración, no de uso general.
 *
 * @param this Una lista.
 */
void CDLL_PrintStructure( CDLL* this );


#endif   /* ----- #ifndef CDLL_INC  ----- */
