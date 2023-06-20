import pathlib
import types
import time

class Instruction:
    def __init__(self,opcode,opnd):
        self.opcode = opcode
        self.opnd = opnd


class VMEngine:
    def __init__(self):
        self.pc = 0
        self.stack = []
        self.values = {}

        self.set_black_list([])
        self.set_file_options(["read_text", "exists", "glob", "is_dir", "read_bytes", "mkdir", "write_bytes", "write_text", "is_dir", "is_file"])

    def set_black_list(self, blacklist):
        self.values["blacklist"] = blacklist
    
    def get_black_list(self):
        return self.values["blacklist"]
    
    def set_file_options(self, options):
        self.values["file_options"] = options
    
    def get_file_options(self):
        return self.values["file_options"]

    def run(self, instructions):
        while True:
            if self.pc >= len(instructions):
                break
            
            insn = instructions[self.pc]
            print(self.pc,self.stack)

            match insn.opcode:
                case "😀":
                    self.stack.append(insn.opnd[0])

                case "😄":
                    operand1 = self.stack.pop()
                    operand2 = self.stack.pop()
                    if type(operand1) != int or type(operand2) != int:
                        print("Operand type error!")
                        break
                    self.stack.append(operand1 + operand2)

                case "😁":
                    operand1 = self.stack.pop()
                    operand2 = self.stack.pop()
                    if type(operand1) != int or type(operand2) != int:
                        print("Operand type error!")
                        break
                    self.stack.append(operand1 - operand2)

                case "😆":
                    operand1 = self.stack.pop()
                    operand2 = self.stack.pop()
                    if type(operand1) != int or type(operand2) != int:
                        print("Operand type error!")
                        break
                    self.stack.append(operand1 * operand2)

                case "🥹":
                    operand1 = self.stack.pop()
                    operand2 = self.stack.pop()
                    if type(operand1) != int or type(operand2) != int:
                        print("Operand type error!")
                        break
                    self.stack.append(operand1 / operand2)

                case "😂":
                    operand1 = insn.opnd[0]
                    value = self.stack.pop()

                    if type(operand1) != str:
                        print("Operand type error!")
                        break

                    self.values[operand1] = value

                case "😅":
                    operand1 = insn.opnd[0]
                    if type(operand1) != str:
                        print("Operand type error!")
                        break

                    try:    
                        value = self.values[operand1]
                        self.stack.append(value)

                    except KeyError:
                        print("Values key error!")
                        break

                case "🤣":
                    key = insn.opnd[0]
                    operand1 = self.stack.pop()
                    operand2 = self.stack.pop()
                    if type(operand1) != type(operand2):
                        print("Operand type error!")
                        break
                    
                    self.values[key] = operand1 == operand2
                    
                case "🥲":
                    index = insn.opnd[0]
                    if type(index) != int:
                        print("Operand type error!")
                        break
                    
                    self.pc += index
                    continue

                case "😍":
                    index = insn.opnd[1]
                    key = insn.opnd[0]

                    if type(index) != int or type(key) != str:
                        print("Operand type error!")
                        break
                    try:
                        result = self.values[key]
                    except KeyError:
                        print("Values key error!")
                        break 
                
                    if result:
                        self.pc += index
                    else:
                        self.pc += 1
                    continue

                case "🥰":
                    index = insn.opnd[1]
                    key = insn.opnd[0]

                    if type(index) != int or type(key) != str:
                        print("Operand type error!")
                        break
                    
                    try:
                        result = self.values[key]
                    except KeyError:
                        print("Values key error!")
                        break 
                
                    if not result:
                        self.pc += index
                    else:
                        self.pc += 1
                    continue
                
                case "✓":
                    print(self.stack.pop())
                
                case "⭐️":
                    data1 = self.stack.pop()
                    data2 = self.stack.pop()
                    if type(data1) != str or type(data2) != str:
                        print("Operand type error!")
                        break
                    self.stack.append(data1 + data2)

                case "♥️":
                    data = self.stack.pop()
                    index = self.stack.pop()
                    if type(data) != str or type(index) != int:
                        print("Operand type error!")
                        break
                    try:
                        self.stack.append(data[index])
                    except IndexError:
                        print("Out of index error!")
                        break
                
                case "➖":
                    char = self.stack.pop()
                    if type(data) != str and len(data) != 1:
                        print("Operand type error!")
                        break
                    self.stack.append(len(char))

                case "🐸":
                    print("Exit!")
                    break

                case "🧠":
                    filename = self.stack.pop()
                    index = self.stack.pop()
                    if type(filename) != str:
                        print("Operand type error!")
                        break
                    
                    _path = pathlib.Path(filename)
                    
                    if _path.name in self.get_black_list():
                        print("Blacklist error!")
                        break
                    
                    options = self.get_file_options()                        
                    try:
                        result = _path.__getattribute__(options[index])(*insn.opnd)
                        if types.GeneratorType == type(result):
                            self.stack.append(list(result))
                        else:
                            self.stack.append(result)
                    except IndexError:
                        print("Out of range!")
                        break

                case "🗣️":
                    sleep_time = self.stack.pop()
                    if type(sleep_time) != int:
                        print("Operand type error!")
                        break 
                    time.sleep(sleep_time)

                case _:
                    print("Wtf?")
                    break

            self.pc += 1


    def parse_json(self, insntructions:list):
        result = []
        for insn in insntructions:
            print(insn)
            result.append(Instruction(insn["opcode"], insn["operands"]))
        return result

    
