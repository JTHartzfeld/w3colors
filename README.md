% libw3colors(3NCURSES) 1.0.0 | libw3colors
% J.T. Hartzfeld  <Johnathan.T.Hartzfeld@gmail.com>
% 2024-04-30

# NAME
**w3colors** - HTML5 standard named colors for ncurses.

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

## Initialization:
Before using the extended color definitions, and before using\
the **w3color()** function, **init\_w3colors()** function must be called.
```
	
```
	

# EXAMPLES
## Including the header:
```c
#include <w3colors>
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
```

```


