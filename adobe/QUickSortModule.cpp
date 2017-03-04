
#include<stdio.h>
#define SIZE 50
struct Subject{
 char subName[30];
 int marks;
};

struct Student {
   char name[30];
   int total_Marks;
   struct Subject *subject;
};


int main() {
   int i,j,students,subjects,total_Marks=0;
   struct Student st[SIZE];
   struct Subject sub[SIZE];
 //  struct subject sub[SIZE];
//   clrscr();
   /* Input the Total No of Students*/
   printf("Enter No of students--->");
   scanf("%d", &students);

   /*This Loop Stores the name of students*/
   printf("\nEnter names of students\n");
   for (i=1;i<=students;i++) {
      scanf("%s", st[i].name);
   }

   /*Input the Total No of Subjects*/
   printf("Enter the No of subjects--->");
   scanf("%d",&subjects);

   /*This Loop Stores the name of subjects*/
   printf("Enter the names of Subjects\n");
   for (i=1;i<=subjects;i++) {
      scanf("%s", sub[i].subName);
   }

   /*Stores the marks of Each subjects of Each Student*/
   for(i=1;i<=students;i++){
	printf("Enter the marks of %s\n",st[i].name);
	for(j=1;j<=subjects;j++){
		printf("%s-->",sub[j].subName);
		scanf("%d",&st[i].subject[j].marks);
		total_Marks=total_Marks+st[i].subject[j].marks;
	}
	st[i].total_Marks=total_Marks;
	total_Marks=0;
	printf("\n");
   }
   printf("Details of all the students\n");
   for (i=1;i<=students;i++) {
      printf("Detail of student %s\n",st[i].name);
      for(j = 1;j<= subjects;j++) {
        printf("%s\t",sub[j].subName);
	printf("%d\n",st[i].subject[j].marks);
      }
      printf("%d\n",st[i].total_Marks);
   }

//     getch();
}
