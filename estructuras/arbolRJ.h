//
// Created by vadan on 26/11/2023.
//

#ifndef PROYECTO_FINAL_CIENCIAS_I_ARBOLRJ_H
#define PROYECTO_FINAL_CIENCIAS_I_ARBOLRJ_H

#include <iostream>
#include "cola.h"
#include "Pila.h"

 
template <class T, class C>
struct NodoArbol
{
    C clave;
    T info;
    NodoArbol<T, C> *padre;
    NodoArbol<T, C> *izq;
    NodoArbol<T, C> *der;
    int color;
};

template <class T, class C>
class ArbolRojiNegro
{
private:
    NodoArbol<T, C> *raiz;
    NodoArbol<T, C> *TNULO;

    void inicializarNodoNULL(NodoArbol<T, C> *nodo, NodoArbol<T, C> *padre)
    {
        nodo->clave = NULL;
        nodo->info = NULL;
        nodo->padre = padre;
        nodo->izq = nullptr;
        nodo->der = nullptr;
        nodo->color = 0;
    }

    NodoArbol<T, C> *buscar(NodoArbol<T, C> *nodo, C llave)
    {
        if (nodo == TNULO || llave == nodo->clave)
        {
            return nodo;
        }

        if (llave < nodo->clave)
        {
            return buscar(nodo->izq, llave);
        }
        return buscar(nodo->der, llave);
    }

    // Ajusta el arbol tars eliminar un nodo
    void ajusteEliminar(NodoArbol<T, C> *x)
    {
        NodoArbol<T, C> *h;
        while (x != raiz && x->color == 0)
        {

            // X es el hijo de la izquierda
            if (x == x->padre->izq)
            {
                h = x->padre->der;

                // Caso 1
                if (h->color == 1)
                {
                    h->color = 0;
                    x->padre->color = 1;
                    rotarIzq(x->padre);
                    h = x->padre->der;
                }

                // Caso 2
                if (h->izq->color == 0 && h->der->color == 0)
                {
                    h->color = 1;
                    x = x->padre;
                }

                else
                {
                    // Caso 3
                    if (h->der->color == 0)
                    {
                        h->izq->color = 0;
                        h->color = 1;
                        rotarDer(h);
                        h = x->padre->der;
                    }

                    // Caso 4
                    h->color = x->padre->color;
                    x->padre->color = 0;
                    h->der->color = 0;
                    rotarIzq(x->padre);
                    x = raiz;
                }
            }

                // x es el hijo de la derecha
            else
            {
                h = x->padre->izq;

                // Caso 1
                if (h->color == 1)
                {
                    h->color = 0;
                    x->padre->color = 1;
                    rotarDer(x->padre);
                    h = x->padre->izq;
                }

                // Caso 2
                if (h->der->color == 0 && h->der->color == 0)
                {
                    h->color = 1;
                    x = x->padre;
                }

                else
                {
                    // Caso 3
                    if (h->izq->color == 0)
                    {
                        h->der->color = 0;
                        h->color = 1;
                        rotarIzq(h);
                        h = x->padre->izq;
                    }

                    // Caso 4
                    h->color = x->padre->color;
                    x->padre->color = 0;
                    h->izq->color = 0;
                    rotarDer(x->padre);
                    x = raiz;
                }
            }
        }
        x->color = 0;
    }

    void transplantar(NodoArbol<T, C> *u, NodoArbol<T, C> *v)
    {
        if (u->padre == nullptr)
        {
            raiz = v;
        }
        else if (u == u->padre->izq)
        {
            u->padre->izq = v;
        }
        else
        {
            u->padre->der = v;
        }
        v->padre = u->padre;
    }

    void eliminarNodo(NodoArbol<T, C> *nodo, C llave)
    {
        NodoArbol<T, C> *z = TNULO;
        NodoArbol<T, C> *x, *y;
        while (nodo != TNULO)
        {
            if (nodo->clave == llave)
            {
                z = nodo;
            }

            if (nodo->clave <= llave)
            {
                nodo = nodo->der;
            }
            else
            {
                nodo = nodo->izq;
            }
        }

        if (z == TNULO)
        {
            std::cout << "Llave no encontrada en el árbol" << std::endl;
            return;
        }

        y = z;
        int color_original_y = y->color;

        // z tiene un solo hijo o ninguno
        if (z->izq == TNULO)
        {
            x = z->der;
            transplantar(z, z->der);
        }
        else if (z->der == TNULO)
        {
            x = z->izq;
            transplantar(z, z->izq);
        }

            // z tiene dos hijos
        else
        {
            // El menor de sus decendientes mayores lo remplaza, obtiene su color.
            y = minimo(z->der);
            color_original_y = y->color;
            x = y->der;
            if (y->padre == z)
            {
                x->padre = y;
            }
            else
            {
                transplantar(y, y->der);
                y->der = z->der;
                y->der->padre = y;
            }

            transplantar(z, y);
            y->izq = z->izq;
            y->izq->padre = y;
            y->color = z->color;
        }

        delete z;
        if (color_original_y == 0)
        {
            ajusteEliminar(x);
        }
    }

