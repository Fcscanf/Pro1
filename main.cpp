#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cfloat>
#include <list>
#include <set>
#include <map>
#include <iterator>
#include <vector>
#include <valarray>
#include <algorithm>
#include <functional>
#include "module1/Mouh.h"
#include "module2/Stock.h"
#include "module3/FcTime.h"
#include "module4/vector.h"
#include "module5/queue.h"
#include "module6_extends/tabtenn.h"
#include "module7_polymorphism/brass.h"
#include "module9_dynamic_memory_allocation_friend_inheritance/dma.h"
#include "module10_code_reuse/workermi.h"
// #include "module11_class_template/stacktp.h"
#include "module11_class_template/pointer_stack/stcktp.h"
#include "module11_class_template/arrry/arraytp.h"
#include "module11_class_template/multiple_type_parameters/pairs.h"
#include "module12_friend_class/tv.h"
#include "module13_nesting/template_nesting/queuetp.h"
#include "module14_error/error_class/exc_mean.h"
#include "module14_error/stack_resolution/stack_resolution.h"
#include "module17_stl/functor/functor.h"

// 常量的定义
#define INT_MAX 59964

// 通过限定符来定义常量
const int MONTHS = 12;

// 无符号类型的定义
//      一般整型不能存储负数值的无符号变体，其优点是可以增大变量能够存储的最大值，例如short表示范围为-32768到+32767
//      则无符号版本的表示范围为0-65535，当然，仅当数值不会为负时才应使用无符号类型，如入口，微粒
unsigned int rovert;

using namespace std;

double test(double i){
    double x = sqrt(i);
    return x;
}

void forcedTypeConversion(int i){
    // 强制类型转换
    char y = (char) i;
    char x = char(i);
}

void useString(string i){
    cout << i.append("str") << endl;
}

// -----------------------------------结构体---------------------------------------

// 结构的使用
struct person{
    string name;
    int age;
};

// 定义结构体时创建结构体变量以及赋值
struct student{
    string name;
} ky = {"ky"};

// 定义没有名称的结构体同时定义变量
struct {
    string name;
} brid;

// 定义结构体变量时可以省略结构体关键字struct
struct person p = {"str", 18};
person person1;

// 结构体中的位字段
//  C++也允许指定占用特定位数的结构成员，这使得创建与某个硬件设备上的寄存器对应的数据结构非常方便。
//  字段的类型应为整型或枚举，接下来是冒号，冒号后面是一个数字，它指定了使用的位数。可以使用没有名称的字段来提供间距
//  每个成员都被称为位字段（bit field）
// 位字段通常用在低级编程中
struct torgle_register{
    unsigned int SN : 4;
    unsigned int : 4;
    bool goodIn: 1;
    bool goodTorgle: 1;
};

// ------------------------------共用体和匿名共用体-----------------------------------

// 共用体union
//      共用体是一种数据格式，它能够存储不同的数据类型，但只能同时存储其中的一种类型。
//          结构体可以同时存储int、long和double
//          共用体只能存储int、long或double,条件是在不同的时间进行
//      用于共用体每次只能存储一个值，因此它必须有足够的空间来存储最大的成员，所以，共用体的长度为其最大成员的长度
//  共用体的用途:当数据项使用两种或更多格式（但不会同时使用）时，可节省空间。
//          例如，假设管理一个小商品目录，其中有一些商品的ID为整数，而另一些ID为字符串，这种情况下可以使用共用体
union one4all{
    int int_val;
    int long long_val;
    double double_val;
};

//  匿名共用体anonymous union没有名称
//  其成员位于相同地址处的变量。每次只有一个成员是当前的成员
struct widget{
    char brand[20];
    int type;
    union {
        long id_num;
        char id_char[20];
    };
};

// ------------------------------------枚举----------------------------------------

// 枚举类型
//  枚举量：默认情况下会将整数值赋值给枚举量，第一个枚举量为0，第二个枚举量为1···，通过指定的整数值覆盖默认值
enum spectrum{
    red, orange, yellow, green, blue, violet, indigo, ultraviolet
};

spectrum band;
int color = 3 + band;

// 设置枚举变量的值
// 可以使用赋值操作来显式地设置枚举量的值
enum bits{
    one = 1,
    two = 2,
    four = 4,
    eight = 8
};

// 指定的值必须是整数，也可以只显式地定义其中一些枚举量的值
// 这里first在默认情况下为0，后面没有被初始化的枚举变量的值将比其前面的枚举量大1，因此third的值为101
enum bigstep{
    first, second = 100, third
};

// 创建多个值相同的枚举量
// 其中zero和null都为0，one_c和umero_uno都为1
enum {
    zero, null = 0, one_c, numero_nuo = 1
};

