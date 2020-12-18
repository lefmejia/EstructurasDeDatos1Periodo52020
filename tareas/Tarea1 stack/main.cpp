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

    std::cout<<"Resultado: "<< resultado << std::endl;
    return 0;
}