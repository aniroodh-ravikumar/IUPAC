#include<graphics.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<fstream.h>
#include<time.h>
int c[20]={0};
char pp2[10],sp2[10],rw2[10],ps2[10],ss2[10],direct[]="C:/TC/BGI/";

struct iupac
{
char name[30],pass[30],pp[10],sp[10],rw[10],ps[10],ss[10];
};
int nocarb(char root[])
{if(!strcmpi(root,"meth"))
return 1;
else if(!strcmpi(root,"eth"))
return 2;
else if(!strcmpi(root,"prop"))
return 3;
else if(!strcmpi(root,"but"))
return 4;
else if(!strcmpi(root,"pent"))
return 5;
else if(!strcmpi(root,"hex"))
return 6;
else if(!strcmpi(root,"benz"))
return 6;
else if(!strcmpi(root,"hept"))
return 7;
else if(!strcmpi(root,"oct"))
return 8;
else if(!strcmpi(root,"non"))
return 9;
else if(!strcmpi(root,"dec"))
return 10;
else return 0;
}
void unsat(char ps[])
{
int pos;
char ps2[30];
strcpy(ps2,ps);
if(isalpha(ps2[0]))
pos=0;
else if(isdigit(ps2[0]))
{
pos=ps2[0]-49;
for(int i=0;i<strlen(ps2)-2;i++)
ps2[i]=ps2[i+2];
ps2[strlen(ps2)-2]='\0';
}

if(strcmp(ps2,"en")==0||strcmp(ps2,"ene")==0)
{setcolor(4);}
if(strcmp(ps2,"yn")==0||strcmp(ps2,"yne")==0)
{setcolor(1);}
line(c[2*pos],c[2*pos+1],c[2*pos+2],c[2*pos+3]);
setcolor(7);
}


void fun(char ss[],char pp[])
{
char pp2[30],ss2[30];
strcpy(pp2,pp);
strcpy(ss2,ss);
settextstyle(0,HORIZ_DIR,2);
int fpos,ppos;

if(strcmpi(ss2,"0")!=0)
{
if(isalpha(ss2[0]))
fpos=0;
else if(isdigit(ss2[0]))
{
fpos=ss2[0]-49;
for(int i=0;i<strlen(ss2)-2;i++)
ss2[i]=ss2[i+2];
ss2[strlen(ss2)-2]='\0';
}

int y=c[2*fpos+1]+(c[2*fpos+1]-c[2*fpos+3])/2;
int x=c[2*fpos]+(c[2*fpos]-c[2*fpos+2])/2;
setcolor(10);
line(c[2*fpos],c[2*fpos+1],x,y);
setcolor(7);
moveto(x,y);
if(strcmpi(ss2,"al")==0||strcmpi(ss2,"one")==0)
{
setcolor(4);
line(c[2*fpos],c[2*fpos+1],x,y);
setcolor(7);
outtext("O");
}
if(strcmpi(ss2,"ol")==0)
outtext("OH");
if(strcmpi(ss2,"amine")==0)
outtext("NH2");
}

//PREFIX
if(strcmpi(pp2,"0")!=0)
{
if(isalpha(pp2[0]))
ppos=0;
else if(isdigit(pp2[0]))
{
ppos=pp2[0]-49;
for(int i=0;i<strlen(pp2)-2;i++)
pp2[i]=pp2[i+2];
pp2[strlen(pp2)-2]='\0';
}
int y=c[2*ppos+1]+(c[2*ppos+1]-c[2*ppos+3])/2;
int x=c[2*ppos]+(c[2*ppos]-c[2*ppos+2])/2;
setcolor(10);
line(c[2*ppos],c[2*ppos+1],x,y);
setcolor(7);
moveto(x,y);
if(strcmpi(pp2,"chloro")==0)
outtext("Cl");
if(strcmpi(pp2,"Bromo")==0)
outtext("Br");
if(strcmpi(pp2,"Iodo")==0)
outtext("I");
if(strcmpi(pp2,"Fluoro")==0)
outtext("F");
if(strcmpi(pp2,"Nitro")==0)
outtext("NO2");
if(strcmpi(pp2,"Methoxy")==0)
outtext("OCH3");
if(strcmpi(pp2,"Ethoxy")==0)
outtext("OC2H5");
if(strcmpi(pp2,"Propoxy")==0)
outtext("OC3H7");
if(strcmpi(pp2,"Methyl")==0)
outtext("CH3");
if(strcmpi(pp2,"Ethyl")==0)
outtext("C2H5");
if(strcmpi(pp2,"Propyl")==0)
outtext("C3H7");
}
}
void copy(int a[20],int b[20])
{
for(int i=0;i<20;i++)
a[i]=b[i];
}
void prop()
{int gd=DETECT,gm,points[20]={200,200,300,200,250,287,200,200};
initgraph(&gd,&gm,direct);
copy(c,points);
drawpoly(4,points);
}
void but()

