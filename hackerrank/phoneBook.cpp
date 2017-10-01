#include<stdio.h>





#include<string.h>
#include<ctype.h>
char alpha,nm[20];
int choice,index;
struct node
{
	char name[20];
	long int num;
	node *left;
	node *right;
};
node *root=NULL,*temp=NULL,*ptr=NULL;
struct array
{
	node *next;
};
array ar[26];
node* newNode(char n[],long int num)
{
	node *temp=NULL;
	temp=new node;
	strcpy(temp->name,n);
	temp->num=num;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
int height(node* temp)
{
	int h=0,lh,rh,max;
	if(temp!=NULL)
	{
		lh=height(temp->left);
		rh=height(temp->right);
		max=lh>rh?lh:rh;
		h=max+1;
	}
	return h;
}
int difference(node *temp)
{
	int lh,rh,bfactor;
	lh=height(temp->left);
	rh=height(temp->right);
	bfactor=lh-rh;
	return bfactor;
}
node* rightrotation(node *parent)
{
	node *temp,*t;
	temp=parent->right;
	t=parent->left;
	temp->left=parent;
	parent->right=t;
	return temp;
}
node* leftrotation(node *parent)
{
	node *temp,*t;
	temp=parent->left;
	t=parent->right;
	temp->right=parent;
	parent->left=t;
	return temp;
}
node* leftrightrotation(node *parent)
{
	node *temp;
	temp=parent->left;
	parent->left=rightrotation(temp);
	return leftrotation(parent);
}
node* rightleftrotation(node *parent)
{
	node *temp;
	temp=parent->right;
	parent->right=leftrotation(temp);
	return rightrotation(parent);
}
node* balance(node *temp)
{
	int bal_factor=difference(temp);
	if(bal_factor>1)
	{
		if(difference(temp->left)>=0)
			temp=leftrotation(temp);
		else
			temp=leftrightrotation(temp);
	}
	else if(bal_factor<-1)
	{
		if(difference(temp->right)>0)
			temp=rightleftrotation(temp);
		else
			temp=rightrotation(temp);
	}
	return temp;
}
node* insert(node *root,node* temp)
{
	/*if(strcmp(temp->name,root->name)>=0)
	{
		if(root->right==NULL)
		{
			root->right=temp;
		}
		else
		{
			insert(temp,root->right);
		}
	}
	else if(strcmp(temp->name,root->name)<0)
	{
		if(root->left==NULL)
		{
			root->left=temp;
		}
		else
		{
			insert(temp,root->left);
		}
	}*/
	if(root==NULL)
	{
		//root=new node;
		root=temp;
		return root;
	}
	else if(strcmpi(temp->name,root->name)>0)
	{
		root->right=insert(root->right,temp);
		root=balance(root);
	}
	else if(strcmpi(temp->name,root->name)<=0)
	{
		root->left=insert(root->left,temp);
		root=balance(root);
	}
	return root;
}
void find_min(node *temp)
{
	if(temp->left!=NULL)
		find_min(temp->left);
	ptr=temp;
}
void del(char nm[],node *temp)
{
	node *t=NULL;
	if(strcmpi(temp->name,nm)==0&&temp==ar[index].next) //if the contact happens to be the root
	{
		if(temp->right==NULL&&temp->left==NULL)  //leaf node
		{
			ptr=temp;
			delete ptr;

		}
		else if(temp->right==NULL&&temp->left!=NULL)
		{
			ptr=temp;
			temp=temp->left;
			delete ptr;
		}
		else if(temp->right!=NULL&&temp->left==NULL)
		{
			ptr=temp;
			temp=temp->right;
			delete ptr;
		}
		else if(temp->right!=NULL&&temp->left!=NULL)
		{
			t=temp;
			find_min(temp->right);
			strcpy(t->name,ptr->name);
			t->num=ptr->num;
			delete ptr;
		}
		temp=balance(temp);

	}

	else if(temp!=NULL)
	{
	if(strcmpi(nm,temp->name)>0)
	{
		cout<<"\nMoving right";
		if(strcmpi(temp->right->name,nm)==0)
		{
			if(temp->right->right==NULL&&temp->right->left==NULL)
				{
					ptr=temp->right;
					temp->right=NULL;
					delete ptr;
				}
			else if(temp->right->right==NULL&&temp->right->left!=NULL)
			{
				ptr=temp->right;
				temp->right=temp->right->left;
				delete ptr;
				temp->right=balance(temp->right);
			}
			else if(temp->right->right!=NULL&&temp->right->left==NULL)
			{
				ptr=temp->right;
				temp->right=temp->right->right;
				delete ptr;
				temp->right=balance(temp->right);
			}
			else if(temp->right->right!=NULL&&temp->right->left!=NULL)
			{
				t=temp->right;
				find_min(temp->right->right);
				strcpy(t->name,ptr->name);
				t->num=ptr->num;
				delete ptr;
				temp->right=balance(temp->right);
			}
			//ptr=ar[index].next;
			//balance(ptr);

		}
		else
		{
			del(nm,temp->right);
			temp=balance(temp);
		}
	}
	else if(strcmpi(nm,temp->name)<0)
	{
		cout<<"\nMoving left";
		if (strcmpi(temp->left->name,nm)==0)
		{
			if(temp->left->right==NULL&&temp->left->left==NULL)
			{
				ptr=temp->left;
				temp->left=NULL;
				delete ptr;
			}
			else if(temp->left->right==NULL&&temp->left->left!=NULL)
			{
				ptr=temp->left;
				temp->left=temp->left->left;
				delete ptr;
				temp->left=balance(temp->left);
			}
			else if(temp->left->right!=NULL&&temp->left->left==NULL)
			{
				ptr=temp->left;
				temp->left=temp->left->right;
				delete ptr;
				temp->left=balance(temp->left);
			}
			else if(temp->left->right!=NULL&&temp->left->left!=NULL)
			{
				t=temp->left;
				find_min(temp->left->right);
				strcpy(t->name,ptr->name);
				t->num=ptr->num;
				delete ptr;
				temp->left=balance(temp->left);
			}
			//ptr=ar[index].next;
			//balance(ptr);

		}
		else
		{
			del(nm,temp->left);
			temp=balance(temp);
		}
	}
	}
}
void display(node *root)
{
	if(root!=NULL)
	{
		display(root->left);
		cout<<"Name : "<<root->name<<endl;
		cout<<"Number : "<<root->num<<endl;
		display(root->right);
	}
}

/******************KMP Algorithm******************/
int *pi,m,n;
char pat[10],str[50];

void pi_table()
{
	pi=new int(m);
	int k=0,q=1;  //k is the longest prefix suffix length
	char ch;
	pi[0]=0;
	while(q<m)
	{
		ch=pat[q];
		while(tolower(pat[k])!=tolower(ch)&&k!=0)
			k=pi[k-1];
		if(tolower(pat[k])==tolower(ch))
			k++;
		pi[q]=k;
		q++;
	}
}
int search()
{
	int j=0,i=0,f=0;
	for(i=0;i<n;i++)
	{

		while(tolower(str[i])!=tolower(pat[j])&&j>0)
			j=pi[j-1];

		   //	if(str[i-1]!=str[i])
		    //	i++;
		if(tolower(str[i])==tolower(pat[j]))
		{
			j++;
		    //	i++;
		}
		if(j==m)
		{
		      f++;
		      j=pi[j-1];
		      //cout<<"\n"<<i;
		}


	}
	if(f>0)
	return 1;
	return 0;

}

void inorder(node *r)
{
	if(r!=NULL)
	{
		inorder(r->left);
		strcpy(str,r->name);
		n=strlen(str);
		if(search())
		{
		       cout<<"\nName :"<<r->name;
		       cout<<"\nNumber :"<<r->num;
		}
		inorder(r->right);
	}
}
void listinsert(char name1[],long int num)
{
	node *temp=newNode(name1,num);
	//temp=new node;
	//cout<<"Enter name : ";
	alpha=tolower(temp->name[0]);
	index=alpha;
	index=index-97;
	if(ar[index].next==NULL)
	{
		ar[index].next=temp;
		root=temp;
	}
	else
	{
		root=ar[index].next;
		root=insert(root,temp);
	}
}
void listinsertion()
{
	listinsert("Sana",80382092);
	listinsert("Bina",87382092);
	listinsert("Falguni",70382092);
	listinsert("Sahil",988292922);
	listinsert("Shashank",57678778);
	listinsert("Tina",88782092);
	listinsert("Harsh",89882092);
	listinsert("Karthik",23382092);
	listinsert("Anna",88982092);
	listinsert("Henna",80808080);
	listinsert("Hema",80878080);
	listinsert("Akriti",908222080);
	listinsert("Lavanya",80893380);
	listinsert("Deepak",80234480);
	listinsert("Charu",80805640);

}
/*******function prototypes**********************/
void screen1();
void screen2();
void no_insert();
void no_delete();
void no_search();
void exit()
{
}
void no_display();
int initmouse();
void hidemouse();
void showmouse();
void getcord(int*,int*,int*);
void restrictmouseptr(int,int,int,int);
union REGS in,out;
int x,y,click;
char ch,name[30],number[20];
/****************************VOID MAIN*************************/

void main()
{
	int g=DETECT,m,x,y,click;
	char temp[25];
	initgraph(&g,&m,"c:\\tc\\bgi");
	cleardevice();
	for(int i=0;i<25;++i)
		ar[i].next=NULL;
	listinsertion();
	screen1();
	getch();
	closegraph();
}
int initmouse()
{
	in.x.ax=0;
	int86(0x33,&in,&out);
	return out.x.ax;
}
void restrictmouseptr(int x1,int y1,int x2,int y2)
{
	in.x.ax=7;
	in.x.cx=x1;
	in.x.dx=x2;
	int86(0x33,&in,&out);
	in.x.ax=8;
	in.x.cx=y1;
	in.x.dx=y2;
	int86(0x33,&in,&out);
}
void showmouse()
{
	union REGS in,out;
	in.x.ax=1;
	int86(0x33,&in,&out);
}
void hidemouse()
{
	union REGS in,out;
	in.x.ax=2;
	int86(0x33,&in,&out);
}
void getcord(int *x,int *y,int *click)
{
	union REGS in,out;
	in.x.ax=3;
	int86(0x33,&in,&out);
	*x=out.x.cx;
	*y=out.x.dx;
	*click=out.x.bx;
}
void corddisplay()
{
	while(!kbhit())
	{
		getcord(&x,&y,&click);
		cout<<x<<" "<<y<<endl;
		delay(1000);
	}
}
void screen1()
{
	cleardevice();
	setfillstyle(11,RED);
	bar(8,50,642,420);
	setfillstyle(11,BLUE);
	bar(28,70,622,400);
	setcolor(WHITE);
	settextstyle(0,HORIZ_DIR,2);
	outtextxy(220,110,"Project by:");
	outtextxy(220,125,"___________");
	settextstyle(0,HORIZ_DIR,3);
	outtextxy(50,181,"E.ANNAPOORNA   13503864");
	outtextxy(50,232,"SAHIL UPADHYAY 13503865");
	outtextxy(50,280,"SHASHANK GUPTA 13503888");
	getch();
	screen2();
	exit(0);
}
void screen2()
{
	cleardevice();
	showmouse();
	setfillstyle(11,RED);
	bar(8,50,642,420);           //Home
	setfillstyle(11,BLUE);
	bar(28,70,622,400);          //Home
	setfillstyle(11,WHITE);
	bar(243,336,370,378);        //Exit
	settextstyle(0,HORIZ_DIR,3); //Exit
	outtextxy(258,346,"EXIT");
	setcolor(WHITE);
	settextstyle(4,HORIZ_DIR,5);
	outtextxy(69,120,"TELEPHONE DIRECTORY");
	setcolor(WHITE);
	for(int i=0;i<50;i++)
	{
		circle(150,237,i);   //Insert
	}
	setcolor(RED);
	settextstyle(0,HORIZ_DIR,2);
	outtextxy(105,233,"Insert");
	setcolor(WHITE);
	for(i=0;i<50;i++)
	{
		circle(300,237,i);   //Search
	}
	setcolor(RED);
	settextstyle(0,HORIZ_DIR,2);
	outtextxy(252,233,"Search");
	setcolor(WHITE);
	for(i=0;i<50;i++)
	{
		circle(450,237,i);   //Delete
	}
	setcolor(RED);
	settextstyle(0,HORIZ_DIR,2);
	outtextxy(406,233,"Delete");
	ch=getch();
	if(ch=='I' || ch=='i')
	{
		for(int i=0;i<50;i++)
		{
			setcolor(RED);
			circle(150,237,50-i);   //Insert
			setcolor(WHITE);
			settextstyle(0,HORIZ_DIR,2);
			outtextxy(105,233,"Insert");
			delay(20);
		}
		no_insert();
	}
	else if(ch=='S' || ch=='s')
	{
		setcolor(RED);
		for(i=0;i<50;i++)
		{
			setcolor(RED);
			circle(300,237,50-i);   //Search
			setcolor(WHITE);
			settextstyle(0,HORIZ_DIR,2);
			outtextxy(252,233,"Search");
			delay(20);
		}
		no_search();
	}
	else if(ch=='d' ||ch=='D')
	{
		for(i=0;i<50;i++)
		{
			setcolor(RED);
			circle(450,237,50-i);   //Delete
			setcolor(WHITE);
			settextstyle(0,HORIZ_DIR,2);
			outtextxy(406,233,"Delete");
			delay(20);
		}
		no_delete();
	}
	else if(ch=='e' ||ch=='E')
	{
		exit();
	}
	else
	{
		for(i=0;i<10;i++)
		{
			setcolor(WHITE);
			settextstyle(5,HORIZ_DIR,5);
			outtextxy(120,330,"Wrong Input !!!");
			delay(100);
		}
		screen2();
	}

}
void no_insert()
{
	char name1[50];
	long int number;
	cleardevice();
	showmouse();
	setfillstyle(11,RED);
	bar(8,50,642,420);           //Home
	setfillstyle(11,BLUE);
	bar(28,70,622,400);          //Home
	setfillstyle(8,RED);
	bar(243,336,370,378);        //Exit
	settextstyle(0,HORIZ_DIR,2); //Exit
	outtextxy(274,349,"EXIT");
	setcolor(WHITE);
	settextstyle(4,HORIZ_DIR,5);
	outtextxy(69,120,"TELEPHONE DIRECTORY");
	setcolor(WHITE);
	setfillstyle(1,WHITE);
	bar(227,203,420,225);        //Name_panal
	setfillstyle(1,WHITE);
	bar(227,249,420,271);        //Number
	settextstyle(0,HORIZ_DIR,2);
	outtextxy(109,206,"NAME  :");
	settextstyle(0,HORIZ_DIR,2);
	outtextxy(109,249,"NUMBER:");
	setfillstyle(11,RED);
	bar(254,298,363,323);        //Save
	settextstyle(0,HORIZ_DIR,2);
	outtextxy(274,305,"SAVE");
	//corddisplay();
	gotoxy(31, 14);
	gets(name1);
	gotoxy(31, 17);
	cin>>number;
	char c;
	c=getch();
	if(c=='s'||c=='S')
	{
		node *temp=newNode(name1,number);
		//temp=new node;
		//cout<<"Enter name : ";
		alpha=tolower(temp->name[0]);
		index=alpha;
		index=index-97;
		if(ar[index].next==NULL)
		{
			ar[index].next=temp;
			root=temp;
		}
		else
		{
			root=ar[index].next;
			root=insert(root,temp);
		}
		screen2();
	}
	else
	screen2();
	//no_display(name);

}
void no_search()
{
	node *r=NULL;
	cleardevice();
	showmouse();
	setfillstyle(11,RED);
	bar(8,50,642,420);           //Home
	setfillstyle(11,BLUE);
	bar(28,70,622,400);          //Home
	setfillstyle(11,WHITE);
	bar(243,336,370,378);        //Exit
	settextstyle(0,HORIZ_DIR,3); //Exit
	outtextxy(258,346,"EXIT");
	setcolor(WHITE);
	settextstyle(4,HORIZ_DIR,5);
	outtextxy(69,120,"TELEPHONE DIRECTORY");
	setcolor(WHITE);
	setfillstyle(1,WHITE);
	bar(208,213,400,243);        //Search_Panel
	setfillstyle(10,WHITE);
	bar(273,279,332,311);        //Go
	settextstyle(0,HORIZ_DIR,2);
	outtextxy(284,287,"GO");
	gotoxy(30, 15);
	//gets(name);
	//cout<<"\nEnter the pattern ";
	gets(pat);
	no_display();
	m=strlen(pat);
	pi_table();
	//int m1=45, n1=14;
	for(int j=0;j<m;j++)
	{
		cout<<"\n"<<pi[j];

	}
	for(int k=0;k<26;k++)
	{
		if(ar[k].next!=NULL)
		{
			r=ar[k].next;
			inorder(r);
		}

	}
	delete pi;
	getch();
	screen2();


}
void no_display()
{
	cleardevice();
	showmouse();
	setfillstyle(11,RED);
	bar(8,50,642,420);           //Home
	setfillstyle(11,BLUE);
	bar(28,70,622,400);          //Home
	setfillstyle(11,WHITE);
	bar(243,336,370,378);        //Exit
	settextstyle(0,HORIZ_DIR,3); //Exit
	outtextxy(258,346,"EXIT");
	setcolor(WHITE);
	settextstyle(4,HORIZ_DIR,5);
	outtextxy(69,120,"TELEPHONE DIRECTORY");

       //	delay(2000);

}
void no_delete()
{
	cleardevice();
	showmouse();
	setfillstyle(11,RED);
	bar(8,50,642,420);           //Home
	setfillstyle(11,BLUE);
	bar(28,70,622,400);          //Home
	setfillstyle(11,WHITE);
	bar(243,336,370,378);        //Exit
	settextstyle(0,HORIZ_DIR,3); //Exit
	outtextxy(258,346,"EXIT");
	setcolor(WHITE);
	settextstyle(4,HORIZ_DIR,5);
	outtextxy(69,120,"TELEPHONE DIRECTORY");
	setcolor(WHITE);
	setfillstyle(1,WHITE);
	bar(208,213,400,243);        //delete_panal
	setfillstyle(10,WHITE);
	bar(273,279,332,311);        //Delete
	settextstyle(0,HORIZ_DIR,2);
	outtextxy(284,287,"DELETE");
	gotoxy(30, 15);
	//gets(name);
	//cout<<"Enter name to be deleted : ";
	gets(nm);
	alpha=tolower(nm[0]);
	index=alpha;
	index=index-97;
	root=ar[index].next;
	del(nm,root);
	screen2();
	//corddisplay();
}
