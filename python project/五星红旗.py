import turtle
turtle.bgcolor("red")
turtle.fillcolor("yellow")
turtle.color('yellow')
turtle.speed(50)
#主星
turtle.begin_fill()
turtle.up()
turtle.goto(-400,220) 
turtle.down()
for i in range (5):    
    turtle.forward(150)
    turtle.right(144)
turtle.end_fill()

#第1颗副星
turtle.begin_fill()
turtle.up()
turtle.goto(-200,295)
turtle.setheading(305)
turtle.down()
for i in range (30):    
    turtle.forward(50)
    turtle.left(144)

turtle.end_fill()


#第2颗副星
turtle.begin_fill()
turtle.up()
turtle.goto(-150,212)
turtle.setheading(30)
turtle.down()
for i in range (25):  
    turtle.forward(50)
    turtle.right(144)

turtle.end_fill()

#第3颗副星
turtle.begin_fill()
turtle.up()
turtle.goto(-150,145)
turtle.setheading(5)
turtle.down()
for i in range (25):   
    turtle.forward(50)
    turtle.right(144)

turtle.end_fill()

#第4颗副星
turtle.begin_fill()
turtle.up()
turtle.goto(-200,90)
turtle.setheading(300)
turtle.down()
for i in range (30):  
    turtle.forward(50)
    turtle.left(144)
    
turtle.end_fill()
turtle.end_fill()
turtle.done()
