#ifndef _FONT_H
#define	_FONT_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

typedef struct {
    uint16_t width;
    uint16_t height;
    uint16_t const *data_table;
} font_type;

#endif	/* FONT_H */

