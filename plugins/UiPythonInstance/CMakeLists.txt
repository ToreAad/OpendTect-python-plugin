#_______________________Pmake___________________________________________________
#
#	Makefile : 	Tutorial plugin
# 	Jan 2012	K. Tingdahl
#	RCS :		$Id$
#_______________________________________________________________________________

set(OD_MODULE_NAME 
	UiPythonInstance
)
set(OD_IS_PLUGIN 1 )
set(OD_MODULE_DEPS 
	uiODMain 
	PythonInstance
)
set(OD_MODULE_SOURCES
	main.cpp
	uiodpython.cpp
)
SET( OD_PLUGIN_ALO_EXEC ${OD_MAIN_EXEC} )
SET( OD_NO_ALO_ENTRY 1 )
OD_INIT_MODULE()
