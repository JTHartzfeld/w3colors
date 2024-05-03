#define __W3COLORS_C__
#include "w3colors.h"

W3ColorGroup* new_w3colorgroup(int count, ...) {
    va_list names;
    va_start(names, count);
    const char** output_names = calloc(count, sizeof(const char*));
    for(int i=0; i<count; i++) {
        output_names[i]=va_arg(names, const char*);
    }
    va_end(names);
    
    W3ColorGroup* output 	= calloc(1, sizeof(W3ColorGroup));
    output->len 			= count;
    output->aliases 		= output_names;
    
    return output;
}



char* tosquishname(const char* name) {
    int len = strlen(name);
    char* buffer = calloc(len, sizeof((char)' '));
    int j=0;
    for(int i=0; i<len; i++) {
        if((name[i]==' ') || (name[i]=='-'))
            continue;
        else {
            buffer[j++]=(char)tolower((int)name[i]);
        }
    }
    buffer[j]='\0';
    buffer = realloc(buffer, ++j);
    return buffer;
}

int add_w3color(W3ColorGroup* colorgroup, int r, int g, int b) {
    
    return 0;
}

int add_w3color_alias(const char* name, const char* alias) {

    return 0;
}

short w3color(const char* name) {
    int len;
    char* squishname = tosquishname(name);
    char* tmp = calloc(1,1);
    for(short i=0; i<num_w3colors; i++) {
        len = w3colorgroups[i]->len;
        for(short j=0; j<len; j++) {
            tmp = tosquishname(w3colorgroups[i]->aliases[j]);
            if(strcmp(squishname, tmp)==0) {
                free(tmp);
                return i;
            }
            free(tmp);
        }
    }
    free(squishname);
    return -1;
}

