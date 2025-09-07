/************** -*-C-*- *********************************************
 * $Id$
 *                                                                  *
 *       AMESim C code for cosimulation written by code generator.  *

                                 exp9_
 *
 *******************************************************************/

#include "exp9_.h"
#include "ame_interfaces.h"

#include <assert.h>
#include <stdio.h>

#if !defined(AME_DS1006)
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#endif

#ifndef AME_DS1006
#include <fcntl.h>
#endif

#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <setjmp.h>

#ifdef _WIN32
#ifndef WIN32
#define WIN32
#endif
#endif

#include "ameutils.h"
#include "codegen_ameutils_public.h"
#include "itf_amesubintf_public.h"

#if defined (WIN32) || defined(XPCMSVISUALC)
#include <io.h>
#elif !defined(AME_DS1006)
#include <unistd.h>
#endif

#if defined(_WINDOWS) || defined(_WIN32) || defined(WIN32)
#define DLLEXPORTDEF __declspec(dllexport)
#else
#define DLLEXPORTDEF
#endif

#if defined (RTLAB) || defined(AME_DS1006) ||  defined(AME_DS1007) || defined(LABCAR) || defined(AME_ADX) || defined(AME_HWA) || defined(RT) ||defined(AMEVERISTAND)
#ifdef DLLEXPORTDEF
#undef DLLEXPORTDEF
#endif
#define DLLEXPORTDEF
#endif

/* If we are in Simulink we should set things up for a AMEMULTIDLL (only static symbols) */
#if defined(AME_CS_SIMULINK) || defined(AME_ME_SIMULINK)
#ifndef AMEMULTIDLL
#define AMEMULTIDLL
#endif
#endif

/* If we are in Veristand we should set things up for a AMEMULTIDLL (only static symbols) */
#ifdef AMEVERISTAND
#ifndef AMEMULTIDLL
#define AMEMULTIDLL
#endif
#endif

/* avoid globally exported functions - required for exporting several models in one executable */
#if defined AMEMULTIDLL
#define DLLEXPORTDEF_OR_STATIC static
#else
#define DLLEXPORTDEF_OR_STATIC DLLEXPORTDEF
#endif

#if defined CREATING_STATIC_LIB
#define DLLEXPORTDEF_OR_EXTERN extern
#else
#define DLLEXPORTDEF_OR_EXTERN DLLEXPORTDEF
#endif

#define TIME_ROUNDOFF 1.0e-10
#define TLAST_MIN     -1E30

#if defined(FMICS1) || defined(FMICS2) || defined(FMICS3) || defined(FMIME1) || defined(FMIME2)
#ifdef FMIX
#undef FMIX
#endif
#define FMI
#define MODEL_IDENTIFIER         exp9_
#define MODEL_IDENTIFIER_STRING "exp9_"
#endif

/* *****************************************************************

   code inserted by AMESim

   *****************************************************************/

#define AMEVERSION                  202410000
#define SUB_LENGTH                  63

static const char soldToId[] = "46674455";

/**** Model structure definition ****/
/* Structural definition of the model */
#define AME_MODEL_ISEXPLICIT        1

/* Number of explicit declared states  */
#define AME_NBOF_EXPLICIT_STATE     4

/* Number of implicit declared states  */
#define AME_NBOF_IMPLICIT_STATE_DECLARED  0
#define AME_NBOF_IMPLICIT_STATE_GENERATED 0
#define AME_NBOF_IMPLICIT_STATE           0

/* Number of discrete declared states  */
#define AME_NBOF_DISCRETE_STATE     1

/* Total number of states manipulated by the Amesim solver including generated states */
#define AME_NBOF_SOLVER_STATES      4

#define AME_NBOF_PARAMS             205
#define AME_NBOF_REAL_PARAMS        76
#define AME_NBOF_INT_PARAMS         65
#define AME_NBOF_TEXT_PARAMS        53
#define AME_NBOF_CSTATE_PARAMS      4
#define AME_NBOF_DSTATE_PARAMS      1
#define AME_NBOF_FIXED_VAR_PARAMS   6

#define AME_NBOF_VARS               108
#define AME_NBOF_INPUTS             0
#define AME_NBOF_OUTPUTS            0

#define AME_NBOF_REAL_STORES        10
#define AME_NBOF_INT_STORES         15
#define AME_NBOF_POINTER_STORES     3

#define AME_SIZEOF_DBWORK_ARRAY     0

#define AME_NB_VAR_INFO             108

#define AME_NB_NETWORK              0

#define AME_NB_SUBMODEL_REF         21

static const S_AMEModelDef GmodelDef = {
   AME_MODEL_ISEXPLICIT,
   AME_NBOF_EXPLICIT_STATE,
   AME_NBOF_IMPLICIT_STATE_DECLARED,
   AME_NBOF_IMPLICIT_STATE_GENERATED,
   AME_NBOF_DISCRETE_STATE,
   AME_NBOF_VARS,
   AME_NBOF_PARAMS,
   AME_NBOF_REAL_PARAMS,
   AME_NBOF_INT_PARAMS,
   AME_NBOF_TEXT_PARAMS,
   AME_NBOF_CSTATE_PARAMS,
   AME_NBOF_DSTATE_PARAMS,
   AME_NBOF_FIXED_VAR_PARAMS,
   AME_NBOF_INPUTS,
   AME_NBOF_OUTPUTS,
   AME_NBOF_REAL_STORES,
   AME_NBOF_INT_STORES,
   AME_NBOF_POINTER_STORES,
   AME_SIZEOF_DBWORK_ARRAY,
   AME_NB_VAR_INFO,
   AME_NB_NETWORK,
   AME_NB_SUBMODEL_REF
};


static const char **GinputVarTitles = NULL;
static const char **GoutputVarTitles = NULL;

/**** Parameters structure definition ****/

#define NB_SUBMODELNAME       12
static const char* GsubmodelNameArray[NB_SUBMODELNAME] = {
     "THTS0 instance 1"
   , "THSD00 instance 1"
   , "THGCV0 instance 1"
   , "THC000 instance 1"
   , "STOP0 instance 1"
   , "SIGUDA01 instance 1"
   , "SIGUDA01 instance 2"
   , "ESSBATPA01 instance 1"
   , "EBZV01 instance 1"
   , "EBVT01 instance 1"
   , "THHF0 instance 1"
   , "EBL01 instance 1"
};

static const S_AMEParamInfo GParamInfo[205] = {
     {E_Real_Param           , E_Expression_Param, 0, -1, 0, 0}
   , {E_Real_Param           , E_Expression_Param, 1, -1, 0, 0}
   , {E_FixedVar_Param       , E_Expression_Param, 0, 1, 0, 0}
   , {E_Real_Param           , E_Expression_Param, 2, -1, 1, 0}
   , {E_Real_Param           , E_Expression_Param, 3, -1, 1, 0}
   , {E_Real_Param           , E_Expression_Param, 4, -1, 1, 0}
   , {E_Real_Param           , E_Expression_Param, 5, -1, 1, 0}
   , {E_Real_Param           , E_Expression_Param, 6, -1, 1, 0}
   , {E_Real_Param           , E_Expression_Param, 7, -1, 1, 0}
   , {E_Real_Param           , E_Expression_Param, 8, -1, 1, 0}
   , {E_Real_Param           , E_Expression_Param, 9, -1, 1, 0}
   , {E_Real_Param           , E_Expression_Param, 10, -1, 1, 0}
   , {E_Real_Param           , E_Expression_Param, 11, -1, 1, 0}
   , {E_Real_Param           , E_Expression_Param, 12, -1, 1, 0}
   , {E_Int_Param            , E_Expression_Param, 0, -1, 1, 0}
   , {E_Int_Param            , E_Expression_Param, 1, -1, 1, 0}
   , {E_Int_Param            , E_Expression_Param, 2, -1, 1, 0}
   , {E_Int_Param            , E_Expression_Param, 3, -1, 1, 0}
   , {E_Int_Param            , E_Expression_Param, 4, -1, 1, 0}
   , {E_Int_Param            , E_Expression_Param, 5, -1, 1, 0}
   , {E_Int_Param            , E_Expression_Param, 6, -1, 1, 0}
   , {E_Text_Param           , E_Expression_Param, 0, -1, 1, 0}
   , {E_Text_Param           , E_Expression_Param, 1, -1, 1, 0}
   , {E_Text_Param           , E_Expression_Param, 2, -1, 1, 0}
   , {E_Text_Param           , E_Expression_Param, 3, -1, 1, 0}
   , {E_Text_Param           , E_Expression_Param, 4, -1, 1, 0}
   , {E_Text_Param           , E_Expression_Param, 5, -1, 1, 0}
   , {E_Real_Param           , E_Expression_Param, 13, -1, 2, 0}
   , {E_Real_Param           , E_Expression_Param, 14, -1, 2, 0}
   , {E_Real_Param           , E_Expression_Param, 15, -1, 2, 0}
   , {E_Real_Param           , E_Expression_Param, 16, -1, 2, 0}
   , {E_Real_Param           , E_Expression_Param, 17, -1, 2, 0}
   , {E_Real_Param           , E_Expression_Param, 18, -1, 2, 0}
   , {E_Real_Param           , E_Expression_Param, 19, -1, 2, 0}
   , {E_Real_Param           , E_Expression_Param, 20, -1, 2, 0}
   , {E_Real_Param           , E_Expression_Param, 21, -1, 2, 0}
   , {E_Real_Param           , E_Expression_Param, 22, -1, 2, 0}
   , {E_Real_Param           , E_Expression_Param, 23, -1, 2, 0}
   , {E_Real_Param           , E_Expression_Param, 24, -1, 2, 0}
   , {E_Real_Param           , E_Expression_Param, 25, -1, 2, 0}
   , {E_Real_Param           , E_Expression_Param, 26, -1, 2, 0}
   , {E_Real_Param           , E_Expression_Param, 27, -1, 2, 0}
   , {E_Real_Param           , E_Expression_Param, 28, -1, 2, 0}
   , {E_Real_Param           , E_Expression_Param, 29, -1, 2, 0}
   , {E_Real_Param           , E_Expression_Param, 30, -1, 2, 0}
   , {E_Real_Param           , E_Expression_Param, 31, -1, 2, 0}
   , {E_Real_Param           , E_Expression_Param, 32, -1, 2, 0}
   , {E_Real_Param           , E_Expression_Param, 33, -1, 2, 0}
   , {E_Int_Param            , E_Expression_Param, 7, -1, 2, 0}
   , {E_Int_Param            , E_Expression_Param, 8, -1, 2, 0}
   , {E_Text_Param           , E_Expression_Param, 6, -1, 2, 0}
   , {E_Text_Param           , E_Expression_Param, 7, -1, 2, 0}
   , {E_Text_Param           , E_Expression_Param, 8, -1, 2, 0}
   , {E_Text_Param           , E_Expression_Param, 9, -1, 2, 0}
   , {E_Real_Param           , E_Expression_Param, 34, -1, 3, 0}
   , {E_Real_Param           , E_Expression_Param, 35, -1, 3, 0}
   , {E_Real_Param           , E_Expression_Param, 36, -1, 3, 0}
   , {E_Int_Param            , E_Expression_Param, 9, -1, 3, 0}
   , {E_Int_Param            , E_Expression_Param, 10, -1, 3, 0}
   , {E_Int_Param            , E_Expression_Param, 11, -1, 3, 0}
   , {E_ContinuousState_Param, E_Expression_Param, 0, 14, 3, 0}
   , {E_Int_Param            , E_Expression_Param, 12, -1, 4, 0}
   , {E_Int_Param            , E_Expression_Param, 13, -1, 4, 0}
   , {E_Int_Param            , E_Expression_Param, 14, -1, 4, 0}
   , {E_Int_Param            , E_Expression_Param, 15, -1, 4, 0}
   , {E_Text_Param           , E_Expression_Param, 10, -1, 4, 0}
   , {E_Text_Param           , E_Expression_Param, 11, -1, 4, 0}
   , {E_DiscreteState_Param  , E_Expression_Param, 0, 22, 4, 0}
   , {E_Real_Param           , E_Expression_Param, 37, -1, 5, 0}
   , {E_Real_Param           , E_Expression_Param, 38, -1, 5, 0}
   , {E_Int_Param            , E_Expression_Param, 16, -1, 5, 0}
   , {E_Int_Param            , E_Expression_Param, 17, -1, 5, 0}
   , {E_Int_Param            , E_Expression_Param, 18, -1, 5, 0}
   , {E_Int_Param            , E_Expression_Param, 19, -1, 5, 0}
   , {E_Int_Param            , E_Expression_Param, 20, -1, 5, 0}
   , {E_Int_Param            , E_Expression_Param, 21, -1, 5, 0}
   , {E_Int_Param            , E_Expression_Param, 22, -1, 5, 0}
   , {E_Int_Param            , E_Expression_Param, 23, -1, 5, 0}
   , {E_Int_Param            , E_Expression_Param, 24, -1, 5, 0}
   , {E_Int_Param            , E_Expression_Param, 25, -1, 5, 0}
   , {E_Text_Param           , E_Expression_Param, 12, -1, 5, 0}
   , {E_Real_Param           , E_Expression_Param, 39, -1, 6, 0}
   , {E_Real_Param           , E_Expression_Param, 40, -1, 6, 0}
   , {E_Int_Param            , E_Expression_Param, 26, -1, 6, 0}
   , {E_Int_Param            , E_Expression_Param, 27, -1, 6, 0}
   , {E_Int_Param            , E_Expression_Param, 28, -1, 6, 0}
   , {E_Int_Param            , E_Expression_Param, 29, -1, 6, 0}
   , {E_Int_Param            , E_Expression_Param, 30, -1, 6, 0}
   , {E_Int_Param            , E_Expression_Param, 31, -1, 6, 0}
   , {E_Int_Param            , E_Expression_Param, 32, -1, 6, 0}
   , {E_Int_Param            , E_Expression_Param, 33, -1, 6, 0}
   , {E_Int_Param            , E_Expression_Param, 34, -1, 6, 0}
   , {E_Int_Param            , E_Expression_Param, 35, -1, 6, 0}
   , {E_Text_Param           , E_Expression_Param, 13, -1, 6, 0}
   , {E_Real_Param           , E_Expression_Param, 41, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 42, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 43, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 44, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 45, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 46, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 47, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 48, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 49, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 50, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 51, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 52, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 53, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 54, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 55, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 56, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 57, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 58, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 59, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 60, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 61, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 62, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 63, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 64, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 65, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 66, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 67, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 68, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 69, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 70, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 71, -1, 7, 0}
   , {E_Real_Param           , E_Expression_Param, 72, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 36, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 37, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 38, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 39, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 40, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 41, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 42, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 43, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 44, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 45, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 46, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 47, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 48, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 49, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 50, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 51, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 52, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 53, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 54, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 55, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 56, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 57, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 58, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 59, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 60, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 61, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 62, -1, 7, 0}
   , {E_Int_Param            , E_Expression_Param, 63, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 14, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 15, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 16, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 17, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 18, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 19, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 20, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 21, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 22, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 23, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 24, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 25, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 26, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 27, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 28, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 29, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 30, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 31, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 32, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 33, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 34, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 35, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 36, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 37, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 38, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 39, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 40, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 41, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 42, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 43, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 44, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 45, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 46, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 47, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 48, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 49, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 50, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 51, -1, 7, 0}
   , {E_Text_Param           , E_Expression_Param, 52, -1, 7, 0}
   , {E_ContinuousState_Param, E_Expression_Param, 1, 31, 7, 0}
   , {E_ContinuousState_Param, E_Expression_Param, 2, 32, 7, 0}
   , {E_FixedVar_Param       , E_Expression_Param, 1, 93, 8, 0}
   , {E_Real_Param           , E_Expression_Param, 73, -1, 9, 0}
   , {E_Real_Param           , E_Expression_Param, 74, -1, 9, 0}
   , {E_Int_Param            , E_Expression_Param, 64, -1, 9, 0}
   , {E_FixedVar_Param       , E_Expression_Param, 2, 95, 9, 0}
   , {E_FixedVar_Param       , E_Expression_Param, 3, 97, 9, 0}
   , {E_FixedVar_Param       , E_Expression_Param, 4, 99, 9, 0}
   , {E_FixedVar_Param       , E_Expression_Param, 5, 13, 10, 0}
   , {E_Real_Param           , E_Expression_Param, 75, -1, 11, 0}
   , {E_ContinuousState_Param, E_Expression_Param, 3, 104, 11, 0}
};
#define NB_REAL_TUNABLE_PARAM 0
#define NB_INT_TUNABLE_PARAM 0

static const int GcontStateVarNum[AME_NBOF_EXPLICIT_STATE] = {
     14, 31, 32, 104
};

static const int GdiscStateVarNum[AME_NBOF_DSTATE_PARAMS] = {
     22
};

static const int *GInputVarNum = NULL;

static const double *GInputStartValues = NULL;

static const int *GOutputVarNum = NULL;

static const int GFixedVarNum[AME_NBOF_FIXED_VAR_PARAMS] = {
     1, 93, 95, 97, 99, 13
};

#define RP0 (&amesys->pModel->realParamArray[0])
#define RS1 (&amesys->pModel->realStoreArray[0])
#define IS1 (&amesys->pModel->intStoreArray[0])
#define RP1 (&amesys->pModel->realParamArray[2])
#define IP1 (&amesys->pModel->integerParamArray[0])
#define TP1 (&amesys->pModel->textParamArray[0])
#define RS2 (&amesys->pModel->realStoreArray[1])
#define IS2 (&amesys->pModel->intStoreArray[1])
#define RP2 (&amesys->pModel->realParamArray[13])
#define IP2 (&amesys->pModel->integerParamArray[7])
#define TP2 (&amesys->pModel->textParamArray[6])
#define IS3 (&amesys->pModel->intStoreArray[5])
#define PS3 (&amesys->pModel->pointerStoreArray[0])
#define RP3 (&amesys->pModel->realParamArray[34])
#define IP3 (&amesys->pModel->integerParamArray[9])
#define RS4 (&amesys->pModel->realStoreArray[7])
#define IS4 (&amesys->pModel->intStoreArray[6])
#define IP4 (&amesys->pModel->integerParamArray[12])
#define TP4 (&amesys->pModel->textParamArray[10])
#define IS9 (&amesys->pModel->intStoreArray[9])
#define RP9 (&amesys->pModel->realParamArray[37])
#define IP9 (&amesys->pModel->integerParamArray[16])
#define TP9 (&amesys->pModel->textParamArray[12])
#define IS10 (&amesys->pModel->intStoreArray[10])
#define RP10 (&amesys->pModel->realParamArray[39])
#define IP10 (&amesys->pModel->integerParamArray[26])
#define TP10 (&amesys->pModel->textParamArray[13])
#define RS11 (&amesys->pModel->realStoreArray[9])
#define IS11 (&amesys->pModel->intStoreArray[11])
#define PS11 (&amesys->pModel->pointerStoreArray[2])
#define RP11 (&amesys->pModel->realParamArray[41])
#define IP11 (&amesys->pModel->integerParamArray[36])
#define TP11 (&amesys->pModel->textParamArray[14])
#define RP13 (&amesys->pModel->realParamArray[73])
#define IP13 (&amesys->pModel->integerParamArray[64])
#define IS20 (&amesys->pModel->intStoreArray[13])
#define RP20 (&amesys->pModel->realParamArray[75])

static int SP9[1] = {1};
static int SP10[1] = {1};

static const S_AMEVariableInfo GVarInfo[AME_NB_VAR_INFO] = {
   { 0, 1, 1, 1, "THC000", "t3" }
  ,{ 1, 1, 1, 1, "THTS0", "dh1" }
  ,{ 2, 1, 1, 1, "THTS0", "outt" }
  ,{ 3, 1, 1, 1, "THSD00", "mtot" }
  ,{ 4, 1, 1, 1, "THSD00", "se" }
  ,{ 5, 1, 1, 1, "THC000", "t4" }
  ,{ 6, 1, 1, 1, "THGCV0", "dh1" }
  ,{ 7, 1, 1, 1, "THGCV0", "Re" }
  ,{ 8, 1, 1, 1, "THGCV0", "Pr" }
  ,{ 9, 1, 1, 1, "THGCV0", "Gr" }
  ,{ 10, 1, 1, 1, "THGCV0", "NuFree" }
  ,{ 11, 1, 1, 1, "THGCV0", "NuForced" }
  ,{ 12, 1, 1, 1, "THGCV0", "hconv" }
  ,{ 13, 1, 1, 1, "THHF0", "dh1" }
  ,{ 14, 1, 1, 1, "THC000", "t1" }
  ,{ 15, 1, 1, 1, "ESSBATPA01", "dh" }
  ,{ 16, 1, 1, 1, "THC000", "t2" }
  ,{ 17, 1, 1, 1, "THC000", "se" }
  ,{ 18, 0, 1, 1, "THC000", "powerCmass" }
  ,{ 19, 1, 1, 1, "THC000", "calcmass" }
  ,{ 20, 1, 1, 1, "THC000", "x" }
  ,{ 21, 1, 1, 1, "CLOC", "tout" }
  ,{ 22, 1, 1, 1, "STOP0", "xref" }
  ,{ 23, 1, 1, 1, "SIGUDA01", "u" }
  ,{ 24, 1, 1, 1, "EBVT01", "vsig" }
  ,{ 25, 0, 1, 1, "ESSBATPA01", "soc4" }
  ,{ 26, 1, 1, 2, "SIGUDA01", "u" }
  ,{ 27, 1, 1, 1, "EB3N01", "V3" }
  ,{ 28, 1, 1, 1, "ESSBATPA01", "I1" }
  ,{ 29, 1, 1, 1, "EB3N03", "I3" }
  ,{ 30, 1, 1, 1, "ESSBATPA01", "V2" }
  ,{ 31, 1, 1, 1, "ESSBATPA01", "soc" }
  ,{ 32, 1, 1, 1, "ESSBATPA01", "U" }
  ,{ 33, 1, 1, 1, "ESSBATPA01", "I" }
  ,{ 34, 1, 1, 1, "ESSBATPA01", "Ucell" }
  ,{ 35, 1, 1, 1, "ESSBATPA01", "Icell" }
  ,{ 36, 1, 1, 1, "ESSBATPA01", "Icellref" }
  ,{ 37, 1, 1, 1, "ESSBATPA01", "Radd" }
  ,{ 38, 1, 1, 1, "ESSBATPA01", "Q" }
  ,{ 39, 1, 1, 1, "ESSBATPA01", "faradeff" }
  ,{ 40, 1, 1, 1, "ESSBATPA01", "ocv" }
  ,{ 41, 1, 1, 1, "ESSBATPA01", "ocvc" }
  ,{ 42, 1, 1, 1, "ESSBATPA01", "ocvd" }
  ,{ 43, 1, 1, 1, "ESSBATPA01", "ocveq" }
  ,{ 44, 1, 1, 1, "ESSBATPA01", "dUdT" }
  ,{ 45, 1, 1, 1, "ESSBATPA01", "Rohm" }
  ,{ 46, 1, 1, 1, "ESSBATPA01", "Rohmc" }
  ,{ 47, 1, 1, 1, "ESSBATPA01", "Rohmd" }
  ,{ 48, 1, 1, 1, "ESSBATPA01", "Rct" }
  ,{ 49, 1, 1, 1, "ESSBATPA01", "Cct" }
  ,{ 50, 1, 1, 1, "ESSBATPA01", "dssr" }
  ,{ 51, 1, 1, 1, "ESSBATPA01", "dtc" }
  ,{ 52, 1, 1, 1, "ESSBATPA01", "rwlp" }
  ,{ 53, 1, 1, 1, "ESSBATPA01", "wlp" }
  ,{ 54, 1, 1, 1, "ESSBATPA01", "whp" }
  ,{ 55, 1, 1, 1, "ESSBATPA01", "dsohcvar" }
  ,{ 56, 1, 1, 1, "ESSBATPA01", "dsohrvar" }
  ,{ 57, 1, 1, 1, "ESSBATPA01", "ratioQ" }
  ,{ 58, 1, 1, 1, "ESSBATPA01", "ratioRohm" }
  ,{ 59, 1, 1, 1, "ESSBATPA01", "ratioRct" }
  ,{ 60, 1, 1, 1, "ESSBATPA01", "ratioRdiff" }
  ,{ 61, 1, 1, 1, "ESSBATPA01", "Bcal" }
  ,{ 62, 1, 1, 1, "ESSBATPA01", "zcal" }
  ,{ 63, 1, 1, 1, "ESSBATPA01", "Eacal" }
  ,{ 64, 1, 1, 1, "ESSBATPA01", "BcycA" }
  ,{ 65, 1, 1, 1, "ESSBATPA01", "BcycSR" }
  ,{ 66, 1, 1, 1, "ESSBATPA01", "alphacycSR" }
  ,{ 67, 1, 1, 1, "ESSBATPA01", "betacycSR" }
  ,{ 68, 1, 1, 1, "ESSBATPA01", "zcycSR" }
  ,{ 69, 1, 1, 1, "ESSBATPA01", "dQlossvar" }
  ,{ 70, 1, 1, 1, "ESSBATPA01", "drgainvar" }
  ,{ 71, 1, 1, 1, "ESSBATPA01", "deltaUadd" }
  ,{ 72, 1, 1, 1, "ESSBATPA01", "deltaUhyst" }
  ,{ 73, 1, 1, 1, "ESSBATPA01", "deltaUohm" }
  ,{ 74, 1, 1, 1, "ESSBATPA01", "deltaUct2" }
  ,{ 75, 1, 1, 1, "ESSBATPA01", "deltaUdifftotal" }
  ,{ 76, 1, 1, 1, "ESSBATPA01", "deltaUtotal" }
  ,{ 77, 1, 1, 1, "ESSBATPA01", "Phiadd" }
  ,{ 78, 1, 1, 1, "ESSBATPA01", "Phifaradeff" }
  ,{ 79, 1, 1, 1, "ESSBATPA01", "PhidUdT" }
  ,{ 80, 1, 1, 1, "ESSBATPA01", "Phihyst" }
  ,{ 81, 1, 1, 1, "ESSBATPA01", "Phiohm" }
  ,{ 82, 1, 1, 1, "ESSBATPA01", "Phict" }
  ,{ 83, 1, 1, 1, "ESSBATPA01", "Phidiff" }
  ,{ 84, 1, 1, 1, "ESSBATPA01", "imin" }
  ,{ 85, 1, 1, 1, "ESSBATPA01", "imax" }
  ,{ 86, 1, 1, 1, "ESSBATPA01", "umin" }
  ,{ 87, 1, 1, 1, "ESSBATPA01", "umax" }
  ,{ 88, 1, 1, 1, "ESSBATPA01", "Bcoef" }
  ,{ 89, 1, 1, 1, "ESSBATPA01", "zcoef" }
  ,{ 90, 0, 1, 1, "ESSBATPA01", "powerRSelec" }
  ,{ 91, 0, 1, 1, "ESSBATPA01", "powerCelec" }
  ,{ 92, 1, 1, 1, "EB3N01", "I1" }
  ,{ 93, 1, 1, 1, "EBZV01", "V1" }
  ,{ 94, 1, 1, 1, "EB3N02", "V1" }
  ,{ 95, 1, 1, 1, "EBVT01", "I1" }
  ,{ 96, 1, 1, 1, "EB3N03", "V1" }
  ,{ 97, 1, 1, 1, "EBVT01", "I3" }
  ,{ 98, 1, 1, 1, "EBVT01", "U" }
  ,{ 99, 1, 1, 1, "EBVT01", "I" }
  ,{ 100, 1, 1, 1, "EB3N02", "I2" }
  ,{ 101, 1, 1, 1, "EB3N01", "V2" }
  ,{ 102, 1, 1, 1, "EBL01", "I1" }
  ,{ 103, 1, 1, 1, "EB3N02", "V3" }
  ,{ 104, 1, 1, 1, "EBL01", "I" }
  ,{ 105, 1, 1, 1, "EB3N03", "V2" }
  ,{ 106, 1, 1, 1, "EBL01", "U" }
  ,{ 107, 0, 1, 1, "EBL01", "powerIelec" }
};

