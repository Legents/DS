#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
/**
*���ݽṹ���岿��
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
	int c_num;
	grade g[10];//ָ�򱣴�����ѧ����ѡ�γ���Ϣ�����Ա�
	struct student *next;//ָ����һ��ѧ��
}student,*s_link;
typedef struct course1 {	//�γ���Ϣ�ڵ�
	int course_id;		//�γ̴���
	char course_name[50];//�γ�����
}cour[10];;
/**
*��������
*/
void main_menu(bt_course root, s_link student1);//���˵�
void course_menu(bt_course root, s_link student1);//�γ̹���˵�
void student_menu(bt_course root, s_link student1);//ѧ������˵�
s_link InitList();//��ʼ��
s_link stu_add(s_link student1, bt_course root);//���洢ѧ����Ϣ���������ѧ��
int search_stu(s_link student1, int id);//ȷ��Ҫ��ӵ�ѧ���Ƿ����
s_link stu_add_grade(s_link q, bt_course root);//��ѧ����ӳɼ�
void stu_delete(s_link student1);//ѧ���ڵ��ɾ��
void stu_info_change(s_link student1);//ѧ����Ϣ�޸�
void search_grade_change_stu(s_link student1);//������Ҫ�޸ĳɼ���ѧ���ڵ�
s_link stu_grade_change(s_link p);//�Բ��ҵ���ѧ���ڵ�ɼ������޸�
void stu_search(s_link student1);//ѧ����ѯ
void stu_print(s_link student1);//ѧ�����
bt_course course_add(bt_course root1);//�γ����
bt_course course_delete(bt_course root1);//�γ�ɾ��
void course_change(bt_course root1);//�γ��޸�
void course_search(bt_course root1);//������Ҫ��ѯ�Ŀγ�
void course_BST(bt_course root, int key);//�γ̵�����������
void print_course_with_print(bt_course root);
void course_In_print(bt_course root1);//�γ��������
void course_Post_print(bt_course root1);//�γ̺�������
void search_course_node(bt_course root);
int course_add_stu(stu_c_link p, int num);//���γ̽ڵ����ѧ����Ϣ
void course_stu_print(stu_c_link q);//�����γ����ӵ�ѧ����Ϣ
int course_num = 0;
/**
*���������������
*/
int main() {
	bt_course root = (bt_course)malloc(sizeof(course));
	s_link student1 = InitList();
	main_menu(root, student1);
	system("pause");
	return 0;
}
/**
*���˵�ѡ��
*/
void main_menu(bt_course root, s_link student1) {
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
	case 1:system("cls"); course_menu(root, student1); break;
	case 2:system("cls"); student_menu(root, student1); break;
	default:system("cls"); exit(0);break;
	}
}
/**
*�γ̹����ֲ˵�ѡ��
*/
void course_menu(bt_course root, s_link student1) {
	printf("\t\t*********************************************************\n");
	printf("\t\t******************��ӭ�����γ̹�������*******************\n");
	printf("\t\t*\t\t\t1:�γ�����\t\t\t*\n");
	printf("\t\t*\t\t\t2:�γ�ɾ��\t\t\t*\n");
	printf("\t\t*\t\t\t3:�γ��޸�\t\t\t*\n");
	printf("\t\t*\t\t\t4:�γ̲�ѯ\t\t\t*\n");
	printf("\t\t*\t\t\t5:�γ����\t\t\t*\n");
	printf("\t\t*\t\t\t6:������пγ̼���ѧ������\t*\n");
	printf("\t\t*\t\t\t7:����ѧ��\t\t\t*\n");
	printf("\t\t*\t\t\t8:�����ϲ�\t\t\t*\n");
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
		   course_menu(root, student1);
		   break;
	case 6:system("cls"); 
		   if (course_num == 0)
				printf("�γ�Ϊ�գ����������\n");
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
			printf("��ӳɹ���\n");
			printf("�Ƿ����Ϊ���ſγ����ѧ������Y/N��\n");
			char c1;
			scanf("\n%c", &c1);
			if (c1 == 'y' || c1 == 'Y') {
				p->stu_num = course_add_stu(p->link,p->stu_num);
			}
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
		p->link = (stu_c_link)malloc(sizeof(stu_c));
		p->link->next = NULL;
		if (id < r->course_id)
			r->lc = p;
		else
			r->rc = p;
		course_num++;
		printf("��ӳɹ���\n");
		printf("�Ƿ����Ϊ���ſγ����ѧ������Y/N��\n");
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
void print_course_with_print(bt_course root) {
	if (root != NULL) {
		print_course_with_print(root->lc);
		printf("%-10s|  %-20s|  %-10s|  %-10s\n", "�γ̴���", "�γ�����", "�γ�ѧ��", "ѡ������");
		printf("%-10d|  %-20s|  %-10.2f|  %-10d\n", root->course_id, root->course_name, root->credit, root->stu_num);
		printf("-------------------------ѧ������-------------------------\n");
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
	printf("������Ҫ��ӵ�ѧ��ѧ�š��������ɼ�(����0 0 0��������\n");
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
				while (p&&p->next) {//���Ҳ����λ�� 
					if (score > p->next->g) {//Ԫ�ش�С�������򣬵��Ƚϵ���һ���ڵ����Ҫ����Ľڵ�ʱ���в��� 
						s->next = p->next;
						p->next = s;
						break;
					}
					p = p->next;
				}
				if (!p->next) { //����Ƚϵ����һ����û�бȵ�ǰ�������뵽��� 
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
	printf("%-10s|%-10s|%-4s\n", "ѧ��","����","�ɼ�");
	while (q) {
		printf("%-10d|%-10s|%-4d\n", q->s_id, q->s_name, q->g);
		q = q->next;
	}
}
/**
*ѧ�������ֲ˵�ѡ��
*/
void student_menu(bt_course root, s_link student1) {
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
s_link stu_add(s_link student1, bt_course root) {
	printf("���������ѧ������Ϣ��\n");
	int id;
	char name[50];
	char c;
	do {
		scanf("%d", &id);
		scanf("%s", name);
		if (id < 1000000000 || id>9999999999)
			printf("���������ѧ�Ų����Ϲ淶������������ѧ����Ϣ��\n");
	} while (id < 1000000000 || id>9999999999);
	if (search_stu(student1,id)) {
		printf("ѧ��Ϊ%d��ѧ���Ѵ��ڣ����ʧ�ܣ���\n", id);
		return student1;
	}
	printf("������ӵ�ѧ����ϢΪ��\nѧ�ţ�%d  ������%s\n", id, name);
	printf("ȷ����ӣ���Y/N��\n");
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
	printf("������Ӹ�ѧ���ĳɼ�����Y/N��\n");
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
		printf("��ǰû�пγ̣�������ӳɼ���\n");
		return q;
	}
	else {
		if (q->c_num >= 10) {
			printf("��ѧ����ǰ�γ������Ѵﵽ���ޣ���ɾ����ؿγ̺��ٲ�����\n");
			return q;
		}
		else {
			printf("������Ҫ��ӵĿγ����Ƽ����ſγ̵ĳɼ�����0 0��������\n");
			char cou_name[50];
			int cou_g;
			do {
				if (q->c_num >= 10) {
					printf("��ѧ����ǰ�γ������Ѵﵽ���ޣ����ܼ�����ӣ�\n");
					return q;
				}
				else {
						scanf("%s", cou_name);
					do {
						scanf("%d", &cou_g);
						if (cou_g < 0 || cou_g>100)
							printf("����ɼ������Ϲ淶���ɼ���ΧΪ[0,100]�����������룺\n");
					} while (cou_g < 0 || cou_g>100);
					if (strcmp(cou_name, "0") != 0 || cou_g != 0) {
						strcpy(q->g[q->c_num].course_name, cou_name);
						q->g[q->c_num].g = cou_g;
						q->c_num = q->c_num + 1;
					}
				}
			} while (strcmp(cou_name, "0") != 0 || cou_g != 0);
			printf("�ɼ���ӽ�����\n");
			return q;
		}
	}
	

}
void stu_delete(s_link student1) {
	s_link p = student1;
	if (p->next) {
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
					return;
				}
				p = p->next;
			}
			printf("��ѧ�������ڣ�\n");
		}
		else if (c == 2) {
			char name[50];
			printf("��������Ҫɾ����ѧ��������\n");
			scanf("%s", name);
			while (p->next) {
				if (strcmp(p->next->s_name, name) == 0) {
					s_link q = p->next;
					p->next = q->next;
					printf("ɾ���ɹ���\n");
					return;
				}
				p = p->next;
			}
			printf("��ѧ�������ڣ�\n");
		}
		else {
			system("cls");
			return;
		}
	}
	else {
		printf("ѧ����Ϣ����Ϊ�գ�����ɾ����\n");
		return;
	}
}
void stu_info_change(s_link student1) {
	s_link p = student1->next;
	if (p) {
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
					return;
				}
				p = p->next;
			}
			printf("��ѧ�������ڣ�\n");
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
					return;
				}
				p = p->next;
			}
			printf("��ѧ�������ڣ�\n");
		}
		else {
			system("cls");
			return;
		}
	}
	else {
		printf("ѧ����Ϣ����Ϊ�գ������޸ģ�\n");
		return;
	}
}
void search_grade_change_stu(s_link student1) {
	s_link p = student1->next;
	if (p) {
		printf("��ѡ��ѧ�ţ�1���޸Ļ��߰�������2���޸�(1/2),ѡ�����������һ�㣺\n");
		int c;
		scanf("%d", &c);
		if (c == 1) {
			int id;
			printf("��������Ҫ�޸���Ϣ��ѧ��ѧ�ţ�\n");
			scanf("%d", &id);
			while (p) {
				if (p->s_id == id) {
					p = stu_grade_change(p);
					return;
				}
				p = p->next;
			}
			printf("��ѧ�������ڣ�\n");
		}
		else if (c == 2) {
			char name1[50];
			printf("��������Ҫ�޸ĵ�ѧ��������\n");
			scanf("%s", name1);
			while (p) {
				if (strcmp(p->s_name, name1) == 0) {
					p = stu_grade_change(p);
					system("pause");
					return;
				}
				p = p->next;
			}
			printf("��ѧ�������ڣ�\n");
			system("pause");
		}
		else {
			system("cls");
			return;
		}
	}
	else {
		printf("ѧ����Ϣ����Ϊ�գ������޸ģ�\n");
		return;
	}
}
s_link stu_grade_change(s_link p) {

	printf("��������Ҫ�޸ĵĿγ������޸ĺ�ĳɼ���\n");
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
	printf("���ſγ̲����ڣ�����ȥ��ӣ�\n");
	return p;
}
void stu_search(s_link student1) {
	s_link p = student1;
	if (p->next) {
		printf("��ѡ��ѧ�ţ�1����ѯ���߰�������2����ѯ(1/2),ѡ�����������һ�㣺\n");
		int c;
		scanf("%d", &c);
		if (c == 1) {
			int id;
			printf("��������Ҫ��ѯ��ѧ��ѧ�ţ�\n");
			scanf("%d", &id);
			while (p->next) {
				if (p->next->s_id == id) {
					stu_print(p);
					system("pause");
					return;
				}
				p = p->next;
			}
			printf("��ѧ�������ڣ�\n");
		}
		else if (c == 2) {
			char name1[50];
			printf("��������Ҫ��ѯ��ѧ��������\n");
			scanf("%s", name1);
			while (p->next) {
				if (strcmp(p->next->s_name, name1) == 0) {
					stu_print(p);
					return;
				}
				p = p->next;
			}
			printf("��ѧ�������ڣ�\n");
		}
		else {
			system("cls");
			return;
		}
	}
	else {
		printf("ѧ����Ϣ����Ϊ�գ����ܲ�ѯ��\n");
		return;
	}
}
void stu_print(s_link student1) {
	s_link p = student1->next;
	if (p) {
		printf("%-10s|%-10s|%-16s\n", "ѧ��", "����", "�γ̼���ɼ�");
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
		printf("ѧ����Ϣ����Ϊ�գ����������\n");
		return;
	}
}
