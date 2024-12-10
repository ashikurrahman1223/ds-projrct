#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<string.h>


typedef struct Hospital
{
    char name[100];
    int age;
    char address[20];
    char phone[20];
    char bloodgroup[50];
    int disease_no;
    int reg_no;
    char ad_date[20];
    char re_date[20];
    int payment;
    struct Hospital *next; //created a pointer for pointing to the next element
} hospital;



void add_patient(hospital *list)
{
    system("cls");
    hospital *newnode,*temp;
    char name[100];
    char address[20];
    char phone[20];
    char bloodgroup[50];
    char date[20];
    char re_date[20];
    printf("\n\t\t\t\t      |-----------------------------|\n");
    printf("\t\t\t\t      |      Add Patient Details    |\n");
    printf("\t\t\t\t      |-----------------------------|\n");
    newnode=(hospital*)malloc(sizeof(hospital));
    printf("Enter registration number:");
    scanf("%d",&newnode->reg_no);
    printf("Enter patient name:");
    scanf("%s",name);
    strcpy(newnode->name,name);

    printf("Enter patient age:");
    scanf("%d",&newnode->age);

    fflush(stdin);
    printf("Enter patient address:");
    scanf("%s",address);
    strcpy(newnode->address,address);

    fflush(stdin);
    printf("Enter patient phone number:");
    scanf("%s",phone);
    strcpy(newnode->phone,phone);

    fflush(stdin);
    printf("Enter appoinment date:");
    scanf("%s",&date);
    strcpy(newnode->ad_date,date);

    fflush(stdin);
    printf("Enter release date:");
    scanf("%s",&re_date);
    strcpy(newnode->re_date,re_date);

    printf("Enter patient bloodgroup:");
    scanf("%s",bloodgroup);
    strcpy(newnode->bloodgroup,bloodgroup);
    printf("\n");
    printf("----------------------------------");
    disease();
    printf("----------------------------------");
    printf("\nSelect disease from above table ==>>");
    printf("\nEnter disease number:");
    scanf("%d",&newnode->disease_no);
    printf("Enter payment :");
    scanf("%d",&newnode->payment);
    newnode->next=NULL;
    while(list->next!=NULL)
        list=list->next;

    list->next=newnode;
    printf("\n\tPatient details is added\n");
    printf("\n\n\nPress any key to continue....");
    fflush(stdin);
    getchar();

}

void disease()
{
    printf("\n1-> Mononucleosis                |\n");
    printf("2-> Conjunctivitis (pink eye)    |\n");
    printf("3-> Cancer                       |\n");
    printf("4-> Chest pain                   |\n");
    printf("5-> Fracture                     |\n");
    printf("6-> Diabetes checkup             |\n");
    printf("7-> Viral infection              |\n");
    printf("8-> Common cold                  |\n");
    printf("9-> Dengue                       |\n");
}

void display_patient(hospital *list)
{
    system("cls");
    printf("\t\t\t\t      |---------------------|\n");
    printf("\t\t\t\t      |    Patients list    |\n");
    printf("\t\t\t\t      |---------------------|\n");
    printf("\nReg.no\t   Name   \tAge\tAddress\t\tPhone\t\tBlood\tDisease Number\t   Admit date\n");
    printf("------\t   ----   \t---\t-------\t\t-----\t\t-----\t--------------\t   ----------\n");

    while (list!=NULL)
    {
        printf("%d\t   %s   \t%d\t%s\t\t%s\t%s\t   %d\t\t   %s\n",list->reg_no,list->name,list->age,list->address,list->phone,list->bloodgroup,list->disease_no,list->ad_date);
        list=list->next;
    }
    printf("\n\n\nPress any key to continue....");
    fflush(stdin);
    getch();
}

void search_patient(hospital *list)
{
    system("cls");
    int reg;
    printf("\n\nEnter a patient Reg Number:");
    scanf("%d",&reg);
    hospital *temp;
    temp=list;
    while(temp!=NULL)
    {
        if(temp->reg_no==reg)
        {
            printf("\n\nName\t\tAge\t\tAddress\t\t\tPhone\t\t\tBlood\t\tDisease Number\n");
            printf("----\t\t---\t\t-------\t\t\t-----\t\t\t-----\t\t--------------\n");
            printf("%s\t\t%d\t\t%s\t\t\t%s\t\t%s\t\t%d \n",temp->name,temp->age,temp->address,temp->phone,temp->bloodgroup,temp->disease_no);
        }
        temp=temp->next;
    }
    printf("\n\n\nPress any key to continue....");
    fflush(stdin);
    getchar();
}

