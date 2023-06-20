from hashlib import md5, sha1
import sys
import random
import string

def read_flag():
    f = open("/home/ctf/flag", "r")
    flag = f.read().strip()
    f.close()

    return flag

def auth_check(id_key, pw_key, user_id, user_pw, result):
    return sha1(pw_key + user_pw + md5(id_key + user_id).hexdigest().encode("utf-8")).hexdigest() == result

def show(data):
    data = "".join(map(str, data))
    sys.stdout.write(data + "\n")
    sys.stdout.flush()

def input():
    return sys.stdin.readline().strip()

def generate_random_string(length):
    characters = string.ascii_lowercase + string.digits
    random_string = "".join(random.choice(characters) for _ in range(length))
    return random_string.encode()

def main():
    show("**************************************************")
    show("|          [codegate2023 login service]          |")
    show("|                1. create id, pw                |")
    show("|                    2. login                    |")
    show("|                    3. exit                     |")
    show("|                                                |")
    show("|          create id and pw then login!          |")
    show("**************************************************")

    while True:
        num = int(input())
        if num == 1:
            USER_ID = generate_random_string(8)
            USER_PW = generate_random_string(8)
            id_key = generate_random_string(20)
            pw_key = generate_random_string(20)
            show(f"USER_ID = {USER_ID.decode()}")
            show(f"USER_PW = {USER_PW.decode()}")
            show("")
            show(f"md5(id_key) = {md5(id_key).hexdigest()}")
            show(f"sha1(pw_key) = {sha1(pw_key).hexdigest()}")
        elif num == 2:
            if USER_ID is not None and USER_PW is not None:
                show("[             login             ]")
                show("[     ex) 75736572:70617373     ]")
                user_data = input()
                user_id, user_pw = [bytes.fromhex(data) for data in user_data.split(":")]
                if USER_ID in user_id and USER_PW in user_pw:
                    # for testing purposes
                    print("md5(id_key+user_id)",md5(id_key+user_id).hexdigest())
                    print("sha1(pw_key+user_pw)",sha1(pw_key+user_pw).hexdigest())
                    print("result:")
                    result = input()
                    if auth_check(id_key, pw_key, user_id, user_pw, result):
                        flag = read_flag()
                        show(f"login sucess!!\nflag is {flag}")
                    else:
                        show("login fail..")
                        quit()
            else:
                show("not found id and pw")
                quit()
        elif num == 3:
            show("bye~")
            quit()
        else:
            show("no.. invalid number.")

if __name__ == "__main__":
    main()
