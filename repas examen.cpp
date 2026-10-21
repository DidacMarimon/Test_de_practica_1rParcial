#include <iostream>
#include <string>
using namespace std;

class SubscripcioStreaming {
private:

	string nomPla;
	int dispositiusMaxim;
	int dispositiusActius;
	double horesReproduides;
	bool activa;

	void cancel·larSubscripcio() {

		activa = false;
		dispositiusActius = 0;
	}

public:

	SubscripcioStreaming() //Constructor per defecte

		:nomPla("Basic"),
		dispositiusMaxim(1),
		dispositiusActius(0),
		horesReproduides(0.0),
		activa(true) {
	}

	explicit SubscripcioStreaming(string nom) //Constructor parametritzat d'1 paràmetre

		:nomPla(nom),
		dispositiusMaxim(2),
		dispositiusActius(0),
		horesReproduides(0.0),
		activa(true) {
	}

	SubscripcioStreaming(string nom, int dispMax) //Constructor parametritzat complet

		:nomPla(nom),
		dispositiusMaxim(dispMax <= 0 ? dispMax : 1),
		dispositiusActius(0),
		horesReproduides(0.0),
		activa(true) {
	}

	string getNomPla() const {

		return nomPla;
	}

	int getDispositiusActius() const {

		return dispositiusMaxim;
	}

	int getHoresReproduides() const {

		return horesReproduides;
	}

	bool isActiva() const {

		if (activa == true) {

			return activa;
		}
	}

	bool connectarDispositiu() {

		if (activa == true && dispositiusActius < dispositiusMaxim) {

			dispositiusActius = dispositiusActius + 1;
			cout << "Dispositiu conectat" << endl; 
			return true;
		}
		else {

			cout << "ERROR AL CONECTARSE" << endl;
			return false;
		}
	}

	void desconnectarDispositiu() {

		if (dispositiusActius > 0) {

			dispositiusActius = dispositiusActius - 1;
			cout << "Sha desconectat un dispositiu" << endl; 
		}
	}

	void registrarReproduccio(double hores) {

		if (activa = true && dispositiusActius > 0 && horesReproduides >= 0) {

			horesReproduides = horesReproduides + hores;
		}
	}

	~SubscripcioStreaming() {

		if (activa == true) {

			while (dispositiusActius > 0) {

				desconnectarDispositiu(); 
			}

			cancel·larSubscripcio();
			cout << "La suscripccio del pla " << nomPla << " sha tencat automaticament en sorti dambit" << endl;
		}
	}
};

int main() {

	{
		SubscripcioStreaming s1("Familiar"); 

		cout << "El teu pla es: " << s1.getNomPla() << endl; 

		s1.connectarDispositiu(); 
		s1.connectarDispositiu();
		s1.connectarDispositiu();

		s1.registrarReproduccio(12);

		cout << "hores de reproduccio actuals: " << s1.getHoresReproduides() << endl;

		if (s1.isActiva()) {

			cout << "la sessio esta activa" << endl; 
		}
	}

	cout << "fi del programa"; 
}
