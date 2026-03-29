#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "utf16_cp932.h"

extern uint16_t utf16_to_cp932_map[ 0x10000 ];

//
//  utf-16 to cp932
//
void utf16_to_cp932(uint8_t* cp932_buffer, size_t cp932_buffer_bytes, const uint8_t* utf16_buffer, size_t utf16_buffer_bytes) {

    // check buffer length (at least endian information is required)
    if (cp932_buffer_bytes < 2 || utf16_buffer_bytes < 2) return;

    // check utf-16 endian
    int16_t endian = utf16_buffer[0] == 0xfe ? 1 : 0;   // 0:little, 1:big
    
    // number of characters
    size_t utf16_char_len = ( utf16_buffer_bytes - 2 ) / 2;

    // initialize cp932 buffer
    cp932_buffer[0] = '\0';

    // CAUTION: utf16_buffer may be odd address and word access will fail on 68000 machines
    for (int16_t i = 0; i < utf16_char_len; i++) {
        uint16_t utf16_code = ( endian == 0 ) ? ( utf16_buffer[ 2 + i * 2 + 1 ] << 8 ) | ( utf16_buffer[ 2 + i * 2 + 0 ] ) : 
                                                ( utf16_buffer[ 2 + i * 2 + 0 ] << 8 ) | ( utf16_buffer[ 2 + i * 2 + 1 ] );    
        uint16_t cp932_code = utf16_to_cp932_map[ utf16_code ];
        size_t cp932_buffer_index = strlen(cp932_buffer);
        if ((cp932_buffer_index + 2) >= cp932_buffer_bytes) break;           // buffer overflow check
        cp932_buffer[ cp932_buffer_index ] = (cp932_code >> 8);
        cp932_buffer[ cp932_buffer_index + 1 ] = (cp932_code & 0xff);        // can be \0
        cp932_buffer[ cp932_buffer_index + 2 ] = '\0';
    }
}
