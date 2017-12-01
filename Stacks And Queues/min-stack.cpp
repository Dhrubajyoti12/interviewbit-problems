stack<int>  *dataStack;
stack<int>  *miniStack;

MinStack::MinStack() {
    dataStack = new stack<int>();
    miniStack = new stack<int>();
}
//data: 7 8 9 10 12 13 7 5 9 10

//mini: 7 7 5 

void MinStack::push(int q) {
    dataStack->push(q);
    if(!miniStack->size() or q<=(miniStack->top()) )
        miniStack->push(q);
}

void MinStack::pop() {
    if(!dataStack->size())   return;
    
    int top = dataStack->top();  dataStack->pop();
    if(top == miniStack->top())  miniStack->pop();
}

int MinStack::top() {
    if(!dataStack->size())   return -1;
    return dataStack->top();
}

int MinStack::getMin() {
    if(!dataStack->size())   return -1;
    return miniStack->top();
}

