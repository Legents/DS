# DS
## 数据结构课程设计
``` Flowchart
grapg LR
st=>start:开始
op1=>operation: 输入课程信息
cond=>condition: 确认输入情况，是否添加
cond1=>condition: 课程添加成功，是否添加学生
op2=>operation: 输入学生信息，可循环添加，输入0 0 0结束
e=>end: 添加结束
st->op1->cond
cond(yes)->cond1
cond(no)->op1
cond1(yes)->op2
cond1(no)->e
op2->e
