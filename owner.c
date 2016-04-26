/*��student.c�ļ�����������*/
#include"owner.h"
#include<stdio.h>

int readOwn(Owner *own,int n)             /*���복����¼ֵ�����ƺ�Ϊ0������涨������¼ʱֹͣ*/
{
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("Input one owner\'s information\n");
		printf("num: ");
		scanf("%ld",&own[i].num);
		if(own[i].num==0) break;
		printf("name: ");
		scanf("%s",own[i].name);
		printf("sex: ");
		scanf("%s",own[i].sxe);
		own[i].total=0;               /*��ͣ��ʱ����Ҫ������ã���ֵ��Ϊ0*/
		printf("Input ten scores of the owner:\n");
		for(j=0;j<10;j++)
		{
			scanf("%d",&own[i].time[j]);
		}
	}
	return i;                      /*����ʵ�ʶ���ļ�¼����*/
}

void printOwn ( Own *own , int n)       /*�������ѧ����¼��ֵ*/
{
    int i,j;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", own[i].num);
		printf("%8s", own[i].name);
		printf("%8s", own[i].sex);
		for (j=0;j<10;j++)
		   printf("%6d",own[i].time[j]);
	    printf("%7d",own[i].total);
	    printf("%5d\n",stu[i].fee);
	}
}

int equal(Owner s1,Owner s2,int condition)  /*����ж�����Owner��¼���*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚϳ��ƺ�*/
		return s1.num==s2.num;
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚ�����*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*�������condition��ֵΪ3����ȽϷ���*/
	     return s1.fee==s2.fee;
 else if (condition==4)                /*�������condition��ֵΪ4����Ƚ���ͣ��ʱ��*/
		return s1.total==s2.total;
	else return 1;                       /*�����������1*/
} 

void calcuTotal(Owner own[],int n)         /*�������г�������ͣ��ʱ��*/
{
	int i,j;
	for (i=0;i<n;i++)                    /*���ѭ���������г�����¼*/
	{
		own[i].total =0;
		for (j=0;j<10;j++)               /*�ڲ�ѭ������ͣ������*/
			own[i].total +=own[i].time[j];
	}	
}

void cacluTimetable(double m[1][3],Owner Own[],int n);              /*��ͣ���������̡�ƽ��ʱ��*/
                       /*������ʽ������ά����m�ĵ�һά����ͣ���������ڶ�ά���������̡�ƽ��ʱ��*/
{
	int i,j;
	for (i=0;i<10;i++)                 /*��ͣ�����ʱ��*/		
	{ 
		m[i][0]=own[0].time[i];     
		for (j=1;j<n;j++)
			if (m[i][0]<own[j].time[i])
				m[i][0]=own[j].time[i];
	}
	for (i=0;i<10;i++)                  /*��ͣ�������ʱ��*/
	{ 
		m[i][1]=own[0].time[i];      
		for (j=1;j<n;j++)
			if (m[i][1]>own[j].time[i])
				m[i][1]=own[j].time[i];
	}
	for (i=0;i<10;i++)                 /*��ͣ����ƽ��ʱ��*/
	{ 
		m[i][2]=own[0].time[i];     
		for (j=1;j<n;j++)
			m[i][2]+=own[j].time[i];
		m[i][2]/=n;
	}
}

int searchOwn(Owner own[],int n,Owner s,int condition,int f[ ])            /*��stu��������condition��������*/
                                    /*��s��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
		if (equal(own[i],s,condition))  
		{
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/                              
		}
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/ 
}