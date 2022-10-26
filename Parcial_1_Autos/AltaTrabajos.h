#ifndef ALTATRABAJOS_H_INCLUDED
#define ALTATRABAJOS_H_INCLUDED

/** \brief Inicializa trabajos
 *
 * \param listaTrabajo[] eTrabajo
 * \param tam int
 * \return int
 *
 */
int inicializarTrabajos(eTrabajo listaTrabajo[], int tam);

/** \brief Busca espacio libre para dar de alta el trabajo
 *
 * \param listaTrabajo[] eTrabajo
 * \param tam int
 * \return int
 *
 */
int buscarLibreTrabajos(eTrabajo listaTrabajo[], int tam);

/** \brief Carga los datos necesarios para la alta de trabajo
 *
 * \param pTrabajo eTrabajo*
 * \param vecAutos[] eAuto
 * \param vecMarcas[] eMarca
 * \param vecColores[] eColor
 * \param vecServicio[] eServicio
 * \param vecFecha[] eFecha
 * \param tamMarcas int
 * \param tamAutos int
 * \param tamServicios int
 * \param tamColores int
 * \return int
 *
 */
int cargarTrabajo(eTrabajo* pTrabajo, eAuto vecAutos[], eMarca vecMarcas[], eColor vecColores[], eServicio vecServicio[], eFecha vecFecha[], int tamMarcas,  int tamAutos, int tamServicios, int tamColores);

/** \brief da de alta los datos de trabajo
 *
 * \param pIdTrabajo int*
 * \param vecTrabajo[] eTrabajo
 * \param vecAutos[] eAuto
 * \param vecMarcas[] eMarca
 * \param vecColores[] eColor
 * \param vecServicio[] eServicio
 * \param vecFecha[] eFecha
 * \param tamMarcas int
 * \param tamColores int
 * \param tamTrabajos int
 * \param tamServicios int
 * \param tamAutos int
 * \param tamFecha int
 * \return int
 *
 */
int altaTrabajos(int* pIdTrabajo, eTrabajo vecTrabajo[], eAuto vecAutos[], eMarca vecMarcas[], eColor vecColores[], eServicio vecServicio[], eFecha vecFecha[],  int tamMarcas, int tamColores,  int tamTrabajos, int tamServicios, int tamAutos, int tamFecha);

/** \brief Harcodeo de trabajos
 *
 * \param pId int*
 * \param vec[] eTrabajo
 * \param tam int
 * \param cant int
 * \return int
 *
 */
int hardcodearTrabajos(int* pId ,eTrabajo vec[], int tam, int cant);

#endif
