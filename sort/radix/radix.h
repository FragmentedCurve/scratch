#ifndef _RADIX_H_
#define _RADIX_H_
uint8_t* radix_lsb(const uint8_t* item_data, size_t chunk_size, size_t chunk_count);
uint8_t* radix_msb(const uint8_t* item_data, size_t chunk_size, size_t chunk_count);
uint8_t* radix_sort(
		    const uint8_t* buf,
		    size_t chunk_size,
		    size_t chunk_count,
		    size_t last_byte_position,
		    uint8_t (*item_num)(uint8_t*,size_t,size_t,size_t));
#endif // _RADIX_H_
