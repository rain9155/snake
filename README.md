# snake
## C语言版贪吃蛇, 采用MVC架构
### ScreenShots
![](/screenshots/s1.gif)
![](/screenshots/s2.gif)
### How to Play
1、打开.exe文件，按enter键开始游戏 <br>
2、方向键控制上下左右或W（上）S(下)A（左）D（右） <br>
3、snake触碰到自己身体，游戏结束 <br>
### Download
[手动下载snake.exe](https://github.com/rain9155/snake/blob/master/bin/Debug/snake.exe)

## 谈谈MVC
MVC是一种框架模式，MVC的发展有40多年了，经过历史的演变，它也演化出很多的版本，但怎么变还是离不开Model、View、Controller的结构，我们来看一下典型的MVC结构图：<br>
![典型的MVC结构图](/screenshots/s3.png)
* Model: 模型层，在MVC中一般是用来保存程序的数据状态的，如本地数据存储，网络数据的请求，同时Model与View存在耦合，即Model可以通过某种事件机制，通知View改变状态，Model还会接受来自Controller的事件，Model也会允许View查询相关数据以显示自身状态。
* View：视图层，顾名思义就是展示界面，一般由一些GUI组成，可以与用户交互并触发Controller的逻辑，View还可能会修改Model的状态以使其与Model保持同步，View还会通过在Model中注册事件监听Model的改变以此来刷新自己并展示给用户。
* Controller： 控制器，控制器由View根据用户行为触发并响应来自View的用户交互，然后根据View的事件逻辑修改对应的Model，Controller并不关心View如何展示数据，而是通过修改Model并由Model的事件机制来触发View的刷新。
<br>
可以看出MVC通过分层把逻辑交互，数据处理，视图展示分成不同的模块，但由于因为各模块之间逻辑并不是很清晰，对于Model和View而言，Controller职责模糊，因此对于复杂的逻辑而言，导致很多时候我们在不确定某个逻辑是哪个模块负责的情况下，不知道如何确定Controller的责任。所以这种模式有利也有弊。
<br>
snake中用到的MVC模式是在典型的MVC模式下修改的，结构图如下：<br>
![snake中的MVC结构](/screenshots/s4.png)
这里的View到Controller之间砍掉了一条线,Controller不用响应View的事件逻辑，只是简单的整合View和Model之间的关系，View和Model的职责还是原来那样，这里的View主要干的工作是绘制游戏面板、设置面板等，还要根据用户按键的输入（如用户按了上下左右）去Model中改变小蛇的坐标，还要从model中获取数据刷新游戏界面等，主要干的工作是存放小蛇的数据,食物的数据，并根据View的响应来修改小蛇的坐标等。
<br>
框架是死的，开发中要灵活运用，不用按部就班，符合我们的开发需求就行。
