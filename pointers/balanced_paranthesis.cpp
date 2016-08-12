    #include <iostream>
    int number_of_balenced_par(int n){
    int count=0;
    int i=1;
    int k;
    while(1){
    k=1;
    while(1){
    if((i+(k<<1)+1)<=n)
    count++;
    else
    break;
    k++;
    }
    i++;
    if(i+3>n)
    break;
    }
    return count;
    }
    int main(){
    int n=4;
    std::cout<<number_of_balenced_par(n)<<"\n";
    }
