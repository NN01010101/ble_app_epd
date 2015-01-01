#ifndef _EPD_FONT_H_
#define _EPD_FONT_H_

#define FONT_WIDTH       7 // for Font 7x8
#define FONT_HEIGHT      8 // actually full 8-bits high

typedef struct {
    unsigned char charbits [8];
} EPD_chardef_t;

const EPD_chardef_t EPD_font [128] = {
    {{
        /* @0 '_' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @0 '!' (7 pixels wide) */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @10 '"' (7 pixels wide) */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @20 '#' },(7 pixels wide) */
        (unsigned char) ~0x14, /*    # #   */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x50  /*  # #     */
    }},
    {{
        /* @30 '$' (7 pixels wide) */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x40, /*  #       */
        (unsigned char) ~0x30, /*   ##     */
        (unsigned char) ~0x08, /*     #    */
        (unsigned char) ~0x70, /*  ###     */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x20  /*   #      */
    }},
    {{
        /* @40 '%' (7 pixels wide) */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x50, /*  # #     */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x78, /*  ####    */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @50 '&' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x18, /*    ##    */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x58, /*  # ##    */
        (unsigned char) ~0x48, /*  #  #    */
        (unsigned char) ~0x3C, /*   ####   */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @60 ''' (7 pixels wide) */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @70 '(' (7 pixels wide) */
        (unsigned char) ~0x08, /*     #    */
        (unsigned char) ~0x08, /*     #    */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x08, /*     #    */
        (unsigned char) ~0x08  /*     #    */
    }},
    {{
        /* @80 ')' (7 pixels wide) */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x20  /*   #      */
    }},
    {{
        /* @90 '*' (7 pixels wide) */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @100 '+' (7 pixels wide) */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @110 ',' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x18, /*    ##    */
        (unsigned char) ~0x30, /*   ##     */
        (unsigned char) ~0x20  /*   #      */
    }},
    {{
        /* @120 '-' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @130 '.' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x30, /*   ##     */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @140 '/' (7 pixels wide) */
        (unsigned char) ~0x04, /*      #   */
        (unsigned char) ~0x08, /*     #    */
        (unsigned char) ~0x08, /*     #    */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x40  /*  #       */
    }},
    {{
        /* @150 '0' (7 pixels wide) */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @160 '1' (7 pixels wide) */
        (unsigned char) ~0x30, /*   ##     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @170 '2' (7 pixels wide) */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x08, /*     #    */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x40, /*  #       */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @180 '3' (7 pixels wide) */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x04, /*      #   */
        (unsigned char) ~0x18, /*    ##    */
        (unsigned char) ~0x04, /*      #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @190 '4' (7 pixels wide) */
        (unsigned char) ~0x08, /*     #    */
        (unsigned char) ~0x18, /*    ##    */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x48, /*  #  #    */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x08, /*     #    */
        (unsigned char) ~0x1C, /*    ###   */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @200 '5' (7 pixels wide) */
        (unsigned char) ~0x3C, /*   ####   */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x04, /*      #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @210 '6' (7 pixels wide) */
        (unsigned char) ~0x1C, /*    ###   */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x40, /*  #       */
        (unsigned char) ~0x78, /*  ####    */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x00, /*          */
    }},
    {{
        /* @220 '7' (7 pixels wide) */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x04, /*      #   */
        (unsigned char) ~0x08, /*     #    */
        (unsigned char) ~0x08, /*     #    */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @230 '8' (7 pixels wide) */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @240 '9' (7 pixels wide) */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x3C, /*   ####   */
        (unsigned char) ~0x04, /*      #   */
        (unsigned char) ~0x08, /*     #    */
        (unsigned char) ~0x70, /*  ###     */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @250 ':' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x30, /*   ##     */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x30, /*   ##     */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @260 ';' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x18, /*    ##    */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x18, /*    ##    */
        (unsigned char) ~0x30, /*   ##     */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @270 '<' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x04, /*      #   */
        (unsigned char) ~0x18, /*    ##    */
        (unsigned char) ~0x60, /*  ##      */
        (unsigned char) ~0x18, /*    ##    */
        (unsigned char) ~0x04, /*      #   */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @280 '=' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @290 '>' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x40, /*  #       */
        (unsigned char) ~0x30, /*   ##     */
        (unsigned char) ~0x0C, /*     ##   */
        (unsigned char) ~0x30, /*   ##     */
        (unsigned char) ~0x40, /*  #       */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @300 '?' (7 pixels wide) */
        (unsigned char) ~0x30, /*   ##     */
        (unsigned char) ~0x48, /*  #  #    */
        (unsigned char) ~0x08, /*     #    */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x30, /*   ##     */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @310 '@' (7 pixels wide) */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x4C, /*  #  ##   */
        (unsigned char) ~0x54, /*  # # #   */
        (unsigned char) ~0x54, /*  # # #   */
        (unsigned char) ~0x4C, /*  #  ##   */
        (unsigned char) ~0x40, /*  #       */
        (unsigned char) ~0x3C  /*   ####   */
    }},
    {{
        /* @320 'A' (7 pixels wide) */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0xEE, /* ### ###  */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @330 'B' (7 pixels wide) */
        (unsigned char) ~0xF8, /* #####    */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x78, /*  ####    */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0xF8, /* #####    */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @340 'C' (7 pixels wide) */
        (unsigned char) ~0x3C, /*   ####   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x40, /*  #       */
        (unsigned char) ~0x40, /*  #       */
        (unsigned char) ~0x40, /*  #       */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @350 'D' (7 pixels wide) */
        (unsigned char) ~0xF0, /* ####     */
        (unsigned char) ~0x48, /*  #  #    */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x48, /*  #  #    */
        (unsigned char) ~0xF0, /* ####     */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @360 'E' (7 pixels wide) */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x24, /*   #  #   */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x24, /*   #  #   */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @370 'F' (7 pixels wide) */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x24, /*   #  #   */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x70, /*  ###     */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @380 'G' (7 pixels wide) */
        (unsigned char) ~0x3C, /*   ####   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x40, /*  #       */
        (unsigned char) ~0x40, /*  #       */
        (unsigned char) ~0x4E, /*  #  ###  */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @390 'H' (7 pixels wide) */
        (unsigned char) ~0xEE, /* ### ###  */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0xEE, /* ### ###  */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @400 'I' (7 pixels wide) */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @410 'J' (7 pixels wide) */
        (unsigned char) ~0x3C, /*   ####   */
        (unsigned char) ~0x08, /*     #    */
        (unsigned char) ~0x08, /*     #    */
        (unsigned char) ~0x08, /*     #    */
        (unsigned char) ~0x48, /*  #  #    */
        (unsigned char) ~0x48, /*  #  #    */
        (unsigned char) ~0x30, /*   ##     */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @420 'K' (7 pixels wide) */
        (unsigned char) ~0xEE, /* ### ###  */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x48, /*  #  #    */
        (unsigned char) ~0x70, /*  ###     */
        (unsigned char) ~0x48, /*  #  #    */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0xE6, /* ###  ##  */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @430 'L' (7 pixels wide) */
        (unsigned char) ~0x70, /*  ###     */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x24, /*   #  #   */
        (unsigned char) ~0x24, /*   #  #   */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @440 'M' (7 pixels wide) */
        (unsigned char) ~0xEE, /* ### ###  */
        (unsigned char) ~0x6C, /*  ## ##   */
        (unsigned char) ~0x6C, /*  ## ##   */
        (unsigned char) ~0x54, /*  # # #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0xEE, /* ### ###  */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @450 'N' (7 pixels wide) */
        (unsigned char) ~0xEE, /* ### ###  */
        (unsigned char) ~0x64, /*  ##  #   */
        (unsigned char) ~0x64, /*  ##  #   */
        (unsigned char) ~0x54, /*  # # #   */
        (unsigned char) ~0x54, /*  # # #   */
        (unsigned char) ~0x4C, /*  #  ##   */
        (unsigned char) ~0xEC, /* ### ##   */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @460 'O' (7 pixels wide) */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @470 'P' (7 pixels wide) */
        (unsigned char) ~0x78, /*  ####    */
        (unsigned char) ~0x24, /*   #  #   */
        (unsigned char) ~0x24, /*   #  #   */
        (unsigned char) ~0x24, /*   #  #   */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x70, /*  ###     */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @480 'Q' (7 pixels wide) */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x1C  /*    ###   */
    }},
    {{
        /* @490 'R' (7 pixels wide) */
        (unsigned char) ~0x78, /*  ####    */
        (unsigned char) ~0x24, /*   #  #   */
        (unsigned char) ~0x24, /*   #  #   */
        (unsigned char) ~0x24, /*   #  #   */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x24, /*   #  #   */
        (unsigned char) ~0x72, /*  ###  #  */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @500 'S' (7 pixels wide) */
        (unsigned char) ~0x34, /*   ## #   */
        (unsigned char) ~0x4C, /*  #  ##   */
        (unsigned char) ~0x40, /*  #       */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x04, /*      #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x78, /*  ####    */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @510 'T' (7 pixels wide) */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x54, /*  # # #   */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @520 'U' (7 pixels wide) */
        (unsigned char) ~0xEE, /* ### ###  */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @530 'V' (7 pixels wide) */
        (unsigned char) ~0xEE, /* ### ###  */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x48, /*  #  #    */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x30, /*   ##     */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @540 'W' (7 pixels wide) */
        (unsigned char) ~0xEE, /* ### ###  */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x54, /*  # # #   */
        (unsigned char) ~0x54, /*  # # #   */
        (unsigned char) ~0x54, /*  # # #   */
        (unsigned char) ~0x54, /*  # # #   */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @550 'X' (7 pixels wide) */
        (unsigned char) ~0xC6, /* ##   ##  */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0xC6, /* ##   ##  */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @560 'Y' (7 pixels wide) */
        (unsigned char) ~0xEE, /* ### ###  */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @570 'Z' (7 pixels wide) */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x08, /*     #    */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @580 '[' (7 pixels wide) */
        (unsigned char) ~0x18, /*    ##    */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x18  /*    ##    */
    }},
    {{
        /* @590 '\' (7 pixels wide) */
        (unsigned char) ~0x40, /*  #       */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x08, /*     #    */
        (unsigned char) ~0x08  /*     #    */
    }},
    {{
        /* @600 ']' (7 pixels wide) */
        (unsigned char) ~0x30, /*   ##     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x30  /*   ##     */
    }},
    {{
        /* @610 '^' (7 pixels wide) */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @620 '_' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0xFE  /* #######  */
    }},
    {{
        /* @630 '`' (7 pixels wide) */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @640 'a' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x3C, /*   ####   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x7E, /*  ######  */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @650 'b' (7 pixels wide) */
        (unsigned char) ~0xC0, /* ##       */
        (unsigned char) ~0x40, /*  #       */
        (unsigned char) ~0x58, /*  # ##    */
        (unsigned char) ~0x64, /*  ##  #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0xF8, /* #####    */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @660 'c' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x3C, /*   ####   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x40, /*  #       */
        (unsigned char) ~0x40, /*  #       */
        (unsigned char) ~0x3C, /*   ####   */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @670 'd' (7 pixels wide) */
        (unsigned char) ~0x0C, /*     ##   */
        (unsigned char) ~0x04, /*      #   */
        (unsigned char) ~0x34, /*   ## #   */
        (unsigned char) ~0x4C, /*  #  ##   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x3E, /*   #####  */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @680 'e' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x40, /*  #       */
        (unsigned char) ~0x3C, /*   ####   */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @690 'f' (7 pixels wide) */
        (unsigned char) ~0x0C, /*     ##   */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x3C, /*   ####   */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x3C, /*   ####   */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @700 'g' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x36, /*   ## ##  */
        (unsigned char) ~0x4C, /*  #  ##   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x3C, /*   ####   */
        (unsigned char) ~0x04, /*      #   */
        (unsigned char) ~0x38  /*   ###    */
    }},
    {{
        /* @710 'h' (7 pixels wide) */
        (unsigned char) ~0xC0, /* ##       */
        (unsigned char) ~0x40, /*  #       */
        (unsigned char) ~0x58, /*  # ##    */
        (unsigned char) ~0x64, /*  ##  #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0xEE, /* ### ###  */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @720 'i' (7 pixels wide) */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x70, /*  ###     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @730 'j' (7 pixels wide) */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x78, /*  ####    */
        (unsigned char) ~0x08, /*     #    */
        (unsigned char) ~0x08, /*     #    */
        (unsigned char) ~0x08, /*     #    */
        (unsigned char) ~0x08, /*     #    */
        (unsigned char) ~0x70  /*  ###     */
    }},
    {{
        /* @740 'k' (7 pixels wide) */
        (unsigned char) ~0xC0, /* ##       */
        (unsigned char) ~0x40, /*  #       */
        (unsigned char) ~0x5C, /*  # ###   */
        (unsigned char) ~0x48, /*  #  #    */
        (unsigned char) ~0x70, /*  ###     */
        (unsigned char) ~0x48, /*  #  #    */
        (unsigned char) ~0xDC, /* ## ###   */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @750 'l' (7 pixels wide) */
        (unsigned char) ~0x30, /*   ##     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @760 'm' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0xE8, /* ### #    */
        (unsigned char) ~0x54, /*  # # #   */
        (unsigned char) ~0x54, /*  # # #   */
        (unsigned char) ~0x54, /*  # # #   */
        (unsigned char) ~0xFE, /* #######  */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @770 'n' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0xD8, /* ## ##    */
        (unsigned char) ~0x64, /*  ##  #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0xEE, /* ### ###  */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @780 'o' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @790 'p' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0xD8,/* ## ##    */
        (unsigned char) ~0x64, /*  ##  #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x78, /*  ####    */
        (unsigned char) ~0x40, /*  #       */
        (unsigned char) ~0xE0  /* ###      */
    }},
    {{
        /* @800 'q' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x36, /*   ## ##  */
        (unsigned char) ~0x4C, /*  #  ##   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x3C, /*   ####   */
        (unsigned char) ~0x04, /*      #   */
        (unsigned char) ~0x0E  /*     ###  */
    }},
    {{
        /* @810 'r' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x6C, /*  ## ##   */
        (unsigned char) ~0x30, /*   ##     */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x78, /*  ####    */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @820 's' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x3C, /*   ####   */
        (unsigned char) ~0x40, /*  #       */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x04, /*      #   */
        (unsigned char) ~0x78, /*  ####    */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @830 't' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x40, /*  #       */
        (unsigned char) ~0xF8, /* #####    */
        (unsigned char) ~0x40, /*  #       */
        (unsigned char) ~0x40, /*  #       */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x38, /*   ###    */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @840 'u' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0xCC, /* ##  ##   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x4C, /*  #  ##   */
        (unsigned char) ~0x36, /*   ## ##  */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @850 'v' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0xEE, /* ### ###  */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x48, /*  #  #    */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x30, /*   ##     */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @860 'w' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0xEE, /* ### ###  */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x54, /*  # # #   */
        (unsigned char) ~0x54, /*  # # #   */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @870 'x' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x6C, /*  ## ##   */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x6C, /*  ## ##   */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @880 'y' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0xEE, /* ### ###  */
        (unsigned char) ~0x44, /*  #   #   */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x28, /*   # #    */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x70  /*  ###     */
    }},
    {{
        /* @890 'z' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x48, /*  #  #    */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x24, /*   #  #   */
        (unsigned char) ~0x7C, /*  #####   */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @900 '{{' (7 pixels wide) */
        (unsigned char) ~0x08, /*     #    */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x30, /*   ##     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x08, /*     #    */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @910 '|' (7 pixels wide) */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10  /*    #     */
    }},
    {{
        /* @920 '}' (7 pixels wide) */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x18, /*    ##    */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x10, /*    #     */
        (unsigned char) ~0x20, /*   #      */
        (unsigned char) ~0x00  /*          */
    }},
    {{
        /* @930 '~' (7 pixels wide) */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x34, /*   ## #   */
        (unsigned char) ~0x58, /*  # ##    */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00, /*          */
        (unsigned char) ~0x00  /*          */
    }},
};

#endif /* _EPD_FONT_H_ */
