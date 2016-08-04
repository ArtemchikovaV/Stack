//Interpriter 
#include <iostream> 
#include <cmath>
#include <assert.h>
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
	void ProcConstruct( ){ stack = new SStack; stack->StackConstruct( );}		//constructor
	void ProcDestruct( ) { delete stack; stack = NULL; }						//destructor
	void IsOk( ){ assert( stack != NULL ); };									//verification

	void Add( );							//+										
	void Sub( );							//-
	void Mul( );							//*
	void Div( );							//:	
	void Pow( );							//^
	void Sin( );							//sin function
	void Cos( );							//cos function

};

//____________________________________________________
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
void SProcessor::Add( )
{
	double val1 = stack->Pop( );
	double val2 = stack->Pop( );
	stack->Push( val2 + val1 );
}

//-___________________________________________________
void SProcessor::Sub( )
{
	double val1 = stack->Pop( );
	double val2 = stack->Pop( );
	stack->Push( val2 - val1 );
}

//*___________________________________________________
void SProcessor::Mul( )
{
	double val1 = stack->Pop( );
	double val2 = stack->Pop( );
	stack->Push( val2 * val1 );
}

//:___________________________________________________
void SProcessor::Div( )
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
void StackDump( SStack * stack )											//General information
{
	printf("Number of elements: %d\n", stack->top );
	printf("Adress: %x\nStack size: %d\n", stack, sizeof( *stack ));
}

//____________________________________________________
int main()
{
	const char *command = new const char[5];
	double value;
	SProcessor *proc = new SProcessor; 

	proc->ProcConstruct( );
	proc->IsOk( );
	
	scanf("%s", command );
	while ( strcmp( command, "end" ) )
	{
		if ( !strcmp( command, "push" ) )
		{ 
			scanf("%lf", &value ); 
			proc->stack->Push( value );
		}

		if ( !strcmp( command, "pop" ) ) { proc->stack->Pop( );}
		if ( !strcmp( command, "add" ) ) { proc->Add( );}
		if ( !strcmp( command, "sub" ) ) { proc->Sub( );}
		if ( !strcmp( command, "mul" ) ) { proc->Mul( );}
		if ( !strcmp( command, "div" ) ) { proc->Div( );}
		if ( !strcmp( command, "pow" ) ) { proc->Pow( );}
		if ( !strcmp( command, "sin" ) ) { proc->Sin( );}
		if ( !strcmp( command, "cos" ) ) { proc->Cos( );}
		
		scanf("%s", command );		
	}

	StackDump( proc->stack );

	proc->ProcDestruct( );
	delete proc;
	return 0;
}