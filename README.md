# OpendTect-python-plugin
The objective of this project is to add scripting functionality to OpendTect similar to that we are familiar with from open-source GIS systems like QGis and GRASS.
This is to be achieved by embedding a python instance in a plugin that can be loadded by opendtect, and exposing OpendTect classes to the python instance using boost::python wrappers.

# What is working:
We have a embedded python instance that can be accessed from python console with a very simple user interface.
Currently I have wrapped SI().has2D() and SI().has3D() methods to a python object, this demonstrates that more usefull opendtect classes can be exposed to the embedded python instance.

# What needs to be done:
Wrapping OpendTect classes to python objects that we can call from the embedded python console.
Multiline input in the embedded python console.
Redirecting standard input so that it works from the UI.

# To compile the plugins on windows:
You need to have 64 bit Python and boost static libraries installed on the computer.

To configure boost:
Download from http://www.boost.org , and follow directions available there.
When building the library I found that the following command worked for me:
b2.exe link=static variant=release,debug architecture=x86 address-model=64 toolset=msvc-12.0 threading=multi --build-type=complete install

Configure with cmake using command: cmake -G "Visual Studio 12 Win64" <root dir>
