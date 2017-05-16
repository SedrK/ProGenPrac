/**
 * @mainpage Ejemplo de diseño modular: Practica PRO2: Experimentos genéticos en laboratorio.

 Se ha construido un programa modular que ofrece un menú de opciones para realizar un experiemento genetico. Se introducen las clases <em>especie</em>, <em>poblacio</em> y <em>individu</em>.
*/

/** @file main.cc
 @brief Programa principal para la practica <em>Experimentos genéticos en laboratorio</em>.
 */

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hh de la documentación de las clases ocurre lo mismo.
#include "especie.hh"
#include "poblacio.hh"
#include "individu.hh"
#include "arbre_parcial.hh"
#include "parametres_repro.hh"

#ifndef NO_DIAGRAM
#include "Arbre.hh"
#include <iostream>
#include <string>
//#include "Arbre.hh"
#endif

/** @brief Programa principal para la practica <em>Experimentos genéticos en laboratorio</em>.
 */

using namespace std;

int main()
{
	especie esp;
	esp.llegir();
	poblacio POBL;
	POBL.llegir(esp);

	string comando;

	while (cin >> comando)
	{
		if (comando == "anadir_individuo")
		{
			individu ind;
			string nom;
			cin >> nom;
			ind.llegir(esp);

			cout << "anadir_individuo " << nom << endl;

			if (not POBL.existeix_individu(nom)) POBL.afegir_individu(nom, ind);
			else cout << "  error" << endl;
		}

		else if(comando == "escribir_poblacion")
		{
			cout << "escribir_poblacion" << endl;
			POBL.escriure();
		}

		else if(comando == "escribir_genotipo")
		{
			string nom;
			cin >> nom;
			cout << "escribir_genotipo " << nom << endl;
			
			if (POBL.existeix_individu(nom))
			{
				individu ind = POBL.individu_nom(nom);
				ind.escriure();
			}
			else cout << "  error" << endl;

		}


		else if(comando == "reproduccion_sexual")
		{
			string a, b, c;
			cin >> a >> b >> c;

			cout << "reproduccion_sexual " << a << ' ' << b << ' '<< c << endl;

			par_rep pt(esp);
			pt.llegir_parametres_reproduccio();

			if (POBL.existeix_individu(a) and POBL.existeix_individu(b) and not POBL.existeix_individu(c))
			{
				if (POBL.compatibles(a,b))
				{
					individu fill(pt, POBL.individu_nom(a),POBL.individu_nom(b));
					POBL.afegir_individu(c, fill);
					POBL.afegir_pares(a, b, c);
				}
				else cout << "  no es posible reproduccion" << endl;

			}
			else cout << "  error" << endl;
		}
		else if(comando == "escribir_arbol_genealogico")
		{
			string nom;
			cin >> nom;
			cout << "escribir_arbol_genealogico " << nom << endl;
		
			if (POBL.existeix_individu(nom)) POBL.escriure_arbre_genealogic(nom);
			else cout << "  error" << endl;
		}







		else if(comando == "completar_arbol_genealogico")
		{
			ArbreP apr;
			apr.llegir();
			cout << "completar_arbol_genealogico " << apr.consultar_arrel() << endl;

			if (POBL.existeix_individu(apr.consultar_arrel()))
			{
				ArbreP apr;
/*
				if (apr.completar_ap(ag)) apr.escriure();
				else cout << "  no es arbol parcial" << endl;
 */
			}
			else cout << "  error"<< endl;



			apr.escriure();
			cout << endl;
		}




		/*
		else if(comando == "completar_arbol_genealogico")
		{
			string nom;
			cin >> nom;	
			cout << "completar_arbol_genealogico " << nom << endl;
			ArbreP ap;
			ap.llegir(); //preordre

			if (POBL.existeix_individu(nom))
			{
				ArbreP apr;
				if (apr.completar_ap(ap)) apr.escriure();
				else cout << "  no es arbol parcial" << endl;
			}
			else cout << "  error" << endl;


			ap.escriure();
		}
		*/
		
		else if(comando == "acabar")
		{
			cout << "acabar";
			return 0;
		}

	}
}
