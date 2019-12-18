from itertools import permutations 
  
def Perm(str):  
    permList = permutations(str) 
    for perm in list(permList):
    	f = ''.join(perm) 
    	if((int(f))%60 == 0):
    		print("red")
    		return
    print("cyan")
    return
     
         
n = input()
n = int(n)

for i in range (n):
	s = input()
	Perm(s)
	
