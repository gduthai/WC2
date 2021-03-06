﻿#include<stdio.h>
#include<stdlib.h>
int charnumber(char* filename) {
	int num = 0;     //统计字符数
	char c;
	FILE* fp;
	fp = fopen(filename, "r");
	if (!fp)
		exit(-1);
	c = fgetc(fp);
	while (!feof(fp)) {   //feof函数是检查文件是否运行到末端的函数
		num++;
		c = fgetc(fp);
	}
	fclose(fp);
	return num;
}    //统计程序字符数



int wordnumber(char* filename) {      //统计单词数
	int num = 0;
	int flag = 0;
	char c;
	FILE* fp;
	fp = fopen(filename, "r");
	if (!fp)
		exit(-1);
	c = fgetc(fp);
	while (!feof(fp)) {
		c = fgetc(fp);
		if (c < 'A' || (c > 'Z' && c < 'a') || c>'z')
			flag = 0;
		else if (flag == 0) {

			flag = 1;
			num++;
		}
	}
	fclose(fp);
	return num;

}
int linenumber(char* filename) {//统计行数
	FILE* fp = NULL;
	int c, lc = 0;
	int line = 0;
	fp = fopen(filename, "r");   
	if (charnumber(filename) == 0)
		return 0;
	while ((c = fgetc(fp)) != EOF) {
	
		if (c == '\n')
			line++;
		lc = c;
	}
	if (lc != '\n') line++;
	return line;
}




int main() {
	int i = 0;
	FILE* fp;
	int c_num, w_number, l_number;
	char c[3];
	char filename[20];
	for (; i < 3; i++) {
		printf("输入命令wc.exe");
		scanf("%s %s", c, filename);
		if ((fp = fopen(filename, "r")) == NULL) {
			printf("no found");
			return 0;
		}
		switch (c[1]) {


		case 'c': {printf("char number=%d\n", charnumber(filename)); break; }
		case 'w': {printf("word number=%d\n", wordnumber(filename)); break; }
		case 'l': {printf("line number=%d\n", linenumber(filename)); break; }

		}
	}
	getchar();
	return 0;



}