int init_w3colors() {
    if(has_colors() && can_change_color()) {
		start_color();
	
	// Initialize all the colors.
        init_color(COLOR_BLACK,                     0,   0,   0);
        init_color(COLOR_RED,                    1000,   0,   0);
        init_color(COLOR_GREEN,                     0, 502,   0);
        init_color(COLOR_YELLOW,                 1000,1000,   0);
        init_color(COLOR_BLUE,                      0,   0,1000);
        init_color(COLOR_MAGENTA,                1000,   0,1000);
        init_color(COLOR_CYAN,                      0,1000,1000);
        init_color(COLOR_WHITE,                  1000,1000,1000);
        init_color(COLOR_ALICEBLUE,               941, 973,1000);
        init_color(COLOR_ANTIQUEWHITE,            980, 922, 843);
        init_color(COLOR_AQUAMARINE,              498,1000, 831);
        init_color(COLOR_AZURE,                   941,1000,1000);
        init_color(COLOR_BEIGE,                   961, 961, 863);
        init_color(COLOR_BISQUE,                 1000, 894, 769);
        init_color(COLOR_BLANCHEDALMOND,         1000, 922, 804);
        init_color(COLOR_BLUEVIOLET,              541, 169, 886);
        init_color(COLOR_BROWN,                   647, 165, 165);
        init_color(COLOR_BURLYWOOD,               871, 722, 529);
        init_color(COLOR_CADETBLUE,               373, 620, 627);
        init_color(COLOR_CHARTREUSE,              498,1000,   0);
        init_color(COLOR_CHOCOLATE,               824, 412, 118);
        init_color(COLOR_CORAL,                  1000, 498, 314);
        init_color(COLOR_CORNFLOWERBLUE,          392, 584, 929);
        init_color(COLOR_CORNSILK,               1000, 973, 863);
        init_color(COLOR_CRIMSON,                 863,  78, 235);
        init_color(COLOR_DARKBLUE,                  0,   0, 545);
        init_color(COLOR_DARKCYAN,                  0, 545, 545);
        init_color(COLOR_DARKGOLDENROD,           722, 525,  43);
        init_color(COLOR_DARKGRAY,                663, 663, 663);
        init_color(COLOR_DARKGREEN,                 0, 392,   0);
        init_color(COLOR_DARKKHAKI,               741, 718, 420);
        init_color(COLOR_DARKMAGENTA,             545,   0, 545);
        init_color(COLOR_DARKOLIVEGREEN,          333, 420, 184);
        init_color(COLOR_DARKORANGE,             1000, 549,   0);
        init_color(COLOR_DARKORCHID,              600, 196, 800);
        init_color(COLOR_DARKRED,                 545,   0,   0);
        init_color(COLOR_DARKSALMON,              914, 588, 478);
        init_color(COLOR_DARKSEAGREEN,            561, 737, 561);
        init_color(COLOR_DARKSLATEBLUE,           282, 239, 545);
        init_color(COLOR_DARKSLATEGRAY,           184, 310, 310);
        init_color(COLOR_DARKTURQUOISE,             0, 808, 820);
        init_color(COLOR_DARKVIOLET,              580,   0, 827);
        init_color(COLOR_DEEPPINK,               1000,  78, 576);
        init_color(COLOR_DEEPSKYBLUE,               0, 749,1000);
        init_color(COLOR_DIMGRAY,                 412, 412, 412);
        init_color(COLOR_DODGERBLUE,              118, 565,1000);
        init_color(COLOR_FIREBRICK,               698, 133, 133);
        init_color(COLOR_FLORALWHITE,            1000, 980, 941);
        init_color(COLOR_FORESTGREEN,             133, 545, 133);
        init_color(COLOR_GAINSBORO,               863, 863, 863);
        init_color(COLOR_GHOSTWHITE,              973, 973,1000);
        init_color(COLOR_GOLD,                   1000, 843,   0);
        init_color(COLOR_GOLDENROD,               855, 647, 125);
        init_color(COLOR_GRAY,                    502, 502, 502);
        init_color(COLOR_GREENYELLOW,             678,1000, 184);
        init_color(COLOR_HONEYDEW,                941,1000, 941);
        init_color(COLOR_HOTPINK,                1000, 412, 706);
        init_color(COLOR_INDIANRED,               804, 361, 361);
        init_color(COLOR_INDIGO,                  294,   0, 510);
        init_color(COLOR_IVORY,                  1000,1000, 941);
        init_color(COLOR_KHAKI,                   941, 902, 549);
        init_color(COLOR_LAVENDER,                902, 902, 980);
        init_color(COLOR_LAVENDERBLUSH,          1000, 941, 961);
        init_color(COLOR_LAWNGREEN,               486, 988,   0);
        init_color(COLOR_LEMONCHIFFON,           1000, 980, 804);
        init_color(COLOR_LIGHTBLUE,               678, 847, 902);
        init_color(COLOR_LIGHTCORAL,              941, 502, 502);
        init_color(COLOR_LIGHTCYAN,               878,1000,1000);
        init_color(COLOR_LIGHTGOLDENRODYELLOW,    980, 980, 824);
        init_color(COLOR_LIGHTGRAY,               827, 827, 827);
        init_color(COLOR_LIGHTGREEN,              565, 933, 565);
        init_color(COLOR_LIGHTPINK,              1000, 714, 757);
        init_color(COLOR_LIGHTSALMON,            1000, 627, 478);
        init_color(COLOR_LIGHTSEAGREEN,           125, 698, 667);
        init_color(COLOR_LIGHTSKYBLUE,            529, 808, 980);
        init_color(COLOR_LIGHTSLATEGRAY,          467, 533, 600);
        init_color(COLOR_LIGHTSTEELBLUE,          690, 769, 871);
        init_color(COLOR_LIGHTYELLOW,            1000,1000, 878);
        init_color(COLOR_LIME,                      0,1000,   0);
        init_color(COLOR_LIMEGREEN,               196, 804, 196);
        init_color(COLOR_LINEN,                   980, 941, 902);
        init_color(COLOR_MAROON,                  502,   0,   0);
        init_color(COLOR_MEDIUMAQUAMARINE,        400, 804, 667);
        init_color(COLOR_MEDIUMBLUE,                0,   0, 804);
        init_color(COLOR_MEDIUMORCHID,            729, 333, 827);
        init_color(COLOR_MEDIUMPURPLE,            576, 439, 859);
        init_color(COLOR_MEDIUMSEAGREEN,          235, 702, 443);
        init_color(COLOR_MEDIUMSLATEBLUE,         482, 408, 933);
        init_color(COLOR_MEDIUMSPRINGGREEN,         0, 980, 604);
        init_color(COLOR_MEDIUMTURQUOISE,         282, 820, 800);
        init_color(COLOR_MEDIUMVIOLETRED,         780,  82, 522);
        init_color(COLOR_MIDNIGHTBLUE,             98,  98, 439);
        init_color(COLOR_MINTCREAM,               961,1000, 980);
        init_color(COLOR_MISTYROSE,              1000, 894, 882);
        init_color(COLOR_MOCCASIN,               1000, 894, 710);
        init_color(COLOR_NAVAJOWHITE,            1000, 871, 678);
        init_color(COLOR_NAVY,                      0,   0, 502);
        init_color(COLOR_OLDLACE,                 992, 961, 902);
        init_color(COLOR_OLIVE,                   502, 502,   0);
        init_color(COLOR_OLIVEDRAB,               420, 557, 137);
        init_color(COLOR_ORANGE,                 1000, 647,   0);
        init_color(COLOR_ORANGERED,              1000, 271,   0);
        init_color(COLOR_ORCHID,                  855, 439, 839);
        init_color(COLOR_PALEGOLDENROD,           933, 910, 667);
        init_color(COLOR_PALEGREEN,               596, 984, 596);
        init_color(COLOR_PALETURQUOISE,           686, 933, 933);
        init_color(COLOR_PALEVIOLETRED,           859, 439, 576);
        init_color(COLOR_PAPAYAWHIP,             1000, 937, 835);
        init_color(COLOR_PEACHPUFF,              1000, 855, 725);
        init_color(COLOR_PERU,                    804, 522, 247);
        init_color(COLOR_PINK,                   1000, 753, 796);
        init_color(COLOR_PLUM,                    867, 627, 867);
        init_color(COLOR_POWDERBLUE,              690, 878, 902);
        init_color(COLOR_PURPLE,                  502,   0, 502);
        init_color(COLOR_REBECCAPURPLE,           400, 200, 600);
        init_color(COLOR_ROSYBROWN,               737, 561, 561);
        init_color(COLOR_ROYALBLUE,               255, 412, 882);
        init_color(COLOR_SADDLEBROWN,             545, 271,  75);
        init_color(COLOR_SALMON,                  980, 502, 447);
        init_color(COLOR_SANDYBROWN,              957, 643, 376);
        init_color(COLOR_SEAGREEN,                180, 545, 341);
        init_color(COLOR_SEASHELL,               1000, 961, 933);
        init_color(COLOR_SIENNA,                  627, 322, 176);
        init_color(COLOR_SILVER,                  753, 753, 753);
        init_color(COLOR_SKYBLUE,                 529, 808, 922);
        init_color(COLOR_SLATEBLUE,               416, 353, 804);
        init_color(COLOR_SLATEGRAY,               439, 502, 565);
        init_color(COLOR_SNOW,                   1000, 980, 980);
        init_color(COLOR_SPRINGGREEN,               0,1000, 498);
        init_color(COLOR_STEELBLUE,               275, 510, 706);
        init_color(COLOR_TAN,                     824, 706, 549);
        init_color(COLOR_TEAL,                      0, 502, 502);
        init_color(COLOR_THISTLE,                 847, 749, 847);
        init_color(COLOR_TOMATO,                 1000, 388, 278);
        init_color(COLOR_TURQUOISE,               251, 878, 816);
        init_color(COLOR_VIOLET,                  933, 510, 933);
        init_color(COLOR_WHEAT,                   961, 871, 702);
        init_color(COLOR_WHITESMOKE,              961, 961, 961);
        init_color(COLOR_YELLOWGREEN,             604, 804, 196);

	// Initialize the w3colorgroups array
	    max_w3colors = COLORS_COUNT + ADTNL_COLORS_COUNT;
    	num_w3colors = COLORS_COUNT;
    	w3colorgroups = calloc(max_w3colors, sizeof(W3ColorGroup*));
        w3colorgroups[0]=new_w3colorgroup(1, "black");
        w3colorgroups[1]=new_w3colorgroup(1, "red");
        w3colorgroups[2]=new_w3colorgroup(1, "green");
        w3colorgroups[3]=new_w3colorgroup(1, "yellow");
        w3colorgroups[4]=new_w3colorgroup(1, "blue");
        w3colorgroups[5]=new_w3colorgroup(3, "magenta", "fuchsia", "fuschia");
        w3colorgroups[6]=new_w3colorgroup(2, "cyan", "aqua");
        w3colorgroups[7]=new_w3colorgroup(1, "white");
        w3colorgroups[8]=new_w3colorgroup(1, "alice blue");
        w3colorgroups[9]=new_w3colorgroup(1, "antique white");
        w3colorgroups[10]=new_w3colorgroup(1, "aquamarine");
        w3colorgroups[11]=new_w3colorgroup(1, "azure");
        w3colorgroups[12]=new_w3colorgroup(1, "beige");
        w3colorgroups[13]=new_w3colorgroup(1, "bisque");
        w3colorgroups[14]=new_w3colorgroup(1, "blanched almond");
        w3colorgroups[15]=new_w3colorgroup(1, "blue violet");
        w3colorgroups[16]=new_w3colorgroup(1, "brown");
        w3colorgroups[17]=new_w3colorgroup(1, "burly wood");
        w3colorgroups[18]=new_w3colorgroup(1, "cadet blue");
        w3colorgroups[19]=new_w3colorgroup(1, "chartreuse");
        w3colorgroups[20]=new_w3colorgroup(1, "chocolate");
        w3colorgroups[21]=new_w3colorgroup(1, "coral");
        w3colorgroups[22]=new_w3colorgroup(1, "corn flower blue");
        w3colorgroups[23]=new_w3colorgroup(1, "corn silk");
        w3colorgroups[24]=new_w3colorgroup(1, "crimson");
        w3colorgroups[25]=new_w3colorgroup(1, "dark blue");
        w3colorgroups[26]=new_w3colorgroup(1, "dark cyan");
        w3colorgroups[27]=new_w3colorgroup(1, "dark goldenrod");
        w3colorgroups[28]=new_w3colorgroup(2, "dark gray", "dark grey");
        w3colorgroups[29]=new_w3colorgroup(1, "dark green");
        w3colorgroups[30]=new_w3colorgroup(1, "dark khaki");
        w3colorgroups[31]=new_w3colorgroup(1, "dark magenta");
        w3colorgroups[32]=new_w3colorgroup(1, "dark olive green");
        w3colorgroups[33]=new_w3colorgroup(1, "dark orange");
        w3colorgroups[34]=new_w3colorgroup(1, "dark orchid");
        w3colorgroups[35]=new_w3colorgroup(1, "dark red");
        w3colorgroups[36]=new_w3colorgroup(1, "dark salmon");
        w3colorgroups[37]=new_w3colorgroup(1, "dark sea green");
        w3colorgroups[38]=new_w3colorgroup(1, "dark slate blue");
        w3colorgroups[39]=new_w3colorgroup(2, "dark slate gray", "dark slate grey");
        w3colorgroups[40]=new_w3colorgroup(1, "dark turquoise");
        w3colorgroups[41]=new_w3colorgroup(1, "dark violet");
        w3colorgroups[42]=new_w3colorgroup(1, "deep pink");
        w3colorgroups[43]=new_w3colorgroup(1, "deep sky blue");
        w3colorgroups[44]=new_w3colorgroup(2, "dim gray", "dim grey");
        w3colorgroups[45]=new_w3colorgroup(1, "dodger blue");
        w3colorgroups[46]=new_w3colorgroup(1, "firebrick");
        w3colorgroups[47]=new_w3colorgroup(1, "floral white");
        w3colorgroups[48]=new_w3colorgroup(1, "forest green");
        w3colorgroups[49]=new_w3colorgroup(1, "gainsboro");
        w3colorgroups[50]=new_w3colorgroup(1, "ghost white");
        w3colorgroups[51]=new_w3colorgroup(1, "gold");
        w3colorgroups[52]=new_w3colorgroup(1, "goldenrod");
        w3colorgroups[53]=new_w3colorgroup(2, "gray", "grey");
        w3colorgroups[54]=new_w3colorgroup(1, "green yellow");
        w3colorgroups[55]=new_w3colorgroup(1, "honeydew");
        w3colorgroups[56]=new_w3colorgroup(1, "hot pink");
        w3colorgroups[57]=new_w3colorgroup(1, "indian red");
        w3colorgroups[58]=new_w3colorgroup(1, "indigo");
        w3colorgroups[59]=new_w3colorgroup(1, "ivory");
        w3colorgroups[60]=new_w3colorgroup(1, "khaki");
        w3colorgroups[61]=new_w3colorgroup(1, "lavender");
        w3colorgroups[62]=new_w3colorgroup(1, "lavender blush");
        w3colorgroups[63]=new_w3colorgroup(1, "lawn green");
        w3colorgroups[64]=new_w3colorgroup(1, "lemon chiffon");
        w3colorgroups[65]=new_w3colorgroup(1, "light blue");
        w3colorgroups[66]=new_w3colorgroup(1, "light coral");
        w3colorgroups[67]=new_w3colorgroup(1, "light cyan");
        w3colorgroups[68]=new_w3colorgroup(1, "light goldenrod yellow");
        w3colorgroups[69]=new_w3colorgroup(2, "light gray", "light grey");
        w3colorgroups[70]=new_w3colorgroup(1, "light green");
        w3colorgroups[71]=new_w3colorgroup(1, "light pink");
        w3colorgroups[72]=new_w3colorgroup(1, "light salmon");
        w3colorgroups[73]=new_w3colorgroup(1, "light sea green");
        w3colorgroups[74]=new_w3colorgroup(1, "light sky blue");
        w3colorgroups[75]=new_w3colorgroup(2, "light slate gray", "light slate grey");
        w3colorgroups[76]=new_w3colorgroup(1, "light steel blue");
        w3colorgroups[77]=new_w3colorgroup(1, "light yellow");
        w3colorgroups[78]=new_w3colorgroup(1, "lime");
        w3colorgroups[79]=new_w3colorgroup(1, "lime green");
        w3colorgroups[80]=new_w3colorgroup(1, "linen");
        w3colorgroups[81]=new_w3colorgroup(1, "maroon");
        w3colorgroups[82]=new_w3colorgroup(1, "medium aquamarine");
        w3colorgroups[83]=new_w3colorgroup(1, "medium blue");
        w3colorgroups[84]=new_w3colorgroup(1, "medium orchid");
        w3colorgroups[85]=new_w3colorgroup(1, "medium purple");
        w3colorgroups[86]=new_w3colorgroup(1, "medium sea green");
        w3colorgroups[87]=new_w3colorgroup(1, "medium slate blue");
        w3colorgroups[88]=new_w3colorgroup(1, "medium spring green");
        w3colorgroups[89]=new_w3colorgroup(1, "medium turquoise");
        w3colorgroups[90]=new_w3colorgroup(1, "medium violet red");
        w3colorgroups[91]=new_w3colorgroup(1, "midnight blue");
        w3colorgroups[92]=new_w3colorgroup(1, "mint cream");
        w3colorgroups[93]=new_w3colorgroup(1, "misty rose");
        w3colorgroups[94]=new_w3colorgroup(1, "moccasin");
        w3colorgroups[95]=new_w3colorgroup(1, "navajo white");
        w3colorgroups[96]=new_w3colorgroup(1, "navy");
        w3colorgroups[97]=new_w3colorgroup(1, "old lace");
        w3colorgroups[98]=new_w3colorgroup(1, "olive");
        w3colorgroups[99]=new_w3colorgroup(1, "olive drab");
        w3colorgroups[100]=new_w3colorgroup(1, "orange");
        w3colorgroups[101]=new_w3colorgroup(2, "orange red", "red orange");
        w3colorgroups[102]=new_w3colorgroup(1, "orchid");
        w3colorgroups[103]=new_w3colorgroup(1, "pale goldenrod");
        w3colorgroups[104]=new_w3colorgroup(1, "pale green");
        w3colorgroups[105]=new_w3colorgroup(1, "pale turquoise");
        w3colorgroups[106]=new_w3colorgroup(1, "pale violet red");
        w3colorgroups[107]=new_w3colorgroup(1, "papaya whip");
        w3colorgroups[108]=new_w3colorgroup(1, "peach puff");
        w3colorgroups[109]=new_w3colorgroup(1, "peru");
        w3colorgroups[110]=new_w3colorgroup(1, "pink");
        w3colorgroups[111]=new_w3colorgroup(1, "plum");
        w3colorgroups[112]=new_w3colorgroup(1, "powder blue");
        w3colorgroups[113]=new_w3colorgroup(1, "purple");
        w3colorgroups[114]=new_w3colorgroup(1, "rebecca purple");
        w3colorgroups[115]=new_w3colorgroup(1, "rosy brown");
        w3colorgroups[116]=new_w3colorgroup(1, "royal blue");
        w3colorgroups[117]=new_w3colorgroup(1, "saddle brown");
        w3colorgroups[118]=new_w3colorgroup(1, "salmon");
        w3colorgroups[119]=new_w3colorgroup(1, "sandy brown");
        w3colorgroups[120]=new_w3colorgroup(1, "sea green");
        w3colorgroups[121]=new_w3colorgroup(1, "sea shell");
        w3colorgroups[122]=new_w3colorgroup(1, "sienna");
        w3colorgroups[123]=new_w3colorgroup(1, "silver");
        w3colorgroups[124]=new_w3colorgroup(1, "sky blue");
        w3colorgroups[125]=new_w3colorgroup(1, "slate blue");
        w3colorgroups[126]=new_w3colorgroup(2, "slate gray", "slate grey");
        w3colorgroups[127]=new_w3colorgroup(1, "snow");
        w3colorgroups[128]=new_w3colorgroup(1, "spring green");
        w3colorgroups[129]=new_w3colorgroup(1, "steel blue");
        w3colorgroups[130]=new_w3colorgroup(1, "tan");
        w3colorgroups[131]=new_w3colorgroup(1, "teal");
        w3colorgroups[132]=new_w3colorgroup(1, "thistle");
        w3colorgroups[133]=new_w3colorgroup(1, "tomato");
        w3colorgroups[134]=new_w3colorgroup(1, "turquoise");
        w3colorgroups[135]=new_w3colorgroup(1, "violet");
        w3colorgroups[136]=new_w3colorgroup(1, "wheat");
        w3colorgroups[137]=new_w3colorgroup(2, "white smoke", "smoke white");
        w3colorgroups[138]=new_w3colorgroup(1, "yellow green");

    } else
        return FALSE;
    return TRUE;
}

int free_w3colors() {
    for(int i = 0; i<num_w3colors; i++) {
        free(w3colorgroups[i]);
    }
    free(w3colorgroups);
    return 0;
}

#undef __W3COLORS_C__
