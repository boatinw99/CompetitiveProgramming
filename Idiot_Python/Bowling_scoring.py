rd = 1 
ed = 5 
S = input().split(",")
s = []
ro = []
ans = 0 
for e in S :
    s.append(int(e))

cnt = 0 
i = 0 
while (i<len(s)) :
    if rd > ed :
        print("ERROR")
        exit()
    ro.append(rd)
    sc = s[i] 
    ans+=sc
    spare = 0 #bool 
    strike = 0 # bool 
    if sc > 10 or sc < 0 :
        print("ERROR")
        exit()
    if i==0 :
        if sc == 10:
            strike+=1
            rd+=1
    elif ro[i-1]==ro[i] and s[i-1]+s[i]==10:
        spare=1
        rd+=1
    elif ro[i-1]==ro[i] and s[i-1]+s[i]>10 :
        print("ERROR")
        exit()
    elif ro[i-1]==ro[i]:
        rd+=1
    elif sc==10 :
        strike+=1
        rd+=1
    if rd>5 :
        if strike == 1:
            cnt = 2 
            i+=1
            break 
        elif spare == 1 :
            cnt =1 
            i+=1
            break 
        pass
    elif rd>5 :
        pass 
    elif spare==1 :
        ans+=s[i+1]
    elif strike == 1:
        ans+=s[i+1]+s[i+2]
    i+=1
extmp = 0
while cnt>0 and i<len(s):
    extmp+=s[i]
    ans+=s[i]
    if cnt==2 and s[i]==10 :
        extmp=0
    i+=1
    cnt-=1
    if extmp >10 :
        print("ERROR")
        exit()
if i != len(s) or cnt!=0 :
    print("ERROR")
    exit() 
print(ans)
