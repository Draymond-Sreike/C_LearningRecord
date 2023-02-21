# 指针

> ![image-20230111104753476](E:\Typora\Image\image-20230111104753476.png)

## 例子1（sizeof计算数组大小）

> ![image-20230111105421393](E:\Typora\Image\image-20230111105421393.png)

在与数组arr定义的同一个函数中，若用sizeof(数组名)，则所得结果将是该数组的所占的总字节数，而如果将arr传递至其他函数中使用sizeof(arr)，则所得结果是arr这个指针本身的大小4/8(取决于32/64位机器)

### 补充：数组名是首元素地址（另外还有两种数组名的例外情况）

> ![image-20230218212242033](D:\大学\C语言程序设计\C_Learning\C_LearningRecord\image-20230218212242033.png)

## sizeof计算经典例题1

> ![image-20230219163034395](D:\大学\C语言程序设计\C_Learning\C_LearningRecord\image-20230219163034395.png)

- `*&a`相当于\*和&相互抵消，所以sizeo(*&a)就相当于sizeof(a)，算的就是数组的大小

- `&a+1`是跳过了一个数组长度的地址：

    > <img src="D:\大学\C语言程序设计\C_Learning\C_LearningRecord\image-20230219165718661.png" alt="image-20230219165718661" style="zoom:50%;" />

## sizeof计算经典例题2


> ![image-20230220215714779](D:\大学\C语言程序设计\C_Learning\C_LearningRecord\image-20230220215714779.png)

## strlen计算经典好题

> ![image-20230221201110158](D:\大学\C语言程序设计\C_Learning\C_LearningRecord\image-20230221201110158.png)

- `strlen(*arr)`和`strlen(arr[1])`相当于将'a'传给了strlen，而'a'的值为97，所以strlen会去访问地址为97的内存（它想要从地址为97的内存处开始数字符直到遇到'\0'），此时就是非法访问，会导致程序崩溃：

    > ![image-20230221202144064](D:\大学\C语言程序设计\C_Learning\C_LearningRecord\image-20230221202144064.png)
    >
    > 读取位置0x00000061时发生访问冲突（0x00000061即97）

- `strlen(&arr)`中&arr虽然获得的时数组的地址，但其值与数组arr的首元素的地址相同，所以strlen同样是从数组首元素开始向后计数（可以认为strlen在函数将所获得&arr值转化为char*类型，然后在函数里逐个逐个字节地进行内存内容的访问），所以strlen(arr)与strlen(&arr)的结果相同（区别在于strlen(arr)在函数内部不用将所得到的arr转换为char\*，因为其本身就是char\*，而strlen(&arr)则在函数内部发生了将&arr从char (\*parr)[6]数组指针转化为char\*的过程）

## 指针指向字符串

> ​	<img src="E:\Typora\Image\image-20230112221211596.png" alt="image-20230112221211596" style="zoom:50%;" />

以上代码的意思并不是将字符串赋值给指针p，而是将字符串的地址赋值给指针p，准确地说应该是将字符串的首字符的地址赋值给指针p，如下	

> ![image-20230112221505583](E:\Typora\Image\image-20230112221505583.png)
>
>  此代码运行结果如下
>
> ​	<img src="E:\Typora\Image\image-20230112221556385.png" alt="image-20230112221556385" style="zoom:50%;" />
>
> 说明p存的就是字符串首字符的地址

另外注意注意这个字符串abcdef是一个常量字符串。

如果换成打印字符串printf("%s\n", p)，如下

> ​	<img src="E:\Typora\Image\image-20230112221738369.png" alt="image-20230112221738369" style="zoom:50%;" />
>
> 此时程序会顺着字符串首字符的地址向后打印，直到遇到内存存的是'\0'的地址就结束打印，程序运行结果如下
>
> ​	<img src="E:\Typora\Image\image-20230112222046313.png" alt="image-20230112222046313" style="zoom:50%;" />

此案例就是说可以把字符串赋值给一个指针，但这时程序执行的逻辑是将该字符串的首字符地址赋值给该指针，并不是将字符串本身赋值给指针。

