/* program of operation of Circular link list */

#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct LSM
	{
	char bname[50],author[50],dprt[50]; //,sname[50];
	int data,rank,id,doi,dor,mobno,year,iss,isb,rtb;
	struct LSM *next;
	}node;
/*typedef struct Student
	{
	char s1name[50],s1dprt[50],s1bname[50];
	int id1,mobno1,s1year;
	struct Student *next;
	}st;

st  *first1=NULL,  *last1=NULL, *temp1=NULL; */
node *first=NULL, *last=NULL, *temp=NULL, *prev=NULL, *succeed=NULL;
int count=0;

int main()
	{
	int ch,i,key,ch1,position,flag=0;
	char tp[20];
	printf("\n*******LIBRARY MANAGEMENT SYSTEM*******\n");
	printf("\n1.ADD A BOOK \n\n2.DISPLAY AVAILABLE BOOKS \n\n3.SEARCH BOOKS \n\n4.DELETE BOOK  \n\n5.ISSUE THE BOOKS \n\n6.RETURN THE BOOKS \n\n7.Exit\n");
	do
		{
		printf("\n\nPlease,Enter Your Choice=");
		scanf("%d",&ch);
		switch(ch)
			{
			case 1:
				temp=(node *)malloc(sizeof(node));
				//temp1=(st *)malloc(sizeof(st));
				printf("\nPlease Enter name of the book: ");
				scanf("%s",&temp->bname);
				printf("\nPlease Enter name of the book Author: ");
				scanf("%s",&temp->author);
				printf("\nPlease Enter ID number of the book: ");
				scanf("%d",&temp->id);
				printf("\nPlease Enter position of the book in the library/rank: ");
				scanf("%d",&temp->rank);
				temp->next=NULL;
				if(count==0)
					{
					first=temp;
					last=temp;
					count++;

					printf("\n\nSaved successfully!!\n");

					}
				else
					{
					last->next=temp;
					last=temp;
					last->next=first;
					count++;

					printf("\nSaved successfully!!\n");
					}
				break;

			case 2:
				if(count==0)
					{
					printf("\nBOOKS ARE NOT AVAIALABLE..\n");
					}
				else
					{
					temp=first;

						printf("ID NUMBER     NAME OF BOOK     AUTHOR NAME      RANK IN LIBRARY  \n");
						printf("==================================================================\n");
							do
								{
									printf("   %d   \t %s    \t %s    \t  %d",temp->id,temp->bname,temp->author,temp->rank);
									printf("\n");
									temp=temp->next;
								}while(temp!=last->next);
					}
					printf("\nTOTAL NUMBER OF BOOKS: %d",count);
				break;
			case 3:
				flag=0;
				if(count==0)
					{
					printf("\nBOOKS ARE NOT AVIALABLE..\n");
					}
				else
					{
					printf("\nFOR SEARCHING THE BOOK YOU HAVE TO ENTER THE BOOKS ID");
					printf("\n\nENTER BOOK ID:");
					scanf("%d",&key);
					temp=first;
					for(i=0;i<count;i++)
						{
						if(temp->id==key)
							{
							printf("\nID NUMBER: %d\tNAME OF BOOK: %s\tAUTHOR NAME: %s\tRANK IN LIBRARY: %d",temp->id,temp->bname,temp->author,temp->rank);
							flag=1;
							break;
							}
						temp=temp->next;
						}
					if(flag==0)
						{
						printf("\n\nBOOKS ARE NOT AVAIALABLE..\n");
						}
					}
				break;

			case 4:
				if(count==0)
					{
					printf("\nBOOKS ARE NOT AVAIALABLE..\n");
					}
				else
					{
					printf("IF YOU HAVE TO DELETE THE BOOK FROM YOUR REGISTER, YOU HAVE TO ENTER THE ID NUMBER OF BOOK");
					printf("\n\nEnter ID of the Book:");
					scanf("%d",&key);
					flag=0;
					prev=first;
					succeed=first;
					temp=first;
					for(i=0;i<count;i++)
						{
						if(temp->id==key)
							{
							if(prev==succeed)
 								{
								if(temp->next==first)
									{
									printf("\n%s book is Deleted..\n",temp->bname);
									free(temp);
									first=NULL;
									last=NULL;
									count--;
									flag=1;
									break;
									}
								else
									{
									first=first->next;
									last->next=first;
									free(temp);
									count--;
									flag=1;
									printf("\n%s book is Deleted..\n",temp->bname);
									break;
									}
								}
							else
								{
								prev->next=succeed->next;
								if(prev->next==first)
								last=prev;
								free(temp);
								count--;
								flag=1;
								printf("\n%s book is Deleted..\n",temp->bname);
								break;
								}
							}
						else
							{
							prev=succeed;
							temp=temp->next;
							succeed=temp;
							}
						}
					if(flag==0)
						{
						printf("\nBOOK IS NOT FOUND..\n");
						}
					}
				break;

			case 5:
			//	printf("\nEnter student name : \n");
			//		scanf("%s",temp1->s1name);
			//	printf("\nEnter Student Department : \n");
			//	    scanf("%s",temp1->s1dprt);
			//	printf("\nIn which year Student study:");
			//		scanf("%d",temp1->s1year);
			//		printf("Enter Mobile Number of Student:");
			//		scanf("%d",&temp1->mobno1);
					printf("\nEnter Id of The Book that Student want to issue:");
					scanf("%d",&temp->isb);
					if(temp->isb==temp->iss)
					{
						printf("The Book Is Issued on %d  date",temp->doi);
					}
					else
					{

						if(temp->isb==temp->id)
							{
							printf("\nEnter Date of issue:");
							scanf("%d",&temp->doi);
					    	printf("\nPlease Return Book Within 15 Days....");
					  		//temp1->id1=temp->id;

				    		}

				    	else
				   		 	{
							printf("\nEntered Book Is not Available in Database......");

				   			}
				   }
				   	/*if(temp1->id1==temp->id)
				   		{
				   		char strcpy(char *s1name, char *sname);
				   		char strcpy(char *s1bname,char *bname);
						}
					printf("%s	%s	",temp1->s1name,temp1->s1bname); */
				break;
				case 6:
					printf("\nEnter Book Id which want to return:");
					scanf("%d",&temp->rtb);
					if(temp->rtb==temp->id)
					{
						if(temp->rtb==temp->isb)
						{
							printf("\nBook Return Successfully\n");
							free(temp);
						}
					}
				break;
				default :
					printf("Please  Enter Valid Choice");
					printf("\nPlease Re-enter Program............");
			}
		}while(ch>=1 && ch<=7);
	//getch();
	return 0;
	}
