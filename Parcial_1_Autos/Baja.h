#ifndef BAJA_H_INCLUDED
#define BAJA_H_INCLUDED

/** \brief busca un auto por el id
 *
 * \param lista[] eAuto
 * \param tam int
 * \param id int
 * \return int
 *
 */
int buscarAutoId(eAuto lista[], int tam, int id);

/** \brief da de baja un auto
 *
 * \param lista[] eAuto
 * \param vecMarcas[] eMarca
 * \param vecColores[] eColor
 * \param tam int
 * \param tamMarcas int
 * \param tamColores int
 * \return int
 *
 */
int bajaAuto(eAuto lista[], eMarca vecMarcas[], eColor vecColores[], int tam, int tamMarcas, int tamColores);


#endif
