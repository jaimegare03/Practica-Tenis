#include <iostream> 
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include<cstring>

using namespace std;

//-----CONSTANTES Y VARIABLES UNIVERSALES-----

const int LimInfHab = 1, LimSupHab = 2, LimInfVel = 1, LimSupVel = 3, AnchoPista = 7, PosicionTenista1 = 4, PosicionTenista2 = 4, HabilidadTenista1 = 0, HabilidadTenista2 = 0, VelocidadTenista1 = 0, VelocidadTenista2 = 0, PosicionBola = 0, num = 0, puntuacion2 = 0, puntuacion1 = 0;
char NombreTenista1[3], NombreTenista2[3];
bool JuegoAleatorio, victoria1, victoria2, GanarPunto1, GanarPunto2;

//-----FUNCIONES PARA INTRODUCIR EN LA MAIN-----

void IntroducirDato(), ModoDeJuego(), PuntosJugador1(), PuntosJugador2();
int GolpeoBola1(), GolpeoBola2(), CorreTenista1(), CorreTenista2();
string Marcador1(), Marcador2();

//-----FUNCION MAIN-----	

int main() {

	const int LimInfHab = 1, LimSupHab = 2, LimInfVel = 1, LimSupVel = 3, AnchoPista = 7;
	bool JuegoAleatorio, victoria1, victoria2, GanarPunto1, GanarPunto2;
	char NombreTenista1[3], NombreTenista2[3];
	int HabilidadTenista1, HabilidadTenista2, VelocidadTenista1, VelocidadTenista2, puntuacion1 = 0, puntuacion2 = 0, PosicionBola = 0, PosicionTenista2 = 4, PosicionTenista1 = 4;


	cout << "------- INTRODUCIR DATOS DE LOS JUGADORES -------" << endl;  // Embellecedor del programa que indica que vamos a empezar haciendo
	cout << endl;

	//-----INTRODUCIR DATOS TENISTA 1-----

	cout << "Tenista 1 se llama (Siglas de 3 letras) : ";
	cin >> NombreTenista1;

	cout << "Habilidad de " << NombreTenista1 << " es (Introducir numero entre 1 y 2):";
	cin >> HabilidadTenista1;

	while (HabilidadTenista1 < LimInfHab || HabilidadTenista1 > LimSupHab) {

		cout << "No tiene una habilidad valida" << endl;
		cout << "Vuelva a introducir la habilidad: ";
		cin >> HabilidadTenista1;
	}

	cout << "Velocidad de " << NombreTenista1 << " es (Introducir numero entre 1 y 3):";
	cin >> VelocidadTenista1;

	while (VelocidadTenista1 < LimInfVel || VelocidadTenista1 > LimSupVel) {

		cout << "No tiene una velocidad valida" << endl;
		cout << "Vuelva a introducir la velocidad: ";
		cin >> VelocidadTenista1;

	}

	//-----INTRODUCIR DATOS TENISTA 2-----

	cout << "Tenista 2 se llama (Siglas de 3 letras) :";
	cin >> NombreTenista2;

	cout << "Habilidad de " << NombreTenista2 << " es (Introducir numero entre 1 y 2) :";
	cin >> HabilidadTenista2;

	while (HabilidadTenista2 < LimInfHab || HabilidadTenista2 > LimSupHab) {

		cout << "No tiene una habilidad valida" << endl;
		cout << "Vuelva a introducir la habilidad: ";
		cin >> HabilidadTenista2;
	}

	cout << "Velocidad de " << NombreTenista2 << " es (Introducir numero entre 1 y 3) :";
	cin >> VelocidadTenista2;

	while (VelocidadTenista2 < LimInfVel || VelocidadTenista2 > LimSupVel) {

		cout << "No tiene una velocidad valida" << endl;
		cout << "Vuelva a introducir la velocidad: ";
		cin >> VelocidadTenista2;
	}

	cout << endl;

		cout << "/-----------------------------------------------/" << endl;

			cout << endl;

		cout << " ------- ELEGIR MODO DE JUEGO -------" << endl;

			cout << endl;
	
		ModoDeJuego();

			cout << endl;

		cout << "/-----------------------------------/" << endl;

		cout << endl;

		cout << "/////// MARCADOR ///////" << endl;

		cout << NombreTenista1 << " " << PuntosJugador1 << " - " << PuntosJugador2 << " " << NombreTenista2 << endl;

		cout << "////////////////////////" << endl;

	int num;

	srand(time(NULL));

	num = rand() % 2;

	if (num == 0) {

		cout << "Sacara este juego " << NombreTenista1 << "." << endl;

		system("pause");

		GolpeoBola1();

	}
	if (num == 1) {

		cout << "Sacara este juego " << NombreTenista2 << "." << endl;

		system("pause");

		GolpeoBola2();


	}

	victoria1 = false, victoria2 = false;

	while ((victoria1 == false) && (victoria2 == false)) {


		if (num == 0) {

			system("pause");

			GolpeoBola1();

			CorreTenista2();

			if ((PosicionBola < 1) || (PosicionBola > 7)) {

				cout << "Manda la bola fuera de la pista, gana " << NombreTenista2;

				GanarPunto2 = true;
				puntuacion2 = puntuacion2 + 1;
			}

			system("pause");

			GolpeoBola2();

			CorreTenista1();


			if ((PosicionBola < 1) || (PosicionBola > 7)) {

				cout << "Manda la bola fuera de la pista, gana " << NombreTenista1;

				GanarPunto1 = true;
				puntuacion1 = puntuacion1 + 1;

			}

		}

		if (num == 1) {

			system("pause");

			GolpeoBola2();

			CorreTenista1();


			if ((PosicionBola <= 0) || (PosicionBola >= 8)) {

				cout << "Manda la bola fuera de la pista, gana " << NombreTenista1;

				GanarPunto1 = true;
				puntuacion1 = puntuacion1 + 1;
			}

			system("pause");

			GolpeoBola1();

			CorreTenista2();


			if ((PosicionBola < 1) || (PosicionBola > 7)) {

				cout << "Manda la bola fuera de la pista, gana " << NombreTenista2;

				GanarPunto2 = true;
				puntuacion2 = puntuacion2 + 1;
			}
		}



	}



	if ((victoria1 == true) || (victoria2 == true)) {

		if (victoria1 == true) {

			cout << "Acaba el partido y se lleva la victoria " << NombreTenista1 << endl;

		}

		if (victoria2 == true) {

			cout << "Acaba el partido y se lleva la victoria " << NombreTenista2 << endl;
		}
	}



	return 0;
}

