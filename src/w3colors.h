#ifndef __W3COLORS_H__
#define __W3COLORS_H__

#define TRUE 1
#define FALSE (!TRUE)

#include <ctype.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <ncurses.h>

    #ifndef __W3COLORS_C__
        #ifdef __cplusplus
            #define EXTERN extern "C" 
        #else
            #define EXTERN extern
        #endif
    #else
        #define EXTERN
    #endif 

    
typedef struct W3COLORGROUP_t {int len; const char** aliases;} W3ColorGroup;

EXTERN int num_w3colors;
EXTERN int max_w3colors;

EXTERN int init_w3colors();
EXTERN int free_w3colors();
EXTERN int set_w3color(const char* name, int r, int g, int b);
EXTERN int add_w3color_alias(const char* name, const char* alias);
EXTERN W3ColorGroup* new_w3colorgroup(int count,...);
EXTERN short w3color(const char* name);
EXTERN W3ColorGroup** w3colorgroups;

#define COLOR_BLACK                      0 // #000000 =>(   0,   0,   0)
#define COLOR_RED                        1 // #ff0000 =>(1000,   0,   0)
#define COLOR_GREEN                      2 // #008000 =>(   0, 502,   0)
#define COLOR_YELLOW                     3 // #ffff00 =>(1000,1000,   0)
#define COLOR_BLUE                       4 // #0000ff =>(   0,   0,1000)
#define COLOR_MAGENTA                    5 // #ff00ff =>(1000,   0,1000)
#define COLOR_FUCHSIA                    5 // ^^ DUPLICATE of COLOR_MAGENTA ^^
#define COLOR_FUSCHIA                    5 // ^^ DUPLICATE of COLOR_MAGENTA ^^
#define COLOR_CYAN                       6 // #00ffff =>(   0,1000,1000)
#define COLOR_AQUA                       6 // ^^ DUPLICATE of COLOR_CYAN ^^
#define COLOR_WHITE                      7 // #ffffff =>(1000,1000,1000)
#define COLOR_ALICEBLUE                  8 // #f0f8ff =>( 941, 973,1000)
#define COLOR_ANTIQUEWHITE               9 // #faebd7 =>( 980, 922, 843)
#define COLOR_AQUAMARINE                10 // #7fffd4 =>( 498,1000, 831)
#define COLOR_AZURE                     11 // #f0ffff =>( 941,1000,1000)
#define COLOR_BEIGE                     12 // #f5f5dc =>( 961, 961, 863)
#define COLOR_BISQUE                    13 // #ffe4c4 =>(1000, 894, 769)
#define COLOR_BLANCHEDALMOND            14 // #ffebcd =>(1000, 922, 804)
#define COLOR_BLUEVIOLET                15 // #8a2be2 =>( 541, 169, 886)
#define COLOR_BROWN                     16 // #a52a2a =>( 647, 165, 165)
#define COLOR_BURLYWOOD                 17 // #deb887 =>( 871, 722, 529)
#define COLOR_CADETBLUE                 18 // #5f9ea0 =>( 373, 620, 627)
#define COLOR_CHARTREUSE                19 // #7fff00 =>( 498,1000,   0)
#define COLOR_CHOCOLATE                 20 // #d2691e =>( 824, 412, 118)
#define COLOR_CORAL                     21 // #ff7f50 =>(1000, 498, 314)
#define COLOR_CORNFLOWERBLUE            22 // #6495ed =>( 392, 584, 929)
#define COLOR_CORNSILK                  23 // #fff8dc =>(1000, 973, 863)
#define COLOR_CRIMSON                   24 // #dc143c =>( 863,  78, 235)
#define COLOR_DARKBLUE                  25 // #00008b =>(   0,   0, 545)
#define COLOR_DARKCYAN                  26 // #008b8b =>(   0, 545, 545)
#define COLOR_DARKGOLDENROD             27 // #b8860b =>( 722, 525,  43)
#define COLOR_DARKGRAY                  28 // #a9a9a9 =>( 663, 663, 663)
#define COLOR_DARKGREY                  28 // ^^ DUPLICATE of COLOR_DARKGRAY ^^
#define COLOR_DARKGREEN                 29 // #006400 =>(   0, 392,   0)
#define COLOR_DARKKHAKI                 30 // #bdb76b =>( 741, 718, 420)
#define COLOR_DARKMAGENTA               31 // #8b008b =>( 545,   0, 545)
#define COLOR_DARKOLIVEGREEN            32 // #556b2f =>( 333, 420, 184)
#define COLOR_DARKORANGE                33 // #ff8c00 =>(1000, 549,   0)
#define COLOR_DARKORCHID                34 // #9932cc =>( 600, 196, 800)
#define COLOR_DARKRED                   35 // #8b0000 =>( 545,   0,   0)
#define COLOR_DARKSALMON                36 // #e9967a =>( 914, 588, 478)
#define COLOR_DARKSEAGREEN              37 // #8fbc8f =>( 561, 737, 561)
#define COLOR_DARKSLATEBLUE             38 // #483d8b =>( 282, 239, 545)
#define COLOR_DARKSLATEGRAY             39 // #2f4f4f =>( 184, 310, 310)
#define COLOR_DARKSLATEGREY             39 // ^^ DUPLICATE of COLOR_DARKSLATEGRAY ^^
#define COLOR_DARKTURQUOISE             40 // #00ced1 =>(   0, 808, 820)
#define COLOR_DARKVIOLET                41 // #9400d3 =>( 580,   0, 827)
#define COLOR_DEEPPINK                  42 // #ff1493 =>(1000,  78, 576)
#define COLOR_DEEPSKYBLUE               43 // #00bfff =>(   0, 749,1000)
#define COLOR_DIMGRAY                   44 // #696969 =>( 412, 412, 412)
#define COLOR_DIMGREY                   44 // ^^ DUPLICATE of COLOR_DIMGRAY ^^
#define COLOR_DODGERBLUE                45 // #1e90ff =>( 118, 565,1000)
#define COLOR_FIREBRICK                 46 // #b22222 =>( 698, 133, 133)
#define COLOR_FLORALWHITE               47 // #fffaf0 =>(1000, 980, 941)
#define COLOR_FORESTGREEN               48 // #228b22 =>( 133, 545, 133)
#define COLOR_GAINSBORO                 49 // #dcdcdc =>( 863, 863, 863)
#define COLOR_GHOSTWHITE                50 // #f8f8ff =>( 973, 973,1000)
#define COLOR_GOLD                      51 // #ffd700 =>(1000, 843,   0)
#define COLOR_GOLDENROD                 52 // #daa520 =>( 855, 647, 125)
#define COLOR_GRAY                      53 // #808080 =>( 502, 502, 502)
#define COLOR_GREY                      53 // ^^ DUPLICATE of COLOR_GRAY ^^
#define COLOR_GREENYELLOW               54 // #adff2f =>( 678,1000, 184)
#define COLOR_HONEYDEW                  55 // #f0fff0 =>( 941,1000, 941)
#define COLOR_HOTPINK                   56 // #ff69b4 =>(1000, 412, 706)
#define COLOR_INDIANRED                 57 // #cd5c5c =>( 804, 361, 361)
#define COLOR_INDIGO                    58 // #4b0082 =>( 294,   0, 510)
#define COLOR_IVORY                     59 // #fffff0 =>(1000,1000, 941)
#define COLOR_KHAKI                     60 // #f0e68c =>( 941, 902, 549)
#define COLOR_LAVENDER                  61 // #e6e6fa =>( 902, 902, 980)
#define COLOR_LAVENDERBLUSH             62 // #fff0f5 =>(1000, 941, 961)
#define COLOR_LAWNGREEN                 63 // #7cfc00 =>( 486, 988,   0)
#define COLOR_LEMONCHIFFON              64 // #fffacd =>(1000, 980, 804)
#define COLOR_LIGHTBLUE                 65 // #add8e6 =>( 678, 847, 902)
#define COLOR_LIGHTCORAL                66 // #f08080 =>( 941, 502, 502)
#define COLOR_LIGHTCYAN                 67 // #e0ffff =>( 878,1000,1000)
#define COLOR_LIGHTGOLDENRODYELLOW      68 // #fafad2 =>( 980, 980, 824)
#define COLOR_LIGHTGRAY                 69 // #d3d3d3 =>( 827, 827, 827)
#define COLOR_LIGHTGREY                 69 // ^^ DUPLICATE of COLOR_LIGHTGRAY ^^
#define COLOR_LIGHTGREEN                70 // #90ee90 =>( 565, 933, 565)
#define COLOR_LIGHTPINK                 71 // #ffb6c1 =>(1000, 714, 757)
#define COLOR_LIGHTSALMON               72 // #ffa07a =>(1000, 627, 478)
#define COLOR_LIGHTSEAGREEN             73 // #20b2aa =>( 125, 698, 667)
#define COLOR_LIGHTSKYBLUE              74 // #87cefa =>( 529, 808, 980)
#define COLOR_LIGHTSLATEGRAY            75 // #778899 =>( 467, 533, 600)
#define COLOR_LIGHTSLATEGREY            75 // ^^ DUPLICATE of COLOR_LIGHTSLATEGRAY ^^
#define COLOR_LIGHTSTEELBLUE            76 // #b0c4de =>( 690, 769, 871)
#define COLOR_LIGHTYELLOW               77 // #ffffe0 =>(1000,1000, 878)
#define COLOR_LIME                      78 // #00ff00 =>(   0,1000,   0)
#define COLOR_LIMEGREEN                 79 // #32cd32 =>( 196, 804, 196)
#define COLOR_LINEN                     80 // #faf0e6 =>( 980, 941, 902)
#define COLOR_MAROON                    81 // #800000 =>( 502,   0,   0)
#define COLOR_MEDIUMAQUAMARINE          82 // #66cdaa =>( 400, 804, 667)
#define COLOR_MEDIUMBLUE                83 // #0000cd =>(   0,   0, 804)
#define COLOR_MEDIUMORCHID              84 // #ba55d3 =>( 729, 333, 827)
#define COLOR_MEDIUMPURPLE              85 // #9370db =>( 576, 439, 859)
#define COLOR_MEDIUMSEAGREEN            86 // #3cb371 =>( 235, 702, 443)
#define COLOR_MEDIUMSLATEBLUE           87 // #7b68ee =>( 482, 408, 933)
#define COLOR_MEDIUMSPRINGGREEN         88 // #00fa9a =>(   0, 980, 604)
#define COLOR_MEDIUMTURQUOISE           89 // #48d1cc =>( 282, 820, 800)
#define COLOR_MEDIUMVIOLETRED           90 // #c71585 =>( 780,  82, 522)
#define COLOR_MIDNIGHTBLUE              91 // #191970 =>(  98,  98, 439)
#define COLOR_MINTCREAM                 92 // #f5fffa =>( 961,1000, 980)
#define COLOR_MISTYROSE                 93 // #ffe4e1 =>(1000, 894, 882)
#define COLOR_MOCCASIN                  94 // #ffe4b5 =>(1000, 894, 710)
#define COLOR_NAVAJOWHITE               95 // #ffdead =>(1000, 871, 678)
#define COLOR_NAVY                      96 // #000080 =>(   0,   0, 502)
#define COLOR_OLDLACE                   97 // #fdf5e6 =>( 992, 961, 902)
#define COLOR_OLIVE                     98 // #808000 =>( 502, 502,   0)
#define COLOR_OLIVEDRAB                 99 // #6b8e23 =>( 420, 557, 137)
#define COLOR_ORANGE                   100 // #ffa500 =>(1000, 647,   0)
#define COLOR_ORANGERED                101 // #ff4500 =>(1000, 271,   0)
#define COLOR_REDORANGE                101 // ^^ DUPLICATE of COLOR_ORANGERED ^^
#define COLOR_ORCHID                   102 // #da70d6 =>( 855, 439, 839)
#define COLOR_PALEGOLDENROD            103 // #eee8aa =>( 933, 910, 667)
#define COLOR_PALEGREEN                104 // #98fb98 =>( 596, 984, 596)
#define COLOR_PALETURQUOISE            105 // #afeeee =>( 686, 933, 933)
#define COLOR_PALEVIOLETRED            106 // #db7093 =>( 859, 439, 576)
#define COLOR_PAPAYAWHIP               107 // #ffefd5 =>(1000, 937, 835)
#define COLOR_PEACHPUFF                108 // #ffdab9 =>(1000, 855, 725)
#define COLOR_PERU                     109 // #cd853f =>( 804, 522, 247)
#define COLOR_PINK                     110 // #ffc0cb =>(1000, 753, 796)
#define COLOR_PLUM                     111 // #dda0dd =>( 867, 627, 867)
#define COLOR_POWDERBLUE               112 // #b0e0e6 =>( 690, 878, 902)
#define COLOR_PURPLE                   113 // #800080 =>( 502,   0, 502)
#define COLOR_REBECCAPURPLE            114 // #663399 =>( 400, 200, 600)
#define COLOR_ROSYBROWN                115 // #bc8f8f =>( 737, 561, 561)
#define COLOR_ROYALBLUE                116 // #4169e1 =>( 255, 412, 882)
#define COLOR_SADDLEBROWN              117 // #8b4513 =>( 545, 271,  75)
#define COLOR_SALMON                   118 // #fa8072 =>( 980, 502, 447)
#define COLOR_SANDYBROWN               119 // #f4a460 =>( 957, 643, 376)
#define COLOR_SEAGREEN                 120 // #2e8b57 =>( 180, 545, 341)
#define COLOR_SEASHELL                 121 // #fff5ee =>(1000, 961, 933)
#define COLOR_SIENNA                   122 // #a0522d =>( 627, 322, 176)
#define COLOR_SILVER                   123 // #c0c0c0 =>( 753, 753, 753)
#define COLOR_SKYBLUE                  124 // #87ceeb =>( 529, 808, 922)
#define COLOR_SLATEBLUE                125 // #6a5acd =>( 416, 353, 804)
#define COLOR_SLATEGRAY                126 // #708090 =>( 439, 502, 565)
#define COLOR_SLATEGREY                126 // ^^ DUPLICATE of COLOR_SLATEGRAY ^^
#define COLOR_SNOW                     127 // #fffafa =>(1000, 980, 980)
#define COLOR_SPRINGGREEN              128 // #00ff7f =>(   0,1000, 498)
#define COLOR_STEELBLUE                129 // #4682b4 =>( 275, 510, 706)
#define COLOR_TAN                      130 // #d2b48c =>( 824, 706, 549)
#define COLOR_TEAL                     131 // #008080 =>(   0, 502, 502)
#define COLOR_THISTLE                  132 // #d8bfd8 =>( 847, 749, 847)
#define COLOR_TOMATO                   133 // #ff6347 =>(1000, 388, 278)
#define COLOR_TURQUOISE                134 // #40e0d0 =>( 251, 878, 816)
#define COLOR_VIOLET                   135 // #ee82ee =>( 933, 510, 933)
#define COLOR_WHEAT                    136 // #f5deb3 =>( 961, 871, 702)
#define COLOR_WHITESMOKE               137 // #f5f5f5 =>( 961, 961, 961)
#define COLOR_SMOKEWHITE               137 // ^^ DUPLICATE of COLOR_WHITESMOKE ^^
#define COLOR_YELLOWGREEN              138 // #9acd32 =>( 604, 804, 196)
#define COLORS_COUNT                   139


#define ADTNL_COLORS_COUNT 16
#endif
