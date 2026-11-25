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
long long C[10000]={0};

void reg(struct d *dx)
{   
    int t=1;
    printf("Enter your name: ");
    scanf(" %99[^\n]",dx->name);    
    while (t)
    { 
        t=0;
        printf("Enter your id (8 digits): ");
        dx->id=0;
        scanf("%d",&(dx->id));
        scanf("%*[^\n]");
        scanf("%*c");
        if (dx->id<10000000 || dx->id>99999999)
            {
                printf("ID must be 8 digits long\n");
                t=1;
            }
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
    t=1;
    while (t)
    {
        t=0;
        printf("Enter your Blood Group: ");
        scanf("%3s",dx->bg);
        scanf("%*[^\n]");
        scanf("%*c");
        if (!(!strcmp(dx->bg,"A+") || !strcmp(dx->bg,"A-") || !strcmp(dx->bg,"AB+") || !strcmp(dx->bg,"AB-") || !strcmp(dx->bg,"B+") || !strcmp(dx->bg,"B-") || !strcmp(dx->bg,"O-") || !strcmp(dx->bg,"O+")))
        {
            t=1;
            printf("Thats not a valid blood group\n");
        }
    }
    t=1;
        while (t)
    { 
        t=0;
        printf("Enter your contact info (10 digits): ");
        dx->cnt;
        scanf("%lld",&(dx->cnt));
        scanf("%*[^\n]");
        scanf("%*c");
        if (dx->cnt<1000000000 || dx->cnt>9999999999)
            {
                printf("Contact number must be 10 digits long\n");
                t=1;
            }
        for (int i=0; i<c; i++)
        {
            if (dx->cnt == C[i])
            {
                printf("This contact number already exists\n");
                t=1;
                break;
            }
        }
    }
    C[c]=dx->cnt;
    c++;
    printf("Enter your age: ");
    scanf("%3d",&(dx->ag));
    scanf("%*[^\n]");
    scanf("%*c");
    printf("Enter donation date (dd/mm/yyyy): ");
    scanf("%11s",dx->dt);
    scanf("%*[^\n]");
    scanf("%*c");

    printf("%s successfully registered as a donor\n", dx->name);
}

int main()
{   
    int T=1;
    struct d d[10000];
    while (T)
    {   
        printf("\n\n===============================================|\n(1) Register a donor                           |\n(2) Print the donors list                      |\n(3) Search for donors according to blood group |\n(4) Search the donor according to ID           |\n(5) Update a donor's data by ID                |\n(6) Delete a donor by ID                       |\n(7) Exit the program                           |\n===============================================|\n\n");
        int n=0;
        printf("Enter number: ");
        int r = scanf("%d", &n);
        if (r == EOF) break;                 
        scanf("%*[^\n]");                   
        scanf("%*c");     
        if (n<0 || n>7) n=0;
        if (n==0) printf("\n\n\nEnter a valid number from 1 to 7\n");

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
                        long long tc=C[i];
                        C[i]=C[i+1];
                        C[i+1]=tc;
                    }
                }
            }
            
        }
        if (n==2)
        {   
            printf("\n\n");
            printf("Name           ID        Blood group  Age  Contact number  Date\n");
            for (int i=0; i<c; i++)
            {
                printf("%-14s %d  %-11s  %-3d  %-14lld  %s\n", d[i].name, d[i].id, d[i].bg, d[i].ag, d[i].cnt, d[i].dt);
            }
        }
        if (n==3)
        {
            char u[4];
            int t=1;
            while (t)
            {
                t=0;
                printf("Enter your Blood Group: ");
                scanf("%3s",u);
                scanf("%*[^\n]");
                scanf("%*c");
                if (!(!strcmp(u,"A+") || !strcmp(u,"A-") || !strcmp(u,"AB+") || !strcmp(u,"AB-") || !strcmp(u,"B+") || !strcmp(u,"B-") || !strcmp(u,"O-") || !strcmp(u,"O+")))
                {
                    t=1;
                    printf("Thats not a valid blood group\n");
                }
            }
            for (int i=0; i<c; i++)
            {
                if (strcmp(d[i].bg,u)==0) printf("\n\n%s %d %s %d %lld %s\n", d[i].name, d[i].id, d[i].bg, d[i].ag, d[i].cnt, d[i].dt);
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
                int id=0,t=1;
                char s[100];
                while (t)
                {
                    printf("Enter donor's ID: ");
                    r=scanf("%d", &id);
                    scanf("%*[^\n]");
                    scanf("%*c");
                    for (int i=0; i<c; i++) if (id==d[i].id) {t--; break;}
                    if (t) printf("This ID doesnt exist\n");
                }
                while (1)
                {   
                    printf("Options: name, age, id, blood group, contact\n");
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
                        r=scanf("%d",&u);
                        scanf("%*[^\n]");
                        scanf("%*c");
                        if (r!=1)
                        {   
                            u=0;
                        } 
                        if (u<10000000 || u>99999999)
                        {
                            printf("ID must be 8 digits long\n");
                            t=1;
                        }
                        for (int i=0; i<c; i++)
                        {
                    
                            if (u == I[i] && u!=id)
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
                            long long tc=C[i];
                            C[i]=C[i+1];
                            C[i+1]=tc;
                        }
                    }
                }
                if (!strcmp(s,"age\n"))
                {
                    printf("Enter the updated information: ");
                    int u;
                    scanf("%3d", &u);
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
                    char u[4];
                    int t=1;
                    while (t)
                    {
                        t=0;
                        printf("Enter the updated information: ");
                        scanf("%3s",u);
                        scanf("%*[^\n]");
                        scanf("%*c");
                        if (!(!strcmp(u,"A+") || !strcmp(u,"A-") || !strcmp(u,"AB+") || !strcmp(u,"AB-") || !strcmp(u,"B+") || !strcmp(u,"B-") || !strcmp(u,"O-") || !strcmp(u,"O+")))
                        {
                            t=1;
                            printf("Thats not a valid blood group\n");
                        }
                    }
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
                    long long u;
                    t=1;
                    while (t)
                    { 
                        t=0;
                        printf("Enter the updated information: ");
                        scanf("%lld",&u);
                        if (u<1000000000 || u>9999999999)
                            {
                                printf("Contact number must be 10 digits long\n");
                                t=1;
                            }
                        for (int i=0; i<c; i++)
                        {
                            if (u == C[i])
                            {
                                printf("This contact number already exists\n");
                                t=1;
                                break;
                            }
                        }
                    }
                    for (int i=0; i<c; i++)
                    {
                        if (d[i].id==id)
                        {
                            d[i].cnt=u;
                            C[i]=u;
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
                int id=0,x,t=1;
            while (t)
            {
                printf("Enter donor's ID: ");
                r=scanf("%d", &id);
                scanf("%*[^\n]");
                scanf("%*c");
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
                C[i-1]=C[i];
            }
            c--;
            printf("%s has been removed as a donor\n", m);
            }
        }

        if (n==7) T--;
    }
    
}
