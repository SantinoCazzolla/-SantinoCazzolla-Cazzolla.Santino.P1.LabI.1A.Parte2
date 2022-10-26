#ifndef ALTAAUTOS_H_INCLUDED
#define ALTAAUTOS_H_INCLUDED
#include "EstructurasAutos.h"
/*
typedef struct
{
	int id;
	char nombre[20];
	char sexo;
	int isEmpty;
}eCliente;
*/

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int id;
	char descripcion[20];
}eMarca;

typedef struct
{
	int id;
	char nombreColor[20];
}eColor;

typedef struct
{
	int id;
	int idMarca;
	int idColor;
	char caja;
	int isEmpty;
}eAuto;

typedef struct
{
	int id;//comienza en 20 000
	char descripcion[20];
	int precio;
}eServicio;

typedef struct
{
	int id;//autoincremental
	int patente;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eTrabajo;


/** \brief Inicializa autos
 *
 * \param vecAuto[] eAuto
 * \param tam int
 * \return int
 *
 */
int inicializarAutos(eAuto vecAuto[], int tam);

/** \brief Busca espacio libre
 *
 * \param vecAuto[] eAuto
 * \param tam int
 * \return int
 *
 */
int buscarLibreAutos(eAuto vecAuto[], int tam);

/** \brief Carga los datos necesarios para la alta de auto
 *
 * \param pAuto eAuto*
 * \param vecMarcas[] eMarca
 * \param vecColores[] eColor
 * \param tamAutos int
 * \param tamMarcas int
 * \param tamColores int
 * \return int
 *
 */
int cargarAuto(eAuto * pAuto, eMarca vecMarcas[], eColor vecColores[], int tamAutos, int tamMarcas, int tamColores );

/** \brief da de alta los datos de auto
 *
 * \param pIdAuto int*
 * \param vecAuto[] eAuto
 * \param vecMarcas[] eMarca
 * \param vecColores[] eColor
 * \param tamAutos int
 * \param tamMarcas int
 * \param tamColores int
 * \return int
 *
 */
int altaAutos(int* pIdAuto, eAuto vecAuto[], eMarca vecMarcas[], eColor vecColores[], int tamAutos, int tamMarcas, int tamColores);

/** \brief harcodeo de autos
 *
 * \param pId int*
 * \param vec[] eAuto
 * \param tam int
 * \param cant int
 * \return int
 *
 */
int hardcodearAutos(int* pId ,eAuto vec[], int tam, int cant);

//int hardcodearClientes(int* pId , int tam, int cant);

#endif
