/*
 *  Copyright (C) 2010-2022 Fabio Cavallo (aka FHorse)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include "mappers.h"
#include "info.h"
#include "mem_map.h"

void map_init_227(void) {
	EXTCL_CPU_WR_MEM(227);

	extcl_cpu_wr_mem_227(0x8000, 0x00);

	if (info.mapper.submapper == WAIXING_FW01) {
		info.prg.ram.banks_8k_plus = 1;
		info.prg.ram.bat.banks = TRUE;
	}
}
void extcl_cpu_wr_mem_227(WORD address, UNUSED(BYTE value)) {
	WORD bank[2], base = ((address >> 2) & 0x1F) | ((address & 0x0100) >> 3);

	if (address & 0x0080) {
		bank[0] = base;
		bank[1] = base + (address & 0x0001);
	} else {
		WORD mask = (address & 0x0001) ? 0x3E : 0xFF;

		bank[0] = base & mask;

		if (!(address & 0x0200)) {
			bank[1] = base & 0x38;
		} else {
			bank[1] = base | 0x07;
		}
	}

	_control_bank(bank[0], info.prg.rom.max.banks_16k)
	map_prg_rom_8k(2, 0, bank[0]);

	_control_bank(bank[1], info.prg.rom.max.banks_16k)
	map_prg_rom_8k(2, 2, bank[1]);

	map_prg_rom_8k_update();

	if (address & 0x0002) {
		mirroring_H();
	} else {
		mirroring_V();
	}
}
