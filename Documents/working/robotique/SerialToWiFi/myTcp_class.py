import socket, select


class myTcp:

    buff_size = 256
    socket = 0
    data = ""
    
    def __init__(self, ip, port, verbose):
        try:
            self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.socket.connect((ip, port))
            self.socket.setblocking(0)
            self.isVerbose = verbose
            print("\n/***** Connexion Robot Successful. *****\\\n")
        except BaseException as err:
            print("/!\ **** Erreur Connect Robot **** /!\ \n!!! %s !!!"%err)
            self.socket = -1

    def __del__(self):
        if (self.socket != -1):
            self.socket.close()

    def isConnect(self):
        if (self.socket != -1):
            return True
        return False


    def run(self, msg):
        self.data = ""
        if (self.socket != -1):
            try:
                ready_to_read, ready_to_write, in_error = select.select([self.socket], [self.socket], [self.socket], 1)
                if self.socket in ready_to_read:
                    self.data = self.socket.recv(self.buff_size)
                elif len(msg) > 0 and self.socket in ready_to_write:
                    self.socket.send(msg)
            except BaseException as err:
                print("/!\ **** Error TCP **** /!\ \n!!! %s !!!"%err)
                return -1
        return self.data

