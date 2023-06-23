def generate_nasm_code(input_file, output_file):
    with open(input_file, 'r') as input:
        lines = input.readlines()

    with open(output_file, 'w') as output:
        output.write("global _start\n")
        output.write("extern myprint\n\n")
        output.write("_start:\n")
        output.write("\tpush\tebp\n")
        output.write("\tmov\tebp,\tesp\n")

        for line in lines:
            parts = line.strip().split('\t')
            if len(parts) == 4:
                index, op, arg1, result = parts
                if op == 'ASSIGN':
                    output.write(f"\tmov\t{result},\t{arg1}\n")
                elif op == 'ADD':
                    output.write(f"\tadd\t{arg1},\t{result}\n")
            else:
                # Handle other operations if needed
                pass

        output.write("\n")
        output.write("\tmov\teax,\t1\n")
        output.write("\tmov\tebx,\t0\n")
        output.write("\tint\t80h\n")

# 调用函数生成NASM代码
generate_nasm_code('3code.txt', 'out.asm')
