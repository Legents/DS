#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<conio.h>
/**
*���ݽṹ����
*/
typedef struct stu_c {	//��γ����ϴ洢ʱ��ѧ���ڵ㣬
	int s_id;			//ѧ��
	char s_name[50];	//����
	int g;				//���ſγ̵ĳɼ�
	struct stu_c *next;	//ָ����һ��ѡ�����ſγ̵�ѧ��
}stu_c,*stu_c_link;
typedef struct course {	//�γ���Ϣ�ڵ�
	int course_id;		//�γ̴���
	char course_name[50];//�γ�����
	float credit;//�γ�ѧ��
	int stu_num;//ѡ������
	struct course *lc, *rc;
	stu_c_link link;//ָ��ѡ�����ſγ̵�ѧ��
}course,*bt_course;
typedef struct grade {//�γ̳ɼ��ڵ㣬����ѧ����Ϣ��������ʱ�洢�ɼ�
	char course_name[50];//�γ���
	int g;//�ɼ�
};
typedef struct student {//��������ʱ��ѧ���ڵ�
	int s_id;//ѧ��
	char s_name[50];//ѧ������
	int course_num;
	grade g[10];//ָ�򱣴�����ѧ����ѡ�γ���Ϣ������
	struct student *next;//ָ����һ��ѧ��
}student,*s_link;
/**
*��������
*/
void main_menu();
void course_menu();
void student_menu();
s_link InitList();
void stu_add(s_link student);
void stu_delete(s_link student);
void stu_info_change(s_link student);
void stu_grade_change(s_link student);
void stu_search();
void stu_print(s_link student);
bt_course course_add(bt_course root);
bt_course course_delete(bt_course root);
void course_change(bt_course root);
void course_search(bt_course root);
void course_BST(bt_course root, int key);
void course_In_print(bt_course root);
void course_Post_print(bt_course root);
void course_add_stu();
bt_course root = (bt_course)malloc(sizeof(course));
s_link student1 = InitList();
static int course_num = 0;
/**
*���������������
*/
int main() {
	main_menu();
	system("pause");
	return 0;
}
/**
*���˵�ѡ��
*/
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
	default:system("cls"); exit(0);break;
	}
}
/**
*�γ̹����ֲ˵�ѡ��
*/
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
	case 1:system("cls"); 
		   root = course_add(root); 
		   system("pause");
		   system("cls"); 
		   course_menu(); 
		   break;
	case 2:system("cls");
		   root = course_delete(root); 
		   system("pause"); 
		   system("cls"); 
		   course_menu(); 
		   break;
	case 3:system("cls"); 
		   course_change(root); 
		   system("pause");
		   system("cls"); 
		   course_menu(); 
		   break;
	case 4:system("cls"); 
		   course_search(root); 
		   system("pause"); 
		   system("cls"); 
		   course_menu(); 
		   break;
	case 5:system("cls"); 
		   if (course_num == 0)
				printf("�γ�Ϊ�գ����������\n");
		   else {
			   printf("����\n");
			   printf("%-10s|  %-20s|  %-10s|  %-10s\n", "�γ̴���", "�γ�����", "�γ�ѧ��", "ѡ������");
			   course_In_print(root);
			   printf("����\n");
			   printf("%-10s|  %-20s|  %-10s|  %-10s\n", "�γ̴���", "�γ�����", "�γ�ѧ��", "ѡ������");
			   course_Post_print(root);

		   } 
		   system("pause"); 
		   system("cls"); 
		   course_menu(); 
		   break;
	case 6:system("cls"); 
		   course_add_stu();
		   system("pause");
		   system("cls"); 
		   course_menu(); 
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
*�γ̹����ֵĲ�������
*/
bt_course course_add(bt_course root) {
	bt_course p = root, r = (bt_course)malloc(sizeof(course));
	printf("������Ҫ��ӵĿγ���Ϣ������ ���� ѧ�֣���");
	int id;
	char name[50];
	float credit;
	scanf("%d", &id);
	scanf("%s", name);
	scanf("%f", &credit);
	printf("��Ҫ��ӵĿγ���Ϣ���£�\n");
	printf("�γ̴��룺%d  �γ�����%s  ѧ�֣�%.2f\n", id, name, credit);
	char c;
	printf("ȷ����ӣ���Y/N��\n");
	fflush(stdin);
	scanf("\n%c",&c);
	if (c == 'y' || c == 'Y') {
		if (course_num == 0) {
			p->course_id = id;
			strcpy(p->course_name, name);
			p->credit = credit;
			p->stu_num = 0;
			p->lc = p->rc = NULL;
			p->link = NULL;
			course_num++;
			printf("��ӳɹ���\n");
			return root;
		}
		while (p) {
			if (id == p->course_id) {
				printf("�ô���Ŀγ��Ѵ��ڡ����ʧ�ܣ�\n");
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
		p->link = NULL;
		if (id < r->course_id)
			r->lc = p;
		else
			r->rc = p;
		course_num++;
		printf("��ӳɹ���\n");
		return root;
	}
	else
		root = course_add(root);
}
bt_course course_delete(bt_course root) {
	
	//Ѱ��Ҫɾ���Ľڵ㼰��˫�׽ڵ�
	if (course_num == 0)
		printf("�γ�Ϊ�գ�����ɾ��\n");
	else {
		int course_id;
		printf("������Ҫɾ���Ŀγ̴��룺\n");
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
			printf("�ÿγ̲�����!\n");
			return root;
		}
		//ɾ��Ҷ�ӽڵ�
		if (del_node->lc == NULL && del_node->rc == NULL) {
			//ɾ���Ľڵ�Ϊ��
			if (par_of_del_node == NULL)
				root = NULL;
			else if (par_of_del_node->lc == del_node)
				par_of_del_node->lc = NULL;
			else
				par_of_del_node->rc = NULL;
			free(del_node);
		}
		//ɾ���Ľڵ���������
		else if (del_node->lc != NULL && del_node->rc == NULL) {
			//ɾ���Ľڵ�Ϊ���ڵ�
			if (par_of_del_node == NULL)
				root = del_node->lc;
			else if (par_of_del_node->rc == del_node)
				par_of_del_node->rc = del_node->lc;
			else
				par_of_del_node->lc = del_node->lc;
			free(del_node);
		}
		//ɾ���Ľڵ���������
		else if (del_node->lc == NULL && del_node->rc != NULL) {
			//ɾ���Ľڵ�Ϊ���ڵ�
			if (par_of_del_node == NULL)
				root = del_node->rc;
			else if (par_of_del_node->rc == del_node)
				par_of_del_node->rc = del_node->rc;
			else
				par_of_del_node->lc = del_node->rc;
			free(del_node);
		}
		//ɾ���Ľڵ��������������������
		else {
			par_of_sub_node = del_node;
			sub_node = del_node->lc;
			//Ѱ������ڵ��˫�׽ڵ�
			while (sub_node->rc != NULL) {
				par_of_sub_node = sub_node;
				sub_node = sub_node->rc;
			}

			if (par_of_sub_node != del_node) {
				sub_node->rc = del_node->rc;
				sub_node->lc = del_node->lc;
				par_of_sub_node->rc = NULL;
				//ɾ���ڵ�Ϊ���ڵ�
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
		printf("ɾ���ɹ�\n");
		if(course_num==0)
			return root = (bt_course)malloc(sizeof(course));
		return root;
	}
	
}
void course_change(bt_course root) {
	if (course_num == 0) {
		printf("�γ�Ϊ�գ������޸ģ�\n");
		return;
	}
	else {
		int flag = 0;
		bt_course p = root;
		int id;
		char name[50];
		float credit;
		printf("������Ҫ�޸ĵĿγ���Ϣ������ ���� ѧ�֣���");
		scanf("%d", &id);
		scanf("%s", name);
		scanf("%f", &credit);
		printf("��Ҫ�޸ĵĿγ���Ϣ���£�\n");
		printf("�γ̴��룺%d  �γ�����%s  ѧ�֣�%.2f\n", id, name, credit);
		char c;
		printf("ȷ���޸ģ���Y/N��\n");
		fflush(stdin);
		scanf("\n%c", &c);
		if (c == 'y' || c == 'Y') {
			if (p == NULL)
				printf("���ſγ̲�����\n");
			if (p != NULL) {
				while (p) {
					if (p->course_id == id) {
						flag = 1;
						strcpy(p->course_name, name);
						p->credit = credit;
						printf("�޸ĳɹ���\n");
						return;
					}
					else if (p->course_id > id)
						p = p->lc;
					else
						p = p->rc;
				}
			}
			if (!flag)
				printf("���ſγ̲����ڣ�\n");
		}
		else
			course_change(root);
	}
	
}
void course_search(bt_course root) {
	if (course_num == 0) {
		printf("�γ�Ϊ�գ����ܲ�ѯ��\n");
		return;
	}
	else {
		int key;
		printf("������Ҫ��ѯ�Ŀγ̴��룺\n");
		scanf("%d", &key);
		course_BST(root, key);
	}
}
void course_BST(bt_course root,int key) {
	int flag=0;
	bt_course p = root;
	if (p == NULL)
		printf("���ſγ̲�����\n");
	if (p != NULL) {
		while (p) {
			if (p->course_id == key) {
				flag = 1;
				printf("%-10s|  %-20s|  %-10s|  %-10s\n","�γ̴���","�γ�����","�γ�ѧ��","ѡ������");
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
		printf("��ѯʧ�ܣ����ſγ̲����ڣ�\n");
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
void course_add_stu() {

}
/**
*ѧ�������ֲ˵�ѡ��
*/
void student_menu() {
	printf("\t\t*********************************************************\n");
	printf("\t\t******************��ӭ�����γ̹�������*******************\n");
	printf("\t\t*\t\t\t1:ѧ������\t\t\t*\n");
	printf("\t\t*\t\t\t2:ѧ��ɾ��\t\t\t*\n");
	printf("\t\t*\t\t\t3:ѧ����Ϣ�޸�\t\t\t*\n");
	printf("\t\t*\t\t\t4:ѧ���ɼ��޸�\t\t\t*\n");
	printf("\t\t*\t\t\t5:ѧ����Ϣ��ѯ\t\t\t*\n");
	printf("\t\t*\t\t\t6:ѧ����Ϣ���\t\t\t*\n");
	printf("\t\t*\t\t\t7:�����ϲ�\t\t\t*\n");
	printf("\t\t*\t\t\t�������˳�\t\t\t*\n");
	printf("\t\t*********************************************************\n");
	printf("\t\t��ѡ��\n");
	int ch;
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:system("cls"); 
		   stu_add(student1);
		   system("cls");
		   student_menu();
		   break;
	case 2:system("cls"); stu_delete(student1); system("cls"); student_menu(); break;
	case 3:system("cls"); stu_info_change(student1); system("cls"); student_menu(); break;
	case 4:system("cls"); stu_grade_change(student1); system("cls"); student_menu(); break;
	case 5:system("cls"); stu_search(); system("cls"); student_menu(); break;
	case 6:system("cls"); stu_print(student1); system("cls"); student_menu(); break;
	case 7:system("cls"); main(); system("cls"); student_menu(); break;
	default:system("cls");exit(0); break;
	}
}
/**
*ѧ�������ֺ�������
*/
s_link InitList()//��ʼ������ 
{
	s_link h = (s_link)malloc(sizeof(student));
	if (!h)//�ж��Ƿ�Ϊh���䵽����ռ� 
	{
		printf("��ʼ���������\n");
		exit(0);
	}
	h->next = NULL;

	return h;
}
void stu_add(s_link student) {
	printf("���������ѧ������Ϣ��\n");
	int id;
	char name[50];
	scanf("%d", &id);
	scanf("%s", name);
	printf("������ӵ�ѧ����ϢΪ��\nѧ�ţ�%d  ������%s\n", id, name);
	char c;
	printf("ȷ����ӣ���Y/N��\n");
	fflush(stdin);
	scanf("\n%c", &c);
	s_link p = student;
	s_link q = (s_link)malloc(sizeof(student));
	if (c == 'y' || c == 'Y') {
		q->s_id = id;
		strcpy(q->s_name, name);
		q->course_num = 0;
		q->next = student->next;
		student->next = q;
	}
	else {
		system("cls");
		stu_add(student);
	}
	char ch;
	printf("������Ӹ�ѧ���ĳɼ�����Y/N��\n");
	fflush(stdin);
	scanf("\n%c", &ch);
	if (ch == 'y' || ch == 'Y') {
		if (q->course_num >= 10) {
			printf("��ѧ����ǰ�γ������Ѵﵽ���ޣ���ɾ����ؿγ̺��ٲ�����");
			system("pause");
			return;
		}
		else {
			printf("������Ҫ��ӵĿγ����Ƽ����ſγ̵ĳɼ�����0 0��������\n");
			char cou_name[50];
			int cou_g;
			do {
				if (q->course_num >= 10) {
					printf("��ѧ����ǰ�γ������Ѵﵽ���ޣ���ɾ����ؿγ̺��ٲ�����");
					system("pause");
					return;
				}
				else {
					scanf("%s", cou_name);
					scanf("%d", &cou_g);
					if (strcmp(cou_name, "0") != 0 || cou_g != 0) {
						strcpy(q->g[q->course_num].course_name, cou_name);
						q->g[q->course_num].g = cou_g;
						q->course_num = q->course_num + 1;
					}
				}
			} while (strcmp(cou_name, "0") != 0 || cou_g != 0);
			printf("�ɼ���ӽ�����\n");
			getch();
		}
	}
	else
		return;
}
void stu_delete(s_link student) {
	s_link p = student;
	printf("��ѡ��ѧ�ţ�1��ɾ�����߰�������2��ɾ��(1/2),ѡ�����������һ�㣺\n");
	int c;
	scanf("%d", &c);
	if (c == 1) {
		int id;
		printf("��������Ҫɾ����ѧ��ѧ�ţ�\n");
		scanf("%d", &id);
		while (p->next) {
			if (p->next->s_id == id) {
				s_link q = p->next;
				p->next = q->next;
				printf("ɾ���ɹ���\n");
				system("pause");
				return;
			}
		}
		printf("��ѧ�������ڣ�\n");
		system("pause");
	}
	else if (c == 2) {
		char name[50];
		printf("��������Ҫɾ����ѧ��������\n");
		scanf("%s", name);
		while (p->next) {
			if (strcmp(p->next->s_name,name)==0) {
				s_link q = p->next;
				p->next = q->next;
				printf("ɾ���ɹ���\n");
				system("pause");
				return;
			}
		}
		printf("��ѧ�������ڣ�\n");
		system("pause");
	}
	else {
		system("cls");
		student_menu();
	}
}
void stu_info_change(s_link student) {
	s_link p = student->next;
	printf("��ѡ��ѧ�ţ�1���޸Ļ��߰�������2���޸�(1/2),ѡ�����������һ�㣺\n");
	int c;
	scanf("%d", &c);
	if (c == 1) {
		int id;
		char name[50];
		printf("��������Ҫ�޸���Ϣ��ѧ��ѧ�ţ�\n");
		scanf("%d", &id);
		printf("�������޸ĺ��ѧ��������\n");
		scanf("%s", name);
		while (p) {
			if (p->s_id == id) {
				strcpy(p->s_name, name);
				printf("�޸ĳɹ���\n");
				system("pause");
				return;
			}
		}
		printf("��ѧ�������ڣ�\n");
		system("pause");
	}
	else if (c == 2) {
		int id;
		char name[50];
		printf("��������Ҫ�޸ĵ�ѧ��������\n");
		scanf("%s", name);
		printf("�������޸ĺ��ѧ��ѧ�ţ�\n");
		scanf("%d", &id);
		while (p) {
			if (strcmp(p->next->s_name, name) == 0) {
				p->s_id = id;
				printf("�޸ĳɹ���\n");
				system("pause");
				return;
			}
		}
		printf("��ѧ�������ڣ�\n");
		system("pause");
	}
	else {
		system("cls");
		student_menu();
	}
}
void stu_grade_change(s_link student) {

}
void stu_search() { 
	
}
void stu_print(s_link student) {
	s_link p = student->next;
	printf("ѧ��\t����\t�γ̼���ɼ�\n");
	while (p) {
		printf("%d\t%s\t", p->s_id, p->s_name);
		int i;
		for (i = 0; i < p->course_num; i++) {
			printf("%s:%d   ", p->g[i].course_name, p->g[i].g);
		}
		p = p->next;
		printf("\n");
	}
	system("pause");
}