#if !defined(AME_IMPLICIT_MODEL_ACCEPTED) && (AME_MODEL_ISEXPLICIT == 0)
#error "Implicit model not supported for the current interface."
#endif


/* ============================================================== */
/* If the interface needs linearisation (cosim and Amesim) */

#ifndef AME_NO_LA
#ifndef AME_NEED_LINEAR_ANALYSIS
#define AME_NEED_LINEAR_ANALYSIS
#endif
#endif

#if( AME_MODEL_ISEXPLICIT == 1)
#define AMEfuncPerturb LPerturbIfNecessary
#else
#define AMEfuncPerturb DPerturbIfNecessary
#endif

#ifdef AME_ADVANCEDDEBUG
static void AME_POST_SUBMODCALL_WITH_DISCON(AMESIMSYSTEM *amesys, int *flag, int *sflag, int *oflag, int *panic, char *submodelname, int instancenum)
{
   if(*sflag < 3)*sflag = getnfg_();
#ifdef AME_NEED_LINEAR_ANALYSIS
   if(*flag == 5)
   {
      AMEfuncPerturb(amesys, flag);
   }
   else if(*oflag != 5)
   {
      resdis(amesys, flag, sflag, oflag, submodelname, instancenum, panic);
   }
#else
   resdis(amesys, flag, sflag, oflag, submodelname, instancenum, panic);
#endif
}

static void AME_POST_SUBMODCALL_NO_DISCON(AMESIMSYSTEM *amesys, int *flag)
{
#ifdef AME_NEED_LINEAR_ANALYSIS
   if(*flag == 5)
   {
      AMEfuncPerturb(amesys, flag);
   }
#endif
}
#endif


#ifndef AME_ADVANCEDDEBUG
#ifdef AME_NEED_LINEAR_ANALYSIS
/* Typically for normal runs and cosim */
#define AME_POST_SUBMODCALL_WITH_DISCON(amesys,flag,sflag,oflag,panic,submodelname,instancenum) if(*sflag < 3)*sflag = getnfg_(); if(*flag == 5) AMEfuncPerturb(amesys, flag); else if(*oflag != 5) resdis(amesys, flag, sflag, oflag, submodelname, instancenum, panic)
#define AME_POST_SUBMODCALL_NO_DISCON(amesys,flag) if(*flag == 5) AMEfuncPerturb(amesys, flag)
#else
/* Typically for code exchange (simulink for instance) */
#define AME_POST_SUBMODCALL_WITH_DISCON(amesys,flag,sflag,oflag,panic,submodelname,instancenum) if(*sflag < 3)*sflag = getnfg_(); resdis(amesys, flag, sflag, oflag,submodelname,instancenum,panic)
#define AME_POST_SUBMODCALL_NO_DISCON(amesys,flag)
#endif
#endif

#ifdef AMERT
/* We dont need LA nor resdis for real-time - so set them to (almost) empty macros. (reset sflag to orig value "oflag") */
#undef AME_POST_SUBMODCALL_WITH_DISCON
#undef AME_POST_SUBMODCALL_NO_DISCON
#define AME_POST_SUBMODCALL_WITH_DISCON(amesys,flag,sflag,oflag,panic,submodelname,instancenum) *sflag = *oflag
#define AME_POST_SUBMODCALL_NO_DISCON(amesys,flag)
#endif

/* ============================================================== */

#ifdef AMERT
double IL_exp9_step_ratio=0;
#endif

#ifdef AME_MEMORY_ACCESS_RT_EXPORT
/* For memory access in case of RT target such as dSpace targets */
#include "exp9_.export.h"

static void RT_Get_Watch_Var(AMESIMSYSTEM *amesys)
{
#if (NB_WATCH_VAR>0)
   int i;

   for(i=0; i<NB_WATCH_VAR; i++) {
      RT_Export_Vars[i] = amesys->v[RT_Watch_Vars_Idx[i]];
   }
#endif
}

static void RT_Get_Watch_Param(AMESIMSYSTEM *amesys)
{
#if (NB_WATCH_REAL_PARAM>0) || (NB_WATCH_INT_PARAM>0)
   int i;

   for(i=0; i<NB_WATCH_REAL_PARAM; i++) {
      RT_Export_RealParam[i] = amesys->pModel->realParamArray[RT_Watch_RP_Idx[i]];
   }
   for(i=0; i<NB_WATCH_INT_PARAM; i++) {
      RT_Export_IntParam[i] = amesys->pModel->integerParamArray[RT_Watch_IP_Idx[i]];
   }
#endif
}

static void RT_Set_Watch_Param(AMESIMSYSTEM *amesys)
{
#if (NB_WATCH_REAL_PARAM>0) || (NB_WATCH_INT_PARAM>0)
   int i;

   for(i=0; i<NB_WATCH_REAL_PARAM; i++) {
      amesys->pModel->realParamArray[RT_Watch_RP_Idx[i]] = RT_Export_RealParam[i];
   }
   for(i=0; i<NB_WATCH_INT_PARAM; i++) {
      amesys->pModel->integerParamArray[RT_Watch_IP_Idx[i]] = RT_Export_IntParam[i];
   }
#endif
}

#endif

#ifdef AME_INPUT_IN_MEMORY
#include "exp9_.sim.h"
#endif

#if( AME_MODEL_ISEXPLICIT == 0 )
#define LRW (40+9*AME_NBOF_SOLVER_STATES+AME_NBOF_SOLVER_STATES*AME_NBOF_SOLVER_STATES)
#define LIW (21+AME_NBOF_SOLVER_STATES)
#endif

// Submodel THSD00 . 1
// Submodel SIGUDA01 . 1
// variable u (Basic var)
static const int EVIA_V0[7] = {23, -1, 0, -1, 1, 1, 1};
// Submodel SIGUDA01 . 2
// variable u (Basic var)
static const int EVIA_V1[7] = {26, -1, 1, -1, 1, 1, 1};
// Submodel ESSBATPA01 . 1
// variable I1 (Oneline var)
static const int EVIA_V2[7] = {28, -1, 2, -1, 1, 1, 1};
// variable V1 (Basic var)
static const int EVIA_V3[7] = {27, -1, 3, -1, 1, 1, 1};
// variable V2 (Oneline var)
static const int EVIA_V4[7] = {30, -1, 4, -1, 1, 1, 1};
// variable I2 (Basic var)
static const int EVIA_V5[7] = {29, -1, 5, -1, 1, 1, 1};
// variable dh (Basic var)
static const int EVIA_V6[7] = {15, -1, 6, -1, 1, 1, 1};
// variable Temp (Basic var)
static const int EVIA_V7[7] = {16, -1, 7, -1, 1, 1, 1};
// variable soc4 (Oneline var)
static const int EVIA_V8[7] = {25, -1, 8, -1, 1, 1, 1};
// Submodel EBZV01 . 1
// variable V1 (Fixed var)
static const int EVIA_V9[7] = {93, -1, 9, -1, 1, 1, 1};
// Submodel EB3N01 . 1
// variable I1 (Oneline var)
static const int EVIA_V10[7] = {92, -1, 10, -1, 1, 1, 1};
// variable V1 (Basic var)
static const int EVIA_V11[7] = {93, -1, 11, -1, 1, 1, 1};
// variable V2 (Duplicate var)
static const int EVIA_V12[7] = {101, -1, 12, -1, 1, 1, 1};
// variable I2 (Basic var)
static const int EVIA_V13[7] = {100, -1, 13, -1, 1, 1, 1};
// variable V3 (Duplicate var)
static const int EVIA_V14[7] = {27, -1, 14, -1, 1, 1, 1};
// variable I3 (Basic var)
static const int EVIA_V15[7] = {28, -1, 15, -1, 1, 1, 1};
// Submodel CLOC . 1
// variable tout (Basic var)
static const int EVIA_V16[7] = {21, -1, 16, -1, 1, 1, 1};
// Submodel EB3N02 . 1
// variable V1 (Duplicate var)
static const int EVIA_V17[7] = {94, -1, 17, -1, 1, 1, 1};
// variable I1 (Basic var)
static const int EVIA_V18[7] = {95, -1, 18, -1, 1, 1, 1};
// variable I2 (Oneline var)
static const int EVIA_V19[7] = {100, -1, 19, -1, 1, 1, 1};
// variable V2 (Basic var)
static const int EVIA_V20[7] = {101, -1, 20, -1, 1, 1, 1};
// variable V3 (Duplicate var)
static const int EVIA_V21[7] = {103, -1, 21, -1, 1, 1, 1};
// variable I3 (Basic var)
static const int EVIA_V22[7] = {102, -1, 22, -1, 1, 1, 1};
// Submodel THHF0 . 1
// variable dh1 (Fixed var)
static const int EVIA_V23[7] = {13, -1, 23, -1, 1, 1, 1};
// Submodel STOP0 . 1
// variable x (Basic var)
static const int EVIA_V24[7] = {21, -1, 24, -1, 1, 1, 1};
// Submodel SSINK . 1
// variable sink (Basic var)
static const int EVIA_V25[7] = {23, -1, 25, -1, 1, 1, 1};
// Submodel SSINK . 3
// variable sink (Basic var)
static const int EVIA_V26[7] = {25, -1, 26, -1, 1, 1, 1};
// Submodel SSINK . 4
// variable sink (Basic var)
static const int EVIA_V27[7] = {26, -1, 27, -1, 1, 1, 1};
// Submodel EB3N03 . 1
// variable V1 (Duplicate var)
static const int EVIA_V28[7] = {96, -1, 28, -1, 1, 1, 1};
// variable I1 (Basic var)
static const int EVIA_V29[7] = {97, -1, 29, -1, 1, 1, 1};
// variable V2 (Duplicate var)
static const int EVIA_V30[7] = {105, -1, 30, -1, 1, 1, 1};
// variable I2 (Basic var)
static const int EVIA_V31[7] = {104, -1, 31, -1, 1, 1, 1};
// variable I3 (Oneline var)
static const int EVIA_V32[7] = {29, -1, 32, -1, 1, 1, 1};
// variable V3 (Basic var)
static const int EVIA_V33[7] = {30, -1, 33, -1, 1, 1, 1};
// Submodel EBL01 . 1
// variable I1 (Duplicate var)
static const int EVIA_V34[7] = {102, -1, 34, -1, 1, 1, 1};
// variable V1 (Basic var)
static const int EVIA_V35[7] = {103, -1, 35, -1, 1, 1, 1};
// variable I (Explicit state)
static const int EVIA_V36[7] = {104, 3, 36, 37, 1, 1, 1};
// variable V2 (Basic var)
static const int EVIA_V37[7] = {105, -1, 38, -1, 1, 1, 1};
// Submodel EBVT01 . 1
// variable I1 (Fixed var)
static const int EVIA_V38[7] = {95, -1, 39, -1, 1, 1, 1};
// variable V1 (Basic var)
static const int EVIA_V39[7] = {94, -1, 40, -1, 1, 1, 1};
// variable vsig (Basic var)
static const int EVIA_V40[7] = {24, -1, 41, -1, 1, 1, 1};
// variable I3 (Fixed var)
static const int EVIA_V41[7] = {97, -1, 42, -1, 1, 1, 1};
// variable V3 (Basic var)
static const int EVIA_V42[7] = {96, -1, 43, -1, 1, 1, 1};
// Submodel SSINK . 2
// variable sink (Basic var)
static const int EVIA_V43[7] = {24, -1, 44, -1, 1, 1, 1};
// Submodel THC000 . 1
// variable t1 (Explicit state)
static const int EVIA_V44[7] = {14, 0, 45, 46, 1, 1, 1};
// variable dmq1 (Basic var)
static const int EVIA_V45[7] = {13, -1, 47, -1, 1, 1, 1};
// variable t2 (Duplicate var)
static const int EVIA_V46[7] = {16, -1, 48, -1, 1, 1, 1};
// variable dmq2 (Basic var)
static const int EVIA_V47[7] = {15, -1, 49, -1, 1, 1, 1};
// variable t3 (Duplicate var)
static const int EVIA_V48[7] = {0, -1, 50, -1, 1, 1, 1};
// variable dmq3 (Basic var)
static const int EVIA_V49[7] = {1, -1, 51, -1, 1, 1, 1};
// variable t4 (Duplicate var)
static const int EVIA_V50[7] = {5, -1, 52, -1, 1, 1, 1};
// variable dmq4 (Basic var)
static const int EVIA_V51[7] = {6, -1, 53, -1, 1, 1, 1};
// Submodel THTS0 . 1
// variable dh1 (Fixed var)
static const int EVIA_V52[7] = {1, -1, 54, -1, 1, 1, 1};
// variable it (Basic var)
static const int EVIA_V53[7] = {0, -1, 55, -1, 1, 1, 1};
// variable outt (Oneline var)
static const int EVIA_V54[7] = {2, -1, 56, -1, 1, 1, 1};
// Submodel THGCV0 . 1
// variable dh1 (Basic var)
static const int EVIA_V55[7] = {6, -1, 57, -1, 1, 1, 1};
// variable t1 (Basic var)
static const int EVIA_V56[7] = {5, -1, 58, -1, 1, 1, 1};
// Submodel SSINK . 5
// variable sink (Basic var)
static const int EVIA_V57[7] = {2, -1, 59, -1, 1, 1, 1};
static const int* EVIA[58] = {
     EVIA_V0, EVIA_V1, EVIA_V2, EVIA_V3, EVIA_V4, EVIA_V5, EVIA_V6, EVIA_V7, EVIA_V8, EVIA_V9
   , EVIA_V10, EVIA_V11, EVIA_V12, EVIA_V13, EVIA_V14, EVIA_V15, EVIA_V16, EVIA_V17, EVIA_V18, EVIA_V19
   , EVIA_V20, EVIA_V21, EVIA_V22, EVIA_V23, EVIA_V24, EVIA_V25, EVIA_V26, EVIA_V27, EVIA_V28, EVIA_V29
   , EVIA_V30, EVIA_V31, EVIA_V32, EVIA_V33, EVIA_V34, EVIA_V35, EVIA_V36, EVIA_V37, EVIA_V38, EVIA_V39
   , EVIA_V40, EVIA_V41, EVIA_V42, EVIA_V43, EVIA_V44, EVIA_V45, EVIA_V46, EVIA_V47, EVIA_V48, EVIA_V49
   , EVIA_V50, EVIA_V51, EVIA_V52, EVIA_V53, EVIA_V54, EVIA_V55, EVIA_V56, EVIA_V57
};

// Submodel THSD00 . 1
// variable mtot (Basic var)
static const int IVIA_V0[4] = {3, -1, 1, 1};
// variable se (Basic var)
static const int IVIA_V1[4] = {4, -1, 1, 1};
// Submodel SIGUDA01 . 1
// Submodel SIGUDA01 . 2
// Submodel ESSBATPA01 . 1
// variable soc (Explicit state)
static const int IVIA_V2[4] = {31, 1, 1, 1};
// variable U (Explicit state)
static const int IVIA_V3[4] = {32, 2, 1, 1};
// variable I (Basic var)
static const int IVIA_V4[4] = {33, -1, 1, 1};
// variable Ucell (Basic var)
static const int IVIA_V5[4] = {34, -1, 1, 1};
// variable Icell (Basic var)
static const int IVIA_V6[4] = {35, -1, 1, 1};
// variable Icellref (Basic var)
static const int IVIA_V7[4] = {36, -1, 1, 1};
// variable Icellreffilt (Explicit state)
static const int IVIA_V8[4] = {-1, -1, 1, 0};
// variable Radd (Basic var)
static const int IVIA_V9[4] = {37, -1, 1, 1};
// variable Q (Basic var)
static const int IVIA_V10[4] = {38, -1, 1, 1};
// variable faradeff (Basic var)
static const int IVIA_V11[4] = {39, -1, 1, 1};
// variable factorhyst (Explicit state)
static const int IVIA_V12[4] = {-1, -1, 1, 0};
// variable ocv (Basic var)
static const int IVIA_V13[4] = {40, -1, 1, 1};
// variable ocvc (Basic var)
static const int IVIA_V14[4] = {41, -1, 1, 1};
// variable ocvd (Basic var)
static const int IVIA_V15[4] = {42, -1, 1, 1};
// variable ocveq (Basic var)
static const int IVIA_V16[4] = {43, -1, 1, 1};
// variable dUdT (Basic var)
static const int IVIA_V17[4] = {44, -1, 1, 1};
// variable Rohm (Basic var)
static const int IVIA_V18[4] = {45, -1, 1, 1};
// variable Rohmc (Basic var)
static const int IVIA_V19[4] = {46, -1, 1, 1};
// variable Rohmd (Basic var)
static const int IVIA_V20[4] = {47, -1, 1, 1};
// variable Rct (Basic var)
static const int IVIA_V21[4] = {48, -1, 1, 1};
// variable Cct (Basic var)
static const int IVIA_V22[4] = {49, -1, 1, 1};
// variable dssr (Basic var)
static const int IVIA_V23[4] = {50, -1, 1, 1};
// variable dtc (Basic var)
static const int IVIA_V24[4] = {51, -1, 1, 1};
// variable rwlp (Basic var)
static const int IVIA_V25[4] = {52, -1, 1, 1};
// variable wlp (Basic var)
static const int IVIA_V26[4] = {53, -1, 1, 1};
// variable whp (Basic var)
static const int IVIA_V27[4] = {54, -1, 1, 1};
// variable Rdiff (Basic var)
static const int IVIA_V28[4] = {-1, -1, 0, 1};
// variable Cdiff (Basic var)
static const int IVIA_V29[4] = {-1, -1, 0, 1};
// variable sohc (Explicit state)
static const int IVIA_V30[4] = {-1, -1, 1, 0};
// variable sohr (Explicit state)
static const int IVIA_V31[4] = {-1, -1, 1, 0};
// variable dsohcvar (Basic var)
static const int IVIA_V32[4] = {55, -1, 1, 1};
// variable dsohrvar (Basic var)
static const int IVIA_V33[4] = {56, -1, 1, 1};
// variable ratioQ (Basic var)
static const int IVIA_V34[4] = {57, -1, 1, 1};
// variable ratioRohm (Basic var)
static const int IVIA_V35[4] = {58, -1, 1, 1};
// variable ratioRct (Basic var)
static const int IVIA_V36[4] = {59, -1, 1, 1};
// variable ratioRdiff (Basic var)
static const int IVIA_V37[4] = {60, -1, 1, 1};
// variable Bcal (Basic var)
static const int IVIA_V38[4] = {61, -1, 1, 1};
// variable zcal (Basic var)
static const int IVIA_V39[4] = {62, -1, 1, 1};
// variable Eacal (Basic var)
static const int IVIA_V40[4] = {63, -1, 1, 1};
// variable BcycA (Basic var)
static const int IVIA_V41[4] = {64, -1, 1, 1};
// variable BcycSR (Basic var)
static const int IVIA_V42[4] = {65, -1, 1, 1};
// variable alphacycSR (Basic var)
static const int IVIA_V43[4] = {66, -1, 1, 1};
// variable betacycSR (Basic var)
static const int IVIA_V44[4] = {67, -1, 1, 1};
// variable zcycSR (Basic var)
static const int IVIA_V45[4] = {68, -1, 1, 1};
// variable dQlossvar (Basic var)
static const int IVIA_V46[4] = {69, -1, 1, 1};
// variable drgainvar (Basic var)
static const int IVIA_V47[4] = {70, -1, 1, 1};
// variable Qloss (Explicit state)
static const int IVIA_V48[4] = {-1, -1, 1, 0};
// variable rgain (Explicit state)
static const int IVIA_V49[4] = {-1, -1, 1, 0};
// variable deltaUadd (Basic var)
static const int IVIA_V50[4] = {71, -1, 1, 1};
// variable deltaUhyst (Basic var)
static const int IVIA_V51[4] = {72, -1, 1, 1};
// variable deltaUohm (Basic var)
static const int IVIA_V52[4] = {73, -1, 1, 1};
// variable deltaUct (Explicit state)
static const int IVIA_V53[4] = {-1, -1, 0, 1};
// variable deltaUct2 (Basic var)
static const int IVIA_V54[4] = {74, -1, 1, 1};
// variable deltaUdiff (Explicit state)
static const int IVIA_V55[4] = {-1, -1, 0, 1};
// variable deltaUdifftotal (Basic var)
static const int IVIA_V56[4] = {75, -1, 1, 1};
// variable deltaUtotal (Basic var)
static const int IVIA_V57[4] = {76, -1, 1, 1};
// variable Phiadd (Basic var)
static const int IVIA_V58[4] = {77, -1, 1, 1};
// variable Phifaradeff (Basic var)
static const int IVIA_V59[4] = {78, -1, 1, 1};
// variable PhidUdT (Basic var)
static const int IVIA_V60[4] = {79, -1, 1, 1};
// variable Phihyst (Basic var)
static const int IVIA_V61[4] = {80, -1, 1, 1};
// variable Phiohm (Basic var)
static const int IVIA_V62[4] = {81, -1, 1, 1};
// variable Phict (Basic var)
static const int IVIA_V63[4] = {82, -1, 1, 1};
// variable Phidiff (Basic var)
static const int IVIA_V64[4] = {83, -1, 1, 1};
// variable imin (Basic var)
static const int IVIA_V65[4] = {84, -1, 1, 1};
// variable imax (Basic var)
static const int IVIA_V66[4] = {85, -1, 1, 1};
// variable umin (Basic var)
static const int IVIA_V67[4] = {86, -1, 1, 1};
// variable umax (Basic var)
static const int IVIA_V68[4] = {87, -1, 1, 1};
// variable Bcoef (Basic var)
static const int IVIA_V69[4] = {88, -1, 1, 1};
// variable zcoef (Basic var)
static const int IVIA_V70[4] = {89, -1, 1, 1};
// variable powerRSelec (Activity var)
static const int IVIA_V71[4] = {90, -1, 1, 1};
// variable powerCelec (Activity var)
static const int IVIA_V72[4] = {91, -1, 1, 1};
// variable energyRSelec (Explicit state)
static const int IVIA_V73[4] = {-1, -1, 1, 0};
// variable energyCelec (Explicit state)
static const int IVIA_V74[4] = {-1, -1, 1, 0};
// variable actRSelec (Explicit state)
static const int IVIA_V75[4] = {-1, -1, 1, 0};
// variable actCelec (Explicit state)
static const int IVIA_V76[4] = {-1, -1, 1, 0};
// Submodel EBZV01 . 1
// Submodel EB3N01 . 1
// Submodel CLOC . 1
// Submodel EB3N02 . 1
// Submodel THHF0 . 1
// Submodel STOP0 . 1
// variable xref (Discrete var)
static const int IVIA_V77[4] = {22, -1, 1, 1};
// Submodel SSINK . 1
// Submodel SSINK . 3
// Submodel SSINK . 4
// Submodel EB3N03 . 1
// Submodel EBL01 . 1
// variable U (Basic var)
static const int IVIA_V78[4] = {106, -1, 1, 1};
// variable actIelec (Explicit state)
static const int IVIA_V79[4] = {-1, -1, 1, 0};
// variable powerIelec (Activity var)
static const int IVIA_V80[4] = {107, -1, 1, 1};
// variable energyIelec (Explicit state)
static const int IVIA_V81[4] = {-1, -1, 1, 0};
// Submodel EBVT01 . 1
// variable U (Basic var)
static const int IVIA_V82[4] = {98, -1, 1, 1};
// variable I (Fixed var)
static const int IVIA_V83[4] = {99, -1, 1, 1};
// Submodel SSINK . 2
// Submodel THC000 . 1
// variable se (Basic var)
static const int IVIA_V84[4] = {17, -1, 1, 1};
// variable actCmass (Explicit state)
static const int IVIA_V85[4] = {-1, -1, 1, 0};
// variable powerCmass (Activity var)
static const int IVIA_V86[4] = {18, -1, 1, 1};
// variable energyCmass (Explicit state)
static const int IVIA_V87[4] = {-1, -1, 1, 0};
// variable calcmass (Basic var)
static const int IVIA_V88[4] = {19, -1, 1, 1};
// variable x (Basic var)
static const int IVIA_V89[4] = {20, -1, 1, 1};
// Submodel THTS0 . 1
// Submodel THGCV0 . 1
// variable Re (Basic var)
static const int IVIA_V90[4] = {7, -1, 1, 1};
// variable Pr (Basic var)
static const int IVIA_V91[4] = {8, -1, 1, 1};
// variable Gr (Basic var)
static const int IVIA_V92[4] = {9, -1, 1, 1};
// variable NuFree (Basic var)
static const int IVIA_V93[4] = {10, -1, 1, 1};
// variable NuForced (Basic var)
static const int IVIA_V94[4] = {11, -1, 1, 1};
// variable hconv (Basic var)
static const int IVIA_V95[4] = {12, -1, 1, 1};
// Submodel SSINK . 5
static const int* IVIA[96] = {
     IVIA_V0, IVIA_V1, IVIA_V2, IVIA_V3, IVIA_V4, IVIA_V5, IVIA_V6, IVIA_V7, IVIA_V8, IVIA_V9
   , IVIA_V10, IVIA_V11, IVIA_V12, IVIA_V13, IVIA_V14, IVIA_V15, IVIA_V16, IVIA_V17, IVIA_V18, IVIA_V19
   , IVIA_V20, IVIA_V21, IVIA_V22, IVIA_V23, IVIA_V24, IVIA_V25, IVIA_V26, IVIA_V27, IVIA_V28, IVIA_V29
   , IVIA_V30, IVIA_V31, IVIA_V32, IVIA_V33, IVIA_V34, IVIA_V35, IVIA_V36, IVIA_V37, IVIA_V38, IVIA_V39
   , IVIA_V40, IVIA_V41, IVIA_V42, IVIA_V43, IVIA_V44, IVIA_V45, IVIA_V46, IVIA_V47, IVIA_V48, IVIA_V49
   , IVIA_V50, IVIA_V51, IVIA_V52, IVIA_V53, IVIA_V54, IVIA_V55, IVIA_V56, IVIA_V57, IVIA_V58, IVIA_V59
   , IVIA_V60, IVIA_V61, IVIA_V62, IVIA_V63, IVIA_V64, IVIA_V65, IVIA_V66, IVIA_V67, IVIA_V68, IVIA_V69
   , IVIA_V70, IVIA_V71, IVIA_V72, IVIA_V73, IVIA_V74, IVIA_V75, IVIA_V76, IVIA_V77, IVIA_V78, IVIA_V79
   , IVIA_V80, IVIA_V81, IVIA_V82, IVIA_V83, IVIA_V84, IVIA_V85, IVIA_V86, IVIA_V87, IVIA_V88, IVIA_V89
   , IVIA_V90, IVIA_V91, IVIA_V92, IVIA_V93, IVIA_V94, IVIA_V95
};