//-----FUNCIONES PARA DESARROLLAR EN LA MAIN -----

void IntroducirDato() {

	//-----VARIABLES-----

	char NombreTenista1[3], NombreTenista2[3];
	int HabilidadTenista1, HabilidadTenista2, VelocidadTenista1, VelocidadTenista2;

	//-----INTRODUCIR DATOS TENISTA 1-----

	cout << "Tenista 1 se llama (Siglas de 3 letras) : ";
	cin >> NombreTenista1;

	cout << "Habilidad de " << NombreTenista1 << " es (Introducir numero entre 1 y 2):";
	cin >> HabilidadTenista1;

	while (HabilidadTenista1 < LimInfHab || HabilidadTenista1 > LimSupHab) {

		cout << "No tiene una habilidad valida" << endl;
		cout << "Vuelva a introducir la habilidad: ";
		cin >> HabilidadTenista1;
	}

	cout << "Velocidad de " << NombreTenista1 << " es (Introducir numero entre 1 y 3):";
	cin >> VelocidadTenista1;

	while (VelocidadTenista1 < LimInfVel || VelocidadTenista1 > LimSupVel) {

		cout << "No tiene una velocidad valida" << endl;
		cout << "Vuelva a introducir la velocidad: ";
		cin >> VelocidadTenista1;

	}

	//-----INTRODUCIR DATOS TENISTA 2-----

	cout << "Tenista 2 se llama (Siglas de 3 letras) :";
	cin >> NombreTenista2;

	cout << "Habilidad de " << NombreTenista2 << " es (Introducir numero entre 1 y 2) :";
	cin >> HabilidadTenista2;

	while (HabilidadTenista2 < LimInfHab || HabilidadTenista2 > LimSupHab) {

		cout << "No tiene una habilidad valida" << endl;
		cout << "Vuelva a introducir la habilidad: ";
		cin >> HabilidadTenista2;
	}

	cout << "Velocidad de " << NombreTenista2 << " es (Introducir numero entre 1 y 3) :";
	cin >> VelocidadTenista2;

	while (VelocidadTenista2 < LimInfVel || VelocidadTenista2 > LimSupVel) {

		cout << "No tiene una velocidad valida" << endl;
		cout << "Vuelva a introducir la velocidad: ";
		cin >> VelocidadTenista2;
	}
}

