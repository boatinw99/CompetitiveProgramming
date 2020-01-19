sub = [['A','a'],['T','t'],['C','c'],['G','g']]
s=input()
S=[]
ed = 0  
for i in range(len(s)):
    tmp = s[i]
    for j in range(4):
        if s[i]==sub[j][1]:
            tmp=sub[j][0]
    if tmp!="A" and tmp!="T" and tmp!="C" and tmp!="G":
        print("ERROR")
        exit()
    S.append(tmp)
s,S=S,s 
ans = []
ans.append(s[0])
ans.append(1)
for i in range(1,len(s)):
    if s[i]==s[i-1]:
        ans[-1]+=1
    else :
        ans.append(s[i])
        ans.append(1)
L = len(ans)
i = 0 
pr = []
for i in range(L):
    if str(ans[i])!="1" :
        pr.append(str(ans[i]))
print("".join(pr))