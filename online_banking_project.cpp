#include<iostream>
#include<string.h>
#include<fstream>
float acb=1000;
using namespace std;
class Banking{
int pin;
char pnno[100];
	char dct[100];      
	int c,i;
	int ch3,ch4;
	char fn[30],ln[30];
	string pn[50];
	 char email_id[50],dob[10],g[10],pd[100],lpd[100],uid[100];
   string phn;
   	char sqa[50],sqn[100];
	int sch;
	int ch,ch2,dj,mj,yj,dr,mr,yr,nt;
	
	public:
		void login(){
	/*cout<<"email id="<<email_id<<"and passwrd:"<<pd<<endl;*/
	cout<<"ENTER THE FOLLOWING DETAILS:"<<endl;
	cout<<"USERNAME OR EMAIL-ID:";
	cin>>uid;
	cout<<"PASSWORD:";
	cin>>lpd;
	if((strcmp(uid,email_id)==0)&&(strcmp(lpd,pd)==0)){
		cout<<"login sucessfully:";
		bankpage();
	}
	else{
	cout<<"wrong password";	
	}	
}
	void signup(){
	   	cout<<"ENTER THE FOLLOWING DETAILS:"<<endl;
		cout<<"First name:";
		cin>>fn;
		cout<<"last name:";
		cin>>ln;
		cout<<"E-MAIL ID:";
		cin>>email_id;
		cout<<"DOB(dd-mm-yy):";
		cin>>dob;
         gender1();
         cout<<"PHONE NO:";
         cin>>pnno;
          ofstream phn;
         phn.open("phone.txt",ios::out);
         phn<<pnno;
         phn.close();
         cout<<"CREATE PASSWORD:(password should be atleast 6 character long)";
         cin>>pd;
         cout<<"ENTER YOUR ATM PIN:";
         cin>>pin;
         ofstream p;
         p.open("atmpin.txt",ios::out);
         p<<pin;
         p.close();
         cout<<"\n\n\n\t\t\tTHANK YOU FOR REGISTRATION :-) "<<endl;         		
		}
void gender1(){
	int c;
	cout<<"GENDER:\t1.Male\t2.Female\tchoose(1 or 2):";
	cin>>c;
	if(c==1){
	strcpy(g,"MALE");
	}
	else if(c==2){
		strcpy(g,"FEMALE");
	}
	else{
	cout<<"WRONG CHOICE:---ENTER AGAIN PROPERLY\n";
	gender1();
    }
}
  void show(){
	cout<<"YOUR DETAILS:"<<endl;
	cout<<"NAME:"<<fn<<ends<<ln<<endl;
	cout<<"Email id :"<<email_id<<endl;
	cout<<"dob:"<<dob<<endl;
	cout<<"gender:"<<g<<endl;
	cout<<"phone number:"<<phn<<endl;
	
}
void bankpage(){
	int cho,be;
	int opin,npin;
float da,wa;
	cout<<"\n1.VIEW PROFILE \t2.ACCOUNT BALANCE\t3.CASH WITHDRWAL\t4.ADD CASH\t5.PIN CHANGE\t6.BALANCE TRANSFER";
	cout<<"\nchoice:";
	cin>>cho;
	if(cho==1){
	cout<<"YOUR DETAILS:"<<endl;
	cout<<"NAME:"<<fn<<ends<<ln<<endl;
	cout<<"Email id :"<<email_id<<endl;
	cout<<"dob:"<<dob<<endl;
	cout<<"gender:"<<g<<endl;
	    ifstream ph_n;
         ph_n.open("phone.txt",ios::in);
         ph_n>>pnno;;
         ph_n.close();
	cout<<"phone number:"<<pnno<<endl;
	cout<<"\n\nDO YOU WANT TO GO BACK OR EXIT...1)BACK\t2)EXIT\n";
	cin>>be;
	if(be==1){
		bankpage();
	}
	else{
		exit(0);
	}
	}
	else if(cho==2){
		cout<<"YOUR ACCOUNT BALANCE: RS.";
	ifstream abc;
	abc.open("balance.txt");
	abc>>acb;
	abc.close();
	cout<<acb;
    cout<<"\n\nDO YOU WANT TO GO BACK OR EXIT...1)BACK\t2)EXIT\n";
	cin>>be;
	if(be==1){
		bankpage();
	}
	else{
		exit(0);
	}
	}
	else if(cho==3){
		cout<<"AMOUNT TO BE WITHDRAWL:";
		cin>>wa;
		acb=acb-wa;
		cout<<"NEW ACCOUNT BALANCE IS:"<<acb;
	  ofstream ab;
	ab.open("balance.txt");
	ab<<acb;
	ab.close();
		cout<<"PLEASE COLLECT YOUR CASH:-)\n";
		cout<<"\n\nDO YOU WANT TO GO BACK OR EXIT...1)BACK\t2)EXIT\n";
	cin>>be;
	if(be==1){
		bankpage();
	}
	else{
		exit(0);
	}
	}
	else if(cho==4){
		cout<<"AMOUNT TO BE DEPOSIT:";
		cin>>da;
		acb=acb+da;
		cout<<"NEW ACCOUNT BALANCE IS:"<<acb;
	  ofstream ab;
	ab.open("balance.txt");
	ab<<acb;
	ab.close();
		cout<<"\n:-)\n";
		cout<<"\n\nDO YOU WANT TO GO BACK OR EXIT...1)BACK\t2)EXIT\n";
	cin>>be;
	if(be==1){
		bankpage();
	}
	else{
		exit(0);
	}
	}
	else if(cho==5){
		cout<<"ENTER YOUR OLD PIN:";
		cin>>opin;
	    ifstream atm_pin;
         atm_pin.open("atmpin.txt",ios::out);
         atm_pin>>pin;
         atm_pin.close();
		
		if(opin==pin){
			cout<<"ENTER YOUR NEW PIN:";
			cin>>npin;
			ofstream new_pin;
         new_pin.open("atmpin.txt",ios::out);
        new_pin<<npin;
         new_pin.close();
         cout<<"*******NEW PIN SET SUCESSFULLY*****";
         	cout<<"\n\nDO YOU WANT TO GO BACK OR EXIT...1)BACK\t2)EXIT\n";
         	cin>>be;
        	if(be==1){
	             	bankpage();
	                 }
	           else{
		           exit(0);
	           }
		}
		
	else{
	cout<<"******YOUR ENTERED WRONG PIN******";
	exit(0);	
	}
	}
	else if(cho==6){
		float nam;
		cout<<"\nAMOUNT TO BE TRANSFER:";
		cin>>nam;
		acb=acb-nam;
		cout<<"NEW ACCOUNT BALANCE IS:"<<acb;
	  ofstream ba;
	ba.open("balance.txt");
	ba<<acb;
	ba.close();
		
	}
	else{
		cout<<"\n\n*******WRONG INPUT!!!********";
	}

}

};
int main(){
	Banking B;
	int ch;
	cout<<"****WELCOME TO ONLINE BANKING SYSTEM*****\n\n\n";
	cout<<"1.LOGIN\t\t2.SIGNUP\n";
	cout<<"choice:";
	cin>>ch;
	if(ch==1){
		ifstream a;
		a.open("banklogin.txt",ios::in);
		a.read((char *)&B,sizeof(B));
	    B.login();
	    a.close();
		
		
	}
	else{
		B.signup();
		ofstream b;
	b.open("banklogin.txt");
	b.write((char *)&B,sizeof(B));
	b.close();		
	}
	ofstream ab;
	ab.open("balance.txt");
	ab<<acb;
	ab.close();
  return 0;	
}
