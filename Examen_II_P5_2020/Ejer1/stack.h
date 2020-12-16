#ifndef _STACK_H
#define _STACK_H

/* Implement a stack using an array of fixed size.
 * The size of the stack should be defined in the
 * class constructor.
 * 
 * The implementation should throw an exception on error.
 * The posible errors are stack overflow and underflow
 **/
template<typename TElem>
class Stack
{
public:
    int size;
    int quantity;
    TElem *stack;
    Stack(int _size)
    :size(_size)
    {
        stack = new TElem[size];
        quantity = 0;
    }

    void push(TElem elem)
    {
        if(quantity>=size)
        {
            throw "Stack overflow";
            return;
        }

        for(int i = 0; i<size; i++)
        {
            TElem temp = stack[size-1-i];
            stack[size-1-i] = stack[size-2-i];
        }
        stack[0] = elem;
        quantity++;
    }

    TElem pop()
    {
        if(quantity==0)
        {
            throw "Stack underflow";
        }
        TElem elem = stack[0];
        TElem *nuevo = new TElem[size];
        for(int i=0; i<size-1; i++)
        {
            nuevo[i] = stack[i+1];
        }

        delete []stack;

        stack =  new TElem[size];
        stack = nuevo;

        quantity--;

        return elem;
    }
};

#endif
