//this file is edited
#include <iostream>
#include <conio.h>
#include "Array_h.h"
#include <assert.h>

//yaroslav
using namespace std;

char* CONTINUE = "������� ����� ������� ��� �����������, ESC - �����!";

template <class TypeArray>
int Array <TypeArray>::arrayCount=0;

void input(int& k, const char* n)
{
	while (true)
	{
		cout<<"������� ������ ������� "<<n<<": ";
		ifstream inp("CON");
		inp>>k;
		if (inp.fail() || inp.bad() )
			cout<<"��������� ������ �������!!!!"<<endl;
		else if ( k<1 || k>1000) cout<<"�������� ������ �������!!!"<<endl;
		else break;
	}
}

void main()
{
	setlocale(LC_ALL, "RUS");
	srand((unsigned) time(NULL));
	int asize=0, bsize=0;
	int t=0;
	
	for (;;)
		{
			cout<<"<======test======> #"<< ++t <<endl;
			cout<<"������� 42:"<<endl;
			cout<<"   1) a/b - a, ���� a<b"<<endl;
			cout<<"X= 2) -b ,���� a=b"<<endl;
			cout<<"   3) (a*b-8)/a ,���� a>b"<<endl;
			
			try{
				cout <<"���������� ��������� ������������� �������� = " 
					<< Array<int>::getArrayCount() <<endl;
				input(asize, "a");
				input(bsize, "b");
				//*** �������� ������������� �������� ***
				Array<int> a(asize), b(bsize), X;
				cout <<"� ������ ���������� ��������� �������� = " 
					<< Array<int>::getArrayCount()<< endl;
				if (asize <= 10)
				{
					cout<<"���� ��������� ������� �: "<<endl;
					cin>>a;
				}
				if (bsize <= 10)
				{
					cout<<"���� ��������� ������� b: "<<endl;
					cin>>b;
				}
				if (a==b)
				{
				#ifdef _DEBUG
					cout<<" a=b: X=-b"<<endl;
				#endif // _DEBUG
					X=-b;
				}
				else if (a<b)
				{
				#ifdef _DEBUG
					cout<<" a<b: X=a/b - a"<<endl;
					cout<<" a/b= ";
				#endif // _DEBUG
					X=a/b;
				#ifdef _DEBUG
					cout << X << endl;
				#endif
					X -= a;
				}
				else if (a>b)
				{
				#ifdef _DEBUG
					cout<<" a>b: X = (a*b-8) / a"<<endl;
					cout<<" a*b=  "<<endl;
				#endif // _DEBUG
					X = a*b;
				#ifdef _DEBUG
					cout << X << endl;
					cout<<"X= a*b-8"<<endl;
				#endif // _DEBUG
					X -= 8;
				#ifdef _DEBUG
					cout << X << endl;
					cout<<"X= (a*b-8) / � "<<endl;
				#endif // _DEBUG
					X = X/a;
				}
				cout << "��������� X: " << X << endl;
				
				cout <<"���������� ��������� ������������ �������� = " 
					<< Array<double>::getArrayCount() <<endl;
				Array<double>::getArrayCount();
				asize=0; bsize=0;
				input(asize, "a");
				input(bsize, "b");
				Array<double> aa(asize), bb(bsize), XX;
				cout <<"� ������ ���������� ��������� �������� = " 
					<< Array<double>::getArrayCount()<< endl;
				if (asize <= 10)
				{
					cout<<"���� ��������� ������� �: "<<endl;
					cin>>aa;
				}
				if (bsize <= 10)
				{
					cout<<"���� ��������� ������� b: "<<endl;
					cin>>bb;
				}
				if (aa==bb)
				{
				#ifdef _DEBUG
					cout<<" a=b: X=-b"<<endl;
				#endif // _DEBUG
					XX=-bb;
				}
				else if (aa<bb)
				{
				#ifdef _DEBUG
					cout<<" a<b: X=a/b - a"<<endl;
					cout<<" a/b= ";
				#endif // _DEBUG
					XX = aa/bb;
				#ifdef _DEBUG
					cout << XX << endl;
				#endif
					XX -= aa;
				}
				else if (aa>bb)
				{
				#ifdef _DEBUG
					cout<<" a>b: X = (a*b-8) / a"<<endl;
					cout<<" a*b=  "<<endl;
				#endif // _DEBUG
					XX = aa*bb;
				#ifdef _DEBUG
					cout << XX << endl;
					cout<<"X= a*b-8"<<endl;
				#endif // _DEBUG
					XX -= 8;
				#ifdef _DEBUG
					cout << XX << endl;
					cout<<"X= (a*b-8) / � "<<endl;
				#endif // _DEBUG
					XX = XX/aa;
				}
				cout << "��������� X: " << XX << endl;

				cout<<CONTINUE<<endl;
			}
			catch(char* exc)
			{
				cout<<"������: ����������: "<<exc<< endl;
			}
			catch(...)
			{
				cout<<"������: ��������� �������������� ��������!"<<endl;
			}
			if (_getch() == 27) return;
		}
}