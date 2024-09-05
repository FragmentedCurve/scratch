/*
 * Copyright (c) 2024 Paco Pascal  <me@pacopascal.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

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
