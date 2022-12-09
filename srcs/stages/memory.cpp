#include "../../incs/stages.hpp"
#include <iostream>
#include <algorithm>

bool	memory(Info &info);
ui		get_data_from_memory(Info &info);
bool	cmp(const Memory &mem1, const Memory &mem2);

bool	memory(Info &info) {
	Instruction	instruction = info.exmem.get_instruction();
	instruction.set_status(MEM);
	info.memwb.set_instruction(instruction);

	// EX/MEM pipe is empty
	if (instruction.get_pc() == 0) {
		// set all values to 0
		info.memwb.set_mem_to_reg(false);
		info.memwb.set_reg_write(false);
		info.memwb.set_data_read(0);
		info.memwb.set_alu_result(0);
		return (true);
	}

	// set mem/wb signal ------------------------------------------------------------------------------------
		info.memwb.set_mem_to_reg(info.exmem.get_mem_to_reg());
		info.memwb.set_reg_write(info.exmem.get_reg_write());
	// set mem/wb signal ------------------------------------------------------------------------------------

	// set mem/wb values ------------------------------------------------------------------------------------
		// TODO: What should I do if memRead is false?
		info.memwb.set_data_read(0);
		if (info.exmem.get_mem_read() == true) {
			info.memwb.set_data_read(get_data_from_memory(info));
		}
		info.memwb.set_alu_result(info.exmem.get_alu_result());
		info.memwb.set_write_register(info.exmem.get_write_register());
	// set mem/wb values ------------------------------------------------------------------------------------

	// write data to memory ---------------------------------------------------------------------------------
		if (info.exmem.get_mem_write() == true) {
			Memory	mem;
			mem.address = info.exmem.get_alu_result();
			mem.value = info.exmem.get_write_data();
			info.mem.push_back(mem);
			sort(info.mem.begin(), info.mem.end(), cmp);
		}
	// write data to memory ---------------------------------------------------------------------------------
	
	// TODO: set forwarding unit ----------------------------------------------------------------------------------
		// info.forwarding_unit.set_reg_write(info.exmem.get_reg_write());
	(void) info;
	return (true);
}

ui	get_data_from_memory(Info &info) {
	ui	ret = 0;
	ui	address = info.memwb.get_alu_result();

	find_if(info.mem.begin(), info.mem.end(), [&ret, address](const Memory &mem) {
		if (mem.address == address) {
			ret = mem.value;
			return (ret);
		}
		return (ret);
	});
	return (ret);
}

bool	cmp(const Memory &mem1, const Memory &mem2) {
	return (mem1.address < mem2.address);
}