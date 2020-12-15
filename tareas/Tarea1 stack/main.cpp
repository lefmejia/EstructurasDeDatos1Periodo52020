#include <iostream>
#include <bits/stdc++.h>


int main()
{
    std::stack<int> pila;
    std::string operacion;
    std::string numeros = "";
    int resultado=0;
    std::cout<< "Ingrese operacion en forma de postorder: \n\n";
    std::cin>>operacion;

    for(auto n: operacion)
    {
         switch(n)
        {
            case '+':
                resultado=pila.top();
                pila.pop();
                resultado+=pila.top();
                pila.pop();
                pila.push(resultado);
                break;
            case '-':
                resultado-=pila.top();
                pila.pop();
                resultado+=pila.top();
                pila.pop();
                pila.push(resultado);
                break;
            case '*':
                resultado=pila.top();
                pila.pop();
                resultado*=pila.top();
                pila.pop();
                pila.push(resultado);
                break;
            case '/':
                resultado=pila.top();
                pila.pop();
                resultado=pila.top()/resultado;
                pila.pop();
                pila.push(resultado);
                break;
            default:
                pila.push(n-'0');
        }
    }
/*
    for(int i = operacion.length()-1; i>=0; i--)
    {
        pila.push(operacion[i]);
    }

    resultado+= pila.top() - '0';
    pila.pop();

    while(!pila.empty())
    {
        switch(pila.top())
        {
            case '+':
                for(auto x: numeros)
                {
                    resultado+= x - '0';
                }
                numeros = "";
                pila.pop();
                break;
            case '-':
                for(auto x: numeros)
                {
                    resultado-= x - '0';
                }
                numeros = "";
                pila.pop();
                break;
            case '*':
                for(auto x: numeros)
                {
                    resultado*= x - '0';
                }
                numeros = "";
                pila.pop();
                break;
            case '/':
                for(auto x: numeros)
                {
                    resultado/= x - '0';
                }
                numeros = "";
                pila.pop();
                break;

        }
        if(pila.empty())
        break;

        numeros+=pila.top();
        pila.pop();
    }
*/
    std::cout<<"Resultado: "<< resultado << std::endl;
    return 0;
}