我们可以利用这个特点，**通过一个指针来维护一个字符串**

该案例的内存示意图如下

> ​	<img src="E:\Typora\Image\image-20230112222348949.png" alt="image-20230112222348949" style="zoom: 50%;" />

### 常量字符串内容不可改

> ​	<img src="E:\Typora\Image\image-20230112222450702.png" alt="image-20230112222450702" style="zoom:50%;" />
>
> 该代码们要修改字符串的内容，这是不允许的，因为这是一个常量字符串，它的内容是不允许修改的

但是在VS编译器64位的模式下，该代码可以编译和运行，如下

> ​	<img src="E:\Typora\Image\image-20230112223259538.png" alt="image-20230112223259538" style="zoom:50%;" />
>
> 运行结果：
>
> ​	<img src="E:\Typora\Image\image-20230112223326279.png" alt="image-20230112223326279" style="zoom:50%;" />

但是在32位的编译器模式下，该程序无法运行，在Linux也是无法运行的，如下

> **Linux**
>
> ![image-20230112223742765](E:\Typora\Image\image-20230112223742765.png)
>
> 代码运行结果
>
> ​	<img src="E:\Typora\Image\image-20230112223800910.png" alt="image-20230112223800910" style="zoom:50%;" />
>
> 报错`Segmentation fault`（段错误），这是一个非法访问内存报的一个错误
>
> **VS，32位编译器模式运行结果：**
>
> ​	<img src="E:\Typora\Image\image-20230112224404987.png" alt="image-20230112224404987" style="zoom: 67%;" />
>
> 此时代码运行发生了崩溃（没有打印什么东西）

至于为什么VS64位编译器模式下可以修改常量字符串的内容，可能是编译器优化的缘故。

**总之我们应该明确常量字符串的内容是不可用修改的！**

另外如果我们要明确地指明一个字符串不可用修改可以用const修饰，如下：

> ​	<img src="E:\Typora\Image\image-20230112224622963.png" alt="image-20230112224622963" style="zoom:50%;" />
>
> 此时const修饰*p，表面\*p的内容不可以修改（即指针所指不可修改）
>
> 上述代码编译结果如下
>
> ![image-20230112224935959](E:\Typora\Image\image-20230112224935959.png)
>
> 此时编译报错，因为const修饰，内容不可修改。
>
> **这是最正确的写法**（用const修饰表明内容不可修改）

#### 拓展（两个网站stackoverflow、segmentfault）

www.stackoverflow.com

segmentfault.com(这是国内的一个技术问答社区，仿国外的stackoverflow网站，有空可以看看该网站)

## 经典好题（字符串数组名及字符串指针）

### 数组存储字符串

> ​	<img src="E:\Typora\Image\image-20230113115912735.png" alt="image-20230113115912735" style="zoom:50%;" />

**问：**以上题目的输出结果？

程序运行的结果如下

> ​	<img src="E:\Typora\Image\image-20230113120003739.png" alt="image-20230113120003739" style="zoom:50%;" />

不论字符串内容相同也好，不同也好，我们都是用两个数组去存放（arr1和arr2、arr3和arr4）

在字符串内容相同的情况下我们用arr1和arr2两个数组去存储，那么内存空间中就会开辟两个不同的空间来存储abcdef，所以arr1和arr2是不同的，即地址是不同的（数组名表示地址）

字符串内容不同的情况下也是如此，都是一个数组开辟一块空间去存储字符串，那么不管字符串内容如何，数组的地址肯定是不一样的，所以都是"异"

### char指针指向字符串

案例如下

> ​	<img src="E:\Typora\Image\image-20230113121219986.png" alt="image-20230113121219986" style="zoom: 50%;" />

问程序运行输出hehe还是haha？

程序运行的结果如下

> ​	<img src="E:\Typora\Image\image-20230113121753704.png" alt="image-20230113121753704" style="zoom:50%;" />

这时p1==p2。

