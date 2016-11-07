I found the old code and cleaned it up. Back in 2014 it was cross compiled from Linux to Windows. As the cross compile configuration was lost, I provided a seperate native build and binaries for Windows. Furthermore, **some bash scripts have been provided to automate the build process**. Can be found in the **scripts** folder.
**Note**: Scripts **have to** be executed from the **scripts** folder.

## Pre-built binaries and libraries
Available under Release tab on the main repo page.
#### Linux
Download file **dice_simulator.exe**.
Requires wxWidgets3.0+ and basic build tools installed using your system's repository. A simple script to automate this on ubuntu is included in **scripts/prepare_ubuntu.sh**. In the future, I may provide a more comprehensive solution.
**Note**: Linux binary is compiled dynamically using 64bit archlinux. If you find the binary incompatible, you can always compile the binary yourself (described later) or use wine to run Windows version.
#### Windows
Download file **dice_simulator.exe.exe** and run it.
**Note**: Binary was compressed using [upx](https://upx.github.io/). As a result, it may be falsely flagged as a virus. However, the file is 100% safe as stated by [virustotal test](https://www.virustotal.com/en/file/804a2c8c8f1493148b3bd2469c12c9c038e2dc441f5b4cdbf5e28b74ee4ea006/analysis/1478529451/).

## Building binaries
#### Linux
Requires wxWidgets3.0+, basic build tools and codeblocks. As mentioned before, a simple script to automate installation on ubuntu is included in the **scripts** folder.
#### Windows
Requires wxWidgets3.0+ library files and codeblocks with compiler **supporting C++11**.
Download the library named **wxwidgets_windows.exe** from the repo Release tab. [Codeblocks can be downloaded here](http://downloads.sourceforge.net/project/codeblocks/Binaries/16.01/Windows/codeblocks-16.01mingw-setup.exe?r=http%3A%2F%2Fwww.codeblocks.org%2Fdownloads%2F26&ts=1478470360&use_mirror=freefr).
**Note**: This is a minified version of wxWidgets. It should not be used to build other projects as some files may be missing.


## Building manually the library on Windows
1. [Download sources](https://github.com/wxWidgets/wxWidgets/releases/download/v3.0.2/wxMSW-3.0.2-Setup.exe).
2. Run the installer to unpack the library.
3. In powershell, go to **build/msw** inside the selected directory.
4. Compile using the following command:
```mingw32-make -f makefile.gcc CXXFLAGS="-std=gnu++11 -Os -w" LDFLAGS="-s" BUILD=release MONOLITHIC=0 SHARED=0 UNICODE=1 DEBUG_FLAG=0 DEBUG_INFO=0 USE_AUI=0 USE_HTML=0 USE_MEDIA=0 USE_PROPGRID=0 USE_OPENGL=0 USE_RIBBON=0 USE_RICHTEXT=0 USE_STC=0  USE_WEBVIEW=0 USE_XRC=0```
5. Copy **include** and **lib** directores from the unzipped directory to the project's directory.

## MacOS users
Wine can be used to run the Windows binary. Compilation on MacOS is **NOT** prepared.

## Known issues
- Result value centering does not work correctly on Windows.
- Numerous errors may be thrown during compilation on Windows. They result from compiling against minified version of the library. Should be simply ignored.

## License
The MIT License (MIT)

Copyright (c) 2014 Tomasz Hamerla

Full text available in the LICENSE file.
