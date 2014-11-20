// pila.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <array>
#include <string>
#include <ciso646>
#define CANTACCIONES 100

using namespace std;

struct stack
{
	int precioaccion = 0;
	string mes;
	stack *anterior;
};                                   

stack* comprar(stack*, int, string);
stack* vender (stack*, int&, int);

int main(int argc, char* argv[])
{
	int montoTotal = 0;
	int	precio = 0;
	char operacion = 0;
	string mes;
	stack* ultima = nullptr;

	cout << "Ingrese operacion: ";
	cin >> operacion;
	
	while (operacion != '0')
	{
		switch (operacion)
		{
			case 'c':
			case 'C':
					cout << "Ingrese precio de compra "; 
					cin >> precio;
					cout << "Ingrese mes: ";
					cin >> mes;
					ultima = comprar(ultima, precio, mes); 
					break;
			case 'v':
			case 'V':
					cout << "Ingrese precio de venta: ";
					cin >> precio;
					ultima = vender(ultima, montoTotal, precio);
					break;
			default:
				   cout << "Opción incorrecta" << endl; 
				   break;
		}

		
		cout << "Ingrese operacion: ";
		cin >> operacion;
	}


	if (montoTotal >= 0)
	{
		cout << "Usted a ganado: " << montoTotal << endl;
	}
	else
	{
		cout << "Usted a perdido: " << montoTotal*(-1) << endl;
	}
	
	return 0;
}

stack* comprar(stack* ultima, int precio, string mes)
{
	stack* nueva = new stack;
	nueva->precioaccion = precio;
	nueva->mes = mes;
	nueva->anterior = ultima;
	return nueva;
}
stack* vender(stack* ultima, int& total, int precioVenta)
{
	stack* ultimo = ultima ->anterior;
	total += precioVenta*CANTACCIONES - (ultima->precioaccion*CANTACCIONES) ;
	delete ultima;
	return ultimo;
}
