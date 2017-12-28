#include "uiodpython.h"

#include "uistrings.h"
#include "uilineedit.h"
#include "uimsg.h"
#include "uitextedit.h"
#include "uilabel.h"

UiOdPython::UiOdPython(uiParent* p)
	: uiDialog(p, Setup(tr("Python Console"),
		      tr("Specify python command"),
		      HelpKey("Python")))
{
    odPython = std::make_unique<OdPython>();

    command_history = uiString("");
    command_history_disp = new uiTextBrowser(this);
    command_history_disp->setText(command_history.getFullString());

    command_label = new uiLabel(this, ">>>");
    command_label->attach(leftAlignedBelow, command_history_disp);

    command_field = new uiLineEdit(this, "");
    command_field->setPrefWidthInChar(100);
    command_field->attach(rightOf, command_label);
    const CallBack return_pressed(mCB(this, UiOdPython, acceptOK));
    command_field->returnPressed.notify(return_pressed);
}

UiOdPython::~UiOdPython()
{
}


bool UiOdPython::acceptOK(CallBacker*)
{
    return do_command();
}

bool UiOdPython::do_command()
{
    BufferString current_command = command_field->text();
    command_field->setText("");
    command_history.append(">>> ", false);
    command_history.append(current_command, false);

    auto cmnd_cstr = current_command.getCStr();
    auto command_success = odPython->do_command(cmnd_cstr);
    
    auto command_result = odPython->get_result();
    
    command_history.append(command_result.c_str(), true);

    command_history_disp->setText(command_history.getFullString());
    return 0;
}