def EC_algo(a,b):
	while(b):
		a%=b
		a,b = b,a
	return a
for k in range(-50,50):
	print(-8*k*128 + 19*k*54)
""" 
a longer than b
1. 2b<a
aaaaaaa
bbb
a%b < b
len(a%b) < ken(b)

old length m = len(a) + len(b)
new lehgth = len(b) + len(a%b) < 2 len(b) < 0.5 (len(a)+len(b)) reduce more than half

2. 2b>a
aaaa aaa
bbbb
a%b < b
len(a%b) < ken(b)
old length m = len(a) + len(b)
new lehgth = len(b) + len(a%b) < 2 len(b) reduce more than half

3. 2b=a
a%b = 0
old length m = len(a) + len(b)
new lehgth = len(b) + len(a%b) = len(b) reduce more than half

"""