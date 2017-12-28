#include "uiodpython.h"

#include "odplugin.h"

#include "uiodmain.h"
#include "uimenu.h"
#include "uiodmenumgr.h"


class uiMgr : public CallBacker
{mODTextTranslationClass(uiMgr);
public:

		uiMgr(uiODMain*);

    uiODMain*	applicationInstance;
    void	launchDialog(CallBacker*);
};

uiMgr::uiMgr(uiODMain* a)
    : applicationInstance(a)
{
    applicationInstance->menuMgr().toolsMnu()->insertItem(new uiAction(m3Dots(tr("Python Console")), 
							      mCB(this, uiMgr, launchDialog)));
}

void uiMgr::launchDialog(CallBacker*)
{
    UiOdPython dlg(applicationInstance);
    dlg.go();
}

mDefODPluginInfo(UiPythonInstance)
{
    mDefineStaticLocalObject( PluginInfo, retpi,(
	"GUI for Python Console",
	"GUI for Python Console",
	"Tore Aadland",
	"0.0.1",
    	"Front-end for the plugin that exposes OpendTect classes to Pyton embedded."
    	"\nThis non-UI part can also be loaded into od_process_attrib." ) );
    return &retpi;
}

mDefODInitPlugin(UiPythonInstance)
{
    mDefineStaticLocalObject(PtrMan<uiMgr>, theinst_, = 0);
    if (theinst_) return 0;

    theinst_ = new uiMgr(ODMainWin());
    if (!theinst_)
	return "Cannot instantiate Python Console plugin";

    return 0;
}
