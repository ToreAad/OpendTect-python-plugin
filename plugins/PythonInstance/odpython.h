#include "pythoninstancemod.h"
#include "odpythoninstance/odpythoninstance.h"
#include <string>

mExpClass(PythonInstance) OdPython
{ mODTextTranslationClass(OdPython);
public:
    std::string get_result();
    bool do_command(const char*);

    static void initialize_class();

protected:
    OdPythonInstance odpythoninstance;
};