void hospital_doctors()
{
    system("cls");
    printf("\n\n\t\t\t\t\t===================");
    printf("\n\t\t\t\t\t||  DOCTORS INFO ||");
    printf("\n\t\t\t\t\t===================");
    printf("\n\n\t\t\t>> Dr.H A M Nazmul Ahsan. (medicine specialist)");
    printf("\n\n\t\t\t>> Dr.Sheikh Nesaruddin Ahmed. (surgery)");
    printf("\n\n\t\t\t>> Dr.Mir Mahfuzul Haque Chowdhury. (Internal Medicine)");
    printf("\n\n\t\t\t>> Prof. Dr.Nazlima Nargis. (gynecologist)");
    printf("\n\n\t\t\t>> Prof. Dr. Ashok kumar Dutta. (cardiology)");
    printf("\n\n\t\t\t>> Dr. Aroop Mukherjee. (Orthopedics) ");
    printf("\n\n\t\t\t>> Dr.kamruzzaman. (Medicine specialist)");
    printf("\n\n\t\t\t>> Dr.AKM Fazlul Haque. (Colorectal Surgery)");
    printf("\n\n\tPress any key to continue....");
    getch();
}

void UpdatePatient(hospital *list)
{
    system("cls");
    int Reg;
    printf("\n\nEnter registration number:");
    scanf("%d",&Reg);
    printf("\n\t\t\t\t      |---------------------|\n");
    printf("\t\t\t\t      |   Patient Details   |\n");
    printf("\t\t\t\t      |---------------------|\n");
    printf("\nReg.no\t Name\t\tAge\t\tAddress\t\tPhone\t\tBlood\t\tDisease Number\n");
    printf("------\t ----\t\t---\t\t-------\t\t-----\t\t-----\t\t--------------\n");
    char re_date[20];
    hospital *t=list;
    while(t->reg_no != Reg)
    {
        t=t->next;
    }

    printf("%d\t %s\t\t%d\t\t%s\t%s\t%s\t\t%d \n",t->reg_no,t->name,t->age,t->address,t->phone,t->bloodgroup,t->disease_no);
    printf("\n\n\t\t\t\tUpdate Patient Info..");
    printf("\n\n\t\t\t\tEnter release date:");
    scanf("%s",re_date);
    strcpy(t->re_date,re_date);
    printf("\t\t\t\tPayment amount:");
    scanf("%d",&t->payment);
    printf("\n\t\t\t\tdone....");
    fflush(stdin);
    getchar();
}
void ReleasePatient(hospital *list)
{
    system("cls");
    printf("\n\n\t\t\t      |------------------------|\n");
    printf("\t\t\t      |    Released Patients   |\n");
    printf("\t\t\t      |------------------------|\n");
    printf("\n\nadmit\t\tName\t\trelease\t\tpayment");
    printf("\t\t\t\n-----\t\t----\t\t-------\t\t-------");
    hospital *temp;
    temp=list;
    while (temp!=NULL)
    {
        if(temp->payment!=0)
        {
            printf("\n%s\t%s\t\t%s\t%d\n",temp->ad_date,temp->name,temp->re_date,temp->payment);
        }
        temp=temp->next;
    }
    printf("\n\n\nPress any key to continue....");
    fflush(stdin);
    getchar();
}


