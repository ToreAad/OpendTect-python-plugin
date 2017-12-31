#pragma once
#include "uipythoninstancemod.h"

#include "uidialog.h"
#include "odpython.h"
#include <memory>

class uiIOObjSel;
class uiTextEdit;
class uiTextBrowser;
class uiLabel;

mExpClass(UiPythonInstance) UiOdPython : public uiDialog
{ mODTextTranslationClass(UiPythonInstanceTools);
public:
    UiOdPython(uiParent*);
    ~UiOdPython();
protected:
    bool		acceptOK(CallBacker*);
	bool		do_command();

	uiTextEdit*	command_field;
	uiLabel*	command_label;
	uiTextBrowser*	command_history_disp;
	
	uiString	command_history;

	std::unique_ptr<OdPython> odPython;
};

