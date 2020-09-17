#引入小海龟模块
import turtle
#设置画板的背景色
turtle.bgcolor("gray")
#设置画板的背景图片
#turtle.bgpic(".../timg.gif")
 
#设置小海龟画笔速度
turtle.speed(0)
turtle.pensize(1)
#画出钻戒的钻石
for i in range(1,5):
    #顺时针移动画笔的角度
    turtle.right(0)
    turtle.speed(0)
    #设置画笔的颜色
    turtle.pencolor('white')
    #画圆,参数steps可以设置形状
    turtle.circle(23,steps= 3)
    turtle.circle(20,steps= 7)
    turtle.circle(15, steps = 6)
    turtle.circle(13, steps = 5)
    turtle.circle(10,steps = 4)
    turtle.circle(10,steps = 3)
    #像当前画笔方向前进对应的距离
    turtle.forward(4)
    turtle.forward(6)
 
turtle.speed(0)
#像画笔相反的方向移动相应的距离
turtle.backward(48)
turtle.forward(24)
turtle.right(180)
 
turtle.speed(0)
turtle.circle(36)
#提起画笔
turtle.penup()
#移动画笔的坐标(x,y)
turtle.goto(16,12)
#落下画笔
turtle.pendown()
turtle.circle(42)
 
turtle.penup()
turtle.goto(50,-100)
turtle.pendown()
 
#turtle.pencolor('white')
#写入文本
turtle.write('Python的第n个作品:cc',
font = ('华文隶书' ,15 ,'normal'))
turtle.penup()
turtle.goto(50,-115)
turtle.pendown()
turtle.write('2020年 04 月 20 日' ,
 font = ('华文隶书',12,'normal'))
turtle.pendown()
 
#隐藏画笔箭头
turtle.hideturtle()
 
#关闭turtle
turtle.done()
