# OpendTect-python-plugin
The objective of this project is to add scripting functionality to OpendTect similar to that we are familiar with from open-source GIS systems like QGis and GRASS.
This is achieved by embedding a python instance in a plugin that can be loaded by OpendTect, and exposing OpendTect classes to the python instance using boost::python wrappers.

# What is working:
I embedded a python instance in a plugin that can be accessed using a preliminary user interface that allows us to give single line commands to the python instance.
Currently I have wrapped has2D() and has3D() methods of the SI() OpenDtect object to a python object, this demonstrates that more usefull OpendTect classes can be exposed to the embedded python instance.

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

Configure the project with cmake using command: cmake -G "Visual Studio 12 Win64" <root dir>
