# Simple-Dll-Injector
This is a Simple dll injector which will run your dll by invoking LoadLibraryA with CreateRemoteThread.

<h4>Usage:</h4>
dllinject.exe [Process ID] [Dll path]

* Process ID - The process ID of the process of wich the DLL will be injected to.
* Dll path - The path to the DLL wich will be injected to the process.

<h4>note:</h4>
I have provided you with a 64 and a 32 bit versions of the injector as well as a test dll named "Hello World.dll.  
The test dll when attached will display a messege box.
