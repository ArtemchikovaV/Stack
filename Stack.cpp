//Interpriter 
#include <iostream> 
using std::cout;
using std::cin;
using std::endl; 
#include <string>
using std::string;
#include <cmath>
#include <cassert>
#include <stdio.h>

const int SIZE = 10;

struct SStack
{
	unsigned int top;	
	double data[SIZE];

	void StackConstruct() { top = 0;}			//constructor
	void StackDestruct() { top = 0; }			//destructor

	double Pop( );
	void Push( double value );

};

struct SProcessor
{
	SStack *stack;																//Stack structure
	void ProcConstruct( ) { stack = new SStack; stack->StackConstruct( );}		//constructor
	void ProcDestruct( ) { delete stack; stack = NULL; }						//destructor

	void add( );							//+										
	void sub( );							//-
	void mul( );							//*
	void div( );							//:	
	void Pow( );							//^
	void Sin( );							//sin function
	void Cos( );							//cos function
};

void StackDump( SStack *stack );			//Stack general information
bool IsOk( SStack *stack );					//Stack verification

void SStack::Push( double value )
{
	if ( top == (SIZE - 1))
	{
		printf("Warning!Stack is full.\n");
		return;
	}
	data[ top ] = value;
	++top;
}

//____________________________________________________
double SStack::Pop( )
{
	double value = -9999.0;
	if ( top != 0) 
	{
		value = data[ top - 1 ];
		--top;
	}
	else printf( "Warning!Stack is empty.\n");
	return value;
}

//+___________________________________________________
void SProcessor::add( )
{
	double val1 = stack->Pop( );
	double val2 = stack->Pop( );
	stack->Push( val2 + val1 );
}

//-___________________________________________________
void SProcessor::sub( )
{
	double val1 = stack->Pop( );
	double val2 = stack->Pop( );
	stack->Push( val2 - val1 );
}

//*___________________________________________________
void SProcessor::mul( )
{
	double val1 = stack->Pop( );
	double val2 = stack->Pop( );
	stack->Push( val2 * val1 );
}

//:___________________________________________________
void SProcessor::div( )
{
	double val1 = stack->Pop( );
	double val2 = stack->Pop( );
	stack->Push( val2 / val1 );
}

//^___________________________________________________
void SProcessor::Pow( )
{
	double val1 = stack->Pop( );
	double val2 = stack->Pop( );
	stack->Push( pow( val2,val1 ) );
}

//sin___________________________________________________
void SProcessor::Sin( )
{
	double val = stack->Pop( );
	stack->Push( sin(val) );
}

//cos___________________________________________________
void SProcessor::Cos( )
{
	double val = stack->Pop( );
	stack->Push( cos(val) );
}


//____________________________________________________
void StackDump( SStack *stack )											//General information
{
	printf("Adress: %x\nStack size: %d\n", stack, sizeof( *stack ));
	//cout << "Number of elements:	" << stack->top << endl;
	//cout << "Adress:	" << stack << endl;
	//cout << "Stack size:	" << sizeof( *stack ) << endl;
	cout << "Number of elements:	" << stack->top << endl;
}

//____________________________________________________
bool IsOk( SStack *stack )
{
	if ( stack == NULL )
	{
		return false;
	}
	else 
		return true;
}

//____________________________________________________
int main()
{
	char *command;
	double value;
	SProcessor *proc = new SProcessor; 
	proc->ProcConstruct( );

	cin >> command;
	while ( command != "end" )
	{
		
		if ( command == "push" ) { cin >> value; proc->stack->Push( value );}
		if ( command == "pop" ) { proc->stack->Pop( );}
		if ( command == "add" ) { proc->add( );}
		if ( command == "sub" ) { proc->sub( );}
		if ( command == "mul" ) { proc->mul( );}
		if ( command == "div" ) { proc->div( );}
		if ( command == "pow" ) { proc->Pow( );}
		if ( command == "sin" ) { proc->Sin( );}
		if ( command == "cos" ) { proc->Cos( );}
		
		cin >> command;		
	}

	StackDump( proc->stack );
	proc->ProcDestruct( );
	delete proc;
	return 0;
}