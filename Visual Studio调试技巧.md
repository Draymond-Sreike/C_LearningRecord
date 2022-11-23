# Visual Studio调试技巧

- **F9——产生/取消（红色）断点**

  > 与**F5**搭配使用，让程序瞬间执行至断点处（断点前的程序都执行了）

  <img src="C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221118190402949.png" alt="image-20221118190402949" style="zoom:50%;" />

  > 注意：上例如果按F5跳至断点处之后还可以继续按F5，这时继续这次循环，待到下一次循环又遇到该断点时会又停下来（如第一次按F5执行至断点时，i=0，再按一次F5之后，执行至断点，i=1）
  >

  - 断点：代码执行到“这个地方”停下来
  - **条件断点**：用于执行至指定循环次数后产生断点，输入一个条件，满足条件时才会停再断点处

![image-20221121164125043](C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221121164125043.png)

![image-20221121164140566](C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221121164140566.png)

![image-20221121164151340](C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221121164151340.png)

![image-20221121164208080](C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221121164208080.png)

- **F5——启动调试**

  > 经常用来直接跳到下一个断点处

- **F10——逐过程**

  > 通常用来处理一个过程，一个过程可以是一次函数调用，或者是一条语句

- **F11——逐语句**

    > 每次都执行一条语句，但是这个快捷键可以使我们的执行逻辑**进入函数内部（这是最常用的）**

- **Shift+F11——跳出（迅速执行完当前函数并跳出该函数）**

    > 程序调试至某个函数内部时，需要**马上执行完该函**数以跳出该函数

- **Ctrl+F5——开始执行不调试**

    > 让程序直接运行起来而不调试

- **自动窗口**

    > 观察程序当前执行位置以上的、同级局部中存在的变量
    >
    > <img src="C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221119165254593.png" alt="image-20221119165254593" style="zoom: 33%;" />
    >
    > <img src="C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221119165342821.png" alt="image-20221119165342821" style="zoom:33%;" />
    >
    > <img src="C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221119165407791.png" alt="image-20221119165407791" style="zoom: 33%;" />
    >
    > 可以注意到自动窗口中观察的变量信息是自动添加和销毁的，上面代码的for循环执行时，当语句执行到for内部时，自动窗口才会观察到`arr[i]`而循环出到循环外时，`arr[i]`的观察自动销毁

- **局部变量（窗口）**

    > 观察程序当前所在局部{}中以及该局部外层的所有已存在的（程序执行创建完成的）变量（但无法观察该局部{}所包含的内层局部的变量）
    >
    > <img src="C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221119170058459.png" alt="image-20221119170058459" style="zoom:33%;" />
    >
    > <img src="C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221119170120244.png" alt="image-20221119170120244" style="zoom:33%;" />
    >
    > <img src="C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221119170140588.png" alt="image-20221119170140588" style="zoom:33%;" />
    >
    > <img src="C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221119170200508.png" alt="image-20221119170200508" style="zoom:33%;" />
    >
    > <img src="C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221119170244386.png" alt="image-20221119170244386" style="zoom:33%;" />
    >
    > <img src="C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221119170545633.png" alt="image-20221119170545633" style="zoom:33%;" />
    >
    > **注意：局部变量窗口无法查看`arr[i]`**
    >
    > <img src="C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221119170556829.png" alt="image-20221119170556829" style="zoom:33%;" />
    >
    > <img src="C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221119170609961.png" alt="image-20221119170609961" style="zoom: 25%;" />
    >
    > <img src="C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221119170625935.png" alt="image-20221119170625935" style="zoom:33%;" />

- **自动窗口和局部变量（窗口）的缺陷是：无法让程序员手动的设置要观察的变量值**

- **监视窗口**

    > 程序员手动添加要观察的变量，在程序运行调试期间永不销毁，一直观察

- **内存（监视窗口）**

- **反汇编**

- **寄存器**

- **调用堆栈**

**注意：所有的窗口的打开都是在程序运行调试时才能打开，敲代码的程序没办法打开这些窗口**

## 栈区小知识

**本节内容在P29（1:21:00~1:46:34处**）

栈区内存的默认分配方式：先使用高地址处的内存空间，再使用低地址处的内存空间（如下图）

![image-20221123155332356](C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221123155332356.png)

而且是根据变量定义的先后顺序来分配内存，先定义的变量则其内存空间的地址较高，后定义的变量其内存空间地址较低（如下图）

- 但应注意数组：随着下标的增长，地址是由低到高变化的（同样如下图）

![image-20221123155513005](C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221123155513005.png)

> 另外还应注意，若有代码如下
>
> ```c
> for(int i = 0; i <= 12; i++){}
> ```
>
> ​	该代码实际上是C++代码，不是严格的C代码，因为C代码不允许在for循环的头部来定义变量，即`int i = 0`应该在for循环的头部外定义，才符合C语法，在VS里之所以不报错是因为编译器将该代码视为C++，没有严格按照C的语法给予报错，此处应予以注意！

所以由上图中的内存分析框图可知，如果数组下标越界访问到`arr[12]`时，实际上访问到了变量`i`（如下图所示，arr[12]与i是同一块内存）

![image-20221123160258739](C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221123160258739.png)

- 注意在VS中，该案例中的变量`i`与数组`arr[]`最后一个元素的间隔是2个int单位的内存空间（即8个字节），不同的编译器，i与arr[]数组的最后一个元素的间隔不同，有如下规律：

> ![image-20221123163905501](C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221123163905501.png)

- VC6.0的内存分配间隔布局（<=10就死循环）：	

> <img src="C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221123164044593.png" alt="image-20221123164044593" style="zoom:25%;" />

- GCC的内存分配布局（<=11就死循环）：

> <img src="C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221123164149992.png" alt="image-20221123164149992" style="zoom:25%;" />





- 如果将for循环中的循环条件i<=12改成i<=11则不会死循环，但此时系统会报错，说我们数组越界访问（如下图）

![image-20221123163616963](C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221123163616963.png)

![image-20221123163629560](C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221123163629560.png)

- 之所以i<=12的时候不会报错，是因为陷入了死循环，编译器没有机会来给我们报错

- 上述代码产生死循环的原因是i的地址高于数组的地址，而数组又随着下标的增加，其地址增加，当数组越界到一定程度之后，就会访问到地址位于高处的变量i，然后将i的值修改导致死循环。
- 如果将i的定义放在数组定义之后，也就是说i变量的内存地址比数组的地址低，则数组越界访问时就永远不会访问到i



- 还应注意VS2022的默认栈内存分配原则变化了，不再是先使用高地址的内存，而是先使用低地址的内存！！！

> ![image-20221123162736862](C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221123162736862.png)
>
> 所以不会有越界访问数组时访问到循环控制变量i的情况发生，而是只会在数组越界访问后程序报错
