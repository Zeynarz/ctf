from socket import *
import json
import ctypes
import base64

lib = './simpllocator.so'
funcs = ctypes.cdll.LoadLibrary(lib)
print(funcs)

# void init()
init = funcs.init

# int allocate()
allocate = funcs.allocate
allocate.restype = ctypes.c_int # prob is return type?

# int insert(fd, ptr, sz)
insert = funcs.insert
insert.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_int8), ctypes.c_int] # prob is argument type?
insert.restype = ctypes.c_int

# int delete(fd)
delete = funcs.delete
delete.argtypes = [ctypes.c_int]
delete.restype = ctypes.c_int

# int mprotect(fd, flag)
mprotect = funcs.fd_mprotect
mprotect.argtypes = [ctypes.c_int, ctypes.c_int]
mprotect.restype = ctypes.c_int

# int execute(fd)
execute = funcs.execute
execute.argtypes = [ctypes.c_int]
execute.restype = ctypes.c_int

def parse_args(args):
    res = list()
    for arg in args:
        # in json data, have to mention type also
        type = arg['type']
        data = arg['data']
        if type == 'INT':
            data = ctypes.c_int(arg['data'])
        elif type == 'PTR':
            decoded = base64.b64decode(arg['data'])
            data = {'data' : (ctypes.c_int8 * len(decoded))(*decoded), 'len' : ctypes.c_int(len(decoded))}
        else:
            return None
        res.append(data)
    return res

init()
print("Hello! This is Simpllocator!")

while True:
    argc = 0
    args = None
    received = input()
    try:
        received = json.loads(received)
        callNum = received['callNum']
        if received['args'] is not None:
            argc = len(received['args'])
            args = received['args']
        
        if callNum == 1:
            if argc != 0:
                continue
            print(f"fd[{allocate()}] created.") # allocate is called here
        
        elif callNum == 2:
            if argc != 2 or received['args'][0]['type'] != 'INT':
                continue
            c_args = parse_args(args)
            if c_args is not None:
                if 0 <= insert(c_args[0], c_args[1]['data'],c_args[1]['len']): # !!! the 2nd arg is just a string
                    print(f"Data inserted at fd[{received['args'][0]['data']}]")

        elif callNum == 3:
            if argc != 1 or received['args'][0]['type'] != 'INT':
                continue
            c_args = parse_args(args)
            if 0 <= delete(c_args[0]):
                print(f"fd[{received['args'][0]['data']}] was deleted.")

        elif callNum == 4:
            if argc != 2 or received['args'][0]['type'] != 'INT' or received['args'][1]['type'] != 'INT':
                continue
            c_args = parse_args(args)
            if 0 <= mprotect(c_args[0], c_args[1]):
                print(f"fd[{received['args'][0]['data']}] permission changed.")
        
        elif callNum == 5:
            if argc != 1 or received['args'][0]['type'] != 'INT':
                continue
            c_args = parse_args(args)
            if 0 <= execute(c_args[0]):
                print(f"fd[{received['args'][0]['data']}] was executed.")
    except:

