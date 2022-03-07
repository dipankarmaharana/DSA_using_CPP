#include<bits/stdc++.h>
using namespace std;
Stack st{

};

void insert_at_bottom(char x){

    if(st.isEmpty())
        st.push(x);

    else{
        /* All items are held in Function Call Stack until we
           reach end of the stack. When the stack becomes
           empty, the st.size() becomes 0, the
           above if part is executed and the item is inserted
           at the bottom */

        char a = st.peek();
        st.pop();
        insert_at_bottom(x);

        //push all the items held in Function Call Stack
        //once the item is inserted at the bottom
        st.push(a);
    }
    // Execution Order
// char a = st.peek();
// st.pop();
// char a2 = st.peek();
// st.pop();
// char a3 = st.peek();
// st.pop();
// st.push(x);
// st.push(a3);
// st.push(a2);
// st.push(a);
}

int main(){

}