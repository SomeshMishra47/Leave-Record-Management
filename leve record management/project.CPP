#include<stdio.h>           //contains printf, scanf etc
#include<conio.h>           //contains delay(),getch(),gotoxy(),etc.
#include<iostream.h>        //contains cout,cin,etc.
#include<process.h>         //contains exit(),etc.
#include<string.h>          //contains strcmp(), strcpy(), strlen(),etc.
#include<time.h>            //contains clock,ctime(),etc.
#include<dos.h>             //contains _dos_getdata


      class Leave
      {
	    private: // data member of class
		     int find;                 // variable  ( used by srchlv() member function )
		     FILE *fp,*ft,*fs;         // file pointers

		     struct mydate             // use define data type ( structure )
			{
			 int mm,dd,yy;
			};


		     struct leaves            // use define data type ( structure )
		     {
		       char branch[15];
		       int sem;
		       char rlno[25];
		       char name[20];
		       char reasn[10];
		       struct mydate going;   // nested structure
		     };
		       struct leaves lv;



	    public :



		       Leave()           // its is an user define constructor
		      {
			 clrscr();
			 gotoxy(15,9);
			 cout<<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB";
			 gotoxy(15,10);
			 textbackground(9);
			 textcolor(15);
			 cprintf("\xDB GYAN GANGA INSTITUTE OF TECHNOLOGY AND MANAGEMENT \xDB");
			 gotoxy(15,11);
			 cprintf("\xDB            COMPUTER SCIENCE DEPARTMENT            \xDB");
			 gotoxy(15,12);
			 cprintf("\xDB              LEAVE RECORD MANAGEMENT              \xDB");
			 gotoxy(15,13);
			 cout<<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB";
			 gotoxy(35,25);
			 cout<<"Press Any Key to CONTINU.......";
			 getch();

		      }
		      // member function for class
		      int getdata(int);
		      int checkid();
		      void addlv();
		      void dltlv();
		      void srchlv();
		      void todylv();
		      void allv();
		      void edtlv();
		      void password();
		      void mainmenu();
		      int t(void);
		      void returnfunc();
      };



	    void Leave::returnfunc()  // function for return in main menu ( alllv(),todylv() )
			{
			   {
			     cout<<"Press ENTER to return to MAIN MENU";
			   }
			   a:
			      if(getch()==13)
			      mainmenu();
			      else
			      goto a;
			}

	    int Leave::checkid()
	    {
	      char rlno[25];
	      clrscr();
	      gotoxy(15,5);
	      cout<<"**** Check Enrollment Number ****";
	      gotoxy(15,7);
	      cout<<"Enter Enrollment NO. :-> ";
	      gets(rlno);

	      struct mydate t;
	      struct dosdate_t d;
	      _dos_getdate(&d);
	      t.dd=d.day;
	      t.mm=d.month;
	      t.yy=d.year;

	      fp=fopen("somesh.lv","rb+");
	      rewind(fp);
	      while(fread(&lv,sizeof(lv),1,fp)==1)
	      {
		if(strcmp(rlno,lv.rlno)==0)
		if(t.dd==lv.going.dd && t.mm==lv.going.mm && t.yy==lv.going.yy)
		return 1;
	      }
	      return 0;
	    }


	    int Leave::t(void)         // time function
	    {
	     time_t t;
	     time(&t);
	     printf("\tDate and Time : %s\n",ctime(&t));
	     return 0;
	    }

	    void Leave::password()         // a function for taking password
			{
			 while(1)
			 {
			  clrscr();
			  int i=0,count=0;

			  char pswd[10]={"bunny"};
			  char ch,pass[10];
			  cout<<"\n\n\t ********* Password Protected *********";
			  cout<<"\n\n\t Enter THe Password :->    ";
			      while(ch!=13)
			      {
			       ch=getch();
			       if(ch!=13)
			       {
				putch('*');
				pass[i]=ch;
				i++;
			       }
			       count++;
			       if(count==10)
			       break;
			      }
			      pass[i]='\0';


			       if(strcmp(pass,pswd)==0)
				{
				 printf("\n\n\t");
				 textbackground(2);
				 textcolor(15);
				 cprintf(" Password Matched");
				 textbackground(9);
				 cout<<"\n\n\t press any key to continue . . . .";
				 getch();
				 mainmenu();
				}
				else
				{
				 printf("\n\n\t");
				 textbackground(4);
				 textcolor(15);
				 cprintf(" Sorry Wrong !! Password");
				 textbackground(9);
				 sound(125);
				 delay(200);
				 nosound();
				 cout<<"\n\n\t Press ENTER to rewrite the password";
				 cout<<"\n\n\t PRESS  X  for EXIT ";
				 if(getch()=='x')
				 exit(0);
				 password();
				}
			 }
			}


	    int Leave::getdata(int c)       // function for taking data from user it will call by (addlv) member function
		       {
			  if(c==1)
			  {
			     gotoxy(15,5);
			     cout<<"*** Enter new Imformation Below *** ";
			  }
			  else
			  {
			     gotoxy(15,5);
			     cout<<"*** Enter Imformation Below *** ";
			  }
			     gotoxy(15,7);
			     cout<<"Branch        :  ";
			     gets(lv.branch);
			     gotoxy(15,9);
			     cout<<"Semester      :  ";
			     cin>>lv.sem;
			     gotoxy(15,11);
			     cout<<"Enrollment no :  ";
			     gets(lv.rlno);
			     gotoxy(15,13);
			     cout<<"Name          :  ";
			     gets(lv.name);
			     gotoxy(15,15);
			     cout<<"Reason to go  :  ";
			     gets(lv.reasn);
			     return 1;
		       }

	    void Leave::mainmenu()       // main menu function
			{


			 while(1)
			 {

			  clrscr();
			  cout<<"\n\n\t ******* LEAVE RECORD MANAGEMENT *********";
			  cout<<"\n\n\t --------->>>>> MAIN MENU <<<<<-----------";

			  cout<<"\n\n\t   1. Add New Leave ";
			  cout<<"\n\t   2. Delete Leave  ";
			  cout<<"\n\t   3. Search Leave  ";
			  cout<<"\n\t   4. Edit Leave    ";
			  cout<<"\n\t   5. View Today's leaves";
			  cout<<"\n\t   6. View  All Leaves  ";
			  cout<<"\n\t   7. EXIT FROM PROGRAME     \n\n";

			  t();
			  cout<<"\n\t now enter your choice :  ";


			   switch(getch())
			   {
			     case  1 : addlv();
				       break;

			     case  2 : dltlv();
				       break;

			     case  3 : srchlv();
				       break;

			     case  4 : edtlv();
				       break;


			     case  5 : todylv();
				       break;

			     case  6 : allv();
				       break;

			     case  7 :  clrscr();
					gotoxy(16,3);
					printf("\n\n\t  Programmer....");
					printf("\n\n\t  SOMESH KUMAR MISHRA       ");
					printf("\n\n\t  Mobile:8962616747  E-mail: mishra.somesh47@gmail.com");
					printf("\n\n\t  With  the Unexplainable Help of all TEACHERS");
					printf("\n\n\t  Exiting in 3 seconds...........>");

					delay(3000);
					exit(0);


			     default : cout<<"\n\t  INVALID CHOICE   ";
				       sound(125);
				       delay(200);
				       nosound();
				       getch();
				       mainmenu();

			   }
			 }
			}


	       void Leave::addlv()            // function for adding record
			   {
			     if(checkid()==1)
			     {
			      gotoxy(15,9);
			      cout<<"Record is Already Present";
			      gotoxy(15,11);
			      cout<<"Do you want to modify (y/n)";
			      if(getch()=='y')
			      addlv();
			      else
			      mainmenu();
			     }
			     clrscr();
			     fp=fopen("somesh.lv","ab+");

			     if(getdata(0)==1)
			     {
			      struct dosdate_t d;
			      _dos_getdate(&d);
			      lv.going.dd=d.day;
			      lv.going.mm=d.month;
			      lv.going.yy=d.year;
			      fseek(fp,0,SEEK_END);
			      fwrite(&lv,sizeof(lv),1,fp);
			      fclose(fp);
			      gotoxy(15,17);
			      printf("Going date    :  %d-%d-%d",lv.going.dd,lv.going.mm,lv.going.yy);
			      gotoxy(15,19);
			      cout<<"Record Is Succesfully Saved";
			      gotoxy(15,21);
			      cout<<"Save Any More  ? ( y / n ) : ";
			      if(getch()=='n')
				mainmenu();
			      else
				addlv();
			    }
			   }


      void Leave::dltlv()      // function for delete record
		  {
			      int ch;
			      clrscr();
			      gotoxy(15,8);
			      cout<<"************************************";
			      gotoxy(15,10);
			      cout<<"1. Search by Enrolment no. to Delete";
			      gotoxy(15,12);
			      cout<<"2. Back to MainMenu";
			      gotoxy(15,14);
			      cout<<"************************************";
			      gotoxy(15,16);
			      cout<<"Now Enter your choice  ";
			      cin>>ch;

			switch(ch)
			{

			   case 1:
			   {
			     clrscr();
			     find=0;
			     char d[25];
			     int a=1;
			     while(a)  //infinite loop
			     {
				   find=0;
				   clrscr();
				   gotoxy(10,1);
				   cout<<"***************** Delete Leave Record *****************";
				   gotoxy(15,3);
				   cout<<"Enter the STUDENT ENROLMENT NUMBER : ";
				   gets(d);
				   fp=fopen("somesh.lv","rb+");
				   rewind(fp);
				   while(fread(&lv,sizeof(lv),1,fp)==1)
				   {

					if(strcmp(d,lv.rlno)==0)
					{
					    gotoxy(15,5);
					    printf(" The Student record is available");
					    gotoxy(15,7);
					    printf(" Name            : %s",lv.name);
					    gotoxy(15,9);
					    printf(" semester        : %d",lv.sem);
					    gotoxy(15,11);
					    printf(" Branch          : %s",lv.branch);
					    gotoxy(15,13);
					    printf(" Reason to go    : %s",lv.reasn);
					    gotoxy(15,15);
					    printf(" Going Date      : %d-%d-%d",lv.going.dd,lv.going.mm,lv.going.yy);
					    find=1;
					}
				   }

				   if(find!=1)
				   {
					gotoxy(15,5);
					cout<<"No record is found modify the search (y/n)";
					if(getch()=='n')
					a=0;


				   }

				   if(find==1)
				   {
					gotoxy(15,17);
					cout<<"Do you want to delete it?(Y/N):";
					if(getch()=='y')
					{
					    ft=fopen("test.lv","wb+");  //temporary file for delete
					    rewind(fp);
					    while(fread(&lv,sizeof(lv),1,fp)==1)
					    {
						if(strcmp(d,lv.rlno)!=0)
						{
						    fseek(ft,0,SEEK_CUR);
						    fwrite(&lv,sizeof(lv),1,ft); //write all in tempory file except that
						}                              //we want to delete
					    }
					    fclose(ft);
					    fclose(fp);
					    remove("somesh.lv");
					    rename("test.lv","somesh.lv"); //copy all item from temporary file to fp except that
					    fp=fopen("somesh.lv","rb+");    //we want to delete

					    if(find==1)
					     {
					      gotoxy(15,19);
					      cout<<"The record is sucessfully deleted";
					      gotoxy(15,21);
					      cout<<"Delete another record?(Y/N)";
					     }
					  }
					  else
					  mainmenu();
					  fflush(stdin);
					  if(getch()=='n')
					  a=0;
				   }
			     }

				mainmenu();
			   }


			   case 2:  mainmenu();

			   default: gotoxy(15,18);
				    cout<<" invalid choice ";
				    dltlv();
			}
	    }




	       void Leave::srchlv()        // function for search a record
			   {
			    find=0;
			    clrscr();
			    char d[25];
			    gotoxy(20,8);
			    cout<<"******* Search Leave Record *******";
			    gotoxy(20,10);
			    cout<<"1. Search By Enrolment Number";
			    gotoxy(20,12);
			    cout<<"2. Search By Name";
			    gotoxy(20,14);
			    cout<<"3. Back to MainMenu";
			    gotoxy(20,16);
			    cout<<"***********************************";
			    gotoxy(20,20);
			    cout<<"Enter Your Choice";
			    fp=fopen("somesh.lv","rb+"); //open file for reading propose
			    rewind(fp);   //move pointer at the begining of file
			     switch(getch())
			     {
			       case '1':
			       {
				  clrscr();
				  gotoxy(20,4);
				  cout<<"****Search Leave by Enrolment No. ****";
				  gotoxy(20,6);
				  cout<<"Enter the Sudent Roll No : ";
				  gets(d);
				  gotoxy(20,8);


				 cout<<"Searching ......";
				 delay(3000);


				     while(fread(&lv,sizeof(lv),1,fp)==1)
				     {
					if(strcmp(d,lv.rlno)==0)
					{

					  gotoxy(20,10);
					  cout<<"The Leave Record is available";

					  gotoxy(20,12);
					  printf("Enrolment No  : %s",lv.rlno);
					  gotoxy(20,13);
					  printf("Name          : %s",lv.name);
					  gotoxy(20,14);
					  printf("Semester      : %d ",lv.sem);
					  gotoxy(20,15);
					  printf("Branch        : %s ",lv.branch);
					  gotoxy(20,16);
					  printf("Reason for go : %s",lv.reasn);
					  gotoxy(20,17);
					  printf("Going Date    : %d-%d-%d",lv.going.dd,lv.going.mm,lv.going.yy );

					  find=1;
					}

				     }
				     if(find!=1)  //checks whether conditiion enters inside loop or not
				     {
				       gotoxy(20,10);
				       cout<<"\aNo Record Found";
				     }
				     gotoxy(20,19);
				     cout<<"Try another search?(Y/N)";
				     if(getch()=='y')
				     srchlv();
				     else
				     mainmenu();
				     break;
			       }

			       case '2':
			       {
				  clrscr();
				  gotoxy(20,4);
				  cout<<"**** Search Leave by Name ****";
				  gotoxy(20,6);
				  cout<<"Enter the Sudent Name : ";
				  gets(d);
				  gotoxy(20,8);
				  cout<<"Searching........";
				  delay(3000);
				     while(fread(&lv,sizeof(lv),1,fp)==1)
				     {
					if(strcmp(d,lv.name)==0)
					{
					  delay(2000);
					  gotoxy(20,10);
					  cout<<"The Leave Record is available";

					  gotoxy(20,12);
					  printf("Enrolment No  : %s",lv.rlno);
					  gotoxy(20,13);
					  printf("Name          : %s",lv.name);
					  gotoxy(20,14);
					  printf("Semester      : %d ",lv.sem);
					  gotoxy(20,15);
					  printf("Branch        : %s ",lv.branch);
					  gotoxy(20,16);
					  printf("Reason for go : %s",lv.reasn);
					  gotoxy(20,17);
					  printf("Going Date    : %d-%d-%d",lv.going.dd,lv.going.mm,lv.going.yy );

					  find=1;
					}

				     }
				     if(find!=1)  //checks whether conditiion enters inside loop or not
				     {
				       gotoxy(20,10);
				       cout<<"No Record Found";
				     }
				     gotoxy(20,19);
				     cout<<"Try another search?(Y/N)";
				     if(getch()=='y')
				     srchlv();
				     else
				     mainmenu();
				     break;
			       }


			       case '3': mainmenu();


	default : srchlv();
    }
    fclose(fp);
}


	       void Leave::todylv()     // function for search record by date
			   {

				  struct mydate t;



				  clrscr();
				  gotoxy(20,4);
				  cout<<"****Search Leave by DATE ****";
				  gotoxy(20,6);
				  cout<<"Enter the DATE - MONTH - YEAR =  ";
				  scanf("%d%d%d",&t.dd,&t.mm,&t.yy);
				  gotoxy(20,8);
				  cout<<"Searching........";
				  delay(2000);


					  int j,i=0;
					  clrscr();
					  gotoxy(1,1);
					  cout<<" *******************************LEAVE RECORD LIST******************************";
					  gotoxy(2,2);
					  cout<<" BRANCH       SEMESTER   ENROLMENT     NAME          GOINGDATE    REASON to GO ";
					  j=4;
					  fp=fopen("somesh.lv","rb");
					  rewind(fp);
					  while(fread(&lv,sizeof(lv),1,fp)==1)
					  {
					    if(t.dd==lv.going.dd && t.mm==lv.going.mm && t.yy==lv.going.yy)
					    {
					     gotoxy(3,j);
					     printf("%s",lv.branch);
					     gotoxy(21,j);
					     printf("%d",lv.sem);
					     gotoxy(27,j);
					     printf("%s",lv.rlno);
					     gotoxy(41,j);
					     printf("%s",lv.name);
					     gotoxy(55,j);
					     printf("%d-%d-%d",lv.going.dd,lv.going.mm,lv.going.yy );
					     gotoxy(68,j);
					     puts(lv.reasn);
					     printf("\n\n");
					     i++;
					     j++;
					    }
					  }
					     gotoxy(3,25);
					     cout<<"Total Number of LEAVES -  "<<i;
					     fclose(fp);
					     gotoxy(35,25);
					     returnfunc();






				     if(i==0)
				     {
				       gotoxy(20,10);
				       cout<<"No Record Found";
				       gotoxy(20,12);
				       cout<<"Search another (y/n) ";
				       gotoxy(20,14);
				       cout<<"Press 'n' for MainMenu";
				       if(getch()=='y')
				       todylv();


				     }




			   }





	       void Leave::allv()    // function for to see all records avilable
			   {

			    int j,i=0;
			    clrscr();
			    gotoxy(1,1);
			    cout<<" *******************************LEAVE RECORD LIST******************************";
			    gotoxy(2,2);
			    cout<<" BRANCH       SEMESTER   ENROLMENT     NAME          GOINGDATE    REASON to GO ";
			    j=4;
			    fp=fopen("somesh.lv","rb");
			    while(fread(&lv,sizeof(lv),1,fp)==1)
			     {
			      gotoxy(3,j);
			      printf("%s",lv.branch);
			      gotoxy(20,j);
			      printf("%d",lv.sem);
			      gotoxy(27,j);
			      printf("%s",lv.rlno);
			      gotoxy(41,j);
			      printf("%s",lv.name);
			      gotoxy(55,j);
			      printf("%d-%d-%d",lv.going.dd,lv.going.mm,lv.going.yy );
			      gotoxy(68,j);
			      puts(lv.reasn);
			      printf("\n\n");
			      i++;
			      j++;
			     }

			      gotoxy(3,25);
			      cout<<"Total Number of LEAVES -  "<<i;
			      fclose(fp);
			      gotoxy(35,25);
			      returnfunc();
			   }

       void Leave::edtlv()      //function for edit information about students leave record
       {
	 int ch;
	 clrscr();
	 gotoxy(20,8);
	 cout<<"******* Search Record to edit a Record *******";
	 gotoxy(20,10);
	 cout<<"1.  By Name ";
	 gotoxy(20,12);
	 cout<<"2.  BY ROll NUMBER";
	 gotoxy(20,14);
	 cout<<"3.  Back to Mainmenu";
	 gotoxy(20,16);
	 cout<<"**********************************************";
	 gotoxy(20,18);
	 cout<<"Now Enter your choice";
	 cin>>ch;
	 switch(ch)
	 {
		  case 1:
		  {
		   clrscr();
		   int c=0;
		   int e;
		   char d[25];
		   char another='y';
		   while(another=='y')
		   {
		      clrscr();
		      gotoxy(15,5);
		      cout<<"**** Edit Leave Record ****";
		      gotoxy(15,7);
		      cout<<"Enter the Student Name. : ";
		      gets(d);
		      fp=fopen("somesh.lv","rb+");
		      rewind(fp);
		      while(fread(&lv,sizeof(lv),1,fp)==1)
		      {
			   if(strcmp(d,lv.name)==0)
			   {
				clrscr();
				gotoxy(15,3);
				cout<<"The RECORD is availble";
				if(getdata(1))
				{
				  gotoxy(15,17);
				  printf("Going date    :  %d-%d-%d",lv.going.dd,lv.going.mm,lv.going.yy);
				  gotoxy(15,19);
				  printf("The record is modified");
				  fseek(fp,ftell(fp)-sizeof(lv),0);
				  fwrite(&lv,sizeof(lv),1,fp);
				  fclose(fp);
				  c=1;
				}
			   }

		      }
			    if(c==0)
			    {
				gotoxy(15,9);
				cout<<"No record found";
				gotoxy(15,11);
				cout<<"Want to Search by Another (y/n) ";
				if(getch()=='y')
				edtlv();
				else
				mainmenu();

			    }



			    gotoxy(15,22);
			    cout<<"Modify another Record?(Y/N)";
			    fflush(stdin);
			    gotoxy(15,24);
			    cout<<"Press 'n' for Mainmenu ";
			    if(getch()=='n')
			    mainmenu();

		   }



		  }

		  case 2 :
		  {
		   clrscr();
		   int c=0;
		   int e;
		   char d[25];


		   char another='y';
		   while(another=='y')
		   {
		      clrscr();
		      gotoxy(15,5);
		      cout<<"**** Edit Leave Record ****";
		      gotoxy(15,7);
		      cout<<"Enter the Enrolment NO. : ";
		      gets(d);
		      fp=fopen("somesh.lv","rb+");
		      rewind(fp);
		      while(fread(&lv,sizeof(lv),1,fp)==1)
		      {
			   if(strcmp(d,lv.rlno)==0)
			   {
				clrscr();
				gotoxy(15,3);
				cout<<"The RECORD is availble";
				if(getdata(1))
				{
				  gotoxy(15,17);
				  printf("Going date    :  %d-%d-%d",lv.going.dd,lv.going.mm,lv.going.yy);
				  gotoxy(15,19);
				  cout<<"The record is modified";
				  fseek(fp,ftell(fp)-sizeof(lv),0);
				  fwrite(&lv,sizeof(lv),1,fp);
				  fclose(fp);
				  c=1;
				}
			   }

		      }
			    if(c==0)
			    {
				gotoxy(15,9);
				cout<<"No record found";
				gotoxy(15,11);
				cout<<"Want to Search by Another (y/n) ";
				if(getch()=='y')
				edtlv();
				else
				mainmenu();

			    }



			    gotoxy(15,22);
			    cout<<"Modify another Record?(Y/N)";
			    fflush(stdin);
			    gotoxy(15,24);
			    cout<<"Press 'n' for Mainmenu ";
			    if(getch()=='n')
			    mainmenu();
		   }

		  }

	    case 3 : mainmenu();

	    default : gotoxy(20,20);
		      cout<<" invalid choice ";
		      edtlv();

	 }

       }






	  void main()            // program starts from here main function
	{
	  Leave l1;              // creating object for class  ( user define constructor will call )
	  l1.password();         // object calling member function ( password() )

	  getch();
	}
