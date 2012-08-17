import sys, os, pexpect, pxssh

class session:
    def __init__(self,ip='192.168.1.13',user='root',passwd='uestc8020'):
        self.child = pxssh.pxssh()
        self.child.timeout=2 #change this to set timeout
        self.child.maxread=2000 #useless
        self.child.searchwindows=None #useless
        self.child.login(ip,user,passwd)



        print "session established..."
        #print "info:\nIP: "+ip+"\ncurrent directory: "+

    def close(self):
        self.child.close()
        
    # 
    def cmd(self, cmd, ok='', error='', prompt=''):
        #if prompt is set by user, we save the UNIQUE_PROMPT, and 
        #use the user defined prompt for this time, set it back in
        #the end
        if prompt != '':
            save_prompt = self.child.UNIQUE_PROMPT
            self.child.UNIQUE_PROMPT = prompt
        self.child.sendline(cmd)
        sys.stdout.write(">>>> "+cyan(cmd))
        if ok != '':
            sys.stdout.write(", "+green(ok))
        if error != '':
            sys.stdout.write(", "+red(error))
        print '.'
        #this loop will end only if STATE_PROMPT is reached.
        STATE_PROMPT = 0
        STATE_TIMEOUT = 1
        STATE_OK = 2
        STATE_ERROR = 3

        length = 0 #count characters in self.child.before
        ok_times = 0
        error_times = 0
        while True:
            if ok == '' and error == '':
                index = self.child.expect([self.child.UNIQUE_PROMPT,pexpect.TIMEOUT], 2)
                if index == 0:
                    state = STATE_PROMPT
                elif index == 1:
                    state = STATE_TIMEOUT
            elif ok == '' and error != '':
                index = self.child.expect([self.child.UNIQUE_PROMPT,pexpect.TIMEOUT,error], 2)
                if index == 0:
                    state = STATE_PROMPT
                elif index == 1:
                    state = STATE_TIMEOUT
                elif index == 2:
                    state = STATE_ERROR
            elif ok != '' and error == '':
                index = self.child.expect([self.child.UNIQUE_PROMPT,pexpect.TIMEOUT,ok], 2)
                if index == 0:
                    state = STATE_PROMPT
                elif index == 1:
                    state = STATE_TIMEOUT
                elif index == 2:
                    state = STATE_OK
            elif ok != '' and error != '':
                index = self.child.expect([self.child.UNIQUE_PROMPT,pexpect.TIMEOUT,ok,error], 2)
                if index == 0:
                    state = STATE_PROMPT
                elif index == 1:
                    state = STATE_TIMEOUT
                elif index == 2:
                    state = STATE_OK
                elif index == 3:
                    state = STATE_ERROR
            if state == STATE_PROMPT:
                sys.stdout.write(cyan("PROMPT matched"))#print would has a extra blank, this has not
                if ok != '': 
                    sys.stdout.write(", "+green(ok)+" matched "+str(ok_times)+" times")
                if error != '':
                    sys.stdout.write(", "+red(error)+" matched "+str(error_times)+" times")
                print ".\n"
                break
            elif state == STATE_TIMEOUT:
                #check if something new is received
                if len(self.child.before) == length:
                    print "Haven't receive anything for 2 seconds"
                else:
                    length = len(self.child.before)
                    sys.stdout.write(". . . ")
                    sys.stdout.write(self.child.before[-20:].replace('\n','\\n').replace('\r','\\r'))
                    sys.stdout.write(" . . .\n")
            elif state == STATE_OK:
                ok_times += 1
                sys.stdout.write(green("ok:")+" . . . ")
                #you could change 20 to some other number to control num of charactres print 
                #with ok words
                sys.stdout.write(self.child.before[-20:].replace('\n','\\n').replace('\r','\\r'))
                print green(self.child.after)
            elif state == STATE_ERROR:
                error_times += 1
                print red('error:')
                sys.stdout.write(self.child.before)
                print red(self.child.after)
        if prompt != '':
            self.child.UNIQUE_PROMPT = save_prompt
   


def red(str):
    return '\033[31;49m'+str+'\033[0m'
def green(str):
    return '\033[32;49m'+str+'\033[0m'
def cyan(str):
    return '\033[36;49m'+str+'\033[0m'
