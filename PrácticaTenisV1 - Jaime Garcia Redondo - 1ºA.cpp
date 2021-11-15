

// DESARROLLADO POR JAIME GARCIA REDONDO, 1ºA


#include <iostream>				
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include<cstring>

using namespace std;

// -------CONSTANTES DEL PROGRAMA-------//

const int LimInfHab = 0, LimSupHab = 2, LimInfVel = 0, LimSupVel = 3, AnchoPista = 7;
bool JuegoAleatorio = false, Victoria1 = false, Victoria2 = false, GanarPunto1 = false, GanarPunto2 = false, ModoDebug = false;

//-------DECLARACION DE FUNCIONES-------//

void ModoDeJuego();
int GolpeoBola(int PosicionTenista, int HabilidadTenista);
string Marcador(int puntuacion);
int CorreTenista(int PosicionTenista, int VelocidadTenista, int PosicionBola);

int main() {											// DESARROLLADO POR JAIME GARCIA REDONDO, 1ºA

	//----- DECLARACION DE VARIABLES -----//

	int HabilidadTenista1 = 0, VelocidadTenista1 = 0, HabilidadTenista2 = 0, VelocidadTenista2 = 0, PosicionTenista1 = 4, PosicionTenista2 = 4, Puntuacion1 = 0, Puntuacion2 = 0;
	string NombreTenista1, NombreTenista2;


	cout << "BIENVENIDO AL SIMULADOR DE PARTIDOS DE TENIS" << endl;
	cout << endl;

	cout << "------- INTRODUCIR DATOS DE LOS JUGADORES -------" << endl;  // Embellecedor del programa que indica que vamos a empezar haciendo
	cout << endl;

	//-----INTRODUCIR DATOS TENISTA 1-----//

	cout << "_-_-_- INTRODUCIR DATOS TENISTA 1 -_-_-_" << endl;
	cout << endl;

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

	cout << endl;

	//-----INTRODUCIR DATOS TENISTA 2-----//

	cout << "_-_-_- INTRODUCIR DATOS TENISTA 2 -_-_-_" << endl;
	cout << endl;

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

	//-----FUNCIÓN PARA DECIDIR EL MODO DE JUEGO DEL PARTIDO-----//
	cout << endl;

	cout << "_-_-_- ELEGIR MODO DE JUEGO -_-_-_" << endl;

	cout << endl;

	ModoDeJuego();

	//-----MOSTRAMOS EL MARCADOR ANTES DE COMENZAR EL PARTIDO-----//

	cout << endl;

	cout << "/////// MARCADOR ///////" << endl;

	cout << NombreTenista1 << " // " << Marcador(Puntuacion1) << " - " << Marcador(Puntuacion2) << " // " << NombreTenista2 << endl;

	cout << "////////////////////////" << endl;

	cout << endl;

	//----- ELEGIR SERVICIO -----//

	int num, PosicionBola;

	srand(time(NULL));

	num = rand() % 2;

	if (num == 0) {

		cout << "Sacara este juego " << NombreTenista1 << "." << endl;

	}
	if (num == 1) {

		cout << "Sacara este juego " << NombreTenista2 << "." << endl;

	}

	while ((Victoria1 == false) && (Victoria2 == false)) {

		if (ModoDebug == false) {

			if (num == 0) {

				// COMIENZA GOLPEANDO JUGADOR 1 Y RECIBIENDO JUGADOR 2

				system("pause");

				cout << "Golpea " << NombreTenista1 << endl;

				PosicionBola = GolpeoBola(PosicionTenista1, HabilidadTenista1);

				PosicionTenista2 = CorreTenista(PosicionTenista2, VelocidadTenista2, PosicionBola);


				if ((PosicionBola < 1) || (PosicionBola > 7)) {			// PERDER SI LA PELOTA SALE FUERA

					cout << "Gana el punto " << NombreTenista2 << endl;

					if ((Puntuacion1 == 4) && (Puntuacion2 == 3)) {

						Puntuacion1 = 3;
						Puntuacion2 = 3;
					}
					else if ((Puntuacion2 == 4) && (Puntuacion1 == 3)) {

						Puntuacion2 = Puntuacion2 + 1;
						Victoria2 = true;
					}
					else if ((Puntuacion2 == 4) && (Puntuacion1 < 3)) {

						Puntuacion2 = Puntuacion2 + 1;
						Victoria2 = true;
					}
					else {

						Puntuacion2 = Puntuacion2 + 1;

						GanarPunto2 = true;
					}


				}

				if ((PosicionTenista2 != PosicionBola) && ((PosicionBola >= 1) && (PosicionBola <= 7))) {			// PERDER SI EL TENISTA NO ALCANZA LA PELOTA

					cout << "Gana el punto " << NombreTenista1 << endl;

					if ((Puntuacion1 == 4) && (Puntuacion2 == 3)) {

						Puntuacion1 = Puntuacion1 + 1;
						Victoria1 = true;
					}
					else if ((Puntuacion2 == 4) && (Puntuacion1 == 3)) {

						Puntuacion2 = 3;
						Puntuacion1 = 3;
					}
					else if ((Puntuacion1 == 4) && (Puntuacion2 < 3)) {

						Puntuacion1 = Puntuacion1 + 1;
						Victoria1 = true;
					}
					else {

						Puntuacion1 = Puntuacion1 + 1;

						GanarPunto1 = true;
					}

				}


				if ((GanarPunto1 == true) || (GanarPunto2 == true)) {

					cout << endl;

					cout << "/////// MARCADOR ///////" << endl;

					cout << NombreTenista1 << " // " << Marcador(Puntuacion1) << " - " << Marcador(Puntuacion2) << " // " << NombreTenista2 << endl;

					cout << "////////////////////////" << endl;

					cout << endl;

					if (Puntuacion1 == 5) {
						Victoria1 = true;
					}

					if (Puntuacion2 == 5) {
						Victoria2 = true;
					}

					PosicionBola = 4, PosicionTenista1 = 4, PosicionTenista2 = 4;

				}


				system("pause"); //PARA PODER JUGAR CON CALMA Y VER CLARAMENTE LO QUE HA PASADO EN LA JUGADA ANTERIOR

				// AHORA GOLPEA EL JUGADOR 2 Y RECIBE EL 1

				cout << "Golpea " << NombreTenista2 << endl;

				PosicionBola = GolpeoBola(PosicionTenista2, HabilidadTenista2);

				PosicionTenista1 = CorreTenista(PosicionTenista1, VelocidadTenista1, PosicionBola);

				if ((PosicionBola < 1) || (PosicionBola > 7)) {

					cout << "Gana el punto " << NombreTenista1 << endl;

					if ((Puntuacion1 == 4) && (Puntuacion2 == 3)) {

						Puntuacion1 = Puntuacion1 + 1;
						Victoria1 = true;
					}
					else if ((Puntuacion2 == 4) && (Puntuacion1 == 3)) {

						Puntuacion2 = 3;
						Puntuacion1 = 3;
					}
					else if ((Puntuacion1 == 4) && (Puntuacion2 < 3)) {

						Puntuacion1 = Puntuacion1 + 1;
						Victoria1 = true;
					}
					else {

						Puntuacion1 = Puntuacion1 + 1;

						GanarPunto1 = true;
					}
				}

				if ((PosicionTenista1 != PosicionBola) && ((PosicionBola >= 1) && (PosicionBola <= 7))) {

					cout << "Gana el punto " << NombreTenista2 << endl;


					if ((Puntuacion1 == 4) && (Puntuacion2 == 3)) {

						Puntuacion1 = 3;
						Puntuacion2 = 3;
					}
					else if ((Puntuacion2 == 4) && (Puntuacion1 == 3)) {

						Puntuacion2 = Puntuacion2 + 1;
						Victoria2 = true;
					}
					else if ((Puntuacion2 == 4) && (Puntuacion1 < 3)) {

						Puntuacion2 = Puntuacion2 + 1;
						Victoria2 = true;
					}
					else {

						Puntuacion2 = Puntuacion2 + 1;

						GanarPunto2 = true;
					}

				}


				if ((GanarPunto1 == true) || (GanarPunto2 == true)) {

					cout << endl;

					cout << "/////// MARCADOR ///////" << endl;

					cout << NombreTenista1 << " // " << Marcador(Puntuacion1) << " - " << Marcador(Puntuacion2) << " // " << NombreTenista2 << endl;

					cout << "////////////////////////" << endl;

					cout << endl;

					if (Puntuacion1 == 5) {
						Victoria1 = true;
					}

					if (Puntuacion2 == 5) {
						Victoria2 = true;
					}

					PosicionBola = 4, PosicionTenista1 = 4, PosicionTenista2 = 4;

				}

			}

			if (num == 1) {

				system("pause");

				cout << "Golpea " << NombreTenista2 << endl;

				PosicionBola = GolpeoBola(PosicionTenista2, HabilidadTenista2);

				PosicionTenista1 = CorreTenista(PosicionTenista1, VelocidadTenista1, PosicionBola);

				if ((PosicionBola < 1) || (PosicionBola > 7)) {

					cout << "Gana el punto " << NombreTenista1 << endl;
					if ((Puntuacion1 == 4) && (Puntuacion2 == 3)) {

						Puntuacion1 = Puntuacion1 + 1;
						Victoria1 = true;
					}
					else if ((Puntuacion2 == 4) && (Puntuacion1 == 3)) {

						Puntuacion2 = 3;
						Puntuacion1 = 3;
					}
					else if ((Puntuacion1 == 4) && (Puntuacion2 < 3)) {

						Puntuacion1 = Puntuacion1 + 1;
						Victoria1 = true;
					}
					else {

						Puntuacion1 = Puntuacion1 + 1;

						GanarPunto1 = true;
					}
				}

				if ((PosicionTenista1 != PosicionBola) && ((PosicionBola >= 1) && (PosicionBola <= 7))) {

					cout << "Gana el punto " << NombreTenista2 << endl;

					if ((Puntuacion1 == 4) && (Puntuacion2 == 3)) {

						Puntuacion1 = 3;
						Puntuacion2 = 3;
					}
					else if ((Puntuacion2 == 4) && (Puntuacion1 == 3)) {

						Puntuacion2 = Puntuacion2 + 1;
						Victoria2 = true;
					}
					else if ((Puntuacion2 == 4) && (Puntuacion1 < 3)) {

						Puntuacion2 = Puntuacion2 + 1;
						Victoria2 = true;
					}
					else {

						Puntuacion2 = Puntuacion2 + 1;

						GanarPunto2 = true;
					}

				}


				if ((GanarPunto1 == true) || (GanarPunto2 == true)) {

					cout << endl;

					cout << "/////// MARCADOR ///////" << endl;

					cout << NombreTenista1 << " // " << Marcador(Puntuacion1) << " - " << Marcador(Puntuacion2) << " // " << NombreTenista2 << endl;

					cout << "////////////////////////" << endl;

					cout << endl;

					if (Puntuacion1 == 5) {
						Victoria1 = true;
					}

					if (Puntuacion2 == 5) {
						Victoria2 = true;
					}

					PosicionBola = 4, PosicionTenista1 = 4, PosicionTenista2 = 4;

				}

				system("pause");

				cout << "Golpea " << NombreTenista1 << endl;

				PosicionBola = GolpeoBola(PosicionTenista1, HabilidadTenista1);

				PosicionTenista2 = CorreTenista(PosicionTenista2, VelocidadTenista2, PosicionBola);


				if ((PosicionBola < 1) || (PosicionBola > 7)) {			// PERDER SI LA PELOTA SALE FUERA

					cout << "Gana el punto " << NombreTenista2 << endl;

					if ((Puntuacion1 == 4) && (Puntuacion2 == 3)) {

						Puntuacion1 = 3;
						Puntuacion2 = 3;
					}
					else if ((Puntuacion2 == 4) && (Puntuacion1 == 3)) {

						Puntuacion2 = Puntuacion2 + 1;
						Victoria2 = true;
					}
					else if ((Puntuacion2 == 4) && (Puntuacion1 < 3)) {

						Puntuacion2 = Puntuacion2 + 1;
						Victoria2 = true;
					}
					else {

						Puntuacion2 = Puntuacion2 + 1;

						GanarPunto2 = true;
					}

				}

				if ((PosicionTenista2 != PosicionBola) && ((PosicionBola >= 1) && (PosicionBola <= 7))) {			// PERDER SI EL TENISTA NO ALCANZA LA PELOTA

					cout << "Gana el punto " << NombreTenista1 << endl;

					if ((Puntuacion1 == 4) && (Puntuacion2 == 3)) {

						Puntuacion1 = Puntuacion1 + 1;
						Victoria1 = true;
					}
					else if ((Puntuacion2 == 4) && (Puntuacion1 == 3)) {

						Puntuacion2 = 3;
						Puntuacion1 = 3;
					}
					else if ((Puntuacion1 == 4) && (Puntuacion2 < 3)) {

						Puntuacion1 = Puntuacion1 + 1;
						Victoria1 = true;
					}
					else {

						Puntuacion1 = Puntuacion1 + 1;

						GanarPunto1 = true;
					}

				}

				if ((GanarPunto1 == true) || (GanarPunto2 == true)) {

					cout << endl;

					cout << "/////// MARCADOR ///////" << endl;

					cout << NombreTenista1 << " // " << Marcador(Puntuacion1) << " - " << Marcador(Puntuacion2) << " // " << NombreTenista2 << endl;

					cout << "////////////////////////" << endl;

					cout << endl;

					if (Puntuacion1 == 5) {
						Victoria1 = true;
					}

					if (Puntuacion2 == 5) {
						Victoria2 = true;
					}

					PosicionBola = 4, PosicionTenista1 = 4, PosicionTenista2 = 4;

				}

			}


		}


		if (ModoDebug == true) {

			if (num == 0) {

				system("pause");

				cout << "Golpea " << NombreTenista1 << endl;

				PosicionBola = GolpeoBola(PosicionTenista1, HabilidadTenista1);

				PosicionTenista2 = CorreTenista(PosicionTenista2, VelocidadTenista2, PosicionBola);

				if ((PosicionBola < 1) || (PosicionBola > 7)) {

					cout << "Manda la bola fuera de la pista, gana " << NombreTenista2 << endl;

					if ((Puntuacion1 == 4) && (Puntuacion2 == 3)) {

						Puntuacion1 = 3;
						Puntuacion2 = 3;
					}
					else if ((Puntuacion2 == 4) && (Puntuacion1 == 3)) {

						Puntuacion2 = Puntuacion2 + 1;
						Victoria2 = true;
					}
					else if ((Puntuacion2 == 4) && (Puntuacion1 < 3)) {

						Puntuacion2 = Puntuacion2 + 1;
						Victoria2 = true;
					}
					else {

						Puntuacion2 = Puntuacion2 + 1;

						GanarPunto2 = true;
					}

				}

				if ((PosicionTenista2 != PosicionBola) && ((PosicionBola >= 1) && (PosicionBola <= 7))) {

					cout << "No llega a tiempo para devolver el golpeo y pierde el punto." << endl;

					if ((Puntuacion1 == 4) && (Puntuacion2 == 3)) {

						Puntuacion1 = Puntuacion1 + 1;
						Victoria1 = true;
					}
					else if ((Puntuacion2 == 4) && (Puntuacion1 == 3)) {

						Puntuacion2 = 3;
						Puntuacion1 = 3;
					}
					else if ((Puntuacion1 == 4) && (Puntuacion2 < 3)) {

						Puntuacion1 = Puntuacion1 + 1;
						Victoria1 = true;
					}
					else {

						Puntuacion1 = Puntuacion1 + 1;

						GanarPunto1 = true;
					}
				}
				else {

					cout << "Alcanza la bola y devuelve el golpeo." << endl;
				}

				if ((GanarPunto1 == true) || (GanarPunto2 == true)) {

					cout << endl;

					cout << "/////// MARCADOR ///////" << endl;

					cout << NombreTenista1 << " // " << Marcador(Puntuacion1) << " - " << Marcador(Puntuacion2) << " // " << NombreTenista2 << endl;

					cout << "////////////////////////" << endl;

					cout << endl;

					if (Puntuacion1 == 5) {
						Victoria1 = true;
					}

					if (Puntuacion2 == 5) {
						Victoria2 = true;
					}

					PosicionBola = 4, PosicionTenista1 = 4, PosicionTenista2 = 4;

				}

				system("pause");


				cout << "Golpea " << NombreTenista2 << endl;

				PosicionBola = GolpeoBola(PosicionTenista2, HabilidadTenista2);

				cout << "La bola es lanzada hasta la calle numero " << PosicionBola << endl;

				PosicionTenista1 = CorreTenista(PosicionTenista1, VelocidadTenista1, PosicionBola);

				if ((PosicionBola < 1) || (PosicionBola > 7)) {

					cout << "Manda la bola fuera de la pista, gana " << NombreTenista1 << endl;

					if ((Puntuacion1 == 4) && (Puntuacion2 == 3)) {

						Puntuacion1 = Puntuacion1 + 1;
						Victoria1 = true;
					}
					else if ((Puntuacion2 == 4) && (Puntuacion1 == 3)) {

						Puntuacion2 = 3;
						Puntuacion1 = 3;
					}
					else if ((Puntuacion1 == 4) && (Puntuacion2 < 3)) {

						Puntuacion1 = Puntuacion1 + 1;
						Victoria1 = true;
					}
					else {

						Puntuacion1 = Puntuacion1 + 1;

						GanarPunto1 = true;
					}
				}

				if ((PosicionTenista1 != PosicionBola) && ((PosicionBola >= 1) && (PosicionBola <= 7))) {

					cout << "No llega a tiempo para devolver el golpeo y pierde el punto." << endl;

					if ((Puntuacion1 == 4) && (Puntuacion2 == 3)) {

						Puntuacion1 = 3;
						Puntuacion2 = 3;
					}
					else if ((Puntuacion2 == 4) && (Puntuacion1 == 3)) {

						Puntuacion2 = Puntuacion2 + 1;
						Victoria2 = true;
					}
					else if ((Puntuacion2 == 4) && (Puntuacion1 < 3)) {

						Puntuacion2 = Puntuacion2 + 1;
						Victoria2 = true;
					}
					else {

						Puntuacion2 = Puntuacion2 + 1;

						GanarPunto2 = true;
					}

				}
				else {

					cout << "Alcanza la bola y devuelve el golpeo." << endl;
				}

				if ((GanarPunto1 == true) || (GanarPunto2 == true)) {

					cout << endl;

					cout << "/////// MARCADOR ///////" << endl;

					cout << NombreTenista1 << " // " << Marcador(Puntuacion1) << " - " << Marcador(Puntuacion2) << " // " << NombreTenista2 << endl;

					cout << "////////////////////////" << endl;

					cout << endl;

					if (Puntuacion1 == 5) {
						Victoria1 = true;
					}

					if (Puntuacion2 == 5) {
						Victoria2 = true;
					}

					PosicionBola = 4, PosicionTenista1 = 4, PosicionTenista2 = 4;

				}

			}

			if (num == 1) {

				system("pause");

				cout << "Golpea " << NombreTenista2 << endl;

				PosicionBola = GolpeoBola(PosicionTenista2, HabilidadTenista2);

				cout << "La bola es lanzada hasta la calle numero " << PosicionBola << endl;

				PosicionTenista1 = CorreTenista(PosicionTenista1, VelocidadTenista1, PosicionBola);

				if ((PosicionBola < 1) || (PosicionBola > 7)) {

					cout << "Manda la bola fuera de la pista, gana " << NombreTenista1 << endl;

					if ((Puntuacion1 == 4) && (Puntuacion2 == 3)) {

						Puntuacion1 = Puntuacion1 + 1;
						Victoria1 = true;
					}
					else if ((Puntuacion2 == 4) && (Puntuacion1 == 3)) {

						Puntuacion2 = 3;
						Puntuacion1 = 3;
					}
					else if ((Puntuacion1 == 4) && (Puntuacion2 < 3)) {

						Puntuacion1 = Puntuacion1 + 1;
						Victoria1 = true;
					}
					else {

						Puntuacion1 = Puntuacion1 + 1;

						GanarPunto1 = true;
					}
				}

				if ((PosicionTenista1 != PosicionBola) && ((PosicionBola >= 1) && (PosicionBola <= 7))) {

					cout << "No llega a tiempo para devolver el golpeo y pierde el punto." << endl;

					if ((Puntuacion1 == 4) && (Puntuacion2 == 3)) {

						Puntuacion1 = 3;
						Puntuacion2 = 3;
					}
					else if ((Puntuacion2 == 4) && (Puntuacion1 == 3)) {

						Puntuacion2 = Puntuacion2 + 1;
						Victoria2 = true;
					}
					else if ((Puntuacion2 == 4) && (Puntuacion1 < 3)) {

						Puntuacion2 = Puntuacion2 + 1;
						Victoria2 = true;
					}
					else {

						Puntuacion2 = Puntuacion2 + 1;

						GanarPunto2 = true;
					}
				}
				else {

					cout << "Alcanza la bola y devuelve el golpeo." << endl;
				}

				if ((GanarPunto1 == true) || (GanarPunto2 == true)) {

					cout << endl;

					cout << "/////// MARCADOR ///////" << endl;

					cout << NombreTenista1 << " // " << Marcador(Puntuacion1) << " - " << Marcador(Puntuacion2) << " // " << NombreTenista2 << endl;

					cout << "////////////////////////" << endl;

					cout << endl;

					if (Puntuacion1 == 5) {
						Victoria1 = true;
					}

					if (Puntuacion2 == 5) {
						Victoria2 = true;
					}

					PosicionBola = 4, PosicionTenista1 = 4, PosicionTenista2 = 4;

				}

				system("pause");

				cout << "Golpea " << NombreTenista1 << endl;

				PosicionBola = GolpeoBola(PosicionTenista1, HabilidadTenista1);

				PosicionTenista2 = CorreTenista(PosicionTenista2, VelocidadTenista2, PosicionBola);

				if ((PosicionBola < 1) || (PosicionBola > 7)) {

					cout << "Manda la bola fuera de la pista, gana " << NombreTenista2 << endl;

					if ((Puntuacion1 == 4) && (Puntuacion2 == 3)) {

						Puntuacion1 = 3;
						Puntuacion2 = 3;
					}
					else if ((Puntuacion2 == 4) && (Puntuacion1 == 3)) {

						Puntuacion2 = Puntuacion2 + 1;
						Victoria2 = true;
					}
					else if ((Puntuacion2 == 4) && (Puntuacion1 < 3)) {

						Puntuacion2 = Puntuacion2 + 1;
						Victoria2 = true;
					}
					else {

						Puntuacion2 = Puntuacion2 + 1;

						GanarPunto2 = true;
					}
				}

				if ((PosicionTenista2 != PosicionBola) && ((PosicionBola >= 1) && (PosicionBola <= 7))) {

					cout << "No llega a tiempo para devolver el golpeo y pierde el punto." << endl;

					if ((Puntuacion1 == 4) && (Puntuacion2 == 3)) {

						Puntuacion1 = Puntuacion1 + 1;
						Victoria1 = true;
					}
					else if ((Puntuacion2 == 4) && (Puntuacion1 == 3)) {

						Puntuacion2 = 3;
						Puntuacion1 = 3;
					}
					else if ((Puntuacion1 == 4) && (Puntuacion2 < 3)) {

						Puntuacion1 = Puntuacion1 + 1;
						Victoria1 = true;
					}
					else {

						Puntuacion1 = Puntuacion1 + 1;

						GanarPunto1 = true;
					}

				}
				else {

					cout << "Alcanza la bola y devuelve el golpeo." << endl;


				}

				if ((GanarPunto1 == true) || (GanarPunto2 == true)) {

					cout << endl;

					cout << "/////// MARCADOR ///////" << endl;

					cout << NombreTenista1 << " // " << Marcador(Puntuacion1) << " - " << Marcador(Puntuacion2) << " // " << NombreTenista2 << endl;

					cout << "////////////////////////" << endl;

					cout << endl;

					if (Puntuacion1 == 5) {
						Victoria1 = true;
					}

					if (Puntuacion2 == 5) {
						Victoria2 = true;
					}

					PosicionBola = 4, PosicionTenista1 = 4, PosicionTenista2 = 4;

				}

			}
		}
	}

	if ((Victoria1 == true) || (Victoria2 == true)) {

		if (Victoria1 == true) {

			cout << "Acaba el partido y se lleva la victoria " << NombreTenista1 << "." << endl;

		}

		if (Victoria2 == true) {

			cout << "Acaba el partido y se lleva la victoria " << NombreTenista2 << "." << endl;

		}
	}

	return 0;
}