static const int PVIA[60] = {
     23, 26, 28, 27, 30, 29, 15, 16, 25, 93
   , 92, 93, 101, 100, 27, 28, 21, 94, 95, 100
   , 101, 103, 102, 13, 21, 23, 25, 26, 96, 97
   , 105, 104, 29, 30, 102, 103, 104, 3, 105, 95
   , 94, 24, 97, 96, 24, 14, 0, 13, 16, 15
   , 0, 1, 5, 6, 1, 0, 2, 6, 5, 2
};

// Submodel THSD00 . 1
static const int RPARAM_0[2] = {0, 1};
static const int RPARAM_1[2] = {1, 1};
static const int RPARAM_2[2] = {2, 1};
static const int RPARAM_3[2] = {3, 1};
static const int RPARAM_4[2] = {4, 1};
static const int RPARAM_5[2] = {5, 1};
static const int RPARAM_6[2] = {6, 1};
static const int RPARAM_7[2] = {7, 1};
static const int RPARAM_8[2] = {8, 1};
static const int RPARAM_9[2] = {9, 1};
static const int RPARAM_10[2] = {10, 1};
static const int IPARAM_11[2] = {0, 1};
static const int IPARAM_12[2] = {1, 1};
static const int IPARAM_13[2] = {2, 1};
static const int IPARAM_14[2] = {3, 1};
static const int IPARAM_15[2] = {4, 1};
static const int IPARAM_16[2] = {5, 1};
static const int IPARAM_17[2] = {6, 1};
static const int TPARAM_18[2] = {0, 1};
static const int TPARAM_19[2] = {1, 1};
static const int TPARAM_20[2] = {2, 1};
static const int TPARAM_21[2] = {3, 1};
static const int TPARAM_22[2] = {4, 1};
static const int TPARAM_23[2] = {5, 1};
// Submodel SIGUDA01 . 1
static const int RPARAM_24[2] = {0, 1};
static const int RPARAM_25[2] = {1, 1};
static const int IPARAM_26[2] = {0, 1};
static const int IPARAM_27[2] = {1, 1};
static const int IPARAM_28[2] = {2, 1};
static const int IPARAM_29[2] = {3, 1};
static const int IPARAM_30[2] = {4, 1};
static const int IPARAM_31[2] = {5, 1};
static const int IPARAM_32[2] = {6, 1};
static const int IPARAM_33[2] = {7, 1};
static const int IPARAM_34[2] = {8, 1};
static const int IPARAM_35[2] = {9, 1};
static const int TPARAM_36[2] = {0, 1};
// Submodel SIGUDA01 . 2
static const int RPARAM_37[2] = {0, 1};
static const int RPARAM_38[2] = {1, 1};
static const int IPARAM_39[2] = {0, 1};
static const int IPARAM_40[2] = {1, 1};
static const int IPARAM_41[2] = {2, 1};
static const int IPARAM_42[2] = {3, 1};
static const int IPARAM_43[2] = {4, 1};
static const int IPARAM_44[2] = {5, 1};
static const int IPARAM_45[2] = {6, 1};
static const int IPARAM_46[2] = {7, 1};
static const int IPARAM_47[2] = {8, 1};
static const int IPARAM_48[2] = {9, 1};
static const int TPARAM_49[2] = {0, 1};
// Submodel ESSBATPA01 . 1
static const int RPARAM_50[2] = {0, 1};
static const int RPARAM_51[2] = {1, 1};
static const int RPARAM_52[2] = {2, 1};
static const int RPARAM_53[2] = {3, 1};
static const int RPARAM_54[2] = {4, 1};
static const int RPARAM_55[2] = {5, 1};
static const int RPARAM_56[2] = {6, 1};
static const int RPARAM_57[2] = {7, 1};
static const int RPARAM_58[2] = {8, 1};
static const int RPARAM_59[2] = {9, 1};
static const int RPARAM_60[2] = {10, 1};
static const int RPARAM_61[2] = {11, 1};
static const int RPARAM_62[2] = {12, 1};
static const int RPARAM_63[2] = {13, 1};
static const int RPARAM_64[2] = {14, 1};
static const int RPARAM_65[2] = {15, 1};
static const int RPARAM_66[2] = {16, 1};
static const int RPARAM_67[2] = {17, 1};
static const int RPARAM_68[2] = {18, 1};
static const int RPARAM_69[2] = {19, 1};
static const int RPARAM_70[2] = {20, 1};
static const int RPARAM_71[2] = {21, 1};
static const int RPARAM_72[2] = {22, 1};
static const int RPARAM_73[2] = {23, 1};
static const int RPARAM_74[2] = {24, 1};
static const int RPARAM_75[2] = {25, 1};
static const int RPARAM_76[2] = {26, 1};
static const int RPARAM_77[2] = {27, 1};
static const int RPARAM_78[2] = {28, 1};
static const int RPARAM_79[2] = {29, 1};
static const int RPARAM_80[2] = {30, 1};
static const int RPARAM_81[2] = {31, 1};
static const int IPARAM_82[2] = {0, 1};
static const int IPARAM_83[2] = {1, 1};
static const int IPARAM_84[2] = {2, 1};
static const int IPARAM_85[2] = {3, 1};
static const int IPARAM_86[2] = {4, 1};
static const int IPARAM_87[2] = {5, 1};
static const int IPARAM_88[2] = {6, 1};
static const int IPARAM_89[2] = {7, 1};
static const int IPARAM_90[2] = {8, 1};
static const int IPARAM_91[2] = {9, 1};
static const int IPARAM_92[2] = {10, 1};
static const int IPARAM_93[2] = {11, 1};
static const int IPARAM_94[2] = {12, 1};
static const int IPARAM_95[2] = {13, 1};
static const int IPARAM_96[2] = {14, 1};
static const int IPARAM_97[2] = {15, 1};
static const int IPARAM_98[2] = {16, 1};
static const int IPARAM_99[2] = {17, 1};
static const int IPARAM_100[2] = {18, 1};
static const int IPARAM_101[2] = {19, 1};
static const int IPARAM_102[2] = {20, 1};
static const int IPARAM_103[2] = {21, 1};
static const int IPARAM_104[2] = {22, 1};
static const int IPARAM_105[2] = {23, 1};
static const int IPARAM_106[2] = {24, 1};
static const int IPARAM_107[2] = {25, 1};
static const int IPARAM_108[2] = {26, 1};
static const int IPARAM_109[2] = {27, 1};
static const int TPARAM_110[2] = {0, 1};
static const int TPARAM_111[2] = {1, 1};
static const int TPARAM_112[2] = {2, 1};
static const int TPARAM_113[2] = {3, 1};
static const int TPARAM_114[2] = {4, 1};
static const int TPARAM_115[2] = {5, 1};
static const int TPARAM_116[2] = {6, 1};
static const int TPARAM_117[2] = {7, 1};
static const int TPARAM_118[2] = {8, 1};
static const int TPARAM_119[2] = {9, 1};
static const int TPARAM_120[2] = {10, 1};
static const int TPARAM_121[2] = {11, 1};
static const int TPARAM_122[2] = {12, 1};
static const int TPARAM_123[2] = {13, 1};
static const int TPARAM_124[2] = {14, 1};
static const int TPARAM_125[2] = {15, 1};
static const int TPARAM_126[2] = {16, 1};
static const int TPARAM_127[2] = {17, 1};
static const int TPARAM_128[2] = {18, 1};
static const int TPARAM_129[2] = {-1, 0};
static const int TPARAM_130[2] = {-1, 0};
static const int TPARAM_131[2] = {19, 1};
static const int TPARAM_132[2] = {20, 1};
static const int TPARAM_133[2] = {21, 1};
static const int TPARAM_134[2] = {22, 1};
static const int TPARAM_135[2] = {23, 1};
static const int TPARAM_136[2] = {24, 1};
static const int TPARAM_137[2] = {25, 1};
static const int TPARAM_138[2] = {26, 1};
static const int TPARAM_139[2] = {27, 1};
static const int TPARAM_140[2] = {28, 1};
static const int TPARAM_141[2] = {29, 1};
static const int TPARAM_142[2] = {30, 1};
static const int TPARAM_143[2] = {31, 1};
static const int TPARAM_144[2] = {32, 1};
static const int TPARAM_145[2] = {33, 1};
static const int TPARAM_146[2] = {34, 1};
static const int TPARAM_147[2] = {35, 1};
static const int TPARAM_148[2] = {36, 1};
static const int TPARAM_149[2] = {37, 1};
static const int TPARAM_150[2] = {38, 1};
// Submodel EBZV01 . 1
// Submodel EB3N01 . 1
// Submodel CLOC . 1
// Submodel EB3N02 . 1
// Submodel THHF0 . 1
// Submodel STOP0 . 1
static const int IPARAM_151[2] = {0, 1};
static const int IPARAM_152[2] = {1, 1};
static const int IPARAM_153[2] = {2, 1};
static const int IPARAM_154[2] = {3, 1};
static const int TPARAM_155[2] = {0, 1};
static const int TPARAM_156[2] = {1, 1};
// Submodel SSINK . 1
// Submodel SSINK . 3
// Submodel SSINK . 4
// Submodel EB3N03 . 1
// Submodel EBL01 . 1
static const int RPARAM_157[2] = {0, 1};
// Submodel EBVT01 . 1
static const int RPARAM_158[2] = {0, 1};
static const int RPARAM_159[2] = {1, 1};
static const int IPARAM_160[2] = {0, 1};
// Submodel SSINK . 2
// Submodel THC000 . 1
static const int RPARAM_161[2] = {0, 1};
static const int RPARAM_162[2] = {1, 1};
static const int RPARAM_163[2] = {2, 1};
static const int IPARAM_164[2] = {0, 1};
static const int IPARAM_165[2] = {1, 1};
static const int IPARAM_166[2] = {2, 1};
// Submodel THTS0 . 1
static const int RPARAM_167[2] = {0, 1};
static const int RPARAM_168[2] = {1, 1};
// Submodel THGCV0 . 1
static const int RPARAM_169[2] = {0, 1};
static const int RPARAM_170[2] = {1, 1};
static const int RPARAM_171[2] = {2, 1};
static const int RPARAM_172[2] = {3, 1};
static const int RPARAM_173[2] = {4, 1};
static const int RPARAM_174[2] = {5, 1};
static const int RPARAM_175[2] = {6, 1};
static const int RPARAM_176[2] = {7, 1};
static const int RPARAM_177[2] = {8, 1};
static const int RPARAM_178[2] = {9, 1};
static const int RPARAM_179[2] = {10, 1};
static const int RPARAM_180[2] = {11, 1};
static const int RPARAM_181[2] = {12, 1};
static const int RPARAM_182[2] = {13, 1};
static const int RPARAM_183[2] = {14, 1};
static const int RPARAM_184[2] = {15, 1};
static const int RPARAM_185[2] = {16, 1};
static const int RPARAM_186[2] = {17, 1};
static const int RPARAM_187[2] = {18, 1};
static const int RPARAM_188[2] = {19, 1};
static const int RPARAM_189[2] = {20, 1};
static const int IPARAM_190[2] = {0, 1};
static const int IPARAM_191[2] = {1, 1};
static const int TPARAM_192[2] = {0, 1};
static const int TPARAM_193[2] = {1, 1};
static const int TPARAM_194[2] = {2, 1};
static const int TPARAM_195[2] = {3, 1};
// Submodel SSINK . 5
static const int* PIA[196] = {
     RPARAM_0, RPARAM_1, RPARAM_2, RPARAM_3, RPARAM_4, RPARAM_5, RPARAM_6, RPARAM_7, RPARAM_8, RPARAM_9
   , RPARAM_10, IPARAM_11, IPARAM_12, IPARAM_13, IPARAM_14, IPARAM_15, IPARAM_16, IPARAM_17, TPARAM_18, TPARAM_19
   , TPARAM_20, TPARAM_21, TPARAM_22, TPARAM_23, RPARAM_24, RPARAM_25, IPARAM_26, IPARAM_27, IPARAM_28, IPARAM_29
   , IPARAM_30, IPARAM_31, IPARAM_32, IPARAM_33, IPARAM_34, IPARAM_35, TPARAM_36, RPARAM_37, RPARAM_38, IPARAM_39
   , IPARAM_40, IPARAM_41, IPARAM_42, IPARAM_43, IPARAM_44, IPARAM_45, IPARAM_46, IPARAM_47, IPARAM_48, TPARAM_49
   , RPARAM_50, RPARAM_51, RPARAM_52, RPARAM_53, RPARAM_54, RPARAM_55, RPARAM_56, RPARAM_57, RPARAM_58, RPARAM_59
   , RPARAM_60, RPARAM_61, RPARAM_62, RPARAM_63, RPARAM_64, RPARAM_65, RPARAM_66, RPARAM_67, RPARAM_68, RPARAM_69
   , RPARAM_70, RPARAM_71, RPARAM_72, RPARAM_73, RPARAM_74, RPARAM_75, RPARAM_76, RPARAM_77, RPARAM_78, RPARAM_79
   , RPARAM_80, RPARAM_81, IPARAM_82, IPARAM_83, IPARAM_84, IPARAM_85, IPARAM_86, IPARAM_87, IPARAM_88, IPARAM_89
   , IPARAM_90, IPARAM_91, IPARAM_92, IPARAM_93, IPARAM_94, IPARAM_95, IPARAM_96, IPARAM_97, IPARAM_98, IPARAM_99
   , IPARAM_100, IPARAM_101, IPARAM_102, IPARAM_103, IPARAM_104, IPARAM_105, IPARAM_106, IPARAM_107, IPARAM_108, IPARAM_109
   , TPARAM_110, TPARAM_111, TPARAM_112, TPARAM_113, TPARAM_114, TPARAM_115, TPARAM_116, TPARAM_117, TPARAM_118, TPARAM_119
   , TPARAM_120, TPARAM_121, TPARAM_122, TPARAM_123, TPARAM_124, TPARAM_125, TPARAM_126, TPARAM_127, TPARAM_128, TPARAM_129
   , TPARAM_130, TPARAM_131, TPARAM_132, TPARAM_133, TPARAM_134, TPARAM_135, TPARAM_136, TPARAM_137, TPARAM_138, TPARAM_139
   , TPARAM_140, TPARAM_141, TPARAM_142, TPARAM_143, TPARAM_144, TPARAM_145, TPARAM_146, TPARAM_147, TPARAM_148, TPARAM_149
   , TPARAM_150, IPARAM_151, IPARAM_152, IPARAM_153, IPARAM_154, TPARAM_155, TPARAM_156, RPARAM_157, RPARAM_158, RPARAM_159
   , IPARAM_160, RPARAM_161, RPARAM_162, RPARAM_163, IPARAM_164, IPARAM_165, IPARAM_166, RPARAM_167, RPARAM_168, RPARAM_169
   , RPARAM_170, RPARAM_171, RPARAM_172, RPARAM_173, RPARAM_174, RPARAM_175, RPARAM_176, RPARAM_177, RPARAM_178, RPARAM_179
   , RPARAM_180, RPARAM_181, RPARAM_182, RPARAM_183, RPARAM_184, RPARAM_185, RPARAM_186, RPARAM_187, RPARAM_188, RPARAM_189
   , IPARAM_190, IPARAM_191, TPARAM_192, TPARAM_193, TPARAM_194, TPARAM_195
};


static const int** NGIA = NULL;

static const int* NIA = NULL;

static const int SUBSIMU[21][6][2] = {
     {{11, 2}, {7, 0}, {6, 0}, {1, 0}, {1, 0}, {0, 0}}
   , {{2, 37}, {10, 16}, {1, 12}, {0, 9}, {1, 9}, {0, 2}}
   , {{2, 39}, {10, 26}, {1, 13}, {0, 9}, {1, 10}, {0, 2}}
   , {{32, 41}, {28, 36}, {39, 14}, {1, 9}, {2, 11}, {1, 2}}
   , {{0, 73}, {0, 64}, {0, 53}, {0, 10}, {0, 13}, {0, 3}}
   , {{0, 75}, {0, 65}, {0, 53}, {0, 10}, {0, 13}, {0, 3}}
   , {{0, 75}, {0, 65}, {0, 53}, {0, 10}, {0, 13}, {0, 3}}
   , {{0, 75}, {0, 65}, {0, 53}, {0, 10}, {0, 13}, {0, 3}}
   , {{0, 75}, {0, 65}, {0, 53}, {0, 10}, {0, 13}, {0, 3}}
   , {{0, 37}, {4, 12}, {2, 10}, {2, 7}, {3, 6}, {0, 2}}
   , {{0, 37}, {0, 16}, {0, 12}, {0, 9}, {0, 9}, {0, 2}}
   , {{0, 37}, {0, 16}, {0, 12}, {0, 9}, {0, 9}, {0, 2}}
   , {{0, 37}, {0, 16}, {0, 12}, {0, 9}, {0, 9}, {0, 2}}
   , {{0, 75}, {0, 65}, {0, 53}, {0, 10}, {0, 13}, {0, 3}}
   , {{1, 75}, {0, 65}, {0, 53}, {0, 10}, {2, 13}, {0, 3}}
   , {{2, 73}, {1, 64}, {0, 53}, {0, 10}, {0, 13}, {0, 3}}
   , {{0, 37}, {0, 16}, {0, 12}, {0, 9}, {0, 9}, {0, 2}}
   , {{3, 34}, {3, 9}, {0, 10}, {0, 7}, {1, 5}, {2, 0}}
   , {{2, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}}
   , {{21, 13}, {2, 7}, {4, 6}, {6, 1}, {4, 1}, {0, 0}}
   , {{0, 75}, {0, 65}, {0, 53}, {0, 10}, {0, 13}, {0, 3}}
};