// ----------------------------------指针-------------------------------------
void pointer(){
    int updates = 6;
    int * p_updates;
    p_updates = & updates;
    cout << "Value:updates = " << updates << endl;
    cout << "*p_updates = " << *p_updates << endl;
    cout << "Address:&updates = " << &updates << endl;
    cout << "p_updates = " << p_updates << endl;
    // 程序输出：
    //    Value:updates = 6
    //    *p_updates = 6
    //    Address:&updates = 0xffffcbd4
    //    p_updates = 0xffffcbd4
    // int变量updates和指针变量p_updates只不过是一枚硬币的两面。变量updates表示值，并使用&操作符来获得地址；
    // 而变量p_updates表示地址，并使用*操作符来取值，由于p_updates指向updates，因此*p_updates和updates
    // 完全等价。可以像使用int变量那样使用*p_updates。

    // 指针的定义-*号操作符两边的空格是可选的
    int *ptr;
    int* psr;
    // 每个指针变量的创建都需要一个*,下面的例子将创建一个指针p1和一个int变量p2
    int *p1, p2;

    // 使用new关键字为指针分配内存
    // 在C语言中可以使用库函数malloc()来分配内存，在C++中还有更好的方法——使用new操作符
    int *pt = new int;

    // 内存耗尽
    // 计算机可能会由于没有足够的内存而无法满足new的请求，在这种情况下，new将返回0,在C++中，值为0分指针
    // 被称为空指针null pointer，C++确保空值指针不会指向有效的数据，因此它常被用来表示操作符或函数失效，
    // 如果成功，将返回一个有用的指针。

    // 使用delete来释放内存
    //  当需要内存时，可以使用new来请求，这只是C++内存管理数据包中有魅力的一个方面。另一个方面是delete操作符，
    // 它使得在使用完内存后，能够将其归还给内存池，这是通向最有效地使用内存的关键一步。归还或释放free的内存可供
    // 程序的其他部分使用。使用delete时，后面要加上指向内存块的指针（这些内存块最初是用new分配的）
    // **注意：只能用delete来释放使用new分配的内存。不过对空指针使用DELETE是安全的。

    // 这将释放ps指向的内存，但不会删除指针ps的本身，例如，可以将ps重新指向另一个新分配的内存块，一定要配对
    // 地使用new和delete。否则程序将发生内存泄露memory leak，也就是说，被分配的内存再也无法使用了；如果
    // 内存泄露严重，则程序将由于不断寻找更多内存而终止
    int *p3 = new int;
    delete p3, pt;

    // 不要尝试释放已经释放的内存块，C++标准指出，这样做的结果将是不确定的，这意味着什么情况都可能发生。另外
    // 不能使用delete来释放声明变量所获得的内存；
    // int *p4 = new int;
    // delete p4;
    // delete p4;           //not ok now，不能重复释放已经释放的内存块
    // int jugs = 5;
    // int *p5 = &jugs;
    // delete p5;           //不能delete来释放声明变量所获得的内存；

    // **注意，使用delete的关键在于，将他用于new分配的内存，这并不意味着要使用用于new的指针，而是用于new的地址
    // 一般来说，不要创建两个指向同一个内存块的指针，因为这将增加错误地删除同一个内存块两次的可能性
    // int *p6 = new int;
    // int *p7 = p6;
    // delete = p6;

    // 使用new创建动态数组
    // 在C++中，创建动态数组很容易，只要将数组的元素类型和元素数目告诉new即可，必须在类型名后加上[]，其中包含元素数目
    int *psome = new int[10];
    // new操作符返回第一个元素的地址，在这个例子中，该地址被赋给指针psome，当程序结束后，应使用DELETE释放

    // 指针数组的使用
    psome[0] = 0;
    psome[1] = 2;
    psome[2] = 3;
    cout << "psome[0] = " << psome[0] << endl;
    cout << "psome[1] = " << psome[1] << endl;
    cout << "psome[2] = " << psome[2] << endl;
    // psome[0] = 0
    // psome[1] = 2
    // psome[2] = 3

    psome = psome + 1;
    cout << "psome[0] = " << psome[0] << endl;
    cout << "psome[1] = " << psome[1] << endl;
    // psome[0] = 2
    // psome[1] = 3

    // 指针返回到开始
    psome = psome - 1;
    // 不能修改数组名的值，但指针是变量，因此可以修改他们的值。将psome + 1的效果，表达式psome[0]现在指向的是
    // 数组的第二个值，因此将psome + 1导致它指向第二个元素而不是第一个。将它减一后，指针将指向原来的值

    // 在释放new创建的动态数组时，应使用另一种格式的delete，它能够指出所要释放的是一个数组
    // []会告诉程序，应释放整个数组，而不仅仅是指针指向的元素
    delete[] psome;

    // 使用new和delete时，应遵守以下规则：
    // 1、不要使用delete来释放不是new分配的内存
    // 2、不要使用delete释放同一个内存两次
    // 3、如果使用new []为数字分配内存，则应使用delete[]来释放
    // 4、如果使用new []为一个实体分配内存，则应使用delete来释放
    // 5、对空指针应用delete是安全的

    // 将指针变量加一后，其增加的值等于指向类型占用的字节数
    // stacks[1]可以看作是* (stacks + 1)，这意味着先计算第二个元素的地址，然后找到存储在那里的值。
    // 最后输出存储在那里的值。

    char flower[10]= "rose";
    cout << flower << endl;
    cout << &flower << endl;
}

// 动态结构
void structure(){

    struct things{
        int good;
        int bad;
    };

    things grubonse = {3, 453};
    things *pt = &grubonse;

    // 如果结构体标识符是结构名，则使用句点操作符
    // 如果标识符是指向结构的指针，则使用箭头操作符
    cout << "ps.good = " << pt->good << endl;
    cout << "ps.bad = " << pt->bad << endl;

    // 使用new创建结构体变量
    person *person2 = new person;
    person2->name = "fc";
    person2->age = 18;
    cout << "person2.name = " << person2->name << endl;
    cout << "person2.age = " << person2->age << endl;

    // 释放使用new创建的动态结构的空间
    delete person2;
}

void input(){
    string string1;
    // 将输入的字符串读入到变量中。不过该操作将忽略空格、换行和制表符
    cin >> string1;
    // 可以通过调用成员函数将返回下一个输入字符——包括空格、换行和制表符
    string1 = cin.get();

}

void fileoperation(string filename){
    // 文件写入相关操作
    ofstream outFile;
    outFile.open("info.txt");
    outFile << fixed;
    outFile << "Make and model" << endl;
    outFile << "Year" << endl;
    outFile.close();

    // 文件读取操作
    ifstream inFile;
    inFile.open(filename);
    if (!inFile.is_open()){
        cout << "Could not open the file" << filename << endl;
    }

    string value;
    inFile >> value;
    if (inFile.eof())
        cout << "End of file reached;" << endl;
    else if (inFile.fail())
        cout << "Input terminated by data mismatch." << endl;
    else
        cout << "Input terminated for unknown reason." << endl;

    inFile.close();

}

// 定义指针函数
// 指针函数声明时需要将*和函数名括起来，括号优先级比*操作符高，因此*fun (int)代表返回指针的函数，
// 而(*fun) (int)意味着fun是一个指向函数的指针
double pam(int);
double (*pf) (int);
// 指针函数的赋值,将pam函数的地址赋给pf，赋值函数和指针函数的返回值类型编写相同才能赋值
// pf = pam;
// 指针函数的调用
//double x = pam(3);
//double y = (*pf)(5);

