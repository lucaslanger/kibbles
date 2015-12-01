def f():
	x=3

def g():
	global x
	x=3
'''
x=2
print x
f()
print 'after f', x
g()
print 'after g', x
'''

class TestScope:
	class_int = 1
	class_list = [2]

	def __init__(self):
		self.instance_int = 4
		self.instance_list = [6,2]

'''
instanceA = TestScope()
instanceB = TestScope()

instanceA.class_int = 5	#int didnt change for B, but the list did change
instanceA.class_list[0] = 3
instanceA.instance_int = 7
instanceA.instance_list[0] = 8

print instanceB.class_int, instanceB.class_list
print instanceB.instance_int, instanceB.instance_list
'''

import time
key_list = [ k % 371 for k in range(0,100000) ]
# Version 1
start_time = time.time()
d = {}
for k in key_list:
        if d.has_key(k):
                d[k] = d[k] + 1
        else:
                d[k] = 1
print time.time() - start_time

#Version 2
start_time = time.time()
d = {}
for k in key_list:
        try:
                d[k] = d[k] + 1
        except KeyError:
                d[k] = 1
print time.time() - start_time
