#include "list.h"
using namespace std;

int main()
{
    //This variable is essentially your Linked List
    node * head = NULL;

    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned

	cout << "Number of even numbers: " << countEven(head) << '\n' << endl;
	cout << "Number to be removed: " << findSecondFinal(head) << '\n' << endl;
	removeSecondFinal(head);
	
    //You may place extra calls to display to help with debugging
    display(head);
    destroy(head);
    
    return 0;
}
