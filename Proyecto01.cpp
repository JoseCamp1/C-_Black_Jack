// Fecha de Creacion:27/11/22
// Nombre: Jose Campos Chaves
// Fecha de ultima modificacion:9/12/22
// Descripcion: 
// Ejercicio 1:
// El juego de cartas conocido como Blackjack o 21 consiste en un sencillo juego cuyo
// objetivo es lograr obtener 21 puntos o lo más cercano posible, pero sin pasarse.
// En la baraja cada carta numérica vale sus respectivos puntos, cada carta con 
// dibujo(J, Q, K) valen 10 puntos y el As vale 1 u 11 puntos, el valor del As lo 
// decide el jugador a su conveniencia.
// Se reparten 2 cartas a cada jugador, y cada jugador decide si pide más cartas o se 
// queda con su valor actual.Gana la persona que logre obtener 21 puntos, o lo más cercano
// posible, pero sin pasarse.
//
// Implementación:
//
// Realice una aplicación de consola que permita a 3 personas jugar una partida de Blackjack,
// no se utilizarán las reglas oficiales(dividir, doblar, rendirse, seguro, cobrar 1 a 1, etc.).
// Tampoco existirán las reglas de verse obligado a pedir si se tiene mayor o menor cantidad 
// de ciertos puntos.No existirá la figura oficial del crupier(repartidor), ya que este tiene
// reglas diferentes.
// Se realizará una partida sencilla en donde al iniciar se le reparten 2 cartas a cada una 
// de las 3 personas.Cada persona puede decidir si quiere una carta más en cada ronda, 
// pero si se pasa de 21 automáticamente pierde.
// Si una persona tiene un As se tomará como 11. Pero cuando una persona se pase de 21 
// automáticamente se tomará el As como 1.
// En cada ronda cada persona decide si desea tomar otra carta o no, y además cada vez 
// que una persona toma una carta se comprueba si tiene un 21 para declarar que ganó.
// Cuando las 3 personas ya hayan indicado que no desean tomar más cartas, entonces el 
// programa calculará quién ganó, tomando como ganadora a la persona cuyos puntos estén 
// más cerca de 21, pero sin pasarse, como se indicó anteriormente.Podría haber empates.
//

#include "Funciones.h"
//using namespace std;

int main()
{
	string jugadorGanador = "";
	bool ganador = false;
	int cartaSiguiente = 6;
	int turno = 0;

	//char num = 0;
	//int conversion;

	int puntosJugador1 = 0, puntosJugador2 = 0, puntosJugador3 = 0;
	cartas naipe;
	vector<cartas> losNaipes(0);
	vector<cartas> manoJugador1(0);
	vector<cartas> manoJugador2(0);
	vector<cartas> manoJugador3(0);

	int opcion = 0;
	do
	{
		cout << "\n\t\t\t===================================================\n";
		cout << "\t\t\t= Desea iniciar el programa (1)Iniciar , (2)Salir =";
		cout << "\n\t\t\t===================================================\n";
		cin >> opcion;
		system("pause");
		system("cls");
		if (opcion == 1)
		{
			cout << "\n\t\t\t\t\t\t\t=======================\n";
			cout << "\t\t\t\t\t\t\t= Bienvenido al juego =";
			cout << "\n\t\t\t\t\t\t\t=======================\n";
			system("pause");
			system("cls");


			cout << "\n\t\t\t\t\t\t\t ==============\n";
			cout << "\t\t\t\t\t\t\t = Black Jack =";
			cout << "\n\t\t\t\t\t\t\t ==============\n";
			system("pause");
			cout << "\n\t\t\t============================================================================================\n";
			cout << "\n\t\t\t= El juego de cartas conocido como Blackjack o 21 consiste en un sencillo juego cuyo       =\n";
			cout << "\n\t\t\t= objetivo es lograr obtener 21 puntos o lo mas cercano posible, pero sin pasarse.         =\n";
			cout << "\n\t\t\t= En la baraja cada carta numerica vale sus respectivos puntos, cada carta con             =\n";
			cout << "\n\t\t\t= dibujo(J, Q, K) valen 10 puntos y el As vale 1 u 11 puntos, el valor del As lo           =\n";
			cout << "\n\t\t\t= decide el jugador a su conveniencia.                                                     =\n";
			cout << "\n\t\t\t= Se reparten 2 cartas a cada jugador, y cada jugador decide si pide mas cartas o se       =\n";
			cout << "\n\t\t\t= queda con su valor actual.Gana la persona que logre obtener 21 puntos, o lo mas cercano  =\n";
			cout << "\n\t\t\t= posible, pero sin pasarse.                                                               =\n";
			cout << "\n\t\t\t============================================================================================\n";
			cout << "\n\t\t\t \n";
			cout << "\n\t\t\t \n";
			system("pause");
			system("cls");
			creacionBaraja(naipe, losNaipes);
			//imprimeJuego(naipe, losNaipes, manoJugador1, manoJugador2, manoJugador3, puntosJugador1, puntosJugador2, puntosJugador3);
			revolverBaraja(naipe, losNaipes);
			//imprimeJuego(naipe, losNaipes, manoJugador1, manoJugador2, manoJugador3, puntosJugador1, puntosJugador2, puntosJugador3);

			repartirDosCartas(losNaipes, manoJugador1, manoJugador2, manoJugador3);
			//imprimeJuego(naipe, losNaipes,manoJugador1,manoJugador2,manoJugador3, puntosJugador1, puntosJugador2, puntosJugador3);
			//imprimeJuego(naipe, losNaipes, manoJugador1, manoJugador2, manoJugador3, puntosJugador1, puntosJugador2, puntosJugador3);
			comprobarPuntos(manoJugador1, puntosJugador1, manoJugador2, puntosJugador2, manoJugador3, puntosJugador3, ganador);
			imprimeJuego(naipe, losNaipes, manoJugador1, manoJugador2, manoJugador3, puntosJugador1, puntosJugador2, puntosJugador3);
			menu(naipe, losNaipes, manoJugador1, manoJugador2, manoJugador3, puntosJugador1, puntosJugador2, puntosJugador3, jugadorGanador, ganador, cartaSiguiente, turno);
			cout << "\n\t\t\t==========================================\n";
			cout << "\nA continuacion se le dirigira al menu inicial\n"
				<<"\ny podra volver a jugar o salir del juego.\n";
			cout << "\n\t\t\t==========================================\n";
			system("pause");//para reiniciar todo
			losNaipes.clear();
			manoJugador1.clear();
			manoJugador2.clear();
			manoJugador3.clear();
			puntosJugador1 = 0;
			puntosJugador2 = 0;
			puntosJugador3 = 0;
			jugadorGanador = "";
			ganador = false;
			cartaSiguiente = 6;
			turno = 0;
		}
		else if (opcion == 2)
		{
			cout << "\n\t\t\t==========================================\n";
			cout << "\t\t\t= Gracias por su tiempo, tenga buen dia. =";
			cout << "\n\t\t\t==========================================\n";
			cout << "\n\t\t\t=================================================================\n";
			cout << "\t\t\t= Hecho por Jose Campos Chaves para Curso Programacion INA 2022 =";
			cout << "\n\t\t\t=================================================================\n";
		}
		else 
		{
			cout << "\n\t\t\t========================================\n";
			cout << "\t\t\t= Opcion incorrecta intentelo de nuevo =";
			cout << "\n\t\t\t========================================\n";
		}

	} while (opcion != 2);


	return 0;
}