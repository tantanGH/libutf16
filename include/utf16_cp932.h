#ifndef __H_UTF16_CP932__
#define __H_UTF16_CP932__

#include <stdint.h>

extern const uint16_t utf16_to_cp932_map[ 0x10000 ];

void utf16_to_cp932(uint8_t* cp932_buffer, size_t cp932_buffer_bytes, const uint8_t* utf16_buffer, size_t utf16_buffer_bytes);

#endif