{int gd=DETECT,gm,points[20]={200,200,300,200,300,300,200,300,200,200};
initgraph(&gd,&gm,direct);
drawpoly(5,points);
copy(c,points);
}

void pent()
{int gd=DETECT,gm,points[20]={200,200,250,113,300,200,300,300,200,300,200,200};
initgraph(&gd,&gm,direct);
drawpoly(6,points);
copy(c,points);
}
void hex()
{int gd=DETECT,gm,points[20]={200,200,287,150,373,200,373,300,287,350,200,300,200,200};
initgraph(&gd,&gm,direct);
drawpoly(7,points);
copy(c,points);
}
void oct()
{int gd=DETECT,gm,points[20]={200,200,270,130,370,130,440,200,440,300,370,370,270,370,200,300,200,200};
initgraph(&gd,&gm,direct);
drawpoly(9,points);
copy(c,points);
}

void draw(char pp[],char sp[],char rw[],char ps[],char ss[],int n)
{
int noc=0;
if(strcmpi(sp,"cyclo")==0)
{

if(strcmpi(rw,"prop")==0)
{prop();}
else if(strcmpi(rw,"but")==0)
{but();}
else if(strcmpi(rw,"pent")==0)
{pent();}
else if(strcmpi(rw,"hex")==0)
{hex();}
else if(strcmpi(rw,"oct")==0)
{oct();}
else
{outtextxy(0,0,"Invalid name");
return;}
unsat(ps);
fun(ss,pp);

}

//STRAIGHT CHAINS
else if(strcmpi(sp,"0")==0)
{

int gd=DETECT,gm;
initgraph(&gd,&gm,direct);
moveto(200,200);
if(strcmpi(rw,"meth")==0)
{
outtext("C");
c[0]=200;
c[1]=200;
}
else if(strcmpi(rw,"eth")==0);
else if(strcmpi(rw,"prop")==0);
else if(strcmpi(rw,"but")==0);
else if(strcmpi(rw,"pent")==0);
else if(strcmpi(rw,"hex")==0);
else if(strcmpi(rw,"hept")==0);
else if(strcmpi(rw,"oct")==0);
else if(strcmpi(rw,"non")==0);
else if(strcmpi(rw,"dec")==0);
else if(strcmpi(rw,"benz")==0)
{
hex();
circle(287,250,50);
}
else
{
outtextxy(0,0,"Invalid name");
return;
}
noc=nocarb(rw);
if(isdigit(pp[0]))
if(pp[0]-49>noc)
{
outtextxy(0,0,"Invalid name");
getch();
return;
}

if(isdigit(ss[0]))
if(ss[0]-49>noc)
{outtextxy(0,0,"Invalid name");
getch();
return;
}
int x=200,y=200;
if(strcmpi(rw,"benz"))
{
for(int i=0;i<noc-1;i++)
{
c[2*i]=x;c[2*i+1]=y;
x+=50;
if(i%2==0)
{y-=50;
linerel(50,-50);
}
else
{y+=50;
linerel(50,50);
}
}
if(noc>1)
{
c[2*i]=getx();
c[2*i+1]=gety();
i++;
c[2*i]=getx()+50;
if(i%2==0)
c[2*i+1]=gety()-50;
else
c[2*i+1]=getx()+50;
unsat(ps);
}
}
}
fun(ss,pp);
if(n==1)
{settextstyle(0,HORIZ_DIR,0);
outtextxy(0,400,"Enter the primary prefix,secondary prefix, root word, primary suffix");
outtextxy(0,420,"and secondary suffix");
moveto(500,0);
gets(pp2);gets(sp2);gets(rw2);gets(ps2);gets(ss2);
}
getch();
closegraph();
restorecrtmode();
}


void main()
{
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,direct);
settextstyle(0,HORIZ_DIR,4);
outtextxy(30,200,"IUPAC Nomenclature");
settextstyle(0,HORIZ_DIR,0);
outtextxy(400,400,"Press any key to continue");
getch();
closegraph();
clrscr();
iupac obj;
char pp[30],sp[30],rw[30],ps[30],ss[30],ch,name[30],choice,sam;
int pos,fpos,ppos,ct=0,n,k,a;
setlinestyle(0,0,10);
ifstream f("IUPAC.dat");
ofstream g("IUPAC.dat",ios::app);
 if(!f)
 {cout<<"Error";
 getch();
 return;}
cout<<"Do you want to login as a guest(g) or as a user(u)"<<endl;
cin>>ch;