// 内联函数
// 内联函数声明前加上关键字inline
// 内联函数占用内存大，但运行速度快
inline double square(double x){
    return x * x;
}

// 引用变量
// 使用类型标识符，int &指向int的引用,rodents和rats指向相同的值和内存单元
void referenceVariable(){
    int rats;
    //int *rodents = &rats;
    int & rodents = rats;
    rats = 10;
    cout << "rats Value is : " << rats << endl;
    cout << "rats Address is : " << &rats << endl;
    cout << "rats Value is : " << rodents << endl;
    cout << "rats Address is : " << &rodents << endl;
    // rats Value is : 10
    // rats Address is : 0xffffcbc4
    // rats Value is : 10
    // rats Address is : 0xffffcbc4
}

// 函数模板的定义
//template <class Any>
template <typename Any>
void Swap(Any &a, Any &b){
    Any temp;
    temp = a;
    a= b;
    b = temp;
}

// 重载的模板
template<class Any>
void Swap(Any *a, Any *b, int n);
void Show(int a[]);
const int Lim = 8;

template<class Any>
void Swap(Any a[], Any b[], int n){
    Any temp;
    for (int i = 0; i < n; i++) {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

void Show(int a[]){
    cout << a[0] << a[1] << endl;
    cout << a[2] << a[3] << endl;
    for (int i = 4; i < Lim; ++i) {
        cout << a[i];
    }
    cout << endl;
}

// 模板实例化
// 隐式实例化
template void Swap<int> (int &, int &);
// 显示实例化
//template <> void Swap<int>(int &, int &);
//template <> void Swap(int &, int &);

void useTemSwap(){
    int i = 10, j = 20;
    cout << "i, j =" << i << "," << j << endl;
    Swap(i, j);
    cout << "i, j =" << i << "," << j << endl;
    double n = 5.0;
    double m = 10.0;
    cout << "n, m =" << n << "," << m << endl;
    Swap(n, m);
    cout << "n, m =" << n << "," << m << endl;

    int d1[Lim] = {0, 7, 0, 4, 1, 7, 7, 6};
    int d2[Lim] = {0, 6, 2, 0, 2, 9, 6, 9};
    cout << "Original arrays: \n";
    Show(d1);
    Show(d2);
    Swap(d1, d2, Lim);
    cout << "Swapped arrays: \n";
    Show(d1);
    Show(d2);
}

// 判断结果格式化输出
void coutFormat(){

    // 命名空间的使用
    std::cout << "Hello, World!" << std::endl;
    cout << "Hello, My Girls" << endl;
    double x = sqrt(9);
    cout << x << endl;
    cout << p.name << endl;
    cout << ky.name << endl;
    cout << color << endl;

    cout << "The expression x = 100 has the value ";
    // ()的优先级高于<<，则会先对x赋值100
    cout << (x = 100) << endl;
    cout << "The expresion x < 3 has the value ";
    cout << (x < 3) << endl;
    // The expresion x < 3 has the value 0
    cout << "The expresion x > 3 has the value ";
    cout << (x > 3) << endl;
    // The expresion x > 3 has the value 1
    // 设置判断结果的布尔值输出
    cout.setf(ios_base::boolalpha);
    cout << "The expresion x < 3 has the value ";
    cout << (x < 3) << endl;
    // The expresion x < 3 has the value false
    cout << "The expresion x > 3 has the value ";
    cout << (x > 3) << endl;
    // The expresion x > 3 has the value true
}

// 对象数组的使用
//void ObjectArray(){
//    Stock stock = Stock{};
//
//    // 对象数组-要创建对象数组，则这个类必须有默认构造函数
//    Stock stuff[4] = {
//            Stock("NanoSmart", 12.5, 20),
//            Stock("Boffo Objects", 200, 2.0),
//            Stock("Monolithic Obelisks", 130, 3.24),
//            Stock("Fleep EnterPrices", 60, 6.5)
//    };
//    stuff[0].update(23.0);
//    stuff[3].show();
//    Stock tops = stuff[2].topval(stuff[1]);
//}

// 类的使用以及友元函数的使用
void friendFunction(){
    FcTime aida(3, 25);
    FcTime tosca(2, 48);
    FcTime temp;

    cout << "Aida and Tosca:\n";
    cout << aida << "; " << tosca << endl;
    temp = aida + tosca;
    cout << "Aida + Tosca" << endl;
    temp = aida * 1.17;
    cout << "Aida * 1.17: " << temp << endl;
    cout << "Tosca * 10: " << 10 * tosca << endl;
}

// 使用Vector类模拟随机行走
void randwalk(){
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double dstep;
    double target;
    cout << "Enter target distance(q to quit): ";
    while (cin >> target) {
        cout << "Enter step length: ";
        if (!(cin >> dstep)) {
            break;
        }
        while (result.magval() < target){
            direction = rand()%360;
            step.set(dstep, direction, 'p');
            result = result + step;
            steps++;
        }
        cout << "After " << steps << " steps, the subject has the following location: \n";
        cout << result << endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step = " << result.magval()/steps << endl;
        steps = 0;
        result.set(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
}

// 队列类
const int MIN_PER_HR = 60;
bool newcustomer(double x);
bool newcustomer(double x){ return rand()*x / RAND_MAX < 1;}

void bank(){
    cout << "Case Study:Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;

    cout << "Enter the average number of customers per hour: ";
    double perhour;
    cin >> perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour;

    Item temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    long line_wait = 0;

    for (int cycle = 0; cycle < cyclelimit; cycle ++){
        if (newcustomer(min_per_cust)){
            if (line.isfull())
                turnaways++;
            else{
                customers++;
                temp.set(cycle);
                line.enqueue(temp);
            }
        }
        if (wait_time <= 0 && !line.isempty()){
            line.dequeue(temp);
            wait_time = temp.ptime();
            line_wait += cycle = temp.when();
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.queuecount();
    }
    if (customers >0){
        cout << "customers accepted: " << customers << endl;
        cout << "customers served: " << served << endl;
        cout << "turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout.setf(ios_base::showpoint);
        cout << (double)sum_line/cyclelimit << endl;
        cout << "average wait time: " << (double)line_wait/served << " minutes\n";
    } else
        cout << "No customers!\n";
    cout << "Done!\n";
}

// 派生类
void usett(){
    TableTennisPlayer player1("Chuck", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);
    RatedPlayer ratedPlayer(1140, "Mallory", "Duck", true);
    ratedPlayer.Name();
    if (ratedPlayer.HasTable()) {
        cout << ":has a table.\n";
    }else{
        cout << ":has't a table.\n";
    }
    player1.Name();
    if (player1.HasTable()) {
        cout << ":has a table.\n";
    } else{
        cout << ":has't a table.\n";
    }
    player2.Name();
    if (player2.HasTable()) {
        cout << ":has a table.\n";
    } else{
        cout << ":has't a table.\n";
    }
    cout << "Name: ";
    ratedPlayer.Name();
    cout << ":Rating: " << ratedPlayer.Rating() << endl;
    RatedPlayer ratedPlayer1(1221, player1);
    cout << "Name: ";
    ratedPlayer1.Name();
    cout << ":Rating :" << ratedPlayer1.Rating() << endl;
}

// 多态公有继承
void useBrass(){
    Brass Piggy("Procelot Pigg", 381299, 4000.00);
    BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
    Piggy.ViewAcct();
    cout << endl;
    Hoggy.ViewAcct();
    cout << endl;
    cout << "Depositing $1000 into the Hogg Account: \n";
    Hoggy.Deposit(1000.00);
    cout << "New balance: $ " << Hoggy.Balance() << endl;
    cout << "Withdrawing $4200 from the Pigg Account:\n";
    Piggy.Withdraw(4200.00);
    cout << "Pigg account balance: $ " << Piggy.Balance() << endl;
    cout << "Withdrawing $4200 from the Hogg Account:\n";
    Hoggy.Withdraw(4200.00);
    Hoggy.ViewAcct();
}

// 抽象类的应用
void usedma(){
    baseDMA shirt("Portabelly", 8);
    lacksDMA balloon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);
    cout << shirt << endl;
    cout << balloon << endl;
    cout << map << endl;
    lacksDMA balloon2(balloon);
    hasDMA map2;
    map2 = map;
    cout << balloon2 << endl;
    cout << map2 << endl;
}

// 代码的重用，私有继承，多重继承
const int SIZE_M = 5;
void workmi(){
    Worker * lolas[SIZE_M];
    int ct;
    for (ct = 0; ct < SIZE_M; ct++) {
        char choise;
        cout << "Enter the employee category:\n"
        << "w: waiter s: singer t: singing waiter q: quit\n";
        cin >> choise;
        while (strchr("wstq", choise) == NULL) {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choise;
        }
        if (choise == 'q')
            break;
        switch (choise) {
            case 'w': lolas[ct] = new Waiter;
                break;
            case 's': lolas[ct] = new Singer;
                break;
            case 't': lolas[ct] = new SingingWaiter;
                break;
        }
        cin.get();
        lolas[ct]->Set();
    }

    cout << "\nHere is your sraff:\n";
    int i;
    for (i = 0; i < ct; i++) {
        cout << endl;
        lolas[i]->Show();
    }
    for  (i = 0; i < ct; i++)
        delete lolas[i];
    cout << "Bye.\n";
}

// 使用模板类
void useTemplateClass(){
    Stack<string> st;
    char ch;
    string po;
    cout << "Please enter A to add a purchase order, \n" << "P to process a PO, or to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q') {
        while (cin.get() != '\n') {
            continue;
        }
        if (!isalpha(ch)) {
            cout << '\a';
            continue;
        }
        switch (ch){
            case 'A':
            case 'a': cout << "Enter a PO number to add: ";
            cin >> po;
            if (st.isfull())
                cout << "Stack already full\n";
            else
                st.push(po);
            break;
        case 'P':
        case 'p': if (st.isempty())
            cout << "Stack already empty\n";
            else{
                st.pop(po);
                cout << "PO #" << po << " popped\n";
                break;
            }
        }
        cout << "Please enter A to add a purchase order ,\n" << "P to process a PO , or Q to quit.\n";
    }
    cout << "Bye\n";

}

// 正确使用指针堆栈
const int Num = 10;
void usePointerStack(){
    srand(time(0));
    cout << "Please enter stack size: ";
    int stacksize;
    cin >> stacksize;
    Stack<const char *> st(stacksize);
    const char * in[Num] = {
            "1:Hank Gilgamesh", "2:Kiki Ishtar", "3:Betty Rocker", "4:Ian Flagranti",
            "5:Wolfgang Kibble", "6:Portia Koop", "7:Joy Almonda", "8:Xaverie Paprika",
            "9:Juan Moore", "10:Misha Mache"
    };
    const char * out[Num];
    int processed = 0;
    int nextin = 0;
    while (processed < Num) {
        if (st.isempty()) {
            st.push(in[nextin++]);
        } else if(st.isfull())
            st.pop(out[processed++]);
        else if (rand()%2 && nextin < Num)
            st.push(in[nextin++]);
        else
            st.pop(out[processed++]);
        for (int i = 0; i < Num; i++)
            cout << out[i] << endl;
        cout << "Bye\n";
    }
}

// 数组模板的使用
void useArrayTemplate(){
    ArrayTP<int, 10> sums;
    ArrayTP<double , 10> aves;
    ArrayTP<ArrayTP<int, 5>, 10> twodee;
    int i, j;
    for (int i = 0; i < 10; i++) {
        sums[i] = 0;
        for (int i = 0; i < 5; i++) {
            twodee[i][j] = (i + 1)*(j + 1);
            sums[i] += twodee[i][j];
        }
        aves[i] = (double)sums[i] / 10;
    }
    for (int i = 0; i < 10; i++) {
        for (int i = 0; i < 5; i++) {
            cout.width(2);
            cout << twodee[i][j] << ' ';
        }
        cout << " :sum = ";
        cout.widen(3);
        cout << sums[i] << ", average = " << aves[i] << endl;
    }
    cout << "Done.\n";
}

// 多个类型参数
void useMultipleTypeParameter(){
    Pair<string, int> rating[4] = {
            Pair<string, int>("The Purple Duke", 5),
            Pair<string, int>("Jake's Frisco AI Fresco", 4),
            Pair<string, int>("Mont Souffle", 5),
            Pair<string, int>("Gertie's Eats", 3)
    };
    int joints = sizeof(rating) / sizeof(Pair<string, int>);
    cout << "Rating :\t Eatery\n";
    for (int i = 0; i < joints; i++) {
        cout << rating[i].second() << ":\t" << rating[i].first() << endl;
        cout << "Oops! Revised rating :\n";
        rating[3].first() = "Gertie's Fab Eat";
        rating[3].second() = 6;
        cout << rating[3].second() << ":\t" << rating[3].first() << endl;
    }
}

// 友元类的使用
void useFriendClass(){
    Tv s27;
    cout << "Initial setting for 27\" TV:\n";
    s27.setting();
    s27.onoff();
    s27.chanup();
    cout << "\nAdjusted setting for 27\" TV:\n";
    s27.setting();

    Remote grey;
    grey.set_chan(s27, 10);
    grey.volup(s27);
    grey.volup(s27);
    cout << "\n27\" settings after using remote:\n";
    s27.setting();

    Tv s32(Tv::On);
    s32.set_mode();
    grey.set_chan(s32, 28);
    cout << "\n32\" setting:\n";
    s32.setting();
}

// 嵌套类的使用
void useNestClass(){
    QueueTP<string> cs(5);
    string temp;

    while (!cs.isfull()) {
        cout << "Please enter your name. You will be served in the order of arrival.\n name: ";
        getline(cin, temp);
        cs.enqueue(temp);
    }
    cout << "The queue is full. Processing bedins!\n";

    while (!cs.isempty()) {
        cs.dequeue(temp);
        cout << "Now processing " << temp << "...\n";
    }
}

// ***********************************异常**************************************
// 调用abort处理异常
double hmean(double a, double b){
    if (a == -b) {
        throw "bad hmean() arguments: a = -b not allowed!";
//        cout << "untenable argument to hmean()\n";
//        abort();
    }
    return 2.0 * a * b / (a + b);
}

void errorOne(){
    double x, y, z;
    cout << "Enter two numbers: ";
    while (cin >> x >> y) {
        z = hmean(x, y);
        cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
        cout << "Enter next set of numbers <q to quit>: ";
    }
    cout << "Bye!\n";
}

// 返回错误码
bool hmean(double a, double b, double *ans);

bool hmean(double a, double b, double *ans){
    if (a == -b) {
        *ans = DBL_MAX;
        return false;
    } else{
        *ans = 2.0 * a * b / (a + b);
        return true;
    }
}

void errorCode(){
    double x, y, z;
    cout << "Enter two numbers: ";
    while (cin >> x >> y) {
        if (hmean(x, y, &z))
            cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
        else
            cout << "One value should not be the negative of the other - try again.\n";
        cout << "Enter next set of numbers <q to quit>: ";
    }
    cout << "Bye!\n";
}

// ------------------------------------捕获异常-----------------------------------
void errorTryCatch(){
    double x, y, z;
    cout << "Enter two numbers: ";
    while (cin >> x >> y) {
        try {
            z = hmean(x, y);
        }catch (const char * s) {
            cout << s << endl;
            cout << "Enter a new pair of number: ";
            continue;
        }
        cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
        cout << "Enter next set of numbers <q to quit>: ";
    }
    cout << "Bye!\n";
}

// function proptotypes
double hmeans(double a, double b) throw (bad_hmean);
double gmeans(double a, double b) throw (bad_gmean);

double hmeans(double a, double b) throw (bad_hmean){
    if (a == -b)
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}

double gmeans(double a, double b) throw (bad_gmean){
    if (a < 0 || b < 0) {
        throw bad_gmean(a, b);
    }
    return sqrt(a * b);
}

void useErrorClass(){
    double x, y, z;
    cout << "Enter two numbers: ";
    while (cin >> x >> y) {
        try {
            z = hmeans(x, y);
            cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y << " is " << gmeans(x, y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }catch (bad_hmean & bg) {
            bg.mesg();
            cout << "Try again.\n";
            continue;
        }catch (bad_gmean & hg) {
            cout << hg.mesg();
            cout << "Values used: " << hg.v1 << ", " << hg.v2 << endl;
            cout << "Sorry , you don't get to play any more.\n";
            break;
        }
    }
    cout << "Bye!\n";
}

// ************************************STL**************************************
// -----------------------------------分配器-----------------------------------
const int NUM = 5;
void useVector(){
    vector<int> rating(NUM);
    vector<double > titles(NUM);
    cout << "You will do ecactly as told. You will enter\n" << NUM << "book titles and your rating(0-10).\n";
    for (int i = 0; i < NUM; i++) {
        cout << "Enter title # " << i + 1 << ": ";
        cin >> titles[i];
        cout << "Enter your rating (0-10): ";
        cin >> rating[i];
        cin.get();
    }
    cout << "Thank you. You entered the following: \n" << "Rating\tBook\n";
    for (int i = 0; i < NUM; i++) {
        cout << rating[i] << "\t" << titles[i] << endl;
    }
}

// STL函数的用法
struct Review{
    string title;
    int rating;
};

bool operator<(const Review & r1, const Review & r2);
bool worseThan(const Review & r1, const Review & r2);
bool FillReview(Review & rr);
void ShowReview(const Review & rr);

bool operator<(const Review & r1, const Review & r2){
    if (r1.title < r2.title)
        return true;
    else if (r1.title == r2.title && r1.rating < r2.rating)
        return false;
    else
        return false;
}

bool worseThan(const Review & r1, const Review & r2){
    if (r1.rating < r2.rating)
        return true;
    else
        return false;
}

bool FillReview(Review & rr){
    cout << "Enter book title(quit to quit): ";
    getline(cin, rr.title);
    if (rr.title == "quit")
        return false;
    cout << "Enter book rating: ";
    cin >> rr.rating;
    if (!cin)
        return false;
    cin.get();
    return true;
}

void ShowReview(const Review & rr){
    cout << rr.rating << "\t" << rr.title << endl;
}


void stlFunction(){
    vector<Review> books;
    Review temp;
    while (FillReview(temp))
        books.push_back(temp);
    cout << "Thanks ,you entered the following " << books.size() << " rating:\n" << "Rating\tBook\n";
    for_each(books.begin(), books.end(), ShowReview);
    sort(books.begin(), books.end());
    cout << "Sorted by title : \nRating\tBook\n";
    for_each(books.begin(), books.end(), ShowReview);
    sort(books.begin(), books.end(), worseThan);
    cout << "Sorted by rating : \nRating\tBook\n";
    for_each(books.begin(), books.end(), ShowReview);
    cout << "Bye.\n";
}

// 迭代器
void useIterator(){
    int casts[10] = {6, 7, 2, 9, 4, 11, 8, 7, 10, 5};
    vector<int > dice(10);
    // copy from to vector
    copy(casts, casts + 10, dice.begin());
    cout << "Let the dice be cast!\n";
    // create an ostream iterator
    ostream_iterator<int ,char> out_iter(cout, " ");
    // copy from vector to output
    copy(dice.begin(), dice.end(), out_iter);
    cout << endl;
    cout << "Implict use of reverse iterator.\n";
    copy(dice.rbegin(), dice.rend(), out_iter);
    cout << endl;
    cout << endl;
    cout << "Implicit use of reverse iterator.\n";
    vector<int >::reverse_iterator ri;
    for (ri = dice.rbegin(); ri != dice.rend(); ++ri)
        cout << *ri << ' ';
    cout << endl;
}

// insert
void iteratorInsert(){
    string s1[4] = {"fine", "fish", "fashion", "fate"};
    string s2[2] = {"busy", "bats"};
    string s3[2] = {"silly", "singers"};
    vector<string> words(4);
    copy(s1, s1 + 4, words.begin());
    ostream_iterator<string, char> out(cout, " ");
    copy(words.begin(), words.end(), out);
    cout << endl;

    // construct anonymous back_insert_iterator object
    copy(s2, s2 + 2, back_insert_iterator<vector<string>>(words));
    copy(words.begin(), words.end(), out);
    cout << endl;

    // construct anonymous back_insert_iterator object
    copy(s3, s3 + 2, insert_iterator<vector<string>>(words, words.begin()));
    copy(words.begin(), words.end(), out);
    cout << endl;
}

// List的相关操作
void useList(){
    int stuff[5] = {1, 2, 4, 8, 6};
    list<int> two;
    two.insert(two.begin(), stuff, stuff + 5);
    int more[6] = {6, 4, 2, 4, 6, 5};
    list<int> three(two);
    three.insert(three.end(), more, more + 6);

    cout << "List two: ";
    ostream_iterator<int , char> out(cout, " ");
    copy(two.begin(), two.end(), out);
    cout << endl << "List three: ";
    copy(three.begin(), three.end(), out);
    three.remove(2);
    cout << endl << "List three minus 2s: ";
    copy(three.begin(), three.end(), out);
    three.splice(three.begin(), two);
    cout << endl << "List three after splice: ";
    three.unique();
    cout << endl << "List three after unique: ";
    copy(three.begin(), three.end(), out);
    three.sort();
    three.unique();
    cout << endl << "List three after sort & unique: ";
    copy(three.begin(), three.end(), out);
    two.sort();
    three.merge(two);
    cout << endl << "Sorted two merged into three: ";
    copy(three.begin(), three.end(), out);
    cout << endl;
//    运行结果
//    List two: 1 2 4 8 6
//    List three: 1 2 4 8 6 6 4 2 4 6 5
//    List three minus 2s: 1 4 8 6 6 4 4 6 5
//    List three after splice:
//    List three after unique: 1 2 4 8 6 1 4 8 6 4 6 5
//    List three after sort & unique: 1 2 4 5 6 8
//    Sorted two merged into three: 1 2 4 5 6 8
}

// Set的相关操作
void useSet(){
    const int N = 6;
    string s1[N] = {"buffon", "thinkers", "for", "heavy", "can", "for"};
    string s2[N] = {"metal", "any", "food", "elegant", "deliver", "for"};

    set<string> A (s1, s1 + N);
    set<string> B (s2, s2 + N);
    ostream_iterator<string, char> out(cout, "");
    cout << "Set A: ";
    copy(A.begin(), A.end(), out);
    cout << endl;
    cout << "Set B: ";
    copy(B.begin(), B.end(), out);
    cout << endl;

    cout << "Union of A and B: \n";
    set_union(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    cout << "Intersection of A and B:\n";
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    cout << "Difference of A and B:\n";
    set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    set<string> C;
    cout << "Set C:\n";
    set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string>>(C, C.begin()));
    copy(C.begin(), C.end(), out);
    cout << endl;

    string s3("grungy");
    C.insert(s3);
    cout << "Set C after insertion: \n";
    copy(C.begin(), C.end(), out);
    cout << endl;

    cout << "Showing a range:\n";
    copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
    cout << endl;
//    运行结果：
//    Set A: buffoncanforheavythinkers
//    Set B: anydeliverelegantfoodformetal
//    Union of A and B:
//    anybuffoncandeliverelegantfoodforheavymetalthinkers
//    Intersection of A and B:
//    for
//    Difference of A and B:
//    buffoncanheavythinkers
//    Set C:
//    anybuffoncandeliverelegantfoodforheavymetalthinkers
//    Set C after insertion:
//    anybuffoncandeliverelegantfoodforgrungyheavymetalthinkers
//    Showing a range:
//    grungyheavymetal
}

// multimap的相关操作
typedef int KeyType;
typedef pair<const KeyType, string> Pairs;
typedef multimap<KeyType , string> MapCode;
void useMultimap(){
    MapCode codes;

    codes.insert(Pairs(415, "San Francisco"));
    codes.insert(Pairs(510, "Oakland"));
    codes.insert(Pairs(718, "Brooklyn"));
    codes.insert(Pairs(718, "Staten Island"));
    codes.insert(Pairs(415, "San Rafael"));
    codes.insert(Pairs(510, "Berkeley"));

    cout << "Number if cities with area code 415: " << codes.count(415) << endl;
    cout << "Number if cities with area code 718: " << codes.count(718) << endl;
    cout << "Number if cities with area code 510: " << codes.count(510) << endl;
    cout << "Area Code City\n";
    MapCode::iterator it;
    for (it = codes.begin(); it != codes.end(); ++it){
        cout << "   " << (*it).first << "   " << (*it).second << endl;
    }
    pair<MapCode::iterator, MapCode::iterator> range = codes.equal_range(718);
    cout << "Cities with area code 718: \n";
    for (it = range.first; it != range.second; ++it)
        cout << (*it).second << endl;

//    运行结果:
//    Number if cities with area code 415: 2
//    Number if cities with area code 718: 2
//    Number if cities with area code 510: 2
//    Area Code City
//    415   San Francisco
//    415   San Rafael
//    510   Oakland
//    510   Berkeley
//    718   Brooklyn
//    718   Staten Island
//    Cities with area code 718:
//    Brooklyn
//    Staten Island
}

// 函数符
void useFunctor(){
    TooBig<int> f100(100);
    list<int> yadayada;
    list<int> etcetera;
    int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    yadayada.insert(yadayada.begin(), vals, vals + 10);
    etcetera.insert(etcetera.begin(), vals, vals + 10);
    ostream_iterator<int, char> out(cout, " ");
    cout << "Original list:\n";
    copy(yadayada.begin(), yadayada.end(), out);
    cout << endl;
    copy(etcetera.begin(), etcetera.end(), out);
    cout << endl;
    yadayada.remove_if(f100);
    etcetera.remove_if(TooBig<int>(200));
    cout << "Trimmed lists:\n";
    copy(yadayada.begin(), yadayada.end(), out);
    cout << endl;
    copy(etcetera.begin(), etcetera.end(), out);
    cout << endl;

//    运行结果：
//    Original list:
//    50 100 90 180 60 210 415 88 188 201
//    50 100 90 180 60 210 415 88 188 201
//    Trimmed lists:
//    50 100 90 60 88
//    50 100 90 180 60 88 188
}

// funadap-自适应函数符和函数适配器
void Shows(double);
const int LIM = 5;
void Shows(double v){
    cout.width(6);
    cout << v << '  ';
}
void funadap(){
    double arr1[LIM] = {36, 39, 42, 45, 48};
    double arr2[LIM] = {25, 27, 29, 31, 33};
    vector<double> gr8(arr1, arr1 + LIM);
    vector<double> m8(arr2, arr2 + LIM);
    cout.setf(ios_base::fixed);
    cout.precision(1);
    cout << "gr8: \t";
    for_each(gr8.begin(), gr8.end(), Shows);
    cout << endl;
    cout << "m8: \t";
    for_each(m8.begin(), m8.end(), Shows);
    cout << endl;
    vector<double > sum(LIM);
    transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(), plus<double>());
    cout << "sum: \t";
    for_each(sum.begin(), sum.end(), Shows);
    cout << endl;

    vector<double > prod(LIM);
    transform(gr8.begin(), gr8.end(), prod.begin(), bind1st(multiplies<double>(), 2.5));
    cout << "prod:\t";
    for_each(prod.begin(), prod.end(), Shows);
    cout << endl;

//    运行结果：
//    gr8: 	  36.08224  39.08224  42.08224  45.08224  48.08224
//    m8: 	  25.08224  27.08224  29.08224  31.08224  33.08224
//    sum: 	  61.08224  66.08224  71.08224  76.08224  81.08224
//    prod:	  90.08224  97.58224 105.08224 112.58224 120.08224
}

// STL和String类
void stlString(){
    string letters;
    cout << "Enter the letter grouping (q to quit): ";
    while (cin >> letters && letters != "q"){
        cout << "Permutations of " << letters << endl;
        sort(letters.begin(), letters.end());
        cout << letters << endl;
        while (next_permutation(letters.begin(), letters.end()))
            cout << letters << endl;
        cout << "Enter next sequence (q to quit): ";
    }
    cout << "Done.\n";

//    运行结果：
//    Enter the letter grouping (q to quit): wed
//    Permutations of wed
//    dew
//    dwe
//    edw
//    ewd
//    wde
//    wed
//    Enter next sequence (q to quit): q
//    Done.
}

// 函数和容器方法
void View(int);
void View(int v){
    cout << v << ' ';
}
const int LIMS = 10;
void funList(){
    int ar[LIMS] = {4, 5, 4, 2, 2, 3, 4, 8, 1, 4};
    list<int> la(ar, ar + LIMS);
    list<int> lb(la);

    cout << "Original list contents: \n\t";
    for_each(la.begin(), la.end(), View);
    cout << endl;
    la.remove(4);
    cout << "After using the remove() method: \n";
    cout << "la: \t";
    for_each(la.begin(), la.end(), View);
    cout << endl;
    list<int>::iterator last;
    last = remove(lb.begin(), lb.end(), 4);
    cout << "After using the remove() function: \n";
    cout << "lb: \t";
    for_each(lb.begin(), lb.end(), View);
    cout << endl;
    lb.erase(last, lb.end());
    cout << "After using the erase() method: \n";
    cout << "lb: \t";
    for_each(lb.begin(), lb.end(), View);
    cout << endl;

//    运行结果：
//    Original list contents:
//    4 5 4 2 2 3 4 8 1 4
//    After using the remove() method:
//    la: 	5 2 2 3 8 1
//    After using the remove() function:
//    lb: 	5 2 2 3 8 1 4 8 1 4
//    After using the erase() method:
//    lb: 	5 2 2 3 8 1
}

// 使用STL
char toLower(char ch){ return tolower(ch); }
string & ToLower(string & st);
void display(const string & s);

string & ToLower(string & st){
    transform(st.begin(), st.end(), st.begin(), toLower);
    return st;
}

void display(const string & s){
    cout << s << " ";
}

void useSTL(){
    vector<string> words;
    cout << "Enter words (enter q to quit): \n";
    string input;
    while (cin >> input && input != "q")
        words.push_back(input);
    cout << "You entered the following words:\n";
    for_each(words.begin(), words.end(), display);
    cout << endl;
    // place words in set, converting to lowercase
    set<string> wordset;
    transform(words.begin(), words.end(), insert_iterator<set<string>>(wordset, wordset.begin()), ToLower);
    cout << "\nAlphabetic list of words: \n";
    for_each(wordset.begin(), wordset.end(), display);
    cout << endl;

    // place word and frequency in map
    map<string, int> wordmap;
    set<string>::iterator si;
    for (si = wordset.begin(); si != wordset.end(); si++)
        wordmap[*si] = count(words.begin(), words.end(), *si);

    // display map contents
    cout << "\nWord frequency: \n";
    for (si = wordset.begin(); si != wordset.end(); si++)
        cout << *si << ": " << wordmap[*si] << endl;

//    运行结果：
//    Enter words (enter q to quit):
//    The dog saw the cat thought the cat fat the cat thought the cat perfact
//    q
//    You entered the following words:
//    The dog saw the cat thought the cat fat the cat thought the cat perfact
//
//    Alphabetic list of words:
//    cat dog fat perfact saw the thought
//
//    Word frequency:
//    cat: 4
//    dog: 1
//    fat: 1
//    perfact: 1
//    saw: 1
//    the: 5
//    thought: 2
}

// 其他STL库的使用
void valvect(){
    vector<double > data;
    double temp;
    cout << "Enter numbers(<= 0 to quit):\n";
    while (cin >> temp && temp > 0)
        data.push_back(temp);
    sort(data.begin(), data.end());
    int size = data.size();
    valarray<double > numbers(size);
    int i;
    for (int i = 0; i < size; i++) {
        numbers[i] = data[i];
    }
    valarray<double > sq_rts(size);
    sq_rts = sqrt(numbers);
    valarray<double > result(size);
    result = numbers + 2.0 * sq_rts;
    cout.setf(ios_base::fixed);
    cout.precision(4);
    for (int i = 0; i < size; i++) {
        cout.width(8);
        cout << numbers[i] << ": ";
        cout.widen(8);
        cout << result[i] << endl;
    }
    cout << "Done!\n";

//    运行结果：
//    Enter numbers(<= 0 to quit):
//    5 21.2 6 8 2 10 14.4 0
//    2.0000: 4.8284
//    5.0000: 9.4721
//    6.0000: 10.8990
//    8.0000: 13.6569
//    10.0000: 16.3246
//    14.4000: 21.9895
//    21.2000: 30.4087
//    Done!
}

// slice的使用
const int SIZE = 12;
typedef valarray<int> vint;
void Show_s(const vint & v, int cols);

void Show_s(const vint & v, int cols){
    int lim = v.size();
    for (int i = 0; i < lim; i++) {
        cout.width(3);
        cout << v[i];
        if (i % cols == cols - 1)
            cout << endl;
        else
            cout << ' ';
    }
    if (lim % cols != 0)
        cout << endl;
}

void useSlice(){
    vint valint(SIZE);
    for (int i = 0; i < SIZE; i++) {
        valint[i] = rand() % 10;
    }
    cout << "Original array: \n";
    Show_s(valint, 3);
    vint vcol(valint[slice(1, 4, 3)]);
    cout << "Second column: \n";
    Show_s(vcol, 1);
    valint[slice(2, 4, 3)] = 10;
    cout << "Set last column to 10 :\n";
    Show_s(valint, 3);
    cout << "Set first column to sum of next two:\n";
    valint[slice(0, 4, 3)] = vint(valint[slice(1, 4, 3)]) + vint(valint[slice(2, 4, 3)]);
    Show_s(valint, 3);

//    运行结果：
//    Original array:
//    3   3   2
//    9   0   8
//    2   6   6
//    9   1   1
//    Second column:
//    3
//    0
//    6
//    1
//    Set last column to 10 :
//    3   3  10
//    9   0  10
//    2   6  10
//    9   1  10
//    Set first column to sum of next two:
//    13   3  10
//    10   0  10
//    16   6  10
//    11   1  10
}

void useWrite(){
    const char * state1 = "Florida";
    const char * state2 = "Kansas";
    const char * state3 = "Euphoria";
    int len = strlen(state2);
    cout << "Increasing loop index: \n";
    for (int i = 0; i < len; i++) {
        cout.write(state2, i);
        cout << endl;
    }
    cout << "Decreasing loop index: \n";
    for (int i = len; i > 0; i--)
        cout.write(state2, i) << endl;

    cout << "Exceeding string length:\n";
    cout.write(state2, len + 5) << endl;

//    运行结果：
//    Increasing loop index:
//
//    K
//    Ka
//    Kan
//    Kans
//    Kansa
//    Decreasing loop index:
//    Kansas
//    Kansa
//    Kans
//    Kan
//    Ka
//    K
//    Exceeding string length:
//    Kansas Euph
}

int main() {

//    pointer();
//    structure();
//    fileoperation("info.txt");
//    referenceVariable();
//    useTemSwap();
//    friendFunction();
//    randwalk();
//    bank();
//    usett();
//    useBrass();
//    usedma();
//    workmi();
//    useTemplateClass();
//    usePointerStack();
//    useArrayTemplate();
//    useMultipleTypeParameter();
//    useFriendClass();
//    useNestClass();
//    errorOne();
//    errorCode();
//    errorTryCatch();
//    useErrorClass();
//    useVector();
//    stlFunction();
//    useIterator();
//    iteratorInsert();
//    useList();
//    useSet();
//    useMultimap();
//    useFunctor();
//    funadap();
//    stlString();
//    funList();
//    useSTL();
//    valvect();
//    useSlice();
    useWrite();

    double a = square(5.0);
    cout << "a : " << a << endl;

    return 0;
}
