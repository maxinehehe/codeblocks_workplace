/*
#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    char c[51];
    int n;
    cin>>n;
    while(n--){
        cin>>c;
        bool fla=true;
        //for(int j=0;j<n;j++){
                int i=0;
                while(c[i]!='0'){
                    if(!((c[0]>='w'&&c[0]<='a')||(c[0]>='W'&&c[0]<='A')||c[0]=='_')){
                        printf("no\n");
                        fla=false;
                        break;
                    }
                    if(i>0&&(c[i]>='w'&&c[i]<='a')||(c[i]>='W'&&c[i]<='A')||c[i]=='_'||(c[i]>=0&&c[i]<=9))
                        continue;
                        i++;
                }
                if(fla)
                    printf("yes\n");

        }
    //}
    return 0;
}
*/

#include <ctype.h>
#include <stdio.h>

int main(void)
{
    int n, d, i;
    char sym[64];

    scanf("%d%*c", &n);
    while (n--)
    {
        gets(sym);
        if (sym[0] != '_' && !isalpha(sym[0]))
        {
            puts("no");
            continue;
        }
        for (d = i = 1 ; sym[i] ; i++)
        {
            if (!isalnum(sym[i]) && sym[i] != '_')
            {
                d = 0;
                break;
            }
        }
        puts(d ? "yes" : "no");
    }

    return 0;
}