    // Ajustar el árbol después de una inserción
    void ajusteInsercion(NodoArbol<T, C> *k)
    {
        NodoArbol<T, C> *u;
        while (k->padre->color == 1)
        {

            // Padre es el hijo de la derecha del abuelo
            if (k->padre == k->padre->padre->der)
            {
                u = k->padre->padre->izq; // u es el tío de k
                // Caso 1
                if (u->color == 1)
                {
                    u->color = 0;
                    k->padre->color = 0;
                    k->padre->padre->color = 1;
                    k = k->padre->padre;
                }
                else
                {
                    // Caso 2
                    if (k == k->padre->izq)
                    {
                        k = k->padre;
                        rotarDer(k);
                    }
                    // Caso 3
                    k->padre->color = 0;
                    k->padre->padre->color = 1;
                    rotarIzq(k->padre->padre);
                }
            }
                // Simétrico, padre es el hijo de la izquierda del abuelo
            else
            {
                u = k->padre->padre->der;
                // Caso 1
                if (u->color == 1)
                {
                    u->color = 0;
                    k->padre->color = 0;
                    k->padre->padre->color = 1;
                    k = k->padre->padre;
                }
                else
                {
                    // Caso 2
                    if (k == k->padre->der)
                    {
                        k = k->padre;
                        rotarIzq(k);
                    }

                    // Caso 3
                    k->padre->color = 0;
                    k->padre->padre->color = 1;
                    rotarDer(k->padre->padre);
                }
            }
            if (k == raiz)
            {
                break;
            }
        }
        // La raíz siempre es negra
        raiz->color = 0;
    }

    void imprimir(NodoArbol<T, C> *raiz, std::string indentacion, bool ultimo)
    {
        if (raiz != TNULO)
        {
            std::cout << indentacion;
            if (ultimo)
            {
                std::cout << "Der----";
                indentacion += "   ";
            }
            else
            {
                std::cout << "Izq----";
                indentacion += "|  ";
            }

            std::string sColor = raiz->color ? "ROJO" : "NEGRO";
            std::cout << raiz->info << "(" << sColor << ")" << std::endl;
            imprimir(raiz->izq, indentacion, false);
            imprimir(raiz->der, indentacion, true);
        }
    }

public:
    ArbolRojiNegro()
    {
        TNULO = new NodoArbol<T, C>;
        TNULO->color = 0;
        TNULO->izq = nullptr;
        TNULO->der = nullptr;
        raiz = TNULO;
    }

    Cola<NodoArbol<T, C> *> obtenerPreOrden(NodoArbol<T, C> *nodo)
    {
        Cola<NodoArbol<T, C> *> retorno;
        Pila<NodoArbol<T, C> *> antepasados;

        while (!antepasados.vacia() || nodo != TNULO)
        {
            if (nodo != TNULO)
            {
                retorno.enqueue(nodo);
                if (nodo->der != TNULO)
                {
                    antepasados.meter(nodo->der);
                }
                nodo = nodo->izq;
            }
            else
            {
                nodo = antepasados.sacar();
            }
        }
        return retorno;
    }

    Cola<NodoArbol<T, C> *> obtenerInOrden(NodoArbol<T, C> *nodo)
    {
        Cola<NodoArbol<T, C> *> retorno;
        Pila<NodoArbol<T, C> *> antepasados;
        while (nodo != TNULO || !antepasados.vacia())
        {
            while (nodo != TNULO)
            {
                antepasados.meter(nodo);
                nodo = nodo->izq;
            }
            nodo = antepasados.sacar();
            retorno.enqueue(nodo);
            nodo = nodo->der;
        }

        return retorno;
    }

