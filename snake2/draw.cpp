#include<stdio.h>
#include<stdlib.h> 
#include<iostream>
#include<time.h>
#include<windows.h>//����̨�����Ҫͷ�ļ�
using namespace std;
void pos(int x,int y);//ȷ�����λ��
HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ��׼������
struct snake{	
	int i;
	int j;
	struct snake *next;
	};


//���ù��λ��
void pos(int x,int y){
    COORD posPoint = {x,y}; //��������
    SetConsoleCursorPosition(hOut,posPoint);
}

void update(int x, int y, int sign){
	pos(x * 2, y);
	switch(sign){
		case 0: //�������� 
			cout << "��";
			break;
		case 1: //�������� 
			cout << "��";
			break;
		case 2: //��������
			cout << "��";	
			break; 
		case 3: //ɾ������
			cout << "��"; 
			break;
	}
	pos(0, 0);	
}
//	ǽ�壬����
//   �ա�
void initMap(int **map, int height, int weight){

	// ������һ����Ҫ��ע�ĵط��� �Ǿ��Ǳ߽���ǽ����ô��ʱ�����ж���ʱ�� 
	// ����Ҫ��ǽ��Ĵ�С�����������ͼ��С�У�Ҳ����height�ǰ�����ǽ���˵� 
	for(int i = 0; i < height; i++){
		for(int j = 0; j < weight; j++){
			if(i == 0 || i == height - 1){
				map[i][j] = 1; 
			}else if(j == 0 || j == weight - 1){
				map[i][j] = 1; 
			}else{
				map[i][j] = 0; 
			}
		}
	} 
	return;
}
void draw(int **map, int *star, int height, int weight){
	// ������һ����Ҫ��ע�ĵط��� �Ǿ��Ǳ߽���ǽ����ô��ʱ�����ж���ʱ�� 
	// ����Ҫ��ǽ��Ĵ�С�����������ͼ��С�У�Ҳ����height�ǰ�����ǽ���˵� 

	/* �����Ļ */
	system("cls");
	pos(0, 0);
	for(int i = 0; i < height; i++){
		for(int j = 0; j < weight; j++){
			if(map[i][j] == 1){
				cout << "��";	// ������ǽ�� 
			}else if(map[i][j] == 2){
				cout << "��";	// ���� 
			}else if(i == star[0] && j == star[1]){
				cout << "��";	// ���� 
			}else{
				cout << "��"; 	// ���ƶ����� 
			}
		}
		cout<<"akash"
		cout << endl;
	} 
	return;
}

void drawSnake(int **map, struct snake snake){
	struct snake *p = snake.next;
	map[p->i][p->j] = 2;	// ��ͷ
	p = p->next;
	while(p){
		map[p->i][p->j] = 1;
		p = p->next;
	}
	return;
}