void ModoDeJuego() {

	string Modo = "usuario";

	cout << "Si desea que el destino de la bola sea elegido aleatoriamente por el ordenador introduce <ordenador>" << endl;
	cout << "Si desea que el destino de la bola sea elegido por el usuario introduce <usuario>" << endl;
	cout << "Introducir modo de juego deseado: ";
	cin >> Modo;
	cout << endl;

	if (Modo == "usuario") {

		JuegoAleatorio = true;
		cout << "Se jugara con el destino del golpeo introducido por el usuario." << endl;

	}

	if (Modo == "ordenador") {

		JuegoAleatorio = false;
		cout << "Se jugara con el destino del golpeo elegido por el ordenador." << endl;
	}

}

int GolpeoBola1() {

	int  ProbabilidadAcierto, PosicionBola, num;

	if (JuegoAleatorio == false) {


		srand(time(NULL));

		PosicionBola = rand() % 8;

		cout << NombreTenista1 << " Mandara la bola hasta la calle numero " << PosicionBola << endl;


		if (abs(PosicionBola - PosicionTenista1) <= HabilidadTenista1) {

			cout << " La bola llega hasta esa posicion sin problemas." << endl;

		}
		if (abs(PosicionBola - PosicionTenista2) > HabilidadTenista2) {

			ProbabilidadAcierto = 100 - ((abs(PosicionBola - PosicionTenista1) - HabilidadTenista1) / (AnchoPista - 1) - LimInfHab) * 100;

			int num;

			srand(time(NULL));

			num = rand() % 100;

			if (num < ProbabilidadAcierto) {

				cout << "La bola llegara hasta la posicion deseada." << endl;

			}


			if (num > ProbabilidadAcierto) {

				cout << "La bola se desviara un poco." << endl;

				int num1;

				srand(time(NULL));

				num1 = rand() % 2;

				if (num1 == 0) {

					PosicionBola = PosicionBola - 1;

					cout << "La bola se desviara una calle a la izquierda.";

				}
				if (num1 == 1) {

					PosicionBola = PosicionBola + 1;

					cout << "La bola se desviara una calle a la derecha.";
				}

			}

		}
	}


	if (JuegoAleatorio == true) {

		cout << "¿ A que calle golpea " << NombreTenista1 << " la bola ? : " << endl;
		cin >> PosicionBola;



		if (abs(PosicionBola - PosicionTenista1) <= HabilidadTenista1) {

			cout << " La bola llega hasta esa posicion sin problemas." << endl;

		}
		if (abs(PosicionBola - PosicionTenista2) > HabilidadTenista2) {

			ProbabilidadAcierto = 100 - ((abs(PosicionBola - PosicionTenista1) - HabilidadTenista1) / (AnchoPista - 1) - LimInfHab) * 100;

			int num2;

			srand(time(NULL));

			num2 = rand() % 100;

			if (num2 < ProbabilidadAcierto) {

				cout << "La bola llegara hasta la posicion deseada." << endl;

			}
			if (num2 > ProbabilidadAcierto) {

				cout << "La bola se desviara un poco." << endl;

				int num3;

				srand(time(NULL));

				num3 = rand() % 2;

				if (num3 == 0) {

					PosicionBola = PosicionBola - 1;

					cout << "La bola se desviara una calle a la izquierda.";

				}
				if (num3 == 1) {

					PosicionBola = PosicionBola + 1;

					cout << "La bola se desviara una calle a la derecha.";

				}

			}

		}

	}

	return 0;
}

