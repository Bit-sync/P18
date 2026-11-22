#include <stdio.h>
#include <string.h>

struct d
{
    int id;
    char name[100];
    int ag;
    char bg[4];
    long long cnt;
    char dt[30];   
};

int c=0;
int I[10000]={0};

void reg(struct d *dx)
{   
    int t=1;
    printf("Enter your name: ");
    scanf(" %99[^\n]",dx->name);    
    while (t)
    { 
        t=0;
        printf("Enter your id: ");
        scanf("%8d",&(dx->id));
        for (int i=0; i<c; i++)
        {
            if (dx->id == I[i])
            {
                printf("This ID has been taken\n");
                t=1;
                break;
            }
        }
    }
    I[c]=dx->id;
    c++;
    printf("Enter your Blood Group: ");
    scanf("%3s",dx->bg);
    printf("Enter your contact info: ");
    scanf("%10lld",&(dx->cnt));
    printf("Enter your age: ");
    scanf("%2d",&(dx->ag));
    printf("Enter donation date (dd/mm/yyyy): ");
    scanf("%11s",dx->dt);


    // or (for I/O terminal)


    // scanf("%99s %3s %10lld %2d %29s",dx->name,dx->bg,&(dx->cnt),&(dx->ag),dx->dt);
}

int main()
{   
    int T=1;
    struct d d[10000];
    while (T)
    {   
        printf("\n\n==============================================\n(1) Register a donor\n");
        printf("(2) Print the donors list\n");
        printf("(3) Search for donors according to blood group\n");
        printf("(4) Search the donor according to ID\n");
        printf("(5) Update a donor's data by ID\n");
        printf("(6) Delete a donor by ID\n");
        printf("(7) Exit the program\n==============================================\n\n");
        int n=0;
        printf("Enter number: ");
        int r = scanf("%d", &n);
        if (r == EOF) break;                 
        scanf("%*[^\n]");                   
        scanf("%*c");     
        if (n<0 || n>7) n=0;
        if (n==0) printf("\nEnter a valid number from 1 to 7\n");

        if (n==1)
        {
            if (c>9999) { printf("List is full\n"); continue; }
            reg(&d[c]);

            for (int j=1; j<c; j++)
            {
                for (int i=0; i<c-j; i++)
                {
                    if (d[i].id>d[i+1].id)
                    {
                        struct d tt=d[i];
                        d[i]=d[i+1];
                        d[i+1]=tt;
                        int t=I[i];
                        I[i]=I[i+1];
                        I[i+1]=t;
                    }
                }
            }
        }
        if (n==2)
        {   
            printf("\n\n");
            for (int i=0; i<c; i++)
            {
                printf("%s %d %s %d %lld %s\n", d[i].name, d[i].id, d[i].bg, d[i].ag, d[i].cnt, d[i].dt);
            }
        }
        if (n==3)
        {
            char b[4];
            printf("Enter blood group: ");
            scanf("%3s", b);
            for (int i=0; i<c; i++)
            {
                if (strcmp(d[i].bg,b)==0) printf("%s %d %s %d %lld %s\n", d[i].name, d[i].id, d[i].bg, d[i].ag, d[i].cnt, d[i].dt);
            }
        }
        if (n==4)
        {
            int id;
            printf("Enter donor's ID: ");
            scanf("%d", &id);
            for (int i=0; i<c; i++)
            {
            if (id==d[i].id) printf("%s %d %s %d %lld %s\n", d[i].name, d[i].id, d[i].bg, d[i].ag, d[i].cnt, d[i].dt);
            }
        }
        if (n==5)
        {
            if (!c) printf("There exists no donor yet\n");
            else
            {
                int id,t=1;
                char s[100];
                while (t)
                {
                    printf("Enter donor's ID: ");
                    scanf("%8d%*c", &id);
                    for (int i=0; i<c; i++) if (id==d[i].id) {t--; break;}
                    if (t) printf("This ID doesnt exist\n");
                }
                while (1)
                {
                    printf("Edit donor's ");
                    fgets(s, 100, stdin);
                    if ((!strcmp(s,"name\n") || !strcmp(s,"age\n") || !strcmp(s,"id\n") || !strcmp(s,"blood group\n") || !strcmp(s,"contact\n") || !strcmp(s,"date\n"))) break;
                    else printf("That's not a valid information\n");
                }
                if (!strcmp(s,"name\n"))
                {
                    printf("Enter the updated information: ");
                    char u[100];
                    scanf(" %99[^\n]", u);
                    for (int i=0; i<c; i++)
                    {
                        if (d[i].id==id)
                        {
                            strcpy(d[i].name,u);
                            break;
                        }
                    }
                }
                if (!strcmp(s,"id\n"))
                {
                    int u,t=1;
                    while (t)
                    { 
                        t=0;
                        printf("Enter the updated information: ");
                        scanf("%8d",&u);
                        for (int i=0; i<c; i++)
                        {
                            if (u == I[i])
                            {
                                printf("This ID has been taken\n");
                                t=1;
                                break;
                            }
                        }
                    }
                    for (int i=0; i<c; i++)
                    {
                        if (d[i].id==id)
                        {
                            d[i].id=u;
                            I[i]=u;
                            break;
                        }
                    }  
                    
                    for (int j=1; j<c; j++)

                    for (int i=0; i<c-j; i++)
                    {
                        if (d[i].id>d[i+1].id)
                        {
                            struct d tt=d[i];
                            d[i]=d[i+1];
                            d[i+1]=tt;
                            int t=I[i];
                            I[i]=I[i+1];
                            I[i+1]=t;
                        }
                    }
                }
                if (!strcmp(s,"age\n"))
                {
                    printf("Enter the updated information: ");
                    int u;
                    scanf("%2d", &u);
                    for (int i=0; i<c; i++)
                    {
                        if (d[i].id==id)
                        {
                            d[i].ag=u;
                            break;
                        }
                    }
                }
                if (!strcmp(s,"blood group\n"))
                {
                    printf("Enter the updated information: ");
                    char u[4];
                    scanf("%3s", u);
                    for (int i=0; i<c; i++)
                    {
                        if (d[i].id==id)
                        {
                            strcpy(d[i].bg,u);
                            break;
                        }
                    }
                }
                if (!strcmp(s,"contact\n"))
                {
                    printf("Enter the updated information: ");
                    long long u;
                    scanf("%10lld", &u);
                    for (int i=0; i<c; i++)
                    {
                        if (d[i].id==id)
                        {
                            d[i].cnt=u;
                            break;
                        }
                    }
                }
                if (!strcmp(s,"date\n"))
                {
                    printf("Enter the updated information: ");
                    char u[100];
                    scanf("%11s", u);
                    for (int i=0; i<c; i++)
                    {
                        if (d[i].id==id)
                        {
                            strcpy(d[i].dt,u);
                            break;
                        }
                    }
                }
            }


        }
        if (n==6)
        {   
            if (!c) printf("There exists no donor yet\n");
            else
            {
                int id,x,t=1;
            while (t)
            {
                printf("Enter donor's ID: ");
                scanf("%8d", &id);
                for (int i=0; i<c; i++) if (id==d[i].id) {t--; break;}
                if (t) printf("This ID doesnt exist\n");
            }
            for (int i=0; i<c ; i++) if (d[i].id==id) {x=i; break;};
            char m[100];
            strcpy(m,d[x].name);
            for (int i=x+1; i<c; i++)
            {
                I[i-1]=I[i];
                d[i-1]=d[i];
            }
            c--;
            printf("%s has been removed as a donor\n", m);
            }
            
        }
        if (n==7) T--;
    }
}
