#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
struct Node{
	int id_num;
	char name[16];
	struct Node *next;
};
typedef struct Node Node;
//-----------------------------------------------------------------

//-------------------DELETE ALL------------------------------------
/*
Node * deleteAll(Node *head)
{
 if(head!=0)                                       // LL Present
 {
	  if(head->next==NULL)                     // last node of LL
	  {
		    free(head);                    // delete last node
		    cout<<"\nLast Node Deleted\n";                   // test
		    return NULL;
	  }
	  else                                     // not last node
	  {
		 head->next=deleteAll(head->next); // delete further nodes
		 free(head);                       // delete this node
		 cout<<"\nNode Deleted\n";
		 return NULL;
	  }
 }
 else
 {
	cout<<"\nList Empty\n";
	return NULL;
 }
}
*/
//------------------------------------------------------------------

//-----------------------PRINT NODE---------------------------------
void printNode(Node *node)
{
 cout<<"\n\n\tName "<<node->name;
 cout<<"\n\tId Number "<<node->id_num;
}
//------------------------------------------------------------------

//-----------------------Print All----------------------------------
void printAll(Node *head)
{
 if(head!=0)                                      // head present non empty l.l.
  {
	 printNode(head);                         // print current data

	 if(head->next!=0)                        // check if next node is present        //custom
	   printAll(head->next);                  // therefore call for next node
	 else
	 {
		   cout<<"\nPrinting Ends\n";     // last node reached printing ends
	 }
  }
 else
 {
	 cout<<"\nList Empty,Insert Student Data\n";
 }
}
//--------------------------------------------------------------------

//--------------------------INSERT------------------------------------
void getData(int *id_num,char *name)
{
 cout<<"\nEnter Id Number\t";
 cin>>*id_num;
 cout<<"\nEnter Name\t";
 gets(name);
 cout<<"\nData Saved\n";                         //test
}

Node * InsertNode(Node *head)
{
 Node *newHead=(Node *)malloc(sizeof(Node));
 if(!newHead)
 {
   cout<<"\nMemory Full, Delete a Student Data";
   return head;
 }
 else
 {
   getData(&newHead->id_num,newHead->name);
   newHead->next=head;
   return newHead;
 }
}

//---------------------------------------------------------------------
//----------------FIND-------------------------------------------------
Node *findNode(Node *head,int keyNum)
{
 while(head)
 {
    if(head->id_num==keyNum)                // node found
     return head;                           // return ptr to that node
    //else                                  
     head=head->next;                       // not found goto next node
 }
 return NULL;                               // not found in LL return NULL
}
//-----------------------------------------------------------------------

//-------------------------------Print Func------------------------------
void printSpecificNode(Node *head)
{
 if(!head)
    cout<<"\nList Empty,Insert Student Data\n";
 else
 {
  int keyNum;
  Node *keyNode;
  cout<<"\nEnter ID Number\t";
  cin>>keyNum;
  keyNode=findNode(head,keyNum);
  if(!keyNode)
     cout<<"\nData Not Found\n";
  else
     printNode(keyNode);
 }
}
//-----------------------------------------------------------------------

//------------------------------Edit Data--------------------------------
void editData(Node *head)
{
 if(!head)
    cout<<"\nList Empty,Insert Student Data\n";
 else
 {
  int keyNum;
  Node *keyNode;
  cout<<"\nEnter Previous ID Number\t";
  cin>>keyNum;
  keyNode=findNode(head,keyNum);
  if(!keyNode)
     cout<<"\nData Not Found\n";
  else
     {
      cout<<"\nData Found\n";
      getData(&keyNode->id_num,keyNode->name);
      cout<<"\nData Overwritten\n";
     }
 }
}
//-----------------------------------------------------------------------
//-----------------------FIND FUNC FOR DELETE----------------------------
Node *findNodeForDel(Node *head,int keyID)
{
 while(head->next!=NULL)
 {
  if(head->next->id_num==keyID)
   return head;
  else
   head=head->next;
 }
 return NULL;
}
//-----------------------------------------------------------------------

//-----------------------------DELETE Data-------------------------------
Node *deleteNode(Node *head)
{
 if(!head)
  {
    cout<<"\nList Empty,Insert Student Data\n";
    return head;
  }
 else
 {
  int keyNum;
  cout<<"\nEnter ID Number\t";
  cin>>keyNum;

  if(head->id_num==keyNum)
  {
   Node *newHead=head->next;
   head->next=NULL;
   free(head);
   cout<<"\nData Deleted\n";
   return newHead;
  }
  else
  {
   Node *p=findNodeForDel(head,keyNum);
   if(!p)
    {
     cout<<"\nData Not Found\n";
     return head;
    }
    else
    {
      Node *q=p->next;
      p->next=p->next->next;
      free(q);
      cout<<"\nData Deleted\n";
      return head;
    }
  }
 }
}
//-----------------------------------------------------------------------
void main()
{
 int choice;
 clrscr();
 Node *head=NULL;
 cout<<"LINKED LISTS\n";

 do{
    cout<<"\n\nMENU\n"
	  <<"1 Insert Student Data\n"
	  <<"2 Print Student Data\n"
	  <<"3 Edit Student Data\n"
	  <<"4 Delete Student Data\n"
	  <<"5 Print All Students' Data\n"
	 // <<"6 Delete All\n"
	  <<"6 Exit\n";
    cout<<"Enter Your Choice\t";
    cin>>choice;
    switch(choice)
    {
     case 1:
     {
	head=InsertNode(head);
	break;
     }
     case 2:
     {
	printSpecificNode(head);
	break;
     }
     case 3:
     {
	editData(head);
	break;
     }
     case 4:
     {
     head=deleteNode(head);
     break;
     }
     case 5:
     {
	printAll(head);
	break;
     }
     /*case 6:
     {
       head=deleteAll(head);
       if(head==NULL)
       { cout<<"\nDeletion Ends";}
       break;
     }*/
     case 6:
     {
		//head=deleteAll(head);
		//if(head==NULL)
		  //cout<<"\nDELETION ENDS";
	cout<<"\nAre You Sure, Press Again to Exit\t";cin>>choice;

	break;
     }
     default:
      cout<<"Invalid Input\n";
    }
 }
 while(choice!=6);
 cout<<"\nProgram Successful\nEnd Of Program";
 getch();
}