这是因为p1和p2指向的字符串的内容是一样的，都是abcdef，且是常量字符串，在内存中没有必要分配两块内存空间来存储一个相同的东西，所以"abcdef"只在内存中存一份，此时的p1和p2都是指向"abcdef"所存放的内存位置（字符串的首字符的地址）

内存示意图

> <img src="E:\Typora\Image\image-20230113122344864.png" alt="image-20230113122344864" style="zoom:50%;" />

当然上述代码的准确写法应该是加上const

>  <img src="E:\Typora\Image\image-20230113122433693.png" alt="image-20230113122433693" style="zoom:50%;" />

也就是说以后常量字符串我们准确的写法是加上一个const，这样代码更加健壮。当然这样加上const之后，程序的运行结果仍然是一样的，p1和p2在该程序中仍然是相等的。

如果换作是两个内容不同的字符串，那么p1和p2不相同是合情合理的（懒得验证，我的直觉告诉我，这种情况绝对p1不等于p2）。

另外再补充与上述题目相同的一道题

> ​	<img src="E:\Typora\Image\image-20230113122933008.png" alt="image-20230113122933008" style="zoom:50%;" />

该题正确答案的A（这里E是错的）

# 指针数组

指针数组的主语是**数组**，数组的元素都是指针，即数组是用来存放指针的

> ​	<img src="E:\Typora\Image\image-20230114101958054.png" alt="image-20230114101958054" style="zoom:50%;" />

## 最基本的应用

> ​	<img src="E:\Typora\Image\image-20230114102036173.png" alt="image-20230114102036173" style="zoom:50%;" />
>
> 以上程序的内存如下
>
> ​	<img src="E:\Typora\Image\image-20230114102238606.png" alt="image-20230114102238606" style="zoom:50%;" />

下面对以上程序进行进一步的应用

> ​	<img src="E:\Typora\Image\image-20230114102329668.png" alt="image-20230114102329668" style="zoom: 50%;" />
>
> 程序运行结果如下图所示
>
> ​	<img src="E:\Typora\Image\image-20230114102402219.png" alt="image-20230114102402219" style="zoom:33%;" />

以上介绍的应用是指针数组最低级的运用。

## 常见的应用

> ​	<img src="E:\Typora\Image\image-20230115153338170.png" alt="image-20230115153338170" style="zoom:50%;" />

存储数组地址，即数组首元素地址。

该程序的内存示意图如下

> ​	<img src="E:\Typora\Image\image-20230115153721373.png" alt="image-20230115153721373" style="zoom:50%;" />

可见一个一维的指针数组就可以用来维护三个一维的整型数组，这个一维的指针数组的每个元素都是指针，是一个整型指针数组。

如果我们能够拿到parr[]数组，我们可以访问arr[]数组的每个元素，如下

> ​	<img src="E:\Typora\Image\image-20230115153908524.png" alt="image-20230115153908524" style="zoom:50%;" />
>
> 此时的parr[i]就是arr[]数组的地址，也即arr[]数组首元素的地址，然后我们再在此基础上加一个偏移量，如下
>
> ​	<img src="E:\Typora\Image\image-20230115154047361.png" alt="image-20230115154047361" style="zoom:50%;" />
>
> j作为一个在arr[]首元素地址基础上的偏移量，使得其可以访问arr[]中每个元素的地址，然后进行解引用就可以访问到arr[]中每个元素的内容了，如下
>
> ​	<img src="E:\Typora\Image\image-20230115154310660.png" alt="image-20230115154310660" style="zoom:50%;" />
>
> 程序运行结果如下
>
> ​	<img src="E:\Typora\Image\image-20230115154343980.png" alt="image-20230115154343980" style="zoom:50%;" />

## 小拓展（多级指针数组）

> ​	<img src="E:\Typora\Image\image-20230115154511978.png" alt="image-20230115154511978" style="zoom:50%;" />

# void类型指针

## 1.void*指针可以接收任意类型的指针（而不报警告）

> <img src="C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20230208121453482.png" alt="image-20230208121453482" style="zoom:50%;" />