if(ch=='u')
{
cout<<"enter your name";
cin>>name;
cout<<endl<<endl;
cout<<"Welcome "<<name<<endl<<endl;
while(f.read((char*)&obj,sizeof(obj)))
{
if(strcmpi(obj.name,name)==0)
{cout<<obj.pp<<' '<<obj.sp<<' '<<obj.rw<<' '<<obj.ps<<' '<<obj.ss<<endl<<endl;
ct++;}
}
if(ct>0)
cout<<"These are your previous records"<<endl<<endl;
}
if(ch=='g')
cout<<endl<<"Welcome guest"<<endl;
getch();


do
{
clrscr();
cout<<"Enter your choice: 1.Learn IUPAC nomenclature"<<endl;
cout<<"2.Display the structure of a given compound"<<endl;
cout<<"3.Play a quiz game"<<endl;
cout<<"4.Exit"<<endl<<endl;
cin>>n;
clrscr();
if(n==1)
{
char buf[2000];
cout<<"1.Basic naming rules \n2.Unsaturation and cyclic compounds \n3.Naming of functional groups"<<endl;
cin>>k;
if(k==1)
{ ifstream l("iupac2.txt");
while(l.getline(buf,2000,'$'))
{cout<<buf;
getch();}
l.close();}
if(k==2)

{ ifstream l("iupac3.txt");
while(l.getline(buf,2000,'$'))
{cout<<buf;
getch();}
l.close();}
if(k==3)
{ ifstream l("iupac4.txt");
while(l.getline(buf,2000,'$'))
{cout<<buf;
getch();}
l.close();}

}
if(n==2)
{iupac obj1;
cout<<"Enter the primary prefix,sec. prefix,root word,prim suffix,sec suffix"<<endl;
cout<<"Primary prefix is the function group that is prefixed"<<endl;
cout<<"Secondary prefix \"cyclo\" is used for cyclic compounds(except benzene)"<<endl;
cout<<"Root word is the number of carbons(meth,eth.prop.etc"<<endl;
cout<<"Primary suffix is the degree of unsaturation(ane,ene,yne"<<endl;
cout<<"Secondary suffix is the function group that is suffixed"<<endl;
cout<<"If any of these are not there in the name, enter 0"<<endl;
gets(obj1.pp);gets(obj1.sp);gets(obj1.rw);gets(obj1.ps);gets(obj1.ss);
clrscr();
draw(obj1.pp,obj1.sp,obj1.rw,obj1.ps,obj1.ss,0);
if(ch=='u')
{strcpy(obj1.name,name);
g.write((char*)&obj1,sizeof(obj1));}
}
if(n==3)
{
randomize();
char pp1[15][15]={"Chloro","Bromo","Iodo","Fluoro","Nitro","Methoxy","Ethoxy","Propoxy","Methyl","Ethyl","Propyl"};//11
char sp1[15][15]={"0","cyclo"};//2
char rw1[15][15]={"Benz","Eth","Hept","Prop","But","Pent","Hex","Oct","Non"};//9
char ps1[15][15]={"yne","ene","ane"};//3
char ss1[15][15]={"one","ol","amine"};//3
int i=4+random(6),j=random(9),rootrand;
char ppos[2]=" ",spos[2]=" ",unsatpos[2]=" ";
strcpy(sp,sp1[random(2)]);

if(!strcmpi(sp,"cyclo"))
strcpy(rw,rw1[i]);
else
strcpy(rw,rw1[j]);
strcmpi(sp,"0")==0?rootrand=0:rootrand=1;

ppos[0]=random(nocarb(rw)-rootrand)+49;
spos[0]=random(nocarb(rw)-rootrand)+49;
if(ppos[0]==spos[0])
ppos[0]+=1;

unsatpos[0]=random(nocarb(rw)-1)+49;

if(random(11))
{
strcpy(pp,ppos);
strcat(pp,"-");
strcat(pp,pp1[random(10)]);
}
else strcpy(pp,"0");

if(random(4))
{
strcpy(ss,spos);
strcat(ss,"-");
strcat(ss,ss1[random(3)]);
if(!strcmpi(ss,"one")&&spos[0]=='1')
strcpy(ss,"1-al");
}
else strcpy(ss,"0");

if(!strcmpi(rw,"benz"))
strcpy(ps,"ene");
else
{
if(!random(3))
strcpy(ps,"ane");
else
{strcpy(ps,unsatpos);
strcat(ps,"-");
strcat(ps,ps1[random(2)]);
}
}
draw(pp,sp,rw,ps,ss,1);
clrscr();
if(!(strcmpi(pp,pp2))&&!(strcmpi(sp,sp2))&&!(strcmpi(rw,rw2))&&!(strcmpi(ps,ps2))&&!(strcmpi(ss,ss2)))
cout<<"Correct"<<endl;
else
{cout<<"Incorrect"<<endl;
 cout<<"Correct answer:  "<<pp<<' '<<sp<<' '<<rw<<' '<<ps<<' '<<ss<<' '<<endl;}
getch();
}
clrscr();
}while(n!=4);
f.close();
g.close();
getch();
}