static const S_AMESubStructuralInfo STLI_0 = {1, NULL, &IVIA[0], NULL, &PIA[0], NULL, NULL, NULL};
static const S_AMESubStructuralInfo STLI_1 = {1, &EVIA[0], NULL, PVIA, &PIA[24], SP9, NULL, NULL};
static const S_AMESubStructuralInfo STLI_2 = {2, &EVIA[1], NULL, PVIA, &PIA[37], SP10, NULL, NULL};
static const S_AMESubStructuralInfo STLI_3 = {1, &EVIA[2], &IVIA[2], PVIA, &PIA[50], NULL, NULL, NULL};
static const S_AMESubStructuralInfo STLI_4 = {1, &EVIA[9], NULL, PVIA, NULL, NULL, NULL, NULL};
static const S_AMESubStructuralInfo STLI_5 = {1, &EVIA[10], NULL, PVIA, NULL, NULL, NULL, NULL};
static const S_AMESubStructuralInfo STLI_6 = {1, &EVIA[16], NULL, PVIA, NULL, NULL, NULL, NULL};
static const S_AMESubStructuralInfo STLI_7 = {1, &EVIA[17], NULL, PVIA, NULL, NULL, NULL, NULL};
static const S_AMESubStructuralInfo STLI_8 = {1, &EVIA[23], NULL, PVIA, NULL, NULL, NULL, NULL};
static const S_AMESubStructuralInfo STLI_9 = {1, &EVIA[24], &IVIA[77], PVIA, &PIA[151], NULL, NULL, NULL};
static const S_AMESubStructuralInfo STLI_10 = {1, &EVIA[25], NULL, PVIA, NULL, NULL, NULL, NULL};
static const S_AMESubStructuralInfo STLI_11 = {3, &EVIA[26], NULL, PVIA, NULL, NULL, NULL, NULL};
static const S_AMESubStructuralInfo STLI_12 = {4, &EVIA[27], NULL, PVIA, NULL, NULL, NULL, NULL};
static const S_AMESubStructuralInfo STLI_13 = {1, &EVIA[28], NULL, PVIA, NULL, NULL, NULL, NULL};
static const S_AMESubStructuralInfo STLI_14 = {1, &EVIA[34], &IVIA[78], PVIA, &PIA[157], NULL, NULL, NULL};
static const S_AMESubStructuralInfo STLI_15 = {1, &EVIA[38], &IVIA[82], PVIA, &PIA[158], NULL, NULL, NULL};
static const S_AMESubStructuralInfo STLI_16 = {2, &EVIA[43], NULL, PVIA, NULL, NULL, NULL, NULL};
static const S_AMESubStructuralInfo STLI_17 = {1, &EVIA[44], &IVIA[84], PVIA, &PIA[161], NULL, NULL, NULL};
static const S_AMESubStructuralInfo STLI_18 = {1, &EVIA[52], NULL, PVIA, &PIA[167], NULL, NULL, NULL};
static const S_AMESubStructuralInfo STLI_19 = {1, &EVIA[55], &IVIA[90], PVIA, &PIA[169], NULL, NULL, NULL};
static const S_AMESubStructuralInfo STLI_20 = {5, &EVIA[57], NULL, PVIA, NULL, NULL, NULL, NULL};

/* *******************  Function prototypes ************ */

extern AMEModelStatus thsd00_in(const S_AMESubIntf *sitf);
extern AMEModelStatus thsd00_calc(const S_AMESubIntf *sitf);
extern AMEModelStatus thsd00_end(const S_AMESubIntf *sitf);
extern AMEModelStatus siguda01_in(const S_AMESubIntf *sitf);
extern AMEModelStatus siguda01_calc(const S_AMESubIntf *sitf);
extern AMEModelStatus siguda01_end(const S_AMESubIntf *sitf);
extern void ebzv01in_(int *n, double *y0);
extern AMEModelStatus cloc_in(const S_AMESubIntf *sitf);
extern AMEModelStatus cloc_calc(const S_AMESubIntf *sitf);
extern AMEModelStatus cloc_end(const S_AMESubIntf *sitf);
extern AMEModelStatus thhf0_in(const S_AMESubIntf *sitf);
extern AMEModelStatus thhf0_end(const S_AMESubIntf *sitf);
extern AMEModelStatus stop0_in(const S_AMESubIntf *sitf);
extern AMEModelStatus stop0_calc(const S_AMESubIntf *sitf);
extern AMEModelStatus stop0_end(const S_AMESubIntf *sitf);
extern AMEModelStatus ssink_in(const S_AMESubIntf *sitf);
extern AMEModelStatus ssink_end(const S_AMESubIntf *sitf);
extern void ebl01in_(int *n, double *RP, int *IS, double *y0, double *y1
                   , double *y2);
extern void ebl01_(int *n, double *ve0, double *ve1, double *vedot1
                   , double *ve2, double *vi3, double *vi4, double *vidot4
                   , double *vi5, double *vi6, double *vidot6
                   , double *RP, int *IS);
extern void ebvt01in_(int *n, double *RP, int *IP, double *y0
                   , double *y1, double *y2);
extern void ebvt01_(int *n, double *ve0, double *ve1, double *ve2
                   , double *vi3, double *RP, int *IP);
extern void eb3n02in_(int *n);
extern void eb3n03in_(int *n);
extern void eb3n01in_(int *n);
extern void essbatpa01in_(int *n, double *RP, int *IP, char **TP
                 , double *RS, int *IS, void **PS, double *y0
                   , double *y1, double *y2, double *y3, double *y4
                   , double *y5, double *y6, double *y7, double *y8
                   , double *y9, double *y10, double *y11, double *y12
                   , double *y13);
extern void essbatpa01_(int *n, double *port_1_v2, double *port_2_v2
                   , double *port_3_v1, double *port_3_v2, double *int_v1
                   , double *int_dv1, double *int_v2, double *int_dv2
                   , double *int_v3, double *int_v4, double *int_v5
                   , double *int_v6, double *int_v7, double *int_dv7
                   , double *int_v8, double *int_v9, double *int_v10
                   , double *int_v11, double *int_dv11, double *int_v12
                   , double *int_v13, double *int_v14, double *int_v15
                   , double *int_v16, double *int_v17, double *int_v18
                   , double *int_v19, double *int_v20, double *int_v21
                   , double *int_v22, double *int_v23, double *int_v24
                   , double *int_v25, double *int_v26, double *int_v27
                   , double *int_v28, double *int_v29, double *int_dv29
                   , double *int_v30, double *int_dv30, double *int_v31
                   , double *int_v32, double *int_v33, double *int_v34
                   , double *int_v35, double *int_v36, double *int_v37
                   , double *int_v38, double *int_v39, double *int_v40
                   , double *int_v41, double *int_v42, double *int_v43
                   , double *int_v44, double *int_v45, double *int_v46
                   , double *int_v47, double *int_dv47, double *int_v48
                   , double *int_dv48, double *int_v49, double *int_v50
                   , double *int_v51, double *int_v52, double *int_dv52
                   , double *int_v53, double *int_v54, double *int_dv54
                   , double *int_v55, double *int_v56, double *int_v57
                   , double *int_v58, double *int_v59, double *int_v60
                   , double *int_v61, double *int_v62, double *int_v63
                   , double *int_v64, double *int_v65, double *int_v66
                   , double *int_v67, double *int_v68, double *int_v69
                   , double *int_v70, double *int_v71, double *int_v72
                   , double *int_dv72, double *int_v73, double *int_dv73
                   , double *int_v74, double *int_dv74, double *int_v75
                   , double *int_dv75, double *RP, int *IP, char **TP
                 , double *RS, int *IS, void **PS, int *flag, double *t
                   );
extern AMEModelStatus thts0_in(const S_AMESubIntf *sitf);
extern AMEModelStatus thts0_end(const S_AMESubIntf *sitf);
extern AMEModelStatus thgcv0_in(const S_AMESubIntf *sitf);
extern AMEModelStatus thgcv0_calc(const S_AMESubIntf *sitf);
extern AMEModelStatus thgcv0_end(const S_AMESubIntf *sitf);
extern AMEModelStatus thc000_in(const S_AMESubIntf *sitf);
extern AMEModelStatus thc000_calc(const S_AMESubIntf *sitf);
extern AMEModelStatus thc000_end(const S_AMESubIntf *sitf);

/* ******************    Here comes the functions ************ */
static void PreInitialize(AMESIMSYSTEM *amesys, double *y)
{
   int n = 0;
   double *v = amesys->v;
   double *Z = amesys->discrete_states;
   double *dbk_wk = amesys->pModel->dbk_wk;
   const double t = getstarttime_();
   S_AMESubIntf sitf = {amesys, NULL, NULL, t, NULL, v, NULL};
   AMEModelStatus status = AME_MODEL_OK;


   (void)n;

   /* Assign continuous state variables calculated by the integrator */
#if( (AME_MODEL_ISEXPLICIT == 0) && (AME_NBOF_SOLVER_STATES > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_SOLVER_STATES; idxState++) {
         v[GcontStateVarNum[idxState]] = y[idxState];
      }
   }
#elif( (AME_MODEL_ISEXPLICIT == 1) && (AME_NBOF_EXPLICIT_STATE > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_EXPLICIT_STATE; idxState++) {
         v[GcontStateVarNum[idxState]] = y[idxState];
      }
   }
#endif

   /* Assign discrete state variables */
#if( AME_NBOF_DISCRETE_STATE > 0 )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_DISCRETE_STATE; idxState++) {
         v[GdiscStateVarNum[idxState]] = Z[idxState];
      }
   }
#endif

   InitializeUnitsManagerAsDefault();


   /* Assign continuous state variables initialized by submodels */
#if( (AME_MODEL_ISEXPLICIT == 0) && (AME_NBOF_SOLVER_STATES > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_SOLVER_STATES; idxState++) {
         y[idxState] = v[GcontStateVarNum[idxState]];
      }
   }
#elif( (AME_MODEL_ISEXPLICIT == 1) && (AME_NBOF_EXPLICIT_STATE > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_EXPLICIT_STATE; idxState++) {
         y[idxState] = v[GcontStateVarNum[idxState]];
      }
   }
#endif

   /* Assign discrete state initialized by submodels */
#if( AME_NBOF_DISCRETE_STATE > 0 )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_DISCRETE_STATE; idxState++) {
         Z[idxState] = v[GdiscStateVarNum[idxState]];
      }
   }
#endif

   if(status & AME_MODEL_FATAL) AmeExit(1);
}

static void Initialize(AMESIMSYSTEM *amesys, double *y)
{
   int n;
   double *v = amesys->v;
   double *Z = amesys->discrete_states;
   double *dbk_wk = amesys->pModel->dbk_wk;
   const double t = getstarttime_();
   S_AMESubIntf sitf = {amesys, NULL, NULL, t, NULL, v, NULL};
   AMEModelStatus status = AME_MODEL_OK;


   (void)n;

   /* Assign continuous state variables */
#if( (AME_MODEL_ISEXPLICIT == 0) && (AME_NBOF_SOLVER_STATES > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_SOLVER_STATES; idxState++) {
         v[GcontStateVarNum[idxState]] = y[idxState];
      }
   }
#elif( (AME_MODEL_ISEXPLICIT == 1) && (AME_NBOF_EXPLICIT_STATE > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_EXPLICIT_STATE; idxState++) {
         v[GcontStateVarNum[idxState]] = y[idxState];
      }
   }
#endif

   /* Assign discrete state variables */
#if( AME_NBOF_DISCRETE_STATE > 0 )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_DISCRETE_STATE; idxState++) {
         v[GdiscStateVarNum[idxState]] = Z[idxState];
      }
   }
#endif

   sitf.structuralInfo = &STLI_0;
   sitf.simulationInfo = &amesys->pModel->subArray[0];
   status |= thsd00_in(&sitf);
   if(status & AME_MODEL_FATAL) goto _amefunc_init_end;
   sitf.structuralInfo = &STLI_1;
   sitf.simulationInfo = &amesys->pModel->subArray[1];
   status |= siguda01_in(&sitf);
   if(status & AME_MODEL_FATAL) goto _amefunc_init_end;
   sitf.structuralInfo = &STLI_2;
   sitf.simulationInfo = &amesys->pModel->subArray[2];
   status |= siguda01_in(&sitf);
   if(status & AME_MODEL_FATAL) goto _amefunc_init_end;

   n = 1;
   ebzv01in_(&n, &v[93]);
   sitf.structuralInfo = &STLI_6;
   sitf.simulationInfo = &amesys->pModel->subArray[6];
   status |= cloc_in(&sitf);
   if(status & AME_MODEL_FATAL) goto _amefunc_init_end;
   sitf.structuralInfo = &STLI_8;
   sitf.simulationInfo = &amesys->pModel->subArray[8];
   status |= thhf0_in(&sitf);
   if(status & AME_MODEL_FATAL) goto _amefunc_init_end;
   sitf.structuralInfo = &STLI_9;
   sitf.simulationInfo = &amesys->pModel->subArray[9];
   status |= stop0_in(&sitf);
   if(status & AME_MODEL_FATAL) goto _amefunc_init_end;
   sitf.structuralInfo = &STLI_10;
   sitf.simulationInfo = &amesys->pModel->subArray[10];
   status |= ssink_in(&sitf);
   if(status & AME_MODEL_FATAL) goto _amefunc_init_end;
   sitf.structuralInfo = &STLI_11;
   sitf.simulationInfo = &amesys->pModel->subArray[11];
   status |= ssink_in(&sitf);
   if(status & AME_MODEL_FATAL) goto _amefunc_init_end;
   sitf.structuralInfo = &STLI_12;
   sitf.simulationInfo = &amesys->pModel->subArray[12];
   status |= ssink_in(&sitf);
   if(status & AME_MODEL_FATAL) goto _amefunc_init_end;

   n = 1;
   ebl01in_(&n, RP20, IS20, &v[104], NULL, NULL);

   n = 1;
   ebvt01in_(&n, RP13, IP13, &v[95], &v[97], &v[99]);

   n = 1;
   eb3n02in_(&n);

   n = 1;
   eb3n03in_(&n);
   sitf.structuralInfo = &STLI_16;
   sitf.simulationInfo = &amesys->pModel->subArray[16];
   status |= ssink_in(&sitf);
   if(status & AME_MODEL_FATAL) goto _amefunc_init_end;

   n = 1;
   eb3n01in_(&n);

   n = 1;
   {


      essbatpa01in_(&n, RP11, IP11, TP11, RS11, IS11, PS11, &v[31]
         , &v[32], NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
         , NULL, NULL, NULL, NULL);
   }
   sitf.structuralInfo = &STLI_18;
   sitf.simulationInfo = &amesys->pModel->subArray[18];
   status |= thts0_in(&sitf);
   if(status & AME_MODEL_FATAL) goto _amefunc_init_end;
   sitf.structuralInfo = &STLI_19;
   sitf.simulationInfo = &amesys->pModel->subArray[19];
   status |= thgcv0_in(&sitf);
   if(status & AME_MODEL_FATAL) goto _amefunc_init_end;
   sitf.structuralInfo = &STLI_17;
   sitf.simulationInfo = &amesys->pModel->subArray[17];
   status |= thc000_in(&sitf);
   if(status & AME_MODEL_FATAL) goto _amefunc_init_end;
   sitf.structuralInfo = &STLI_20;
   sitf.simulationInfo = &amesys->pModel->subArray[20];
   status |= ssink_in(&sitf);
   if(status & AME_MODEL_FATAL) goto _amefunc_init_end;

   /* Assign continuous state variables initialized by submodels */
#if( (AME_MODEL_ISEXPLICIT == 0) && (AME_NBOF_SOLVER_STATES > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_SOLVER_STATES; idxState++) {
         y[idxState] = v[GcontStateVarNum[idxState]];
      }
   }
#elif( (AME_MODEL_ISEXPLICIT == 1) && (AME_NBOF_EXPLICIT_STATE > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_EXPLICIT_STATE; idxState++) {
         y[idxState] = v[GcontStateVarNum[idxState]];
      }
   }
#endif

   /* Assign discrete state initialized by submodels */
#if( AME_NBOF_DISCRETE_STATE > 0 )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_DISCRETE_STATE; idxState++) {
         Z[idxState] = v[GdiscStateVarNum[idxState]];
      }
   }
#endif

_amefunc_init_end:
   if(status & AME_MODEL_FATAL) AmeExit(1);
}

#define AME_HAS_ENABLED_SUBMODEL    0

static void localFuncEval(AMESIMSYSTEM *amesys, double t, double *y, double *yprime, double *delta, int *flag)
{
   int sflag, oflag, n, panic, i=0;
   int *oldflag, *newflag;
   double *v = amesys->v;
   double *Z = amesys->discrete_states;
   double *input = amesys->inputs;
   double *output = amesys->outputs;
   double *dbk_wk = amesys->pModel->dbk_wk;
   AMEModelStatus status = AME_MODEL_OK;

#if(AME_MODEL_ISEXPLICIT == 1)
   double *dot = yprime;
   S_AMESubIntf sitf = {amesys, NULL, NULL, t, &sflag, v, dot};

#if(AME_HAS_ENABLED_SUBMODEL == 1)
   memset(dot,0,AME_NBOF_SOLVER_STATES*sizeof(double));
#elif (AME_NBOF_EXPLICIT_STATE == 0)
   dot[0] = 0.0;
#endif

#else
   double dot[AME_NBOF_SOLVER_STATES];
   S_AMESubIntf sitf = {amesys, NULL, NULL, t, &sflag, v, dot};

   /* Initialize the dot vector to the yprime vector. */
   memcpy((void *)dot, (void *)yprime, AME_NBOF_SOLVER_STATES*sizeof(double));
#endif

   SetGlobalSystem(amesys);

   (void)n;

#if(defined(AME_COSIM) && (AME_NBOF_INPUTS > 0))
   if(amesys->doInterpol) {
      if( getInputsCosimSlave(amesys->csSlave, t, input) != AME_NO_ERROR ) {
         AmeExit(1);
      }
   }
#endif

   /* Record old value of flag (oflag) and set
      flag value for use in submodels (sflag).
      Also get addresses of main discontinuity flags. */

   oflag = *flag;
   sflag = *flag;

   if(amesys->first_call)
   {
      GetFlagAddresses(&amesys->oldflag, &amesys->newflag);
   }
   oldflag = amesys->oldflag;
   newflag = amesys->newflag;

   /* Initialize everything ready for potential calls to stepdn
      in submodels. */

   panic = 0;
   getredstep();

   if(isstabrun_())
   {
      t = amesys->simOptions->fixedTime;
      sitf.t = t;
   }
   else if(*flag == 2)
   {
      /* Record current simulation time for message passing. */

      SetSimTime(t);
   }
   /* Record current simulation time for ametim_(). */

   SetTimeAtThisStep(t);

   if (holdinputs_())
   {
      /* We reset artificially the time to the initial value
         to give the illusion of held inputs. */
      t = getstarttime_();
      sitf.t = t;
   }
   /* Assign the state variables y[] calculated by the integrator
      to the appropriate variables v[]. */

   /* Assign continuous state variables calculated by the integrator */
#if( (AME_MODEL_ISEXPLICIT == 0) && (AME_NBOF_SOLVER_STATES > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_SOLVER_STATES; idxState++) {
         v[GcontStateVarNum[idxState]] = y[idxState];
      }
   }
#elif( (AME_MODEL_ISEXPLICIT == 1) && (AME_NBOF_EXPLICIT_STATE > 0) )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_EXPLICIT_STATE; idxState++) {
         v[GcontStateVarNum[idxState]] = y[idxState];
      }
   }
#endif

   /* Assign discrete state variables */
#if( AME_NBOF_DISCRETE_STATE > 0 )
   {
      int idxState;
      for(idxState = 0; idxState < AME_NBOF_DISCRETE_STATE; idxState++) {
         v[GdiscStateVarNum[idxState]] = Z[idxState];
      }
   }
#endif

   /* Assign the interface input variables to the appropriate variable v(). */
#if(AME_NBOF_INPUTS > 0)
   {
      int idxInput;
      for(idxInput = 0; idxInput < AME_NBOF_INPUTS; idxInput++) {
         v[GInputVarNum[idxInput]] = input[idxInput];
      }
   }
#endif

#if(AME_MODEL_ISEXPLICIT == 1)
  /* The following call ensures that lsoda does not integrate past
      time amesys->t_end_of_time_slice. This does not matter in a standard AMESim run but is
      very important with cosimulation. */

#ifdef AME_COSIM
   *oldflag = *newflag = sflag;
   discInput(&amesys->t_end_of_time_slice);
   AME_POST_SUBMODCALL_WITH_DISCON(amesys, flag,&sflag,&oflag,&panic,"_TunableParam",1);
#endif

#else
   if(*flag == 5)
   {
      DPerturbIfNecessary(amesys, flag);
   }

#ifdef AME_COSIM
   *oldflag = *newflag = sflag;
   discInput(&amesys->t_end_of_time_slice);
   AME_POST_SUBMODCALL_WITH_DISCON(amesys, flag,&sflag,&oflag,&panic,"_TunableParam",1);
#endif

#endif

   /* Call submodel calculation subroutine in the order
      that ensures the input requirements of each submodel
      are satisfied. */

#if (NB_REAL_TUNABLE_PARAM > 0) || (NB_INT_TUNABLE_PARAM > 0)
   if(*flag == 0)
   {
      int idxParam;
#if (NB_REAL_TUNABLE_PARAM > 0)
      for(idxParam = 0; idxParam < NB_REAL_TUNABLE_PARAM; idxParam++) {
         v[GRealTunableParam[idxParam][1]] = amesys->pModel->realParamArray[GRealTunableParam[idxParam][0]];
      }
#endif
#if(NB_INT_TUNABLE_PARAM > 0)
      for(idxParam = 0; idxParam < NB_INT_TUNABLE_PARAM; idxParam++) {
         v[GIntTunableParam[idxParam][1]] = amesys->pModel->integerParamArray[GIntTunableParam[idxParam][0]];
      }
#endif
   }
#endif


   {
      *oldflag = *newflag = sflag;
      sitf.structuralInfo = &STLI_0;
      sitf.simulationInfo = &amesys->pModel->subArray[0];
      status |= thsd00_calc(&sitf);
      AME_POST_SUBMODCALL_WITH_DISCON(amesys, flag, &sflag, &oflag, &panic, "THSD00", 1);
   }
   {
      *oldflag = *newflag = sflag;
      sitf.structuralInfo = &STLI_1;
      sitf.simulationInfo = &amesys->pModel->subArray[1];
      status |= siguda01_calc(&sitf);
      AME_POST_SUBMODCALL_WITH_DISCON(amesys, flag, &sflag, &oflag, &panic, "SIGUDA01", 1);
   }
   {
      *oldflag = *newflag = sflag;
      sitf.structuralInfo = &STLI_2;
      sitf.simulationInfo = &amesys->pModel->subArray[2];
      status |= siguda01_calc(&sitf);
      AME_POST_SUBMODCALL_WITH_DISCON(amesys, flag, &sflag, &oflag, &panic, "SIGUDA01", 2);
   }
   v[25] = v[31];
   AME_POST_SUBMODCALL_NO_DISCON(amesys,flag);

   v[101] = v[93] /* Duplicate variable. */;
   AME_POST_SUBMODCALL_NO_DISCON(amesys,flag);

   v[27] = v[93] /* Duplicate variable. */;
   AME_POST_SUBMODCALL_NO_DISCON(amesys,flag);

   {
      *oldflag = *newflag = sflag;
      sitf.structuralInfo = &STLI_6;
      sitf.simulationInfo = &amesys->pModel->subArray[6];
      status |= cloc_calc(&sitf);
      AME_POST_SUBMODCALL_WITH_DISCON(amesys, flag, &sflag, &oflag, &panic, "CLOC", 1);
   }
   v[94] = v[101] /* Duplicate variable. */;
   AME_POST_SUBMODCALL_NO_DISCON(amesys,flag);

   v[103] = v[101] /* Duplicate variable. */;
   AME_POST_SUBMODCALL_NO_DISCON(amesys,flag);

   {
      *oldflag = *newflag = sflag;
      sitf.structuralInfo = &STLI_9;
      sitf.simulationInfo = &amesys->pModel->subArray[9];
      status |= stop0_calc(&sitf);
      AME_POST_SUBMODCALL_WITH_DISCON(amesys, flag, &sflag, &oflag, &panic, "STOP0", 1);
   }
   v[30] = v[27]+v[32];
   AME_POST_SUBMODCALL_NO_DISCON(amesys,flag);

   v[96] = v[30] /* Duplicate variable. */;
   AME_POST_SUBMODCALL_NO_DISCON(amesys,flag);

   v[105] = v[30] /* Duplicate variable. */;
   AME_POST_SUBMODCALL_NO_DISCON(amesys,flag);

   n = 1;
   *oldflag = *newflag = sflag;
   ebl01_(&n, &v[103], &v[104], &dot[3], &v[105], &v[106], NULL
      , NULL, &v[107], NULL, NULL, RP20, IS20);
   AME_POST_SUBMODCALL_WITH_DISCON(amesys,flag,&sflag,&oflag,&panic,"EBL01",1);

   v[102] = -v[104] /* Duplicate variable. */;
   AME_POST_SUBMODCALL_NO_DISCON(amesys,flag);

   n = 1;
   *oldflag = *newflag = sflag;
   ebvt01_(&n, &v[94], &v[24], &v[96], &v[98], RP13, IP13);
   AME_POST_SUBMODCALL_WITH_DISCON(amesys,flag,&sflag,&oflag,&panic,"EBVT01",1);

   v[100] = v[95]+v[102];
   AME_POST_SUBMODCALL_NO_DISCON(amesys,flag);

   v[29] = v[97]+v[104];
   AME_POST_SUBMODCALL_NO_DISCON(amesys,flag);

   v[28] = v[29];
   AME_POST_SUBMODCALL_NO_DISCON(amesys,flag);

   v[92] = v[100]+v[28];
   AME_POST_SUBMODCALL_NO_DISCON(amesys,flag);

   {
      v[16] = v[14];
      AME_POST_SUBMODCALL_NO_DISCON(amesys,flag);
   }
   {
      v[0] = v[14];
      AME_POST_SUBMODCALL_NO_DISCON(amesys,flag);
   }
   {
      v[5] = v[14];
      AME_POST_SUBMODCALL_NO_DISCON(amesys,flag);
   }
   n = 1;
   *oldflag = *newflag = sflag;
   {  /* DBK specific start. */


      essbatpa01_(&n, &v[27], &v[29], &v[15], &v[16], &v[31], &dot[1]
      , &v[32], &dot[2], &v[33], &v[34], &v[35], &v[36], NULL
      , NULL, &v[37], &v[38], &v[39], NULL, NULL, &v[40], &v[41]
      , &v[42], &v[43], &v[44], &v[45], &v[46], &v[47], &v[48]
      , &v[49], &v[50], &v[51], &v[52], &v[53], &v[54], NULL, NULL
      , NULL, NULL, NULL, NULL, &v[55], &v[56], &v[57], &v[58]
      , &v[59], &v[60], &v[61], &v[62], &v[63], &v[64], &v[65]
      , &v[66], &v[67], &v[68], &v[69], &v[70], NULL, NULL, NULL
      , NULL, &v[71], &v[72], &v[73], NULL, NULL, &v[74], NULL
      , NULL, &v[75], &v[76], &v[77], &v[78], &v[79], &v[80], &v[81]
      , &v[82], &v[83], &v[84], &v[85], &v[86], &v[87], &v[88]
      , &v[89], &v[90], &v[91], NULL, NULL, NULL, NULL, NULL, NULL
      , NULL, NULL, RP11, IP11, TP11, RS11, IS11, PS11, &sflag
      , &t);
   }
   AME_POST_SUBMODCALL_WITH_DISCON(amesys,flag,&sflag,&oflag,&panic,"ESSBATPA01",1);

   {
      v[2] = (v[0]-RP0[0])*RP0[1];
      AME_POST_SUBMODCALL_NO_DISCON(amesys,flag);
   }
   {
      *oldflag = *newflag = sflag;
      sitf.structuralInfo = &STLI_19;
      sitf.simulationInfo = &amesys->pModel->subArray[19];
      status |= thgcv0_calc(&sitf);
      AME_POST_SUBMODCALL_WITH_DISCON(amesys, flag, &sflag, &oflag, &panic, "THGCV0", 1);
   }
   {
      *oldflag = *newflag = sflag;
      sitf.structuralInfo = &STLI_17;
      sitf.simulationInfo = &amesys->pModel->subArray[17];
      status |= thc000_calc(&sitf);
      AME_POST_SUBMODCALL_WITH_DISCON(amesys, flag, &sflag, &oflag, &panic, "THC000", 1);
   }


   /* Set interface outputs here. */