void RecentPatient(hospital *list)
{
    system("cls");
    printf("\t\t\t\t      |------------------------|\n");
    printf("\t\t\t\t      |     Admitted Patients  |\n");
    printf("\t\t\t\t      |------------------------|\n");
    printf("\nId\tName\t\tAge\t\tAddress\t\tPhone\t\tBlood\t\tDisease Number\t   Admit date\n");
    printf("--\t----\t\t---\t\t-------\t\t-----\t\t-----\t\t--------------\t   ----------\n");
    hospital *temp1;
    temp1=list;
    while (temp1!=NULL)
    {
        if(temp1->payment==0)
        {
            printf("%d\t%s\t\t%d\t\t%s\t\t%s\t%s\t\t%d\t\t   %s\n",temp1->reg_no,temp1->name,temp1->age,temp1->address,temp1->phone,temp1->bloodgroup,temp1->disease_no,temp1->ad_date);
            //printf("\n%s\t%s\t\t%s\t%d\n",temp1->ad_date,temp1->name,temp1->re_date,temp1->payment);
        }
        temp1=temp1->next;
    }
    printf("\n\n\nPress any key to continue....");
    fflush(stdin);
    getchar();
}
void ReadData(hospital *list)
{
    system("cls");
    FILE *fp;
    fp=fopen("hospitalfile.txt","rb");
    hospital p;
    hospital *temp;

    if(fp==NULL)
    {
        printf("Failed to open file...");
        return;
    }
    while(list->next!=NULL)
        list=list->next;
    while(fread(&p,sizeof(p),1,fp))
    {
        temp=(hospital*)malloc(sizeof(hospital));
        temp->next=NULL;
        strcpy(temp->name,p.name);
        temp->age=p.age;
        strcpy(temp->address,p.address);
        strcpy(temp->bloodgroup,p.bloodgroup);
        strcpy(temp->phone,p.phone);
        temp->reg_no=p.reg_no;
        temp->disease_no=p.disease_no;
        strcpy(temp->ad_date,p.ad_date);
        strcpy(temp->re_date,p.re_date);
        temp->payment=p.payment;
        list->next=temp;
        list=list->next;
    }
    fclose(fp);
    //printf("\n\n\t\tRead successfully....");
    //printf("\n\n\t\tPress any key to continue....");
    //fflush(stdin);
    //getch();
}

void Save_File(hospital *list)
{
    system("cls");
    FILE *fp;
    fp=fopen("hospitalfile.txt","wb");
    hospital p;
    if(fp==NULL)
    {
        printf("File not found...");
    }
    while(list!=NULL)
    {
        strcpy(p.name,list->name);
        p.age=list->age;
        strcpy(p.address,list->address);
        strcpy(p.bloodgroup,list->bloodgroup);
        strcpy(p.phone,list->phone);
        p.reg_no=list->reg_no;
        strcpy(p.ad_date,list->ad_date);
        p.disease_no=list->disease_no;
        strcpy(p.re_date,list->re_date);
        p.payment=list->payment;
        fwrite(&p,sizeof(p),1,fp);
        list=list->next;
    }
    //printf("\n\n\t\tData saved to file...");
    //printf("\n\n\t\tPress any key to continue....");
    fclose(fp);
    // fflush(stdin);
    // getchar();
}
int admin()
{
    system("COLOR E");
    int ch;
    system("cls");
    printf("\n\n\t\t\t\t==================================");
    printf("\n\t\t\t\t||  HOSPITAL MANAGEMENT SYSTEM  ||");
    printf("\n\t\t\t\t==================================");
    printf("\n\n\t\t\t\t   1. To insert new patient.\n");
    printf("\n\t\t\t\t   2. Search a patient.\n");
    printf("\n\t\t\t\t   3. Update patients info\n");
    printf("\n\t\t\t\t   4. Display all appointments.\n");
    printf("\n\t\t\t\t   5. Admitted patients\n");
    printf("\n\t\t\t\t   6. Released patients\n");
    printf("\n\t\t\t\t   7. Doctors Info.\n");
    printf("\n\t\t\t\t   0. Exit the PROGRAM.\n");
    printf("\n\n\t     ENTER YOUR CHOICE:");
    scanf("%d",&ch);
    return ch;
}

int homepage(){
    int n;
    system("COLOR E");
    system("cls");
    printf("\n\n\t\t\t\t==================================");
    printf("\n\t\t\t\t||  HOSPITAL MANAGEMENT SYSTEM  ||");
    printf("\n\t\t\t\t==================================");
    printf("\n\n\t\t\t\t   1. Admin Panel\n");
    printf("\n\t\t\t\t   2. User Area\n");
    printf("\n\t\t\t\t   3. Developers\n");
    printf("\n\t\t\t\t   0. Exit\n");
    printf("\n\n\t     ENTER YOUR CHOICE:");
    scanf("%d",&n);
    return n;
}

int user(){
    int ch;
    system("COLOR E");
    system("cls");
    printf("\n\n\t\t\t\t==================================");
    printf("\n\t\t\t\t||  HOSPITAL MANAGEMENT SYSTEM  ||");
    printf("\n\t\t\t\t==================================");
    printf("\n\t\t\t\t   1. Search a patient\n");
    printf("\n\t\t\t\t   2. Doctors Info\n");
    printf("\n\t\t\t\t   3. Hospital Info\n");
    printf("\n\t\t\t\t   0. Exit the PROGRAM");
    printf("\n\n\t     ENTER YOUR CHOICE:");
    scanf("%d",&ch);
    return ch;
}

