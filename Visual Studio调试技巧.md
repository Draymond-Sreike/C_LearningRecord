# Visual Studio调试技巧

- **F9——产生/取消（红色）断点**

  > 与**F5**搭配使用，让程序瞬间执行至断点处（断点前的程序都执行了）

  <img src="C:\Users\win10\AppData\Roaming\Typora\typora-user-images\image-20221118190402949.png" alt="image-20221118190402949" style="zoom:50%;" />

  > 注意：上例如果按F5跳至断点处之后还可以继续按F5，这时继续这次循环，待到下一次循环又遇到该断点时会又停下来（如第一次按F5执行至断点时，i=0，再按一次F5之后，执行至断点，i=1）
  >

  ​	

  - 断点：代码执行到“这个地方”停下来

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