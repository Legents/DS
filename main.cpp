#include<stdio.h>
#include<stdlib.h>
#include<string>
typedef struct stu_c {
	int s_id;
	char s_name[10];
	struct stu_c *next;
}stu_c,*stu_c_link;
typedef struct course {
	int course_id;
	char course_name[10];
	int credit;
	int stu_num;
	struct course *lc, *rc;
	struct stu_c *link;
}course,*bt_course;
typedef struct student {
	int s_id;
	char s_name[10];
	struct grade *g;
	struct student *next;
}student,*s_link;
typedef struct grade {
	char course_name[10];
	int g;
	struct grade *next;
}grade,*g_link;

void main_menu();
void course_menu();
void student_menu();
void stu_add();
void stu_delete();
void stu_change();
void stu_search();
void stu_print();
bt_course course_add(bt_course root);
bt_course course_delete(bt_course root);
void course_change();
void course_search();
void course_print();
void course_add_stu();
bt_course root = (bt_course)malloc(sizeof(course));
static int course_num = 0;
int main() {
	main_menu();
	system("pause");
	return 0;
}

void main_menu() {
	printf("\t\t*********************************************************\n");
	printf("\t\t*************��ӭ���������רҵ�γ̹���ϵͳ**************\n");
	printf("\t\t*\t\t\t1:����γ�\t\t\t*\n");
	printf("\t\t*\t\t\t2:����ѧ��\t\t\t*\n");
	printf("\t\t*\t\t\t�������˳�\t\t\t*\n");
	printf("\t\t*********************************************************\n");
	printf("\t\t��ѡ��\n");
	int x;
	scanf("%d", &x);
	switch (x)
	{
	case 1:system("cls"); course_menu(); break;
	case 2:system("cls"); student_menu(); break;
	default:system("cls"); main();break;
	}
}
void course_menu() {
	printf("\t\t*********************************************************\n");
	printf("\t\t******************��ӭ�����γ̹�������*******************\n");
	printf("\t\t*\t\t\t1:�γ�����\t\t\t*\n");
	printf("\t\t*\t\t\t2:�γ�ɾ��\t\t\t*\n");
	printf("\t\t*\t\t\t3:�γ��޸�\t\t\t*\n");
	printf("\t\t*\t\t\t4:�γ̲�ѯ\t\t\t*\n");
	printf("\t\t*\t\t\t5:�γ����\t\t\t*\n");
	printf("\t\t*\t\t\t6:����ѧ��\t\t\t*\n");
	printf("\t\t*\t\t\t7:�����ϲ�\t\t\t*\n");
	printf("\t\t*\t\t\t�������˳�\t\t\t*\n");
	printf("\t\t*********************************************************\n");
	printf("\t\t��ѡ��\n");
	int ch;
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:system("cls"); root = course_add(root); system("cls"); course_menu(); break;
	case 2:system("cls"); course_delete(root); system("cls"); course_menu(); break;
	case 3:system("cls"); course_change(); system("cls"); course_menu(); break;
	case 4:system("cls"); course_search(); system("cls"); course_menu(); break;
	case 5:system("cls"); course_print(); system("cls"); course_menu(); break;
	case 6:system("cls"); course_add_stu(); system("cls"); course_menu(); break;
	case 7:system("cls"); main(); break;
	default:system("cls"); course_menu(); break;
	}
}
bt_course course_add(bt_course root) {
	bt_course p = root, r = (bt_course)malloc(sizeof(course));
	printf("������Ҫ��ӵĿγ���Ϣ������ ���� ѧ�֣���");
	int id;
	char name[10];
	int credit;
	scanf("%d", &id);
	scanf("%s", name);
	scanf("%d", &credit);
	if (course_num == 0) {
		root->course_id = id;
		strcpy(root->course_name, name);
		root->credit = credit;
		root->stu_num = 0;
		root->lc = root->rc = NULL;
		root->link = NULL;
		course_num++;
		return root;
	}
	while (p) {
		if (id == p->course_id)
			return root;
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
	p->link = NULL;
	if (id < r->course_id)
		r->lc = p;
	else
		r->rc = p;
	course_num++;
	return root;
}
bt_course course_delete(bt_course root) {
	return root;
}
void course_change() {

}
void course_search() {

}
void course_print() {

}
void course_add_stu() {

}
void student_menu() {
	printf("\t\t*********************************************************\n");
	printf("\t\t******************��ӭ�����γ̹�������*******************\n");
	printf("\t\t*\t\t\t1:ѧ������\t\t\t*\n");
	printf("\t\t*\t\t\t2:ѧ��ɾ��\t\t\t*\n");
	printf("\t\t*\t\t\t3:ѧ����Ϣ�޸�\t\t\t*\n");
	printf("\t\t*\t\t\t4:ѧ����Ϣ��ѯ\t\t\t*\n");
	printf("\t\t*\t\t\t5:ѧ����Ϣ���\t\t\t*\n");
	printf("\t\t*\t\t\t6:�����ϲ�\t\t\t*\n");
	printf("\t\t*\t\t\t�������˳�\t\t\t*\n");
	printf("\t\t*********************************************************\n");
	printf("\t\t��ѡ��\n");
	int ch;
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:system("cls"); stu_add(); break;
	case 2:system("cls"); stu_delete(); break;
	case 3:system("cls"); stu_change(); break;
	case 4:system("cls"); stu_search(); break;
	case 5:system("cls"); stu_print(); break;
	case 6:system("cls"); main(); break;
	default:system("cls"); student_menu(); break;
	}
}
void stu_add() {
	
}
void stu_delete() {
	
}
void stu_change() {

}
void stu_search() {
	
}
void stu_print() {
	
}
