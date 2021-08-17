//8.6 结构体做函数参数
#include<iostream>
using namespace std;
struct stu
{
    int score;
    int age;
};
//值传递：
void print1( stu A) //要用结构体定义的stu数据类型来定义形参
{   A.score=18;
    A.age=90;
    cout<<"进行值传递："<<endl;
    cout<<A.score<<' '<<A.age<<endl;
}
//地址传递：
void print2(struct stu *p) //若采用地址传递，则要用一个指针作为形参接收
{   p->score=18;
    p->age=90;
    cout<<"进行地址传递:"<<endl;
    cout<<p->score<<' '<<p->age<<endl;
}
int main()
{
     stu A={90,18};
     print1(A);
     cout<<"值传递后："<<endl;
     cout<<A.score<<' '<<A.age<<endl;
    print2(&A); //若使用地址传递，则要传入地址（用取址符&）
    cout<<"地址传递后："<<endl;
     cout<<A.score<<' '<<A.age<<endl;
    return 0;
}


// 8.7 结构体中 const使用场景
#include<iostream>
using namespace std;
struct student
{
    int age;
    int score;
};
void print(student *p)
{   
    p->score=100;
    cout<<p->age<<' '<<p->score<<endl;
}
void print2(const student *p)//const使子函数中的变量值只可以读，不可以写。
{   
   // p->score=100; 错误，用const修饰形参之后不可以在子函数中修改变量的值
    cout<<p->age<<' '<<p->score<<endl;
}
int main()
{
    student a={9,8};
    print(&a);
    return 0;
}

// 8.8 案例一
// 学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下:
// 设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员
// 学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师及所带的学生赋值
// 最终打印出老师数据以及老师所带的学生数据。
#include<iostream>
#include<string>
#include<ctime>
using namespace std;
struct student
{
    string name;
    int score;
};
struct teacher
{
    string name;
    struct student arr[5];
};
//创建赋值函数,给学生和老师赋值姓名和成绩
void fuzhi(teacher arr1[],int len)//若传入的为数组，则用类型名+arr1[] （不写其中元素个数的数组）来接收
{   string tn ="教师";
    string sn ="学生";
    string nameseed="ABCDE";//此处定义的string变量可以相加组成新的字符串，也可以以数组形式来调用其中的某个值
                                
    for(int i=0;i<len;i++)     
    {                          
      arr1[i].name=tn+nameseed[i];//上面定义的string变量可以相加组成新的字符串，也可以以数组形式来调用其中的某个值
    //调用数组的值只需要用如：arr[i]. 即可，不需要再写类型名
    for(int j=0;j<5;j++)
    {
        arr1[i].arr[j].name=sn+nameseed[j];
        arr1[i].arr[j].score=rand()%61+40;//随机数的使用如：rand()%50 -----表示随机取0~49之间的数字；
    }                                     //若为rand（）%50+10---表示的是0+10~~49+10 即10~59之间的数字
    }                                     //后面的加号会让取值范围两边都增加相应的数字）
}
//创建打印函数，打印输出对应的值
void print (teacher arr1[],int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<arr1[i].name<<":"<<endl;
        for(int j=0;j<5;j++)
        {
            cout<<"\t姓名："<<arr1[i].arr[j].name<<' '<<"分数："<<arr1[i].arr[j].score<<endl;
        }         //注意:转义符\t 表示tab键（即为退格）
    }
}

int main()
{
    teacher arr1[3];
    int len=sizeof(arr1)/sizeof(arr1[0]);//使用sizeof关键字来求出数组所含元素的个数
    //若需要使每次编译时均有不同的随机数产生，则要写下列代码
    srand((unsigned int)time(NULL)); //设置随机数种子，要写上头文件<ctime>
    fuzhi(arr1,len);
    print(arr1,len);

}



// 8.9 案例二  设计一个英雄的结构体，包括成员姓名，年龄，性别;创建结构体数组，数组中存放5名英雄。
// // 通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。
#include<iostream>
using namespace std;
struct hero
{
    string name;
    int age;
    string sex;
};
void paixu(hero arr[],int len) //冒泡排序
{
    for(int i=0;i<len-1;i++)
    {
        for(int j=0;j<len-1-i;j++)
        {
            if(arr[j].age>arr[j+1].age)
            {
                hero temp=arr[j];//用对应的数据类型来定义中间变量
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
} 
void print(hero arr[],int len)//注意，形参是数组的传递为地址传递
{
    for (int i = 0; i < len; i++)
	{
		cout << "姓名： " << arr[i].name << " 性别： " << arr[i].sex << " 年龄： " << arr[i].age << endl;
	}
}

int main()
{   hero arr[5]
{
        {"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"},

};  
int len =sizeof(arr)/sizeof(arr[0]);
paixu (arr,len);
print(arr,len);

    return 0;
}