#if(AME_NBOF_OUTPUTS > 0)
   {
      int idxOutput;
      for(idxOutput = 0; idxOutput < AME_NBOF_OUTPUTS; idxOutput++) {
         output[idxOutput] = v[GOutputVarNum[idxOutput]];
      }
   }
#endif

#if(AME_MODEL_ISEXPLICIT == 1)
   applyStateStatus(dot,AME_NBOF_SOLVER_STATES);
#else
#if( AME_NBOF_EXPLICIT_STATE > 0)
   applyStateStatus(dot,AME_NBOF_EXPLICIT_STATE);

   for(i=0;i<AME_NBOF_EXPLICIT_STATE;i++)
   {
      delta[i] = dot[i] - yprime[i];
   }
#endif
   for(i=AME_NBOF_EXPLICIT_STATE;i<(AME_NBOF_EXPLICIT_STATE + AME_NBOF_IMPLICIT_STATE_DECLARED);i++)
   {
      delta[i] = dot[i];
   }
#endif

   if(*flag == 0)
   {
      /* It is an initialization call and the user
         is permitted to change the state variables
         and discrete variables. */
      updateStatesFromModel(amesys, y, AME_CONTINUOUS_STATE|AME_DISCRETE_STATE);
   }

#if( AME_NBOF_DISCRETE_STATE > 0)
   if(is_sample_time()) {
      /* Change discrete variables */
      updateStatesFromModel(amesys, y, AME_DISCRETE_STATE);
   }
#endif

   UpFECount(amesys);

   amesys->first_call = 0;
   
   if(status & AME_MODEL_FATAL) {
      AmeExit(1);
   }
}

static AMEModelStatus localJFuncEval_0(AMESIMSYSTEM * amesys, double t, double * y, double * dot, double * v, double * yprime, double * delta, int col)
{
   int sflag = 1;
   int n;
   double *dbk_wk = amesys->pModel->dbk_wk;
   S_AMESubIntf sitf = { amesys, NULL, NULL, t, &sflag, v, dot };
   AMEModelStatus status = AME_MODEL_OK;

   (void)n;

   v[14] = y[col];
   v[16] = v[14];
   v[0] = v[14];
   v[5] = v[14];
   n = 1;
   {  /* DBK specific start. */


      essbatpa01_(&n, &v[27], &v[29], &v[15], &v[16], &v[31], &dot[1]
      , &v[32], &dot[2], &v[33], &v[34], &v[35], &v[36], NULL
      , NULL, &v[37], &v[38], &v[39], NULL, NULL, &v[40], &v[41]
      , &v[42], &v[43], &v[44], &v[45], &v[46], &v[47], &v[48]
      , &v[49], &v[50], &v[51], &v[52], &v[53], &v[54], NULL, NULL
      , NULL, NULL, NULL, NULL, &v[55], &v[56], &v[57], &v[58]
      , &v[59], &v[60], &v[61], &v[62], &v[63], &v[64], &v[65]
      , &v[66], &v[67], &v[68], &v[69], &v[70], NULL, NULL, NULL
      , NULL, &v[71], &v[72], &v[73], NULL, NULL, &v[74], NULL
      , NULL, &v[75], &v[76], &v[77], &v[78], &v[79], &v[80], &v[81]
      , &v[82], &v[83], &v[84], &v[85], &v[86], &v[87], &v[88]
      , &v[89], &v[90], &v[91], NULL, NULL, NULL, NULL, NULL, NULL
      , NULL, NULL, RP11, IP11, TP11, RS11, IS11, PS11, &sflag
      , &t);
   }
   v[2] = (v[0]-RP0[0])*RP0[1];
   sitf.structuralInfo = &STLI_19;
   sitf.simulationInfo = &amesys->pModel->subArray[19];
   status |= thgcv0_calc(&sitf);
   sitf.structuralInfo = &STLI_17;
   sitf.simulationInfo = &amesys->pModel->subArray[17];
   status |= thc000_calc(&sitf);
   return status;
}


static AMEModelStatus localJFuncEval_1(AMESIMSYSTEM * amesys, double t, double * y, double * dot, double * v, double * yprime, double * delta, int col)
{
   int sflag = 1;
   int n;
   double *dbk_wk = amesys->pModel->dbk_wk;
   S_AMESubIntf sitf = { amesys, NULL, NULL, t, &sflag, v, dot };
   AMEModelStatus status = AME_MODEL_OK;

   (void)n;

   v[31] = y[col];
   v[25] = v[31];
   n = 1;
   {  /* DBK specific start. */


      essbatpa01_(&n, &v[27], &v[29], &v[15], &v[16], &v[31], &dot[1]
      , &v[32], &dot[2], &v[33], &v[34], &v[35], &v[36], NULL
      , NULL, &v[37], &v[38], &v[39], NULL, NULL, &v[40], &v[41]
      , &v[42], &v[43], &v[44], &v[45], &v[46], &v[47], &v[48]
      , &v[49], &v[50], &v[51], &v[52], &v[53], &v[54], NULL, NULL
      , NULL, NULL, NULL, NULL, &v[55], &v[56], &v[57], &v[58]
      , &v[59], &v[60], &v[61], &v[62], &v[63], &v[64], &v[65]
      , &v[66], &v[67], &v[68], &v[69], &v[70], NULL, NULL, NULL
      , NULL, &v[71], &v[72], &v[73], NULL, NULL, &v[74], NULL
      , NULL, &v[75], &v[76], &v[77], &v[78], &v[79], &v[80], &v[81]
      , &v[82], &v[83], &v[84], &v[85], &v[86], &v[87], &v[88]
      , &v[89], &v[90], &v[91], NULL, NULL, NULL, NULL, NULL, NULL
      , NULL, NULL, RP11, IP11, TP11, RS11, IS11, PS11, &sflag
      , &t);
   }
   sitf.structuralInfo = &STLI_17;
   sitf.simulationInfo = &amesys->pModel->subArray[17];
   status |= thc000_calc(&sitf);
   return status;
}


static AMEModelStatus localJFuncEval_2(AMESIMSYSTEM * amesys, double t, double * y, double * dot, double * v, double * yprime, double * delta, int col)
{
   int sflag = 1;
   int n;
   double *dbk_wk = amesys->pModel->dbk_wk;
   S_AMESubIntf sitf = { amesys, NULL, NULL, t, &sflag, v, dot };
   AMEModelStatus status = AME_MODEL_OK;

   (void)n;

   v[32] = y[col];
   v[30] = v[27]+v[32];
   v[96] = v[30] /* Duplicate variable. */;
   v[105] = v[30] /* Duplicate variable. */;
   n = 1;
   ebl01_(&n, &v[103], &v[104], &dot[3], &v[105], &v[106], NULL
      , NULL, &v[107], NULL, NULL, RP20, IS20);
   n = 1;
   ebvt01_(&n, &v[94], &v[24], &v[96], &v[98], RP13, IP13);
   n = 1;
   {  /* DBK specific start. */


      essbatpa01_(&n, &v[27], &v[29], &v[15], &v[16], &v[31], &dot[1]
      , &v[32], &dot[2], &v[33], &v[34], &v[35], &v[36], NULL
      , NULL, &v[37], &v[38], &v[39], NULL, NULL, &v[40], &v[41]
      , &v[42], &v[43], &v[44], &v[45], &v[46], &v[47], &v[48]
      , &v[49], &v[50], &v[51], &v[52], &v[53], &v[54], NULL, NULL
      , NULL, NULL, NULL, NULL, &v[55], &v[56], &v[57], &v[58]
      , &v[59], &v[60], &v[61], &v[62], &v[63], &v[64], &v[65]
      , &v[66], &v[67], &v[68], &v[69], &v[70], NULL, NULL, NULL
      , NULL, &v[71], &v[72], &v[73], NULL, NULL, &v[74], NULL
      , NULL, &v[75], &v[76], &v[77], &v[78], &v[79], &v[80], &v[81]
      , &v[82], &v[83], &v[84], &v[85], &v[86], &v[87], &v[88]
      , &v[89], &v[90], &v[91], NULL, NULL, NULL, NULL, NULL, NULL
      , NULL, NULL, RP11, IP11, TP11, RS11, IS11, PS11, &sflag
      , &t);
   }
   sitf.structuralInfo = &STLI_17;
   sitf.simulationInfo = &amesys->pModel->subArray[17];
   status |= thc000_calc(&sitf);
   return status;
}


static AMEModelStatus localJFuncEval_3(AMESIMSYSTEM * amesys, double t, double * y, double * dot, double * v, double * yprime, double * delta, int col)
{
   int sflag = 1;
   int n;
   double *dbk_wk = amesys->pModel->dbk_wk;
   S_AMESubIntf sitf = { amesys, NULL, NULL, t, &sflag, v, dot };
   AMEModelStatus status = AME_MODEL_OK;

   (void)n;

   v[104] = y[col];
   n = 1;
   ebl01_(&n, &v[103], &v[104], &dot[3], &v[105], &v[106], NULL
      , NULL, &v[107], NULL, NULL, RP20, IS20);
   v[102] = -v[104] /* Duplicate variable. */;
   v[100] = v[95]+v[102];
   v[29] = v[97]+v[104];
   v[28] = v[29];
   v[92] = v[100]+v[28];
   n = 1;
   {  /* DBK specific start. */


      essbatpa01_(&n, &v[27], &v[29], &v[15], &v[16], &v[31], &dot[1]
      , &v[32], &dot[2], &v[33], &v[34], &v[35], &v[36], NULL
      , NULL, &v[37], &v[38], &v[39], NULL, NULL, &v[40], &v[41]
      , &v[42], &v[43], &v[44], &v[45], &v[46], &v[47], &v[48]
      , &v[49], &v[50], &v[51], &v[52], &v[53], &v[54], NULL, NULL
      , NULL, NULL, NULL, NULL, &v[55], &v[56], &v[57], &v[58]
      , &v[59], &v[60], &v[61], &v[62], &v[63], &v[64], &v[65]
      , &v[66], &v[67], &v[68], &v[69], &v[70], NULL, NULL, NULL
      , NULL, &v[71], &v[72], &v[73], NULL, NULL, &v[74], NULL
      , NULL, &v[75], &v[76], &v[77], &v[78], &v[79], &v[80], &v[81]
      , &v[82], &v[83], &v[84], &v[85], &v[86], &v[87], &v[88]
      , &v[89], &v[90], &v[91], NULL, NULL, NULL, NULL, NULL, NULL
      , NULL, NULL, RP11, IP11, TP11, RS11, IS11, PS11, &sflag
      , &t);
   }
   sitf.structuralInfo = &STLI_17;
   sitf.simulationInfo = &amesys->pModel->subArray[17];
   status |= thc000_calc(&sitf);
   return status;
}


static AMEModelStatus (*jfunc_table[])(AMESIMSYSTEM *, double, double *, double *, double *, double *, double *, int) = {
      localJFuncEval_0, localJFuncEval_1, localJFuncEval_2, localJFuncEval_3
};



static void localJFuncEval(AMESIMSYSTEM *amesys, double t, double *y, double *yprime, double *delta, int col)
{
   int sflag=1; /* Only one flag value is required. */
   int n=1, i=0;
   double *v = amesys->v;
   double *vcopy = amesys->vcopy;
   double *input = amesys->inputs;
   double *output = amesys->outputs;
   double *Z = amesys->discrete_states;
   double *dbk_wk = amesys->pModel->dbk_wk;
   AMEModelStatus status = AME_MODEL_OK;
   
#if(AME_MODEL_ISEXPLICIT == 1)
   double *dot = yprime;

#else
   double dot[AME_NBOF_SOLVER_STATES];

   /* Initialize the dot vector to the yprime vector. */
   memcpy((void *)dot, (void *)yprime, AME_NBOF_SOLVER_STATES*sizeof(double));
#endif

#if(AME_MODEL_ISEXPLICIT == 0)
   /* Initialize everything ready for potential calls to stepdn
      in submodels. */

#if(defined(AME_COSIM) && (AME_NBOF_INPUTS > 0))
   if(amesys->doInterpol) {
      if( getInputsCosimSlave(amesys->csSlave, t, input) != AME_NO_ERROR ) {
         AmeExit(1);
      }
   }
#endif

   if(isstabrun_())
   {
      t = amesys->simOptions->fixedTime;
   }
#endif

   /* Record current simulation time for ametim_(). */

   SetTimeAtThisStep(t);

   if (holdinputs_())
   {
      /* We reset artificially the time to the initial value
         to give the illusion of held inputs. */

      t = getstarttime_();
   }

   /* Assign the state variables y[] calculated by the integrator
      to the appropriate variables v[] and right calls necessary
      for that state in a case of a switch. */


   status |= (*jfunc_table[col])(amesys, t, y, dot, v, yprime, delta, col);


   UpFECount(amesys);
   
   if(status & AME_MODEL_FATAL) {
      AmeExit(1);
   }
}

static void EndOfSimulation(AMESIMSYSTEM *amesys)
{
   int n=1;
   double *y = amesys->states;
   double *v = amesys->v;
   double *Z = amesys->discrete_states;
   double *dbk_wk = amesys->pModel->dbk_wk;
   const double t = getfinaltime_();
   S_AMESubIntf sitf = {amesys, NULL, NULL, t, NULL, v, NULL};
   AMEModelStatus status = AME_MODEL_OK;
   

   (void)n;
   (void)status;

   sitf.structuralInfo = &STLI_20;
   sitf.simulationInfo = &amesys->pModel->subArray[20];
   status |= ssink_end(&sitf);
   sitf.structuralInfo = &STLI_17;
   sitf.simulationInfo = &amesys->pModel->subArray[17];
   status |= thc000_end(&sitf);
   sitf.structuralInfo = &STLI_19;
   sitf.simulationInfo = &amesys->pModel->subArray[19];
   status |= thgcv0_end(&sitf);
   sitf.structuralInfo = &STLI_18;
   sitf.simulationInfo = &amesys->pModel->subArray[18];
   status |= thts0_end(&sitf);
   sitf.structuralInfo = &STLI_16;
   sitf.simulationInfo = &amesys->pModel->subArray[16];
   status |= ssink_end(&sitf);
   sitf.structuralInfo = &STLI_12;
   sitf.simulationInfo = &amesys->pModel->subArray[12];
   status |= ssink_end(&sitf);
   sitf.structuralInfo = &STLI_11;
   sitf.simulationInfo = &amesys->pModel->subArray[11];
   status |= ssink_end(&sitf);
   sitf.structuralInfo = &STLI_10;
   sitf.simulationInfo = &amesys->pModel->subArray[10];
   status |= ssink_end(&sitf);
   sitf.structuralInfo = &STLI_9;
   sitf.simulationInfo = &amesys->pModel->subArray[9];
   status |= stop0_end(&sitf);
   sitf.structuralInfo = &STLI_8;
   sitf.simulationInfo = &amesys->pModel->subArray[8];
   status |= thhf0_end(&sitf);
   sitf.structuralInfo = &STLI_6;
   sitf.simulationInfo = &amesys->pModel->subArray[6];
   status |= cloc_end(&sitf);
   sitf.structuralInfo = &STLI_2;
   sitf.simulationInfo = &amesys->pModel->subArray[2];
   status |= siguda01_end(&sitf);
   sitf.structuralInfo = &STLI_1;
   sitf.simulationInfo = &amesys->pModel->subArray[1];
   status |= siguda01_end(&sitf);
   sitf.structuralInfo = &STLI_0;
   sitf.simulationInfo = &amesys->pModel->subArray[0];
   status |= thsd00_end(&sitf);
}

static void ameTerminate(AMESIMSYSTEM *amesys)
{
#ifdef AME_WRITE_RUNSTAT
   if(amesys->simOptions ) {
      if(amesys->simOptions->statistics)
      {
         WriteRunStats(amesys);
      }
   }
#endif
#ifdef AME_PROCESS_TIME
   ProcessTime(2);
#endif

   /* Save state count, discontinuities and finalize the Performance Analyzer */
#ifdef AME_PERFORMANCE_ANALYZER
   if(!isfixedstepsolver_()){
      PerfAnalyzer_SaveStateCount (amesys);
      PerfAnalyzer_SaveDiscontinuities(amesys);
      PerfAnalyzer_Close(amesys);
   }
#endif

#ifdef AME_RESULT_FILE
   amesys->CloseResultFile(amesys);
#endif

   EndOfSimulation(amesys);
   AmeCallAtEnd(amesys->ameExitStatus);
   modelCleanStore(amesys->pModel);
}

#ifdef AME_EXPOSE_JACOBIAN
static int getPartialDerivatives(double *A, double *B, double *C, double *D)
{
   int res;
   AMESIMSYSTEM  *amesys = GetGlobalSystem();

   SPARSE_MATRIX *Amat, *Bmat, *Cmat, *Dmat;

#if(AME_MODEL_ISEXPLICIT == 1)
   if (amesys->tlast > TLAST_MIN)
      res = LDoLinearAnalysisOnDemand(amesys, amesys->numstates,
                                       amesys->tlast, amesys->states,
                                       &Amat, &Bmat, &Cmat, &Dmat);
#else
   if (amesys->tlast > TLAST_MIN)
      res = DDoLinearAnalysisOnDemand(amesys, amesys->neq,
                                       amesys->tlast,
                                       amesys->states, amesys->dotstates,
                                       &Amat, &Bmat, &Cmat, &Dmat);
#endif
   else
      res = 0;  /* failed: system probably not initialized */

   if(res != 0) {
      if(Amat) {
         GetMatAsDense(Amat,A);
      }
      if(Bmat) {
         GetMatAsDense(Bmat,B);
      }
      if(Cmat) {
         GetMatAsDense(Cmat,C);
      }
      if(Dmat) {
         GetMatAsDense(Dmat,D);
      }
      FreeSparseMatrix(Amat);
      FreeSparseMatrix(Bmat);
      FreeSparseMatrix(Cmat);
      FreeSparseMatrix(Dmat);
   }

   return res;
} /* getPartialDerivatives */

static int setLASettingsFromIO(int num_input_index, int num_output_index,
                              int *input_index, int *output_index, int *nbState)
{
   *nbState = AME_NBOF_EXPLICIT_STATE + AME_NBOF_IMPLICIT_STATE;

   return SetLADetailsFromIO(AME_NBOF_EXPLICIT_STATE, AME_NBOF_IMPLICIT_STATE,
                              AME_NBOF_INPUTS, AME_NBOF_OUTPUTS,
                              num_input_index, num_output_index, input_index, output_index,
                              GInputVarNum, GOutputVarNum, 0.0, 1.0, 1.0, 0.1);
}
#endif

/* ============================================================== */

static void ModelAmeExit(AMESIMSYSTEM *amesys, int status)
{
   /* Will be catch by the state machine */
   amesys->ameExitStatus = status;
   longjmp(amesys->jump_env, status);
}

#ifdef AME_INPUT_IN_MEMORY
#include "exp9_.ssf.h"
static const char **getssflist(int *num_items)
{
   *num_items = savestatusflags_length;
   return savestatusflags;
}
#endif

/**************************************************************
*                                                             *
* Function load_subdata_tables reads data for lookuptables    *
* mostly/only used for realtime                               *
*                                                             *
* 0106429                                                     *
* Move the include outside of function. The include now       *
* contains one function per table and a function that calls   *
* them all. This reduces the risk that a compiler crashes due *
* to a huge function.                                         *
**************************************************************/
#ifdef AME_TABLES_IN_MEMORY
#include "exp9_.subdata.h"
#endif

static void load_subdata_tables(void)
{
#ifdef AME_TABLES_IN_MEMORY
   add_all_tables_to_memory();
#endif
}

/***********************************************************
   Purpose  :  Return Simcenter Amesim version used to generate the model C code
               It allows the client to update interface management for
               backward compatibility.
   Author	:  J.Andre
   Creation :  2016 - 09 - 05
   Inputs   :  None
   Outputs  :  Simcenter Amesim version
   Revision :
************************************************************/
static unsigned int AmesysGetVersion()
{
	/* Returned number indicates 10000* main verion + 100* SL version + minor */
   /* Eg. Rev15     (15.0.0)  => 150000 */
   /* Eg. Rev15SL1  (15.1.0)  => 150100 */
   /* Eg. Rev15.0.1 (15.0.1)  => 150001 */

   return AMEVERSION;
}

/***********************************************************
   Purpose  :  Return SoldTo ID which Simcenter Amesim model has been generated.
   Author	:  J.Andre
   Creation :  2017 - 02 - 13
   Inputs   :  None
   Outputs  :  SoldToID
   Revision :
************************************************************/
static const char* getSoldToID()
{
   return "46674455";
}

#ifdef AME_INPUT_IN_MEMORY
#include "exp9_.globalparams.h"
#endif

/***********************************************************
   Purpose  : Load and evaluate model parameters from files
   Author   : J.Andre
   Created  : 2016 - 09 - 08
   Inputs   :
      amesys  : system
      errmsg  : error message
   Outputs  : Error code
   Revision :
************************************************************/
static AMESystemError loadModelParamFromDisk(AMESIMSYSTEM *amesys, AMESystemError *gpError,  AMESystemError *lpError, char *errmsg)
{
   AMESystemError ret;
   *gpError = AME_NO_ERROR;
   *lpError = AME_NO_ERROR;

   ret = AmeReadGPFile(amesys);

   if(ret == AME_NO_ERROR) {
      *gpError = AmeEvalGlobalParamList(amesys, 1, errmsg);
      *lpError = loadParameterFromFile(amesys->pModel, GetDataFileName(), errmsg);
   }
   return ret;
}

