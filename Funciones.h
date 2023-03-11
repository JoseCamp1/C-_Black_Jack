#include "Estructuras.h"
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <iomanip>


void creacionBaraja(cartas& naipe, vector<cartas>& losNaipes)//esta funcion crea las cartas y las ingresa en el vector
{

	int cont_C = 1, cont_D = 1, cont_T = 1, cont_P = 1;

	cout << "\nLA BARAJA FUE CREADA!!!\n";
	system("pause");

	for (int i = 0; i <= 12; i++)
	{
		naipe.numero = cont_C;		
		naipe.palo = "\3";
		losNaipes.insert(losNaipes.begin() + i, naipe);
		cont_C++;
	}
	for (int i = 13; i <= 25; i++)
	{
		naipe.numero = cont_T;
		
		naipe.palo = "\5";
		losNaipes.insert(losNaipes.begin() + i, naipe);
		cont_T++;
	}
	for (int i = 26; i <= 38; i++)
	{
		naipe.numero = cont_D;		
		naipe.palo = "\4";
		losNaipes.insert(losNaipes.begin() + i, naipe);
		cont_D++;
	}
	for (int i = 39; i <= 51; i++)
	{
		naipe.numero = cont_P;		
		naipe.palo = "\6";
		losNaipes.insert(losNaipes.begin() + i, naipe);
		cont_P++;
	}

	cout << "\n\n";//se da una explicacion al usuario y muestran las cartas hechas 
	cout << "\n================================================================================\n";
	cout << "\nAlgunas cartas se representaran de la siguiente forma.\n";
	cout << "\nEjemplo: As=1  J=11 Q=12  K=13\n";
	cout << "\n=================================================================================\n";
	cout << "cantidad de cartas: "<<losNaipes.size()<<endl;
	for (int i = 0; i <= 51; i++)
	{
		if ((i == 12) || (i == 25) || (i == 38) || (i == 51))
		{
			cout << setw(1) << "[" << losNaipes[i].numero << losNaipes[i].palo << "]" << endl;
		}
		else
		{
			cout << setw(1) << "[" << losNaipes[i].numero << losNaipes[i].palo << "]";
		}

	}
	system("pause");
}

void imprimeJuego(cartas& naipe, vector<cartas>& losNaipes, vector<cartas>& manoJugador1, vector<cartas>& manoJugador2, vector<cartas>& manoJugador3, int& puntosJugador1, int& puntosJugador2, int& puntosJugador3)
{
	//esta funcion imprime o muestra constantemente las manos de los jugadores para poder desarrollar el juego correctamente
	system("cls");


	//=====================================================================
	//baraja. esta no se mostrara al usuario solo esta hecha para controlar y corregir posibles errores 
	/*cout << "cantidad de cartas: " << losNaipes.size() << endl;
	for (int i = 0; i <= 51; i++)
	{
		if ((i == 12) || (i == 25) || (i == 38) || (i == 51))
		{
			cout << setw(1) << "[" << losNaipes[i].numero << losNaipes[i].palo << "]" << endl;
		}
		else
		{
			cout << setw(1) << "[" << losNaipes[i].numero << losNaipes[i].palo << "]";
		}

	}
	cout << "\n\n";*/
	//======================================================================
	//jugador1
	cout << "\nMano jugador 1: ";
	for (int i = 0; i < manoJugador1.size(); i++)
	{
		cout << "[" << manoJugador1[i].numero << manoJugador1[i].palo << "]";
	}
	cout << "\n Puntos Jugador1: " << puntosJugador1 << endl;
	if (puntosJugador1 == 21)
	{
		cout << "\nJugador1 Gano!!!\n";
	}
	else if (puntosJugador1 > 21)
	{
		cout << "\nJugador1 Perdio!!!\n";
	}
	cout << "cantidad de cartas: " << manoJugador1.size() << endl;
	//=========================================================================
	//jugador2
	cout << "\nMano jugador 2: ";
	for (int i = 0; i < manoJugador2.size(); i++)
	{
		cout << "[" << manoJugador2[i].numero << manoJugador2[i].palo << "]";
	}
	cout << "\n Puntos Jugador2: " << puntosJugador2 << endl;
	if (puntosJugador2 == 21)
	{
		cout << "\nJugador2 Gano!!!\n";
	}
	else if (puntosJugador2 > 21)
	{
		cout << "\nJugador2 Perdio!!!\n";
	}
	cout << "cantidad de cartas: " << manoJugador2.size() << endl;
	//=========================================================================
	//jugador3
	cout << "\nMano jugador 3: ";
	for (int i = 0; i < manoJugador3.size(); i++)
	{
		cout << "[" << manoJugador3[i].numero << manoJugador3[i].palo << "]";
	}
	cout << "\n Puntos Jugador3: " << puntosJugador3 << endl;
	cout << "\n\n";
	if (puntosJugador3 == 21)
	{
		cout << "\nJugador3 Gano!!!\n";
	}
	else if (puntosJugador3 > 21)
	{
		cout << "\nJugador3 Perdio!!!\n";
	}
	cout << "cantidad de cartas: " << manoJugador3.size() << endl;
}



