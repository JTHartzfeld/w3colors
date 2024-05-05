% w3colors(3NCURSES) 1.0.0 | w3colors
% J.T. Hartzfeld  <Johnathan.T.Hartzfeld@gmail.com>
% 2024-04-30

# NAME
\
**w3colors** - HTML5 standard named colors for ncures, and more.


# SYNOPSIS
```
#include <w3colors.h>
/* ...
   assuming curses is initialized in main 
   and extended colors are required
   ...
*/
  if(!init_w3colors()) return EXIT_FAILURE;
/* ... */
  init_pair(1, COLOR_SMOKEWHITE, w3color("Slate Grey"));
/* ... */
```

# DESCRIPTION
The **w3colors** library provides an extended set of default\
COLOR\_*COLORNAME* constants which can be initialized with\
the **init_w3colors()** function.  Afterward, all the colors\
are available as either COLOR\_*COLORNAME* or by calling\
**w3color("Color Name")**.  The former is considerably faster\
at runtime, while the latter allows for colors to be requested\
at runtime with a string of the format "Color Name",\
"colorname", or "color-name".

## Features
- Easy-to-use API for accessing predefined colors
- Support for RGB and hexadecimal color representations
- Comprehensive test suite for ensuring code quality
- Continuous integration and code coverage reports

## Installation
To install w3colors, you can use the following methods:

### PREREQUISITES:
Before installation, one must assure that the following packages\
are installed 
- A linux operating system.
- GCC (or other, c89 compliant, C Compiler)
- Make utility
- The NCURSES library.
- python
- pandoc


The necessary packages can be installed with your package manager\
 using something like:
```shell
  sudo apt install --upgrade gcc make ncurses6 \
  ncurses-dev python3 pandoc
```
*Other package managers do exist, but since the author does*\
*not use them, he will not comment on their usage.*


### Method 1: Manual Installation
1. Clone the repository:
    ```shell
    git clone https://github.com/your-username/w3colors.git
    ```

2. Build and install the library:
    ```shell
    cd w3colors
    make
    sudo make install
    ```

## Initialization:
Before using the extended color definitions, and before using\
the **w3color()** function, **init\_w3colors()** function must\
be called.
```
	
```


# EXAMPLES
## Including the header:
```c
 #include <w3colors.h>
```

## Initializing the library:
```c
initscr();
//...
init_w3colors();
//...
```

## Initializing a color pair:
```c
init_pair(1, COLOR_FORESTGREEN, COLOR_KHAKI);
```


# COPYLEFT
The w3colors library is MITvOC licensed and may be used as one\
sees fit under the conditions thereof.  MITvOC is a grammatical\
correction to the punctuation of the MIT license such that it is\
more readily comprehensible upon first reading.

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/JTHartzfeld/w3colors/blob/master/LICENSE.md)*vOC*