#ifdef AME_INPUT_IN_MEMORY

/***********************************************************
   Purpose    : Load and evaluate model parameters from memory
   Author	  : J.Andre
   Created on : 2016 - 09 - 08
   Inputs	  :
      amesys  : system
      errmsg  : error message
   Outputs	  : Parameter error code
   Revision   :
************************************************************/
static AMESystemError loadModelParamFromMemory(AMESIMSYSTEM *amesys, AMESystemError *gpError,  AMESystemError *lpError, char * errmsg)
{
#include "exp9_.data.h"

   ameAddGlobalParamsFromMemory(amesys,errmsg);

   if(amecheckversion(AMESIMRUNTIMEVERSION, __TIME__, __DATE__, NULL)) {
      amefprintf(stderr, "A problem with incompatible versions of the AMESim runtime library has been found.");
   }

   *gpError = AmeEvalGlobalParamList(amesys, 1, errmsg);
   *lpError = loadParameterFromDataTable(amesys->pModel, allparams, errmsg);

   return AME_NO_ERROR;
}

#endif

/***********************************************************
   Purpose    : Load and evaluate model parameters
   Author	  : J.Andre
   Created on : 2016 - 09 - 08
   Inputs	  :
      amesys  : system
      errmsg  : error message
   Outputs	  : Parameter error code
   Revision   :
************************************************************/
static AMESystemError loadModelParameters(AMESIMSYSTEM *amesys)
{
   AMESystemError res = AME_PARAMETER_ERROR;
   char errmsg[PATH_MAX+128];
   AMESystemError ret_gp = AME_NO_ERROR;
   AMESystemError ret_lp = AME_NO_ERROR;

   errmsg[0] = '\0';

#ifdef AME_INPUT_IN_MEMORY
#ifdef AME_RT_CAN_READ_FILE
   res = loadModelParamFromDisk(amesys, &ret_gp, &ret_lp, errmsg);

   if (res != AME_NO_ERROR) {
      /* If the file is not there - we say nothing */
      if (res != AME_PARAM_FILE_OPEN_ERROR) {
         amefprintf(stderr,"%s",errmsg);
         amefprintf(stderr,"loadParameterFromFile> %s\n",errmsg);
         ClearGPs();
      }
   }
   else {
      amefprintf(stderr,"Using data from disk (%s)\n",GetDataFileName());
   }
#endif
   if(res != AME_NO_ERROR) {
      /* Read all from memory */
      res = loadModelParamFromMemory(amesys, &ret_gp, &ret_lp, errmsg);
      SetGlobalParamReadFile(0);
   }
#else
   /* Read all from disk */
   res = loadModelParamFromDisk(amesys, &ret_gp, &ret_lp, errmsg);
#endif

   if( (res != AME_NO_ERROR) || (ret_gp != AME_NO_ERROR) || (ret_lp != AME_NO_ERROR) ) {
      amefprintf(stderr,"%s",errmsg);

      if( (res != AME_NO_ERROR) || (ret_lp != AME_NO_ERROR) ) {
         res = AME_GLOBAL_PARAMETER_ERROR;
      }
   }
   return res;
}

static AMESystemError Input(AMESIMSYSTEM *amesys)
{
   int retval;

   /* Load data files for submodels */
   load_subdata_tables();

   /* Load parameters for submodels */
   retval = loadModelParameters(amesys);

   /* Ensure parameters seen by RT is initialized correctly */
#ifdef AME_MEMORY_ACCESS_RT_EXPORT
   RT_Get_Watch_Param(amesys);
#endif

   return retval;
}

static int ameSetOptions(AMESIMSYSTEM *amesys,
                         double tsaveinc,
                         double maxstepsize,
                         double tolerance,
                         int errorcontrol,
                         int writelevel,
                         int extradisconprint,
                         int runstats,
                         int theruntype,
                         int thesolvertype)
{
   amesys->simOptions->errorType = errorcontrol;
   amesys->simOptions->tol = tolerance;
   amesys->simOptions->rStrtp = extradisconprint;
   amesys->simOptions->statistics = runstats;
   amesys->simOptions->solverType = thesolvertype;
   amesys->simOptions->runType = theruntype;
   amesys->simOptions->iWrite = writelevel;
   amesys->simOptions->tInc = tsaveinc;
   amesys->simOptions->hMax = maxstepsize;

   /* Copy sim option to share with libraries before to modify it */
   memcpy(amesys->sharedSimOptions, amesys->simOptions, sizeof(SIMOptions));

   if(amesys->simOptions->solverType) {
      /* It is the cautious option. The maximum time step
         should not exceed the print interval. */
      setmaxstep_(&amesys->simOptions->tInc);
   }

#if( AME_MODEL_ISEXPLICIT == 1) && (AME_NBOF_EXPLICIT_STATE == 0 )
   if(maxstepsize > tsaveinc) {
      amefprintf(stderr, "Since the model has no state variable,\n");
      amefprintf(stderr, "the maximum time step has been reduced to %gs.\n", tsaveinc);
      setmaxstep_(&amesys->simOptions->tInc);
   }
#endif

   SetInitPrintIntervalFromSimOpts(amesys);

   ValidateRuntype(theruntype);

   ameSetupTolerance(amesys->simOptions);

   return 1;
}

static int ameSetOptionsFixed(AMESIMSYSTEM *amesys,
                              double printinterval,
                              int fixed_type,
                              int fixedOrder,
                              double fixed_h,
                              int run_type)
{
   amesys->simOptions->iWrite = 2;

   ValidateRuntype(run_type);

	/* Ensure that runflag StabilizingRun=0. It might have been set to true */
	/* due to a previous selection for the variable step integrator. */
   ClearStabilizingRun();

   amesys->simOptions->fixedOrder = fixedOrder;
   amesys->simOptions->fixedStep  = 1; /* Yes - fixed step */
   amesys->simOptions->fixedH     = fixed_h;

   amesys->simOptions->tInc =  printinterval;
   amesys->simOptions->rStrtp = 0;  /* No discontinuity printout using fixed step solver */

   amesys->simOptions->fixedType  = fixed_type;
   SetIsUsingFixedSolver(( fixed_type == 1)*100 +  (fixed_type != 1)*200 + fixedOrder);

   SetFixedTimeStep(fixed_h);

   return 1;
}

static int ameInputs(AMESIMSYSTEM *amesys, int numInputs, const double *inputARG)
{
   if(numInputs != amesys->numinputs)
   {
      char error_message[256];
      sprintf(error_message, "AMEInputs> Expected %d inputs but got %d\n", amesys->numinputs, numInputs);
      DisplayMessage(error_message);
      return 0;
   }
#if (AME_NBOF_INPUTS > 0)
   memcpy(amesys->inputs, inputARG, amesys->numinputs*sizeof(double) );
#endif
   return 1;
}

static void doAssembly(AMESIMSYSTEM *amesys)
{
   if (IsAssemblyNecessary_())
   {
      double time = getstarttime_();
      double tmp[AME_NBOF_SOLVER_STATES];
      int local_flag;

      /* Perform the assembly. */
      amesys->consflag = 1;
      local_flag = 0;
#if(AME_MODEL_ISEXPLICIT == 1)
      amesys->FuncEval(amesys, time, amesys->states, tmp, NULL, &local_flag);
#else
      amesys->res(amesys, time, amesys->states, amesys->dotstates, tmp, &local_flag);
#endif
      amesys->first_call = 1;

      amesys->consflag = 2;
      local_flag = 0;
#if(AME_MODEL_ISEXPLICIT == 1)
      amesys->FuncEval(amesys, time, amesys->states, tmp, NULL, &local_flag);
#else
      amesys->res(amesys, time, amesys->states, amesys->dotstates, tmp, &local_flag);
#endif
      amesys->first_call = 1;
      amesys->consflag = 0;
   }
}

static int ameEvalTstart(AMESIMSYSTEM *amesys, const double *modelInputs, double *modelOutputs)
{
#ifndef AMERT
   double time = getstarttime_();

   ameInputs(amesys, AME_NBOF_INPUTS, modelInputs);

   doAssembly(amesys);

   /* Initialize, maybe perform an initialising run */

   if(isstabrun_())
   {
      amesys->simOptions->fixedTime = time;
   }
   amesys->simOptions->stabilOption += 4*amesys->simOptions->solverType;

#if(AME_MODEL_ISEXPLICIT == 1)

   if(!IntegrateInit(amesys, time, time))
   {
      return 0;
   }
#else
   amesys->internal_discont = 1;

   DIntegrateInit(amesys, AME_NBOF_EXPLICIT_STATE, time, getfinaltime_(), amesys->simOptions->tInc, amesys->states,
                  amesys->dotstates, amesys->simOptions->hMax, AME_NBOF_SOLVER_STATES, amesys->iwork, amesys->simOptions->reltol, amesys->simOptions->abstol, amesys->simOptions->rStrtp, LIW, LRW, amesys->simOptions->statistics,amesys->simOptions->stabilOption, amesys->simOptions->iWrite, amesys->simOptions->minimalDiscont, Gis_constraint);

   if(isstabrun_())
   {
      /* HELP !!!! */
   }
#endif

#if (AME_NBOF_OUTPUTS > 0)
   memcpy(modelOutputs, amesys->outputs, amesys->numoutputs*sizeof(double) );
#endif
   amesys->tlast = time;

   return 1;
#else
   char error_message[256];
   sprintf(error_message, "ameEvalTstart> Should never be called for real-time simulation\n");
   DisplayMessage(error_message);
   return 0;
#endif
}

static int ameSetUpLockedStatus(AMESIMSYSTEM *amesys)
{
#ifdef AME_INPUT_IN_MEMORY
#include "exp9_.lock.h"
   if(0 != SetUpLockedStatesFromMemory(amesys, lockedstates_length, lockedstates_array))
   {
      amefprintf(stderr,"Failed to set the locked states status.\n");
   }
#else
   SetUpLockedStates(GetCircuitName());
#endif
   return 0;
}

static int ameInitializeConditions(AMESIMSYSTEM *amesys)
{
#ifdef AME_VSOLVER_ACCEPTED
   double time = amesys->simOptions->tStart;

   /* Initialise some static variables */
   setfinaltime_(amesys->simOptions->tFinal);

   amesys->first_call=1;  /* should this be done or not ?*/
   amesys->internal_discont = 1;

   amesys->tlast = TLAST_MIN;

   memset(amesys->ecount,0,amesys->numstates*sizeof(int));
   memset(amesys->dotstates,0,amesys->numstates*sizeof(double));

#if(AME_MODEL_ISEXPLICIT == 0)
   memset(amesys->iwork,0,LIW*sizeof(int));
#endif
   /*  The following statement covers the case where there are
       no state variables y. */
#if( AME_NBOF_EXPLICIT_STATE == 0 )
   amesys->states[0] = 0.0;
#endif

   /* Call Input to read submodel and simulation parameters. */
   if(Input(amesys) != AME_NO_ERROR) return 0;
   modelSetInitValues(amesys->pModel, amesys->states, amesys->discrete_states);

   /* Register print interval that maybe used bys some submodels */
   SetInitPrintIntervalFromSimOpts(amesys);

   setstarttime_(time);

   /* Call pre-initialize function */

   PreInitialize(amesys,amesys->states);

#ifndef AME_INPUT_IN_MEMORY
   if( NeedReloadInputFiles() != 0 )
   {
      ClearGPs();
      if(Input(amesys) != AME_NO_ERROR) return 0;
      modelSetInitValues(amesys->pModel, amesys->states, amesys->discrete_states);
      ClearReloadedFiles();
   }
#endif

   /* Call initialize subroutine to set con and icon array members */

   Initialize(amesys,amesys->states);

   /* Overwriting initial state values with requests emitted by */
   /* submodels that have a more global view (cf. register.c mechanism) */
   /* Can also fire some callbacks to 'fix' float and integer store */
   OverloadStatesWithRegister(amesys, amesys->states, SVREGISTER_DEFAULT);

   CheckSimParams(amesys, &amesys->simOptions->abstol,
                  &amesys->simOptions->reltol,
                  &amesys->simOptions->hMax);

#ifdef AME_RESULT_FILE
   /*  Open file for results. */
   amesys->AmeReadFile(amesys, &time, amesys->states);
#endif

   if(isconrun_() || isusefinval_())
   {
      updateStatesFromModel(amesys, amesys->states, AME_CONTINUOUS_STATE|AME_DISCRETE_STATE);
   }

   /* Read linear analysis specification. */
#ifndef FMI
   SetLADetails(GetLAFileName(), amesys->numstates, amesys->numvars, time,  amesys->simOptions->reltol, amesys->simOptions->abstol, getfinaltime_()-time);

   /* Remove old err file */

   remove(GetErrorFileName());

   /* Initialize the Performance analyzer */
   if(!isfixedstepsolver_()) {
      PerfAnalyzer_Init(amesys, time, getfinaltime_() );
   }
#endif
   if(isconrun_())
      setstarttime_(time);

   /* Set the locked states info */
   ameSetUpLockedStatus(amesys);

   return 1;
#else
   char error_message[256];
   sprintf(error_message, "AMEInitializeConditions> Should never be called for real-time simulation\n");
   DisplayMessage(error_message);
   return 0;
#endif
}

#if(AME_MODEL_ISEXPLICIT == 1)
static int ameEvalTstartFixed(AMESIMSYSTEM *amesys, const double *modelInputs, double *modelOutputs)
{
   double time = getstarttime_();

   ameInputs(amesys, AME_NBOF_INPUTS, modelInputs);

   doAssembly(amesys);

   amesys->tlast = time;

   /* Evaluation of the model at tStart */
   {
      int local_flag = 0;
      SetIsPrinting(amesys);
      amesys->FuncEval(amesys, time, amesys->states, amesys->yh, NULL, &local_flag);
      ClearIsPrinting(amesys);

#if defined(AME_RESULT_FILE) && !defined(STANDALONESIMULATOR)
      amesys->OutputResults(amesys, amesys->tlast);
      amesys->resultFileStructPtr->lastprinttime = amesys->tlast;
#endif

      /* Now, amesys->first_call == 0 (set at the end of FunctionEval) */
   }

#if (AME_NBOF_OUTPUTS > 0)
   memcpy(modelOutputs, amesys->outputs,amesys->numoutputs*sizeof(double) );
#endif
   amesys->tlast = time;

#ifdef AME_PROCESS_TIME
   /* Initialization of time timers */
   ProcessTime(0);
#endif

   return 1;
}

static int ameInitializeConditionsFixed(AMESIMSYSTEM *amesys)
{
   double start_time = amesys->simOptions->tStart;

   assert(amesys);

   amesys->first_call=1;  /* should this be done or not ?*/

   amesys->tlast=TLAST_MIN;

   /* Init solver */
   memset(amesys->yh,0,(AME_NBOF_SOLVER_STATES*13)*sizeof(double));

   InitFixedStepIntegrate(amesys);

   setfinaltime_(amesys->simOptions->tFinal);

   /* Call Input to read submodel and simulation parameters. */
   if(Input(amesys) != AME_NO_ERROR) return 0;
   modelSetInitValues(amesys->pModel, amesys->states, amesys->discrete_states);

   SetInitPrintIntervalFromSimOpts(amesys);

   setstarttime_(start_time);

   /* Call pre-initialize function */

   PreInitialize(amesys,amesys->states);

#ifndef AME_INPUT_IN_MEMORY
   if( NeedReloadInputFiles() != 0 )
   {
      ClearGPs();
      if(Input(amesys) != AME_NO_ERROR) return 0;
      modelSetInitValues(amesys->pModel, amesys->states, amesys->discrete_states);
      ClearReloadedFiles();
   }
#endif

   /* Call initialize subroutine to set con and icon array members */

   Initialize(amesys,amesys->states);

   /* Overwriting initial state values with requests emitted by */
   /* submodels that have a more global view (cf. register.c mechanism) */
   /* Can also fire some callbacks to 'fix' float and integer store */
   OverloadStatesWithRegister(amesys, amesys->states, SVREGISTER_DEFAULT);

#ifdef AME_RESULT_FILE
   /*  Open file for results. */
   amesys->AmeReadFile(amesys, &start_time, amesys->states);
#endif

   if(isconrun_() || isusefinval_())
   {
      updateStatesFromModel(amesys, amesys->states, AME_CONTINUOUS_STATE|AME_DISCRETE_STATE);
   }

   /* Set the locked states info */
   ameSetUpLockedStatus(amesys);

   if(isconrun_()) {
      setstarttime_(start_time);
   }

   return 1;
}
#endif

/*=============================================================================*/

/*=============================================================================*/

/***********************************************************
   Purpose    : Test request acceptance
   Author	  : J.Andre
   Created on : 2016 - 09 - 05
   Inputs	  :
      event   : entry event
   Outputs	  :
      AME_NO_ERROR : event accepted
      AME_SEQUENCE_ERROR : event refused
   Revision   :
************************************************************/
static AMESystemError AmesysControlRequest(AMESIMSYSTEM *amesys, AMESystemCmd event)
{
   AMESystemError res = AME_NO_ERROR;

   if(!amesys) {
      if(event == AME_CMD_GET_MODEL_INFO) {
         return AME_NO_ERROR;
      }
      return AME_SEQUENCE_ERROR;
   }

   switch(event) {
      case AME_CMD_RELEASE: {
         if( !(amesys->systemState & (AMESTATE_TERMINATED | AMESTATE_FATAL | AMESTATE_INSTANTIATED)) ) {
            res = AME_SEQUENCE_ERROR;
         }
      }
      break;
      case AME_CMD_SETUP: {
         if( !(amesys->systemState & AMESTATE_INSTANTIATED) ) {
            res = AME_SEQUENCE_ERROR;
         }
      }
      break;
      case AME_CMD_INITIALIZE: {
         if(amesys->systemState != AMESTATE_READY) {
            res = AME_SEQUENCE_ERROR;
         }
      }
      break;
      case AME_CMD_TERMINATE: {
         if( !(amesys->systemState & (AMESTATE_RUN | AMESTATE_READY | AMESTATE_ERROR)) ) {
            res = AME_SEQUENCE_ERROR;
         }
      }
      break;
      case AME_CMD_TSTART: {
         if( !(amesys->systemState & AMESTATE_INITIALIZED) ) {
            res = AME_SEQUENCE_ERROR;
         }
      }
      break;
      case AME_CMD_STEP: {
         if( !(amesys->systemState & AMESTATE_RUNNING) ) {
            res = AME_SEQUENCE_ERROR;
         }
         else {
            amesys->systemState |= AMESTATE_STEP_IN_PROGRESS;
         }
      }
      break;
      case AME_CMD_RESTART: {
         /* At this time, it is not still implemented */
         /* Depends of clean-up in terminated state and static variables */
         res = AME_SEQUENCE_ERROR;
      }
      break;
      case AME_CMD_GET_MODEL_INFO: {
         res = AME_NO_ERROR;
      }
      break;
      case AME_CMD_SET_MODEL_PARAM_TUNABLE: {
         if( !(amesys->systemState & (AMESTATE_READY | AMESTATE_RUN)) ) {
            res = AME_SEQUENCE_ERROR;
         }
      }
      break;
      case AME_CMD_SET_MODEL_PARAM:
      case AME_CMD_SET_RUN_PARAM:
      case AME_CMD_SET_SOLVER_PARAM: {
         if(amesys->systemState != AMESTATE_READY) {
            res = AME_SEQUENCE_ERROR;
         }
      }
      break;
      case AME_CMD_GET_MODEL_PARAM:
      case AME_CMD_GET_SOLVER_PARAM:
      case AME_CMD_GET_RUN_PARAM: {
         if( !(amesys->systemState & (AMESTATE_READY | AMESTATE_RUN | AMESTATE_ERROR)) ) {
            res = AME_SEQUENCE_ERROR;
         }
      }
      break;
      case AME_CMD_REQ_RUN_INTERRUPT: {
         if( !(amesys->systemState & (AMESTATE_INSTANTIATED | AMESTATE_READY | AMESTATE_INITIALIZED | AMESTATE_RUNNING)) ) {
            res = AME_SEQUENCE_ERROR;
         }
      }
      break;
      case AME_CMD_SET_ENV: {
         if( !(amesys->systemState & AMESTATE_INSTANTIATED) ) {
            res = AME_SEQUENCE_ERROR;
         }
      }
      break;
      case AME_CMD_FUNCEVAL: {
         if( !(amesys->systemState & AMESTATE_RUNNING) ) {
            res = AME_SEQUENCE_ERROR;
         }
      }
      break;
      default:
         res = AME_SEQUENCE_ERROR;
      break;
   }

   return res;
}

/***********************************************************
   Purpose    : Update state and manage result of request
   Author	  : J.Andre
   Created on : 2016 - 09 - 05
   Inputs	  :
      event   : entry event
      reqResult : result of request achievement
   Outputs	  :
      AME_NO_ERROR : event accepted
      AME_SEQUENCE_ERROR : event refused
   Revision   :
************************************************************/
static AMESystemError AmesysUpdateState(AMESIMSYSTEM *amesys, AMESystemCmd event, AMESystemError reqResult)
{
   unsigned int newState;
   AMESystemError res;

   if(!amesys) {
      return AME_SEQUENCE_ERROR;
   }

   newState = amesys->systemState;   /* Default: no change in state */
   res = reqResult;                  /* Default: no change in result */

   switch(event) {
      case AME_CMD_INSTANTIATE: {
         if(reqResult != AME_NO_ERROR) {
            newState = AMESTATE_FATAL;
         }
         else {
            newState = AMESTATE_INSTANTIATED;
         }
      }
      break;
      case AME_CMD_SETUP: {
         if(reqResult != AME_NO_ERROR) {
            newState = AMESTATE_FATAL;
         }
         else {
            newState = AMESTATE_READY;
         }
      }
      break;
      case AME_CMD_INITIALIZE: {
         if(reqResult != AME_NO_ERROR) {
            newState = AMESTATE_ERROR;
         }
         else {
            newState = AMESTATE_INITIALIZED;
         }
      }
      break;
      case AME_CMD_TERMINATE: {
         if(reqResult != AME_NO_ERROR) {
            amesys->systemState = AMESTATE_TERMINATED; /* Avoid automatic call to ameterminate */
            newState = AMESTATE_FATAL;
         }
         else {
            newState = AMESTATE_TERMINATED;
         }
      }
      break;
      case AME_CMD_TSTART: {
         if(reqResult != AME_NO_ERROR) {
            newState = AMESTATE_ERROR;
         }
         else {
            newState = AMESTATE_RUNNING;
         }
      }
      break;
      case AME_CMD_STEP: {
         if(reqResult != AME_NO_ERROR) {
            /* test ameExitStatus */
            if(reqResult == AME_EXIT_ERROR) {
               if(amesys->ameExitStatus == 0) {
                  /* Simulation stopped early but normally */
                  amesys->requestinterrupt = 0;
                  newState = AMESTATE_STOPPED_EARLY;
                  res = AME_NO_ERROR;
               }
               else
               {
                  newState = AMESTATE_ERROR;
               }
            }
            else {
               newState = AMESTATE_ERROR;
            }
         }
         else if(amesys->requestinterrupt) {
            amesys->requestinterrupt = 0;
            newState = AMESTATE_STOPPED_END;
         }
         newState &= ~AMESTATE_STEP_IN_PROGRESS;
      }
      break;
      case AME_CMD_REQ_RUN_INTERRUPT:
      break;
      case AME_CMD_FUNCEVAL: {
         if(reqResult != AME_NO_ERROR) {
            /* test ameExitStatus */
            if(reqResult == AME_EXIT_ERROR) {
               if(amesys->ameExitStatus == 0) {
                  /* Simulation stopped early but normally */
                  newState = AMESTATE_STOPPED_EARLY;
                  res = AME_NO_ERROR;
               }
               else
               {
                  newState = AMESTATE_ERROR;
               }
            }
            else {
               newState = AMESTATE_ERROR;
            }
         }
      }
      break;
      default:
      /* No state change, no exception to catch, just pass result */
      break;
   }

   if(amesys->systemState != newState) {
      if(newState == AMESTATE_FATAL) {
         if(amesys->systemState & (AMESTATE_RUN | AMESTATE_READY | AMESTATE_ERROR)) {
            /* Terminating the simulation */
            ameTerminate(amesys);
         }
      }

#if !defined(STANDALONESIMULATOR)
      if(newState & (AMESTATE_FATAL | AMESTATE_ERROR)) {
         if(amesys->systemState & AMESTATE_RUN) {
            amefprintf(stderr, "Simcenter Amesim model: simulation failed.\n");
         }
         else if(amesys->systemState & AMESTATE_IDLE) {
            amefprintf(stderr, "Simcenter Amesim model: instantiation failed.\n");
         }
         else if(amesys->systemState & AMESTATE_READY) {
            amefprintf(stderr, "Simcenter Amesim model: initialization failed.\n");
         }
      }
      else if(newState & AMESTATE_INITIALIZED) {
         amefprintf(stdout, "Simcenter Amesim model: initialization done.\n");
      }
      else if(newState & AMESTATE_TERMINATED) {
         amefprintf(stdout, "Simcenter Amesim model: simulation terminated.\n");
      }
      else if((newState & AMESTATE_RUNNING) && (amesys->systemState & AMESTATE_INITIALIZED)) {
         amefprintf(stdout, "Simcenter Amesim model: simulation started.\n");
      }
#endif

      /* Update state */
      amesys->systemState = newState;
   }

   if(amesys->systemState == AMESTATE_FATAL) {
      /* Greedy error */
      res = AME_FATAL_ERROR;
   }

   return res;
}

/***********************************************************
   Purpose    : Instantiate the system
   Author	  : J.Andre
   Created on : 2016 - 09 - 08
   Inputs	  : None
   Outputs	  : Error code
   Revision   :
************************************************************/
static AMESystemError AmesysInstantiate(AMESIMSYSTEM **amesysPtr)
{
   int jump_ret;
   AMESIMSYSTEM *amesys;
   AMESystemError result = AME_FATAL_ERROR;

   S_AME_Model *pModel;

   if(*amesysPtr != NULL) {
      return AME_SEQUENCE_ERROR;
   }

   result = createModel(&pModel, &GmodelDef, GParamInfo, GVarInfo, GsubmodelNameArray,
                        GcontStateVarNum, GdiscStateVarNum, GFixedVarNum);

   if(result == AME_NO_ERROR) {
#if(AME_MODEL_ISEXPLICIT == 1)
      amefprintf(stdout, "Instantiating a system with %d unknowns.\n", AME_NBOF_EXPLICIT_STATE);
#else
      amefprintf(stdout, "Instantiating a system with %d unknowns.\n", AME_NBOF_SOLVER_STATES);
#endif
      if (strcmp(soldToId,"not available") != 0)
         amefprintf(stdout, "Simcenter Amesim version: %s (%s).\n", "2404", soldToId);
      else
         amefprintf(stdout, "Simcenter Amesim version: %s.\n", "2404");
      result = createAMESystem(&amesys, pModel, AME_NBOF_SOLVER_STATES, AMEVERSION);
   }
#if (AME_NB_SUBMODEL_REF>0)
   if(result == AME_NO_ERROR) {
      int idx_sub;
      for(idx_sub = 0; idx_sub < AME_NB_SUBMODEL_REF; idx_sub++) {
         S_AMESubSimuInfo info;
         info.rp = SUBSIMU[idx_sub][0][0] > 0 ? &pModel->realParamArray[SUBSIMU[idx_sub][0][1]] : NULL;
         info.ip = SUBSIMU[idx_sub][1][0] > 0 ? &pModel->integerParamArray[SUBSIMU[idx_sub][1][1]] : NULL;
         info.tp = (const char **)(SUBSIMU[idx_sub][2][0] > 0 ? &pModel->textParamArray[SUBSIMU[idx_sub][2][1]] : NULL);
         info.c = SUBSIMU[idx_sub][3][0] > 0 ? &pModel->realStoreArray[SUBSIMU[idx_sub][3][1]] : NULL;
         info.ic = SUBSIMU[idx_sub][4][0] > 0 ? &pModel->intStoreArray[SUBSIMU[idx_sub][4][1]] : NULL;
         info.ps = SUBSIMU[idx_sub][5][0] > 0 ? &pModel->pointerStoreArray[SUBSIMU[idx_sub][5][1]] : NULL;
         info.na = pModel->ptrNetWorkArray;
         result |= setSubSimuParam(pModel, idx_sub, &info);
      }
   }
#endif

   if(result == AME_NO_ERROR) {
      if( (jump_ret = setjmp(amesys->jump_env)) == 0) { /* ~try */
         SetGlobalSystem(amesys);

#ifdef AME_INPUT_IN_MEMORY
         amesys->getssflist = getssflist;
#endif
         amesys->consflag = 0;

#if(AME_MODEL_ISEXPLICIT == 1)
         amesys->FuncEval = localFuncEval;
         amesys->JFuncEval = localJFuncEval;
#else
         amesys->res = localFuncEval;
         amesys->Jres = localJFuncEval;
#endif
         amesys->AmeExit = ModelAmeExit;

         amesys->ameExitStatus = 0;

         /* Set input directory to current directory */
         AmeSetInputDir(amesys,NULL);

         /* Set output directory to current directory */
         AmeSetOutputDir(amesys,NULL);

         /* Set base name of input files, no extension */
         AmeSetModelBaseName(amesys,"exp9_", NULL);

         result = AME_NO_ERROR;
      }
      else { /* Catch AmeExit */
         result = AME_EXIT_ERROR;
      }
   }

   if(result == AME_NO_ERROR) {
      /* Update state and result */
      result =  AmesysUpdateState(amesys, AME_CMD_INSTANTIATE, result);
   }

   if(result != AME_NO_ERROR) {
      deleteAMESystem(&amesys);
      SetGlobalSystem(NULL);
   }
   else {
      *amesysPtr = amesys;
   }

   return result;
}

static AMESystemError AmesysTerminate(AMESIMSYSTEM *amesys)
{
   int jump_ret;
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_TERMINATE);
   if(res != AME_NO_ERROR) {
      /* Request not accepted */
      return res;
   }

   if(res == AME_NO_ERROR) { /* Request accepted */
      if( (jump_ret = setjmp(amesys->jump_env)) == 0) { /* ~try */
         ameTerminate(amesys);
      }
      else { /* Catch AmeExit */
         res = AME_EXIT_ERROR;
      }
   }

   /* Update state and result */
   res =  AmesysUpdateState(amesys, AME_CMD_TERMINATE, res);

   return res;
}

static AMESystemError AmesysRelease(AMESIMSYSTEM **amesysPtr)
{
   AMESystemError res = AME_NO_ERROR;
   if(*amesysPtr) {
      SetGlobalSystem(*amesysPtr);
      res = AmesysControlRequest(*amesysPtr, AME_CMD_RELEASE);

      if(res == AME_NO_ERROR) { /* Request accepted */
         AmeSignalModelUnload();
         res = deleteAMESystem(amesysPtr);
         SetGlobalSystem(NULL);
      }
   }
   return res;
}

/***********************************************************
   Purpose    : Go in Ready state to be able receive external
                initialization of model and simulation
   Author	  : J.Andre
   Created on : 2016 - 09 - 08
   Inputs	  : loadParam: if true, model parameters are read
   Outputs	  : Error code
   Revision   :
************************************************************/
static AMESystemError AmesysSetUp(AMESIMSYSTEM *amesys, const int loadParam)
{
   int jump_ret;
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SETUP);

   if(res != AME_NO_ERROR) {
      /* Request not accepted */
      return res;
   }

   if( (jump_ret = setjmp(amesys->jump_env)) == 0) { /* ~try */
      amesys->ameExitStatus = 0;

      /* Construct file names */
      AmeConstructFileName(amesys);

      /* Read sim file */
      {
         SIMOptions opts;

#ifndef AME_INPUT_IN_MEMORY
         char errMsg[PATH_MAX+128];
         int result = readsimfile(&opts, GetSimFileName(), errMsg);
#else
         int result = readsimfromchararrays(&opts, simparams, simparams_length);
#endif

         if(result != 0) {

            /* Initialyze Amesystem SIMOptions */
            memcpy(amesys->simOptions,&opts,sizeof(SIMOptions));

#ifdef AME_RESULT_FILE
            amesys->simOptions->outoff = 0;
#else
            amesys->simOptions->outoff = 1;
#endif

#ifdef AME_PERFORMANCE_ANALYZER
            ALA_Setparam(opts.autoLA, 1, opts.autoLAstep);
            DISCLOG_SetParam(1);
#endif
         }
         else {
            res = AME_SETUP_ERROR;
         }
      }

      if(loadParam) {
         /* Load parameters */
         loadModelParameters(amesys);
      }

   }
   else { /* Catch AmeExit */
      res = AME_EXIT_ERROR;
   }

   /* Update state and result */
   res =  AmesysUpdateState(amesys, AME_CMD_SETUP, res);

   return res;
}

/***********************************************************
   Purpose    : Initialize the model
   Author	  : J.Andre
   Created on : 2016 - 09 - 08
   Inputs	  : None
   Outputs	  : Error code
   Revision   :
************************************************************/
static AMESystemError AmesysInitialize(AMESIMSYSTEM *amesys)
{
   int jump_ret;
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_INITIALIZE);

   if(res != AME_NO_ERROR) {
      /* Request not accepted */
      return res;
   }

   if( (jump_ret = setjmp(amesys->jump_env)) == 0) { /* try */
      if(amesys->simOptions->runType & 0x20) {
         /* fixed step initialization */
#if(AME_MODEL_ISEXPLICIT == 1)
         ameSetOptionsFixed(amesys, amesys->simOptions->tInc, amesys->simOptions->fixedType,
            amesys->simOptions->fixedOrder, amesys->simOptions->fixedH, amesys->simOptions->runType);

         if(!ameInitializeConditionsFixed(amesys)) {
            res = AME_INITIALIZE_ERROR;
         }
#else
         amefprintf(stderr,"It is not possible to use a fixed step solver\nfor implicit systems.\n");
         res = AME_INITIALIZE_ERROR;
#endif
      }
      else {
#ifdef AME_VSOLVER_ACCEPTED
         /* variable step initialization */
         ameSetOptions(amesys, amesys->simOptions->tInc, amesys->simOptions->hMax, amesys->simOptions->tol,
            amesys->simOptions->errorType, amesys->simOptions->iWrite, amesys->simOptions->rStrtp,
            amesys->simOptions->statistics, amesys->simOptions->runType, amesys->simOptions->solverType);

         if(!ameInitializeConditions(amesys)) {
            res = AME_INITIALIZE_ERROR;
         }
#else
         amefprintf(stderr,"It is not possible to use a variable step solver\nfor this interface.\n");
         res = AME_INITIALIZE_ERROR;
#endif
      }

#if defined(AME_MEMORY_ACCESS_RT_EXPORT)
#if (NB_WATCH_VAR>0)
         RT_Get_Watch_Var(amesys);
#endif
#endif

   }
   else { /* Catch AmeExit */
      res = AME_EXIT_ERROR;
   }

   /* Update state and result */
   res =  AmesysUpdateState(amesys, AME_CMD_INITIALIZE, res);

   return res;
}

#if(AME_MODEL_ISEXPLICIT == 1)
static void doAFixedStep(AMESIMSYSTEM *amesys, double time)
{
   double timerange;
   double actual_timestep;
   int stepratio;
   int stepratio_ceil;
   int stepratio_floor;
   int i=0;
   int zero=0;
   double tinc;
   int isTimeForPrint=0;
   double next_print_time;

   if (amesys->first_call)
   {
      SetIsPrinting(amesys);
      amesys->FuncEval(amesys, amesys->tlast, amesys->states, amesys->yh, NULL, &zero);
      ClearIsPrinting(amesys);

#if defined(AME_RESULT_FILE) && !defined(STANDALONESIMULATOR)
      amesys->OutputResults(amesys, amesys->tlast);
      amesys->resultFileStructPtr->lastprinttime = amesys->tlast;
#endif
   }

   timerange = time - amesys->tlast;

   if(timerange <= 0.0)
   {
      return;
   }
   if(amesys->simOptions->fixedH > 0.0)
   {
      stepratio = stepratio_ceil = (int)ceil(timerange/amesys->simOptions->fixedH);
      stepratio_floor = (int)floor(timerange/amesys->simOptions->fixedH);

      actual_timestep = timerange/(double)stepratio_ceil;

      if(fabs(actual_timestep-amesys->simOptions->fixedH) > 0.001*amesys->simOptions->fixedH)
      {
         if(stepratio_floor == 0)
         {
#ifdef AMEDEBUG
            amefprintf(stdout,"skipping %14.8e  range= %14.8e  actual_timestep=%14.8e stepratio_ceil=%d   stepratio_floor=%d\n",time, timerange, actual_timestep, stepratio_ceil,stepratio_floor);
#endif
            return;
         }

#ifdef AMEDEBUGw
         amefprintf(stdout,"using floor\n");
         amefprintf(stdout,"timerange=%14.8e\n", timerange);
         amefprintf(stdout,"actual_timestep=%14.8e\n", actual_timestep);
         amefprintf(stdout,"amesys->simOptions->fixedH=%14.8e\n", amesys->simOptions->fixedH);
         amefprintf(stdout,"fabs(actual_timestep-amesys->simOptions->fixedH)=%14.8e\n", fabs(actual_timestep-amesys->simOptions->fixedH));
         amefprintf(stdout,"stepratio_floor=%d\n", stepratio_floor);
         amefprintf(stdout,"stepratio_ceil=%d\n", stepratio_ceil);
#endif
         actual_timestep = timerange/(double)stepratio_floor;
         stepratio = stepratio_floor;
      }

      if(fabs(actual_timestep-amesys->simOptions->fixedH) > 0.001*amesys->simOptions->fixedH)
      {
#ifdef AMEDEBUGw
         amefprintf(stdout,"Adjusting time step %14.8e => %14.8e\n", amesys->simOptions->fixedH, actual_timestep);
         amefprintf(stdout,"stepratio_floor=%d\n", stepratio_floor);
         amefprintf(stdout,"stepratio_ceil=%d\n", stepratio_ceil);
         amefprintf(stdout,"stepratio=%d\n", stepratio);
         amefprintf(stdout,"timerange=%14.8e\n", timerange);
#endif
      }
   }
   else
   {
      /* just single step from the last point in time when we were called */
      stepratio=1;
      actual_timestep = timerange;
   }

#if defined(AME_RESULT_FILE) && !defined(STANDALONESIMULATOR)
   if(amesys->resultFileStructPtr && !amesys->resultFileStructPtr->outoff)
   {
      next_print_time = GetNextPrintTime(&tinc, amesys->resultFileStructPtr->lastprinttime, amesys->simOptions->tFinal, amesys->simOptions->tInc, actual_timestep);
   }
#endif

#ifdef AMERT
   /* Allow changes of the stepratio - typically on RT platforms. */
   {
      double localstepratio=floor(IL_exp9_step_ratio);
      if (localstepratio >= 1)
      {
         actual_timestep=timerange/localstepratio;
         stepratio = (int)localstepratio;
      }
   }
#endif
#ifdef STANDALONESIMULATOR
   FixedStepIntegrate(amesys,AME_NBOF_SOLVER_STATES,amesys->tlast,time,amesys->simOptions->tInc,amesys->states,
         amesys->yh,amesys->simOptions->fixedType,amesys->simOptions->fixedOrder,actual_timestep);
#else
	for (i=0; (i<stepratio) && (amesys->requestinterrupt == 0);i++)
   {
      /*Integrate one step */
	  if ( amesys->simOptions->fixedType == 1)
	  {
		DoAnABStep(amesys, amesys->numstates, amesys->simOptions->fixedOrder, &amesys->tlast, actual_timestep, amesys->states, amesys->yh);
	  }
	  else
	  {
		DoAnRKStep(amesys, amesys->numstates, amesys->simOptions->fixedOrder, &amesys->tlast, actual_timestep, amesys->states, amesys->yh);
	  }

#ifndef AMERT
      isTimeForPrint = amesys->resultFileStructPtr && (!amesys->resultFileStructPtr->outoff && ((amesys->tlast >= next_print_time) || ((next_print_time-amesys->tlast)/tinc < TIME_ROUNDOFF)));
      if(isTimeForPrint)
      {
#ifdef AME_PROCESS_TIME
         ProcessTime(1);
#endif
         SetIsPrinting(amesys);
         amesys->FuncEval(amesys, amesys->tlast, amesys->states, amesys->yh, NULL, &zero);
         ClearIsPrinting(amesys);
         amesys->OutputResults(amesys,amesys->tlast);
         next_print_time = GetNextPrintTime(&tinc, amesys->tlast, amesys->simOptions->tFinal, amesys->simOptions->tInc, actual_timestep);
      }
      else
#endif
      {
         amesys->FuncEval(amesys, amesys->tlast, amesys->states, amesys->yh, NULL, &zero);
      }
   }
#endif
   amesys->tlast = time;
}
#endif

static int ameOutputs(AMESIMSYSTEM *amesys, double timeARG, int numOutputs, double *outputARG)
{
   int theprintflag=1;
   double *dot;
   double *v;

   assert(amesys);

   v = amesys->v;
   dot = amesys->dotstates;

   if(numOutputs != amesys->numoutputs)
   {
      char error_message[256];
      sprintf(error_message, "AMEOutputs> Expected %d outputs but got %d\n", amesys->numoutputs, numOutputs);
      DisplayMessage(error_message);
      AmeExit(1);
   }

   if (!isdynrun_())
   {
      /* it is not a dynamic run (neither dynamic nor stabilizing + dynamic) */
      /* stabilizing has already been processed during Init.*/
      /*Exit */
      return 1;
   }

   if(timeARG < amesys->tlast)
   {
      DisplayMessage("trying to integrate backwards\n");
      return 0;
   }
#if(AME_MODEL_ISEXPLICIT == 1)
   amesys->t_end_of_time_slice = timeARG;
#ifndef AMERT
   if(!isfixedstepsolver_())
   {
      if(!IntegrateStep(amesys, amesys->tlast, timeARG))
      {
         DisplayMessage("IntegrateStep failed");
         return 0;
      }
      amesys->tlast = timeARG;
   }
   else
   {
      doAFixedStep(amesys, timeARG);
   }
#else
   doAFixedStep(amesys, timeARG);
#endif

#else
   if(!DIntegrateStep(amesys, AME_NBOF_EXPLICIT_STATE, amesys->tlast, timeARG, amesys->simOptions->tInc, amesys->states,
      amesys->dotstates, amesys->simOptions->hMax, AME_NBOF_SOLVER_STATES, amesys->iwork, amesys->simOptions->reltol,
      amesys->simOptions->abstol, amesys->simOptions->rStrtp, LIW, LRW, amesys->simOptions->statistics,
      amesys->simOptions->stabilOption, amesys->simOptions->iWrite, amesys->simOptions->minimalDiscont,
      amesys->internal_discont, Gis_constraint, &amesys->requestinterrupt))
   {
      DisplayMessage("DIntegrateStep failed");
      return 0;
   }

   amesys->tlast = timeARG;
#endif

#if (AME_NBOF_OUTPUTS > 0)
   memcpy(outputARG, amesys->outputs, amesys->numoutputs*sizeof(double) );
#endif

   return 1;
}

static AMESystemError AmesysComputeAtTstart(AMESIMSYSTEM *amesys, const double *theInputs, double *theOutputs)
{
   int jump_ret;
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_TSTART);

   if(res != AME_NO_ERROR) {
      /* Request not accepted */
      return res;
   }

   if( (jump_ret = setjmp(amesys->jump_env)) == 0) { /* try */
      if(amesys->simOptions->runType & 0x20) {
         /* fixed step solver */
#if(AME_MODEL_ISEXPLICIT == 1)
         if(!ameEvalTstartFixed(amesys, theInputs, theOutputs)) {
            res = AME_INITIALIZE_ERROR;
         }
#else
         amefprintf(stderr,"It is not possible to use a fixed step solver\nfor implicit systems.\n");
         res = AME_INITIALIZE_ERROR;
#endif
      }
      else {
         /* variable step solver */
         if(!ameEvalTstart(amesys, theInputs, theOutputs)) {
            res = AME_INITIALIZE_ERROR;
         }
      }

   }
   else { /* Catch AmeExit */
      res = AME_EXIT_ERROR;
   }

   /* Update state and result */
   res =  AmesysUpdateState(amesys, AME_CMD_TSTART, res);

   return res;
}

/***********************************************************
   Purpose    : Do a co-simulation step
   Author	  : J.Andre
   Created on : 2016 - 09 - 12
   Inputs	  : None
   Outputs	  : Error code
   Revision   :
************************************************************/
static AMESystemError AmesysStep(AMESIMSYSTEM *amesys, int stepType, const double t, const double *theInputs, double *theOutputs,
   const int doInterpol, const unsigned int *orderTab, const double **polyTab, const E_CS_Reset cs_reset)
{
   int jump_ret;
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_STEP);

   if(res != AME_NO_ERROR) {
      /* Request not accepted */
      return res;
   }

   if( (jump_ret = setjmp(amesys->jump_env)) == 0) { /* try */

#if defined(AME_MEMORY_ACCESS_RT_EXPORT)
#if (NB_WATCH_REAL_PARAM>0) || (NB_WATCH_INT_PARAM>0)
      RT_Set_Watch_Param(amesys);
#endif
#endif

#if defined(AME_COSIM) && (AME_NBOF_INPUTS > 0) && (!defined(AMERT))
      amesys->doInterpol = doInterpol;

      if(amesys->doInterpol) {
         stepType = 1;
         res = setPolyCosimSlave(amesys->csSlave, orderTab, polyTab);
      }
      else {
         res = setPolyCosimSlaveByInputs(amesys->csSlave, theInputs);
      }
#else
      amesys->doInterpol = 0;
#endif

      if(res == AME_NO_ERROR) {
         if(stepType == 0) {  /* Do a step */
            if(!ameOutputs(amesys, t, AME_NBOF_OUTPUTS, theOutputs)) {
               res = AME_STEP_ERROR;
            }
#ifndef AMERT
            amesys->input_discont = CheckIfColdStartNeed(amesys, theInputs, cs_reset);
            /* Need to do something here if no internal disc and disc printout */
            AddExtraPrintOut(amesys, amesys->tlast);
#endif
            if(amesys->doInterpol == 0) {
               if(!ameInputs(amesys, AME_NBOF_INPUTS, theInputs)) {
                  res = AME_STEP_ERROR;
               }
            }
         }
         else {  /* Do a step 2 */
#ifndef AMERT
            amesys->input_discont = CheckIfColdStartNeed(amesys, theInputs, cs_reset);

            /* Need to do something here if no internal disc and disc printout */
            res |= changePolynomialSlot(amesys->csSlave);
            AddExtraPrintOut(amesys, amesys->tlast);
            res |= changePolynomialSlot(amesys->csSlave);
#endif
            if(amesys->doInterpol == 0) {
               if(!ameInputs(amesys, AME_NBOF_INPUTS, theInputs)) {
                  res = AME_STEP_ERROR;
               }
            }

            if(!ameOutputs(amesys, t, AME_NBOF_OUTPUTS, theOutputs)) {
               res = AME_STEP_ERROR;
            }
#ifndef AMERT
            if(amesys->doInterpol != 0) {
               if( getInputsCosimSlave(amesys->csSlave, t, amesys->inputs) != AME_NO_ERROR ) {
                  res = AME_STEP_ERROR;
               }
            }
#endif
         }
         amesys->num_steps_taken++;
#ifndef AMERT
         res |= changePolynomialSlot(amesys->csSlave);
         res |= setTciCosimSlave(amesys->csSlave, t);
#endif
      }

#if defined(AME_MEMORY_ACCESS_RT_EXPORT)
#if (NB_WATCH_VAR>0)
      RT_Get_Watch_Var(amesys);
#endif
#endif
   }
   else { /* Catch AmeExit */
      res = AME_EXIT_ERROR;
   }

   /* Update state and result */
   res =  AmesysUpdateState(amesys, AME_CMD_STEP, res);

   return res;
}

/***********************************************************
   Purpose    : Set solver parameters
   Author	  : J.Andre
   Created on : 2016 - 09 - 09
   Inputs	  : None
   Outputs	  :
   Revision   :
************************************************************/
static AMESystemError AmesysSetSolverParam(AMESIMSYSTEM *amesys, const solverSettings *solver)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_SOLVER_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      /* Initialyze Amesystem solver parameters */
      simOptSetSolverParam(amesys->simOptions,solver);
   }

   return res;
}

/***********************************************************
   Purpose    : Get solver parameters
   Author	  : J.Andre
   Created on : 2016 - 09 - 09
   Inputs	  : None
   Outputs	  :
   Revision   :
************************************************************/
static AMESystemError AmesysGetSolverParam(AMESIMSYSTEM *amesys, solverSettings *solver)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_GET_SOLVER_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      /* Initialyze Amesystem solver parameters */
      simOptGetSolverParam(amesys->simOptions, solver);
   }

   return res;
}