void revolverBaraja(cartas&, vector<cartas>& losNaipes)//esta funcion revuelve mi baraja de cartas de manera aleatoria siempre
{
	
	system("cls");
	srand(time(NULL));
	random_shuffle(losNaipes.begin(), losNaipes.end());//funcion random
	cout << "\nLA BARAJA FUE REVUELTA!!!\n";
	system("pause");
}


void repartirDosCartas(vector<cartas>& losNaipes, vector<cartas>& manoJugador1, vector<cartas>& manoJugador2, vector<cartas>& manoJugador3)
{
	// esta funcion sirve para repartir las primeras 2 cartas a cada jugador para poder comenzar el juego
	
	cout << "\n================================================================================\n";
	cout << "\nSe cambiara el valor representativo de las cartas por su valor real en el juego.\n"
		<< "\nPara su rapida interpretacion.\n";
	cout << "\nEjemplo: As=1punto o 11puntos  J=10puntos Q=10puntos  K=10puntos\n";
	cout << "\n=================================================================================\n";
	//se le cambia el valor a cualquier carta mayor de 10 por 10 segun las reglas de la valencia de los puntos
	for (int i = 0; i <= 51; i++)
	{
		if (losNaipes[i].numero > 10)
		{
			losNaipes[i].numero = 10;
		}

	}
	//se reparten las primeras 6 cartas a los jugadores
	cout << "\nINICIA EL JUEGO!!!\n";
	system("pause");
	manoJugador1.push_back(losNaipes[0]);
	manoJugador1.push_back(losNaipes[1]);
	manoJugador2.push_back(losNaipes[2]);
	manoJugador2.push_back(losNaipes[3]);
	manoJugador3.push_back(losNaipes[4]);
	manoJugador3.push_back(losNaipes[5]);
	//esta condicion es por si algun usuario le tocan 2 As en una misma mano,cambiara el valor de uno de los As a 11 pero el segundo lo dejara en 1
	if (manoJugador1[0].numero == 1 && manoJugador1[1].numero == 1)
	{
		manoJugador1[0].numero = 11;
		manoJugador1[1].numero = 1;
	}
	if (manoJugador2[0].numero == 1 && manoJugador2[1].numero == 1)
	{
		manoJugador2[0].numero = 11;
		manoJugador2[1].numero = 1;
	}
	if (manoJugador3[0].numero == 1 && manoJugador3[1].numero == 1)
	{
		manoJugador3[0].numero = 11;
		manoJugador3[1].numero = 1;
	}
}


void comprobarPuntos(vector<cartas>& manoJugador1, int& puntosJugador1, vector<cartas>& manoJugador2, int& puntosJugador2, vector<cartas>& manoJugador3, int& puntosJugador3, bool& ganador)
{
	// esta funcion sirve para comprobar los puntos de los jugadores 
	//primero evaula si ya hay un ganador entonces no hara nada y se saldra
	if (ganador == true)
	{
		return;
	}
	int contPerdieron = 0;
	puntosJugador1 = 0;
	puntosJugador2 = 0;
	puntosJugador3 = 0;

	//=============================================================
	if (puntosJugador1 <= 11)
	{
		puntosJugador1 = 0;
		for (int i = 0; i < manoJugador1.size(); i++)
		{
			if (manoJugador1[i].numero == 1)
			{
				manoJugador1[i].numero = 11;
			}
			puntosJugador1 = puntosJugador1 + manoJugador1[i].numero;
		}

	}
	if (puntosJugador1 == 21)
	{
		ganador = true;
		cout << "\nGano el jugador 1.\n";
	}
	if (puntosJugador1 > 21)
	{
		cout << "\nPerdio el jugador 1.\n";
		contPerdieron++;
	}
	//================================================================

	if (puntosJugador2 <= 11)
	{
		puntosJugador2 = 0;
		for (int i = 0; i < manoJugador2.size(); i++)
		{
			if (manoJugador2[i].numero == 1)
			{
				manoJugador2[i].numero = 11;
			}
			puntosJugador2 = puntosJugador2 + manoJugador2[i].numero;
		}

	}
	if (puntosJugador2 == 21)
	{
		ganador = true;
		cout << "\nGano el jugador 2.\n";
	}
	if (puntosJugador2 > 21)
	{
		cout << "\nPerdio el jugador 2.\n";
		contPerdieron++;
	}
	//===================================================

	if (puntosJugador3 <= 11)
	{
		puntosJugador3 = 0;
		for (int i = 0; i < manoJugador3.size(); i++)
		{
			if (manoJugador3[i].numero == 1)
			{
				manoJugador3[i].numero = 11;
			}
			puntosJugador3 = puntosJugador3 + manoJugador3[i].numero;
		}

	}
	if (puntosJugador3 == 21)
	{
		ganador = true;
		cout << "\nGano el jugador 3.\n";
	}
	if (puntosJugador3 > 21)
	{
		cout << "\nPerdio el jugador 3.\n";
		contPerdieron++;
	}
	if (contPerdieron >= 2)
	{

		if (puntosJugador1 < 21)
		{
			cout << "\nGano el jugador 1.\n";
		}
		else if (puntosJugador2 < 21)
		{
			cout << "\nGano el jugador 2.\n";
		}
		else if (puntosJugador3 < 21)
		{
			cout << "\nGano el jugador 3.\n";
		}
		else
		{
			cout << "\nPerdieron.\n";
		}
		system("pause");
		ganador = true;
	}

}