//-------FUNCIONES A IMPLEMENTAR EN LA MAIN-------//

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

int GolpeoBola(int PosicionTenista, int HabilidadTenista) {

	int  ProbabilidadAcierto, PosicionBola;

	if (JuegoAleatorio == false) {

		srand(time(NULL));

		PosicionBola = rand() % 9;

		if (abs(PosicionBola - PosicionTenista) <= HabilidadTenista) {

			cout << "La bola llega hasta esa posicion sin problemas." << endl;

		}
		if (abs(PosicionBola - PosicionTenista) > HabilidadTenista) {

			ProbabilidadAcierto = 100 - (((abs(PosicionBola - PosicionTenista) - HabilidadTenista) * 100) / ((AnchoPista - 1) - LimInfHab));

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

		cout << "A que calle golpea la bola ? : " << endl;
		cin >> PosicionBola;

		if ((PosicionBola <= 0) || (PosicionBola >= 8)) {
		}
		else {

			if (abs(PosicionBola - PosicionTenista) <= HabilidadTenista) {

				cout << " La bola llega hasta esa posicion sin problemas." << endl;

			}
			if (abs(PosicionBola - PosicionTenista) > HabilidadTenista) {

				ProbabilidadAcierto = 100 - (((abs(PosicionBola - PosicionTenista) - HabilidadTenista) * 100) / ((AnchoPista - 1) - LimInfHab));

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
	}

	return PosicionBola;
}

string Marcador(int puntuacion) {

	string marcador;

	switch (puntuacion) {

	case 0: marcador = "00";
		break;

	case 1: marcador = "15";
		break;

	case 2: marcador = "30";
		break;

	case 3: marcador = "40";
		break;

	case 4: marcador = "Ad";
		break;

	case 5: marcador = "WIN";
		break;
	}

	return marcador;
}

int CorreTenista(int PosicionTenista, int VelocidadTenista, int PosicionBola) {

	if (abs(PosicionTenista - PosicionBola) <= VelocidadTenista) {


		if (PosicionTenista - PosicionBola < 0) {

			PosicionTenista = PosicionTenista + abs(PosicionTenista - PosicionBola);

		}

		if (PosicionTenista - PosicionBola > 0) {

			PosicionTenista = PosicionTenista - abs(PosicionTenista - PosicionBola);

		}

	}

	if (abs(PosicionTenista - PosicionBola) > VelocidadTenista) {

		if (PosicionTenista - PosicionBola < 0) {

			PosicionTenista = PosicionTenista + VelocidadTenista;

		}

		if (PosicionTenista - PosicionBola > 0) {

			PosicionTenista = PosicionTenista - VelocidadTenista;

		}

	}

	return PosicionTenista;

}