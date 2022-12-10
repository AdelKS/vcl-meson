# Vector Class Library V2

This is a fork of the latest version of [Vector Class Library](https://github.com/vectorclass/version2) that implements the [meson build system](https://mesonbuild.com/).

This is a C++ class library for using the Single Instruction Multiple Data (SIMD) instructions to improve performance on modern microprocessors with the x86 or x86/64 instruction set on Windows, Linux, and Mac platforms. There are no plans to support ARM or other instruction sets.

[Latest release](https://github.com/vectorclass/version2/releases)

[Download manual](https://github.com/vectorclass/manual/raw/master/vcl_manual.pdf)

[Add-on packages for particular applications](https://github.com/vectorclass/add-on)

[Getting-started video.](https://www.youtube.com/watch?v=TKjYdLIMTrI) Video blogger Christopher Rose has made this nice video telling how to get started with the Vector Class Library.

**Help:** You may ask for programming help on [StackOverflow](https://stackoverflow.com) using the tag vector-class-library.


### How to use in your meson project

It can be used directly through a "wrap file", for example you can copy-paste the following in your `subprojects/` folder, at the root of your meson project, as `vcl.wrap`:

```
[wrap-git]
url = https://github.com/AdelKS/vcl-meson.git
revision = master
depth = 1

[provide]
dependency_names = vcl
```

**Note:** Documentation about wrap files [here](https://mesonbuild.com/Wrap-dependency-system-manual.html)

Then you can declare your dependency in your `meson.build` with

```
vcl_dep = dependency('vcl', version : '>=2.0')
```

The library's headers can then be included under the `vcl` prefix, for example:

```c++
#include <vcl/vectorclass.h>
```