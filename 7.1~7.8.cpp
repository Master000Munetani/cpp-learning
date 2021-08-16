//7-1 ~ 7-2
//1、基本格式：int * p= &a;
//2、指针存放的是地址
//3、通过解引用（*p）来调用指向对象的值

//7-5 const修饰指针
#include<iostream>
using namespace std;
int main()
{
    int a=10;
    int b=20;

    const int *p1=&a;//常量指针
    p1 =&b;    //（正确，指针的指向可以修改）
    //*p1=9;  (错误，指针常量不可修改指向的值)

    int * const p2=&b;
    *p2 =8;  //(正确，指向的值可以修改)
    //p2 =&a;   (错误，指针指向不可以修改)

    const int * const p3=&a;
    //均不可修改



    return 0;
}

//7-6  指针与函数  ---利用指针访问数组中的元素
#include<iostream>
using namespace std;
int main()
{
    int arr[4]={1,2,3,8};
    int *p;
    p=arr;  //数组名即为数组的首地址，可以直接将指针指向它  (或者可用 int *p=arr 指向数组)
    for(int i=0;i<4;i++)
    {

        cout<<p[i]<<' '; //方法一：将已经指向数组arr[]的指针p直接用 p[]的形式来调用数组中的对应元素

        cout<<*p<<' ';  //方法二：（p已经指向了arr[0]）,直接*p 调用值,然后将其自加（p++）使所指向元素向后移一位
        //注意：一定要用 *p 解引用来调用指向的数值
        p++;
    }


    return 0;
}


//7.7 指针和函数---------利用指针作函数参数，可以修改实参的值
#include<iostream>
using namespace std;
void swap(int *p1,int * p2)
{
    int temp=*p1;
    *p1=*p2;
    *p2=temp;
}
int main()
{
    int a=10;
    int b=20;
     cout<<"a="<<a<<' '<<"b="<<b<<endl;

    swap(&a,&b);

    cout<<"a="<<a<<' '<<"b="<<b<<endl;


    return 0;
}

//7.8 案例练习：封装一个函数，利用冒泡排序，实现对整型数组的升序排序
#include<iostream>
using namespace std;
void paixu(int *p,int len)  //利用指针作函数参数，可以修改实参的值(传入的实参为数组时依然会改变)
{                           //此处为一个利用地址传递的冒泡排序
    for(int i=0;i<len-1;i++)
    {for(int j=0;j<len-i-1;j++)
        if(p[j]>p[j+1])
        {
            int temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;

        }
    }
}
void print(int p[],int len) //注意此处还应该传入数组的长度len
{
    for(int i=0;i<len;i++)
    {
        cout<<p[i]<<' ';
    }
    cout<<endl;
}
int main()
{int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
    int len=sizeof(arr)/sizeof(arr[0]); //用sizeof()关键字相除来求数组中元素个数
    print(arr,len);                     //sizeof(数组名)：整个数组的长度  sizeof(arr[i]):数组中第i+1个元素所占空间
    paixu(arr,len);
    print(arr,len);

return 0;
}
