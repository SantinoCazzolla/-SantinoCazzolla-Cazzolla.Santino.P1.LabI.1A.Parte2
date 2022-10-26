#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

/** \brief Muestra los auto del color seleccionado
 *
 * \param autos[] eAuto
 * \param tamA int
 * \param colores[] eColor
 * \param tamC int
 * \param marcas[] eMarca
 * \param tamM int
 * \return int
 *
 */
int mostrarAutosColorSelec(eAuto autos[],int tamA, eColor colores[],int tamC, eMarca marcas[],int tamM);

/** \brief Muestra los auto de la marca seleccionada
 *
 * \param autos[] eAuto
 * \param tamA int
 * \param colores[] eColor
 * \param tamC int
 * \param marcas[] eMarca
 * \param tamM int
 * \return int
 *
 */
int mostrarAutosMarcaSelec(eAuto autos[],int tamA, eColor colores[],int tamC, eMarca marcas[],int tamM);

/** \brief muestra el porsentaje de las cajas
 *
 * \param autos[] eAuto
 * \param tamA int
 * \param colores[] eColor
 * \param tamC int
 * \param marcas[] eMarca
 * \param tamM int
 * \return int
 *
 */
int mostrarPorsentajeDeCajas(eAuto autos[],int tamA, eColor colores[],int tamC, eMarca marcas[],int tamM);

/** \brief mustra los autos separados por cajas
 *
 * \param autos[] eAuto
 * \param tamA int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \return int
 *
 */
int mostrarPorCaja(eAuto autos[], int tamA ,eMarca marcas[],int tamM, eColor colores[],int tamC);

/** \brief
 *
 * \param autos[] eAuto
 * \param tamA int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \return int
 *
 */
int contarMarcaYColor(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);

/** \brief muestra la o las marcas mas elegidas
 *
 * \param autos[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \return int
 *
 */
int marcaMasElegida(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC);
#endif // INFORMES_H_INCLUDED
