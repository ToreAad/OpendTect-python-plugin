cmake_minimum_required(VERSION 3.0)
set(OD_MODULE_DEPS 
#	uiODMain
	AttributeEngine 
	EarthModel 
	Well
)
set(OD_IS_PLUGIN yes )
set(OD_MODULE_SOURCES
	main.cpp
	odpython.cpp
	odpythoninstance/odpythonio.cpp
	odpythoninstance/odpythoninstance.cpp
	wrapper/wrapper_survinfo.cpp
	
)
set(OD_MODULE_EXTERNAL_LIBS
	Boost::python
	Python::libs
)
SET( OD_PLUGIN_ALO_EXEC ${OD_ATTRIB_EXECS} )
SET( OD_NO_ALO_ENTRY 1 )
OD_INIT_MODULE()