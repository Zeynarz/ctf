from Engine import VMEngine

import json
import base64
import binascii
import sys
import signal

def timeout_handler(signum, frame):
    print("time out.")
    raise SystemExit()

# very very very very very very very very very very easy code virutalization teq 
def main():
    code = input("Input code:")
    try:
        decode_data = base64.b64decode(code)
    except binascii.Error:
        print("[!] base64 decode error!")
        sys.exit(0)

    try:
        json_insns = json.loads(decode_data)
    except json.decoder.JSONDecodeError:
        print("[!] json decode error!")
        sys.exit(0)
    

    vme = VMEngine()
    vme.set_black_list(["flag"])
    vme.set_file_options(["exists"])

    instructions = vme.parse_json(json_insns)
    print("[*] Init instructions ....")
    print("[+] Execute IL!")
    print("----------------------------------")
    vme.run(instructions)
    print("----------------------------------")

if __name__ == "__main__":
    timeout_seconds = 3
    signal.signal(signal.SIGALRM, timeout_handler)
    signal.alarm(timeout_seconds)
    main()