/***********************************************************
   Purpose    : Set run parameters
   Author	  : J.Andre
   Created on : 2016 - 09 - 09
   Inputs	  : None
   Outputs	  :
   Revision   :
************************************************************/
static AMESystemError AmesysSetSimParam(AMESIMSYSTEM *amesys, const simSettings *simOpt)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      /* Initialyze Simulation parameters */
      simOptSetSimParam(amesys->simOptions,simOpt);
   }

   return res;
}

static AMESystemError AmesysGetSimParam(AMESIMSYSTEM *amesys, simSettings *simOpt)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_GET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      /* Get Simulation parameters */
      simOptGetSimParam(amesys->simOptions, simOpt);
   }

   return res;
}

static AMESystemError AmesysSetSimItem(AMESIMSYSTEM *amesys, const int Id, const int enabled)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      /* Initialyze Amesystem solver parameters */
      if(simOptSetOneOfSimParam(amesys->simOptions, Id, enabled) != 0) {
         res = AME_SETTINGS_ERROR;
      }
   }

   return res;
}

static AMESystemError AmesysGetSimItem(AMESIMSYSTEM *amesys, const int Id, int *enabled)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_GET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      /* Initialyze Amesystem solver parameters */
      if(simOptGetOneOfSimParam(amesys->simOptions, Id, enabled) != 0) {
         res = AME_SETTINGS_ERROR;
      }
   }

   return res;
}

/***********************************************************
   Purpose    : Set run parameters
   Author	  : J.Andre
   Created on : 2016 - 09 - 09
   Inputs	  : None
   Outputs	  :
   Revision   :
************************************************************/
static AMESystemError AmesysSetStdOptions(AMESIMSYSTEM *amesys, const stdOptions *stdOpt)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      /* Initialize standard parameters */
      simOptSetStdParam(amesys->simOptions,stdOpt);
   }

   return res;
}

static AMESystemError AmesysGetStdOptions(AMESIMSYSTEM *amesys, stdOptions *stdOpt)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_GET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      /* Get standard parameter */
      simOptGetStdParam(amesys->simOptions, stdOpt);
   }

   return res;
}

static AMESystemError AmesysSetStdItem(AMESIMSYSTEM *amesys, const int Id, const int enabled)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      /* Initialize standard parameter */
      if(simOptSetOneOfStdParam(amesys->simOptions, Id, enabled) != 0) {
         res = AME_SETTINGS_ERROR;
      }
   }

   return res;
}

static AMESystemError AmesysGetStdItem(AMESIMSYSTEM *amesys, const int Id, int *enabled)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_GET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      /* Initialize standard parameter */
      if(simOptGetOneOfStdParam(amesys->simOptions, Id, enabled) != 0) {
         res = AME_SETTINGS_ERROR;
      }
   }

   return res;
}

static AMESystemError AmesysSetALAParam(AMESIMSYSTEM *amesys, const autoLAOptions *alaOpt)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      /* Initialize standard parameters */
      simOptSetAlaParam(amesys->simOptions, alaOpt);
   }

   return res;
}

static AMESystemError AmesysGetALAParam(AMESIMSYSTEM *amesys, autoLAOptions *alaOpt)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_GET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      /* Get standard parameter */
      simOptGetAlaParam(amesys->simOptions, alaOpt);
   }

   return res;
}

/***********************************************************
   Purpose     : Turn off/on results
   Author	   : J.Andre
   Created on  : 2016 - 09 - 09
   Inputs	   :
      outoff   :  0 : result file off
                  1 : result file on
   Outputs	   :
   Revision    :
************************************************************/
static AMESystemError AmesysEnableResult(AMESIMSYSTEM *amesys, const int out)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      if(out) {
         amesys->simOptions->outoff = 0;
      }
      else {
         amesys->simOptions->outoff = 1;
      }
   }

   return res;
}

/***********************************************************
   Purpose     : Return the state of Amesystem
   Author	   : J.Andre
   Created     : 2016 - 09 - 05
   Inputs	   : None
   Outputs	   :
      state    : machine state
   Revision    :
************************************************************/
static unsigned int AmesysGetState(AMESIMSYSTEM *amesys)
{
   if(amesys) {
      return amesys->systemState;
   }
   else {
      return AMESTATE_IDLE;
   }
}

static AMESystemError AmesysGetModelInfo(unsigned int *numinputs, unsigned int *numoutputs, unsigned int *numstates, unsigned int *numimplicits)
{
   *numinputs = AME_NBOF_INPUTS;
   *numoutputs = AME_NBOF_OUTPUTS;
   *numstates = AME_NBOF_EXPLICIT_STATE;
   *numimplicits = AME_NBOF_IMPLICIT_STATE;

   return AME_NO_ERROR;
}

static AMESystemError AmesysGetModelPortName(const char **inputName[], const char **outputName[])
{
   *inputName = GinputVarTitles;
   *outputName = GoutputVarTitles;

   return AME_NO_ERROR;
}

static AMESystemError AmesysGetModelNumParam(unsigned int *numParam)
{
   *numParam = AME_NBOF_PARAMS;

   return AME_NO_ERROR;
}

static AMESystemError AmesysGetParamType(const int nbParam, const int idx[], E_ParamCType paramType[])
{
   AMESystemError res = AME_NO_ERROR;
   int i;

   for(i = 0; (i < nbParam) && (res == AME_NO_ERROR); i++) {
      if(i < AME_NBOF_PARAMS) {
         switch(GParamInfo[idx[i]].category) {
            case E_Int_Param:
               paramType[i] = E_CType_IntParam;
            break;
            case E_Text_Param:
               paramType[i] = E_CType_StringParam;
            break;
            default:
               paramType[i] = E_CType_DoubleParam;
            break;
         }
         return AME_NO_ERROR;
      }
      else {
         res = AME_PARAM_IDX_ERROR;
      }
   }

   return res;
}

static AMESystemError AmesysFindParamFromVar(const int nbParam, const int varIdx[], int paramIdx[], E_ParamCategory category[])
{
   AMESystemError res = AME_NO_ERROR;
   int idx, i;

   for(idx = 0; (idx < nbParam) && (res == AME_NO_ERROR); idx++) {
      res = AME_PARAM_IDX_ERROR;
      for(i = 0; i < AME_NBOF_PARAMS; i++) {
         if(GParamInfo[i].varIdx == varIdx[idx]) {
            paramIdx[idx] = i;
            category[idx] = GParamInfo[i].category;
            res = AME_NO_ERROR;
         }
      }
   }

   return res;
}

static AMESystemError AmesysGetIntParamValue(AMESIMSYSTEM *amesys, const int nbParam, const int idx[], int value[])
{
   AMESystemError res;
   int i;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_GET_MODEL_PARAM);

   for(i = 0; (i < nbParam) && (res == AME_NO_ERROR); i++) {
      res = getIntParameter(amesys->pModel, idx[i], &value[i]);
   }

   return res;
}

static AMESystemError AmesysGetDoubleParamValue(AMESIMSYSTEM *amesys, const int nbParam, const int idx[], double value[])
{
   AMESystemError res;
   int i;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_GET_MODEL_PARAM);

   for(i = 0; (i < nbParam) && (res == AME_NO_ERROR); i++) {
      res = getDoubleParameter(amesys->pModel, idx[i], &value[i]);
   }

   return res;
}

static AMESystemError AmesysGetStringParamValue(AMESIMSYSTEM *amesys, const int nbParam, const int idx[], const char* value[])
{
   AMESystemError res;
   int i;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_GET_MODEL_PARAM);

   for(i = 0; (i < nbParam) && (res == AME_NO_ERROR); i++) {
      res = getStringParameter(amesys->pModel, idx[i], &value[i]);
   }

   return res;
}

static AMESystemError AmesysSetIntParamValue(AMESIMSYSTEM *amesys, const int nbParam, const int idx[], const int value[])
{
   AMESystemError res;
   int i;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_MODEL_PARAM_TUNABLE);

   for(i = 0; (i < nbParam) && (res == AME_NO_ERROR); i++) {
      int isTunable;
      res = isParamTunable(amesys->pModel, idx[i], &isTunable);

      if(res ==  AME_NO_ERROR) {
         if(isTunable) {
            res = AmesysControlRequest(amesys, AME_CMD_SET_MODEL_PARAM_TUNABLE);
         }
         else {
            res = AmesysControlRequest(amesys, AME_CMD_SET_MODEL_PARAM);
         }
      }
      if(res ==  AME_NO_ERROR) {
         res = setIntParameter(amesys->pModel, idx[i], value[i]);
      }
      if(res == AME_NO_ERROR) {
         SignalInputChange();
         res = setParamAsUserDefined(amesys->pModel, idx[i]);
      }
   }

   return res;
}

static AMESystemError AmesysSetDoubleParamValue(AMESIMSYSTEM *amesys, const int nbParam, const int idx[], const double value[])
{
   AMESystemError res;
   int i;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_MODEL_PARAM_TUNABLE);

   for(i = 0; (i < nbParam) && (res == AME_NO_ERROR); i++) {
      int isTunable;
      res = isParamTunable(amesys->pModel, idx[i], &isTunable);

      if(res ==  AME_NO_ERROR) {
         if(isTunable) {
            res = AmesysControlRequest(amesys, AME_CMD_SET_MODEL_PARAM_TUNABLE);
         }
         else {
            res = AmesysControlRequest(amesys, AME_CMD_SET_MODEL_PARAM);
         }
      }
      if(res ==  AME_NO_ERROR) {
         res = setDoubleParameter(amesys->pModel, idx[i], value[i]);
      }
      if(res == AME_NO_ERROR) {
         SignalInputChange();
         res = setParamAsUserDefined(amesys->pModel, idx[i]);
      }
   }

   return res;
}

static AMESystemError AmesysSetStringParamValue(AMESIMSYSTEM *amesys, const int nbParam, const int idx[], const char* value[])
{
   AMESystemError res;
   int i;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_MODEL_PARAM_TUNABLE);

   for(i = 0; (i < nbParam) && (res == AME_NO_ERROR); i++) {
      int isTunable;
      res = isParamTunable(amesys->pModel, idx[i], &isTunable);

      if(res ==  AME_NO_ERROR) {
         if(isTunable) {
            res = AmesysControlRequest(amesys, AME_CMD_SET_MODEL_PARAM_TUNABLE);
         }
         else {
            res = AmesysControlRequest(amesys, AME_CMD_SET_MODEL_PARAM);
         }
      }
      if(res ==  AME_NO_ERROR) {
         res = setStringParameter(amesys->pModel,idx[i], value[i]);
      }
      if(res == AME_NO_ERROR) {
         res = setParamAsUserDefined(amesys->pModel, idx[i]);
      }
   }

   return res;
}

static AMESystemError AmesysGetDoubleGlobalParamValue(AMESIMSYSTEM *amesys, const int nbParam, const char* name[], double value[])
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_GET_MODEL_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      int i;
      for(i = 0; i<nbParam; i++) {
         if(getGlobalParamValueByName(name[i], &value[i]) != no_error) {
            res = AME_GLOBAL_PARAMETER_ERROR;
            break;
         }
      }
   }

   return res;
}

static AMESystemError AmesysGetStringGlobalParamValue(AMESIMSYSTEM *amesys, const int nbParam, const char* name[], const char* value[])
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_GET_MODEL_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      int i;
      for(i = 0; i<nbParam; i++) {
         if(getTextGlobalParamValueByName(name[i], &value[i]) != no_error) {
            res = AME_GLOBAL_PARAMETER_ERROR;
            break;
         }
      }
   }

   return res;
}

static AMESystemError AmesysSetIntGlobalParamValue(AMESIMSYSTEM *amesys, const int nbParam, const char* name[], const int value[])
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_MODEL_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      int i;
      for(i = 0; i<nbParam; i++) {
         if(ChangeOrAddIntGlobalParamValue(name[i], value[i], 1) != AME_NO_ERROR) {
            res = AME_GLOBAL_PARAMETER_ERROR;
            break;
         }
      }
   }

   return res;
}

static AMESystemError AmesysSetDoubleGlobalParamValue(AMESIMSYSTEM *amesys, const int nbParam, const char* name[], const double value[])
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_MODEL_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      int i;
      for(i = 0; i<nbParam; i++) {
         if(ChangeOrAddRealGlobalParamValue(name[i], value[i], 1) != AME_NO_ERROR) {
            res = AME_GLOBAL_PARAMETER_ERROR;
            break;
         }
      }
   }

   return res;
}

static AMESystemError AmesysSetStringGlobalParamValue(AMESIMSYSTEM *amesys, const int nbParam, const char* name[], const char* value[])
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_MODEL_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      int i;
      for(i = 0; i<nbParam; i++) {
         if(ChangeOrAddTextGlobalParamValue(name[i], value[i], 1) != AME_NO_ERROR) {
            res = AME_GLOBAL_PARAMETER_ERROR;
            break;
         }
      }
   }

   return res;
}

static AMESystemError AmesysRequestRunInterrupt(AMESIMSYSTEM *amesys)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_REQ_RUN_INTERRUPT);

   if(res == AME_NO_ERROR) { /* Request accepted */
      amesys->requestinterrupt = 1;

	   /* Update state and result */
	   res =  AmesysUpdateState(amesys, AME_CMD_REQ_RUN_INTERRUPT, res);
   }

   return res;
}

static AMESystemError AmesysSetFinalTime(AMESIMSYSTEM *amesys, const double finaltime)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      amesys->simOptions->tFinal = finaltime;
   }

   return res;
}

static AMESystemError AmesysSetInitTime(AMESIMSYSTEM *amesys, const double inittime)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      amesys->simOptions->tStart = inittime;
   }

   return res;
}

static AMESystemError AmesysSetPrintInterval(AMESIMSYSTEM *amesys, const double tInc)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_RUN_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      amesys->simOptions->tInc = tInc;
   }

   return res;
}

static AMESystemError AmesysSetLogger( int (*newameInternalfprintf)(FILE *fp, const char *fmt, va_list ap) )
{
   ameInstallFprintf(newameInternalfprintf);
   return AME_NO_ERROR;
}

static AMESystemError AmesysSetInputDir(AMESIMSYSTEM *amesys, const char *inputDir)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_ENV);

   if(res == AME_NO_ERROR) { /* Request accepted */
      AmeSetInputDir(amesys, inputDir);
   }

   return res;
}

static AMESystemError AmesysSetOutputDir(AMESIMSYSTEM *amesys, const char *outputDir)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_ENV);

   if(res == AME_NO_ERROR) { /* Request accepted */
      AmeSetOutputDir(amesys, outputDir);
   }

   return res;
}

static AMESystemError AmesysSetBaseFilesName(AMESIMSYSTEM *amesys, const char *baseName, const char* extension)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_ENV);

   if(res == AME_NO_ERROR) { /* Request accepted */
      AmeSetModelBaseName(amesys, baseName, extension);
   }

   return res;
}

static AMESystemError AmesysSetResultFilesName(AMESIMSYSTEM *amesys, const char *outName)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_ENV);

   if(res == AME_NO_ERROR) { /* Request accepted */
      AmeSetResultFileName(amesys, outName);
   }

   return res;
}

/* To ensure compliancy with old template and entry points */
static AMESystemError AmesysSetParamAsInitModel(AMESIMSYSTEM *amesys,
                  double time,
                  double PrintInterval,
                  double MaxTimeStep,
                  double tolerance,
                  int errCtrl,
                  int writeLevel,
                  int extraDisconPrints,
                  int runStats,
                  int runType,
                  int thesolvertype)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_RUN_PARAM);
   res |= AmesysControlRequest(amesys, AME_CMD_SET_SOLVER_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      SIMOptions *sim_options = amesys->simOptions;

      solverSettings solver;
      simSettings sim;
      stdOptions std;

      solver.integType =  0; /* Variable solver */
      solver.variable.hMax = MaxTimeStep;
      solver.variable.tol = tolerance;
      solver.variable.errorType = errCtrl;

      simOptSetSolverParam(amesys->simOptions, &solver);

      sim.tStart = time;
      sim.tFinal = amesys->simOptions->tFinal;
      sim.simOpt = 0;

      if(runType & 0x01) {
         sim.simOpt |= SIMOPT_SIM_CONTINUATION_RUN;
      }
      if(runType & 0x02) {
         sim.simOpt |= SIMOPT_SIM_USE_FINAL_VALUES;
      }
      if(writeLevel != 2) {
         sim.simOpt |= SIMOPT_SIM_MONITOR_TIME;
      }
      if(runStats) {
         sim.simOpt |= SIMOPT_SIM_STATISTICS;
      }

      if(PrintInterval <= 0) {
         sim.tInc = -PrintInterval;
         amesys->simOptions->outoff = 1;
      }
      else {
         sim.tInc = PrintInterval;
         amesys->simOptions->outoff = 0;
      }

      simOptSetSimParam(amesys->simOptions, &sim);

      std.simMode = ((runType & 0x0c) >> 2);
      std.stdOpt = 0;

      if(extraDisconPrints) {
         std.stdOpt |= SIMOPT_STD_DISC_PRINTOUT;
      }
      if(runType & 0x10) {
         std.stdOpt |= SIMOPT_STD_HOLD_INPUTS;
      }
      if(amesys->simOptions->stabilOption & 0x01) {
         std.stdOpt |= SIMOPT_STD_LOCK_STATES;
      }
      if(amesys->simOptions->stabilOption & 0x02) {
         std.stdOpt |= SIMOPT_STD_DIAGNOSTICS;
      }
      if(thesolvertype) {
         std.stdOpt |= SIMOPT_STD_CAUTIOUS;
      }
      if(amesys->simOptions->minimalDiscont) {
         std.stdOpt |= SIMOPT_STD_MIN_DISC_HANDLING;
      }
      if(runType & 0x100) {
         std.stdOpt |= SIMOPT_STD_DISABLE_OPTIMAZED;
      }
      if(sim_options->activityIndex & 0x01) {
         std.stdOpt |= SIMOPT_STD_ACTIVITY;
      }
      if(sim_options->activityIndex & 0x02) {
         std.stdOpt |= SIMOPT_STD_POWER;
      }
      if(sim_options->activityIndex & 0x04) {
         std.stdOpt |= SIMOPT_STD_ENERGY;
      }
      simOptSetStdParam(amesys->simOptions, &std);
   }
   return res;
}

/* To ensure compliancy with old template and entry points */
static AMESystemError AmesysSetParamAsFixedStep(AMESIMSYSTEM *amesys,
                                       double start_time, int run_type, int solver_type,
                                       int runge_kutta_order, double fixed_h, double printinterval)
{
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_SET_RUN_PARAM);
   res |= AmesysControlRequest(amesys, AME_CMD_SET_SOLVER_PARAM);

   if(res == AME_NO_ERROR) { /* Request accepted */
      solverSettings solver;

      res = AME_NO_ERROR;

      solver.integType = 1; /* Fixed solver */
      solver.fixed.fixedH = fixed_h;
      solver.fixed.fixedOrder = runge_kutta_order;
      solver.fixed.fixedType = solver_type;

      simOptSetSolverParam(amesys->simOptions, &solver);
      amesys->simOptions->tStart = start_time;

      if(printinterval <= 0) {
         amesys->simOptions->outoff = 1;
         amesys->simOptions->tInc = -printinterval;
      }
      else {
         amesys->simOptions->outoff = 0;
         amesys->simOptions->tInc = printinterval;
      }
      simOptSetOneOfSimParam(amesys->simOptions, SIMOPT_SIM_CONTINUATION_RUN, run_type & 0x01);
      simOptSetOneOfSimParam(amesys->simOptions, SIMOPT_SIM_USE_FINAL_VALUES, (run_type & 0x02)>>1);
   }
   return res;
}

#ifndef AME_COSIM

static AMESystemError AmesysInitME(AMESIMSYSTEM *amesys, int withAssembly)
{
   AMESystemError res = AME_NO_ERROR;
   int jump_ret;

   res = AmesysControlRequest(amesys, AME_CMD_INITIALIZE);

   if(res != AME_NO_ERROR) {
      /* Request not accepted */
      return res;
   }

   /* Load parameters */
   res = Input(amesys);

   /* Set initial values */
   modelSetInitValues(amesys->pModel, amesys->states, amesys->discrete_states);

   if(res == AME_NO_ERROR) {
      if( (jump_ret = setjmp(amesys->jump_env)) == 0) { /* try */

         setstarttime_(amesys->simOptions->tStart);
         setfinaltime_(amesys->simOptions->tFinal);

         amesys->first_call = 1;  /* should this be done or not ?*/
         amesys->internal_discont = 1;

         amesys->tlast = TLAST_MIN;

         memset(amesys->ecount,0,amesys->numstates*sizeof(int));
         memset(amesys->dotstates,0,amesys->numstates*sizeof(double));

         PreInitialize(amesys,amesys->states);

#ifndef AME_INPUT_IN_MEMORY
         if( NeedReloadInputFiles() != 0 )
         {
            ClearGPs();
            Input(amesys);
            /* Set initial values */
            modelSetInitValues(amesys->pModel, amesys->states, amesys->discrete_states);
            ClearReloadedFiles();
         }
#endif

         Initialize(amesys,amesys->states);

         OverloadStatesWithRegister(amesys, amesys->states, SVREGISTER_DEFAULT);

         if(withAssembly) {
            doAssembly(amesys);
         }
         amesys->tlast = getstarttime_();
#ifdef AME_PROCESS_TIME
         /* Initialization of time timers */
         ProcessTime(0);
#endif
      }
      else { /* Catch AmeExit */
         res = AME_EXIT_ERROR;
      }
   }

   /* Update state and result */
   res =  AmesysUpdateState(amesys, AME_CMD_INITIALIZE, res);

   if(res == AME_NO_ERROR) {
      /* Go in Run state: simulate acknowledgment of evaluation at t start command */
      res =  AmesysUpdateState(amesys, AME_CMD_TSTART, res);

#if defined(AME_MEMORY_ACCESS_RT_EXPORT)
#if (NB_WATCH_VAR>0)
         RT_Get_Watch_Var(amesys);
#endif
#endif
   }

   return res;
}

static AMESystemError AmesysFuncEvalME(AMESIMSYSTEM *amesys, double t, double *y, double *yprime, double *delta, int *flag)
{
   int jump_ret;
   AMESystemError res;

   SetGlobalSystem(amesys);
   res = AmesysControlRequest(amesys, AME_CMD_FUNCEVAL);

   if(res != AME_NO_ERROR) {
      /* Request not accepted */
      return res;
   }

   if( (jump_ret = setjmp(amesys->jump_env)) == 0) { /* try */
      amesys->doInterpol = 0;
      localFuncEval(amesys, t, y, yprime, delta, flag);
   }
   else { /* Catch AmeExit */
      res = AME_EXIT_ERROR;
   }

   /* Update state and result */
   res =  AmesysUpdateState(amesys, AME_CMD_FUNCEVAL, res);
   return res;
}

#endif

/****************************/

#define SYSNME exp9_

#if defined(STANDALONESIMULATOR) || defined(OLS)
#include "ame_standalone_simulator.h"

#elif defined(FMICS1)
#include "ame_fmics1.h"
#elif defined(FMICS2)
#include "ame_fmics2.h"
#elif defined(FMICS3)
#include "ame_fmics3.h"
#elif defined(FMIME1) || defined(FMIME2)
#if(AME_MODEL_ISEXPLICIT == 0)
#error "FMI for model exchange is not allowed for implicit model."
#elif defined(AMERT)
#error "FMU for real-time is not allowed for model exchange."
#elif defined(FMIME1)
#include "ame_fmime1.h"
#else
#include "ame_fmime2.h"
#endif
#elif defined(FMIX)
#include "ame_user_cosim.h"

#elif defined(AMEUSERCOSIM)
#include "ame_user_cosim.h"

#elif defined(AME_CS_SIMULINK)
#include "ame_simulink_cosim.h"

#elif defined(AME_ME_SIMULINK)
#include "ame_simulink_me.h"

#elif defined(AME_CS_ADAMS)
#include "ame_adams_cosim.h"

#elif defined(AME_ME_ADAMS)
#include "adams_cont.h"

#elif defined(AME_CS_MOTION)
#include "ame_motion_cosim.h"

#elif defined(AME_ME_MOTION)
#include "ame_motion_me.h"

#elif defined(DISCRETEPART)
#include "ame_discrete_part.h"

#elif defined(GEN_COSIM)
#include "gen_cosim.h"

#elif defined(AME_CS_SIMULINK_SCANER)
#include "ame_simulink_scaner.h"

#else
#error "Unknown interface defined. Cannot generate Amesim model code."
#endif