void pedirCarta(int& cartaSiguiente, vector<cartas>& manoJugador1, vector<cartas>& losNaipes, bool ganador)
{
	if (ganador == true)
	{
		return;
	}
	manoJugador1.push_back(losNaipes[cartaSiguiente]);
	cartaSiguiente++;
}

void buscarGanador(int& puntosJugador1, int& puntosJugador2, int& puntosJugador3, string& jugadorGanador, bool& ganador)
{
	if (ganador == true)
	{
		return;
	}
	if (puntosJugador1 > puntosJugador2 && puntosJugador3)
	{
		if (puntosJugador1 <= 21)
		{
			jugadorGanador = "Jugador1";
			cout << "Puntos: " << puntosJugador1 << " Ganador: " << jugadorGanador << endl;

		}

	}
	if (puntosJugador2 > puntosJugador1 && puntosJugador3)
	{
		if (puntosJugador2 <= 21)
		{
			jugadorGanador = "Jugador2";
			cout << "Puntos: " << puntosJugador1 << " Ganador: " << jugadorGanador << endl;
		}

	}
	if (puntosJugador3 > puntosJugador2 && puntosJugador1)
	{
		if (puntosJugador3 <= 21)
		{
			jugadorGanador = "Jugador2";
			cout << "Puntos: " << puntosJugador1 << " Ganador: " << jugadorGanador << endl;
		}

	}
	if (jugadorGanador != "")
	{
		ganador = true;
	}
}


