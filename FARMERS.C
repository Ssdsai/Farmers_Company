#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define max 10
void push1(int sts[max],int data1);
void push2(char stn[max][100],char data2[100]);
void push3(char stb[max][100],char data3[100]);
void push4(int stp[max],int data4);
void push5(int stq[max],int data5);
struct cust
{
	char name[50],gender;
	long int ph_no;
	int age;
	struct cust *link;
	struct cust *data;
};
struct pro
{
	struct pro *llink;
	struct pro *rlink;
	int sl_no,price;
	char brand_name[50],pro_name[50],pro_de[100];
};
struct enode
{
	struct enode *ll;
	char e_nm[50],det[100];
	int s_n,price;
	struct enode *rl;
};
struct tree
{
struct tree *llink;
char soil[50],info[50];
struct tree *rlink;
};
struct tree *root=NULL,*disp;
struct tree *cur,*pre,*p;
struct tree* preorder(char s[50]);
struct enode *temp,*fi=NULL;
struct cust *first=NULL,*tmp,*ptr;
struct pro *l1,*f1=NULL,*c1;
char stn[max][100],stb[max][100];
int top1=-1,top2=-1,top3=-1,top4=-1,top5=-1,top=0,stp[max],sts[max],stq[max];
int num=0,num1=0,t=0;
void login();
void admin();
void crop_req();
void shop();
void e_mark();
void main()
{
	int ch,n;
	clrscr();
	printf("Greetings to everyone\nWelcome to FarmTech platform\n\n");
	printf("Here in this program a online platform is created for buying\n");
	printf("and selling all the products related to farmers.\n");
	printf("---------------------------------------------------------\n");
	do
	{
		printf("Menu\n-----\n1.Login details\n2.Admins login\n3.Crop requirements\n");
		printf("4.Farmer's shop\n5.E-marketing\n6.Exit\n");
		printf("\nEnter your choice (1-6):\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:login();
				printf("\nTo go back to menu, please enter 0\n");
				scanf("%d",&n);
				break;
			case 2:admin();
				printf("\nTo go back to menu, please enter 0\n");
				scanf("%d",&n);
				break;
			case 3:crop_req();
				printf("\nTo go back to menu, please enter 0\n");
				scanf("%d",&n);
				break;
			case 4:shop();
				printf("\nTo go back to menu, please enter 0\n");
				scanf("%d",&n);
				break;
			case 5: e_mark();
				printf("\nTo go back to menu, please enter 0\n");
				scanf("%d",&n);
				break;
			case 6: exit(0);
				break;
			default:printf("\nInvalid choice\nEnter again\n");
				main();
		}
	}while(n==0);
}
void login()
{
	tmp=(struct cust*)malloc(sizeof(struct cust));
	clrscr();
	printf("Welcome to the customer login page.Please fill in your details carefully\n");
	printf("\nEnter your name :\n");
	fflush(stdin);
	gets(tmp->name);
	printf("\nEnter your contact number :\n");
	scanf("%ld",&tmp->ph_no);
	fflush(stdin);
	printf("\nEnter your gender (m/M=male & f/F=female) :\n");
	scanf("%s",&tmp->gender);
	printf("\nEnter your age :\n");
	scanf("%d",&tmp->age);
	if(first==NULL)
	{
	first=tmp;
	first->link=NULL;
	}
	else
	{
	tmp->link=first;
	first=tmp;
	}
	if(first==NULL)
	printf("\nNo deatils found\n");
	else
	{
	ptr=first;
	printf("\nThe details you entered are:\n");
	while(ptr!=NULL)
	{
		printf("Your name is ");
		puts(ptr->name);
		printf("The contact number provided is %ld\n",ptr->ph_no);
		printf("Your gender is %c\n",ptr->gender);
		printf("Your age is %d\n",ptr->age);
		ptr=ptr->link;
	}
	}
	getch();
}
void admin()
{
	int ans,ch6,ans1,ans5;
	char epass[20],spass[20]="realfarmer";
	clrscr();
	printf("Welcome to the admin login page\n");
	printf("Here only the admin is permitted to enter the relevant details\n");
	printf("Dear admin,\nPlease enter the password to continue...\n");
	scanf("%s",epass);
	if(strcmp(epass,spass)==0)
	{
	printf("\nPassword matched!\n\nHi Dhanush!,You can proceed\n");
	printf("1.Entering of the shop section\n2.Entering of the e-market section\n");
	printf("3.Entering of the crop details section\n\nEnter your choice:\n");
	scanf("%d",&ch6);
	if((ch6!=1&&ch6!=2)&&ch6!=3)
	{
	printf("Enter correct choice:\n");
	scanf("%d",&ch6);
	}
	if(ch6==1)
	{
	do
	{
	l1=(struct pro*)malloc(sizeof(struct pro));
	clrscr();
	printf("Enter the code number of the product :\n");
	scanf("%d",&l1->sl_no);
	printf("Enter the brand name of the product :\n");
	fflush(stdin);
	gets(l1->brand_name);
	printf("Enter the name of the product :\n");
	fflush(stdin);
	gets(l1->pro_name);
	printf("Enter the price of the product :\n");
	scanf("%d",&l1->price);
	printf("Enter the details of the product :\n");
	fflush(stdin);
	gets(l1->pro_de);
	num++;
	if(f1==NULL)
	{
	f1=l1;
	l1->rlink=l1;
	l1->llink=l1;
	}
	else
	{
	c1=f1->llink;
	c1->rlink=l1;
	l1->llink=c1;
	l1->rlink=f1;
	f1->llink=l1;
	}
	printf("\nDo you want to add another product? (yes=1/no=0):\n");
	scanf("%d",&ans);
	}while(ans==1);
	}
	if(ch6==2)
	{
	do
	{
	temp=(struct enode*)malloc(sizeof(struct enode));
	clrscr();
	printf("Enter the code number of the produce :\n");
	scanf("%d",&temp->s_n);
	printf("Enter the name of the produce :\n");
	fflush(stdin);
	gets(temp->e_nm);
	printf("Enter the price of the produce :\n");
	scanf("%d",&temp->price);
	printf("Enter the details of the produce :\n");
	fflush(stdin);
	gets(temp->det);
	num1++;
	if(fi==NULL)
	{
	fi=temp;
	fi->ll=NULL;
	fi->rl=NULL;
	}
	else
	{
	temp->ll=NULL;
	temp->rl=fi;
	fi->ll=temp;
	fi=temp;
	}
	printf("\nDo you want to add another produce (yes=1/no=0)?\n");
	scanf("%d",&ans1);
	}while(ans1==1);
	}
	if(ch6==3)
	{
	do
	{
	disp=(struct tree*)malloc(sizeof(struct tree));
	clrscr();
	printf("Enter the name of the soil\n");
	scanf("%s",disp->soil);
	printf("Enter the name of the crops\n");
	fflush(stdin);
	gets(disp->info);
	disp->llink=NULL;
	disp->rlink=NULL;
	if(root==NULL)
	root=disp;
	else
	{
		cur=root;
		while(cur!=NULL)
		{
		pre=cur;
		if(strcmp(disp->soil,cur->soil)<0)
		cur=cur->llink;
		else
		cur=cur->rlink;
		}
		if(strcmp(disp->soil,pre->soil)<0)
		pre->llink=disp;
		else
		pre->rlink=disp;
	}
	printf("\nDo you want to add another info (yes=1/no=0)?\n");
	scanf("%d",&ans5);
	}while(ans5==1);
	}
	}
	else
	printf("Wrong password!!!\nTry again\n");
	getch();
}
void crop_req()
{
	char s[50];
	clrscr();
	printf("Welcome to the requirements of the crops page\n");
	printf("The type of the crop to be grown mainly depends on the type\n");
	printf("of the soil available for the farmer\n\n");
	printf("Select the soil of your land\n");
	fflush(stdin);
	gets(s);
	p=preorder(s);
	if(p!=NULL)
	{
	printf("The crops grown in this soil are\n");
	fflush(stdout);
	puts(p->info);
	}
	else
	printf("\nThe details of the soil is not found\n");
	getch();
}
struct tree* preorder(char s[50])
{
struct tree *sam=root;
while(strcmp(sam->soil,s)!=0)
{
	if(strcmp(sam->soil,s)>0)
	sam=sam->llink;
	else
	sam=sam->rlink;
	if(sam==NULL)
	return NULL;
}
return sam;
}
void shop()
{
	int ch3,ch4,q,ans3;
	clrscr();
	printf("Welcome to the 'Farmers Enterprises'\n");
	printf("-------------------------------------------\n");
	printf("\nIn this page you can buy the products related to farming and agriculture\n");
	printf("A bill will be generated for the same\n");
	do
	{
	printf("Menu\n-----\n1.Product display\n2.Bill\n3.Main menu\n");
	printf("\nEnter your choice (1-3) :\n");
	scanf("%d",&ch3);
	if(ch3==1)
	{
	struct pro *ptr1;
	int ct=0,i,f=0,sn;
	if(f1==NULL)
	printf("\nNo details found\n");
	else
	{
		c1=f1;
		while(c1->rlink!=f1)
		{
			printf("%d\n",c1->sl_no);
			fflush(stdout);
			puts(c1->brand_name);
			fflush(stdout);
			puts(c1->pro_name);
			printf("%d\n",c1->price);
			fflush(stdout);
			puts(c1->pro_de);
			printf("\n\n");
			c1=c1->rlink;
		}
		printf("%d\n",c1->sl_no);
		fflush(stdout);
		puts(c1->brand_name);
		fflush(stdout);
		puts(c1->pro_name);
		printf("%d\n",c1->price);
		fflush(stdout);
		puts(c1->pro_de);
	}
	do
	{
	f=0;
	printf("\nSelect the product code of which you want to buy :\n");
	scanf("%d",&sn);
	if(f1==NULL)
	printf("\nNo details found\n");
	else
	{
		for(ptr1=f1,i=0;i<num;i++,top++,ptr1=ptr1->rlink)
		{
		ct++;
		if(ptr1->sl_no==sn)
		{
		f=1;
		printf("\nThe price of the product chosen is %d\n",ptr1->price);
		fflush(stdout);
		puts(ptr1->pro_de);
		printf("\nEnter the quantity of the product (in kgs/ltr ,etc):\n");
		scanf("%d",&q);
		printf("The payable amount for this product is %d\n",(ptr1->price*q));
		push1(sts,ptr1->sl_no);
		push2(stn,ptr1->pro_name);
		push3(stb,ptr1->brand_name);
		push4(stp,ptr1->price);
		push5(stq,q);
		}
		}
		if(f==0)
		{
		printf("\nSorry the product you entered is out of stock\n");
		printf("Sorry for the inconvenience\n");
		}
	}
	printf("\nDo you want to purchase another item (yes=1/no=0)?\n");
	scanf("%d",&ans3);
	}while(ans3==1);
	}
	else if(ch3==2)
	{
		int j,tot=0;
		clrscr();
		printf("Your bill is ready for the purchase\n\n\n");
		printf("\t\tFarmers Enterprises\n");
		printf("\tPresidency University\n");
		printf("\t\tRajankunte, Bengaluru\n");
		printf("\t\tMob no:-9741846326\n");
		printf("-------------------------------------------------\n");
		printf("Name:");
		puts(tmp->name);
		printf("\nMobile no:- %ld\t\t\tGender:- %c\n",tmp->ph_no,tmp->gender);
		printf("-------------------------------------------------\n");
		printf("Sl.no\tProduct_code\tProduct_name\tRate\tQty\tAmount\n");
		for(j=0,t=1;j<=top;j++,t++)
		{
		printf("%d\t",t);
		fflush(stdout);
		printf("%d\t",sts[j]);
		fflush(stdout);
		puts(stn[j]);
		printf("\t%d\t",stp[j]);
		fflush(stdout);
		printf("%d\t",stq[j]);
		fflush(stdout);
		printf("%d\n",(stp[j]*stq[j]));
		tot+=(stp[j]*stq[j]);
		}
		printf("\n");
		printf("******Thank You, Visit Again*****\n\n");
		printf("Total amount is %d\n",tot);
		printf("Received with thanks\n");
		printf("Keep smiling\n");
	}
	else if(ch3==3)
	main();
	else
	printf("Invalid choice\n");
	printf("\nTo go back to shop, please enter 1\n");
	scanf("%d",&ch4);
	}while(ch4==1);
	getch();
}
void e_mark()
{
	struct enode *ptr2;
	int i,f=0,ct=0,sn1,q2,ans4;
	clrscr();
	printf("Welcome to the e-marketing section\n");
	printf("The rates at which the products are taken is displayed\n");
	printf("Please select the fruits,vegetables or crop which you want to sell\n");
	printf("Sl_no\t\tCrop_name\t\tPrice\tDetails\n");
	if(fi==NULL)
	printf("No details found\n");
	else
	{
		temp=fi;
		while(temp!=NULL)
		{
		printf("%d\t",temp->s_n);
		fflush(stdout);
		puts(temp->e_nm);
		printf("\t\t%d\t\t",temp->price);
		fflush(stdout);
		puts(temp->det);
		printf("\n");
		temp=temp->rl;
		}
	}
	do
	{
	printf("\nSelect the serial number of the produce which you want to sell\n");
	scanf("%d",&sn1);
	if(fi==NULL)
	printf("\nNo details found\n");
	else
	{
		for(ptr2=fi,i=0;i<num1;i++,ptr2=ptr2->rl)
		{
			ct++;
			if(ptr2->s_n==sn1)
			{
			f=1;
			printf("\nThe price of this produce is %d\n",ptr2->price);
			printf("\nEnter the quantity of the produce you are selling (in kgs):\n");
			scanf("%d",&q2);
			printf("The amount payable is %d\n",(ptr2->price*q2));
			}
		}
		if(f==0)
		{
		printf("\nThe entered produce is not been taken in our market\n");
		printf("Sorry for the inconvenience\n");
		}
	}
	printf("\nDo you want to sell another produce (yes=1/no=0)?\n");
	scanf("%d",&ans4);
	}while(ans4==1);
	getch();
}
void push1(int sts[max],int data1)
{
	if(top1==max-1)
	printf("Not selected anything\n");
	else
	{
		top1=top1+1;
		sts[top1]=data1;
	}
}
void push2(char stn[max][100],char data2[100])
{
	if(top2==max-1)
	printf("Not selected anything\n");
	else
	{
		top2=top2+1;
		strcpy(stn[top2],data2);
	}
}
void push3(char stb[max][100],char data3[100])
{
	if(top3==max-1)
	printf("Not selected anything\n");
	else
	{
		top3=top3+1;
		strcpy(stb[top3],data3);
	}
}
void push4(int stp[max],int data4)
{
	if(top4==max-1)
	printf("Not selected anything\n");
	else
	{
		top4=top4+1;
		stp[top4]=data4;
	}
}
void push5(int stq[max],int data5)
{
	if(top5==max-1)
	printf("Not selected anything\n");
	else
	{
		top5=top5+1;
		stq[top5]=data5;
	}
}