int GolpeoBola2() {

	int  ProbabilidadAcierto, PosicionBola, num;

	if (JuegoAleatorio == false) {

		srand(time(NULL));

		PosicionBola = rand() % 8;

		cout << NombreTenista2 << " mandara la bola hasta la calle numero " << PosicionBola << endl;

		if (abs(PosicionBola - PosicionTenista2) <= HabilidadTenista2) {

			cout << " La bola llega hasta esa posicion sin problemas." << endl;

		}
		if (abs(PosicionBola - PosicionTenista2) > HabilidadTenista2) {

			ProbabilidadAcierto = 100 - ((abs(PosicionBola - PosicionTenista2) - HabilidadTenista2) / (AnchoPista - 1) - LimInfHab) * 100;

			int num;

			srand(time(NULL));

			num = rand() % 100;

			if (num < ProbabilidadAcierto) {

				cout << "La bola llegara hasta la posicion deseada." << endl;

			}


			if (num > ProbabilidadAcierto) {

				cout << "La bola se desviara un poco." << endl;

				int num1;

				srand(time(NULL));

				num1 = rand() % 2;

				if (num1 == 0) {

					PosicionBola = PosicionBola - 1;

					cout << "La bola se desviara una calle a la izquierda.";

				}
				if (num == 1) {

					PosicionBola = PosicionBola + 1;

					cout << "La bola se desviara una calle a la derecha.";
				}

			}

		}

	}

	if (JuegoAleatorio == true) {

		cout << "A que calle golpea " << NombreTenista2 << " la bola ?: ";
		cin >> PosicionBola;

		if (abs(PosicionBola - PosicionTenista2) <= HabilidadTenista2) {

			cout << "La bola llega hasta esa posicion sin problemas." << endl;

		}

		if (abs(PosicionBola - PosicionTenista2) > HabilidadTenista2) {

			ProbabilidadAcierto = 100 - ((abs(PosicionBola - PosicionTenista2) - HabilidadTenista2) / (AnchoPista - 1) - LimInfHab) * 100;

			int num2;

			srand(time(NULL));

			num2 = rand() % 100;

			if (num2 < ProbabilidadAcierto) {

				cout << "La bola llegara hasta la posicion deseada." << endl;

			}
			if (num2 > ProbabilidadAcierto) {

				cout << "La bola se desviara un poco." << endl;

				int num3;

				srand(time(NULL));

				num3 = rand() % 2;

				if (num3 == 0) {

					PosicionBola = PosicionBola - 1;

					cout << "La bola se desviara una calle a la izquierda.";

				}
				else {

					PosicionBola = PosicionBola + 1;

					cout << "La bola se desviara una calle a la derecha.";

				}

			}

		}
	}
	return 0;
}

int CorreTenista1() {

	if (abs(PosicionTenista1 - PosicionBola) <= VelocidadTenista1) {

		cout << NombreTenista1 << " llega hasta la bola y devuelve el golpeo." << endl;

		GolpeoBola1();
	}

	if (abs(PosicionTenista1 - PosicionBola) > VelocidadTenista1) {

		cout << NombreTenista1 << " fue demasiado lento y no llego a tiempo, punto para " << NombreTenista2 << endl;

		GanarPunto1 = puntuacion2+ 1;

	}

	return 0;
}

int CorreTenista2() {

	if (abs(PosicionTenista2 - PosicionBola) <= VelocidadTenista2) {

		cout << NombreTenista2 << " llega hasta la bola y devuelve el golpeo." << endl;

		GolpeoBola2();
	}

	else {

		cout << NombreTenista1 << " fue demasiado lento y no llego a tiempo, punto para " << NombreTenista2 << endl;

		GanarPunto1 = puntuacion1 + 1;
	}

	return 0;

}

string Marcador() {

	int puntuacion1 = 0, puntuacion2 = 0;

	switch (puntuacion1) {

	case 1: cout << "00";
		break;

	case 2: cout << "15";
		break;

	case 3: cout << "30";
		break;

	case 4: cout << "40";
		break;

	case 5: cout << "Ad";
		break;

	}

	switch (puntuacion2) {

	case 1: cout << "00";
		break;

	case 2: cout << "15";
		break;

	case 3: cout << "30";
		break;

	case 4: cout << "40";
		break;

	case 5: cout << "Ad";
		break;

	}
	return 0;
}

void PuntosJugador1() {

	Marcador();

}

void PuntosJugador2() {

	Marcador();

}