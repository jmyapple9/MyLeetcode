s=input('')
if(len(s)%2):
    s = (s[0].upper() + s[1::])[::-1]
else:
    s = s[0:int(len(s)/2) - 1:1] + "42" + s[int(len(s)/2)+1::1]
print(s)