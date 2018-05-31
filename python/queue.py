#!/usr/bin/python


queue = []

def enQ():
    queue.append(raw_input('Enter new queue element: '))

def deQ(flag):
    if len(queue) == 0:
        print 'Cannot dequeue from empty queue!'
    else:
	if flag == 'h':
        	print 'Removed from head [', queue.pop(0), ']'
	else :
		print 'Removed from tail [', queue.pop(), ']'



def viewQ():
    print str(queue)



def showmenu():
    prompt = """
(E)nqueue
(D)equeue
(V)iew
(Q)uit

Enter choice: """

    done = 0
    while not done:

        chosen = 0
        while not chosen:
            try:
		input_content=raw_input(prompt)
                choice = input_content[0]
            except (IndexError, EOFError, KeyboardInterrupt):
                choice = 'q'
            print '\nYou picked: [%s]' % choice
            if choice not in 'devqDEVQ':
                print 'invalid option, try again'
            else:
                chosen = 1

        if choice == 'q' or choice == 'Q': done = 1
        if choice == 'e' or choice == 'E': enQ()
        if choice == 'd' or choice == 'D':
		option = 't' #default value
		if len(input_content) == 2: 
			option = input_content[1]
		deQ(option)
        if choice == 'v' or choice == 'V': viewQ()




if __name__ == '__main__':
	showmenu()