void menu(cartas& naipe, vector<cartas>& losNaipes, vector<cartas>& manoJugador1, vector<cartas>& manoJugador2, vector<cartas>& manoJugador3, int& puntosJugador1, int& puntosJugador2, int& puntosJugador3, string& jugadorGanador, bool ganador, int cartaSiguiente, int turno)
{
	int opcion1 = 0, opcion2 = 0, opcion3 = 0;
	int contdeTurnos = 0, contdePerdedores = 0;
	if (ganador == true)
	{
		return;
	}
	cout << "\nFASE DE TURNOS.\n";
	system("pause");
	while (jugadorGanador == "")
	{
		system("cls");
		imprimeJuego(naipe, losNaipes, manoJugador1, manoJugador2, manoJugador3, puntosJugador1, puntosJugador2, puntosJugador3);
		cout << "\nOrden de los turnos sera:\n"
			<< "\n1.Turno Jugador 1\n"
			<< "\n2.Turno Jugador 2\n"
			<< "\n3.Turno Jugador 3\n";
		system("pause");
		system("cls");
		turno++;
		switch (turno)
		{
		case 1:
			if (ganador == true)
			{
				return;
			}
			cout << "1. Turno Jugador 1.\n";
			turno++;
			if (puntosJugador1 < 21)
			{
				cout << "\nElija una opcion\n"
					<< "\n1. Pedir carta.\n"
					<< "\n2. Pasar turno.\n";
				cin >> opcion1;
			}
			else if (puntosJugador1 > 21)
			{
				cout << "Jugador 1 Perdio,pasa turno\n";
				opcion1 = 2;
				contdePerdedores++;
			}

			if (opcion1 == 1)
			{
				pedirCarta(cartaSiguiente, manoJugador1, losNaipes, ganador);
				comprobarPuntos(manoJugador1, puntosJugador1, manoJugador2, puntosJugador2, manoJugador3, puntosJugador3, ganador);
				imprimeJuego(naipe, losNaipes, manoJugador1, manoJugador2, manoJugador3, puntosJugador1, puntosJugador2, puntosJugador3);
				if (puntosJugador1 == 21)
				{
					system("cls");
					jugadorGanador = "Jugador1";
					imprimeJuego(naipe, losNaipes, manoJugador1, manoJugador2, manoJugador3, puntosJugador1, puntosJugador2, puntosJugador3);
					//break;
					
				}
			}
			else if (opcion1 == 2)
			{

				cout << "\nPaso turno.\n";
				contdeTurnos++;
			}
			system("pause");
			system("cls");
			//break;
		case 2:
			if (ganador == true)
			{
				return;
			}
			cout << "2. Turno Jugador 2.\n";
			turno++;
			if (puntosJugador2 < 21)
			{
				cout << "\nElija una opcion\n"
					<< "\n1. Pedir carta.\n"
					<< "\n2. Pasar turno.\n";
				cin >> opcion2;

			}
			else if (puntosJugador2 > 21)
			{
				cout << "Jugador 1 Perdio,pasa turno\n";
				opcion2 = 2;
				contdePerdedores++;
			}

			if (opcion2 == 1)
			{
				pedirCarta(cartaSiguiente, manoJugador2, losNaipes, ganador);
				comprobarPuntos(manoJugador1, puntosJugador1, manoJugador2, puntosJugador2, manoJugador3, puntosJugador3, ganador);
				imprimeJuego(naipe, losNaipes, manoJugador1, manoJugador2, manoJugador3, puntosJugador1, puntosJugador2, puntosJugador3);
				if (puntosJugador2 == 21)
				{
					system("cls");
					jugadorGanador = "Jugador2";
					imprimeJuego(naipe, losNaipes, manoJugador1, manoJugador2, manoJugador3, puntosJugador1, puntosJugador2, puntosJugador3);
					//break;
				}
			}
			else if (opcion2 == 2)
			{

				cout << "\nPaso turno.\n";
				contdeTurnos++;
			}
			system("pause");
			system("cls");
			//break;
		case 3:
			if (ganador == true)
			{
				return;
			}
			cout << "3. Turno Jugador 3.\n";
			turno = 0;
			if (puntosJugador3 < 21)
			{
				cout << "\nElija una opcion\n"
					<< "\n1. Pedir carta.\n"
					<< "\n2. Pasar turno.\n";
				cin >> opcion3;

			}
			else if (puntosJugador3 > 21)
			{
				cout << "Jugador 3 Perdio,pasa turno\n";
				opcion3 = 2;
				contdePerdedores++;
			}
			if (opcion3 == 1)
			{
				pedirCarta(cartaSiguiente, manoJugador3, losNaipes, ganador);
				comprobarPuntos(manoJugador1, puntosJugador1, manoJugador2, puntosJugador2, manoJugador3, puntosJugador3, ganador);
				imprimeJuego(naipe, losNaipes, manoJugador1, manoJugador2, manoJugador3, puntosJugador1, puntosJugador2, puntosJugador3);
				if (puntosJugador3 == 21)
				{
					system("cls");
					jugadorGanador = "Jugador3";
					imprimeJuego(naipe, losNaipes, manoJugador1, manoJugador2, manoJugador3, puntosJugador1, puntosJugador2, puntosJugador3);
					//break;
				}
			}
			else if (opcion3 == 2)
			{
				cout << "\nPaso turno.\n";
				contdeTurnos++;
			}
			system("pause");
			system("cls");
			break;

		default:
			system("cls");
			cout << "\nOpcion incorrecta\n"
				<< "Intentelo de nuevo\n";
			//turno = 1;
			break;
		}
		if (contdeTurnos >= 3)
		{
			cout << "Fase de turnos finalizada\n";
			//jugadorGanador = "NoHubo21!!!";
			buscarGanador(puntosJugador1, puntosJugador2, puntosJugador3, jugadorGanador, ganador);
			//break;
		}
		else
		{
			contdeTurnos = 0;
		}
		if (contdePerdedores >= 2)
		{
			cout << "Fase de turnos finalizada\n";
			//jugadorGanador = "NoHubo21!!!";
			buscarGanador(puntosJugador1, puntosJugador2, puntosJugador3, jugadorGanador, ganador);
			//break;
		}
		else
		{
			contdePerdedores = 0;
		}
	}
}


