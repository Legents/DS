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
/************
* 函数声明
*************/
void main_menu(bt_course root, s_link student1);//主菜单
void course_menu(bt_course root, s_link student1);//课程管理菜单
bt_course course_add(bt_course root);//课程添加
bt_course course_delete(bt_course root);//课程删除
void course_change(bt_course root);//课程修改
void course_search(bt_course root);//课程查找
void course_BST(bt_course root, int key);//课程的二分查找
void print_course_with_stu(bt_course root);//将课程与该门课程的学生一起输出
void course_In_print(bt_course root);//中序
void course_Post_print(bt_course root);//后序
void search_course_node(bt_course root);//查找需要的课程节点
int course_add_stu(stu_c_link q, int num);//给新建的课程节点添加学生信息
void course_stu_print(stu_c_link q);//每门课程的学生名单输出
int course_confirmation(bt_course root);//确认该门课程是否存在
void student_menu(bt_course root, s_link student1);//学生管理菜单
s_link InitList();//学生链表初始化
s_link stu_add(s_link student1, bt_course root);//学生添加
int search_stu(s_link student1, int id);//查找添加的学生是否存在
s_link stu_add_grade(s_link q, bt_course root);//给学生链表添加成绩
bt_course search_course_node2(bt_course root);//给学生添加成绩时查找到该门课程在二叉树的位置，将学生信息插入
void stu_delete(s_link student1, bt_course root);//学生删除
void InOrder_delete_with_id(bt_course root);//按学号删除时查找
int stu_node_delete_with_id(stu_c_link p,int num);//按学号删除时遍历每个节点删除对应的学生
void InOrder_delete_with_name(bt_course root);//删掉该节点上的学生中需要删除的学生
int stu_node_delete_with_name(stu_c_link p,int num);//按姓名删除时遍历每个节点删除对应的学生
void stu_info_change(s_link student1, bt_course root);//删掉该节点上的学生中需要删除的学生
void InOrder_change_with_id(bt_course root);//按学号修改时遍历每个节点修改对应的学生
void stu_node_change_with_id(stu_c_link p);//修改该节点上的学生中需要修改的学生信息
void InOrder_change_with_name(bt_course root);//按姓名修改时遍历每个节点修改对应的学生
void stu_node_change_with_name(stu_c_link p);//修改该节点上的学生中需要修改的学生信息
void search_grade_change_stu(s_link student1, bt_course root);//学生信息修改前期选择
s_link stu_grade_change(s_link p, bt_course root, int choose);//成绩修改函数
void search_change_course_node_id(bt_course root);//对学生成绩修改时在课程树中找到该课程的节点传给修改的函数（按学号修改）
void change_grade_in_course_id(stu_c_link q);//在该课程的学生链表中根据学号找到要修改成绩的学生节点并修改其成绩
void search_change_course_node_name(bt_course root);//对学生成绩修改时在课程树中找到该课程的节点传给修改的函数（按姓名修改）
void change_grade_in_course_name(stu_c_link q);//在该课程的学生链表中根据姓名找到要修改成绩的学生节点并修改其成绩
void stu_search(s_link student1);//学生查找
void stu_print(s_link student1);//学生输出
void course_statistics(bt_course root);//信息统计函数
void average(bt_course c);
bt_course root = (bt_course)malloc(sizeof(course));
int course_num = 0;
char sear_course_name[50];
int delete_s_id;
char delete_s_name[50];
int change_s_id;
char change_s_name[50];
int change_grade;
char change_c_name[50];
/**
*主函数，程序入口
*/
int main() {
	bt_course root = (bt_course)malloc(sizeof(course));
	root->lc = root->rc = NULL;
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
	printf("\t\t*\t\t\t8:成绩统计\t\t\t*\n");
	printf("\t\t*\t\t\t9:返回上层\t\t\t*\n");
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
			   print_course_with_stu(root);
		   } 
		   system("pause"); 
		   system("cls"); 
		   course_menu(root, student1);
		   break;
	case 7:system("cls");
		   if (course_num == 0) {
			   printf("当前课程为空，不能添加学生！\n");

		   }
		   else {
			   printf("请输入你要添加学生的课程名称：\n");
			   char name[50];
			   scanf("%s", sear_course_name);
			   search_course_node(root);
		   }
		   system("pause");
		   system("cls"); 
		   course_menu(root, student1);
		   break;
	case 8:system("cls");
		   if (course_num == 0)
				printf("课程为空，不能输出！\n");
           else {
			   course_statistics(root);
		   }
		   system("pause");
		   system("cls");
		   course_menu(root, student1);
		   break;
	case 9:system("cls"); 
		   main_menu(root,student1);
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
			p->stu_num = course_add_stu(p->link, p->stu_num);
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
void print_course_with_stu(bt_course root) {
	if (root != NULL) {
		print_course_with_stu(root->lc);
		printf("%-10s|  %-20s|  %-10s|  %-10s\n", "课程代码", "课程名称", "课程学分", "选课人数");
		printf("%-10d|  %-20s|  %-10.2f|  %-10d\n", root->course_id, root->course_name, root->credit, root->stu_num);
		printf("-------------------------学生名单-------------------------\n");
		course_stu_print(root->link);
		printf("----------------------------------------------------------\n");
		print_course_with_stu(root->rc);
	}
}
void course_In_print(bt_course root) {
	if (root != NULL) {
		course_In_print(root->lc);
		printf("%-10d|  %-20s|  %-10.2f|  %-10d\n", root->course_id, root->course_name, root->credit, root->stu_num);
		course_In_print(root->rc);
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
	if (root != NULL) {
		search_course_node(root->lc);
		if (strcmp(root->course_name, sear_course_name)==0) {
			root->stu_num = course_add_stu(root->link, root->stu_num);
			return;
		}
		search_course_node(root->rc);
	}
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
int course_confirmation(bt_course root) {
	if (root != NULL) {
		search_course_node(root->lc);
		if (strcmp(root->course_name, sear_course_name) == 0) {
			return 1;
		}
		search_course_node(root->rc);
	}
	return 0;
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
		   stu_delete(student1, root);
		   system("pause");
		   system("cls"); 
		   student_menu(root, student1); 
		   break;
	case 3:system("cls"); 
		   stu_info_change(student1,root); 
		   system("pause");
		   system("cls"); 
		   student_menu(root, student1); 
		   break;
	case 4:system("cls");  
		   search_grade_change_stu(student1,root);
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
		   main_menu(root, student1);
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
	s_link p = student1;
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
	s_link q = (s_link)malloc(sizeof(student));
	if (c == 'y' || c == 'Y') {
		q->s_id = id;
		strcpy(q->s_name, name);
		q->c_num = 0;
		if (student1->next == NULL) {
			q->next = p->next;
			p->next = q;
		}
		else {
			while (p&&p->next) {
				if (id < p->next->s_id) {
					q->next = p->next;
					p->next = q;
					break;
				}
				p = p->next;
			}
			if (!p->next) {
				q->next = p->next;
				p->next = q;
			}
		}
	}
	else {
		system("cls");
		stu_add(student1,root);
	}
	char ch;
	printf("继续添加该学生的成绩？（Y/N）\n");
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
			printf("当前的所有课程如下，请添加：\n");
			printf("%-10s|  %-20s|  %-10s|  %-10s\n", "课程代码", "课程名称", "课程学分", "选课人数");
			course_Post_print(root);
			int cou_g;
			do {
				if (q->c_num >= 10) {
					printf("该学生当前课程数量已达到上限！不能继续添加！\n");
					return q;
				}
				else {
					printf("请输入要添加的课程名称及该门课程的成绩，成绩的范围为[0,100]。（以0 0结束）：\n");
					scanf("%s", sear_course_name);
					scanf("%d", &cou_g);
					if (strcmp(sear_course_name, "0") != 0 || cou_g != 0) {
						if (course_confirmation(root) == 1 && cou_g >= 0 && cou_g <= 100) {
							strcpy(q->g[q->c_num].course_name, sear_course_name);
							q->g[q->c_num].g = cou_g;
							q->c_num = q->c_num + 1;

							bt_course btc=search_course_node2(root);
							stu_c_link p = btc->link;
							stu_c_link s = (stu_c_link)malloc(sizeof(stu_c));
							s->s_id = q->s_id;
							strcpy(s->s_name, q->s_name);
							s->g = cou_g;
							if (btc->stu_num == 0) {
								s->next = p->next;
								p->next = s;
							}
							else {
								p = btc->link;
								while (p&&p->next) {//查找插入的位置 
									if (cou_g > p->next->g) {//元素从小到大排序，当比较到后一个节点大于要插入的节点时进行插入 
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
							btc->stu_num++;
						}
						else {
							if (course_confirmation(root) != 1 && (cou_g >= 0 && cou_g <= 100)) {
								printf("该门课程不在课程列表中，不能添加!\n");
								continue;
							}
							if ((cou_g < 0 || cou_g>100) && course_confirmation(root) == 1) {
								printf("输入成绩格式不符，范围应该为[0,100],请重新输入！\n");
								continue;
							}
							if (course_confirmation(root) != 1 && (cou_g < 0 || cou_g>100)) {
								printf("该门课程不在课程列表中，不能添加！而且输入成绩格式不符，请重新输入！\n");
								continue;
							}
						}
					}
				}
			} while (strcmp(sear_course_name, "0") != 0 || cou_g != 0);
			printf("成绩添加结束！\n");
			return q;
		}
	}
}
bt_course search_course_node2(bt_course root) {
	if (root != NULL) {
		search_course_node(root->lc);
		if (strcmp(root->course_name, sear_course_name) == 0) {
			return root;
		}
		search_course_node(root->rc);
	}
}
void stu_delete(s_link student1, bt_course root) {
	s_link p = student1;
	if (p->next) {
		printf("请选择按学号（1）删除或者按姓名（2）删除(1/2),选择其他项返回上一层：\n");
		int c;
		scanf("%d", &c);
		if (c == 1) {
			printf("请输入你要删除的学生学号：\n");
			scanf("%d", &delete_s_id);
			while (p->next) {
				if (p->next->s_id == delete_s_id) {
					s_link q = p->next;
					p->next = q->next;
					InOrder_delete_with_id(root);
					printf("删除成功！\n");
					return;
				}
				p = p->next;
			}
			printf("该学生不存在！\n");
		}
		else if (c == 2) {
			printf("请输入你要删除的学生姓名：\n");
			scanf("%s", delete_s_name);
			while (p->next) {
				if (strcmp(p->next->s_name, delete_s_name) == 0) {
					s_link q = p->next;
					p->next = q->next;
					InOrder_delete_with_name(root);
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
void InOrder_delete_with_id(bt_course root) {
	if (root) {
		InOrder_delete_with_id(root->lc);
		root->stu_num=stu_node_delete_with_id(root->link, root->stu_num);
		InOrder_delete_with_id(root->rc);
	}
}
int stu_node_delete_with_id(stu_c_link p,int num) {
	stu_c_link q = p;
	if (q->s_id == delete_s_id){
		p = p->next;
		num--;
		return num;
	}
	if (q&&q->next) {
		while (q&&q->next) {
			if (q->next->s_id == delete_s_id) {
				q->next = q->next->next;
				num--;
				return num;
			}
			q = q->next;
		}
	}
}
void InOrder_delete_with_name(bt_course root) {
	if (root) {
		InOrder_delete_with_name(root->lc);
		root->stu_num=stu_node_delete_with_name(root->link, root->stu_num);
		InOrder_delete_with_name(root->rc);
	}
}
int stu_node_delete_with_name(stu_c_link p,int num) {
	stu_c_link q = p;
	if (strcmp(q->s_name, delete_s_name)==0) {
		p = p->next;
		num--;
		return num;
	}
	if (q&&q->next) {
		while (q&&q->next) {
			if (strcmp(q->next->s_name,delete_s_name)==0) {
				q->next = q->next->next;
				num--;
				return num;
			}
			q = q->next;
		}
	}
}
void stu_info_change(s_link student1, bt_course root) {
	s_link p = student1->next;
	if (p) {
		printf("请选择按学号（1）修改或者按姓名（2）修改(1/2),选择其他项返回上一层：\n");
		int c;
		scanf("%d", &c);
		if (c == 1) {
			printf("请输入你要修改信息的学生学号：\n");
			scanf("%d", &change_s_id);
			printf("请输入修改后的学生姓名：\n");
			scanf("%s", change_s_name);
			while (p) {
				if (p->s_id == change_s_id) {
					strcpy(p->s_name, change_s_name);
					InOrder_change_with_id(root);
					printf("修改成功！\n");
					return;
				}
				p = p->next;
			}
			printf("该学生不存在！\n");
		}
		else if (c == 2) {
			printf("请输入你要修改的学生姓名：\n");
			scanf("%s", change_s_name);
			printf("请输入修改后的学生学号：\n");
			scanf("%d", &change_s_id);
			while (p) {
				if (strcmp(p->s_name, change_s_name) == 0) {
					p->s_id = change_s_id;
					InOrder_change_with_name(root);
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
void InOrder_change_with_id(bt_course root) {
	if (root) {
		InOrder_change_with_id(root->lc);
		stu_node_change_with_id(root->link);
		InOrder_change_with_id(root->rc);
	}
}
void stu_node_change_with_id(stu_c_link p) {
	stu_c_link q = p;
		while (q) {
			if (q->s_id == change_s_id) {
				strcpy(q->s_name,change_s_name);
				return;
			}
			q = q->next;
		}
}
void InOrder_change_with_name(bt_course root) {
	if (root) {
		InOrder_change_with_name(root->lc);
		stu_node_change_with_name(root->link);
		InOrder_change_with_name(root->rc);
	}
}
void stu_node_change_with_name(stu_c_link p) {
	stu_c_link q = p;
	while (q) {
		if (strcmp(q->s_name, change_s_name)==0) {
			q->s_id = change_s_id;
			return;
		}
		q = q->next;
	}
}
void search_grade_change_stu(s_link student1,bt_course root) {
	s_link p = student1->next;
	if (p) {
		printf("请选择按学号（1）修改或者按姓名（2）修改(1/2),选择其他项返回上一层：\n");
		int c;
		scanf("%d", &c);
		if (c == 1) {
			printf("请输入你要修改信息的学生学号：\n");
			scanf("%d", &change_s_id);
			while (p) {
				if (p->s_id == change_s_id) {
					p = stu_grade_change(p,root,c);
					return;
				}
				p = p->next;
			}
			printf("该学生不存在！\n");
		}
		else if (c == 2) {
			printf("请输入你要修改的学生姓名：\n");
			scanf("%s", change_s_name);
			while (p) {
				if (strcmp(p->s_name, change_s_name) == 0) {
					p = stu_grade_change(p, root,c);
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
s_link stu_grade_change(s_link p,bt_course root,int choose) {
	printf("请输入你要修改的课程名及修改后的成绩：\n");
	int i;
	scanf("%s", change_c_name);
	scanf("%d", &change_grade);
	for (i = 0; i < p->c_num; i++) {
		if (strcmp(p->g[i].course_name, change_c_name) == 0) {
			p->g[i].g = change_grade;
			if(choose==1)
				search_change_course_node_id(root);
			else if(choose==2)
				search_change_course_node_name(root);
			return p;
		}
	}
	printf("该门课程不存在，请先去添加！\n");
	return p;
}
void search_change_course_node_id(bt_course root) {
	if (root != NULL) {
		search_course_node(root->lc);
		if (strcmp(root->course_name, change_c_name) == 0) {
			change_grade_in_course_id(root->link);
			return;
		}
		search_course_node(root->rc);
	}
}
void change_grade_in_course_id(stu_c_link q) {
	stu_c_link p = q;
	while (p) {
		if (p->s_id == change_s_id) {
			p->g = change_grade;
			return;
		}
		p = p->next;
	}
}
void search_change_course_node_name(bt_course root) {
	if (root != NULL) {
		search_course_node(root->lc);
		if (strcmp(root->course_name, change_c_name) == 0) {
			change_grade_in_course_name(root->link);
			return;
		}
		search_course_node(root->rc);
	}
}
void change_grade_in_course_name(stu_c_link q) {
	stu_c_link p = q;
	while (p) {
		if (strcmp(p->s_name,change_s_name)==0) {
			p->g = change_grade;
			return;
		}
		p = p->next;
	}
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
					printf("%-10s|%-10s|%-16s\n", "学号", "姓名", "课程及其成绩");
					printf("%-10d|%-10s|", p->next->s_id, p->next->s_name);
					if (p->next->c_num != 0) {
						int i;
						for (i = 0; i < p->next->c_num; i++) {
							if (i == 0)
								printf("%-s:%d\n", p->next->g[i].course_name, p->next->g[i].g);
							else
								printf("\t\t     |%s:%d\n", p->next->g[i].course_name, p->next->g[i].g);
						}
					}
					printf("\n");
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
					printf("%-10s|%-10s|%-16s\n", "学号", "姓名", "课程及其成绩");
					printf("%-10d|%-10s|", p->next->s_id, p->next->s_name);
					if (p->next->c_num != 0) {
						int i;
						for (i = 0; i < p->next->c_num; i++) {
							if (i == 0)
								printf("%-s:%d\n", p->next->g[i].course_name, p->next->g[i].g);
							else
								printf("\t\t     |%s:%d\n", p->next->g[i].course_name, p->next->g[i].g);
						}
					}
					printf("\n");
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
			printf("\n");
		}
	}
	else {
		printf("学生信息链表为空，不能输出！\n");
		return;
	}
}
void course_statistics(bt_course root) {
	if (root != NULL) {
		course_statistics(root->lc);
		printf("%-10s|  %-20s|  %-10s|  %-10s\n", "课程代码", "课程名称", "课程学分", "选课人数");
		printf("%-10d|  %-20s|  %-10.2f|  %-10d\n", root->course_id, root->course_name, root->credit, root->stu_num);
		average(root);
		course_statistics(root->rc);
	}
}
void average(bt_course c) {
	stu_c_link c1 = c->link;
	int sum = 0;
	if (c1 == NULL) {
		printf("该课程当前没有学生！\n");
			return;
	}
	else {
		while (c1) {
			sum += c1->g;
			c1 = c1->next;
		}
	}
	printf("%d\t%d\n", sum, c->stu_num);
	float ave = (float)sum / c->stu_num;
	printf("平均分：%.2f", ave);
}