void info(){
    system("COLOR E");
    system("cls");
    printf("\n\n\t\t\t\t==================================");
    printf("\n\t\t\t\t||    DIU MEDICAL CENTER        ||");
    printf("\n\t\t\t\t==================================");
    printf("\n\n\t\t\t\t\tDiseases to be cured....\n");
    printf("\n\n\t\t\t\t==================================");
    printf("\n\t\t\t\t| 1-> Mononucleosis                |\n");
    printf("\n\t\t\t\t| 2-> Conjunctivitis (pink eye)    |\n");
    printf("\n\t\t\t\t| 3-> Cancer                       |\n");
    printf("\n\t\t\t\t| 4-> Chest pain                   |\n");
    printf("\n\t\t\t\t| 5-> Fracture                     |\n");
    printf("\n\t\t\t\t| 6-> Diabetes checkup             |\n");
    printf("\n\t\t\t\t| 7-> Viral infection              |\n");
    printf("\n\t\t\t\t| 8-> Common cold                  |\n");
    printf("\n\t\t\t\t| 9-> Dengue                       |\n");
    printf("\t\t\t\t==================================\n");
    printf("\n\t\t\t\tDaffodil Smart City\n\t\t\t\tBirulia, Savar, Dhaka");
    printf("\n\t\t\t\tTime  : 24/7 hours.");
    printf("\n\t\t\t\tOffday: N/A");
    printf("\n\n\t\t\t\tPress Enter to continue...");
    fflush(stdin);
    getchar();

}

void developers(){
    system("COLOR E");
    system("cls");
    printf("\n\n\t\t\t\t==================================");
    printf("\n\t\t\t\t||  HOSPITAL MANAGEMENT SYSTEM  ||");
    printf("\n\t\t\t\t==================================");
    printf("\n\t\tNo\t\tName\t\tID\t");
    printf("\n\t\t==\t\t====\t\t==\t");
    printf("\n\t\t1.\t\tFaisal Ahmed\t241-15-464");
    printf("\n\t\t2.\t\tSakib Shahriar\t241-15-461");
    printf("\n\t\t3.\t\tAshikur Rahman\t241-15-723");
    printf("\n\n\t\t\t\tPress Enter to continue...");
    fflush(stdin);
    getchar();

}



int main_menu(){
    int ch,n;
    hospital *list;
    list=(hospital *)malloc(sizeof(hospital));
    list->next=NULL;
    list->reg_no=0;
    int i=1;
    if(i==1)
    {
        ReadData(list);
        i--;
    }
    while(1){
        n=homepage();
        switch(n)
        {
        case 1:
            printf("\n\n\tEnter password: ");
            int x;
            scanf("%d",&x);
            for(int j=0; ;j++){
                if(x==12345){break;}
                else{
                    printf("\n\n\tWrong password....\n\tPlease try again....");
                    printf("\n\n\tEnter password: ");
                    scanf("%d",&x);
                }
            }while(1)
            {
                ch=admin();
                switch(ch)
                {
                case 1:
                    add_patient(list);
                    break;
                case 2:
                    search_patient(list->next);
                    break;
                case 3:
                    UpdatePatient(list->next);
                    break;
                case 4:
                    display_patient(list->next);
                    break;
                case 5:
                     RecentPatient(list->next);
                    break;
                case 6:
                    ReleasePatient(list->next);
                    break;
                case 7:
                    hospital_doctors();
                    break;
                case 0:
                    Save_File(list->next);
                    exit(0);
                    break;
                default :
                    printf("\n\t\t\t\tWrong choice..\n");
                    fflush(stdin);
                    getchar();
                }
            }break;
        case 2:
            ch=user();
            switch(ch)
            {
            case 1:
                search_patient(list->next);
                break;
            case 2:
                hospital_doctors();
                break;
            case 3:
                info();
                break;

            default :
                printf("\n\t\t\t\tWrong choice..\n\t\t\t\tPress any key to continue...");
                fflush(stdin);
                getchar();
            }break;
        case 3:
            developers();
            break;
        case 0:

            exit(0);
            break;
        default :
            printf("\n\t\t\t\tWrong choice..\n\t\t\t\tPress any key to continue...");
            fflush(stdin);
            getchar();
        }
    }
}

int main(){
    main_menu();
    return 0;
}. In this code how the all function work and how work write it serialy in bangla
