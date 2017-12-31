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
	wrapper/odpywrapper.cpp
#	wrapper/wrapper_survinfo.cpp
#	wrapper/wrapper_emmanager.cpp
#	wrapper/wrapper_emobject
#	wrapper/wrapper_emhorizon3d.cpp
#	wrapper/wrapper_emsurface.cpp
#	wrapper/wrapper_multiid
#	wrapper/wrapper_objectid
#	wrapper/wrapper_surfaceiodata
)
set(OD_MODULE_EXTERNAL_LIBS
	Boost::python
	Python::libs
)
SET( OD_PLUGIN_ALO_EXEC ${OD_ATTRIB_EXECS} )
SET( OD_NO_ALO_ENTRY 1 )
OD_INIT_MODULE()