#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
/**
*数据结构定义部分
*/
typedef struct stu_c {	//与课程联合存储时的学生节点，
	int s_id;			//学号
	char s_name[50];	//姓名
	int g;				//该门课程的成绩
	struct stu_c *next;	//指向下一个选修这门课程的学生
}stu_c,*stu_c_link;
typedef struct course {	//课程信息节点
	int course_id;		//课程代码
	char course_name[50];//课程名称
	float credit;//课程学分
	int stu_num;//选课人数
	struct course *lc, *rc;
	stu_c_link link;//指向选修这门课程的学生
}course,*bt_course;
typedef struct grade {//课程成绩节点，用于学生信息单独保存时存储成绩
	char course_name[50];//课程名
	int g;//成绩
};
typedef struct student {//独立保存时的学生节点
	int s_id;//学号
	char s_name[50];//学生姓名
	int c_num;
	grade g[10];//指向保存这名学生所选课程信息的线性表
	struct student *next;//指向下一名学生
}student,*s_link;
typedef struct course1 {	//课程信息节点
	int course_id;		//课程代码
	char course_name[50];//课程名称
}cour[10];;
/**
*函数声明
*/
void main_menu(bt_course root, s_link student1);//主菜单
void course_menu(bt_course root, s_link student1);//课程管理菜单
void student_menu(bt_course root, s_link student1);//学生管理菜单
s_link InitList();//初始化
s_link stu_add(s_link student1, bt_course root);//往存储学生信息的链表添加学生
int search_stu(s_link student1, int id);//确认要添加的学生是否存在
s_link stu_add_grade(s_link q, bt_course root);//给学生添加成绩
void stu_delete(s_link student1);//学生节点的删除
void stu_info_change(s_link student1);//学生信息修改
void search_grade_change_stu(s_link student1);//查找需要修改成绩的学生节点
s_link stu_grade_change(s_link p);//对查找到的学生节点成绩进行修改
void stu_search(s_link student1);//学生查询
void stu_print(s_link student1);//学生输出
bt_course course_add(bt_course root1);//课程添加
bt_course course_delete(bt_course root1);//课程删除
void course_change(bt_course root1);//课程修改
void course_search(bt_course root1);//输入需要查询的课程
void course_BST(bt_course root, int key);//课程的排序树搜索
void print_course_with_print(bt_course root);
void course_In_print(bt_course root1);//课程中序遍历
void course_Post_print(bt_course root1);//课程后续遍历
void search_course_node(bt_course root);
int course_add_stu(stu_c_link p, int num);//给课程节点添加学生信息
void course_stu_print(stu_c_link q);//输出与课程连接的学生信息
int course_num = 0;
/**
*主函数，程序入口
*/
int main() {
	bt_course root = (bt_course)malloc(sizeof(course));
	s_link student1 = InitList();
	main_menu(root, student1);
	system("pause");
	return 0;
}
/**
*主菜单选项
*/
void main_menu(bt_course root, s_link student1) {
	printf("\t\t*********************************************************\n");
	printf("\t\t*************欢迎来到计算机专业课程管理系统**************\n");
	printf("\t\t*\t\t\t1:管理课程\t\t\t*\n");
	printf("\t\t*\t\t\t2:管理学生\t\t\t*\n");
	printf("\t\t*\t\t\t其他：退出\t\t\t*\n");
	printf("\t\t*********************************************************\n");
	printf("\t\t请选择：\n");
	int x;
	scanf("%d", &x);
	switch (x)
	{
	case 1:system("cls"); course_menu(root, student1); break;
	case 2:system("cls"); student_menu(root, student1); break;
	default:system("cls"); exit(0);break;
	}
}
/**
*课程管理部分菜单选项
*/
void course_menu(bt_course root, s_link student1) {
	printf("\t\t*********************************************************\n");
	printf("\t\t******************欢迎来到课程管理中心*******************\n");
	printf("\t\t*\t\t\t1:课程增加\t\t\t*\n");
	printf("\t\t*\t\t\t2:课程删除\t\t\t*\n");
	printf("\t\t*\t\t\t3:课程修改\t\t\t*\n");
	printf("\t\t*\t\t\t4:课程查询\t\t\t*\n");
	printf("\t\t*\t\t\t5:课程输出\t\t\t*\n");
	printf("\t\t*\t\t\t6:输出所有课程及其学生名单\t*\n");
	printf("\t\t*\t\t\t7:增加学生\t\t\t*\n");
	printf("\t\t*\t\t\t8:返回上层\t\t\t*\n");
	printf("\t\t*\t\t\t其他：退出\t\t\t*\n");
	printf("\t\t*********************************************************\n");
	printf("\t\t请选择：\n");
	int ch;
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:system("cls"); 
		   root = course_add(root); 
		   system("pause");
		   system("cls"); 
		   course_menu(root, student1);
		   break;
	case 2:system("cls");
		   root = course_delete(root); 
		   system("pause"); 
		   system("cls"); 
		   course_menu(root, student1);
		   break;
	case 3:system("cls"); 
		   course_change(root); 
		   system("pause");
		   system("cls"); 
		   course_menu(root, student1);
		   break;
	case 4:system("cls"); 
		   course_search(root); 
		   system("pause"); 
		   system("cls"); 
		   course_menu(root, student1);
		   break;
	case 5:system("cls");
		   if (course_num == 0)
			   printf("课程为空，不能输出！\n");
		   else {
			   printf("中序：\n");
			   printf("%-10s|  %-20s|  %-10s|  %-10s\n", "课程代码", "课程名称", "课程学分", "选课人数");
			   course_In_print(root);
			   printf("后序：\n");
			   printf("%-10s|  %-20s|  %-10s|  %-10s\n", "课程代码", "课程名称", "课程学分", "选课人数");
			   course_Post_print(root);

		   }
		   system("pause");
		   system("cls");
		   course_menu(root, student1);
		   break;
	case 6:system("cls"); 
		   if (course_num == 0)
				printf("课程为空，不能输出！\n");
		   else {
			   print_course_with_print(root);
		   } 
		   system("pause"); 
		   system("cls"); 
		   course_menu(root, student1);
		   break;
	case 7:system("cls"); 
		   //course_add_stu();
		   system("pause");
		   system("cls"); 
		   course_menu(root, student1);
		   break;
	case 8:system("cls"); 
		   main(); 
		   break;
	default:system("cls"); 
			exit(0);
			break;
	}
}
/**
*课程管理部分的操作函数
*/
bt_course course_add(bt_course root) {
	bt_course p = root, r = (bt_course)malloc(sizeof(course));
	printf("请输入要添加的课程信息（代码 名称 学分）：");
	int id;
	char name[50];
	float credit;
	scanf("%d", &id);
	scanf("%s", name);
	scanf("%f", &credit);
	printf("你要添加的课程信息如下：\n");
	printf("课程代码：%d  课程名：%s  学分：%.2f\n", id, name, credit);
	char c;
	printf("确认添加？（Y/N）\n");
	scanf("\n%c",&c);
	if (c == 'y' || c == 'Y') {
		if (course_num == 0) {
			p->course_id = id;
			strcpy(p->course_name, name);
			p->credit = credit;
			p->stu_num = 0;
			p->lc = p->rc = NULL;
			p->link = (stu_c_link)malloc(sizeof(stu_c));
			p->link->next = NULL;
			course_num++;
			printf("添加成功！\n");
			printf("是否继续为该门课程添加学生？（Y/N）\n");
			char c1;
			scanf("\n%c", &c1);
			if (c1 == 'y' || c1 == 'Y') {
				p->stu_num = course_add_stu(p->link,p->stu_num);
			}
			return root;
		}
		while (p) {
			if (id == p->course_id) {
				printf("该代码的课程已存在。添加失败！\n");
				return root;
			}
			r = p;
			if (id <  p->course_id)
				p = p->lc;
			else
				p = p->rc;
		}
		p = (bt_course)malloc(sizeof(course));
		p->course_id = id;
		strcpy(p->course_name, name);
		p->credit = credit;
		p->stu_num = 0;
		p->lc = p->rc = NULL;
		p->link = (stu_c_link)malloc(sizeof(stu_c));
		p->link->next = NULL;
		if (id < r->course_id)
			r->lc = p;
		else
			r->rc = p;
		course_num++;
		printf("添加成功！\n");
		printf("是否继续为该门课程添加学生？（Y/N）\n");
		char c1;
		scanf("\n%c", &c1);
		if (c1 == 'y' || c1 == 'Y') {
			course_add_stu(p->link, p->stu_num);
			p->stu_num++;
		}
		return root;
	}
	else
		return root;
}
bt_course course_delete(bt_course root) {
	
	//寻找要删除的节点及其双亲节点
	if (course_num == 0)
		printf("课程为空，不能删除\n");
	else {
		int course_id;
		printf("请输入要删除的课程代码：\n");
		scanf("%d", &course_id);
		bt_course del_node = root;
		bt_course par_of_del_node = NULL;
		bt_course sub_node, par_of_sub_node;
		while (del_node != NULL && course_id != del_node->course_id) {
			par_of_del_node = del_node;
			if (del_node->course_id > course_id)
				del_node = del_node->lc;
			else
				del_node = del_node->rc;
		}
		if (del_node == NULL)
		{
			printf("该课程不存在!\n");
			return root;
		}
		//删除叶子节点
		if (del_node->lc == NULL && del_node->rc == NULL) {
			//删除的节点为根
			if (par_of_del_node == NULL)
				root = NULL;
			else if (par_of_del_node->lc == del_node)
				par_of_del_node->lc = NULL;
			else
				par_of_del_node->rc = NULL;
			free(del_node);
		}
		//删除的节点有左子树
		else if (del_node->lc != NULL && del_node->rc == NULL) {
			//删除的节点为根节点
			if (par_of_del_node == NULL)
				root = del_node->lc;
			else if (par_of_del_node->rc == del_node)
				par_of_del_node->rc = del_node->lc;
			else
				par_of_del_node->lc = del_node->lc;
			free(del_node);
		}
		//删除的节点有右子树
		else if (del_node->lc == NULL && del_node->rc != NULL) {
			//删除的节点为根节点
			if (par_of_del_node == NULL)
				root = del_node->rc;
			else if (par_of_del_node->rc == del_node)
				par_of_del_node->rc = del_node->rc;
			else
				par_of_del_node->lc = del_node->rc;
			free(del_node);
		}
		//删除的节点既有左子树又有右子树
		else {
			par_of_sub_node = del_node;
			sub_node = del_node->lc;
			//寻找替代节点和双亲节点
			while (sub_node->rc != NULL) {
				par_of_sub_node = sub_node;
				sub_node = sub_node->rc;
			}

			if (par_of_sub_node != del_node) {
				sub_node->rc = del_node->rc;
				sub_node->lc = del_node->lc;
				par_of_sub_node->rc = NULL;
				//删除节点为根节点
				if (par_of_del_node == NULL) {
					root->course_id = sub_node->course_id;
					strcpy(root->course_name, sub_node->course_name);
					root->credit = sub_node->credit;
					root->stu_num = sub_node->stu_num;
					root->link = sub_node->link;
				}
				else {
					if (par_of_del_node->lc == del_node)
						par_of_del_node->lc = sub_node;
					else
						par_of_del_node->rc = sub_node;
				}
			}

			if (par_of_sub_node == del_node) {
				del_node->course_id = sub_node->course_id;
				strcpy(del_node->course_name, sub_node->course_name);
				del_node->credit = sub_node->credit;
				del_node->stu_num = sub_node->stu_num;
				del_node->link = sub_node->link;
				if (par_of_sub_node->rc == sub_node)
					del_node->rc = NULL;
				else
					del_node->lc = NULL;
			}
			else
				par_of_sub_node->rc = NULL;
			free(sub_node);
		}
		course_num--;
		printf("删除成功\n");
		if(course_num==0)
			return root = (bt_course)malloc(sizeof(course));
		return root;
	}
	
}
void course_change(bt_course root) {
	if (course_num == 0) {
		printf("课程为空，不能修改！\n");
		return;
	}
	else {
		int flag = 0;
		bt_course p = root;
		int id;
		char name[50];
		float credit;
		printf("请输入要修改的课程信息（代码 名称 学分）：");
		scanf("%d", &id);
		scanf("%s", name);
		scanf("%f", &credit);
		printf("你要修改的课程信息如下：\n");
		printf("课程代码：%d  课程名：%s  学分：%.2f\n", id, name, credit);
		char c;
		printf("确认修改？（Y/N）\n");
		fflush(stdin);
		scanf("\n%c", &c);
		if (c == 'y' || c == 'Y') {
			if (p == NULL)
				printf("该门课程不存在\n");
			if (p != NULL) {
				while (p) {
					if (p->course_id == id) {
						flag = 1;
						strcpy(p->course_name, name);
						p->credit = credit;
						printf("修改成功！\n");
						return;
					}
					else if (p->course_id > id)
						p = p->lc;
					else
						p = p->rc;
				}
			}
			if (!flag)
				printf("该门课程不存在！\n");
		}
		else
			course_change(root);
	}
	
}
void course_search(bt_course root) {
	if (course_num == 0) {
		printf("课程为空，不能查询！\n");
		return;
	}
	else {
		int key;
		printf("请输入要查询的课程代码：\n");
		scanf("%d", &key);
		course_BST(root, key);
	}
}
void course_BST(bt_course root,int key) {
	int flag=0;
	bt_course p = root;
	if (p == NULL)
		printf("该门课程不存在\n");
	if (p != NULL) {
		while (p) {
			if (p->course_id == key) {
				flag = 1;
				printf("%-10s|  %-20s|  %-10s|  %-10s\n","课程代码","课程名称","课程学分","选课人数");
				printf("%-10d|  %-20s|  %-10.2f|  %-10d\n", p->course_id, p->course_name, p->credit, p->stu_num);
				return;
			}
			else if (p->course_id > key)
				p = p->lc;
			else
				p = p->rc;
		}
	}
	if (!flag)
		printf("查询失败，该门课程不存在！\n");
}
void print_course_with_print(bt_course root) {
	if (root != NULL) {
		print_course_with_print(root->lc);
		printf("%-10s|  %-20s|  %-10s|  %-10s\n", "课程代码", "课程名称", "课程学分", "选课人数");
		printf("%-10d|  %-20s|  %-10.2f|  %-10d\n", root->course_id, root->course_name, root->credit, root->stu_num);
		printf("-------------------------学生名单-------------------------\n");
		course_stu_print(root->link);
		printf("----------------------------------------------------------\n");
		print_course_with_print(root->rc);
	}
}
void course_In_print(bt_course root) {
	if (root != NULL) {
		course_Post_print(root->lc);
		printf("%-10d|  %-20s|  %-10.2f|  %-10d\n", root->course_id, root->course_name, root->credit, root->stu_num);
		course_Post_print(root->rc);
	}
}
void course_Post_print(bt_course root) {
	if (root != NULL) {
		course_Post_print(root->lc);
		course_Post_print(root->rc);
		printf("%-10d|  %-20s|  %-10.2f|  %-10d\n", root->course_id, root->course_name, root->credit, root->stu_num);
	}
}
void search_course_node(bt_course root) {

}
int course_add_stu(stu_c_link q,int num) {
	stu_c_link p = q,s=(stu_c_link)malloc(sizeof(stu_c));
	printf("请输入要添加的学生学号、姓名、成绩(输入0 0 0结束）：\n");
	int id;
	char name[50];
	int score;
	do {
		scanf("%d", &id);
		scanf("%s", name);
		scanf("%d", &score);
		if (id != 0 && strcmp(name, "0") != 0 && score != 0) {
			p = q;
			s = (stu_c_link)malloc(sizeof(stu_c));
			s->s_id = id;
			strcpy(s->s_name, name);
			s->g = score;
			if (num == 0) {
				s->next = p->next;
				p->next = s;
			}
			else {
				p = q;
				while (p&&p->next) {//查找插入的位置 
					if (score > p->next->g) {//元素从小到大排序，当比较到后一个节点大于要插入的节点时进行插入 
						s->next = p->next;
						p->next = s;
						break;
					}
					p = p->next;
				}
				if (!p->next) { //如果比较到最后一个都没有比当前大的则插入到最后 
					p->next = s;
					s->next = NULL;
				}
			}
			num++;
		}
	} while (id != 0 && strcmp(name, "0") != 0 && score != 0);
	return num;
}
void course_stu_print(stu_c_link q) {
	q = q->next;  
	printf("%-10s|%-10s|%-4s\n", "学号","姓名","成绩");
	while (q) {
		printf("%-10d|%-10s|%-4d\n", q->s_id, q->s_name, q->g);
		q = q->next;
	}
}
/**
*学生管理部分菜单选项
*/
void student_menu(bt_course root, s_link student1) {
	printf("\t\t*********************************************************\n");
	printf("\t\t******************欢迎来到课程管理中心*******************\n");
	printf("\t\t*\t\t\t1:学生增加\t\t\t*\n");
	printf("\t\t*\t\t\t2:学生删除\t\t\t*\n");
	printf("\t\t*\t\t\t3:学生信息修改\t\t\t*\n");
	printf("\t\t*\t\t\t4:学生成绩修改\t\t\t*\n");
	printf("\t\t*\t\t\t5:学生信息查询\t\t\t*\n");
	printf("\t\t*\t\t\t6:学生信息输出\t\t\t*\n");
	printf("\t\t*\t\t\t7:返回上层\t\t\t*\n");
	printf("\t\t*\t\t\t其他：退出\t\t\t*\n");
	printf("\t\t*********************************************************\n");
	printf("\t\t请选择：\n");
	int ch;
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:system("cls"); 
		   student1 = stu_add(student1,root);
		   system("pause");
		   system("cls");
		   student_menu(root, student1);
		   break;
	case 2:system("cls");
		   stu_delete(student1); 
		   system("pause");
		   system("cls"); 
		   student_menu(root, student1); 
		   break;
	case 3:system("cls"); 
		   stu_info_change(student1); 
		   system("pause");
		   system("cls"); 
		   student_menu(root, student1); 
		   break;
	case 4:system("cls");  
		   search_grade_change_stu(student1);
		   system("pause");
		   system("cls"); 
		   student_menu(root, student1); 
		   break;
	case 5:system("cls"); 
		   stu_search(student1);
		   system("pause");
		   system("cls"); 
		   student_menu(root, student1);
		   break;
	case 6:system("cls"); 
		   stu_print(student1); 
		   system("pause");
		   system("cls"); 
		   student_menu(root, student1);
		   break;
	case 7:system("cls");
		   main(); 
		   break;
	default:system("cls");
		    exit(0); 
			break;
	}
}
/**
*学生管理部分函数操作
*/
s_link InitList()//初始化链表 
{
	s_link h = (s_link)malloc(sizeof(student));
	if (!h)//判断是否为h分配到所需空间 
	{
		printf("初始化链表错误！\n");
		exit(0);
	}
	h->next = NULL;
	return h;
}
s_link stu_add(s_link student1, bt_course root) {
	printf("请输入添加学生的信息：\n");
	int id;
	char name[50];
	char c;
	do {
		scanf("%d", &id);
		scanf("%s", name);
		if (id < 1000000000 || id>9999999999)
			printf("你所输入的学号不符合规范，请重新输入学生信息：\n");
	} while (id < 1000000000 || id>9999999999);
	if (search_stu(student1,id)) {
		printf("学号为%d的学生已存在，添加失败！：\n", id);
		return student1;
	}
	printf("即将添加的学生信息为：\n学号：%d  姓名：%s\n", id, name);
	printf("确认添加？（Y/N）\n");
	scanf("\n%c", &c);
	s_link p = student1;
	s_link q = (s_link)malloc(sizeof(student));
	if (c == 'y' || c == 'Y') {
		q->s_id = id;
		strcpy(q->s_name, name);
		q->c_num = 0;
		q->next = p->next;
		p->next = q;
	}
	else {
		system("cls");
		stu_add(student1,root);
	}
	char ch;
	printf("继续添加该学生的成绩？（Y/N）\n");
	fflush(stdin);
	scanf("\n%c", &ch);
	if (ch == 'y' || ch == 'Y') {
		stu_add_grade(q,root);
	}
	return student1;
}
int search_stu(s_link student1,int id) {
	s_link p = student1->next;
	while (p) {
		if (p->s_id == id)
			return 1;
		p = p->next;
	}
	return 0;
}
s_link stu_add_grade(s_link q, bt_course root) {
	if (course_num == 0) {
		printf("当前没有课程，不能添加成绩！\n");
		return q;
	}
	else {
		if (q->c_num >= 10) {
			printf("该学生当前课程数量已达到上限！请删除相关课程后再操作！\n");
			return q;
		}
		else {
			printf("请输入要添加的课程名称及该门课程的成绩（以0 0结束）：\n");
			char cou_name[50];
			int cou_g;
			do {
				if (q->c_num >= 10) {
					printf("该学生当前课程数量已达到上限！不能继续添加！\n");
					return q;
				}
				else {
						scanf("%s", cou_name);
					do {
						scanf("%d", &cou_g);
						if (cou_g < 0 || cou_g>100)
							printf("输入成绩不符合规范，成绩范围为[0,100]，请重新输入：\n");
					} while (cou_g < 0 || cou_g>100);
					if (strcmp(cou_name, "0") != 0 || cou_g != 0) {
						strcpy(q->g[q->c_num].course_name, cou_name);
						q->g[q->c_num].g = cou_g;
						q->c_num = q->c_num + 1;
					}
				}
			} while (strcmp(cou_name, "0") != 0 || cou_g != 0);
			printf("成绩添加结束！\n");
			return q;
		}
	}
	

}
void stu_delete(s_link student1) {
	s_link p = student1;
	if (p->next) {
		printf("请选择按学号（1）删除或者按姓名（2）删除(1/2),选择其他项返回上一层：\n");
		int c;
		scanf("%d", &c);
		if (c == 1) {
			int id;
			printf("请输入你要删除的学生学号：\n");
			scanf("%d", &id);
			while (p->next) {
				if (p->next->s_id == id) {
					s_link q = p->next;
					p->next = q->next;
					printf("删除成功！\n");
					return;
				}
				p = p->next;
			}
			printf("该学生不存在！\n");
		}
		else if (c == 2) {
			char name[50];
			printf("请输入你要删除的学生姓名：\n");
			scanf("%s", name);
			while (p->next) {
				if (strcmp(p->next->s_name, name) == 0) {
					s_link q = p->next;
					p->next = q->next;
					printf("删除成功！\n");
					return;
				}
				p = p->next;
			}
			printf("该学生不存在！\n");
		}
		else {
			system("cls");
			return;
		}
	}
	else {
		printf("学生信息链表为空，不能删除！\n");
		return;
	}
}
void stu_info_change(s_link student1) {
	s_link p = student1->next;
	if (p) {
		printf("请选择按学号（1）修改或者按姓名（2）修改(1/2),选择其他项返回上一层：\n");
		int c;
		scanf("%d", &c);
		if (c == 1) {
			int id;
			char name[50];
			printf("请输入你要修改信息的学生学号：\n");
			scanf("%d", &id);
			printf("请输入修改后的学生姓名：\n");
			scanf("%s", name);
			while (p) {
				if (p->s_id == id) {
					strcpy(p->s_name, name);
					printf("修改成功！\n");
					return;
				}
				p = p->next;
			}
			printf("该学生不存在！\n");
		}
		else if (c == 2) {
			int id;
			char name[50];
			printf("请输入你要修改的学生姓名：\n");
			scanf("%s", name);
			printf("请输入修改后的学生学号：\n");
			scanf("%d", &id);
			while (p) {
				if (strcmp(p->next->s_name, name) == 0) {
					p->s_id = id;
					printf("修改成功！\n");
					return;
				}
				p = p->next;
			}
			printf("该学生不存在！\n");
		}
		else {
			system("cls");
			return;
		}
	}
	else {
		printf("学生信息链表为空，不能修改！\n");
		return;
	}
}
void search_grade_change_stu(s_link student1) {
	s_link p = student1->next;
	if (p) {
		printf("请选择按学号（1）修改或者按姓名（2）修改(1/2),选择其他项返回上一层：\n");
		int c;
		scanf("%d", &c);
		if (c == 1) {
			int id;
			printf("请输入你要修改信息的学生学号：\n");
			scanf("%d", &id);
			while (p) {
				if (p->s_id == id) {
					p = stu_grade_change(p);
					return;
				}
				p = p->next;
			}
			printf("该学生不存在！\n");
		}
		else if (c == 2) {
			char name1[50];
			printf("请输入你要修改的学生姓名：\n");
			scanf("%s", name1);
			while (p) {
				if (strcmp(p->s_name, name1) == 0) {
					p = stu_grade_change(p);
					system("pause");
					return;
				}
				p = p->next;
			}
			printf("该学生不存在！\n");
			system("pause");
		}
		else {
			system("cls");
			return;
		}
	}
	else {
		printf("学生信息链表为空，不能修改！\n");
		return;
	}
}
s_link stu_grade_change(s_link p) {

	printf("请输入你要修改的课程名及修改后的成绩：\n");
	int g,i;
	char name[50];
	scanf("%s", name);
	scanf("%d", &g);
	for (i = 0; i < p->c_num; i++) {
		if (strcmp(p->g[i].course_name, name) == 0) {
			p->g[i].g = g;
			return p;
		}
	}
	printf("该门课程不存在，请先去添加！\n");
	return p;
}
void stu_search(s_link student1) {
	s_link p = student1;
	if (p->next) {
		printf("请选择按学号（1）查询或者按姓名（2）查询(1/2),选择其他项返回上一层：\n");
		int c;
		scanf("%d", &c);
		if (c == 1) {
			int id;
			printf("请输入你要查询的学生学号：\n");
			scanf("%d", &id);
			while (p->next) {
				if (p->next->s_id == id) {
					stu_print(p);
					system("pause");
					return;
				}
				p = p->next;
			}
			printf("该学生不存在！\n");
		}
		else if (c == 2) {
			char name1[50];
			printf("请输入你要查询的学生姓名：\n");
			scanf("%s", name1);
			while (p->next) {
				if (strcmp(p->next->s_name, name1) == 0) {
					stu_print(p);
					return;
				}
				p = p->next;
			}
			printf("该学生不存在！\n");
		}
		else {
			system("cls");
			return;
		}
	}
	else {
		printf("学生信息链表为空，不能查询！\n");
		return;
	}
}
void stu_print(s_link student1) {
	s_link p = student1->next;
	if (p) {
		printf("%-10s|%-10s|%-16s\n", "学号", "姓名", "课程及其成绩");
		while (p) {
			printf("%-10d|%-10s|", p->s_id, p->s_name);
			if (p->c_num != 0) {
			int i;
			for (i = 0; i < p->c_num; i++) {
				if(i == 0)
					printf("%-s:%d\n", p->g[i].course_name, p->g[i].g);
				else
					printf("\t\t     |%s:%d\n", p->g[i].course_name, p->g[i].g);
				}
			}
			p = p->next;
		}
	}
	else {
		printf("学生信息链表为空，不能输出！\n");
		return;
	}
}
