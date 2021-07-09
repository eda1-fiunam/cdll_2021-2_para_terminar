
#include "CDLL.h"

static Node* new_node( int x )
{
   Node* n = (Node*) malloc( sizeof( Node ) );
   if( n != NULL ){
      n->datos = x;
      n->next = NULL;
      n->prev = NULL;
   }

   return n;
}

CDLL* CDLL_New()
{
   CDLL* list = (CDLL*) malloc( sizeof( CDLL ) );
   if( list != NULL ){
      list->first = NULL;
      list->last = NULL;
      list->cursor = NULL;
      list->len = 0;
   }

   return list;
}

void CDLL_Delete( CDLL** this )
{
   assert( *this );

   // 1. Borramos todos los nodos:
   while( (*this)->first != NULL ){
      CDLL_Pop_back( *this );
   }

   // 2. Borramos al objeto DLL:
   free( *this );

   // 3. Evitamos problemas futuros:
   *this = NULL;
}

int CDLL_Front( CDLL* this )
{
   assert( this->first != NULL );
   // ERR: no se puede leer de una lista vacía

   return this->first->datos;
}

int CDLL_Back( CDLL* this )
{
}


void CDLL_Insert( CDLL* this, int item )
{
}

void CDLL_Push_front( CDLL* this, int item )
{
}

void CDLL_Push_back( CDLL* this, int item )
{
}


void CDLL_Pop_front( CDLL* this )
{
}

void CDLL_Pop_back( CDLL* this )
{
}

int CDLL_Get( CDLL* this, Node* pos )
{
}

void CDLL_Cursor_front( CDLL* this )
{
   this->cursor = this->first;
}

void CDLL_Cursor_back( CDLL* this )
{
}

void CDLL_Cursor_next( CDLL* this )
{
}

// es responsabilidad del programador el no llamar a esta función si el cursor es NULL
void CDLL_Cursor_prev( CDLL* this )
{
}

bool CDLL_IsEmpty( CDLL* this )
{
   return this->first == NULL;
}

size_t CDLL_Len( CDLL* this )
{
}

void CDLL_MakeEmpty( CDLL* this )
{
}

// recorre la this y ejecuta la función fn en la parte de datos de cada
// elemento de la misma
void CDLL_Traverse( CDLL* this, void (*fn)( int item ) )
{
}

void CDLL_Remove( CDLL* this, int key )
{
}

Node* CDLL_Erase( CDLL* this, Node* pos )
{
}

void CDLL_Remove_if( CDLL* this, bool (*cmp)( int x, int y ), int key )
{
}

Node* CDLL_Find( CDLL* this, int key )
{

#if 0 

   assert( CDLL_IsEmpty( this ) == false );
   // ERR: no se puede buscar nada en una lista vacía


   // NO funciona con la CDLL:


   Node* it = this->first;
   // |it| es la abreviación de "iterator", o  en español, "iterador"

   while( it != NULL ){

      if( it->datos == key ) break;

      it = it->next;
   }

   return it;
   // ¡un único punto de salida!
#endif  
   return NULL;
}

Node* CDLL_Find_if( CDLL* this, bool (*cmp)( int, int ), int key )
{
}

void CDLL_PrintStructure( CDLL* this )
{
}

