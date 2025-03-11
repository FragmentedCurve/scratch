/*
 * Copyright (c) 2024 Paco Pascal <me@pacopascal.com>
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

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#define COUNT_LEN (UINT8_MAX+1)
#define COUNT_BYTES (COUNT_LEN * sizeof(size_t))

static uint8_t*
_radix_sort(
	uint8_t* rbuf,
	uint8_t* wbuf,
	size_t chunk_size,
	size_t chunk_count,
	size_t last_byte_position,
	uint8_t (*item_num)(uint8_t*,size_t,size_t,size_t))
{
	size_t counts[COUNT_LEN];

	for (size_t pos = 0; pos < last_byte_position; pos++) {
		{ // Count up digits/bytes in position
			memset(counts, 0, COUNT_BYTES);
			for (size_t i = 0; i < chunk_count; i++) {
				uint8_t index = item_num(rbuf, chunk_size, i, pos);
				counts[index]++;
			}
		}

		// Nothing left to do
		if (counts[0] == chunk_count)
			continue;

		{ // Prefix sum of digit counts
			for (size_t i = 1; i < COUNT_LEN; i++)
				counts[i] += counts[i - 1];
		}

		{ // Move data into it's new position
			for (size_t i = 0; i < chunk_count; i++) {
				size_t ri = chunk_count - i - 1;
				uint8_t c = item_num(rbuf, chunk_size, ri, pos);
				size_t wi = --counts[c];
				switch (chunk_size) {
				case sizeof(uint8_t):
					wbuf[wi] = rbuf[ri];
					break;
				case sizeof(uint16_t):
					((uint16_t*)wbuf)[wi] = ((uint16_t*)rbuf)[ri];
					break;
				case sizeof(uint32_t):
					((uint32_t*)wbuf)[wi] = ((uint32_t*)rbuf)[ri];
					break;
				case sizeof(uint64_t):
					((uint64_t*)wbuf)[wi] = ((uint64_t*)rbuf)[ri];
					break;
				default:
					memcpy(
						(wbuf + chunk_size * wi),
						(rbuf + chunk_size * ri),
						chunk_size);
					break;
				}
			}
		}

		{ // Swap the read & write buffers
			uint8_t* temp = wbuf;
			wbuf = rbuf;
			rbuf = temp;
		}
	}

	return rbuf;
}


uint8_t*
radix_sort(
	const uint8_t* buf,
	size_t chunk_size,
	size_t chunk_count,
	size_t last_byte_position,
	uint8_t (*item_num)(uint8_t*,size_t,size_t,size_t))
{
	uint8_t* rbuf = malloc(chunk_size * chunk_count);
	uint8_t* wbuf = malloc(chunk_size * chunk_count);

	if (!rbuf || !wbuf) {
		free(rbuf);
		free(wbuf);
		return NULL;
	}

	memcpy(rbuf, buf, (chunk_size * chunk_count));

	if (_radix_sort(rbuf, wbuf, chunk_size, chunk_count, last_byte_position, item_num) == wbuf) {
		free(rbuf);
		return wbuf;
	}

	free(wbuf);
	return rbuf;
}

static inline uint8_t
lsb_byte(uint8_t* buf, size_t byte_len, size_t index, size_t pos)
{
	return buf[byte_len*index+pos];
}

static inline uint8_t
msb_byte(uint8_t* buf, size_t byte_len, size_t index, size_t pos)
{
	return buf[byte_len*index-pos+byte_len-1];
}

uint8_t*
radix_lsb(const uint8_t* item_data, size_t chunk_size, size_t chunk_count)
{
	return radix_sort(item_data, chunk_size, chunk_count, chunk_size, lsb_byte);
}

uint8_t*
radix_msb(const uint8_t* item_data, size_t chunk_size, size_t chunk_count)
{
	return radix_sort(item_data, chunk_size, chunk_count, chunk_size, msb_byte);
}
