8.1-8.2 结构体与结构体变量的定义
#include<iostream>
#include<string> //定义string变量的时候必须要加的头文件
using namespace std;
struct abc
{
    int score;
    int age;
    string name;
}A3;    //第三中定义结构体变量的方法，直接写在结构体定义的后边，但不常用
写完struct定义后要加 ；
int main()
{

    struct abc A1={99,18,"a"};//第一种方法，定义时直接就赋值

    abc A2 ;//第二种定义的方法（在定义时可以不用加struct直接用结构体名来定义）
    A2.name="b";//“. + 成员名”的方式来赋值
    A2.score=80;
    A2.age =19;
    
    A3.name="c"; //使用第三种定义变量的方法时，也必须采用“. + 成员名”的方式来赋值
    A3.score=9;
    A3.age =10;
 
 //用“. + 成员名”的方式调用结构体变量对应的成员值。
 cout<<A2.name<<' '<<A1.score<<' '<<A3.age<<endl;
 return 0;
}


8.3 结构体数组
#include<iostream>
using namespace std;
struct abc
{
    int age;
    int score;
}; //定义完结构体之后必须写上分号 ；；；；；
int main()
{   struct abc arr[3]//定义结构体数组时，struct不可以省略
{
{1,8},{9,8},{998,2}
};
for(int i=0;i<3;i++)
{
    cout<<arr[i].age<<' '<<arr[i].score<<endl;
}
cout<<"改变后为："<<endl;
arr[0].age=0;   //用“. + 成员名”的方式来修改结构体数组中的元素对应值        
arr[2].age=0;
for(int i=0;i<3;i++)
{
    cout<<arr[i].age<<' '<<arr[i].score<<endl;
}   //用“. + 成员名”的方式来输出结构体数组中的值

    return 0;
}


8.4 结构体指针
#include<iostream>
using namespace std;
struct abc
{
    int age;
    int score;
};
int main()
{
    struct abc a={9,7};
    struct abc *p =&a;//定义结构体指针：struct abc *p =&a （结构体名 abc不可以省略，a为对应结构体变量名）
    cout<<p->age<<endl;//对于结构体指针来说，用“-> 成员名“来调用变量对应的值
    cout<<p->score<<endl;
    return 0;
}

//8.5 嵌套结构体
#include<iostream>
using namespace std;
//内层结构体先定义
struct student
{ int age;
  int score;
};
struct teacher
{
    int age;
    int id;
    struct student stu; //其中stu为在当前结构体中的成员名，可以通过stu来给
};                      //调用内层结构体中的成员并赋值
int main()
{
    student a9={9,80};
    teacher b;
    b.age=30;
    b.id=9;
    b.stu.age=7;//通过stu来调用student结构体中的成员
    b.stu.score=99;

cout<<b.stu.score<<endl;//嵌套结构体中调用了内部结构体的成员，其仍为当前结构体的一个成员
cout<<a9.score<<endl;
    return 0;
}
