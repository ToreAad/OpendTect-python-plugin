#include "odplugin.h"
#include "odpython.h"


mDefODPluginEarlyLoad(PythonInstance)
mDefODPluginInfo(PythonInstance)
{
    mDefineStaticLocalObject( PluginInfo, retpi,(
	"Python Console",
	"OpendTect",
	"Tore Aadland",
	"0.0.1",
    	"Back-end for the plugin that exposes OpendTect classes to Pyton embedded."
    	"\nThis non-UI part can also be loaded into od_process_attrib." ) );
    return &retpi;
}


mDefODInitPlugin(PythonInstance)
{
    OdPython::initialize_class();
    return 0;
}