## 2.void*指针不能进行解引用、加减操作

因为void*是无类型指针，这就会导致我们对其解引用的时候编译器不知道要访问多少个字节，此时编译代码报错如下：

> <img src="D:\大学\C语言程序设计\C_Learning\C_LearningRecord\image-20230209122214868.png" alt="image-20230209122214868" style="zoom:50%;" />
>
> 非法的间接寻址

再是因为void*是无类型指针，其加减时编译器并不知道要向后或向前迈多少个字节，所以编译代码也会报错：

> ![image-20230209122402941](D:\大学\C语言程序设计\C_Learning\C_LearningRecord\image-20230209122402941.png)
>
> “void*“：未知的大小

要使用void*类型的变量一定要将其强制转换为对应的指针类型再进行使用：

> <img src="D:\大学\C语言程序设计\C_Learning\C_LearningRecord\image-20230209123138378.png" alt="image-20230209123138378" style="zoom:50%;" />

## 案例：qsort函数的使用

> ![image-20230209123544395](D:\大学\C语言程序设计\C_Learning\C_LearningRecord\image-20230209123544395.png)![image-20230212095301185](D:\大学\C语言程序设计\C_Learning\C_LearningRecord\image-20230212095301185.png)

> ![image-20230209123752385](D:\大学\C语言程序设计\C_Learning\C_LearningRecord\image-20230209123752385.png)

### 实现cmp_int：

> ![image-20230209124227704](D:\大学\C语言程序设计\C_Learning\C_LearningRecord\image-20230209124227704.png)

> ![image-20230209124024233](D:\大学\C语言程序设计\C_Learning\C_LearningRecord\image-20230209124024233.png)

### 实现cmp_float：

> <img src="D:\大学\C语言程序设计\C_Learning\C_LearningRecord\image-20230211123336938.png" alt="image-20230211123336938" style="zoom:50%;" />

### 实现cmp_stu_by_age：（比较结构体的年龄属性）

> ![image-20230211130533963](D:\大学\C语言程序设计\C_Learning\C_LearningRecord\image-20230211130533963.png)

要观察排序后的结果可以通过调试窗口查看：

> 排序前：
>
> <img src="D:\大学\C语言程序设计\C_Learning\C_LearningRecord\image-20230211130602103.png" alt="image-20230211130602103" style="zoom:50%;" />
>
> 排序后：
>
> <img src="D:\大学\C语言程序设计\C_Learning\C_LearningRecord\image-20230211130635982.png" alt="image-20230211130635982" style="zoom:50%;" />

### cmp_stu_by_name：（比较结构体的名字字符串属性）

> ![image-20230211130744471](D:\大学\C语言程序设计\C_Learning\C_LearningRecord\image-20230211130744471.png)

> 排序前：
>
> <img src="D:\大学\C语言程序设计\C_Learning\C_LearningRecord\image-20230211130759720.png" alt="image-20230211130759720" style="zoom:50%;" />
>
> <img src="D:\大学\C语言程序设计\C_Learning\C_LearningRecord\image-20230211130836066.png" alt="image-20230211130836066" style="zoom:50%;" />

### qsort函数实现（实现为bubble_sort）[回调函数的知识]【有必要自己实现一下。。。】

该部分内容讲解见视频 [10：00~35：00](https://www.bilibili.com/video/BV1oi4y1g7CF/?p=40&spm_id_from=333.1007.top_right_bar_window_history.content.click&vd_source=b8a7d9f6d396acb27e811371a96d6e9a)

> ![image-20230213144509942](D:\大学\C语言程序设计\C_Learning\C_LearningRecord\image-20230213144509942.png)
>
> <img src="D:\大学\C语言程序设计\C_Learning\C_LearningRecord\image-20230213143009771.png" alt="image-20230213143009771" style="zoom:50%;" />
>
> <img src="D:\大学\C语言程序设计\C_Learning\C_LearningRecord\image-20230213142943932.png" alt="image-20230213142943932" style="zoom:50%;" />
>
> 

