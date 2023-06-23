from Include.REGh import *


def construct_asm(op: str, dst=None, dst_offset: int = None, src=None) -> str:
    if dst_offset is None and isinstance(dst, REG) and isinstance(src, REG):
        return "\t" + op + " \t " + to_string(dst) + " \t , \t " + to_string(src)
    elif dst_offset is None and isinstance(dst, str) and isinstance(src, str):
        return "\t" + op + " \t " + src + " \t , \t " + dst
    elif dst_offset is None and isinstance(dst, REG) and isinstance(src, int):
        return "\t" + op + " \t " + to_string(dst) + " \t , \t " + "[ ebp" + (" - " if src > 0 else " + ") + str(
            abs(src)) + " ]"
    elif dst_offset is None and isinstance(dst, REG) and isinstance(src, str):
        return "\t" + op + " \t " + to_string(dst) + " \t , \t " + src
    elif dst_offset is None and isinstance(dst, int) and isinstance(src, REG):
        return "\t" + op + " \t " + "[ ebp" + (" - " if dst > 0 else " + ") + str(
            abs(dst)) + " ]" + " \t , \t " + to_string(src)
    elif dst_offset is None and isinstance(dst, int) and isinstance(src, str):
        return "\t" + op + " \t " + "[ ebp" + (" - " if dst > 0 else " + ") + str(abs(dst)) + " ]" + " \t , \t " + src
    elif dst_offset is None and dst is None and isinstance(src, str):
        return "\t" + op + "\t" + src
    elif dst_offset is None and dst is None and isinstance(src, REG):
        return "\t" + op + "\t" + to_string(src)
    elif dst_offset is None and dst is None and isinstance(src, int):
        return "\t" + op + "\t" + "[ ebp" + (" - " if src > 0 else " + ") + str(abs(src)) + " ]"
    elif dst_offset is None and dst is None and src is None:
        return "\t" + op
    elif dst_offset is not None and isinstance(dst, REG) and isinstance(src, REG):
        return "\t" + op + "\t" + construct_asm_mem(dst, dst_offset, "dword") + " \t , \t " + to_string(src)
    elif dst_offset is not None and isinstance(dst, REG) and isinstance(src, int):
        return "\t" + op + "\t" + construct_asm_mem(
            dst, dst_offset, "dword") + " \t , \t " + "[ ebp" + (" - " if src > 0 else " + ") + str(abs(src)) + " ]"
    elif dst_offset is not None and isinstance(dst, REG) and isinstance(src, str):
        return "\t" + op + "\t" + construct_asm_mem(dst, dst_offset, "dword") + " \t , \t " + src
    else:
        print("菜狗ConstructASMh.py的elif写错辣！！！")


def construct_asm_mem(reg: REG, offset: int, data_size: str = ""):
    return data_size + "[ " + to_string(reg) + (" - " if offset > 0 else " + ") + str(abs(offset)) + " ]"
