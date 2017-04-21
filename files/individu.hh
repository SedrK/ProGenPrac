/** @file individu.hh
 @brief Especificación de la clase individu
 */

#ifndef INDIVIDU_HH
#define INDIVIDU_HH



#include "especie.hh"
#include "Excepcio.hh"
//#include "parell_cromosoma.hh"

#ifndef NO_DIAGRAM 
#include <iostream>
#include <list>
#endif

/** @class individu
 @brief Representa un individuo.

 Contiene la informacion de un individuo (nombre, sexo, codigo genetico y padres) de la especie de su poblacion. Puede usarse para realizar experimentos con un solo individuo.*/

class individu
{

private:

	string NOM;
	vector<pair<list<int>, list<int>>> COD_GEN ;
	especie EspInd;
	char sex1 = 'X';
	char sex2;
	string SEXE;
	bool amb_pare;
	individu* PARE;
	bool amb_mare;
	individu* MARE;

public:

	//Constructores

	/** @brief Creadora por defecto.
	 Se ejecuta automáticamente al declarar una poblacion.
	 \pre <em>cierto</em>
	 \post El resultado es una individuo sin especie , sin nombre ni codigo genetico ni padres.
	 \coste Constante */
	individu();

	/** @brief Creadora por defecto.
	 Se ejecuta automáticamente al declarar una poblacion.
	 \pre <em>cierto</em>
	 \post El resultado es una individuo con especie esp, sin nombre ni codigo genetico ni padres.
	 \coste Constante */
	individu(especie esp);

	/** @brief Destructora por defecto.
	 \pre <em>cierto</em>
	 \post Se destruye el individuo
	 \coste Constante  */
	~individu();

	//Modificadores

	/** @brief Añade la especie al individuo
	 \pre <em>El p.i. no tiene especie</em>
	 \post El parámetro implícito pasa a ser de la especie esp
	 \coste Constante */
	void afegir_especie(const especie& esp);

	//Consultores

	/** @brief Consulta el nombre del individuo.
	 \pre <em>El p.i. tiene nombre</em>
	 \post El resultado es el nombre del individuo
	 \coste Constante  */
	string consultar_NOM() const;

	/** @brief Consulta el sexo del individuo.
	 \pre <em>El p.i. tiene sexo</em>
	 \post El resultado es el sexo del individuo
	 \coste Constante  */
	string consultar_SEXE() const;

	/** @brief Consulta si tiene madre el individuo.
	 \pre <em>cierto</em>
	 \post El resultado es true si tiene padre
	 \coste Constante  */
	bool te_pare() const;

	/** @brief Consulta el padre del individuo.
	 \pre <em>El p.i. tiene padre</em>
	 \post El resultado el individuo padre del p.i.
	 \coste Constante  */
	individu consultar_PARE() const;

	/** @brief Consulta sie tiene madre el individuo.
	 \pre <em>cierto</em>
	 \post El resultado es true si tiene madre
	 \coste Constante  */
	bool te_mare() const;

	/** @brief Consulta la madre del individuo.
	 \pre <em>El p.i. tiene madre</em>
	 \post El resultado el individuo madre del p.i.
	 \coste Constante  */
	individu consultar_MARE() const;

	// Lectura i escriptura

	/** @brief Operación de lectura.
	 \pre <em>Estan preparados en el canal estandar de entrada el cromosomas sexual Y y su codigo genetico</em>
	 \post Lee un conjunto de individuos por el canal estándar de entrada
	 \coste */
	void llegir();

	/** @brief Operación de escritura.
	 \pre <em>cierto</em>
	 \post Escribe el nombre, los cromosomas sexuales y los padres (si tiene) del parámetro implícito por el canal estándar de salida
	 \coste */
	void escriure() const;

	/** @brief Operación de escritura.
	 \pre <em>Existe un individuo con el nombre ind en la poblacion</em>
	 \post Escribe el nombre, y su codigo genetico por el canal estándar de salida
	 \coste */
	void escriure_particular() const;

};
#endif
