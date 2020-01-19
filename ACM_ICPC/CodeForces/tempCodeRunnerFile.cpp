
    for(int i=1;i<N;i++)
    {
        fact[i]=1ll*fact[i-1]*i %mod ;
    }
    for(int i=0;i<N;i++)
    {
        inv[i]=pow2(fact[i],mod-2);
    }
}
bool Is_lucky(int x)
{
    int tmp = x ; 
    while(x)
    {
        if((x%10!=4)&&(x%10!=7))return 0 ;
        x/=10 ; 