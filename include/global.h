/* global.h - Definitions et constantes globales du compilateur */

#ifndef GLOBAL_H
#define GLOBAL_H


/* -- Version du compilateur -- */
#define LGLO_VERSION  "1.0.0"
#define LGLO_NOM      "LGLo Compiler"


/* -- Limites -- */
#define MAX_NOM         256   /* longueur maximale d'un identifiant            */
#define MAX_PORTEE       32   /* profondeur maximale d'imbrication des blocs   */
#define MAX_PARAMS       64   /* nombre maximal de parametres par fonction     */


/* -- Codes de retour -- */
#define LGLO_OK          0
#define LGLO_ERR_LEX    -1
#define LGLO_ERR_SYN    -2
#define LGLO_ERR_SEM    -3


#endif