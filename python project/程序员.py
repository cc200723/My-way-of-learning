from turtle import *
import math
# 设置画布宽高/背景色和设置画笔粗细/速度/颜色
screensize(600, 500, '#99CCFF')
pensize(5),speed(10),color('red')
# 定义椭圆函数: 绘制蜡烛火焰和被圆柱函数调用
def ellipse(x,y,a,b,angle,steps):
    penup(),goto(x,y),forward(a),pendown()
    theta = 2*math.pi*angle/360/steps
    for i in range(steps):
        nextpoint = [x+a*math.cos((i+1)*theta),y+b*math.sin((i+1)*theta)]
        setpos(nextpoint)
# 定义圆柱函数: 绘制生日蛋糕和蜡烛柱体
def cylinder(x,y,a,b,angle,steps,height):
    ellipse(x,y,a,b,angle,steps)
    ellipse(x,y-height,a,-b,angle/2,steps)
    penup(),goto(x,y),forward(a),pendown()
    right(90),forward(height)
    penup(),right(90),forward(2*a),pendown()
    right(90),forward(height)
    setheading(0)

x = 0; y = 50
# 调用圆柱函数绘制生日蛋糕
cylinder(x,y,200,50,360,90,150)
# 调用圆柱函数绘制4个蜡烛柱体
begin_fill(),cylinder(x+100,y+100,10,5,360,20,70),goto(x+100,y+100),end_fill()
begin_fill(),cylinder(x-50, y+100,10,5,360,20,70),goto(x-50, y+100),end_fill()
begin_fill(),cylinder(x+50, y+80, 10,5,360,20,70),goto(x+50, y+80 ),end_fill()
begin_fill(),cylinder(x-100,y+80, 10,5,360,20,70),goto(x-100,y+80 ),end_fill()
# 调用椭圆函数绘制4个蜡烛火焰
color('yellow')
begin_fill(),ellipse(x+100,y+100+10,5,15,360,20),goto(x+100,y+100+10),end_fill()
begin_fill(),ellipse(x-50, y+100+10,5,15,360,20),goto(x-50, y+100+10),end_fill()
begin_fill(),ellipse(x+50, y+80+10, 5,15,360,20),goto(x+50, y+80+10 ),end_fill()
begin_fill(),ellipse(x-100,y+80+10, 5,15,360,20),goto(x-100,y+80+10 ),end_fill()
# 在生日蛋糕上添加文字'1024'和'程序员节日快乐'
penup(),goto(0,-100),pendown(),
color('yellow')
write('1 0 2 4',move=False,
align='center',
font=('Time New Roman',50,'bold'))
penup(),goto(0,-230),
pendown(),color('red')
write('程序员节日快乐',move=False,
align='center',
font=('黑体',45,'normal'))
hideturtle();mainloop() 
