//1.3 new与delete运算符
#include<iostream>
using namespace std;
int* func() //此处返回值数据类型是指针
{
    int * a=new int (19);  //用new在堆区开辟空间的语法：new 数据类型（初值）
    return a;           //用new在堆区开辟空间会返回指针（地址），要用指针来接收
}

int main()
{   
    int *p=func();    //重新定义一个指针来接收函数的返回值
    cout<<*p<<endl;    
    cout<<*p<<endl; 
    delete p;   //new开辟空间后一定要用delete手动释放，delete后面直接加主函数中的指针即可
    int *arr=new int[5];//用new在堆中开辟数组，也同样需要定义一个指针来接收
    for(int i=0;i<5;i++)
    {
        arr[i]=i+1; //之前定义的指针名即为 在堆中创建的数组名
    }
    for(int j=0;j<5;j++)
    {
        cout<<arr[j]<<endl;
    }
    delete[] arr; //用delete来释放数组：delete【】数组名
    return 0;
}

//2.1 ~2.5 别名
#include<iostream>
using namespace std;
void swap(int &a,int& b)//别名做函数参数，可以实现地址传递的功能，比指针更加简便
{
    int temp=a;
    a=b;
    b=temp;
}

//注意！局部变量不可以作为返回值，静态变量可以作为返回值
int& abc()
{
    static int a=10;//静态变量可以作为返回值
    return a;
}
int main()
{   int a,b;
    cin>>a>>b;
    swap(a,b);
    cout<<a<<' '<<b<<endl;

    int& c=abc(); //注意！必须定义一个别名来接受返回值（因为返回值类型也是别名！）
    cout<<c<<endl;
    abc()=99; //返回值为引用的函数可以做左值；如果函数做左值，那么必须返回引用
    cout<<c<<endl;

}
