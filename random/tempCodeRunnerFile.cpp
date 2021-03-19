int b=1;
    while(!stk.empty()){
        area=max(area,stk.top()*b);
        b++;
        stk.pop();
    }