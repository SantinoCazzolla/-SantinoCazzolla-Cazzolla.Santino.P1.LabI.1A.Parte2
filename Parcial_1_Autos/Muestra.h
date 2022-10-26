#ifndef MUESTRA_H_INCLUDED
#define MUESTRA_H_INCLUDED

/** \brief Muestra menu de inicio
 *
 * \return void
 *
 */
void menuInicio();

/** \brief Ingreso de opcion de menu de inicio
 *
 * \return char
 *
 */
char ingresoDeOpcionMenuPricipal();

/** \brief confirmacion de salida del programa
 *
 * \param respuesta char*
 * \return int
 *
 */
int confirmacionSalida(char* respuesta);

/** \brief muestra el error al inicializar
 *
 * \return void
 *
 */
void errorAlInicializar();

/** \brief muestra un auto
 *
 * \param autos eAuto
 * \param marcas[] eMarca
 * \param colores[] eColor
 * \param tamMarcas int
 * \param tamColores int
 * \return int
 *
 */
int mostrarAuto(eAuto autos, eMarca marcas[], eColor colores[], int tamMarcas, int tamColores);

/** \brief recorre el for mostrando todos los autos
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
int mostrarAutos(eAuto lista[], eMarca vecMarcas[], eColor vecColores[], int tam, int tamMarcas, int tamColores);

/** \brief muestra las marcas
 *
 * \param vec[] eMarca
 * \param tam int
 * \return int
 *
 */
int mostrarMarcas(eMarca vec[], int tam);

/** \brief muestra los colores
 *
 * \param vec[] eColor
 * \param tam int
 * \return int
 *
 */
int mostrarColores(eColor vec[], int tam);

/** \brief muestra los Servicios
 *
 * \param vec[] eServicio
 * \param tam int
 * \return int
 *
 */
int mostrarServicios(eServicio vec[], int tam);

/** \brief muestra Submenu modificar
 *
 * \return char
 *
 */
char subMenuModificar();

/** \brief muestra las marcas por nombre
 *
 * \param idMarcas int
 * \param descripcion[] char
 * \param vec[] eMarca
 * \param tam int
 * \return int
 *
 */
int cargarDescripcionMarca(int idMarcas, char descripcion[], eMarca vec[], int tam);

/** \brief muestra los colores por nombre
 *
 * \param idColores int
 * \param descripcion[] char
 * \param vec[] eColor
 * \param tam int
 * \return int
 *
 */
int cargarDescripcionColores(int idColores, char descripcion[], eColor vec[], int tam);

/** \brief muestra los servicios por nombre
 *
 * \param idServicios int
 * \param descripcion[] char
 * \param vec[] eServicio
 * \param tam int
 * \return int
 *
 */
int cargarDescripcionServicios(int idServicios, char descripcion[], eServicio vec[], int tam);

/** \brief muestra un trabajo
 *
 * \param autos eAuto
 * \param trabajos[] eTrabajo
 * \param marcas[] eMarca
 * \param servicios[] eServicio
 * \param fechas[] eFecha
 * \param tamMarcas int
 * \param tamServicios int
 * \param tamFechas int
 * \return int
 *
 */
int mostrarTrabajo(eAuto autos, eTrabajo trabajos[]  ,eMarca marcas[], eServicio servicios[], eFecha fechas[], int tamMarcas, int tamServicios, int tamFechas);

/** \brief recorre el for mostrando todos los trabajos
 *
 * \return int
 *
 */
int mostrarTrabajos();

#endif
