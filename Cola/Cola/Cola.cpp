// Cola.cpp: define el punto de entrada de la aplicación de consola.
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
	stack *proximo = nullptr;
	stack *anterior = nullptr;
};

stack* comprar(stack*,const int&, const string&);
stack* vender(stack*, int&, const int&);

int main(int argc, char* argv[])
{
	int montoTotal = 0;
	int	precio = 0;
	char operacion = 0;
	string mes;
	stack*primera = nullptr;
	stack*ultima = nullptr;

	/*stack *nuevasss = new stack;
	primera = nuevasss;
	ultima = nuevasss;
	*/
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
				if (primera == nullptr)
					primera = ultima;
			
			break;
		case 'v':
		case 'V':
			cout << "Ingrese precio de venta: ";
			cin >> precio;
			primera = vender(primera, montoTotal, precio);
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

stack* comprar(stack* ultima, const int& precio, const string& mes)
{
	stack* nueva = new stack;
	nueva->precioaccion = precio;
	nueva->mes = mes;

	if (ultima != nullptr)
	{
		ultima->anterior = nueva;
		nueva->proximo = ultima;
	}
	return nueva;
}
stack* vender(stack* primera, int& total, const int& precioVenta)
{
	total += precioVenta*CANTACCIONES - (primera->precioaccion)*CANTACCIONES;
	stack* nPrimera;
	if (primera->anterior != nullptr)
	{
		nPrimera = primera->anterior;
		nPrimera->proximo = nullptr;
		
	}
	else
	{
		nPrimera = nullptr;
	}
	
	delete primera;
	return nPrimera;
}