    Cola<NodoArbol<T, C> *> obtenerNiveles(NodoArbol<T, C> *nodo)
    {
        Cola<NodoArbol<T, C> *> retorno;
        Cola<NodoArbol<T, C> *> antepasados;

        NodoArbol<T, C> *aux = nodo;

        antepasados.enqueue(aux);

        while (!antepasados.isVacia())
        {
            aux = antepasados.dequeue();
            retorno.enqueue(aux);
            if (aux->izq != TNULO)
            {
                antepasados.enqueue(aux->izq);
            }
            if (aux->der != TNULO)
            {
                antepasados.enqueue(aux->der);
            }
        }

        return retorno;
    }

    Cola<NodoArbol<T, C> *> obtenerPostOrden(NodoArbol<T, C> *nodo)
    {
        Cola<NodoArbol<T, C> *> retorno;
        Pila<NodoArbol<T, C> *> antepasados;
        NodoArbol<T, C> *aux, *ultimo;

        while (!antepasados.vacia() || nodo != TNULO)
        {
            while (nodo != TNULO)
            {
                antepasados.meter(nodo);
                nodo = nodo->izq;
            }
            if (!antepasados.vacia())
            {
                aux = antepasados.sacar();
                if (aux->der == TNULO || ultimo == aux->der)
                {
                    retorno.enqueue(aux);
                    ultimo = aux;
                }
                else
                {
                    antepasados.meter(aux);
                    nodo = aux->der;
                }
            }
        }

        return retorno;
    }

    NodoArbol<T, C> *buscar(C llave)
    {
        return buscar(this->raiz, llave);
    }

    NodoArbol<T, C> *minimo(NodoArbol<T, C> *nodo)
    {
        while (nodo->izq != TNULO)
        {
            nodo = nodo->izq;
        }
        return nodo;
    }

    NodoArbol<T, C> *maximo(NodoArbol<T, C> *nodo)
    {
        while (nodo->der != TNULO)
        {
            nodo = nodo->der;
        }
        return nodo;
    }

    void rotarIzq(NodoArbol<T, C> *x)
    {
        NodoArbol<T, C> *y = x->der;
        x->der = y->izq;
        if (y->izq != TNULO)
        {
            y->izq->padre = x;
        }
        y->padre = x->padre;
        if (x->padre == nullptr)
        {
            this->raiz = y;
        }
        else if (x == x->padre->izq)
        {
            x->padre->izq = y;
        }
        else
        {
            x->padre->der = y;
        }
        y->izq = x;
        x->padre = y;
    }

    void rotarDer(NodoArbol<T, C> *x)
    {
        NodoArbol<T, C> *y = x->izq;
        x->izq = y->der;
        if (y->der != TNULO)
        {
            y->der->padre = x;
        }
        y->padre = x->padre;
        if (x->padre == nullptr)
        {
            this->raiz = y;
        }
        else if (x == x->padre->der)
        {
            x->padre->der = y;
        }
        else
        {
            x->padre->izq = y;
        }
        y->der = x;
        x->padre = y;
    }

    void insertarNodo(C llave, T info)
    {
        NodoArbol<T, C> *nodo = new NodoArbol<T, C>;
        nodo->padre = nullptr;
        nodo->clave = llave;
        nodo->info = info;
        nodo->izq = TNULO;
        nodo->der = TNULO;
        nodo->color = 1;

        NodoArbol<T, C> *y = nullptr;
        NodoArbol<T, C> *x = this->raiz;

        while (x != TNULO)
        {
            y = x;
            if (nodo->clave < x->clave)
            {
                x = x->izq;
            }
            else
            {
                x = x->der;
            }
        }

        nodo->padre = y;
        if (y == nullptr)
        {
            raiz = nodo;
        }
        else if (nodo->clave < y->clave)
        {
            y->izq = nodo;
        }
        else
        {
            y->der = nodo;
        }

        if (nodo->padre == nullptr)
        {
            nodo->color = 0;
            return;
        }

        if (nodo->padre->padre == nullptr)
        {
            return;
        }

        ajusteInsercion(nodo);
    }

    NodoArbol<T, C> *obtenerRaiz()
    {
        return this->raiz;
    }

    void eliminarNodo(T dato)
    {
        eliminarNodo(this->raiz, dato);
    }

    void imprimir()
    {
        if (raiz)
        {
            imprimir(this->raiz, "", true);
        }
    }
};

#endif //PROYECTO_FINAL_CIENCIAS_I_ARBOLRJ_H
