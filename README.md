# OpendTect-python-plugin

The objective of this project is to add scripting functionality to OpendTect similar to that we are familiar with from open-source GIS systems like QGis and GRASS.
This is achieved by embedding a python instance in a plugin that can be loaded by OpendTect, and exposing OpendTect classes to the python instance using boost::python wrappers.

# What is working:

I have embedded a python instance in a plugin that can be accessed using a preliminary python console that allows us to give single line commands to the python instance.
Currently I have wrapped the has2D() and has3D() methods of the SI() and the size() and objectID() methods of the EMM() OpenDtect c++ objects to a python object, this demonstrates that more usefull OpendTect classes can be exposed to the embedded python instance.

# What needs to be done
## OpendTect Python API

* Designing a useful python API for OpenDtect.
* Wrapping OpendTect classes to python objects that we can call from the embedded python console in a pythonic manner.

## GUI functionality

* Functionality to pass a file containing python code to the embedded python instance.
* Redirecting standard input so that it works from the python console.

# To compile the plugins
## On windows
You need to have 64 bit Python and boost static libraries installed on the computer.

To configure boost:
Download from http://www.boost.org , and follow directions available there.
When building the library I found that the following command worked for me:
b2.exe link=static variant=release,debug architecture=x86 address-model=64 toolset=msvc-12.0 threading=multi --build-type=complete install

Configure the project with cmake using command: cmake -G "Visual Studio 12 Win64" <root dir>
