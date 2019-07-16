struct Stack 
{
	int top;
	unsigned capacity;
	int *array;
};
void print_stack(struct Stack* stack);
int equal(struct Stack* first, struct Stack* second);
struct Stack* createStack(int capacity);
int isfull(struct Stack* stack);
void push(struct Stack* stack, int item);
int isempty(struct Stack* stack);
int pop(struct Stack* stack);