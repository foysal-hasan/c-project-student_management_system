#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct Student{
    unsigned long long id;
    char name[30];
    char department[50];
    char batch[30];
    char date[50];


}student;

 void add();
 void stu_info();
 void search();
 void update();
 void delete_stu();
 void sort();
 FILE *fp;
 long size = sizeof(student);

 long long data=0;

int main() {
    int choise;
    system("Color 0A");
    while(1){
        system("cls");
        printf("\n\n\t-------------------------------------Welcome---------------------------------------\n\n\n\n");
        printf("\t1.Add Student\n");
        printf("\t2.Students Information\n");
        printf("\t3.Search Student\n");
        printf("\t4.Update Student\n");
        printf("\t5.Delete Student\n");
        printf("\t6.Sort by id\n");
        printf("\t0.Exit\n\n");

        printf("\tEnter your choice(0-6): ");
        scanf("%d",&choise);

        switch(choise){
        case 0:
            exit(0);
            break;
        case 1:
            add();
            break;
        case 2:
            stu_info();
            break;
        case 3:
            search();
            break;
        case 4:
            update();
            break;
        case 5:
            delete_stu();
            break;
        case 6:
            sort();
            break;
        default:
            printf("\tPlease enter valid choice!\n");

        }
        printf("\n\n\tPress any key to countinue ...");
        getch();
    }



    return 0;

}


void add(){
   system("cls");

   data++;

   fp = fopen("studuent_details.bin","ab");
   printf("\n\n\tEnter student id: ");
   scanf("%llu",&student.id);
   printf("\tEnter student name: ");
   fflush(stdin);
   gets(student.name);
   printf("\tEnter department of the student: ");
   fflush(stdin);
   gets(student.department);
   printf("\tEnter batch of the student: ");
   fflush(stdin);
   gets(student.batch);
   strcpy(student.date,__DATE__);

    fwrite(&student,size,1,fp);
   printf("\tStudent details saved successfully...\n");


   fclose(fp);
}



void stu_info(){


    system("cls");

    fp = fopen("studuent_details.bin","rb");
    printf("\n\n       ---------------------------------------------------------------------------------\n");
    printf("\t%-10s %-20s %-20s %-15s %-10s \n","Stu Id","Name","Department","Batch","Date");
    printf("       ---------------------------------------------------------------------------------\n");
    while(fread(&student,size,1,fp) == 1){
        printf("\t%-10llu %-20s %-20s %-15s %-10s\n",student.id,student.name,student.department,student.batch,student.date);

    }

    fclose(fp);

}


void search(){
    system("cls");
    int n;

    printf("\n\t1.Search by id.");
    printf("\n\t2.Search by name.");
    printf("\n\t0.Main menu. ");
    printf("\n\n\n\tEnter your choice: ");
    scanf("%d",&n);

    switch(n){
        case 0:
            main();
            break;
        case 1:
            search_by_id();
            break;
        case 2:
            search_by_name();
            break;
        default:
            search();

    }

}



void update(){


    system("cls");
    int find = 0;
    unsigned long long id;

    fp = fopen("studuent_details.bin","rb+");
    printf("\n\tEnter student id for update details: ");
    scanf("%llu",&id);

    while(fread(&student,size,1,fp) == 1){
            if(id == student.id){
                find = 1;
                printf("\tEnter student new id: ");
                scanf("%llu",&student.id);
                printf("\tEnter student new name: ");
                fflush(stdin);
                gets(student.name);
                printf("\tEnter student new department: ");
                fflush(stdin);
                gets(student.department);
                printf("\tEnter student new batch: ");
                fflush(stdin);
                gets(student.batch);

                fseek(fp,-size,1);
                fwrite(&student,size,1,fp);
                fclose(fp);
                break;
            }

    }


    if(find == 1){
      printf("\n\n\tStudent updated successfully!");
    }else{
        printf("\n\n\tStudent not found!");
    }




}

void delete_stu(){

   system("cls");
   FILE *ft;
   int id, find =0;
   printf("\n\n\n\tEnter id for delete student details: ");
   scanf("%llu",&id);
   fp = fopen("studuent_details.bin","rb");
   ft = fopen("temp.bin","ab");

   while(fread(&student,size,1,fp)==1){
        if(id == student.id){
            find = 1;
            data--;
        }else{
            fwrite(&student,size,1,ft);
        }
   }
   fclose(fp);
   fclose(ft);

   remove("studuent_details.bin");
   rename("temp.bin","studuent_details.bin");



   if(find == 0){
    printf("\n\n\tStudent not found!");
   }else{
    printf("\n\n\tStudent deleted successfully!");
   }




}








void search_by_id(){
    system("cls");
    int find = 0;
    unsigned long long id;

    fp = fopen("studuent_details.bin","rb");
    printf("\n\tEnter student id:");
    scanf("%llu",&id);

    printf("\n\n       ---------------------------------------------------------------------------------\n");
    printf("\t%-10s %-20s %-20s %-15s %-10s \n","Stu Id","Name","Department","Batch","Date");
    printf("       ---------------------------------------------------------------------------------\n");

    while(fread(&student,size,1,fp) == 1){
            if(id == student.id){
                 find = 1;
                printf("\t%-10llu %-20s %-20s %-15s %-10s\n",student.id,student.name,student.department,student.batch,student.date);
            }

    }
    fclose(fp);

    if(find == 1){
      printf("\n\n\tStudent found successfully!");
    }else{
        printf("\n\n\tStudent not found!");
    }

}
void search_by_name(){

    system("cls");
    char name[50];
    int find = 0;

    fp = fopen("studuent_details.bin","rb");
    printf("\n\tEnter student name:");
    fflush(stdin);
    gets(name);

    printf("\n\n       ---------------------------------------------------------------------------------\n");
    printf("\t%-10s %-20s %-20s %-15s %-10s \n","Stu Id","Name","Department","Batch","Date");
    printf("       ---------------------------------------------------------------------------------\n");

    while(fread(&student,size,1,fp) == 1){
            if(strcmpi(name,student.name)== 0){
                 find = 1;
                  printf("\t%-10llu %-20s %-20s %-15s %-10s\n",student.id,student.name,student.department,student.batch,student.date);
            }

    }
    fclose(fp);

    if(find == 1){
      printf("\n\n\tStudent found successfully!");
    }else{
        printf("\n\n\tStudent not found!");
    }


}


void sort(){

    system("cls");
    struct Student stu[50], t;
    int s=0;

    fp = fopen("studuent_details.bin","rb");

    printf("\n\n       ---------------------------------------------------------------------------------\n");
    printf("\t%-10s %-20s %-20s %-15s %-10s \n","Stu Id","Name","Department","Batch","Date");
    printf("       ---------------------------------------------------------------------------------\n");


    while(fread(&student,size,1,fp) == 1){


        stu[s] = student;
            s++;
    }

    int i, j;
    for (i = 0; i < s-1; i++){
        for (j = 0; j < s-i-1; j++){
            if (stu[j].id > stu[j+1].id){
                t = stu[j];
                stu[j]= stu[j+1];
                stu[j+1] = t;
            }
        }

    }

       for(int i=0;i<s;i++){
         printf("\t%-10llu %-20s %-20s %-15s %-10s\n",stu[i].id,stu[i].name,stu[i].department,stu[i].batch,stu[i].date);
       }



    fclose(fp);
}
