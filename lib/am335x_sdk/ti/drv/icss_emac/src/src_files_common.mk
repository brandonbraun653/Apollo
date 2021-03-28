
SRCDIR = . src 
INCDIR = . src
# Common source files across all platforms and cores
SRCS_COMMON += icss_emacDrv.c icss_emacFwInit.c icss_emacLearning.c icss_emacFwLearning.c icss_emacStatistics.c icss_emacStormControl.c icss_emacLoc.c

PACKAGE_SRCS_COMMON = makefile icss_emac_component.mk icss_emacCommon.h \
                      icss_emacDrv_Def.h icss_emacDrv.h icss_emacFwInit.h \
                      icss_emacLearning.h icss_emacFwLearning.h icss_emac_osal.h \
                      icss_emacStatistics.h icss_emacStormControl.h \
                      docs/ReleaseNotes_ICSS_EMAC_LLD.pdf \
                      src/ \
                      build/makefile.mk build/makefile_indp.mk build/makefile_profile_indp.mk build/makefile_profile.mk src/src_files_common.mk

